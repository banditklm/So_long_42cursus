NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchr.c ft_putstr.c ft_putnbr.c ft_putunsnbr.c ft_puthex.c ft_putadd.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	ar rsc $(NAME) $(OBJS)

%.o:%.c ft_printf.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
