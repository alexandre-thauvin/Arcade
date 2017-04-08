
NAME	=	snake

SRC	=	sources/Centipede.cpp \
		../src/core/src/Map.cpp \
		sources/Personnage.cpp \
		sources/Missile.cpp

SRC1	= sources/Snake.cpp \
	sources/Personnage.cpp \
	../src/core/src/Map.cpp

LIB_SNAKE     =	lib_arcade_snake.so

LIB_CENTI	= lib_arcade_centipede.so

OBJ	=       $(SRC:.cpp=.o)

GXX	=       g++

RM	=       rm -rf

CXXFLAGS=       -Wall -Werror -W -Wextra -I./includes/ -I../src/core/include/

$(NAME) :       $(OBJ)
		$(GXX) -o $(NAME) $(CXXFLAGS) $(OBJ)

lib	:
		$(eval CXXFLAGS += -shared -fPIC)
		$(GXX) -o $(LIB_CENTI) $(CXXFLAGS) $(SRC)
		$(GXX) -o $(LIB_SNAKE) $(CXXFLAGS) $(SRC1)

all	:       $(NAME)

clean   :
	        $(RM) $(OBJS)
	        $(RM) $(SRCS)/*~
	        $(RM) $(SRCS)/*#

fclean  :       clean
	        $(RM) $(NAME)
		$(RM) $(LIB)

re      :       fclean all
