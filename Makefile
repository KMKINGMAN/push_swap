CC					:= cc
CXX					:= c++
ifeq ($(shell uname -s),Darwin)
	CC				:= gcc
	CXX				:= g++
endif

#The Target Binary Program
TARGET				:= push_swap
BUILD				:= release

include sources.mk

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR				:= src
INCDIR				:= include
BUILDDIR			:= obj
TARGETDIR			:= bin
SRCEXT				:= c
DEPEXT				:= d
OBJEXT				:= o

OBJECTS				:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_BONUS		:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_BONUS:.$(SRCEXT)=.$(OBJEXT)))

OBJECTS_SERVER		:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_SERVER:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_SERVER_BONUS:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_SERVER_BONUS:.$(SRCEXT)=.$(OBJEXT)))

#Flags, Libraries and Includes
cflags.release		:= -Wall -Werror -Wextra
cflags.valgrind		:= -Wall -Werror -Wextra -DDEBUG -ggdb
cflags.debug		:= -Wall -Werror -Wextra -DDEBUG -ggdb -fsanitize=address -fno-omit-frame-pointer
CFLAGS				:= $(cflags.$(BUILD))
CPPFLAGS			:= $(cflags.$(BUILD))

lib.release			 := -Llibft -lft -Lgc_collector -lcollect
lib.valgrind		:= $(lib.release)
lib.debug			:= $(lib.release) -fsanitize=address -fno-omit-frame-pointer
LIB					:= $(lib.$(BUILD))

INC					:= -I$(INCDIR) -I/usr/local/include -Igc_collector -Ilibft
INCDEP				:= -I$(INCDIR) -I/usr/local/include -Igc_collector -Ilibft

# Colors
C_RESET				:= \033[0m
C_PENDING			:= \033[0;36m
C_SUCCESS			:= \033[0;32m

# Multi platforms
ECHO				:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE			:= "\033[1A\033[2K\033[1A"
ERASE				:= $(ECHO) $(ES_ERASE)

GREP				:= grep --color=auto --exclude-dir=.git
NORMINETTE			:= norminette `ls`

LIBS_DIR = libft/libft.a gc_collector/libcollect.a

# Default Make
all: libft $(TARGETDIR)/$(TARGET)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"


# Remake
re: fclean all

# Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)
	@$(RM) -f $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_SERVER) $(OBJECTS_SERVER_BONUS)
	@$(RM) -f $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))
	@make $@ -C libft
	@make $@ -C gc_collector

# Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGETDIR)
	@make $@ -C libft
	@make $@ -C gc_collector

# Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# Link
$(TARGETDIR)/$(TARGET): $(OBJECTS) $(LIBS_DIR)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)


$(BUILDIR):
	@mkdir -p $@

# Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@$(ERASE)
	@$(ERASE)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

libft:
	@make -C libft
	@make -C gc_collector


norm:
	@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

# Non-File Targets
.PHONY: all re clean fclean norm bonus libft
