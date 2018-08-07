CFLAGS = -Wall -Wextra -Werror

LIBSNAKE = lib/libsnake.a
LIBSRC = lib/srcs/ft_menu.c lib/srcs/ft_game_start.c
LIBOBJ = ft_menu.o ft_game_start.o

all: lib main fastclean

lib:
	@gcc $(CFLAGS) -Ilib/includes -c $(LIBSRC)
	@ar rc $(LIBSNAKE) $(LIBOBJ)

main:
	@gcc $(CFLAGS) srcs/main.c -Llib -lsnake -o exe_snake

fastclean:
	@rm -rf $(LIBOBJ)

clean:
	@rm -rf $(LIBOBJ)

fclean: clean
	@rm -rf $(LIBSNAKE)
	@rm -rf exe_snake

re: fclean all

.PHONY: all lib main fastclean clean fclean re
