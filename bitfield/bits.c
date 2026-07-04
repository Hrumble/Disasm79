#include <stdint.h>


int ft_pow(int n, int power)
{
  while (power) 
    return n * ft_pow(n, --power);
  return (1);
}

uint32_t get_bits(uint32_t value, int lo, int hi)
{
  int n;
  uint32_t b_mask = 0;
  n = lo;
  while (n <= hi)
    b_mask += ft_pow(2, n++);
  value = value & b_mask;
  value = value >> lo;
  return (value);
}

// #include <stdio.h>
// void print_bits(uint32_t n)
// {
//   for (int i = 31; i >= 0; i--)
//   {
//     printf("%d", (n >> i) & 1);
//     if (i % 8 == 0 && i != 32)
//       printf(" ");
//   }
//   printf("\n");
// }
//
// int main()
// {
//   uint32_t modrm = 0xC7;
//   print_bits(modrm);
//   print_bits(get_bits(modrm, 6, 7));
//   printf("0x%08x\n", get_bits(modrm, 6, 7));
//   print_bits(get_bits(modrm, 3, 5));
//   printf("0x%08x\n", get_bits(modrm, 3, 5));
//   print_bits(get_bits(modrm, 0, 2));
//   printf("0x%08x\n", get_bits(modrm, 0, 2));
// }
