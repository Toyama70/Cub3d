# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 10:31:02 by ybestrio          #+#    #+#              #
#    Updated: 2022/02/17 10:40:19 by ybestrio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME1 = cub3d

SRCS1 = parser.c error.c datadivider.c exception.c matrix.c\
		makers.c get_next_line_utils.c get_next_line.c\

OBJS1 = $(SRCS1:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME1): $(OBJS1)
	$(CC) $(OBJS1) -lmlx -framework OpenGL -framework AppKit -o $(NAME1)

all:	$(NAME1)

clean:
		$(RM) $(OBJS1)

fclean:	clean
		$(RM) $(NAME1)

re:		fclean all

.PHONY: all clean fclean re
