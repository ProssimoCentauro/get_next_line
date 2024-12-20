#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char    *line;
    int fd;
    int c;

    fd = open("/nfs/homes/rtodaro/Desktop/common-core-tests/get_next_line/test.txt", O_RDONLY, NULL);
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
