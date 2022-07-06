# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 09:24:12 by ksura             #+#    #+#              #
#    Updated: 2022/07/06 12:07:47 by ksura@student.42 ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
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
FT_LNK	= ./libft/libftprintf.a



SRC := main.c errors.c swapping.c pushing.c rotating.c revrotating.c\
	sorting_ruling.c sortfive.c sortbig.c utils_sortbig.c utils2_sortbig.c

OBJS = ${SRC:.c=.o}
OBJECTS_PREF := $(addprefix $(OBJDIR), $(OBJS))

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_PREF) $(OBJDIR)
	$(CC) $(FLAGS) $(OBJECTS_PREF) $(LIBRARIES) -I$(HEADER) -o $(NAME)
	@echo "$(NAME) was created"
	
$(LIBFT):
	cd ./$(LIBFT_DIRECTORY) && make all
	
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

debug: $(LIBFT) bonus $(OBJECTS_PREF) $(OBJDIR)
	$(CC) $(FLAGS) $(OBJECTS_PREF) $(LIBRARIES) -I$(HEADER) -o $(NAME) -g