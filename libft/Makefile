# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 14:12:06 by ksura             #+#    #+#              #
#    Updated: 2022/06/07 09:43:15 by ksura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC = gcc
CFLAGS := -Wall -Werror -Wextra
LIBRARIES = $(FT_LNK) 
INCLUDES = $(FT_INC)
HEADER = ./header
SRCDIR = src/
OBJDIR := build/

LIBFT = $(LIBFT_DIRECTORY)/libft.a
LIBFT_DIRECTORY = ./libft
FT_INC	= -I ./libft/
FT_LNK	= ./libft/libft.a



SRC := ft_uitoa.c ft_printf.c ft_hex.c helper.c

OBJS = ${SRC:.c=.o}
OBJECTS_PREF := $(addprefix $(OBJDIR), $(OBJS))

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_PREF) $(OBJDIR)
	@ar rcs $(NAME) $(OBJECTS_PREF)
	
$(LIBFT):
	cd ./$(LIBFT_DIRECTORY) && make all
	cp libft/libft.a .
	mv libft.a $(NAME)
	
$(OBJECTS_PREF): build/%.o : src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER) $(INCLUDES)

clean:
	cd ./$(LIBFT_DIRECTORY) && make clean
	rm -rf $(OBJDIR)

fclean: clean
	cd ./$(LIBFT_DIRECTORY) && make fclean
	rm -f $(NAME)

re: fclean all