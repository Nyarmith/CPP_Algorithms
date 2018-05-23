#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <functional>


struct pairCompare{
  bool operator()(std::pair<int,int> l, std::pair<int,int> r){
    if (l.first > r.first || (l.first == r.first && l.second < r.second))
      return false;
    return true;
  }
};

//todo, try to make a heap do this for you automatically
int main(){
  int n, k, t_in, p_in;
  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, pairCompare> mypq;

  std::scanf("%i %i",&n,&k);
  for (int i=0; i<n; ++i){
    std::scanf("%i %i", &t_in, &p_in);
    mypq.push(std::make_pair(t_in, p_in));
  }
  int same=1;
  int place=1;
  int places[n];
  std::pair<int,int> last = mypq.top();
  mypq.pop();
  while (mypq.size()){
    if ( last == mypq.top() )
      ++same;
    else{
      for (int i=0; i<same; ++i){
        places[place-1-i] = same;
      }
      same = 1;
      last = mypq.top();
    }
    mypq.pop();
    ++place;
  }

  for (int i=0; i<same; ++i){
    places[place-1-i] = same;
  }

  std::cout << places[k-1];
}
