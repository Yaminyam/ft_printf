# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 22:34:46 by sikang            #+#    #+#              #
#    Updated: 2021/10/13 18:04:05 by sion             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEADER = ft_printf.h
NAME = libftprintf.a
SRCS = \
ft_printf.c \
ft_treat.c \
ft_uitoa.c \
ft_ull_base.c

BONUSES =

OBJS	= $(SRCS:.c=.o)
OBJS_BONUS = $(BONUSES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar crs $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	cp $(LIBFT) $(NAME)
	ar crs $(NAME) $^

.PHONY: all bonus clean fclean re
