/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:54:55 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:49:15 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	amountwords(char const *smm, char c)
{
	size_t		count;

	count = 0;
	if (*smm != 0)
		smm++;
	while (*smm)
	{
		if ((*smm == c && *(smm - 1) != c) || (*(smm + 1) == '\0' && *smm != c))
			count++;
		smm++;
	}
	return (count);
}

static char	**freemm(char **penmmforfree)
{
	size_t		forfree;

	forfree = 0;
	while (penmmforfree[forfree] != NULL)
		free(penmmforfree[forfree++]);
	free(penmmforfree);
	return (NULL);
}

static void	penetratemm(char **penmm, char c, size_t amm, char const *smm)
{
	size_t		i;
	size_t		j;
	size_t		ipenmm;

	i = 0;
	ipenmm = 0;
	while (ipenmm < amm && smm[i])
	{
		j = i;
		while (smm[j] == c && smm[j])
			j++;
		i = j;
		while (smm[i] != c && smm[i])
			i++;
		penmm[ipenmm] = ft_substr(smm, j, i - j);
		if (!penmm[ipenmm])
			penmm = freemm(penmm);
		ipenmm++;
	}
	penmm[ipenmm] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t		am;
	char		**mm;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	am = amountwords(s, c);
	mm = (char **)malloc(sizeof(char *) * (am + 1));
	if (mm == NULL)
		return (NULL);
	penetratemm(mm, c, am, s);
	return (mm);
}
