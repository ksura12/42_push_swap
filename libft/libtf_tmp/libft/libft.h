/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:21:39 by ksura             #+#    #+#             */
/*   Updated: 2022/07/05 12:30:35 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				chunk;
}	t_list;

typedef struct s_stack
{
	int				value;
	int				index;
	int				pindex;
	int				pos;
	int				tar_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Part I
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// Part II
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
// Bonus
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));
//  PushSwap functions
t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **stk, t_stack *new);
void	ft_stackadd_front(t_stack **stk, t_stack *new);
t_stack	*ft_stacklast(t_stack *stk);
int		ft_stacksize(t_stack *stk);

/**
*@brief returns a line read from a file descriptor
*
*@param fd The file descriptor to read from
*@return Read line: correct behavior
*NULL: there is nothing else to read, or an error
*occurred
*/
char	*get_next_line(int fd);

/**
*@brief allocates spave and wipes it
*
*@param count Number of Objects.
*@param size Size of the objects.
*@return Pointer to allocated memory
* Null if error occurs
*/
char	*calloc_gnl(int count);

/**
*@brief locates first occurance of '\n'
*
*@param line string in which to search
*@return Pointer to location of first occurance
* Null if '\n' doesnt occure
*/
char	*strchr_gnl(const char *line);

/**
*@brief allocates and joins two strings
*
*@param s1 the prefix string
*@param s2 the suffix string
*@return the new string
* Null if allocation fails
*/
char	*strjoin_gnl(char *s1, char *s2);

/**
*@brief gives the length of a string
*
*@param str1 the string to measure
*@return number of characters of the string without NULL
*/
int		strlen_gnl(const char *str);

/**
*@brief saves the remainding characters in a string for next call
*in a static variable
*
*@param rest remainding characters
*@return Pointer to location of the remainding characters
*/
char	*save_rest(char	*rest);

/**
*@brief assembles the whole line of a file to return with gnl
*
*@param rest remainding characters
*@return Pointer to location of teh line to return
*/
char	*line_output_gnl(char	*rest);

/**
*@brief reads from file into buffer, allocates and saves rest,
*frees buffer
*
*@param fd file descriptor
*@param rest remainding string
*@return pointer to rest
* Null if allocation fails
*/
char	*read_saverest_gnl(int fd, char	*rest);

#endif

# define BUFFER_SIZE 1