NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./my_libft/
LIBFT = $(LIBFT_DIR)libft.a
OBJ_DIR = .obj/

MOVES_DIR = .obj/moves/
UTILS_DIR = .obj/utils/

INC_DIR = headers/


MAIN_SRC = main.c
# Add a list of your push_swap source files here
SRC_FILES = $(addprefix src/,str_parsing.c \
	lst_parsing.c \
	arg_checker.c)

UTILS_SRC_FILES = $(addprefix src/utils/,free_mem.c \
	has_dup.c \
	ft_err.c)

MOVES_SRC_FILES = $(addprefix src/moves/,ft_push.c \
	ft_rotate.c \
	ft_reverse_rotate.c \
	ft_swap.c)

OBJ_FILES = $(MAIN_SRC:%.c=$(OBJ_DIR)%.o) \
			$(SRC_FILES:src/%.c=$(OBJ_DIR)%.o) \
			$(MOVES_SRC_FILES:src/moves/%.c=$(MOVES_DIR)%.o) \
			$(UTILS_SRC_FILES:src/utils/%.c=$(UTILS_DIR)%.o)

CFLAGS += -I$(INC_DIR)


NC = \033[0m

all: pre-build $(OBJ_DIR) $(NAME)

pre-build:
	@clear
	@echo "Starting compilation..."

$(OBJ_DIR): $(MOVES_DIR) $(UTILS_DIR)
	@mkdir -p $(OBJ_DIR)

$(UTILS_DIR):
	@mkdir -p $(UTILS_DIR)

$(MOVES_DIR):
	@mkdir -p $(MOVES_DIR)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@ successfully!"

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
