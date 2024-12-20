#include "get_next_line.h"
#include <stdio.h>

int check_newline_lst(t_list *lst)
{
    size_t  i;

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
        lst= lst->next;
    }
    return (0);
}

int check_newline(char  *str)
{
    if (!str)
        return (0);
    while (*str)
    {
        if (*str == '\n')
            return (1);
        str++;
    }
    return (0);
}

char    *extract_line(char  *str)
{
    int  i;
    char    *line;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
    {
        line = (char *)malloc(i + 2);
        i += 1;
    }
    else if (str[i] == '\0')
        line = (char *)malloc(i + 1);
    if (!line)
        return (NULL);
    line[i--] = '\0';
    while (i >= 0)
    {
        line[i] = str[i];
        i--;
    }
    return (line);
}


char    *fix_buffer(char *str)
{
    size_t  i;
    size_t  j;
    size_t  k;
    char    *new;

    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i] != '\n' && str[i])
        i++;
    k = i;
    while (str[i])
        i++;
    new = (char *)malloc(i - k);
    if (!new)
        return (NULL);
    k++;
    while (str[k])
        new[j++] = str[k++];
    new[j] = '\0';
    free(str);
    if (!new[0])
    {
        free(new);
        str = NULL;
        return (str);
    }
    return (new);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

    /*if (!s)
        return (NULL);*/
    i = 0;
    while (s[i])
    {
        i++;
    }
    dest = (char *)malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t  ft_strlen(char *str)
{
    size_t  i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

size_t    ft_strncpy(char *dest, char *src, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (i);
}

char    *create_buffer(int fd, char *buffer)
{
    char    *tmp;
    int count;
    ssize_t readed_bytes;

    count = 1;
    while(!check_newline(buffer))
    {
        if (buffer)
        {
            tmp = ft_strdup(buffer);
            if (!tmp)
                return (NULL);
            free(buffer);
        }
        else
            tmp = NULL;
        buffer = (char *)malloc(ft_strlen(tmp) + (BUFFER_SIZE * count) + 1);
        //ft_zero(buffer);
        if (!buffer)
        {
            free(tmp);
            return (NULL);
        }
        readed_bytes = read(fd, &buffer[ft_strncpy(buffer, tmp, ft_strlen(tmp))], BUFFER_SIZE);
        if (readed_bytes == 0)
        {
            free(buffer);
            if (!tmp)
            {
                free(tmp);
                return (NULL);
            }
            return (tmp);
        }
        buffer[ft_strlen(tmp) + (BUFFER_SIZE * count)] = '\0';
        free(tmp);
    }
    //printf("%s\n", buffer);
    //exit(EXIT_SUCCESS);;
    return (buffer);
}

char    *get_next_line(int fd)
{
    static char    *buffer;
    char    *line;
    t_list  *lst;
    int lst_elems;

    if (!fd || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
        return (NULL);
    /*if (!buffer)
        buffer = ft_strdup("hola\nwei\njay\n");*/
    if (check_newline(buffer))
    {
        line = extract_line(buffer);
        buffer = fix_buffer(buffer);
        if (!buffer)
            buffer = create_buffer(fd, buffer);
        return (line);
    }
    buffer = create_buffer(fd, buffer);
    if (!buffer)
        return (NULL);
    line = extract_line(buffer);
    buffer = fix_buffer(buffer);
    /*if (!buffer[0])
    {
        free(buffer);
    }*/
    return (line);
}
/*
#include <fcntl.h>

int main()
{
    char    *line;
    int fd;
    int c;

    fd = open("/home/prossimocentauro/my-common-core/get_next_line/41_no_nl", O_RDONLY, NULL);
    if (fd < 0)
        printf("can not open file!\n");
    int i = 0;
    while (i<10)
    {
        line = get_next_line(fd);
        i++;
       	c = printf("%s", line);
        if (c <= 0)
           printf("can not print line!\n");
	    free(line);
    }
    return (0);
}
*/
