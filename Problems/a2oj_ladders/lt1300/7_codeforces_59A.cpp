#include <cstdio>
#include <cstdint>
#include <cmath>

char ourStr[101];

int main(){
  std::scanf("%s",ourStr);
  int i=0;
  int diff='a'-'A';
  uint32_t lower=0;
  uint32_t upper=0;
  //tally votes
  while (ourStr[i] != '\0'){
    if (ourStr[i] >= 'A' && ourStr[i] <= 'Z')
      upper++;
    else
      lower++;
    ++i;
  }
  i=0;
  while (ourStr[i] != '\0'){
    if (lower >= upper && ourStr[i] <= 'Z' && ourStr[i] >= 'A')
      ourStr[i] += diff;
    else if (upper > lower && ourStr[i] <= 'z' && ourStr[i] >= 'a')
      ourStr[i] -= diff;
    ++i;
  }

  printf("%s",ourStr);
}
