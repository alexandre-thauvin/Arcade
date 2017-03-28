
all:
	make -C ./src/core/

re:	fclean all

clean:
	make clean -C ./src/core/

fclean:
	make fclean -C ./src/core/

exe:
	make exe -C ./src/core/
