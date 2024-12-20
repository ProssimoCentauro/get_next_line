# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    char    *str;
    struct s_list   *next;
}   t_list;

# endif
