/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:04:15 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:45:34 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ter(int i, int start, int len)
{
	if ((i - start) >= len)
		return (len);
	else
		return (i - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	max;
	size_t	i;
	size_t	pogchamp;

	i = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start >= i)
		return (ft_strdup(""));
	max = ter(i, start, len);
	buff = (char *)malloc(max + 1);
	if (buff == NULL)
		return (NULL);
	pogchamp = max;
	while (max-- > 0)
	{
		*(buff++) = s[start];
		start++;
	}
	*buff = '\0';
	return (buff - pogchamp);
}
