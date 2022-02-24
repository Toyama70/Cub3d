/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:21:39 by ybestrio          #+#    #+#             */
/*   Updated: 2022/02/24 11:21:49 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_error(t_data *data)
{
	ft_forbiddenmap(data);
}

void	ft_contentinvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
}

void	ft_checkchar(char c)
{
	if (c == 'C' || c == '0' || c == '1' || c == 'E' || c == 'P' || c == '\n')
		return ;
	else
	{
		printf("Forbidden key in file");
		exit(1);
	}
}

void	ft_checkprechar(char c)
{
	if (c == 'S' || c == 'N' || c == '0' || c == '1' || c == ' ' || c == '\n')
		return ;
	else if (c == 'E' || c == 'W')
		return ;
	else
	{
		printf("Forbidden key in map");
		exit(1);
	}
}
