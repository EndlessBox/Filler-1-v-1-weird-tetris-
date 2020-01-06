/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:51:12 by ybouladh          #+#    #+#             */
/*   Updated: 2019/06/30 21:09:14 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	get_token_dimensions(t_fill **container)
{
	int		jumper;
	char	*line;

	get_next_line(0, &line);
	jumper = 0;
	while (line[jumper] < '0' || line[jumper] > '9')
		jumper++;
	(*container)->y_token = ft_atoi(line + jumper);
	while (line[jumper] != ' ')
		jumper++;
	while (line[jumper] < '0' || line[jumper] > '9')
		jumper++;
	(*container)->x_token = ft_atoi(line + jumper);
	free(line);
}

void	get_token(t_fill **container)
{
	int		jumper;
	char	*line;

	(*container)->token = (char**)malloc(sizeof(char*) * (*container)->y_token);
	jumper = 0;
	while (jumper < (*container)->y_token)
	{
		get_next_line(0, &line);
		(*container)->token[jumper] = ft_strnew((*container)->x_token);
		ft_strcpy((*container)->token[jumper], line);
		free(line);
		jumper++;
	}
}

int		result(int y, int x, t_fill *container)
{
	if (y == 0 && x == 0)
	{
		ft_putnbr(y);
		ft_putchar(' ');
		ft_putnbr(x);
		ft_putchar('\n');
		return (0);
	}
	else
	{
		ft_putnbr(y - container->y_map);
		ft_putchar(' ');
		ft_putnbr(x - container->x_map);
		ft_putchar('\n');
	}
	return (1);
}

int		output_result(t_fill *container)
{
	int	checker;
	int	jumper;
	int	hopper;
	int	x;
	int	y;

	checker = 0;
	x = 0;
	y = 0;
	jumper = -1;
	while (++jumper < container->y_bigger_map)
	{
		hopper = -1;
		while (++hopper < container->x_bigger_map)
		{
			if ((container->placable[jumper][hopper] > -1 && (checker == 0 ||
			container->placable[y][x] > container->placable[jumper][hopper])))
			{
				y = jumper;
				x = hopper;
				checker++;
			}
		}
	}
	return (result(y, x, container));
}
