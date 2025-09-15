/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:48:23 by fenol             #+#    #+#             */
/*   Updated: 2025/09/15 01:55:26 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	count_visible(int arr[4])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > max_height)
		{
			max_height = arr[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_top_view(int grid[4][4], int row, int col, int num)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[i][col];
		i++;
	}
	arr[row] = num;
	return (count_visible(arr));
}

int	check_bottom_view(int grid[4][4], int row, int col, int num)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[3 - i][col];
		i++;
	}
	arr[3 - row] = num;
	return (count_visible(arr));
}

int	check_left_view(int grid[4][4], int row, int col, int num)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[row][i];
		i++;
	}
	arr[col] = num;
	return (count_visible(arr));
}

int	check_right_view(int grid[4][4], int row, int col, int num)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[row][3 - i];
		i++;
	}
	arr[3 - col] = num;
	return (count_visible(arr));
}
