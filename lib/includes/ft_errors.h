/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:50:23 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/12 23:24:00 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define FT_ERROR -1
# define FT_SUCCESS 0
# define FT_DONE 1

typedef enum	e_err
{
	ERR_WIDTH = -1,
	ERR_HEIGHT = -2,
	ERR_SPEED = -3,
	ERR_NICKNAME = -4
}				t_err;

t_err	errors;

#endif
