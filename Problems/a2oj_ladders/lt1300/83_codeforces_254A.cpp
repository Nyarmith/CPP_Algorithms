#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>

/*int decrement(std::map<int,std::vector<int>> &m, int k){
  int ret = *m[k].rbegin();
  m[k].pop_back();
  if (m[k].size() == 0){
    m.erase(k);
  }
  return ret;
}*/

/* This solves a more interesting problem
std::vector<std::pair<int,int>> partition(std::map<int,std::vector<int>> &m){
  std::vector<std::pair<int,int>> ret;
  int fst=m.begin()->first;
  int snd = m.rbegin()->first;
  int prevSum = fst+snd;
  ret.push_back(
      std::make_pair<int,int>(decrement(m, fst),
  decrement(m, snd)));
  while (m.size() > 0){
    fst=m.begin()->first;
    snd = m.rbegin()->first;
    if (prevSum != fst + snd)
      return std::vector<std::pair<int,int>>();
    ret.push_back(std::make_pair(
    decrement(m,fst),
    decrement(m,snd)));
  }
  return ret;
}
*/

std::vector<std::pair<int,int>> partition(std::map<int,std::vector<int>> &m){
  std::vector<std::pair<int,int>> ret;
  while (m.size() > 0){
    auto begin = m.begin();
    if (begin->second.size() < 2)
      return std::vector<std::pair<int,int>>();

    auto itr = begin->second.rbegin();
    int fst = *itr;
    begin->second.pop_back();
    itr = begin->second.rbegin();
    int snd = *itr;
    begin->second.pop_back();

    if (begin->second.size() == 0)
      m.erase(begin);

    ret.push_back(std::make_pair(fst,snd));
  }
  return ret;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,k;
  std::map<int,std::vector<int>> m;
  std::cin >> n;
  for (int i=0; i<2*n; ++i){
    std::cin >> k;
    m[k].push_back(i);
  }
  std::vector<std::pair<int,int>> pair = partition(m);
  if (pair.size() == 0)
    std::cout << -1;
  else
    for (auto it=pair.begin(); it!=pair.end(); ++it)
      std::cout << (it->first+1) << " " << (it->second+1) << "\n";
}
