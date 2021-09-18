/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:15:06 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/18 21:21:14 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	arr[4] = {1, 2, 3, 4};

void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void permu(int N, int (*ptr)[4])
{
	int	i;
	int	j;
	int	index;

	j = 0;
	if (N == 3)
	{
		i = 0;
		while (i < 4)
		{
			index = 0;
			while (ptr[index][i] != 0)
			{
				index++;
			}
			ptr[index][i] = arr[i];
			i++;
		}
		j++;
		ptr++;
	}
	else
   	{
		i = N;
		while (i < 4)
		{
			swap(i, N);
			permu(N + 1, ptr);
			swap(i, N);
			i++;
		}
	}
}
