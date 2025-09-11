SERVER		= server
CLIENT		= client

SERVER_SRC	= server.c
CLIENT_SRC	= client.c

SERVER_OBJ	= $(SERVER_SRC:.c=.o)
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I src -I src/Printf

SRC_DIR		= src
PRINTF_DIR	= $(SRC_DIR)/Printf

SRC_FILES	= $(SRC_DIR)/ft_atoi.c
PRINTF_FILES = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_convert.c $(PRINTF_DIR)/ft_2convert.c

OBJ_FILES	= $(SRC_FILES:.c=.o) $(PRINTF_FILES:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(OBJ_FILES) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(OBJ_FILES) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(OBJ_FILES)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re