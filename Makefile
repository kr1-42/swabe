NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./my_libft/
LIBFT = $(LIBFT_DIR)libft.a
OBJ_DIR = .obj/

MOVES_DIR = .obj/moves/
UTILS_DIR = .obj/utils/
LST_UTILS_DIR = .obj/lst_utils/
PARSING_DIR = .obj/parsing/
SORT_DIR = .obj/sort/
INC_DIR = headers/



# Add a list of your push_swap source files here
SRC_FILES = $(addprefix src/,main.c)

UTILS_SRC_FILES = $(addprefix src/utils/,free_mem.c \
	has_dup.c \
	ft_err.c \
	arg_checker.c\
	idx_list_values.c\
	ft_checksorted.c \
	stack_limits.c \
	stack_positions.c)

MOVES_SRC_FILES = $(addprefix src/moves/,ft_push.c \
	ft_rotate.c \
	ft_reverse_rotate.c \
	ft_swap.c)

LST_UTILS_SRC_FILES = $(addprefix src/lst_utils/,print_list.c \
	list_size.c \
	free_list.c)

PARSING_SRC_FILES = $(addprefix src/parsing/,lst_parsing.c \
	str_parsing.c)

SORT_SRC_FILES = $(addprefix src/sort/,small_sort.c \
	sort_large_list.c \
	apply_rotations.c \
	best_rotations.c \
	rotate_cases.c \
	rotate_cases_2.c)

OBJ_FILES = $(SRC_FILES:src/%.c=$(OBJ_DIR)%.o) \
			$(MOVES_SRC_FILES:src/moves/%.c=$(MOVES_DIR)%.o) \
			$(UTILS_SRC_FILES:src/utils/%.c=$(UTILS_DIR)%.o) \
			$(LST_UTILS_SRC_FILES:src/lst_utils/%.c=$(LST_UTILS_DIR)%.o) \
			$(PARSING_SRC_FILES:src/parsing/%.c=$(PARSING_DIR)%.o) \
			$(SORT_SRC_FILES:src/sort/%.c=$(SORT_DIR)%.o)

CFLAGS += -I$(INC_DIR)


NC = \033[0m

all: pre-build $(OBJ_DIR) $(NAME)

pre-build:
	@clear
	@echo "Starting compilation..."

$(OBJ_DIR): $(MOVES_DIR) $(UTILS_DIR) $(LST_UTILS_DIR) $(PARSING_DIR) $(SORT_DIR)
	@mkdir -p $(OBJ_DIR)

$(UTILS_DIR):
	@mkdir -p $(UTILS_DIR)

$(MOVES_DIR):
	@mkdir -p $(MOVES_DIR)

$(LST_UTILS_DIR):
	@mkdir -p $(LST_UTILS_DIR)

$(PARSING_DIR):
	@mkdir -p $(PARSING_DIR)

$(SORT_DIR):
	@mkdir -p $(SORT_DIR)

# Pattern rule for object files
$(OBJ_DIR)%.o: src/%.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

# Pattern rule for move object files
$(MOVES_DIR)%.o: src/moves/%.c
	@mkdir -p $(MOVES_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

# Pattern rule for utility object files
$(UTILS_DIR)%.o: src/utils/%.c
	@mkdir -p $(UTILS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

# Pattern rule for list utility object files
$(LST_UTILS_DIR)%.o: src/lst_utils/%.c
	@mkdir -p $(LST_UTILS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

# Pattern rule for parsing object files
$(PARSING_DIR)%.o: src/parsing/%.c
	@mkdir -p $(PARSING_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

# Pattern rule for sort object files
$(SORT_DIR)%.o: src/sort/%.c
	@mkdir -p $(SORT_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

$(NAME): $(LIBFT) $(OBJ_FILES)
	@echo "Creating executable $@..."
	@$(CC) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "$$SHELL_ART"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

valgrind: $(NAME)
	@echo "Debugger Mode: Running Valgrind.."
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-limit=no --log-file=valgrind-out.txt ./$(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_DIR)*.o
	@rm -rf $(OBJ_DIR)
	@rm -f valgrind-out.txt
	@rm -f outfile
	@rm -f out
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Full clean..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@clear

re: fclean all

test: $(OBJ_FILES) $(LIBFT) $(NAME)
	@if [ -f .tester/test_push_swap.py ]; then \
		echo "Running push_swap tests..."; \
	else \
		git clone https://github.com/kr1-42/ps_test.git .tester; \
		echo "... now Running push_swap tests..."; \
	fi
	@python3 .tester/test_push_swap.py --tests=20 --min=-10000 --max=10000

testval: $(OBJ_FILES) $(NAME)
	@if [ -f .tester/test_push_swap.py ]; then \
		echo "Running push_swap tests..."; \
	else \
		git clone https://github.com/kr1-42/ps_test.git .tester; \
		echo "... now Running push_swap tests..."; \
	fi
	@python3 .tester/test_push_swap.py --valgrind --tests=100 --min=-10000 --max=10000

define SHELL_ART
                       @@
                    %@@@@
                 *@@@@@@@
               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&
            &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
         /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
           &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@
              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@%
                .@@@@@@@@                               @@@@@@@@
                   %@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                      @@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&
                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*
                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,
                            ///////////////////////////(@@@@@@@@@#
                                                        @@@@@@@
                                                        @@@@.
                                                        @(
endef
export SHELL_ART
