/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:28:18 by ybouladh          #+#    #+#             */
/*   Updated: 2019/06/24 18:39:49 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

#include "./includes/filler.h"

int		check_bound(int y, int x, t_fill *container, int *sum)
{
	if (y < container->y_bigger_map && x < container->x_bigger_map &&
		y >= container->y_map && x >= container->x_map)
	{
		(*sum) += container->heat_map[y][x];
		return (1);
	}
	return (0);
}

int		check_cover(int y, int x, t_fill *container, int *counter)
{
	if (container->map[y][x] == container->player)
	{
		(*counter)++;
		return (1);
	}
	else if (container->map[y][x] != '.')
		return (0);
	return (1);
}

int		check_if_placable(t_fill **container, int y, int x)
{
	int jumper;
	int hopper;
	int counter;
	int sum;

	jumper = -1;
	counter = 0;
	sum = 0;
	while (++jumper < (*container)->y_token)
	{
		hopper = -1;
		while (++hopper < (*container)->x_token)
		{
			if ((*container)->token[jumper][hopper] == '*')
			{
				if (!check_bound(y + jumper, x + hopper, (*container), &sum))
					return (-1);
				if (!check_cover(y + jumper, x + hopper, *container, &counter))
					return (-1);
			}
		}
	}
	if (counter == 1)
		return (sum);
	return (-1);
}

void	allocate(t_fill **container)
{
	int jumper;
	int	hopper;

	jumper = -1;
	(*container)->placable = (int**)malloc(sizeof(int*) *
			(*container)->y_bigger_map);
	while (++jumper < (*container)->y_bigger_map)
	{
		(*container)->placable[jumper] = (int*)malloc(sizeof(int) *
		(*container)->x_bigger_map);
		hopper = -1;
		while (++hopper < (*container)->x_bigger_map)
			(*container)->placable[jumper][hopper] = 0;
	}
}

void	fill_placable(t_fill **container)
{
	int jumper;
	int hopper;

	jumper = -1;
	allocate(container);
	while (++jumper < (*container)->y_bigger_map)
	{
		hopper = -1;
		while (++hopper < (*container)->x_bigger_map)
			(*container)->placable[jumper][hopper] =
			check_if_placable(container, jumper, hopper);
	}
}
