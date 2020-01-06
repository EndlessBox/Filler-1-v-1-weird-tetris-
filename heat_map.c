/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map_and_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:45:05 by ybouladh          #+#    #+#             */
/*   Updated: 2019/07/15 21:39:18 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

void	initialize_heat_map(t_fill **container)
{
	int		jumper;
	int		hopper;
	char	ennemy;

	ennemy = (*container)->player == 'X' ? 'O' : 'X';
	(*container)->heat_map = (int**)malloc(sizeof(int*) *
			(*container)->y_bigger_map);
	jumper = -1;
	while (++jumper < (*container)->y_bigger_map)
	{
		(*container)->heat_map[jumper] = (int*)malloc(sizeof(int) *
				(*container)->x_bigger_map);
		hopper = -1;
		while (++hopper < (*container)->x_bigger_map)
		{
			if ((*container)->map[jumper][hopper] == ennemy)
				(*container)->heat_map[jumper][hopper] = 0;
			else
				(*container)->heat_map[jumper][hopper] = -1;
		}
	}
}

int		check_heat_map(t_fill **container)
{
	int	jumper;
	int	hopper;

	jumper = -1;
	while (++jumper < (*container)->y_bigger_map)
	{
		hopper = -1;
		while (++hopper < (*container)->x_bigger_map)
			if ((*container)->heat_map[jumper][hopper] == -1)
				return (0);
	}
	return (1);
}

void	fill(t_fill **container, int jumper, int hopper, int number)
{
	int	i;
	int	j;

	i = jumper - 1;
	while (i <= jumper + 1)
	{
		j = hopper - 1;
		while (j <= hopper + 1)
		{
			if (i >= 0 && i < (*container)->y_bigger_map && j >= 0
			&& j < (*container)->x_bigger_map &&
			(*container)->heat_map[i][j] == -1)
				(*container)->heat_map[i][j] = number;
			j++;
		}
		i++;
	}
}

void	fill_neighbor(t_fill **container, int number)
{
	int	jumper;
	int	hopper;

	jumper = -1;
	while (++jumper < (*container)->y_bigger_map)
	{
		hopper = -1;
		while (++hopper < (*container)->x_bigger_map)
		{
			if ((*container)->heat_map[jumper][hopper] == number - 1)
				fill(container, jumper, hopper, number);
		}
	}
}

void	fill_it(t_fill **container)
{
	int number;

	number = 1;
	while (check_heat_map(container) == 0)
	{
		fill_neighbor(container, number);
		number++;
	}
}
