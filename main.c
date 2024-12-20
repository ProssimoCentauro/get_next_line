#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
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
    while (i<7)
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
