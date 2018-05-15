#include <cstdint>
#include <cstdio>

char numStr[20];

int main(){
  std::scanf("%s",numStr);
  int isLucky=0;
  for (int i=0; numStr[i] != '\0'; ++i)
    isLucky += (numStr[i] == '4' || numStr[i] == '7' );

  if (isLucky==4 || isLucky==7)
    printf("YES");
  else
    printf("NO");
}

//wow I didn't read the problem statement thoroughly enough, mistake 0
