# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

int check_newline(char  *str);
char    *extract_line(char  *str);
char    *fix_buffer(char *str);
char	*ft_strdup(char *s);
size_t  ft_strlen(char *str);
size_t    ft_strncpy(char *dest, char *src, size_t n);
char    *create_buffer(int fd, char *buffer);
char    *get_next_line(int fd);
void    *ft_calloc(size_t nmemb, size_t size);

# endif
