
all:
	make -C ./src/core/
	make -C ./lib

re:	fclean all

clean:
	make clean -C ./src/core/
	make clean -C ./lib

fclean:
	make fclean -C ./src/core/
	make fclean -C ./lib

exe:
	make exe -C ./src/core/
