/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 16:52:07 by ginger            #+#    #+#             */
/*   Updated: 2020/05/08 20:22:08 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_file	*new_file(const int fd)
{
	t_file *new;

	if ((new = (t_file *)ft_memalloc(sizeof(t_file))))
	{
		new->fd = fd;
		new->str = NULL;
	}
	return (new);
}

static t_file	*get_file(const int fd, t_file **head)
{
	t_file *lst;

	if (!(*head))
		return (*head = new_file(fd));
	lst = *head;
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	return ((lst->fd == fd) ? lst : (lst->next = new_file(fd)));
}

static int		str_divide(char **str, char **line)
{
	char	*new;
	char	*div;

	if (!(*line = ft_strsubchr(*str, '\n')))
		return (-1);
	div = ft_strchrs(*str, '\n');
	div++;
	if (!ft_strlen(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(div);
	free(*str);
	*str = new;
	return ((new) ? 1 : -1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*head = NULL;
	t_file			*f;
	char			buff[BUFF_SIZE + 1];
	ssize_t			size;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || !(f = get_file(fd, &head)))
		return (-1);
	while (!ft_strchrs(f->str, '\n'))
	{
		if (!(size = read(fd, buff, BUFF_SIZE)))
		{
			if (!(*line = f->str))
				return (0);
			f->str = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = f->str;
		f->str = ft_strjoin(f->str, buff);
		free(tmp);
		if (!f->str)
			return (-1);
	}
	return (str_divide(&(f->str), line));
}

//t_arr				*newlist(const int fd)
//{
//	t_arr			*new;
//
//	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
//		return (NULL);
//	new->fd = fd;
//	new->rest = ft_strnew(BUFF_SIZE);
//	new->next = NULL;
//	return (new);
//}
//
//char				*checkrest(char **p_n, char *rest)
//{
//	char			*str;
//
//	if ((*p_n = ft_strchr(rest, '\n')) != NULL)
//	{
//		str = ft_strsub(rest, 0, *p_n - rest);
//		ft_strcpy(rest, ++(*p_n));
//	}
//	else
//	{
//		str = ft_strnew(ft_strlen(rest) + 1);
//		ft_strcat(str, rest);
//		ft_strclr(rest);
//	}
//	return (str);
//}
//
//int					get_line(const int fd, char **line, char *rest)
//{
//	char			buf[BUFF_SIZE + 1];
//	char			*p_n;
//	char			*tmp;
//	int				rd;
//
//	p_n = NULL;
//	rd = 1;
//	*line = checkrest(&p_n, rest);
//	while (p_n == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
//	{
//		buf[rd] = '\0';
//		if ((p_n = ft_strchr(buf, '\n')) != NULL)
//		{
//			ft_strcpy(rest, ++p_n);
//			ft_strclr(--p_n);
//		}
//		tmp = *line;
//		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
//			return (-1);
//		ft_strdel(&tmp);
//	}
//	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
//}
//
//int					get_next_line(const int fd, char **line)
//{
//	static t_arr	*list;
//	t_arr			*tmp;
//	int				ret;
//
//	if (fd < 0 || line == 0)
//		return (-1);
//	if (!list)
//		list = newlist(fd);
//	tmp = list;
//	while (tmp->fd != fd)
//	{
//		if (tmp->next == NULL)
//			tmp->next = newlist(fd);
//		tmp = tmp->next;
//	}
//	ret = get_line(fd, line, tmp->rest);
//	return (ret);
//}
