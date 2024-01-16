/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compaction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:34:21 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 19:34:54 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*revmove(int *dst, int *src, int len)
{
	int	i;
	int	*dest;
	int	*source;

	i = len - 1;
	dest = dst;
	source = src;
	while (i >= 0)
	{
		dest[i] = source[i];
		if (i == 0)
			break ;
		i--;
	}
	return (dst);
}

void	*ft_memmove2(int *dst, int *src, int len)
{
	int	i;
	int	*dest;
	int	*source;

	i = 0;
	dest = dst;
	source = src;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dest > source)
		return (revmove(dst, src, len));
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

int	*compaction(int *array, int len, t_node *node)
{
	int	i;
	int	j;
	int	*copy;

	copy = (int *)malloc((sizeof(int) * len) + 1);
	copy[len] = '\0';
	ft_memmove2(copy, array, len);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (copy[i] > copy[j])
				node->rank++;
			j++;
		}
		//printf("list[%d] compact[%d]\n", copy[i], node->rank);
		i++;
		node = node->next;
	}
	free(copy);
	return (array);
}
