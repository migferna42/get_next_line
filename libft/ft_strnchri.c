/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adomingu <adomingu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 12:22:10 by adomingu          #+#    #+#             */
/*   Updated: 2015/01/19 12:31:15 by adomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnchri(char *s, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (s && i < n && s[i] != c)
		i++;
	if (s && s[i] == c && i < n)
		return (i);
	return (-1);
}
