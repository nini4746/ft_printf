# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 13:46:24 by yunhpark          #+#    #+#              #
#    Updated: 2024/11/08 19:25:29 by yunhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./srcs
INCLUDE_DIR = ./include

LIBFT_SRCS = $(shell find $(LIBFT_DIR) -name "ft_*.c")
FT_PRINTF_SRCS = $(shell find $(FT_PRINTF_DIR) -name "ft_*.c")

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	$(AR) $(NAME) $(FT_PRINTF_OBJS)

clean:
	rm -f $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(BONUS_OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	rm -f $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(BONUS_OBJS) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus


