/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:29:08 by kshore            #+#    #+#             */
/*   Updated: 2024/01/31 01:20:04 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/**
 * The function `ft_vec_new` creates a new vector with a specified size.
 *
 * @param size The "size" parameter represents the initial size of the vector.
 * It determines the number of elements that the vector can initially hold.
 *
 * @return a pointer to a newly allocated t_vec structure.
 */
t_vec	*ft_vec_new(size_t size)
{
	t_vec	*vec;

	vec = (t_vec *)malloc(sizeof(t_vec));
	if (!vec)
		return (NULL);
	vec->size = size;
	vec->data = (void **)malloc(sizeof(void *) * size);
	if (!vec->data)
	{
		free(vec);
		return (NULL);
	}
	vec->size = 0;
	return (vec);
}

/**
 * The function `ft_vec_append` appends a new element to a dynamic array,
 * resizing the array if necessary.
 *
 * @param vec A pointer to a struct t_vec, which contains information about the
 * vector such as its size, capacity, and data.
 * @param data The "data" parameter is a pointer to the data that you want
 *	to append to the vector.
 */
void	ft_vec_append(t_vec *vec, void *data)
{
	if (vec->size == vec->capacity)
	{
		vec->capacity *= 2;
		vec->data = (void **)realloc(vec->data, sizeof(void *) * vec->capacity);
	}
	vec->data[vec->size] = data;
	vec->size++;
}

/**
 * The function `ft_vec_get` returns the element at the specified
 * index in a given vector.
 *
 * @param vec A pointer to a t_vec, which represents a vector data structure.
 * @param index The index parameter is the position of the element in the
 * vector that you want to retrieve. It is of type size_t, which is an unsigned
 * integer type.
 *
 * @return a pointer to the element at the specified index in the vector's data.
 */
void	*ft_vec_get(t_vec *vec, size_t index)
{
	if (index >= vec->size)
		return (NULL);
	return (vec->data[index]);
}

/**
 * The function `ft_vec_del` deletes an element at a given index from a vector
 * and shifts the remaining elements to fill the gap.
 *
 * @param vec A pointer to a struct t_vec, which contains an array of data and
 * the size of the array.
 * @param index The index parameter represents the position of the element that
 * needs to be deleted from the vector.
 *
 * @return The function does not explicitly return a value.
 */
void	ft_vec_del(t_vec *vec, size_t index)
{
	if (index >= vec->size)
		return ;
	vec->data[index] = NULL;
	while (index < vec->size - 1)
	{
		vec->data[index] = vec->data[index + 1];
		vec->data[index + 1] = NULL;
		index++;
	}
	vec->size--;
}

/**
 * The ft_vec_insert function inserts data at a specified index in a dynamic
 * array, resizing the array if necessary.
 *
 * @param vec A pointer to a struct t_vec, which contains information about
 * the vector such as its size, capacity, and data.
 * @param index The index parameter represents the position at which the data
 * should be inserted in the vector.
 * @param data The "data" parameter is a pointer to the data that you want to
 * insert into the vector.
 * @return The function does not explicitly return a value. However, if the
 * condition `index >= vec->size` is true, the function will
 * return without making any changes.
 */
void	ft_vec_insert(t_vec *vec, size_t index, void *data)
{
	if (index >= vec->size)
		return ;
	if (vec->size == vec->capacity)
	{
		vec->capacity *= 2;
		vec->data = (void **)realloc(vec->data, sizeof(void *) * vec->capacity);
		if (!vec->data)
			return ;
	}
	vec->size++;
	while (index < vec->size - 1)
	{
		vec->data[index + 1] = vec->data[index];
		index++;
	}
	vec->data[index] = data;
}
