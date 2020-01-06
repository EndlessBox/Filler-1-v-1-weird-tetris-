/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:44:25 by ybouladh          #+#    #+#             */
/*   Updated: 2019/07/18 18:25:54 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	free_all(t_fill **container)
{
	int	jumper;

	jumper = -1;
	while (++jumper < (*container)->y_bigger_map)
	{
		free((*container)->map[jumper]);
		free((*container)->heat_map[jumper]);
		free((*container)->placable[jumper]);
	}
	free((*container)->map);
	free((*container)->heat_map);
	free((*container)->placable);
	jumper = -1;
	while (++jumper < (*container)->y_token)
		free((*container)->token[jumper]);
	free((*container)->token);
}

void	escape_line(char **line)
{
	get_next_line(0, line);
	free(*line);
}

void	initialize_heat_map_top(t_fill **container)
{
	int		jumper;
	int		hopper;

	jumper = -1;
	(*container)->heat_map = (int**)malloc(sizeof(int*) *
			(*container)->y_bigger_map);
	while (++jumper < (*container)->y_bigger_map)
	{
		hopper = -1;
		(*container)->heat_map[jumper] = (int*)malloc(sizeof(int) *
				(*container)->x_bigger_map);
		while (++hopper < (*container)->x_bigger_map)
		{
			if (jumper == (*container)->y_map && hopper >= (*container)->x_map)
				(*container)->heat_map[jumper][hopper] = 0;
			else
				(*container)->heat_map[jumper][hopper] = -1;
		}
	}
}

int		check_top(t_fill *container)
{
	int	hopper;
	int	counter;

	hopper = container->x_map;
	counter = 0;
	while (hopper < container->x_bigger_map)
	{
		if (container->map[container->y_map][hopper] == 'X')
			return (1);
		if (container->map[container->y_map][hopper] == 'O')
			counter++;
		hopper++;
	}
	if (counter == container->x_map)
		return (1);
	return (0);
}

int		main(void)
{
	static t_fill	*container;
	char			*line;

	container = (t_fill *)malloc(sizeof(t_fill));
	get_player(&container);
	while (1)
	{
		get_map_dimensions(&container);
		escape_line(&line);
		get_map(&container);
		get_token_dimensions(&container);
		get_token(&container);
		if (container->y_map == 15 && container->player == 'X'
		&& !check_top(container))
			initialize_heat_map_top(&container);
		else
			initialize_heat_map(&container);
		fill_it(&container);
		fill_placable(&container);
		if (!output_result(container))
			break ;
		free_all(&container);
	}
	free(container);
	return (0);
}
