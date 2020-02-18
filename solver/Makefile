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

NAME	=	solver

SRC		=	main.c		\
			src/get_next_line.c		\
			src/my_str_to_word_array.c	\
			src/found_exit.c	\
			src/read_file_given.c

SRCS	=	$(SRC)

OBJS	=	$(SRCS:.c=.o)

all		:	title $(NAME) endt
			@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : Solver\n" $(DEFAULT)

endt:
			@$(ECHO) $(RED)"\n → [Solver create]\n" $(DEFAULT)

$(NAME)		:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) &&			\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)
			@cp solver ../tournament
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
