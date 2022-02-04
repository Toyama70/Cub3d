/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:07:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/04 12:18:03 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_contentinvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		//ft_checkprechar(str[i]);
		i++;
	}
}

void	ft_checkprechar(char c)
{
	if (c == 'C' || c == '0' || c == '1' || c == 'E' || c == 'P' || c == '\n')
		return ;
	else
	{
		printf("Forbidden key in file or wrong line length");
		exit(1);
	}
}
