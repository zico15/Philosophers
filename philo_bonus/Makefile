# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/08/06 17:25:19 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_main.c \
					base.c \
					ft_bonus.c \
					philo.c \
					table.c \
					util.c

OBJS		= 		$(SRCS:.c=.o)
CC			= 		gcc -Wall -Wextra -Werror
CCF			=       -pthread -fsanitize=thread
LIB			= 		ar rcs
RM			= 		/bin/rm -f
NAME		= 		philo_bonus

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CCF) $(^) -o $(@)
		
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
					make re && clear && ./$(NAME) 
