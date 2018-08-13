/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_gameplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 04:22:21 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 04:28:31 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_generate_food(void)
{
	static const short	max_food;
	int					gen_y;
	int					gen_x;

	max_food = (x * y) / FOOD_RARITY + 1;
	if (g_food_counter <= max_food)
	{
		gen_y = rand() % y;
		gen_x = rand() % x;
		if (g_playfield[gen_y][gen_x] == ' ')
		{
			g_playfield[gen_y][gen_x] = '@';
			g_food_counter++;
		}
		else
			ft_generate_food();
	}
}

void	ft_level_up(t_snake *snake)
{
	static const short upped_already;

	upped_already = 0;
	if (snake->length % LVLUP_LENGTH == 0)
	{
		if (!upped_already)
		{
			g_level++;
			upped_already = 1;
		}
	}
	else
		upped_already = 0;
}
