NAME		= philosophers
DIR			= src/
SRCS		= $(wildcard $(addprefix $(DIR), *.c))
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -Iincludes -fsanitize=thread -g3
RM			= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $@ $(OBJS)

%.o: %c 
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean : 
	@$(RM) $(DIR)*.o

fclean : clean
	@$(RM) $(NAME)

re :fclean all

.PHONY: all fclean clean re 