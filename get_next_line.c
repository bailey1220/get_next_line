/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bachai <bachai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:36 by bailey            #+#    #+#             */
/*   Updated: 2024/09/22 16:38:33 by bachai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// read from the file and update buffer with new content
static char	*read_txt(int fd, char *buff)
{
	char	*tmp;
	ssize_t	count;

	tmp = ft_calloc(1, BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	count = 1;
	while (count != 0 && !ft_strchr(buff, '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		tmp[count] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	return (buff);
}

// extract the read line into a string
char	*extract(char *buff)
{
	char	*str;
	int		buff_len;

	if (!buff[0])
		return (NULL);
	buff_len = 0;
	while (buff[buff_len] != '\n' && buff[buff_len] != '\0')
		buff_len++;
	str = ft_calloc(1, buff_len + 2);
	if (!str)
		return (NULL);
	buff_len = 0;
	while (buff[buff_len] != '\n' && buff[buff_len] != '\0')
	{
		str[buff_len] = buff[buff_len];
		buff_len++;
	}
	if (buff[buff_len] == '\n')
		str[buff_len] = '\n';
	return (str);
}

// update string 
char	*update(char *buff)
{
	char	*str;
	int		n_len;
	int		c_len;

	c_len = 0;
	while (buff[c_len] != '\0' && buff[c_len] != '\n')
		c_len++;
	if (!buff[c_len])
	{
		free(buff);
		return (NULL);
	}
	str = ft_calloc(1, ft_strlen(buff) - c_len);
	if (!str)
		return (NULL);
	c_len++;
	n_len = 0;
	while (buff[c_len] != '\0')
		str[n_len++] = buff[c_len++];
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*store_nline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_txt(fd, buff);
	if (!buff)
		return (NULL);
	store_nline = extract(buff);
	buff = update(buff);
	return (store_nline);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("file.txt", O_RDONLY);
	i = 1;
	while (i < 4)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
*/