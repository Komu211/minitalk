NAME_SERVER = server
NAME_CLIENT = client
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OUT_DIR = out

VPATH = $(SRC_DIR)

SRC_SERVER = server.c
SRC_CLIENT = client.c

# Object files
OBJ_SERVER = $(addprefix $(OUT_DIR)/, $(SRC_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(OUT_DIR)/, $(SRC_CLIENT:.c=.o))

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/includes

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: all

# Create output directory
$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

# Build server
$(NAME_SERVER): $(OUT_DIR) $(OBJ_SERVER) $(LIBFT)
	$(CC) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

# Build client
$(NAME_CLIENT): $(OUT_DIR) $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

# Compile source files
$(OUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re