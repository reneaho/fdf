/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrappint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:43:03 by raho              #+#    #+#             */
/*   Updated: 2022/04/14 03:23:09 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes a 2D array of integers, array of integers to append and the nbr of
** arrays already in the 2D array. Duplicates the 2D array of integers and
** appends the new array *app to the end of it. Frees the original array.
*/

static int	*dup_array(int *src)
{
	unsigned int	src_len;
	unsigned int	index;
	int				*new;

	src_len = sizeof(*src / sizeof(src));
	index = 0;
	new = (int *)malloc(sizeof(int) * src_len);
	if (!new)
		return (0);
	while (index < src_len)
	{
		new[index] = src[index];
		index++;
	}
	return (new);
}

int	**ft_arrappint(int **arr, int *app, unsigned int n)
{
	unsigned int	index;
	int				**result;

	result = 0;
	index = 0;
	result = (int **)malloc(sizeof(int *) * (n + 1));
	if (!result)
		return (0);
	if (index != n)
	{
		while (index != n)
		{
			result[index] = dup_array(arr[index]);
			//free(arr[index]);
			index++;
		}
		//free(arr);
	}
	result[index] = dup_array(app);
	return (result);
}
