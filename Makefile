CFLAGS = -Wall -Wextra -Werror

LIBSNAKE = lib/libsnake.a
LIBSRC = lib/srcs/ft_wrong_input.c lib/srcs/ft_start_game.c
LIBOBJ = ft_wrong_input.o ft_start_game.o

all: lib main clean

lib:
	@gcc $(CFLAGS) -c $(LIBSRC)
	@ar rc $(LIBSNAKE) $(LIBOBJ)

main:
	@gcc $(CFLAGS) srcs/main.c -Llib -lsnake -o exe_snake

clean:
	@rm -rf $(LIBOBJ)

fclean: clean
	@rm -rf $(LIBSNAKE)
	@rm -rf exe_snake

re: fclean all

.PHONY: all lib main clean fclean re
