##
## EPITECH PROJECT, 2019
## PSU_minishell1_2018
## File description:
## __Makefile__
##

CC	=	@gcc -O3

MAKEFLAGS	+=	--no-print-directory

RM	=	rm -f

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;01;033m"
TEAL		=	"\033[1;01;35m"
RED			=	"\033[1;01;31m"

CFLAGS	+=	-I./include

NAME	=	generator

SRC		=	main.c		\
			back_tracking/create_labyrinth.c	\
			mini_lib/lib_number.c	\
			rule/rule_labyrinth.c	\
			back_tracking/read_lab.c	\
			rule/rule_two.c

SRCS	=	$(SRC)

OBJS	=	$(SRCS:.c=.o)

all		:	title $(NAME) endt
			@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : Generator\n" $(DEFAULT)

endt:
			@$(ECHO) $(RED)"\n → [Labyrinth create]\n" $(DEFAULT)

$(NAME)		:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) &&			\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)
			@cp generator ../tournament
			@make clean

.c.o		:
			@$(CC) $(CFLAGS) -c $< -o $@ &&				\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

tests_run	:
			make -C./tests/ all

clean:
			@$(RM) $(OBJS)

fclean:			clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
