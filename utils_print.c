/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol <fenol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:33:29 by fenol             #+#    #+#             */
/*   Updated: 2025/09/15 01:35:19 by fenol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_error(char *str)
{
	ft_putstr("Error\n");
	if (str)
		ft_putstr(str);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
