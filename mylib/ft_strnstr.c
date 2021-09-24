/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:42:27 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/09 20:32:55 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (ft_strlen(h) < ft_strlen(n))
		return (NULL);
	if (ft_strlen(n) == 0)
		return (h);
	while (i < len && h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j] && i + j < len && n[j] && h[i + j])
		{
			if (n[j + 1] == '\0')
				return (h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
