/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:42:52 by ybouladh          #+#    #+#             */
/*   Updated: 2018/12/18 12:45:03 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper_str(char *str)
{
	int jumper;

	jumper = -1;
	while (str[++jumper])
		if (str[jumper] >= 'a' && str[jumper] <= 'z')
			str[jumper] = str[jumper] - ('a' - 'A');
	return (str);
}
