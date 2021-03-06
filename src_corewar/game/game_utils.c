/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:31:16 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/10 20:36:35 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		possible_arg(int **types, int op_code)
{
	int i;
	int l;

	l = -1;
	while (++l < g_op_tab[op_code].n_arg)
	{
		i = g_op_tab[op_code].t_arg[l];
		if (types[l][0] == 1 && (i == 1 || i == 3 || i == 5 || i == 7))
		{
			if (types[l][1] < 1 || types[l][1] > 16)
				return (1);
			continue ;
		}
		else if (types[l][0] == 2 && (i == 2 || i == 3 || i == 6 || i == 7))
			continue ;
		else if (types[l][0] == 3 && (i == 4 || i == 5 || i == 6 || i == 7))
			continue ;
		else
			return (1);
	}
	return (0);
}

int		read_types(char *arena, int from, int size)
{
	int type;
	int times;

	type = 0;
	times = 0;
	while (--size > -1)
	{
		type += ((arena[ft_place(from + size)] & 0xFF) << (8 * times));
		times++;
	}
	return (type);
}

int		read_statement_code(t_carriage *c, t_game *game, int place)
{
	if (c->statement_code == -1)
		c->statement_code = game->arena[place];
	return (g_op_tab[c->statement_code - 1].f(game, place, c));
}
