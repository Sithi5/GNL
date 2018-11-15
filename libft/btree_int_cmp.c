/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_int_cmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:01:21 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/12 11:00:12 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_int_cmp(void *c1, void *c2)
{
	int a;
	int b;

	a = (int)c1;
	b = (int)c2;
	return (a - b);
}