/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:21 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/17 14:58:24 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

// Utility functions
size_t	ft_strlen(char const *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

// Main functions
int		ft_check_line_jump(char *new_str);
ssize_t	read_from_fd(int fd, char **buffer);
char	*extract_line(char **buffer);
char	*get_next_line(int fd);

#endif
