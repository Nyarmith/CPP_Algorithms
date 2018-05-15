#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <map>
#include <cmath>

int arr[100];

int main(){
  uint32_t n;
  std::scanf("%u", &n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%i",arr+i);
  }
  uint32_t l=0, r=n-1, dist;
  uint32_t minDist=dist=std::abs(arr[n-1] - arr[0]);

  for (uint32_t i=0; i<n-1; ++i){
    dist=std::abs(arr[i+1]-arr[i]);
    if (dist < minDist){
      minDist = dist;
      l=i; r=i+1;
    }
  }
  //this could be halted to print as soon as a 0 is found, but oh well
  //might play with those kinds of optimizations later
  std::printf("%i %i", l+1, r+1);
}


//this was actually solving the wrong problem but I will keep it here for posterity's sake
/*

//approach 1

std::map<uint32_t, uint32_t> uniq;

int main(){
  uint32_t n,c;
  uint32_t dist, l=0, r=1;
  bool ezans=false;
  std::scanf("%u", &n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%u", &c);
    if (uniq.find(c) == uniq.end())
      uniq[c] = i;
    else{
      ezans=true;
      l=uniq[c];
      r=i;
    }
  }

  if (!ezans){
    auto it1 = uniq.begin();
    auto it2 = uniq.begin();
    ++it2;
    uint32_t minDist = 0xFFFFFFFF;
    while(it2 != uniq.end()){
      dist = it2->first - it1->first;
      if (dist < minDist){
        minDist = dist;
        l=it1->second; r=it2->second;
      }
      ++it1; ++it2;
    }
  }
  std::printf("%u %u", l+1, r+1);
}

*/


//approach 2

/*
#include <cstdio>
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>
                                                              
using std::uint32_t;                                          
using std::vector;

//WARNING == UNORIGINAL CODE                                  
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}


int main(){

  vector<uint32_t> myVec;
  myVec.reserve(100000);

  uint32_t n, c;

  std::scanf("%u", &n);

  for (uint32_t i=0; i<n; ++i){
    std::scanf("%u", &c);
    myVec.push_back(c);
  }
  auto inds = sort_indexes(myVec);

  uint32_t l=0, r=0, minPair=0xFFFFFFFF;

  std::scanf("%u", &n);
  uint32_t diff;
  for (uint32_t i=0; i<n-1; ++i){
    diff = myVec[inds[i+1]] - myVec[inds[i]];
    if (diff < minPair){
      minPair = diff;
      l=inds[i]; r=inds[i+1];
    }
  }

  std::cout << l << " " << r << std::endl;
}
*/
