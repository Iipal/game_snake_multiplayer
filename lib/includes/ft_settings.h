/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:03 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 15:28:17 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SETTINGS_H
# define FT_SETTINGS_H

# define BUFF_SIZE			32

# define GRID_MIN			10
# define GRID_MAX			30
# define SPEED_MIN			1
# define SPEED_MAX 			5

# define DEFAULT_GRID		12
# define DEFAULT_NICKNAME	"Player"

typedef enum	e_settings
{
	SETTING_EXIT,
	SETTING_WIDTH,
	SETTING_HEIGHT,
	SETTING_NICKNAME,
	SETTING_DEFAULT,
	SETTING_USER
}				t_settings;

typedef struct	s_usersets
{
	short	USERSETS_WIDTH;
	short	USERSETS_HEIGHT;
	short	USERSETS_NICKNAME;
}				t_usersets;

t_settings	settingsmenu;

void	ft_settings_change(short setting);
char	*ft_settings_setnickname(char *nickname);
void	ft_settings_default(t_game *def);
void	ft_settings_user(t_usersets *us);

#endif
