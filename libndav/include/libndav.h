/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:24:54 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 18:49:59 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_H
# define LIBNDAV_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h> //bool type
# include <stdint.h> //integer types with fixed width

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_atoi(const char *s);
char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dest, const char *src);
void	ft_strcat(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcpy(char *dest, const char *src, size_t d_size);
size_t	ft_strlcat(char *dest, const char *src, size_t d_size);

size_t	ft_strclen(const char *str, char c, bool include_char);
char	*ft_strcdup(const char *str, char c, bool include_char);
void	ft_strccat(char *dest, const char *src, char c, bool include_char);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, t_byte b, int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, t_byte b, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

# define DEC "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"

size_t	ft_dprintf(int fd, const char *format, ...);
size_t	ft_dputchar(int fd, char c);
size_t	ft_dputstr(int fd, const char *s);
size_t	ft_dputptr(int fd, void *p);
size_t	ft_dputlbase(int fd, long n, char *base);
size_t	ft_dputulbase(int fd, t_ulong ul, char *base);
void	ft_dputendl(int fd, char *s);
void	ft_dputnbr(int fd, int n);

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd);

# ifndef ARENA_BLOCK_SIZE
#  define ARENA_BLOCK_SIZE 65536
# endif

/**
 * @brief This function has the same usage than malloc but doesn't handle memory
 * the same way. In an arena allocation, bytes are stored in a list of blocks of
 * continuous memory. If the end of one block is reached, a new one is created
 * and added to the list. There are two benefits from this approach. The first
 * one is performance optimisation due to less malloc calls and memory
 * continuity. The second one is practicity, the user doesn't need to worry
 * about allocated memory, only one call to the ft_free_arena at the end
 * of the program frees all used memory at once, no leaks are possible !
 * 
 * @param size The number of bytes that need to be allocated
 * @return A pointer to the allocated memory or NULL in case of error
 */
void	*ft_arena_alloc(size_t size);
void	ft_free_arena(void);

#endif
