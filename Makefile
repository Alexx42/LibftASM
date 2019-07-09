NAME 		= libfts.a
UNIT		= unit_test
ASM			= nasm
ASMFLAGS	= -f macho64

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS		= ft_bzero.s ft_strcat.s ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_isascii.s \
			  ft_isprint.s ft_toupper.s ft_tolower.s ft_puts.s ft_strlen.s ft_memset.s ft_memcpy.s ft_strdup.s ft_cat.s
OBJ			= $(addprefix $(OBJ_DIR), $(SRCS:.s=.o))


all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling LibftASM"
	@ar rcs $(NAME) $^
	@ranlib $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.s
	@$(ASM) $(ASMFLAGS) $< -o $@

clean:
	@echo "Cleaning object files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Cleaning library."
	@rm -f $(NAME) $(UNIT)

re: fclean all

unit:
	@echo "Compiling unit test."
	@$(CC) $(CFLAGS) -I inc/ -L. -lfts -o $(UNIT) main.c
