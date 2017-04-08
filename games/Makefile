
NAME	=	snake

SRC	=	sources/Centipede.cpp \
		../src/core/src/Map.cpp \
		sources/Personnage.cpp \
		sources/Missile.cpp

LIB     =	lib_arcade_centipede.so

OBJ	=       $(SRC:.cpp=.o)

GXX	=       g++

RM	=       rm -rf

CXXFLAGS=       -Wall -Werror -W -Wextra -I./includes/ -I../src/core/include/

$(NAME) :       $(OBJ)
		$(GXX) -o $(NAME) $(CXXFLAGS) $(OBJ)

lib	:
		$(eval CXXFLAGS += -shared -fPIC)
		$(GXX) -o $(LIB) $(CXXFLAGS) $(SRC)

all	:       $(NAME)

clean   :
	        $(RM) $(OBJS)
	        $(RM) $(SRCS)/*~
	        $(RM) $(SRCS)/*#

fclean  :       clean
	        $(RM) $(NAME)
		$(RM) $(LIB)

re      :       fclean all
