


all : 
	@gcc -Wall -Wextra -Werror ft_printf.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c ft_print_str.c ft_print_pointer.c ft_print_x.c ft_print_u.c && ./a.out