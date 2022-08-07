# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/08/07 14:40:56 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_main.c \
					base.c \
					ft_mandatory.c \
					philo.c \
					table.c \
					table_util.c \
					util.c

OBJS		= 		$(SRCS:.c=.o)
CC			= 		gcc -Wall -Wextra -Werror  -pthread 
CCF			=       -fsanitize=thread -Wno-error=whatever
LIB			= 		ar rcs
RM			= 		/bin/rm -f
NAME		= 		philo

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(^) -o $(@)
		
%.o: %.c
	@$(CC) -c $(^) -o $(@)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
						$(RM) $(NAME)
				
m: fclean				

re			:		fclean all

m			: 		clean fclean

r			: 		
					make re && clear && ./philo
