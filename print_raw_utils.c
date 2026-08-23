/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_raw_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:22:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/17 01:23:03 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	print_raw_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	print_raw_string(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_raw_string(fd, "(null)"));
	while (str[i])
	{
		if (print_raw_char(fd, str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
