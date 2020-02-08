/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:33:49 by ybuhai            #+#    #+#             */
/*   Updated: 2020/02/03 21:56:09 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = destination;
	while (i < n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (destination);
}
