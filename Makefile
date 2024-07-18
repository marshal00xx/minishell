CC = cc

READLINE_L = $(shell brew --prefix readline)/lib
READLINE_I = $(shell brew --prefix readline)/include
HEADERS_DIR = ./headers
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBRARY_DIR = ./libft
DEPS_DIR = $(OBJ_DIR)

CFLAGS = -Wall -Wextra -Werror
HFLAGS = -MMD -I$(READLINE_I) -I$(HEADERS_DIR)
LFLAGS = -L$(LIBRARY_DIR) -lft -L$(READLINE_L) -lreadline
DFLAGS = -g

NAME = minishell

SOURCES =  $(SRC_DIR)/1_syntax_error_checking/syntax_error_checker.c \
           $(SRC_DIR)/1_syntax_error_checking/syntax_error_checker_utils.c \
		   $(SRC_DIR)/2_tokenizer/tokenizer.c \
		   $(SRC_DIR)/2_tokenizer/tokenizer_utils.c \
		   $(SRC_DIR)/3_parser/parser.c \
		   $(SRC_DIR)/3_parser/parser_utils.c \
		   $(SRC_DIR)/96_debuging/ast_graph_generator.c \
		   $(SRC_DIR)/96_debuging/tokens_printer.c \
           $(SRC_DIR)/main.c

LIBRARY = $(LIBRARY_DIR)/libft.a
OBJS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(HFLAGS) $(DFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) $(HFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBRARY):
	$(MAKE) -C $(LIBRARY_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBRARY_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBRARY_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: clean



# todo: remove the debugging flags.
#FIXME: the makefile doesn't regenerate the .d files if deleted manually.