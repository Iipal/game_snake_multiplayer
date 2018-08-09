/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:03 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 23:54:20 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SETTINGS_H
# define FT_SETTINGS_H

void	ft_settings_change(short setting);
void	ft_settings_default(t_game *def);
void	ft_settings_fread();
void	ft_settings_fsave();

#endif
