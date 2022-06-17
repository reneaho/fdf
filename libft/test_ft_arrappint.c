/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_arrappint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:38:40 by raho              #+#    #+#             */
/*   Updated: 2022/04/14 03:26:12 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int	arr[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
	int	app[3] = {9,10,11};
	int	**p;
	int	**new = 0;
	int	j = 0;
	int	k = 0;

	p = arr;
	while (j < 3)
	{
		k = 0;
		while (k < 3)
		{
			printf("arr[%i][%i] = %i\n", j, k, arr[j][k]);
			k++;
		}
		j++;
	}
	printf("\n");
	new = ft_arrappint(p, app, 3);
	j = 0;
	while (j < 3)
	{
		k = 0;
		while (k < 3)
		{
			printf("new[%i][%i] = %i\n", j, k, new[j][k]);
			k++;
		}
		j++;
	}
	while (j > 0)
	{
		free(new[j]);
		j--;
	}
	free(new);
	return (0);
}
