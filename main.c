/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:42:20 by fenol             #+#    #+#             */
/*   Updated: 2025/09/15 01:26:14 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	treat_input(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '4'))
			count++;
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}

void	process_puzzle(char *border_clues)
{
	int	**views;

	views = process_views(border_clues);
	resolve_game(views);
	free_views(views);
}

int	main(int argc, char **argv)
{
	int	is_input_valid;

	is_input_valid = (argc == 2);
	if (!is_input_valid)
		return (ft_error("Uso: ./skyscraper \"<16 numbers>\"\n"));
	is_input_valid = treat_input(argv[1]);
	if (!is_input_valid)
		return (ft_error("Input inválido\n"));
	process_puzzle(argv[1]);
	return (0);
}
