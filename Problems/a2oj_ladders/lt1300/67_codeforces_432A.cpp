#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
#include <vector>

std::vector<std::tuple<int,int,int>> make_tuples(std::map<int,int> &nums, int n){
  std::vector<std::tuple<int,int,int>> tuples;
  tuples.reserve(n/3);
  auto it = nums.begin();
  while (it != nums.end()){
    int fst = it->first;
    while (it->first == fst && it != nums.end())
      ++it;
    while (it != nums.end() && it->first % fst != 0)
      ++it;
    if (it == nums.end())
      return std::vector<std::tuple<int,int,int>>();
    int snd = it->first;
    while (it->first == snd && it != nums.end())
      ++it;
    while (it != nums.end() && it->first % snd != 0)
      ++it;
    if (it == nums.end())
      return std::vector<std::tuple<int,int,int>>();
    int thrd = it->first;
    tuples.push_back(std::make_tuple(fst,snd,thrd));
    //clean up
    --nums[thrd]; --nums[snd]; --nums[fst];
    if (nums[thrd] == 0)
      nums.erase(thrd);
    if (nums[snd] == 0)
      nums.erase(snd);
    if (nums[fst] == 0)
      nums.erase(fst);

    it = nums.begin();
  }
  return tuples;
}


int main(){
  int n,c;
  std::map<int,int> nums;
  std::scanf("%i",&n);
  for (int i=0; i<n; ++i){
    std::scanf("%i",&c);
    nums[c]++;
  }

  auto v = make_tuples(nums,n);
  if (v.size() == 0)
    std::printf("-1");
  else{
    for (int i=0; i<v.size(); ++i){
      std::printf("%i %i %i\n", std::get<0>(v[i]),
          std::get<1>(v[i]), std::get<2>(v[i]));
    }
  }
}
