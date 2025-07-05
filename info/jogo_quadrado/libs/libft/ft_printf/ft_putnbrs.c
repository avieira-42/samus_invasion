/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:44:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 16:45:13 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_base(long nmbr, char *base, int baselen, int i)
{
	if (nmbr < 0)
	{
		i += ft_putcharmod('-');
		nmbr *= -1;
	}
	if (nmbr < baselen)
		i += ft_putcharmod(base[nmbr]);
	else
	{
		i = ft_putnbr_base(nmbr / baselen, base, baselen, i);
		i += ft_putcharmod(base[(nmbr % baselen)]);
	}
	return (i);
}

static int	ft_unsigned_base(unsigned long n, char *base
	, unsigned int baselen, int i)
{
	if (n >= baselen)
		i = ft_unsigned_base((n / baselen), base, baselen, i);
	i += ft_putcharmod(base[n % baselen]);
	return (i);
}

int	ft_putptr(void *address)
{
	unsigned long	addr;
	int				len;

	len = 0;
	if (!address)
		return (ft_putstrmod("(nil)"));
	addr = (unsigned long)address;
	len += ft_putstrmod("0x");
	len += ft_unsigned_base(addr, "0123456789abcdef", 16, 0);
	return (len);
}

int	ft_put_uint(unsigned int nbr)
{
	int		len;

	len = 0;
	len += ft_unsigned_base(nbr, "0123456789", 10, 0);
	return (len);
}
