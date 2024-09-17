/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:31:05 by bailey            #+#    #+#             */
/*   Updated: 2024/09/17 12:36:13 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int		sbuff_len;

	if (!buff[0])
		return (NULL);
	sbuff_len = 0;
	while (buff[sbuff_len] != '\n' && buff[sbuff_len] != '\0')
		sbuff_len++;
	str = ft_calloc(1, sbuff_len + 2);
	if (!str)
		return (NULL);
	sbuff_len = 0;
	while (buff[sbuff_len] != '\n' && buff[sbuff_len] != '\0')
	{
		str[sbuff_len] = buff[sbuff_len];
		sbuff_len++;
	}
	if (buff[sbuff_len] == '\n')
		str[sbuff_len] = '\n';
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
	static char	*buff[1024];
	char		*store_nline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	buff[fd] = read_txt(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	store_nline = extract(buff[fd]);
	buff[fd] = update(buff[fd]);
	return (store_nline);
}

