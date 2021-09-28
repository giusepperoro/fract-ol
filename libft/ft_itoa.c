/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:33:23 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:53:20 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	plswork(int nu)
{
	size_t			i;
	unsigned int	a;

	i = 1;
	a = 0;
	if (nu < 0)
		i++;
	if (nu >= 0)
		a = nu;
	else
		a = -nu;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*b;
	unsigned int	z;
	size_t			i;

	i = plswork(n);
	if (i == 0)
		return (NULL);
	b = (char *)malloc(i + 1);
	if (b == NULL)
		return (NULL);
	if (n >= 0)
		z = n;
	else
		z = -n;
	b[i] = '\0';
	while (i--)
	{
		b[i] = z % 10 + '0';
		z /= 10;
	}
	if (n < 0)
		b[0] = '-';
	return (b);
}
