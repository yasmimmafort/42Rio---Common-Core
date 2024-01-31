# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yathayde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:33:10 by yathayde          #+#    #+#              #
#    Updated: 2023/10/20 11:34:23 by yathayde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_isascii.c \
		ft_strchr.c ft_isprint.c ft_strrchr.c ft_strlen.c ft_strncmp.c \
		ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c \
		ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
		ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c \
		ft_striteri.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstiter_bonus.c \
		ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I.

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
