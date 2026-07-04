#include <fcntl.h>
#include <unistd.h>
#define ABS(X) (X < 0) ? -(X) : (X)

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(char *str, int fd)
{
  while (*str)
    write(fd, str++, 1);
}

// how many times can a be divided by b
int div_n(int a, int b)
{
  int i;
  
  i = 0;
  while (a/b > 0)
    (a = a/b, i++);
  return (i);
}

void  puthex(int n, int padding) 
{
  n = ABS(n);
  while (div_n(n, 16) < (padding--) - 1)
    ft_putchar('0');
  if (n <= -16 || n >= 16)
    puthex(n / 16, 0);
  ft_putchar("0123456789abcdef"[n % 16]);
}

int main(int ac, char **av)
{
  int fd;  
  int line_n;
  int buf_s;
  int bytes_read;
  char buf[16];

  // puthex(-1, 2);
  // return 1;

  if (ac < 2)
    return (ft_putstr("Usage: ./hexdump <filepath>\n", 2), 1);
  fd = open(av[1], O_RDONLY);
  if (fd < 0)
    return (ft_putstr("Cannot find specified file\n", 2), 1);

  line_n = 0;
  while((bytes_read = read(fd, buf, 16)) > 0)
  {
    puthex(line_n, 8);
    ft_putstr("  ", 1);
    buf_s = 0;
    while (buf_s < 16)
    {
      if (buf_s >= bytes_read)
        ft_putstr("  ", 1);
      else
        puthex(buf[buf_s], 2);
      ft_putchar(' ');
      buf_s++;
    }
    ft_putchar(' ');
    buf_s = 0;
    while (buf_s < bytes_read)
    {
      if (buf[buf_s] >= ' ' && buf[buf_s] <= '~')
        ft_putchar(buf[buf_s]);
      else
        ft_putchar('.');
      buf_s++;
    }
    ft_putchar('\n');
    line_n += 16;
  }
  close(fd);
  return (1);
}
