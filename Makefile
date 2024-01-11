#################
##  VARIABLES  ##
#################

#	Libft Makefile path
LIBFTDIR = ./Libft

#	Sources
SRCDIR = ./src
SRC = main.c \
	  ft_printf_utils.c \
	  ft_print_hex.c \
	  ft_print_ptr.c \
	  ft_print_unsigned.c

#	Objects
OBJDIR = ./obj

#	Includes
INCDIR = ./include

#	Libraries
LIBDIR = 
LIBS = 

#	Output
NAME = libftprintf.a

#	Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

##############
##  COLORS  ##
##############

CLEAN_COLOR = 9
CLEAN_COLOR_T = 196
LINK_COLOR = 47
LINK_COLOR_T = 46
OBJ_COLOR = 122
OBJ_COLOR_T = 123
NORM_COLOR = 153
NORM_COLOR_T = 141
NORM_COLOR_ERR = 160
NORM_COLOR_WAR = 214
RUNT_COLR_T = 7
RUN_COLOR = 147

############
##  AUTO  ##
############

OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(basename $(SRC))))
INCFLAG = $(addprefix -I,$(INCDIR))
NORME = $(addsuffix /*.h,$(INCDIR)) $(addprefix $(SRCDIR)/,$(SRC))

###############
##  TARGETS  ##
###############
