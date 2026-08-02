/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:39:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/18 23:28:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef EQUAL_STRINGS
#  define EQUAL_STRINGS 0
# endif

typedef unsigned long size_t;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_isstr_empty(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int 	ft_are_string_equals(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_safe_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void *));
void	ft_lstclear(t_list **lst, void (*del) (void *));
void	ft_lstiter(t_list *lst, void (*f) (void *));
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
char	**ft_split_set(char const *s, char const *set);
int		ft_index(char *str, char c);
int		ft_stroccurrences(char *str, char c);
int		ft_stroccurrences_set(char *str, char *set);
char	*get_next_line(int fd);

typedef struct s_ft_printf_flags
{
	int	minus;
	int	plus;
	int	space;
	int	hashtag;
	int	zero;
	int	width;
	int	precision;
}	t_ft_printf_flags;

int		ft_printf(char const *str, ...);
int		print_raw_char(char c);
int		print_raw_string(char *str);
int		print_character(char c, t_ft_printf_flags *flags);
int		print_number(int n, t_ft_printf_flags *flags);
int		print_unsigned_number(unsigned int n, t_ft_printf_flags *flags);
char	*ft_uitoa(unsigned int n);
int		print_string(char *str, t_ft_printf_flags *flags);
int		print_pointer(void *ptr, t_ft_printf_flags *flags);
int		print_hex_nbr(unsigned int n, char specifier, t_ft_printf_flags *flags);
int		calculate_total_hex_num_length(unsigned long n);
void	puthex_in_str(char *num_str, unsigned long n, int idx);
void	transform_hex_toupper(char *str);
int		print_width(int bytes, char byte_to_print);
int		print_precised_number(char *num_str, t_ft_printf_flags *flags, unsigned int n);
int		print_hex_prefix(unsigned int n, char specifier);
int		check_for_signs_flags(int n, t_ft_printf_flags *flags);
int		calc_total_width(char *num_str, t_ft_printf_flags *flags, int bytes_written);
void	process_precision(char *str, t_ft_printf_flags *flags);
int		print_precised_string(char *str, int precision);
int		calculate_width(char *str, t_ft_printf_flags *flags);
int		count_flags(char const *str, int *pos, t_ft_printf_flags *flags);
void	reset_flags(t_ft_printf_flags *flags);

#endif
