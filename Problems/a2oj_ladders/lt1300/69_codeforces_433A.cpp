#include <cstdio>
#include <cstdint>

int main(){
  int smapple=0;
  int bapple=0;
  int n,c;

  std::scanf("%i",&n);
  for (int i=0; i<n; ++i){
    std::scanf("%i",&c);
    if (c == 100)
      ++smapple;
    else
      ++bapple;
  }

  if ((smapple%2==0 && bapple%2==0)
      || (smapple%2 == 0 && smapple>0 && bapple%2==1))
    std::printf("YES");
   else
    std::printf("NO");

}
