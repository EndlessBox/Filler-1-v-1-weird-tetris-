/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:59:26 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/28 16:39:04 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*new_string;

	new_string = (char*)malloc(sizeof(char) * (size + 1));
	ft_bzero(new_string, size + 1);
	return (new_string);
}
