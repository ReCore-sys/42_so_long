/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_hashmap.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: kshore <kshore@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/30 23:10:13 by kshore 		   #+#	  #+#			  */
/*	 Updated: 2024/01/31 00:56:43 by kshore 		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>
#include "libft.h"
#include <stdbool.h>

/**
 * The function calculates a hash value for a given string using the FNV-1a
 * algorithm.
 *
 * @param key The key parameter is a pointer to a character array, which
 * represents the input string that we want to hash.
 *
 * @return a 64-bit unsigned integer (uint64_t).
 */
uint64_t	hashfunc( const char *key)
{
	uint64_t	h;

	h = 525201411107845655ull;
	while (*key)
	{
		h ^= *key;
		h *= 0x5bd1e9955bd1e995;
		h ^= h >> 47;
		key++;
	}
	return (h);
}

/**
 * The function `hashmap_new` creates a new hashmap by allocating memory for it
 * and initializing its keys and values vectors.
 *
 * @return The function `hashmap_new` is returning a pointer to a newly allocated
 * `t_hashmap` structure.
 */
t_hashmap	*hashmap_new(void)
{
	t_hashmap	*hashmap;

	hashmap = malloc(sizeof(t_hashmap));
	hashmap->keys = ft_vec_new(0);
	hashmap->values = ft_vec_new(0);
	hashmap->key_names = ft_vec_new(0);
	return (hashmap);
}

long	binary_search(t_vec *vec, uint64_t hash)
{
	long		low;
	long		high;
	long		mid;
	uint64_t	*data;

	low = 0;
	high = vec->size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		data = vec->data[mid];
		if (*data < hash)
			low = mid + 1;
		else if (*data > hash)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

void	hm_add(t_hashmap *hashmap, const char *key, void *value)
{
	uint64_t	hash;
	size_t		i;

	hash = hashfunc(key);
	i = 0;
	while (++i < hashmap->keys->size)
	{
		if (i < hashmap->keys->size - 1)
		{
			if (*(uint64_t *)hashmap->keys->data[i + 1] < hash)
				break ;
		}
	}
	if (i <= 1)
	{
		ft_vec_append(hashmap->keys, &hash);
		ft_vec_append(hashmap->values, value);
		ft_vec_append(hashmap->key_names, (void *)key);
		return ;
	}
	hashmap->size++;
	ft_vec_insert(hashmap->keys, i, &hash);
	ft_vec_insert(hashmap->values, i, value);
	ft_vec_insert(hashmap->key_names, i, (void *)key);
}
