# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:33:58 by ggiertzu          #+#    #+#              #
#    Updated: 2023/06/02 04:46:58 by ggiertzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Werror -Wall -Wextra
RM = rm -f

SRCS = ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c \
ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c \
ft_striteri.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c \
ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c \
ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c \
ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c

BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS:.c=.o)

DEPS = $(SRCS:.c=.d)
BNS_DEPS = $(BNS:.c=.d)

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(DEPS)
	ar rcs $@ $^

$(DEPS): %.d: %.c
	$(CC) $(CFLAGS) -MM $< -MT $(@:.d=.o) >$@

include $(DEPS)

bonus: $(BNS_OBJS) $(OBJS) $(HEADER) $(DEPS) $(BNS_DEPS)
	ar rcs $(NAME) $^

$(BNS_DEPS): %.d: %.c
	$(CC) $(CFLAGS) -MM $< -MT $(@:.d=.o) >$@

include $(BNS_DEPS)

clean:
	${RM} $(OBJS) $(BNS_OBJS) $(DEPS) $(BNS_DEPS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

# $@ refers to target name; $^ all prerequisites; $< refers to first matching object
#%.o: %.c   <-- this is an implicit rule and does not need to be written
#   $(CC) $(CFLAGS) -c $< -o $@

