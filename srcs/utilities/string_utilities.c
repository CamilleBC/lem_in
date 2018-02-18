/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:07:20 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/16 16:17:41 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*rev_skip_whitespace(char *s)
{
	while (s && (s - 1)
		&& (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\v' || *s == '\f' || *s == '\r'))
		--s;
	return (s);
}

char	*rev_skip_number(char *s)
{
	if (s && ft_isdigit(*s))
	{
		while ((s - 1) && ft_isdigit(*(s - 1)))
			--s;
		if ((s - 1) && (*(s - 1) == '-'))
			--s;
	}
	return (s);
}