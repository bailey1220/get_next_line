/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:29:33 by bailey            #+#    #+#             */
/*   Updated: 2024/09/10 14:00:04 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>

size_t		ft_strlen(const char *str);
void		*ft_calloc(size_t num, size_t size);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
char		*get_next_line(int fd);

#endif
