/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:31:53 by aychikhi          #+#    #+#             */
/*   Updated: 2025/06/22 16:01:39 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_word(char *input, int *i, t_token **tokens, t_token **last)
{
	char	*word;

	word = add_word(input + *i);
	add_token(tokens, last, TOKEN_WORD, word);
	*i += ft_strlen(word);
	free(word);
}

char	*extract_var(char *var)
{
	char	*new;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (var[l] != '=')
		l++;
	new = malloc(l + 1);
	if (!new)
		malloc_error();
	while (i < l)
	{
		new[i] = var[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int	ft_len(char *value)
{
	int	i;
	int	l;
	int	f;

	i = 0;
	l = 0;
	f = 0;
	while (value[i])
	{
		if (value[i] == '=' && !f)
		{
			i++;
			l = 0;
			f++;
		}
		l++;
		i++;
	}
	return (l);
}

static int	new_start(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*extract_value(char *value)
{
	char	*new;
	int		i;
	int		l;

	i = 0;
	l = ft_len(value);
	new = malloc(l + 1);
	if (!new)
		malloc_error();
	i = 0;
	l = new_start(value);
	while (value[l])
	{
		new[i] = value[l];
		l++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
