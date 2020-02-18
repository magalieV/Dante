##
## EPITECH PROJECT, 2019
## CPE_dante_2018
## File description:
## __DESCRIPTION__
##

createlib:
	make -C generator
	make -C solver

clean:
	make clean -C generator
	make clean -C solver

fclean:
	make fclean -C generator
	make fclean -C solver
	rm -rf tournament/generator
	rm -rf tournament/solver

re:	fclean all
