#PATHS
APP=./app
BIN=./bin
SRC=./src
OBJ=./obj
BONUS=./bonus
INCLUDE=./include
NAME=$(BIN)/gnl
NAME_BONUS=$(BIN)/gnl_bonus

#VARIABLES
SRCS= get_next_line.c get_next_line_utils.c
OBJS=$(addprefix $(OBJ)/,$(SRCS:%.c=%.o))
BONUS_SRC= get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ=$(addprefix $(BONUS)/,$(BONUS_SRC:%.c=%.o))
HEADER=-I $(INCLUDE)
FLAGS=-Wall -Wextra -Werror
CC=cc

all: $(OBJ) $(BIN) $(NAME)

$(NAME): $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@
	ar -rsc $(NAME) $@

bonus: $(OBJ) $(BIN) $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ)

$(BONUS)/%.o: $(BONUS)/%.c
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@
	ar -rsc $(NAME_BONUS) $@

$(OBJ):
	mkdir obj

$(BIN):
	mkdir bin

clean:
	rm -rf $(OBJ)/*.o $(BONUS)/*.o

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re

