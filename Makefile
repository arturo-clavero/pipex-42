# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artclave <artclave@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:33:22 by artclave          #+#    #+#              #
#    Updated: 2024/01/16 18:56:16 by artclave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CODEDIR=. srcs libft
INCLUDEDIR=. ./include/
CC=cc
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -Werror -g $(foreach D,$(INCLUDEDIR),-I$(D)) $(DEPFLAGS)
CFILES=$(foreach D,$(CODEDIR),$(wildcard $(D)/*.c))
OBJ=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(NAME) $(OBJ) $(DEPFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPFILES)
