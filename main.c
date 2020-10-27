#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

const uint8_t swap_table_encode[256] =
{
  0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
  0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
  0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
  0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
  0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
  0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
  0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
  0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
  0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
  0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
  0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
  0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
  0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
  0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
  0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
  0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16,
};

const uint8_t swap_table_decode[256] = {
  0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
  0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
  0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
  0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
  0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
  0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
  0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
  0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
  0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
  0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
  0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
  0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
  0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
  0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
  0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
  0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D,
};

uint8_t xor_key_table[11][16] = { 0 };

int xor_data_buffer(uint8_t *pbuf, const uint8_t *pkey, int size)
{
  for (int i = 0; i < size; i++)
  {
    pbuf[i] ^= pkey[i];
  }
  return size;
}

void swap_data_buffer(uint8_t *pdata, int size, int decode)
{
  const uint8_t *p_swap = 0;

  p_swap = decode ? swap_table_decode : swap_table_encode;

  for (int i = 0; i < size; i++)
  {
    pdata[i] = p_swap[pdata[i]];
  }
}

void shuffle_data_buffer(uint8_t *pdata, int decode)
{
  uint8_t tmp[4] = { 0 };

  for (int i = 1; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      tmp[j] = pdata[4 * j + i];
    }
    int pos = decode ? (4 - i) : i;

    for (int n = 0; n < 4; n++)
    {
      pdata[4 * n + i] = tmp[(pos + n) % 4];
    }
  }
}

uint8_t xor_byte(uint8_t data)
{
  if (data & 0x80)
    return ((data << 1) ^ 0x1B);
  else
    return (data << 1) & 0xFF;
}

int xor_data_block(uint8_t *pdata, int decode)
{
  uint8_t xor_array[4] = { 0 };

  for (int i = 0; i < 4; i++)
  {
    uint8_t xor_key = pdata[0] ^ pdata[1] ^ pdata[2] ^ pdata[3];

    xor_array[0] = xor_byte(pdata[0] ^ pdata[1]) ^ (pdata[0] ^ xor_key);
    xor_array[1] = xor_byte(pdata[1] ^ pdata[2]) ^ (pdata[1] ^ xor_key);
    xor_array[2] = xor_byte(pdata[2] ^ pdata[3]) ^ (pdata[2] ^ xor_key);
    xor_array[3] = xor_byte(pdata[3] ^ pdata[0]) ^ (pdata[3] ^ xor_key);

    if (decode)
    {
      uint8_t a, b, c;
      a = xor_byte(xor_byte(pdata[0] ^ pdata[2]));
      b = xor_byte(xor_byte(pdata[1] ^ pdata[3]));
      c = xor_byte(a ^ b);

      xor_array[0] ^= c ^ a;
      xor_array[1] ^= c ^ b;
      xor_array[2] ^= c ^ a;
      xor_array[3] ^= c ^ b;
    }

    memcpy(pdata, xor_array, 4);
    pdata += 4;
  }

  return 0;
}

int decrypt_data_block(uint8_t *pdata)
{
  xor_data_buffer(pdata, xor_key_table[10], 16);

  for (int i = 9; i >= 0; i--)
  {
    shuffle_data_buffer(pdata, 1);
    swap_data_buffer(pdata, 16, 1);
    xor_data_buffer(pdata, xor_key_table[i], 16);

    if (i != 0)
    {
      xor_data_block(pdata, 1);
    }
  }

  return 0;
}

int encrypt_data_block(uint8_t *pdata)
{
  xor_data_buffer(pdata, xor_key_table[0], 16);

  for (int i = 1; i <= 10; i++)
  {
    swap_data_buffer(pdata, 16, 0);
    shuffle_data_buffer(pdata, 0);
    if (i != 10)
    {
      xor_data_block(pdata, 0);
    }
    xor_data_buffer(pdata, xor_key_table[i], 16);
  }

  return 0;
}

int decrypt_data_buffer(uint8_t *pdata, int size, uint8_t *pkey)
{
  int n = size / 16;
  uint8_t *p = &pdata[size - 16];

  while (n)
  {
    decrypt_data_block(p);
    if (n == 1) /* last one ? */
    {
      xor_data_buffer(p, pkey, 16);
    }
    else
    {
      xor_data_buffer(p, p - 16, 16);
    }
    --n;
    p -= 16;
  }

  return size;
}

int encrypt_data_buffer(uint8_t *pdata, int size, uint8_t *pkey)
{
  int n = size / 16;
  uint8_t *p = pdata;

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      xor_data_buffer(p, pkey, 16);
    }
    else
    {
      xor_data_buffer(p, p - 16, 16);
    }
    encrypt_data_block(p);
    p += 16;
  }

  return size;
}

void rol_bytes(uint8_t *p)
{
  uint8_t t;

  t = p[0];
  p[0] = p[1];
  p[1] = p[2];
  p[2] = p[3];
  p[3] = t;
}

int generate_xor_table(char *psz_key)
{
  int key_len = strlen(psz_key);
  if (key_len != 16)
    return -1;
  /* first entry it is key itself */
  memcpy(xor_key_table[0], psz_key, key_len);
  uint32_t xor_key = 1;

  uint32_t *p_table = (void *)xor_key_table[1];
  for (int i = 4; i < 44; i++)
  {
    p_table[0] = p_table[-1];
    if ((i % 4) == 0)
    {
      rol_bytes((uint8_t *)p_table);
      swap_data_buffer((uint8_t *)p_table, 4, 0);
      xor_data_buffer((uint8_t *)p_table, (uint8_t *) & xor_key, 4);
      xor_key = xor_byte(xor_key & 0xFF);
    }
    xor_data_buffer((uint8_t *)p_table, (uint8_t *) & p_table[-4], 16);
    ++p_table;
  }

  return 0;
}

#include <getopt.h>
int main(int argc, char *argv[])
{
  FILE *f = 0, *o = 0;
  uint8_t buffer[2048];
  uint8_t xor_key[16] = { 0 };
  int c, encode = 0;

#ifdef __linux__
  while ((c = getopt(argc, argv, "ei:o:")) != -1)
#else
  while ((c = _getopt(argc, argv, "ei:o:")) != -1)
#endif
  {
    switch (c)
    {
      case 'e':
        encode = 1;
        break;
      case 'i':
        f = fopen(optarg, "rb");
        printf("intput: %s\n", optarg);
        break;
      case 'o':
        o = fopen(optarg, "wb");
        printf("output: %s\n", optarg);
        break;
    }
  }

  if (!f || !o)
  {
    printf("input/output path does not exist\n");
    exit(-1);
  }

  printf("%s firmware... ", encode ? "encode" : "decode");

  generate_xor_table("flashforge790315");

  while (feof(f) == 0)
  {
    int align_r, w, r = fread(buffer, 1, sizeof(buffer), f);
    if (r < 16)
      break;
    /* if firmware has unaligned data chunk it will not be decoded/encoded */
    align_r = r & (~15);
    if (encode)
    {
      encrypt_data_buffer(buffer, align_r, xor_key);
    }
    else
    {
      decrypt_data_buffer(buffer, align_r, xor_key);
    }
    w = fwrite(buffer, 1, r, o);
    if (w != r)
    {
      printf("i/o problem...\n");
      exit(-3);
    }
  }
  fclose(f);
  fclose(o);

  printf("done\n");
  return 0;
}