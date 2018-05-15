#include <cstdio>
#include <cstdint>

//the main challenge in this problem was understanding the question

int main(){
  int minTime=2000000000, minTown=-1, c, n;
  bool STILL=false;
  std::scanf("%i", &n);
  for (int i=0; i<n; ++i){
    std::scanf("%i", &c);
    if (c < minTime){
      minTime = c;
      minTown = i;
      STILL = false;
    }
    else if (c == minTime){
      STILL = true;
    }
  }

  if (STILL){
    std::printf("Still Rozdil");
  } else{
    std::printf("%i", minTown+1);
  }
}
