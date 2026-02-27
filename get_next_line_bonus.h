#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef MAX_FD
# define MAX_FD 42
#endif

# include <stdlib.h>
# include <unistd.h>

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
