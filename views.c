/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:49:25 by fenol             #+#    #+#             */
/*   Updated: 2025/09/15 01:36:33 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	*process_row_views(char *border_clues, int start_index)
{
	int	*views;
	int	i;

	views = (int *)malloc(4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		views[i] = border_clues[start_index + i * 2] - '0';
		i++;
	}
	return (views);
}

int	*process_col_views(char *border_clues, int start_index)
{
	int	*views;
	int	i;

	views = (int *)malloc(4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		views[i] = border_clues[start_index + i * 2] - '0';
		i++;
	}
	return (views);
}

int	**process_views(char *border_clues)
{
	int	**views;

	views = (int **)malloc(4 * sizeof(int *));
	views[0] = process_row_views(border_clues, 0);
	views[1] = process_row_views(border_clues, 8);
	views[2] = process_col_views(border_clues, 16);
	views[3] = process_col_views(border_clues, 24);
	return (views);
}
