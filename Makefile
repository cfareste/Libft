NAME = libft.a

#----COLORS----#
DEF_COLOR = \033[0m
GREEN = \033[1;32m
PINK = \033[1;35m
CYAN = \033[1;36m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RED = \033[1;91m

#----DEFINITIONS----#
GNL_BUFFER_SIZE ?= 42

#----COMPILER----#
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(GNL_BUFFER_SIZE)

#----LIB LINKER----#
AR = ar
ARFLAGS = rcs

#----DIRS----#
BINDIR = bin

#----MANDATORY----#
SRCS = ft_isdigit.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split_set.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		ft_printf.c \
		handle_flags_helpers.c \
		print_complex_helpers.c \
		print_complex_utils.c \
		print_global_helpers.c \
		print_numbers_helpers.c \
		print_raw_utils.c \
		print_simple_helpers.c \
		print_simple_utils.c \
		print_string_helpers.c \
		ft_stroccurrences.c

OBJS = $(SRCS:%.c=$(BINDIR)/%.o)
DEPS = $(SRCS:%.c=%.d)

#----BONUS----#
BSRCS = ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c
BOBJS = $(BSRCS:%.c=$(BINDIR)/%.o)
BDEPS = $(BSRCS:%.c=%.d)

#----TARGETS----#
all: $(NAME)

ifndef BONUS
$(NAME): $(OBJS)
	@printf "$(BLUE)\r\033[2KLinking objects and creating static library...$(DEF_COLOR)"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "\n$(GREEN)[✓] $(PINK)Libft$(GREEN) created!!!$(DEF_COLOR)\n"
else
$(NAME): $(OBJS) $(BOBJS)
	@printf "$(BLUE)\r\033[2KLinking objects and creating static library...$(DEF_COLOR)"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BOBJS)
	@echo "\n$(GREEN)[✓] $(PINK)Libft bonus$(GREEN) created!!!$(DEF_COLOR)\n"
endif

$(BINDIR)/%.o: %.c Makefile
	@mkdir -p $(BINDIR)
	@printf "$(CYAN)\r\033[2KCompiling: $(PINK)$(notdir $<)...$(DEF_COLOR)"

	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@rm -rf $(BINDIR)
	@echo "$(RED)Binaries and dependencies deleted$(DEF_COLOR)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)Library deleted$(DEF_COLOR)\n"

re: fclean all

bonus:
	@$(MAKE) --no-print-directory BONUS=1

.PHONY: all clean fclean re bonus

-include $(DEPS)

-include $(BDEPS)

.SILENT:
