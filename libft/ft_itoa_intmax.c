/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:24:40 by ybouladh          #+#    #+#             */
/*   Updated: 2019/01/13 01:43:27 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strflipper(char *str)
{
	char	*result;
	int		jumper;
	int		hopper;
	int		limiter;

	jumper = 0;
	limiter = 0;
	hopper = ft_strlen(str);
	result = ft_strnew(hopper);
	hopper--;
	if (str[0] == '-')
	{
		result[0] = '-';
		jumper++;
		limiter = 1;
	}
	while (hopper >= limiter)
	{
		result[jumper] = str[hopper];
		jumper++;
		hopper--;
	}
	return (result);
}

static	int		ft_allocation(intmax_t n)
{
	int counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static void		ft_filler(char *result, int jumper, uintmax_t n_saver)
{
	while (n_saver > 9)
	{
		result[++jumper] = (n_saver % 10) + 48;
		n_saver /= 10;
	}
	result[++jumper] = (n_saver % 10) + 48;
}

char			*ft_itoa_intmax(intmax_t n)
{
	char			*result;
	int				jumper;
	uintmax_t		n_saver;

	jumper = ft_allocation(n);
	if (n < 0 && (result = ft_strnew(jumper + 1)))
	{
		result[0] = '-';
		jumper = 0;
		n_saver = -n;
	}
	else if (n >= 0 && (result = ft_strnew(jumper)))
	{
		jumper = -1;
		n_saver = n;
	}
	else
		return (NULL);
	ft_filler(result, jumper, n_saver);
	return (ft_strflipper(result));
}
