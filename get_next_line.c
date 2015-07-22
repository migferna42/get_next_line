#include "get_next_line.h"

static char		*ft_read(int fd, int *ret)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmpl;
	int		eof;

	ft_bzero(buff, BUFF_SIZE + 1);
	tmpl = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(buff, '\n'))
	{
		eof = read(fd, buff, BUFF_SIZE);
		if (eof < 0 || !buff)
			return (NULL);
		if (!eof)
		{
			*ret = 1;
			return (tmpl);
		}
		buff[eof] = '\0';
		tmpl = ft_realloc_join(&tmpl, buff);
	}
	return (tmpl);
}

static char		*ft_remove_end_line(char *buff, char **tmpl, char *rest)
{
	char	*line;

	line = ft_strjoin(buff, *tmpl);
	if (rest)
		ft_strcpy(buff, rest + 1);
	else
		ft_bzero(buff, BUFF_SIZE + 1);
	if (*tmpl)
		ft_strdel(tmpl);
	return (line);
}

static int		ft_returne(char **line, int ret)
{
	if (!line || !*line)
		return (-1);
	else if (ret)
		return (0);
	else
		return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	char			*tmpl;
	char			*rest;
	int				ret;

	ret = 0;
	tmpl = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (!(rest = ft_strchr(buff, '\n')))
	{
		if (!(tmpl = ft_read(fd, &ret)))
			return (-1);
		rest = ft_strchr(tmpl, '\n');
	}
	if (rest)
		*rest = '\0';
	*line = ft_remove_end_line(buff, &tmpl, rest);
	return (ft_returne(line, ret));
}

/*int			main(void)
{
	int		fd;
	int		ret;
char	*line;

	fd = open("clang", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	//	printf("%d\n", ret);
		free(line);
		line = NULL;
	}
//	printf("%d\n", ret);
	return (0);
}*/
