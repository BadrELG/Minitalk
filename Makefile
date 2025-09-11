SERVER		= server
CLIENT		= client

SERVER_SRC	= server.c
CLIENT_SRC	= client.c

SERVER_OBJ	= $(SERVER_SRC:.c=.o)
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I LibFt

LIBFT_DIR	= LibFt
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re