#include "get_next_line.h"

int     line_len(t_list *lst)
{
        int     count;
        int     i;

        count = 0;
        while (lst)
        {
                i = 0;
                while (lst->str[i])
                {
                        if (lst->str[i] == '\n')
                                return (count + 1);
                        count++;
                        i++;
                }
                lst = lst->next;
        }
        return (count);
}

int     check_newline(t_list *lst)
{
        int     i;

        if (!lst)
                return (0);
        while (lst)
        {
                i = 0;
                while (lst->str[i] && i < BUFFER_SIZE)
                {
                        if (lst->str[i] == '\n')
                                return (1);
                        i++;
                }
                lst = lst->next;
        }
        return (0);
}

void    line_copy(t_list *lst, char *str)
{
        char    *res;
        int     i;
        int     j;

        res = str;
        i = 0;
        j = 0;
        while (lst)
        {
                while (lst->str[j])
                {
                        if (lst->str[j] == '\n')
                        {
                                res[i] = '\n';
                                i++;
                                res[i] = '\0';
                                return ;
                        }
                        res[i] = lst->str[j];
                        i++;
                        j++;
                }
                lst = lst->next;
                j = 0;
        }
        res[i] = '\0';
}

void    lst_add_back(t_list **lst, char *buffer)
{
        t_list  *current;
        t_list  *node;

        current = *lst;
        node = (t_list *)malloc(sizeof(t_list));
        if (!node)
                return ;
        node->str = buffer;
        node->next = NULL;
        if (!*lst)
        {
                *lst = node;
                return ;
        }
        while (current->next)
                current = current->next;
        current->next = node;
}

char    *fix_str(char *str)
{
        char    *res;
        int             i;
        int             j;

        i = 0;
        j = 0;
        res = (char *)malloc(BUFFER_SIZE + 1);
        while (str[j] && str[j] != '\n')
                j++;
        j++;
        while(str[j])
        {
                res[i] = str[j];
                i++;
                j++;
        }
        res[i] = '\0';
        return (res);
}
