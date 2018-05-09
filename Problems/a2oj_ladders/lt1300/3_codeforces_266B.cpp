#include <stdint.h>
#include <stdio.h>


int main(){
  uint32_t n, t;
  scanf("%i %i", &n, &t);
  char str[50];
  scanf("%s", str);

  for (uint32_t i=0; i<t; ++i){
    uint32_t pos=0;
    while (pos < n-1){
      if (str[pos] == 'B' && str[pos+1] == 'G'){
        str[pos] = 'G'; str[pos+1] = 'B';
        ++pos;
      }
      ++pos;
    }
  }

  printf("%s\n", str);

  return 0;
}
