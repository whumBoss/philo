# ===== Target =====
NAME = philo

# ===== Directories =====
OBJ_DIR = objs

# ===== Libraries =====

# ===== Toolchain =====
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -I. -Iheader -MMD -MP

# ===== Source Layout =====
MAIN_DIR = src/
PARSING_DIR = src/parsing/
EXEC_DIR = src/exec/
UTILS_DIR = src/utils/

MAIN_FILES = main.c
PARSING_FILES = init_data.c init_philos.c
EXEC_FILES = actions.c routine_monitor.c routine_philo.c
UTILS_FILES = clear_data.c clear_philos.c test.c utils_gen.c utils_monitor.c utils_value.c

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


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ===== Cleanup =====
clean:
	@rm -rf $(OBJ_DIR) vgcore*

fclean: clean
	@rm -f $(NAME)

re: fclean all

# ===== Auto Dependencies =====
-include $(DEPS)

.PHONY: all clean fclean re
