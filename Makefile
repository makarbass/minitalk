SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = srcs/server.c
SRCS2 = srcs/client.c
SRCS_BONUS = srcs_bonus/server_bonus.c
SRCS2_BONUS = srcs_bonus/client_bonus.c

OBJS		= ${SRCS:.c=.o}
OBJS2		= ${SRCS2:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}
OBJS2_BONUS		= ${SRCS2_BONUS:.c=.o}

LIBFT = libft/libft.a

all:	$(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
		@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(SERVER)
		@printf "\e[32m$@ built\e[0m\n"

$(CLIENT): $(OBJS2)
		@$(CC) $(CFLAGS) $(LIBFT) $(OBJS2) -o $(CLIENT)
		@printf "\e[32m$@ built\e[0m\n"

$(LIBFT):
	make -C libft

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJS_BONUS)
		@$(CC)  $(CFLAGS) $(LIBFT) $(OBJS_BONUS) -o $(SERVER_BONUS)
		@printf "\e[32m$@ built\e[0m\n"

$(CLIENT_BONUS): $(OBJS2_BONUS)
		@$(CC) $(CFLAGS) $(LIBFT) $(OBJS2_BONUS) -o $(CLIENT_BONUS)
		@printf "\e[32m$@ built\e[0m\n"

clean:
	@$(RM) $(OBJS) $(OBJS2) $(OBJS_BONUS) $(OBJS2_BONUS)
	make clean -C ./libft
	@printf "\e[31mclean done\e[0m\n"

fclean:	clean
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make fclean -C ./libft
	@printf "\e[31mfclean done\e[0m\n"

re:		fclean all

.PHONY: all clean fclean re