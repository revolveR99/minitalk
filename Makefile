CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

CLIENT_C = client.c
SERVER_S = server.c

RM = rm -f
PRINTF = ft_printf

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: library $(SERVER) $(CLIENT)

library:
	@make -C $(PRINTF)

$(SERVER):
	cc $(SERVER_S) $(CFLAGS) -L $(PRINTF) -o $(SERVER) -lftprintf
	@echo "$(GREEN)Server is waiting for her client dear don't make her wait too long...\n$(RESET)"

$(CLIENT):
	cc $(CLIENT_C) $(CFLAGS) -L $(PRINTF) -o $(CLIENT) -lftprintf
	@echo "$(YELLOW)Client is ready dear and craving for the server so badly!\n$(RESET)"

clean:
	$(RM) $(CLIENT) $(SERVER)
	@make clean -C $(PRINTF)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	@make fclean -C $(PRINTF)

re:	fclean all

.PHONY: all, re, fclean, clean
