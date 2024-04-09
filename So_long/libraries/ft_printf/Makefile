NAME = libftprintf.a

SRCS = ft_printf.c\
       ft_printchar.c\
       ft_printstr.c\
       ft_printptr.c\
       ft_printnbr.c\
       ft_print_unsint.c\
       ft_printhex.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
