#include "get_next_line.h"

int	new_list(int fd, t_list **lst)
{
	char	*buffer;
	int		readed_chars;

	while (!check_newline(*lst))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return 0;
		readed_chars = read(fd, buffer, BUFFER_SIZE);
		if (!readed_chars)
		{
			free(buffer);
			return 0 ;
		}
		buffer[BUFFER_SIZE] = '\0';
		lst_add_back(lst, buffer);
	}
	return 1;
}

char	*export_line(t_list *lst)
{
	char	*line;

	if (!lst)
		return (NULL);
	line = (char *)malloc(line_len(lst) + 1);
	if (!line)
		return (NULL);
	line_copy(lst, line);
	return (line);
}

void	free_list(t_list **lst, t_list *new_node, char *str)
{
	t_list	*temp;

	while(*lst)
	{
		temp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
	if (!new_node->str[0])
	{
		free(new_node);
		free(str);
	}
	else
		*lst = new_node;
}

void	fix_list(t_list **lst)
{
	t_list	*clean_node;
	t_list	*last_node;
	t_list	*current;
	char	*fixed_str;

	if (!lst)
		return ;
	current = *lst;
	while (current->next)
		current = current->next;
	last_node = current;
	clean_node = (t_list *)malloc(sizeof(t_list));
	fixed_str = fix_str(last_node->str);
	if (!clean_node || !fixed_str)
		return ;
	clean_node->str = fixed_str;
	clean_node->next = NULL;
	free_list(lst, clean_node, fixed_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*lst = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	if(!new_list(fd, &lst))
		return (NULL);
	line = export_line(lst);
	fix_list(&lst);
	return (line);
}
