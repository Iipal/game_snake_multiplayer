/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:25:24 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/11 14:48:55 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/includes/ft_game.h"
#include "../lib/includes/ft_fsettings.h"

int		main(void)
{
	system("clear");
	ft_fswitches_swfread(ft_fsettings_fread());
	return (0);
}
