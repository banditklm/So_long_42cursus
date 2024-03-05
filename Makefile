NAME = so_long
BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = mandatory/sources/so_long.c mandatory/sources/parser.c mandatory/sources/parser2.c \
mandatory/sources/utils.c mandatory/sources/utils2.c mandatory/sources/get_next_line.c \
mandatory/sources/get_next_line_utils.c mandatory/sources/parser3.c mandatory/sources/flood_parser.c \
mandatory/sources/window.c mandatory/sources/moves.c mandatory/sources/read_map.c

SRCSB = bonus/so_long_bonus.c bonus/parser_bonus.c bonus/parser2_bonus.c bonus/parser3_bonus.c \
bonus/get_line_bonus.c bonus/get_line_utils_bonus.c bonus/read_map_bonus.c bonus/flood_parser_bonus.c \
bonus/utils_bonus.c bonus/utils2_bonus.c bonus/window_bonus.c bonus/moves_bonus.c bonus/utils3_bonus.c \
bonus/animation_bonus.c bonus/animation2_bonus.c

HEADERS = mandatory/headers/so_long.h
HEADERSB = bonus/so_long_bonus.h

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

FTPRINT = lib

all : $(FTPRINT) $(NAME)

bonus : $(FTPRINT) $(BONUS)

$(BONUS) : $(OBJSB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -Lft_printf -lftprintf $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) -Lft_printf -lftprintf $^ -o $@

$(FTPRINT) :
	make -C ft_printf

$(OBJS): %.o: %.c  $(HEADERS) ft_printf/libftprintf.a Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSB): %.o: %.c  $(HEADERSB) ft_printf/libftprintf.a Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ft_printf
	rm	-f $(OBJS) $(OBJSB)

fclean : clean
	make fclean -C ft_printf
	rm	-f $(NAME) $(BONUS)

re : fclean all

.PHONY : clean $(FTPRINT)
