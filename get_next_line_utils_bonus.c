/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:28:21 by bailey            #+#    #+#             */
/*   Updated: 2024/09/09 18:29:26 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
       i++;
    return (i); 
}

char *ft_strdup(const char *s)
{
    int i;
    int j;
    char *str;
 
    i = 0;
    j = ft_strlen(s);   
    str = (char*)malloc(sizeof(*str) * (j  + 1));
    while (i < j)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i = 0;
    int j = 0;

    if (!s1 || !s2)  // Add a check for NULL pointers
        return NULL;
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return NULL;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return str;
}

char    *ft_strchr(const char *s, int c)
{
    while (*s)  // Traverse the string until the null terminator
    {
        if (*s == (char)c)  // If current character matches 'c'
            return ((char *)s);  // Return pointer to the matched character
        s++;  // Move to the next character
    }
    if (c == '\0')  // If looking for the null terminator
        return ((char *)s);  // Return a pointer to the null terminator
    return (NULL);  // Return NULL if the character isn't found
}

void	*ft_calloc(size_t num, size_t size)
{
	void		*ptr;
	size_t		i;

	i = 0;
	if (num == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = (char *)malloc (num * size);
	if (!ptr)
		return (NULL);
	while (i < (size * num))
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
