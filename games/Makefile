
NAME	= snake

SRCS	= sources/*.cpp

LIB     = lib_arcade_snake.so

OBJS	= $(SRCS:.cpp=.o)

GCC	= g++

RM	= rm -rf

CXXFLAGS	= -Wall -Werror -W -Wextra -I includes/ -g


$(NAME): $(OBJS)
	$(GCC) -o $(NAME) $(CXXFLAGS) $(SRCS)

all:$(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(SRCS)/*~
	$(RM) $(SRCS)/*#

fclean: clean
	$(RM) $(NAME)

re: fclean all
