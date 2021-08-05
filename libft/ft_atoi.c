/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:52:07 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 22:41:45 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	calc_coef(char c)
{
	int	coef;

	if (c == '-')
		coef = -1;
	else
		coef = 1;
	return (coef);
}

int	ft_atoi(char *s)
{
	int		i;
	int		coef;
	long	result;

	i = 0;
	coef = 1;
	result = 0;
	while ((s[i] != '\0' && (s[i] >= '\t' && s[i] <= '\r')) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		coef = calc_coef(s[i]);
		i++;
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += (s[i] - '0') * coef;
		if (coef > 0 && result < 0)
			return (-1);
		if (coef < 0 && result > 0)
			return (0);
		i++;
	}
	return (result);
}
