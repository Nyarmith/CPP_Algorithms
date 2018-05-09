#include <cstdio>
#include <cstdlib>

int main(){
  char c=std::getchar();
  if (c >= 'a' && c <= 'z')
    std::putchar(c - ('a'-'A'));
  else
    std::putchar(c);

  while ((c = std::getchar()) != '\n')
    std::putchar(c);
}
