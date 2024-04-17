/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:04:50 by kshore            #+#    #+#             */
/*   Updated: 2024/01/31 01:39:17 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

void	*hm_remove(t_hashmap *hashmap, const char *key)
{
	uint64_t	hash;
	long		location;
	void		*value;

	hash = hashfunc(key);
	location = binary_search(hashmap->keys, hash);
	if (location == -1)
		return (NULL);
	value = hashmap->values->data[location];
	ft_vec_del(hashmap->keys, location);
	ft_vec_del(hashmap->values, location);
	ft_vec_del(hashmap->key_names, location);
	hashmap->size--;
	return (value);
}

bool	hm_contains(t_hashmap *hashmap, const char *key)
{
	uint64_t	hash;
	long		location;

	hash = hashfunc(key);
	location = binary_search(hashmap->keys, hash);
	if (location == -1)
		return (false);
	return (true);
}

void	*hm_get(t_hashmap *hashmap, const char *key)
{
	uint64_t	hash;
	long		location;

	hash = hashfunc(key);
	location = binary_search(hashmap->keys, hash);
	if (location == -1)
		return (NULL);
	return (hashmap->values->data[location]);
}

void	*hm_get_by_hash(t_hashmap *hashmap, uint64_t hash)
{
	long		location;

	location = binary_search(hashmap->keys, hash);
	if (location == -1)
		return (NULL);
	return (hashmap->values->data[location]);
}

void	print_hashmap(t_hashmap *hashmap)
{
	size_t		i;
	char		*key;
	void		*value;

	i = 0;
	while (hashmap->key_names->data[i])
	{
		key = hashmap->key_names->data[i];
		value = hashmap->values->data[i];
		printf("%s: %s\n", key, (char *)value);
		i++;
	}
}
