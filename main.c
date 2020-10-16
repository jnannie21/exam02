#include <stdio.h>

int			ft_printf(const char *format, ... );

int			main(void)
{
	int		ret = 0;

	ret = ft_printf("%10.2s\n", "toto");
	printf("%d\n", ret);
	ret = printf("%10.2s\n", "toto");
	printf("%d\n", ret);
	ret = ft_printf("Magic %s is %5d", "number", 42);
	printf("%d\n", ret);
	ret = printf("Magic %s is %5d", "number", 42);
	printf("%d\n", ret);
	ret = ft_printf("Hexadecimal for %d is %7x\n", 6666666, 6666666);
	printf("%d\n", ret);
	ret = printf("Hexadecimal for %d is %7x\n", 6666666, 6666666);
	printf("%d\n", ret);

	// ft_printf("%15.12d | %15.12x | %0.0d | %x\n", 100, 100, -15, -15);
	// printf("%15.12d | %15.12x | %0.0d | %x\n", 100, 100, -15, -15);
	// ft_printf("%15.12s | %15.2s | %.2s | %s\n", "100", "100", "100", "");
	// printf("%15.12s | %15.2s | %.2s | %s\n", "100", "100", "100", "");
	// ft_printf("%10.2s\n", "toto");
	// ft_printf("Magic %s is %5d", "number", 42);
	// ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	// printf("Magic %s is %5d", "number", 42);
	// printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}