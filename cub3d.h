/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:07:46 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/14 18:39:15 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <fcntl.h>

typedef struct s_parser {
	char	**points;
} t_parser;

typedef struct s_game {
	t_parser parser;
	char	**txtr;
	int		floor;
	int		ceiling;
	char	**map;
	int		argc;
	int		maplen;
	int		maphei;
	int		lowhei;
	int 	playercount;
} t_game;

char		*ft_strjoin(char const *s1, char const *s2);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *theString);
char		*ft_strchr(const char *string, int searchedChar);
char		*ft_getrest(char *fbuff);
char		*get_next_line(int fd);
void		free_tab(char **tab);
void		ft_parsemap(char *line, char **tab);
void		ft_setrange(char *path, char **tab, t_game *game);
void		*ft_calloc(size_t elementCount, size_t elementSize);
void		ft_contentinvalid(char *str);
void		ft_checkprechar(char c);
int			ft_skipline(int *ln, int fd);

void	free_tab(char **tab);
void	ft_checkchar(char c);
void	ft_exception(char **tab, t_game *game, int len);
int		create_rgb(int r, int g, int b);

void	ft_cleanpath(char **tab, int ln, int tx, t_game *game);

void	ft_setup(char **tab, t_game *game, int len);
void	ft_checkcount(char c, t_game *game);
void	ft_checkwall(char c, int i, int k, t_game *game);
void	ft_error(t_game *game, int len);

/* Dividers */

void	ft_divideceiling(int i, int k, char **tab, t_game *game);
void	ft_dividefloor(int i, int k, char **tab, t_game *game);
void	ft_makefloor(char **tab, int i, int k, t_game *game);
void	ft_makeceiling(char **tab, int i, int k, t_game *game);
void	ft_dividemap(int i, int k, char **tab, t_game *game);
void	ft_divideno(int i, int k, char **tab, t_game *game);
void	ft_divideso(int i, int k, char **tab, t_game *game);
void	ft_divideea(int i, int k, char **tab, t_game *game);
void	ft_dividewe(int i, int k, char **tab, t_game *game);
void	ft_dividetxtr(int i, int k, char **tab, t_game *game);
void	ft_dividein3(char **tab, t_game *game, int len);

#endif
