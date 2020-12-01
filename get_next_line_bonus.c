/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 10:57:35 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/07/02 17:53:18 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		sub[j] = s[start];
		j++;
		start++;
	}
	sub[j] = '\0';
	return (sub);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static int	read_line(char *str, char *buff, char **line)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	*line = ft_substr(str, 0, i);
	if (*line == NULL)
	{
		free(str);
		return (-1);
	}
	while (buff[y] != '\n' && buff[y] != '\0')
		y++;
	if (buff[y] == '\n')
	{
		ft_memmove(buff, buff + y + 1, ft_strlen(buff) - y);
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

static char	*get_line(char *str, char *buff)
{
	char	*s;

	s = ft_strjoin(str, buff);
	if (s == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (s);
}

int			get_next_line(int fd, char **line)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	ssize_t		ret;

	ret = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	str = ft_strdup(buff[fd]);
	if (str == NULL)
		return (-1);
	while (ret > 0 && ft_strchr(buff[fd], '\n') == NULL)
	{
		ret = read(fd, buff[fd], BUFFER_SIZE);
		if (ret == -1)
		{
			free(str);
			return (-1);
		}
		buff[fd][ret] = '\0';
		str = get_line(str, buff[fd]);
		if (str == NULL)
			return (-1);
	}
	return (read_line(str, buff[fd], line));
}
