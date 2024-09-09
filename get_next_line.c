/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:36 by bailey            #+#    #+#             */
/*   Updated: 2024/09/09 17:44:02 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read the text
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
			free (tmp);
			return (NULL);
		}
		tmp[count] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	free (tmp);
	return (buff);
}

//store the read line into a string
char	*store_line(char *buff)
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

#include "get_next_line.h"

// push string to the front
char	*push_forward(char *buff)
{
	char	*str;
	int		n_len;
	int		p_len;

	p_len = 0;
	while (buff[p_len] != '\0' && buff[p_len] != '\n')
		p_len++;
	if (!buff[p_len])
	{
		free(buff);
		return (NULL);
	}
	str = ft_calloc(1, ft_strlen(buff) - p_len);
	if (!str)
		return (NULL);
	p_len++;
	n_len = 0;
	while (buff[p_len] != '\0')
		str[n_len++] = buff[p_len++];
	free (buff);
	return (str);
}

char *get_next_line(int fd)
{
    static char *buff;
    char *store_nline;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buff)
        buff = ft_strdup("");  // Initialize buff if it's NULL
    buff = read_txt(fd, buff);
    if (!buff)
        return (NULL);
    store_nline = store_line(buff);
    buff = push_forward(buff);
    return (store_nline);
}
