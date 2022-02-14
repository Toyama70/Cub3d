/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:07:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/14 18:15:58 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void ft_forbiddenmap(t_game *game)
{
	int i;
	int k;

	game->playercount = 0;
	i = 0;
	k = 0;
	while (game->map[i] != 0)
	{
		while (game->map[i][k] != 0)
		{
			ft_checkcount(game->map[i][k], game);
			ft_checkprechar(game->map[i][k]);
			ft_checkwall(game->map[i][k], i, k, game);
			k++;
		}
		k = 0;
		i++;
	}
	if (game->playercount != 1)
	{
		printf("Error : player number is incorrect\n");
		exit(1);
	}
}

void	ft_checkcount(char c, t_game *game)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		game->playercount++;
}

void	ft_maperror()
{
	printf("ERROR wall or hole in map ? \n");
	exit(1);
}
void	ft_checkwall(char c, int i, int k, t_game *game)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
	{
		if (game->map[i][k-1] != '0' && game->map[i][k-1] != '1' && 
				game->map[i][k-1] != 'N' && game->map[i][k-1] != 'W' && 
				game->map[i][k-1] != 'E' && game->map[i][k-1] != 'S')
			ft_maperror();
		if (game->map[i][k+1] != '0' && game->map[i][k+1] != '1' && 
				game->map[i][k+1] != 'N' && game->map[i][k+1] != 'W' && 
				game->map[i][k+1] != 'E' && game->map[i][k+1] != 'S')
			ft_maperror();
		if (game->map[i-1][k] != '0' && game->map[i-1][k] != '1' && 
				game->map[i-1][k] != 'N' && game->map[i-1][k] != 'W' && 
				game->map[i-1][k] != 'E' && game->map[i-1][k] != 'S')
			ft_maperror();
		if (game->map[i+1][k] != '0' && game->map[i+1][k] != '1' && 
				game->map[i+1][k] != 'N' && game->map[i+1][k] != 'W' && 
				game->map[i+1][k] != 'E' && game->map[i+1][k] != 'S')
			ft_maperror();
	}
}

void	ft_error(t_game *game, int len)
{
	ft_forbiddenmap(game);
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
