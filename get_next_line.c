#include "get_next_line.h"

int		ft_end_of_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

void	ft_remove_end_line(char **s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*s)[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while ((*s)[i] != '\n')
	{
		tmp[i] = (*s)[i];
		i++;
	}
	tmp[i] = '\0';
	ft_strdel(s);
	*s = tmp;
}

void	ft_read_end(int const fd, char **line, char *tmpl, int eol, int ret)
{
	static char		buff[BUFF_SIZE + 1] = {'\0'};

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_realloc_join(&tmpl, buff);
		if ((eol = ft_end_of_line(buff)) > 0)
		{
			ft_remove_end_line(&tmpl);
			*line = tmpl;
			ft_strcpy(buff, buff + eol + 1);
			return ;
		}
	}
}

int		ft_returne(char **line, char *tmpl, int ret, char *buff)
{
	if (ret > 0)
		return (1);
	if (ret < 0)
		return (-1);
	if (ret == 0 && tmpl != NULL)
	{
		*line = tmpl;
		buff[0] = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1] = {'\0'};
	char			*tmpl;
	int				eol;
	int				ret;

	ret = 0;
	tmpl = NULL;
	if (buff)
	{
		ft_realloc_join(&tmpl, buff);
		if ((eol = ft_end_of_line(tmpl)) >= 0)
		{
			ft_strcpy(buff, tmpl + eol + 1);
			ft_remove_end_line(&tmpl);
			*line = tmpl;
			return (1);
		}
	}
	ft_read_end(fd, line, tmpl, eol, ret);
	return(ft_returne(line, tmpl, ret, buff));
}
