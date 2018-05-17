#include <cstdint>
#include <algorithm>
#include <iostream>

int main(){
  int n, tmp;
  int s=0,m=0,l=0;
  bool can=true;
  std::scanf("%i",&n);
  for (int i=0; i<n; ++i){
    std::scanf("%i",&tmp);
    switch(tmp){
      case 25:
        s++;
        break;
      case 50:
        if (s == 0)
          can = false;
        --s;
        ++m;
        break;
      case 100:
        if (m>0 && s>0){
          --m; --s;
        } else if (m == 0 && s>2){
          s-=3;
        } else {
          can=false;
        }
        ++l;
        break;
    }
  }
  if (can){
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}
