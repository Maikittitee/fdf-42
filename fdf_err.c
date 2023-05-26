#include "fdf.h"

void    check_arg(char *filename)
{
    size_t len;

    len = ft_strlen(filename);
    if (ft_strnstr(filename, ".fdf", len) == NULL)
        exit(1);
    if (filename[len - 1] != 'f' || filename[len - 2] != 'd' || \
        filename[len - 3] != 'f' || filename[len - 4] != '.')  
        exit(1);

}