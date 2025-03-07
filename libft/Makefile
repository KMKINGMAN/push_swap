# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 22:42:29 by mkurkar           #+#    #+#              #
#    Updated: 2025/01/12 19:04:28 by mkurkar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
CC			:= cc
BUILD		:= release

# Build type specific flags
cflags.release	:= -Wall -Wextra -Werror
cflags.debug	:= -Wall -Wextra -Werror -g3 -DDEBUG
cflags.sanitize	:= -Wall -Wextra -Werror -g3 -fsanitize=address -DDEBUG
CFLAGS			:= $(cflags.$(BUILD))

# Directories
SRCDIR		:= .
OBJDIR		:= obj
DEPDIR		:= $(OBJDIR)/.deps

# Source files
SRCS		:= ft_boolean_string.c \
			   ft_itoa.c \
			   ft_put_fd.c \
			   ft_string_method_2.c \
			   ft_striter.c \
			   ft_allocations.c \
			   ft_char_converter.c \
			   ft_memory.c \
			   ft_split.c \
			   ft_string_method.c \
			   ft_printf/ft_main.c ft_printf/src/ft_handlers.c  ft_printf/src/ft_handlers_new.c  ft_printf/src/ft_itoa_base.c  ft_printf/src/ft_print_flags.c  ft_printf/src/ft_strings.c 

# Bonus sources
BONUS_SRCS	:= ft_lists.c \
			   ft_lists_controller.c

# Objects and dependencies
OBJS		:= $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS		:= $(SRCS:%.c=$(DEPDIR)/%.d)
BONUS_OBJS	:= $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)
BONUS_DEPS	:= $(BONUS_SRCS:%.c=$(DEPDIR)/%.d)

# Colors and formatting
BLUE		:= \033[34m
GREEN		:= \033[32m
YELLOW		:= \033[33m
RESET		:= \033[0m
BOLD		:= \033[1m

INCDEP := -I.

# Default target
all: banner $(NAME)

# Pretty output
banner:
	@printf "$(BLUE)$(BOLD)Building $(NAME) [$(BUILD) mode]$(RESET)\n"

# Create directories including nested ones
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@
	@mkdir -p $(OBJDIR)/ft_printf/src
	@mkdir -p $(DEPDIR)/ft_printf/src

# Dependency generation with directory creation
$(DEPDIR)/%.d: %.c | $(DEPDIR)
	@printf "$(YELLOW)Generating dependencies for $<$(RESET)\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCDEP) -MM $< -MT '$(OBJDIR)/$*.o' > $@

# Compilation with directory handling
$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR)
	@printf "$(YELLOW)Compiling $<$(RESET)\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS)  $(INCDEP) -c $< -o $@

# Library creation with status
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)$(BOLD)$(NAME) built successfully!$(RESET)\n"

# Include dependencies
-include $(DEPS) $(BONUS_DEPS)

# Bonus target
bonus: OBJS += $(BONUS_OBJS)
bonus: DEPS += $(BONUS_DEPS)
bonus: banner $(NAME)

# Debug build
debug: BUILD := debug
debug: all

# Sanitize build
sanitize: BUILD := sanitize
sanitize: all

# Clean rules with status messages
clean:
	@rm -rf $(OBJDIR)
	@printf "$(BLUE)Cleaned object files$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(BLUE)Cleaned $(NAME)$(RESET)\n"

# Rebuild
re: fclean all

# Source file information
info:
	@echo "Source files:"
	@for file in $(SRCS); do echo "  $$file"; done

# Non-File Targets
.PHONY: all clean fclean re debug sanitize banner norm bonus info
.SILENT: banner
