/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm & mc <mcrisari & mcrisari>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:11:08 by jm & mc           #+#    #+#             */
/*   Updated: 2022/02/16 15:36:32 by jm & mc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_libs.h"
#include "c3d_parser.h"
#include "c3d_utils.h"

static void
	ft_map_save(char *line, t_map *map, int i)
{
	char	**tmp;
	int		j;

	j = -1;
	tmp = map->map;
	while (tmp && i && ++j <= i)
		tmp[j] = map->map[j];
	map->map = ft_calloc(i + 2, sizeof(*map->map));
	if (map->map == NULL)
		ft_fail(strerror(errno));
	j = -1;
	while (tmp && i && ++j <= i)
		map->map[j] = tmp[j];
	map->map[i] = line;
	if (map->width < (int)ft_strlen(map->map[i]))
		map->width = (int)ft_strlen(map->map[i]);
	free(tmp);
}

static void
	ft_map_resize(t_map *map)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < map->height)
	{
		tmp = ft_calloc(sizeof(*tmp), map->width + 1);
		if (tmp == NULL)
			ft_fail(strerror(errno));
		ft_memset(tmp, SPACE, map->width);
		ft_memcpy(tmp, map->map[i], ft_strlen(map->map[i]));
		free(map->map[i]);
		map->map[i] = tmp;
	}
}

void
	ft_map_read(int fd, t_map *map)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			ft_fail(ERR_GNL);
		if (!ft_strlen(line) && map->map)
			ft_fail(ERR_PARSE_MAP);
		if (!ft_strlen(line) && !map->map)
			free(line);
		else
		{
			ft_map_save(line, map, i);
			i++;
		}
	}
	map->height = i;
	ft_map_resize(map);
}
