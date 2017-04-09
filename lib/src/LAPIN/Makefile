CXX		=		g++

RM		=		rm -rf

NAME		=		../../lib_arcade_lapin.so

SRC		=		lib.cpp

CXXFLAGS	=		-W -Wall -Wextra
CXXFLAGS	+=		-I../../include/ -I../../../src/core/include/
CXXFLAGS	+=		-fPIC

LDFLAGS		+=		-L./ -shared -L${HOME}/.froot/lib/
LDFLAGS		+=		-llapin -lsfml-graphics -lsfml-audio -lsfml-window      \
                                            -lsfml-system -lstdc++ -lm -ldl -lpthread

OBJ 		=		$(SRC:.cpp=.o)

$(NAME) 	:		$(OBJ)
				$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

all 		:	 	$(NAME)

clean		:
				$(RM) $(OBJ)

fclean		:		clean
				$(RM) $(NAME)

re		:		fclean all
