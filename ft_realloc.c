/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:19:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/17 15:05:43 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*ptr;

	if (new_size == 0)
    {
        free(old_ptr);
        return (NULL);
    }

	if (!old_ptr)
		return (ft_calloc(1, new_size));

	ptr = ft_calloc(1, new_size);
	if (!ptr)
		return (NULL);

	size_t copy_size = (new_size < old_size) ? new_size : old_size;
	ft_memcpy(ptr, old_ptr, copy_size);
	free(old_ptr);
	return (ptr);
}

void	*ft_safe_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*ptr = ft_realloc(old_ptr, old_size, new_size);

	if (!ptr)
		exit(ENOMEM);

	return (ptr);
}
