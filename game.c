/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:57:25 by fenol             #+#    #+#             */
/*   Updated: 2025/09/15 02:17:37 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	is_valid(t_game *game, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->grid[row][i] == num || game->grid[i][col] == num)
			return (0);
		i++;
	}
	if ((game->views[0][col] != 0) &&
		(check_top_view(game->grid, row, col, num) > game->views[0][col]))
		return (0);
	if (game->views[1][col] != 0 &&
		(check_bottom_view(game->grid, row, col, num) > game->views[1][col]))
		return (0);
	if (game->views[2][row] != 0 &&
		(check_left_view(game->grid, row, col, num) > game->views[2][row]))
		return (0);
	if (game->views[3][row] != 0 &&
		(check_right_view(game->grid, row, col, num) > game->views[3][row]))
		return (0);
	return (1);
}

int	solve(t_game *game, int row, int col)
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == 4)
		return (1);
	next_row = row;
	if (col == 3)
		next_row = row + 1;
	next_col = (col + 1) % 4;
	num = 1;
	if (game->grid[row][col] != 0)
		return (solve(game, next_row, next_col));
	while (num <= 4)
	{
		if (is_valid(game, row, col, num))
		{
			game->grid[row][col] = num;
			if (solve(game, next_row, next_col))
				return (1);
			game->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	resolve_game(int **views)
{
	t_game	game;

	ft_memset(game.grid, 0, sizeof(game.grid));
	game.views = views;
	if (!solve(&game, 0, 0))
	{
		ft_putstr("No solution found\n");
		return (1);
	}
	print_grid(game.grid);
	return (0);
}
