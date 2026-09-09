# ===== Target =====
NAME = philo

# ===== Directories =====
#LIBFT_DIR = libft/
#PRINTF_DIR = includes/ft_print/
OBJ_DIR = objs

# ===== Libraries =====
#LIBFT = $(LIBFT_DIR)libft.a
#PRINTF = $(PRINTF_DIR)libftprintf.a

# ===== Toolchain =====
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -I. -Iheader -MMD -MP
#CPPFLAGS = -I. -Iincludes -Iincludes/ft_print -Ilibft -MMD -MP

# ===== Source Layout =====
MAIN_DIR = src/
PARSING_DIR = src/parsing/
EXEC_DIR = src/exec/
UTILS_DIR = src/utils/

MAIN_FILES = main.c
PARSING_FILES = init_data.c init_philos.c
EXEC_FILES = actions.c monitor.c philo.c
UTILS_FILES = clear.c test.c utils_gen.c utils_monitor.c utils_value.c

# ===== Source / Object / Dependency Lists =====
SRCS = \
	$(addprefix $(MAIN_DIR),$(MAIN_FILES)) \
	$(addprefix $(PARSING_DIR),$(PARSING_FILES)) \
	$(addprefix $(EXEC_DIR),$(EXEC_FILES)) \
	$(addprefix $(UTILS_DIR),$(UTILS_FILES))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

# ===== Build Rules =====
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#$(LIBFT):
#	@$(MAKE) -C $(LIBFT_DIR)

#$(PRINTF):
#	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ===== Cleanup =====
clean:
	@rm -rf $(OBJ_DIR)
#	@$(MAKE) clean -C $(LIBFT_DIR)
#	@$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
#	@$(MAKE) fclean -C $(LIBFT_DIR)
#	@$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

# ===== Test Helpers =====
#ARGS= Makefile ls wob tests/outfile

#test: $(NAME)
#	./$(NAME) $(ARGS)

#leaks: $(NAME)
#	valgrind --leak-check=full ./$(NAME) $(ARGS)

#hardtest: $(NAME)
#	r./$(NAME) Makefile "ls -l -a" "wc -l" tests/outfile
#	cat tests/outfile

#noinfile: $(NAME)
#	./$(NAME) Makefiled "ls -l -a" wc tests/outfile

# ===== Auto Dependencies =====
-include $(DEPS)

.PHONY: all clean fclean re
