/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:50:11 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/10 21:33:17 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		op_ld(t_game *game, int place, t_carriage *c)
{
	int **types;

	if (!(types = get_arg_types(game, c)))
		return (c->size);
	if (game->print)
		ft_printf(" P   %d | ld", c->id);
	if (types[0][0] == 2)
		c->reg[types[1][1] - 1] = types[0][1];
	else
		c->reg[types[1][1] - 1] = read_types(game->arena, place +
						((short)types[0][1] % IDX_MOD), REG_SIZE);
	if (c->reg[types[1][1] - 1] == 0)
		c->carry = 1;
	else
		c->carry = 0;
	if (game->print)
		ft_printf(" %d r%d | %d | carry = %d\n", c->reg[types[1][1] - 1],
				types[0][0] == 3 ? (short)types[1][1] : types[1][1],
				c->reg[types[1][1] - 1], c->carry);
	return (read_game_param(game, place, c->size, types));
}
