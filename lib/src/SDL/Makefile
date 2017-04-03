CXX		=		g++-6

RM		=		rm -rf

NAME		=		lib_arcade_sdl.so

SRC		=		lib.cpp

CXXFLAGS	=		-W -Wall -Wextra
CXXFLAGS	+=		-I../../include/ -I../../../src/core/include/
CXXFLAGS	+=		-fPIC

LDFLAGS		+=		-L../../lib/ -shared
LDFLAGS		+=		-lSDL2 -lSDL2_image

OBJ 		=		$(SRC:.cpp=.o)

all 		:	 	$(NAME)

$(NAME) 	:		$(OBJ)
				$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean		:
				$(RM) $(OBJ)

fclean		:		clean
				$(RM) $(NAME)

re		:		fclean all
