#include <cstdio>
#include <cstdint>
#include <queue>

int main(){
  int k,c,sum=0;
  std::scanf("%i", &k);
  std::priority_queue<int> waters;
  for (int i=0; i<12; ++i){ //load months
    std::scanf("%i", &c);
    waters.push(c);
  }
  while (sum<k && waters.size() > 0){
    sum += waters.top();
    waters.pop();
  }
  if (sum >= k)
    std::printf("%i",12-(int)waters.size());
  else
    std::printf("-1");
}
