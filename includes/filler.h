/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:14:41 by ybouladh          #+#    #+#             */
/*   Updated: 2019/07/15 21:41:55 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define NEW_L	ft_putchar_fd('\n', 2);
# define DEBUG1	ft_putchar_fd('1', 2);
# define DEBUG2	ft_putchar_fd('2', 2);
# define DEBUG3	ft_putchar_fd('3', 2);
# define DEBUG4	ft_putchar_fd('4', 2);
# define DEBUG5	ft_putchar_fd('5', 2);
# define DEBUG6	ft_putchar_fd('6', 2);

typedef struct	s_fill
{
	char		**map;
	char		**token;
	int			**heat_map;
	int			**placable;
	char		player;
	int			x_map;
	int			y_map;
	int			x_bigger_map;
	int			y_bigger_map;
	int			x_token;
	int			y_token;
}				t_fill;

void			get_player(t_fill **container);
void			get_map_dimensions(t_fill **container);
void			get_map(t_fill **container);
void			escape_line(char **line);
void			get_token_dimensions(t_fill **container);
void			get_token(t_fill **container);
void			show_map(t_fill *container);
void			show_bigger_map(t_fill *container, int number);
void			show_token(t_fill *container);
void			initialize_heat_map(t_fill **container);
void			fill_heat_map(int y, int x, t_fill **container);
void			finish_heat_map(int x, t_fill **container);
void			find_enemy(t_fill **container);
void			fill_placable(t_fill **container);
int				check_if_placable(t_fill **container, int y, int x);
int				output_result(t_fill *container);
int				result(int y, int x, t_fill *container);
void			free_all(t_fill **container);
void			fill_it(t_fill **container);
void			initialize_heat_map_top(t_fill **container);
void			out_put_leak();
void			allocate_placable(t_fill *container);

#endif
