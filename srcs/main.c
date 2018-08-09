/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:25:24 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 22:25:36 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/includes/ft_game.h"
#include "../lib/includes/ft_menu.h"
#include "../lib/includes/ft_settings.h"

int		main(void)
{
	ft_settings_default(&game);
	ft_settings_fsave();
	ft_switches_main(ft_menu_main());

	return (0);
}
