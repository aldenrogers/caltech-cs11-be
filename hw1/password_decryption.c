#include <stdio.h>

// This runs from 0x4005bd to 0x400615
void decode_password(int l, char* d) {
  char* data = d;    // -0x18(%rbp)
  int len = l;       // -0x1c(%rbp)
  char carry = 0xff; // -0x01(%rbp)
  int i = 0;         // -0x08(%rbp)
  while (i < len) {
    char a = data[i];
    data[i] = a ^ carry;
    carry = a;
    ++i;
  }
}

int main(int argc, char *argv[]) {
  // length initialized at 0x40065c
  // Encoded password comes from
  // 0x400748
  // as referenced at 0x40062e
  char pwd[28] = {0x84,0xf4,0x83,0xe7,
                  0xb8,0xcb,0xa2,0xcf,
                  0xbf,0xd3,0xb6,0xe9,
                  0x8f,0xfa,0x94,0xcb,
                  0xb3,0xdc,0xae,0xf1,
                  0x83,0xe6,0x90,0xf5,
                  0x87,0xf4,0x91,0xe3};
  decode_password(28, pwd);
  printf("%.*s\n", 28, pwd);
}
