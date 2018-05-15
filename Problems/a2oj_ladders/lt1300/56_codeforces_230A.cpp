#include <cstdio>
#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

class kirito_t{
  private:
    uint64_t strength_;
    bool dead_;
  public:
    kirito_t(uint64_t strn){
      strength_ = strn;
      dead_ = false;
    }

    kirito_t() : kirito_t(0) { };

    void fight(uint64_t strn, uint64_t xp){
      if (strength_ > strn)
        strength_ += xp;
      else
        dead_ = true;
    }

    bool is_dead(){
      return dead_;
    }
};

int main(){
  uint32_t n, s, xp;
  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> > min_heap;
  std::scanf("%u %u", &s, &n);
  kirito_t kirito(s);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%u %u", &s, &xp);
    min_heap.push(std::make_pair(s,xp));
  }

  while (min_heap.size() > 0){
    std::pair<int,int> m = min_heap.top();
    kirito.fight(m.first, m.second);
    min_heap.pop();
  }
  if (kirito.is_dead())
    std::cout << "NO";
  else
    std::cout << "YES";
}
