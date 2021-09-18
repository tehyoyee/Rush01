/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:18:42 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/18 21:08:43 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_row_left(int (*ptr)[4], int i)			// i 번째 경우의수 보이는 갯수 리턴
{
	int	j;
	int	result;
	int	k;

	result = 4;
	j = 3;
	while (j > 0)
	{
		k = j - 1;
		while (k >= 0)
		{
			if (ptr[i][j] < ptr[i][k])
			{
				result--;
				break;
			}
			k--;
		}
		j--;
	}
	return result;
}

void 	check_row_left(int row_left, int (*ptr)[4])
{
	int	i;

	i = 0;
	while (i < 24)
	{
		if (ptr[i][0] != 0)
		{
			if (row_left != count_row_left(ptr, i))
				ptr[i][0] = 0;
		}
		i++;
	}
}
////////////////////////////////////////////////////////////////////////
int		count_row_right(int (*ptr)[4], int i)			// i 번째 경우의수 보이는 갯수 리턴
{
	int	j;
	int	result;
	int	k;

	result = 4;
	j = 0;
	while (j < 3)
	{
		k = j + 1;
		while (k <= 3)
		{
			if (ptr[i][j] < ptr[i][k])
			{
				result--;
				break;
			}
			k++;
		}
		j++;
	}
	return result;
}

void 	check_row_right(int row_right, int (*ptr)[4])
{
	int	i;

	i = 0;
	while (i < 24)
	{
		if (ptr[i][0] != 0)
		{
			if (row_right != count_row_right(ptr, i))
				ptr[i][0] = 0;
		}
		i++;
	}
}
