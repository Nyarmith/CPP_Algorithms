#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int main(){
  int n,m, tmp;
  std::priority_queue <int, std::vector<int>, std::greater<int> > minq;
  std::priority_queue <int> maxq;
  std::scanf("%i %i", &n, &m);
  for (int i=0; i<m; ++i){
    std::scanf("%i", &tmp);
    minq.push(tmp);
    maxq.push(tmp);
  }
  
  int min=0;
  int max=0;
  for (int i=0; i<n; ++i){
    //min calculator
    int cheapest=minq.top();
    minq.pop();
    min += cheapest;
    --cheapest;
    if (cheapest > 0){
      minq.push(cheapest);
    }
    //max calculator
    int expensivest=maxq.top();
    maxq.pop();
    max += expensivest;
    --expensivest;
    if (expensivest > 0)
      maxq.push(expensivest);
  }

  std::printf("%i %i", max, min);
}
