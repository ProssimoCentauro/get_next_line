#ifndef     GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char	*str;
	struct s_list	*next;
}	t_list;

int             check_newline(t_list *lst);
void    lst_add_back(t_list **lst, char *buffer);
int     new_list(int fd, t_list **lst);
char    *export_line(t_list *lst);
int             line_len(t_list *lst);
void    fix_list(t_list **lst);
char    *fix_str(char *str);
char    *get_next_line(int fd);
void    free_list(t_list **lst, t_list *new_node, char *str);
void    line_copy(t_list *lst, char *str);

#endif
