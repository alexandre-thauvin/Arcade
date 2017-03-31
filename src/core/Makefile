##
## Makefile for  in /home/thauvi_a/rendu/tek2/cpp/cpp_arcade
##
## Made by Alexandre Thauvin
## Login   <thauvi_a@epitech.net>
##
## Started on  Mon Mar  6 14:29:08 2017 Alexandre Thauvin
## Last update Wed Mar 29 18:47:40 2017 Paul THEIS
##

DEBUG			?=		yes

VERSION			?=		0.1

PARAM			?=

NAME			=		../../arcade

SRCS			=		main.cpp \
                    DrawObject.cpp \
					Core.cpp \
					Error.cpp

GAMES			=		games/

CORE			=		src/core

GFX			=		lib/

CC			=		g++
AR			=		ar
RM			=		rm -Rf

ifeq ($(DEBUG), yes)
CXXFLAGS		=		-W -Wall -Wextra -g -pg -ansi
else
CXXFLAGS		=		-W -Wall -Wextra -Werror -ansi
endif
CXXFLAGS                +=		-std=c++11 -fPIC
CXXFLAGS		+=		-I./include/

LDFLAGS			+=		-ldl

GREEN			=		\033[1;32m
YELLOW			=		\033[1;33m
BLUE			=		\033[1;34m
WHITE			=		\033[0m

OBJDIR			=		obj
SRCDIR			=		src
SRCDIRS			=		$(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)/./g' )
OBJS			=		$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, \
							$(addprefix $(SRCDIR)/, $(SRCS)))

name			:		buildrepo project_compil

project_compil		:		$(OBJS)
					$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
					@echo "$(GREEN)\n<--->\t ♩♪♫ $(NAME) $(YELLOW)" \
					" Compiled Sucesfully $(WHITE)\n"

all			:		name

clean			:
					$(RM) $(OBJDIR)

fclean			:		clean
					$(RM) $(NAME) $(LIBDIR)

re			:		fclean all

val			:
					@make re && valgrind ./$(NAME) $(PARAM)

val+			:
					@make re && valgrind --leak-check=full ./$(NAME) $(PARAM)

exe			:
					@make re && ./$(NAME) $(PARAM)

.PHONY			:		all clean fclean re

$(OBJDIR)/%.o		:	 	$(SRCDIR)/%.cpp
					@$(CC) -c $< -o $@ $(CXXFLAGS)
					@echo "$(BLUE)<SRC> \t [√] $<\t$(WHITE)"

$(OBJDIR)/$(BASICDIR)/%.o: 		$(BASICDIR)/%.cpp
					@$(CC) -c $< -o $@ $(CXXFLAGS)
					@echo "$(YELLOW)<LIB> \t [√] $<\t$(WHITE)"

buildrepo		:
					@$(call make-repo)
					@echo "$(GREEN)\n<--->\t ♩♪♫ $(NAME) $(YELLOW)" \
					" Repository Init $(WHITE)\n"
print-%			:
					@echo '$*=$($*)'

define make-repo
					for dir in $(SRCDIRS); \
					do \
					mkdir -p $(OBJDIR)/$$dir; \
					done
endef
