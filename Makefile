#directories
IDIR = inc
ODIR = obj
SDIR = .
LDIR = libftprintf
#compiler settings
CC = gcc
CFLAGS = -std=c11
CCFLAGS = #-std=c11 -Wall -Wextra -Werror -Wpedantic# -Og -g3 -fsanitize=address
FLAGS = $(CCFLAGS) -I $(IDIR) -I $(LDIR)/$(IDIR)
#dependencies
SERVER = server
CLIENT = client
LIB = libftprintf.a
#headers
DEPS := $(wildcard $(IDIR)/*.h)
#sources
SERV_SRCS := $(wildcard *server*.c)
CLNT_SRCS := $(wildcard *client*.c)
#objects
OBJS_SERV = $(SERV_SRCS:.c=.o)

OBJS_CLNT = $(CLNT_SRCS:.c=.o)


#TARGETS
all: $(SERVER) $(CLIENT)

#make library
$(LDIR)/$(LIB):
	@make -C $(LDIR)

#make objects
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@


#make excecutable
$(SERVER): $(OBJS_SERV) $(LDIR)/$(LIB)
	@$(CC) $(FLAGS) $^ -o $@

$(CLIENT): $(OBJS_CLNT) $(LDIR)/$(LIB)
	@$(CC) $(FLAGS) $^ -o $@

#.PHONY: clean uninstall reinstall

bonus: all

clean:
	rm -rf $(OBJS_SERV) $(OBJS_CLNT)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make fclean -C $(LDIR)
re: fclean all