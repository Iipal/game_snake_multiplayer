/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:19:18 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/12 14:01:30 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MENU_H
# define FT_MENU_H

typedef enum	e_gamemode
{
	MODE_EXIT,
	MODE_SOLO,
	MODE_BOT,
	MODE_PVP
}				t_gamemode;

typedef enum	e_mainmenu
{
	MAIN_MENUEXIT,
	MAIN_GAMEMODE,
	MAIN_SETTINGS
}				t_mainmenu;

t_gamemode	gamemode;
t_mainmenu	mainmenu;

short	ft_menu_main(void);
short	ft_menu_gamemode(void);
short	ft_menu_settings(void);

void	ft_switches_main(short main);
void	ft_switches_gamemode(short gamemode);
void	ft_switches_settings(short settings);

#endif
