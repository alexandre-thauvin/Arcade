GXX		=		g++

CXXFLAGS        =               -W -Wall -Wextra -std=c++11
CXXFLAGS        +=              -I./includes/ -I../src/core/include/
CXXFLAGS        +=              -fPIC

RM		=		rm -rf

LDFLAGS         +=              -shared

SRC_C		=		sources/Centipede.cpp \
				../src/core/src/Map.cpp \
				sources/Personnage.cpp \
				sources/Missile.cpp

SRC_S		=		sources/Snake.cpp \
				../src/core/src/Map.cpp \
				sources/Personnage.cpp

LIB_C		=		lib_arcade_centipede.so

LIB_S		=		lib_arcade_snake.so

OBJ_C		=		$(SRC_C:.cpp=.o)

OBJ_S		=		$(SRC_S:.cpp=.o)

lib   :		$(OBJ_S) $(OBJ_C)      
		$(GXX) $(LDFLAGS) -o $(LIB_S) $(OBJ_S)
		$(GXX) $(LDFLAGS) -o $(LIB_C) $(OBJ_C)

all	:       lib

clean   :
	        $(RM) $(OBJ_S)
	        $(RM) $(OBJ_C)
	        $(RM) $(SRCS)/*~
	        $(RM) $(SRCS)/*#

fclean  :       clean
		$(RM) $(LIB_C)
		$(RM) $(LIB_S)

re      :       fclean all
