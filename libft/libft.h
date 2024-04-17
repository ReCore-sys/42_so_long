/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:58 by kshore            #+#    #+#             */
/*   Updated: 2024/02/17 22:03:07 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_vec
{
	void	**data;
	size_t	size;
	size_t	capacity;
}			t_vec;

typedef struct s_hashmap
{
	t_vec	*keys;
	t_vec	*key_names;
	t_vec	*values;
	size_t	size;
}	t_hashmap;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		comment(char *comment);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			numlen(int n);
char		*strrev(char *str);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *str, int fd);
void		*freestring(char **string, int i);
char		**ft_split(const char *str, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *str);
void		ft_striteri(char *str, void (*f)(unsigned int, char*));
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(const char *str);
char		*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
char		*ft_strnstr(const char *str, const char *substr, unsigned int len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, unsigned int len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_front(t_list **lst, t_list *item);
void		ft_lstadd_back(t_list **lst, t_list *item);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
t_list		*ft_lstnew(void *content);
void		ft_lstclear(t_list **lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_get(t_list lst, int index);
t_vec		*ft_vec_new(size_t size);
void		ft_vec_append(t_vec *vec, void *data);
void		*ft_vec_get(t_vec *vec, size_t index);
void		ft_vec_del(t_vec *vec, size_t index0);
void		ft_vec_insert(t_vec *vec, size_t index, void *data);
void		ft_vec_reverse(t_vec *vec);
void		ft_vec_sort(t_vec *vec, int (*cmp)(const void *, const void *));
void		ft_vec_prepend(t_vec *vec, void *data);
t_hashmap	*hashmap_new(void);
void		hm_add(t_hashmap *hashmap, const char *key, void *value);
void		*hm_get(t_hashmap *hashmap, const char *key);
void		*hm_remove(t_hashmap *hashmap, const char *key);
bool		hm_contains(t_hashmap *hashmap, const char *key);
uint64_t	hashfunc( const char *key);
long		binary_search(t_vec *vec, uint64_t hash);
void		print_hashmap(t_hashmap *hashmap);
void		*hm_get_by_hash(t_hashmap *hashmap, uint64_t hash);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putunbr(unsigned int nb);
int			ft_putnbr(int nb);
int			ft_hexlower(unsigned int nb);
int			ft_hexupper(unsigned int nb);
int			ft_pointer(unsigned long ptr);
int			ft_printf(const char *format, ...);
