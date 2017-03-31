
NAME	= snake

SRCS1	= sources/Snake.cpp

LIB     = lib_arcade_snake.so

NAME1   = lib_snake.so

OBJS	= $(SRCS:.cpp=.o)

OBJS1   = $(SRCS1:.cpp=.o)

GXX	= g++

RM	= rm -rf

CXXFLAGS	= -Wall -Werror -W -Wextra -I includes/


$(LIB): $(OBJS1)
	$(GXX) -shared -fpic -o $(NAME1) $(CXXFLAGS) $(SRCS1)

$(NAME): $(OBJS)
	$(GXX) -o $(NAME) $(CXXFLAGS) $(SRCS)

lib: $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(SRCS)/*~
	$(RM) $(SRCS)/*#

fclean: clean
	$(RM) $(NAME)

re: fclean all
