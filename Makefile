# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 13:21:46 by marieke           #+#    #+#              #
#    Updated: 2024/07/26 14:33:06 by maraasve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
AR = ar -rcs

SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_abs.c ft_realloc.c ft_strlcpy_esc.c \
	ft_strcmp_nb.c get_next_line.c get_next_line_utils.c ft_is_str_nb.c \
	ft_str_int_range.c ft_isspace.c
BSOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
OBJECTS_DIR = obj
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES:.c=.o))
BOBJECTS_DIR = obj_bonus
BOBJECTS = $(addprefix $(BOBJECTS_DIR)/, $(BSOURCES:.c=.o))

all: $(NAME)

$(OBJECTS_DIR)/%.o: %.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BOBJECTS_DIR)/%.o: %.c | $(BOBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJECTS)
	@$(AR) $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	@$(AR) $(NAME) $?

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(BOBJECTS_DIR):
	@mkdir -p $(BOBJECTS_DIR)

clean:
	@rm -rf $(OBJECTS_DIR) $(BOBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re