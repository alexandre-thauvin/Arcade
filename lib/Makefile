##
## Makefile for  in /home/cedric/workTek2/cpp_arcade/lib
## 
## Made by Cedric
## Login   <cedric.clemenceau@epitech.eu>
## 
## Started on  Tue Mar 28 13:39:30 2017 Cedric
## Last update Wed Mar 29 16:04:47 2017 Cedric
##

CC		= g++-6

RM		= rm -f

CPPFLAGS	= -I./include/ `sdl-config --cflags --libs` -lSDL -std=c++11 -Wall -Wextra -fpic

PATHSDL		= src/SDL/

PATHNCUSES	= src/NCURSES/

SRCSDL		= $(PATHSDL)lib.cpp

#SRCNCURSES	= #$(PATHNCURSES)lib.cpp

#SRCOPENGL	= 

OBJSDL		= $(SRCSDL:.cpp=.o)

OBJNCURSES	= $(SRCNCURSES:.cpp=.o)

OBJOPENGL	= $(SRCOPENGL:.cpp=.o)

NAMESDL		= lib_arcade_sdl.so

NAMENCURSES	= lib_arcade_ncurses.so

NAMEOPENGL	= lib_arcade_opengl.so

name	: $(OBJSDL) #$(OBJNCURSES) $(OBJOPENGL)
	  $(CC) -shared -o $(NAMESDL) $(OBJSDL)
#	  $(CC) -shared -o $(NAMENCURSES) $(OBJNCURSES)
#	  $(CC) -shared -o $(NAMEOPENGL) $(OBJOPENGL)

all	: name

clean	:
	  $(RM) $(OBJSDL)
	  $(RM) $(OBJNCURSES)

fclean	: clean
	  $(RM) $(NAMESDL)
	  $(RM) $(NAMENCURSES)

re	: fclean all

.PHONY	: re clean fclean all
