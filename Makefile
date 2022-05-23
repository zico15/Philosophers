# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/05/21 13:13:59 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_main.c \
					./mandatory/ft_mandatory.c \
					./mandatory/ft_mandatory_util.c \
					./bonus/ft_bonus.c \
					./program/philo.c \
					./program/table.c \
					./program/base.c  \
					./program/program.c

OBJS		= 		$(SRCS:.c=.o)
CC			= 		gcc
# -pthread -fsanitize=thread
CFLAGS		= 		-Wall -Wextra -Werror -pthread -fsanitize=thread
LIB			= 		ar rcs
RM			= 		/bin/rm -f
NAME		= 		philo

INCLUDE		= 		./headers

all			:		$(NAME)


$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean		:
					$(RM) $(OBJS)

fclean		:		clean
						$(RM) $(NAME)
				
m: fclean				

re			:		fclean all

m			: 		clean fclean

r			: 		
					make re && clear && ./philo
