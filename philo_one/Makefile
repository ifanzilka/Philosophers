# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 04:32:49 by bmarilli          #+#    #+#              #
#    Updated: 2021/05/11 04:32:53 by bmarilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

CC		= gcc

HEADERS	= ./includes

FLAGS	= -Wall -Wextra -Werror -pthread 

OBJS	= $(SRCS:.c=.o)

DIR		= ./srcs/

SRCS = $(addprefix $(DIR),ft_error.c ft_parse.c  ft_init_phil.c ft_start_philo.c \
			ft_free_and_destroy.c ft_other_print.c  ft_philo_sleep.c ft_philo_thinking.c ft_time.c main.c)

OBJS	= $(SRCS:.c=.o)


F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m


all: $(NAME)

$(NAME):	$(OBJS) $(HEADERS)
		$(CC) $(FLAGS)  -I$(HEADERS) $(OBJS) -o $(NAME)
		@echo "$(F_GREEN)$(NAME) Compile! $(F_NONE)"


# 	обьектные файлы зависят от такоего же файла только .c  и от хейдера					
$(OBJS): %.o:%.c  ./includes/ft_philosophers.h
	$(CC) $(FLAGS) -I$(HEADERS) -c $< -o $@
	@echo "$(F_BLUE)Object files in ready! $(F_NONE)"


clean:
		rm $(OBJS) 
		@echo "$(F_GREEN)Object files  delete! $(F_NONE)"

fclean:		clean
			rm $(NAME)
			@echo "$(F_GREEN)Delete $(NAME) FCleaned! $(F_NONE)"

re:	fclean all

norm:
	norminette *.c *.h

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01   1   011"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE) 010   1   110"
	@echo "$(F_BLUE)   11011010**$(F_NONE)"

.PHONY:     all clean fclean re bonus code
