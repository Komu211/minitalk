#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	// Test printf
	ft_printf("\n=== Testing ft_printf ===\n");
	ft_printf("String: %s\n", "Hello World");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hex: %x\n", 255);
	ft_printf("Pointer: %p\n", &main);

	// Test get_next_line
	ft_printf("\n=== Testing get_next_line ===\n");

	// First create a test file
	int fd_write = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd_write, "Line 1\nLine 2\nLine 3\nLine 4\n", 28);
	close(fd_write);

	// Now read it with get_next_line
	int fd_read = open("test.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd_read)))
	{
		ft_printf("GNL read: %s", line);
		free(line);
	}
	close(fd_read);

	return (0);
}