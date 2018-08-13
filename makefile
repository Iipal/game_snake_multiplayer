CFLAGS = -Wall -Werror -Wextra -pedantic -g -std=gnu11

LIBSNAKE = lib/libsnake.a
LIBSRC = lib/srcs/ft_game_menu.c lib/srcs/ft_game_rules.c \
		lib/srcs/ft_game_settings.c lib/srcs/ft_game_fsettings.c \
		lib/srcs/ft_game_start.c
LIBOBJ = ft_game_menu.o ft_game_rules.o \
		ft_game_settings.o ft_game_fsettings.o \
		ft_game_start.o 

all: lib main fastclean

lib:
	@gcc $(CFLAGS) -Ilib/includes -c $(LIBSRC)
	@ar rc $(LIBSNAKE) $(LIBOBJ)

main:
	@gcc $(CFLAGS) srcs/main.c -lrt -Llib -lsnake -o exe_snake

fastclean:
	@rm -rf $(LIBOBJ)

clean:
	@rm -rf $(LIBOBJ)

fclean: clean
	@rm -rf $(LIBSNAKE)
	@rm -rf exe_snake
	@rm -rf settings

re: fclean all

.PHONY: all lib main fastclean clean fclean re
