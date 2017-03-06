##
## Makefile for  in /home/thauvi_a/rendu/tek2/cpp/cpp_arcade
##
## Made by Alexandre Thauvin
## Login   <thauvi_a@epitech.net>
##
## Started on  Mon Mar  6 14:29:08 2017 Alexandre Thauvin
## Last update Mon Mar  6 14:39:19 2017 Alexandre Thauvin
##

NAME		= arcade

PATH		= games/sources/

SRCS		=

OBJS		= $(SRCS:.cpp=.o)

GCC		= g++

RM		= rm -rf

CXXFLAGS	= -Wall -Werror -W -Wextra -I ./games/includes


$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME) $(CXXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) games/sources/*~
	$(RM) games/sources/*#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:         all clean fclean re
