/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:18:20 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/14 15:11:08 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_isprint(int c);

int		ft_atoi(const char *str);

char	*ft_itoa(int n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strchr(const char *s, int c);
void	ft_strncpy(char *dst, const char *src, int n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strrepl(char *s, int c1, int c2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_abs(int n);
int		ft_max(int n1, int n2);
int		ft_min(int n1, int n2);

char	*get_next_line(int fd);
int		ft_find_nextline(char *str);
char	*ft_strldup(char *str, int start, int len);

#endif