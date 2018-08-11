/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsettings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:14:43 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/11 16:22:14 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FSETTINGS_H
# define FT_FSETTINGS_H

# define FSETTING_FGRIDX "gridx: "
# define FSETTING_FGRIDY "gridy: "
# define FSETTING_FSPEED "speed: "
# define FSETTING_FNICKNAME "nickname: "
# define FSETTING_FILENAME "settings"

short	ft_fsettings_fread();
short	ft_fsettings_fread_problem();

void	ft_fswitches_swfread(short fread);
void	ft_fsettings_fexample();
void	ft_fsettings_fread_strparse_data(char *parse, char fp_set);
void	ft_fsettings_fread_strparse(char *parse);
void	ft_fsettings_fsave();

#endif