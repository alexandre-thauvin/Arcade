
all:
	make -C ./src/core/
	make -C ./lib/src/SDL/
	make -C ./lib/src/NCURSES/

re:	fclean all

clean:
	make clean -C ./src/core/
	make clean -C ./lib/src/SDL/
	make clean -C ./lib/src/NCURSES/

fclean:
	make fclean -C ./src/core/
	make fclean -C ./lib/src/SDL/
	make fclean -C ./lib/src/NCURSES/

