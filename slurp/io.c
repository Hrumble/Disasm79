#include "io.h"

uint8_t *read_file(const char *path, size_t *out_len)
{
  uint8_t *buf;
  int size_mul;
  int fd;

  if ((fd = open(path, O_RDONLY)) < 0)
    return (malloc(0));
  if (!(buf = malloc(MAX_SIZE * sizeof(uint8_t))))
    return (malloc(0));

  *out_len = 0;
  size_mul = 1;
  while (read(fd, &buf[*out_len], 1))
  {
    (*out_len)++;
    if (*out_len >= MAX_SIZE)
      buf = realloc(buf, MAX_SIZE * ++size_mul * sizeof(uint8_t));
  }
  if (*out_len < MAX_SIZE * size_mul)
    buf = realloc(buf, *out_len * sizeof(uint8_t));
  return (buf);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
//   size_t size;
//   uint8_t *buf;    
//
//   buf = read_file(av[1], &size);
//   if (!buf)
//     return (free(buf), 1);
//   int i = 0;
//   printf("size: %zu\n", size);
//   while (i < size)
//     printf("%c", buf[i++]);
//   free(buf);
// }
