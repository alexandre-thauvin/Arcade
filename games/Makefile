
NAME	=	snake

SRC	=	sources/Snake.cpp

LIB     =	lib_arcade_snake.so

OBJ	=       $(SRC:.cpp=.o)

GXX	=       g++

RM	=       rm -rf

CXXFLAGS=       -Wall -Werror -W -Wextra -I./includes/

$(NAME) :       $(OBJ)
		$(GXX) -o $(NAME) $(CXXFLAGS) $(OBJ)

lib	:       $(OBJ)
		$(eval CFLAGS += -shared -fpic)
		$(GXX) -o $(LIB) $(CXXFLAGS) $(OBJ)

all	:       $(NAME)

clean   :
	        $(RM) $(OBJS)
	        $(RM) $(SRCS)/*~
	        $(RM) $(SRCS)/*#

fclean  :       clean
	        $(RM) $(NAME)
		$(RM) $(LIB)

re      :       fclean all
