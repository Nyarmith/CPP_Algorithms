#include <cstdio>
#include <cstdint>

int main(){
  uint32_t n;
  char usrInput[51];
  std::scanf("%u", &n);
  std::scanf("%s", usrInput);
  uint32_t i=1;
  int rmv=0;
  char c = usrInput[0];
  while (i < n){
    if (usrInput[i] == c)
      ++rmv;
    else
      c = usrInput[i];
    ++i;
  }

  printf("%i", rmv);
}
