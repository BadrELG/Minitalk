NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
INCLUDE = .

SRCS =  ft_printf.c \
		ft_convert.c \
		ft_2convert.c \

OBJS = ${SRCS:.c=.o}

rm = rm -f

%.o : %.c
	${CC} $(CFLAGS) -c $< -o $@

${NAME}: $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean $(NAME)