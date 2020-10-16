#include "get_next_line.h"
#include <stdio.h>

static char		*ft_strdup(char *str)
{
	int		i = 0;
	char	*dup;

	while (str[i])
		i++;
	dup = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int 			get_next_line(char **line)
{
	char			buf[100000];
	int				i = 0;
	int				ret;

	while ((ret = read(0, buf + i, 1)) > 0)
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	if (ret >= 0)
	{
		buf[i] = 0;
		*line = ft_strdup(buf);
		(*line)[i] = '\0';
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}

int				main(void)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
