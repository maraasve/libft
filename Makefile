# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 13:21:46 by marieke           #+#    #+#              #
#    Updated: 2025/07/04 17:07:09 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCL_DIR) -isystem $(INCL_DIR)
AR = ar -rcs
SRC_DIR = src
BONUS_SRC_DIR = src/bonus
BUILD_DIR = build
OBJ_DIR = build/obj
INCL_DIR = incl
BONUS_OBJ_DIR = build/obj_bonus

SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRC = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
BONUS_SRCS = $(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BONUS_OBJ = $(patsubst $(BONUS_SRC_DIR)/%.c, $(BONUS_OBJ_DIR)/%.o, $(BONUS_SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $?

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $^

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re