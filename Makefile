
all:
	make -C ./src/core/
	make -C ./lib/src/SDL/
	make -C ./lib/src/NCURSES/
	make lib -C ./games/

re:	fclean all

clean:
	make clean -C ./src/core/
	make clean -C ./lib/src/SDL/
	make clean -C ./lib/src/NCURSES/
	make clean -C ./games/

fclean:
	make fclean -C ./src/core/
	make fclean -C ./lib/src/SDL/
	make fclean -C ./lib/src/NCURSES/
	make fclean -C ./games/


