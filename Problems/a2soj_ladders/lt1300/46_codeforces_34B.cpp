#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <queue>

int main(){
  std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
  int sum=0;
  int n, m, c;
  std::scanf("%i %i", &n, &m);
  for (int i=0; i<n; ++i){
    std::scanf("%i", &c);
    if (c < 0 && ((int)min_heap.size()<m || -c>min_heap.top())){
      if ((int)min_heap.size() == m){
        sum -= min_heap.top();
        min_heap.pop();
      }
      min_heap.push(-c);
      sum += -c;
    }
  }

  printf("%i", sum);
}
