#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_delay(void)
{
	int	i;

	i = 0;
	while (i < 30000000)
		i++;
}

void	ft_typewriter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		ft_delay();
		i++;
	}
}

void	print_top(void)
{
	ft_putstr("╔════════════════════════════════════════╗\n");
}

void	print_bottom(void)
{
	ft_putstr("╚════════════════════════════════════════╝\n");
}

void	print_empty_line(void)
{
	ft_putstr("║                                        ║\n");
}

void	print_card(void)
{
	print_top();
	print_empty_line();
	ft_putstr("║        ✦ A Y M A N E   C A R D ✦       ║\n");
	print_empty_line();
	ft_putstr("║        Name     : Aymane               ║\n");
	ft_putstr("║        Level    : C Piscine Learner    ║\n");
	ft_putstr("║        Skill    : Problem Solving      ║\n");
	ft_putstr("║        Status   : Building in C        ║\n");
	print_empty_line();
	ft_putstr("║        Quote    : Code. Debug. Repeat. ║\n");
	print_empty_line();
	print_bottom();
}

int	main(void)
{
	ft_typewriter("\nLaunching Aymane terminal card...\n\n");
	print_card();
	return (0);
}