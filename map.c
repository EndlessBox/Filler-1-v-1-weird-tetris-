/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:51:37 by ybouladh          #+#    #+#             */
/*   Updated: 2019/07/15 21:46:00 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	get_player(t_fill **container)
{
	int		jumper;
	char	*line;

	get_next_line(0, &line);
	jumper = 0;
	while (line[jumper] != 'p')
		jumper++;
	if (line[jumper + 1] == '1')
	{
		(*container)->player = 'O';
	}
	else
		(*container)->player = 'X';
	free(line);
}

void	get_map_dimensions(t_fill **container)
{
	int		jumper;
	char	*line;
	char	*temp;

	get_next_line(0, &line);
	temp = line;
	jumper = 0;
	while (line[jumper] < '0' || line[jumper] > '9')
		jumper++;
	(*container)->y_map = ft_atoi(line + jumper);
	(*container)->y_bigger_map = (*container)->y_map * 2;
	while (line[jumper] != ' ')
		jumper++;
	while (line[jumper] < '0' || line[jumper] > '9')
		jumper++;
	(*container)->x_map = ft_atoi(line + jumper);
	(*container)->x_bigger_map = (*container)->x_map * 2;
	free(temp);
}

void	allocate_map(t_fill **container)
{
	int jumper;

	jumper = -1;
	(*container)->map = (char**)malloc(sizeof(char*) *
			(*container)->y_bigger_map);
	while (++jumper < (*container)->y_bigger_map)
	{
		(*container)->map[jumper] = (char*)malloc(sizeof(char) *
			(*container)->x_bigger_map + 1);
		(*container)->map[jumper][(*container)->x_bigger_map] = '\0';
	}
}

void	allocat_rest_of_the_map(t_fill **container)
{
	int		jumper;
	int		hopper;
	char	*line;
	char	*temp;

	temp = NULL;
	jumper = (*container)->y_map - 1;
	while (++jumper < (*container)->y_bigger_map)
	{
		get_next_line(0, &line);
		temp = line;
		line += 4;
		hopper = (*container)->x_map - 1;
		while (++hopper < (*container)->x_bigger_map)
		{
			(*container)->map[jumper][hopper] =
				line[hopper - (*container)->x_map];
		}
		free(temp);
	}
}

void	get_map(t_fill **container)
{
	int		jumper;
	int		hopper;

	allocate_map(container);
	jumper = 0;
	while (jumper < (*container)->y_bigger_map)
	{
		hopper = 0;
		while (hopper < (*container)->x_bigger_map)
		{
			(*container)->map[jumper][hopper] = '.';
			hopper++;
		}
		jumper++;
	}
	allocat_rest_of_the_map(container);
}
