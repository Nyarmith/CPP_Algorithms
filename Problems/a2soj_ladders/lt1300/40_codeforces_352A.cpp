#include <cstdio>
#include <cstdint>
#include <string>

//has to be a combination of this pattern
//const std::string fives="5555555550";
const int MINFIVES=9;


int main(){
  int n,c;
  int numFives=0;
  int numZeros=0;
  std::scanf("%i",&n);
  for (int i=0; i<n; ++i){
    std::scanf("%i", &c);
    if (c == 5){
      numFives++;
    } else {
      numZeros++;
    }
  }
  if (numZeros == 0){
    std::printf("-1");
  } else if (numFives < 9)
      printf("0");
  else{
    while(numFives >= 9){
      std::printf("555555555");
      numFives-=9;
    }
    while(numZeros){
      std::printf("0");
      --numZeros;
    }
  }
}
