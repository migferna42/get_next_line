#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 8

 int	get_next_line(int const fd, char **line);

#endif
