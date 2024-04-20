NAME =		libftprintf.a

INCLUDE =	include/

LIBFT =		libft/

SRCS =		src/ft_printf.c src/ft_printf_utils.c

OBJS =		$(SRCS:.c=.o)

CC = 		cc

CFLAGS =	-Wall -Wextra -Werror -I

AR =		ar rcs

RM =		rm -f

all:		$(NAME)

$(NAME): 	$(OBJS)
		make -C $(LIBFT)
		cp $(LIBFT)libft.a .
		mv libft.a $(NAME)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean: 	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re:		fclean all

.PHONY:		all clean fclean re
