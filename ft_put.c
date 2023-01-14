#include "push_swap.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[i])
	{
		len += write(fd, &str[i], 1);
		i++;
	}
	return (len);
}

int	ft_putnbr_fd(int nb, int fd)
{
	int		len;
	long	i;

	len = 0;
	i = nb;
	if (i < 0)
	{
		len += write(fd, "-", 1);
		i *= -1;
	}
	if (i > 9)
		len += ft_putnbr_fd((i / 10), 1);
	len += ft_putchar_fd((i % 10 + 48), 1);
	return (len);
}