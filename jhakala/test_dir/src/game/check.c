/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:00:59 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/24 18:52:50 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	kill_head_carriage(t_carriage **alst, t_carriage *c)
{
	*alst = c->next;
	ft_printf("	KILL P   %d\n", c->id);
	free(c);
}

void	kill_carriage(t_carriage *prev, t_carriage *c)
{
	prev->next = c->next;
	ft_printf("	KILL P   %d\n", c->id);
	free(c);
}

int		check_carriages(t_game *game)
{
	t_carriage *c;
	t_carriage *prev;

	c = game->c_lst;
	while (c && c->live_cycle == -1)
	{
		kill_head_carriage(&game->c_lst, c);
		c = game->c_lst;
	}
	prev = c;
	while (c)
	{
		if (c->live_cycle == -1)
			kill_carriage(prev, c);
		else
			prev = c;
		prev->live_cycle = -1;
		c = prev->next;
	}
	ft_printf("	MAKE CHECK\n");
	ft_printf("	nbr_live=%d, get_die=%d\n", game->n_live_in_cycle, game->get_die);
	if (game->c_lst == NULL)
		return (1);
	if (game->n_live_in_cycle >= NBR_LIVE)
	{
		game->get_die -= CYCLE_DELTA;
		game->max_check = 0;
	}
	else
	{
		if (++game->max_check >= MAX_CHECKS)
		{
			game->get_die -= CYCLE_DELTA;
			game->max_check = 0;
		}
	}
	game->n_live_in_cycle = 0;
	game->cycles_to_die = game->get_die > 0 ? game->get_die : 1;
	return (0);
}