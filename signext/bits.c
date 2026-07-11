#include <stdint.h>

void print_bits(int64_t n, int size);

int64_t sign_extend(uint64_t value, int bits)
{
  int64_t sign;
  int64_t l_byte = value;
  int     i = 63;

  sign = (value >> (bits - 1)) & 1;
  while (i >= bits)
  {
    l_byte = l_byte | (sign << i--);
  }
  print_bits(l_byte, 64);
  return(l_byte);
}

// #include <stdio.h>
// void print_bits(int64_t n, int size)
// {
//   for (int i = size - 1; i >= 0; i--)
//   {
//     printf("%ld", (n >> i) & 1);
//     if (i % 8 == 0 && i != 0)
//       printf(" ");
//   }
//   printf("\n");
// }
//
// int main()
// {
//   printf("%ld\n", sign_extend(0xF8, 8));
//   printf("%ld\n", sign_extend(0x7F, 8));
//   printf("%ld\n", sign_extend(0xFFFFFFFF, 32));
// }
