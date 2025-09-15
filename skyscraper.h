/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:38:56 by fenol             #+#    #+#             */
/*   Updated: 2025/09/15 02:17:37 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	int	grid[4][4];
	int	**views;
}	t_game;

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_error(char *str);
int		ft_atoi(char *str);
char	**ft_split(char *str, char sep);
int		**process_views(char *border_clues);
void	free_views(int **views);
int		resolve_game(int **views);
void	print_grid(int grid[4][4]);
int		solve(t_game *game, int row, int col);
int		is_valid(t_game *game, int row, int col, int num);
int		check_top_view(int grid[4][4], int row, int col, int num);
int		check_bottom_view(int grid[4][4], int row, int col, int num);
int		check_left_view(int grid[4][4], int row, int col, int num);
int		check_right_view(int grid[4][4], int row, int col, int num);
int		count_visible(int arr[4]);
void	ft_memset(void *s, int c, size_t n);

#endif