
NAME = push_swap

CC = cc 

CFLAGS = -Wall -Werror -Wextra -g

CFILES_1 = push_swap.c

CFILES_2 =  free.c		\
			pivot.c 	\
			action_a.c	\
			action_b.c	\
			sort_a.c	\
			sort_b.c 	\
			sort.c		\
			split.c 	\
			utils.c 	\
			
OBJS_1 = $(CFILES_1:.c=.o)

OBJS_2 = $(CFILES_2:.c=.o)


$(NAME): $(OBJS_1) $(OBJS_2)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) -o $(NAME)
	@echo "\n\033[33mPush_swap is ready ✅\033[0m\n"


all: $(NAME)
	@echo "\n\033[33mAll files compiled successfully ✅\033[0m\n"

clean:
		@rm -f $(OBJS_1) $(OBJS_2)
		@echo "\n\033[33mObjects files deleted ✅\033[0m\n"

fclean: clean
		@rm -rf $(NAME) 
		@echo "\n\033[33mArchive file deleted ✅\033[0m\n"

re: fclean all

.phony: re fclean clean all
