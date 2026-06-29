#include <unistd.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define CARD_WIDTH 58
#define INNER_WIDTH 56

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	sleep_ms(int ms)
{
	usleep(ms * 1000);
}

void	clear_screen(void)
{
	ft_putstr("\033[2J\033[H");
}

void	hide_cursor(void)
{
	ft_putstr("\033[?25l");
}

void	show_cursor(void)
{
	ft_putstr("\033[?25h");
}

void	print_spaces(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
}

void	print_chars(char c, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar(c);
		i++;
	}
}

void	type_text(char *str, int speed)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		sleep_ms(speed);
		i++;
	}
}

void	print_line_center(char *text)
{
	int	len;
	int	left;
	int	right;

	len = ft_strlen(text);
	if (len > INNER_WIDTH)
		len = INNER_WIDTH;
	left = (INNER_WIDTH - len) / 2;
	right = INNER_WIDTH - len - left;
	ft_putchar('|');
	print_spaces(left);
	ft_putstr(text);
	print_spaces(right);
	ft_putstr("|\n");
}

void	print_empty_box_line(void)
{
	ft_putchar('|');
	print_spaces(INNER_WIDTH);
	ft_putstr("|\n");
}

void	print_border(void)
{
	ft_putchar('+');
	print_chars('-', CARD_WIDTH - 2);
	ft_putstr("+\n");
}

void	print_kv(char *key, char *value)
{
	int	used;
	int	key_width;

	key_width = 12;
	ft_putstr("|  ");
	ft_putstr(key);
	print_spaces(key_width - ft_strlen(key));
	ft_putstr(": ");
	ft_putstr(value);
	used = 2 + key_width + 2 + ft_strlen(value);
	print_spaces(INNER_WIDTH - used);
	ft_putstr("|\n");
}

void	print_skill(char *name, int level)
{
	int	i;
	int	used;

	ft_putstr("|  ");
	ft_putstr(name);
	print_spaces(14 - ft_strlen(name));
	ft_putstr("[");
	i = 0;
	while (i < 20)
	{
		if (i < level)
			ft_putchar('#');
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("] ");
	ft_putnbr(level * 5);
	ft_putchar('%');
	used = 2 + 14 + 1 + 20 + 2;
	if (level * 5 < 10)
		used += 1;
	else if (level * 5 < 100)
		used += 2;
	else
		used += 3;
	print_spaces(INNER_WIDTH - used);
	ft_putstr("|\n");
}

void	loading_bar(char *label)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 20)
	{
		ft_putstr("\r\033[K");
		ft_putstr(CYAN);
		ft_putstr(label);
		ft_putstr(RESET);
		ft_putstr(" [");
		j = 0;
		while (j < 20)
		{
			if (j < i)
				ft_putstr(GREEN "#");
			else
				ft_putstr(DIM "." RESET);
			j++;
		}
		ft_putstr(RESET);
		ft_putstr("] ");
		ft_putnbr(i * 5);
		ft_putchar('%');
		sleep_ms(55);
		i++;
	}
	ft_putchar('\n');
}

void	spinner(char *text)
{
	char	frames[4];
	int		i;

	frames[0] = '|';
	frames[1] = '/';
	frames[2] = '-';
	frames[3] = '\\';
	i = 0;
	while (i < 28)
	{
		ft_putstr("\r\033[K");
		ft_putstr(YELLOW);
		ft_putchar(frames[i % 4]);
		ft_putstr(RESET);
		ft_putchar(' ');
		ft_putstr(text);
		sleep_ms(70);
		i++;
	}
	ft_putstr("\r\033[K");
}

void	print_banner(void)
{
	ft_putstr(CYAN);
	ft_putstr("      ___   __   __  __  __   ___   _   _  _____ \n");
	ft_putstr("     / _ \\  \\ \\ / / |  \\/  | / _ \\ | \\ | || ____|\n");
	ft_putstr("    / /_\\ \\  \\ V /  | |\\/| |/ /_\\ \\|  \\| || |__  \n");
	ft_putstr("    |  _  |   | |   | |  | ||  _  || . ` ||  __| \n");
	ft_putstr("    | | | |   | |   | |  | || | | || |\\  || |___ \n");
	ft_putstr("    \\_| |_/   \\_/   \\_|  |_/\\_| |_/\\_| \\_/|_____|\n");
	ft_putstr(RESET);
}

void	print_matrix_line(char *line)
{
	ft_putstr(GREEN);
	type_text(line, 1);
	ft_putstr(RESET);
	ft_putchar('\n');
}

void	print_intro(void)
{
	clear_screen();
	hide_cursor();
	ft_putstr(GREEN);
	type_text("Booting terminal identity system", 18);
	ft_putstr(RESET);
	type_text("...", 120);
	ft_putchar('\n');
	sleep_ms(250);
	print_matrix_line("01001010 11001010 00110101 10101010 11100010");
	print_matrix_line("10101100 00101010 11101011 00010101 01010111");
	print_matrix_line("11100011 10101010 00100101 11110101 01101000");
	ft_putchar('\n');
	spinner("Checking terminal energy");
	loading_bar("Loading core");
	spinner("Preparing dashboard");
	loading_bar("Building interface");
	sleep_ms(250);
	clear_screen();
}

void	print_dashboard(char *name)
{
	print_banner();
	ft_putchar('\n');
	ft_putstr(BOLD MAGENTA);
	print_border();
	print_line_center("TERMINAL IDENTITY DASHBOARD");
	print_border();
	ft_putstr(RESET);
	print_empty_box_line();
	print_kv("Name", name);
	print_kv("Mode", "Live Terminal Project");
	print_kv("Language", "C");
	print_kv("Compiler", "cc -Wall -Wextra -Werror");
	print_kv("Status", "Online");
	print_kv("Mission", "Build. Break. Debug. Repeat.");
	print_empty_box_line();
	ft_putstr(CYAN);
	print_line_center("SKILLS");
	ft_putstr(RESET);
	print_skill("C Basics", 17);
	print_skill("Logic", 15);
	print_skill("Terminal", 18);
	print_skill("Debugging", 14);
	print_empty_box_line();
	ft_putstr(YELLOW);
	print_line_center("COMMANDS");
	ft_putstr(RESET);
	print_kv("./aymane", "Open dashboard");
	print_kv("./aymane NAME", "Use custom name");
	print_kv("./aymane --help", "Show help");
	print_empty_box_line();
	ft_putstr(BOLD MAGENTA);
	print_border();
	ft_putstr(RESET);
}

void	print_help(void)
{
	ft_putstr(BOLD CYAN);
	ft_putstr("\nAYMANE TERMINAL PROJECT\n");
	ft_putstr(RESET);
	ft_putstr("\nUsage:\n");
	ft_putstr("  ./aymane\n");
	ft_putstr("  ./aymane NAME\n");
	ft_putstr("  ./aymane --help\n");
	ft_putstr("\nExamples:\n");
	ft_putstr("  ./aymane\n");
	ft_putstr("  ./aymane Aymane\n");
	ft_putstr("  ./aymane \"Aymane Dev\"\n\n");
}

void	print_exit(void)
{
	ft_putchar('\n');
	ft_putstr(DIM);
	type_text("System ready. Keep building.\n", 18);
	ft_putstr(RESET);
	show_cursor();
}

int	main(int argc, char **argv)
{
	char	*name;

	name = "Aymane";
	if (argc >= 2)
	{
		if (ft_strcmp(argv[1], "--help") == 0)
		{
			print_help();
			return (0);
		}
		name = argv[1];
	}
	print_intro();
	print_dashboard(name);
	print_exit();
	return (0);
}