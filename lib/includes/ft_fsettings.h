/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsettings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:14:43 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 15:27:29 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FSETTINGS_H
# define FT_FSETTINGS_H

# define FSETTING_FWIDTH	"width: "
# define FSETTING_FHEIGHT	"height: "
# define FSETTING_FNICKNAME "nickname: "
# define FSETTING_FILENAME 	"settings"

short	ft_fsettings_fread(void);
short	ft_fsettings_fread_problem(void);

void	ft_fswitches_swfread(short fread);
void	ft_fsettings_fexample(void);
void	ft_fsettings_fread_strparse_data(char *parse, char fp_set);
void	ft_fsettings_fread_strparse(char *parse);
void	ft_fsettings_fsave(void);

#endif
