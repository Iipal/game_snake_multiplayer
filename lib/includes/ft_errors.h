/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:50:23 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 15:27:11 by _ipal            ###   ########.fr       */
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
	ERR_NICKNAME = -3
}				t_err;

t_err	errors;

#endif
