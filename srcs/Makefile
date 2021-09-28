CC = gcc

CFLAGS = -Werror -Wall -Wextra

LIBFT = ../libft/libft.a

SERVER = server
SERVER_SRCS = server.o

CLIENT = client
CLIENT_SRCS = client.o

all : $(SERVER) $(CLIENT)

$(CLIENT) : $(CLIENT_SRCS)
	@$(CC) $(LIBFT) $(CLIENT_SRCS) -o $(CLIENT)
	@printf "\e[32m$@ built\e[0m\n"

$(SERVER) : $(SERVER_SRCS)
	@$(CC) $(LIBFT) $(SERVER_SRCS) -o $(SERVER)
	@printf "\e[32m$@ built\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c 

clean :
	@rm -f client.o server.o
	@printf "\e[31mclean done\e[0m\n"

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[31mfclean done\e[0m\n"

re : fclean all

.PHONY: all clean fclean re