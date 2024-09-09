/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:24:12 by bailey            #+#    #+#             */
/*   Updated: 2024/09/09 19:00:53 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // for open()
#include <stdio.h> // for printf()
#include <unistd.h> // for close()

#define NUM_FILES 1 // Change to the number of files you want to handle

int	main(void)
{
	char	*buff;
	int		fds[NUM_FILES]; // Array to store file descriptors
	const char *file_names[NUM_FILES] = { "file.txt"}; // Array of file names

	// Open all files and handle errors
	for (int i = 0; i < NUM_FILES; i++) {
		fds[i] = open(file_names[i], O_RDONLY);
		if (fds[i] < 0) {
			perror("Error opening file");
			for (int j = 0; j < i; j++) // Close already opened files
				close(fds[j]);
			return (1);
		}
	}

	// Read lines from each file
	for (int i = 0; i < NUM_FILES; i++) {
		printf("Reading from %s:\n", file_names[i]);
		while ((buff = get_next_line(fds[i])) != NULL) {
			printf("%s", buff);
			if (buff[ft_strlen(buff) - 1] != '\n')  // Check if the last character is not a newline
				printf("\n");  // Manually print a newline if it's missing
			free(buff);  // Don't forget to free the buffer
		}
		close(fds[i]); // Close the file after reading all lines
	}

	return (0);
}
