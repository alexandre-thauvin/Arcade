CXX		=		g++-6

RM		=		rm -rf

NAME		=		lib_arcade_sdl.so

SRC		=		lib.cpp

CXXFLAGS	=		-W -Wall -Wextra
CXXFLAGS	+=		-I../../include/ -I../../../src/core/include/
CXXFLAGS	+=		-fPIC

LDFLAGS		+=		-L./ -shared
LDFLAGS		+=		-lncurses

OBJ 		=		$(SRC:.cpp=.o)

$(NAME) 	:		$(OBJ)
				$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

all 		:	 	$(NAME)

clean		:
				$(RM) $(OBJ)

fclean		:		clean
				$(RM) $(NAME)

re		:		fclean all
