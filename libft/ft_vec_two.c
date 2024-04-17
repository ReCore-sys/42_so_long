/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:42:17 by kshore            #+#    #+#             */
/*   Updated: 2024/01/31 01:22:04 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_vec_reverse` reverses the order of elements in a vector.
 *
 * @param vec The parameter "vec" is a pointer to a structure of type "t_vec".
 */
void	ft_vec_reverse(t_vec *vec)
{
	size_t	i;
	size_t	j;
	void	*tmp;

	i = 0;
	j = vec->size - 1;
	while (i < j)
	{
		tmp = vec->data[i];
		vec->data[i] = vec->data[j];
		vec->data[j] = tmp;
		i++;
		j--;
	}
}

/**
 * The ft_vec_sort function sorts the elements in a vector using a provided
 * comparison function.
 *
 * @param vec A pointer to a struct t_vec, which contains the data and its size.
 * @param cmp The "cmp" parameter is a function pointer that points to a
 * function that compares two elements of the vector. The function should take
 * two parameters of type "const void *" and return an integer. The return value
 * should be negative if the first element is less than the second element,
 * zero if they are
 */
void	ft_vec_sort(t_vec *vec, int (*cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;
	void	*tmp;

	i = 0;
	while (i < vec->size)
	{
		j = i + 1;
		while (j < vec->size)
		{
			if (cmp(vec->data[i], vec->data[j]) > 0)
			{
				tmp = vec->data[i];
				vec->data[i] = vec->data[j];
				vec->data[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/**
 * The function `ft_vec_prepend` prepends an element to the beginning of a
 * dynamic array, resizing the array if necessary.
 *
 * @param vec A pointer to a struct t_vec, which contains information about the
 * vector such as its size, capacity, and data.
 * @param data The "data" parameter is a pointer to the data that you want to
 * prepend to the vector.
 */
void	ft_vec_prepend(t_vec *vec, void *data)
{
	if (vec->size == vec->capacity)
	{
		vec->capacity *= 2;
		vec->data = (void **)realloc(vec->data, sizeof(void *) * vec->capacity);
	}
	ft_memmove(vec->data + 1, vec->data, sizeof(void *) * vec->size);
	vec->data[0] = data;
	vec->size++;
}
