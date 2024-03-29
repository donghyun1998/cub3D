# compile options
NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
MLX			= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT		= -Llibft -lft

# color
RESET		= \033[0m
GREEN		= \033[1;92m
CYAN		= \033[1;96m

# source files
CUB_DIR		= srcs/

CUB_SRCS	= main.c				\
			  init.c				\
			  parse_map_element.c	\
			  parse_map.c			\
			  check_map.c			\
			  map_utils.c			\
			  draw.c				\
			  raycast.c				\
			  game.c				\
			  list.c				\
			  vector.c				\
			  utils.c				\

CUB_PATH	= $(addprefix $(CUB_DIR), $(CUB_SRCS))
CUB_OBJS	= $(CUB_PATH:c=o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(CUB_OBJS)
	make -C mlx all
	@make -sC libft all
	@$(CC) $(CFLAGS) $(MLX) $(LIBFT) $^ -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                     cub3D                     ║$(RESET)"
	@echo "$(GREEN)║               compile finished.               ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	make -C mlx clean
	@make -C libft clean
	@$(RM) $(CUB_OBJS)
	@echo "$(CYAN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║              make clean finished.             ║$(RESET)"
	@echo "$(CYAN)╚═══════════════════════════════════════════════╝$(RESET)"

fclean:
	@make -C libft fclean
	@make clean
	@$(RM) $(NAME)
	@echo "$(CYAN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║             make fclean finished.             ║$(RESET)"
	@echo "$(CYAN)╚═══════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
