#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>

struct region{
  int l, r;
  int zeros;
  region(int l, int r, int zr)  : l(l), r(r), zeros(zr) { }
  region(int l, int r) : region(l,r,0) { }
  region() : region(0,0,0) { }
};

std::pair<int,int> getmaxrng(bool ones[], int n){
  std::vector<region> zones;
  int i=0;
  while (i<n){
    if (ones[i] == false){ //start of a region
      int zeros=0;
      int l=i;
      while((i<n && !ones[i])){ // || (i<n-1 && !ones[i+1]) ){ //premature optimization = evil
        zeros += 1;
        ++i;
      }
      --i;
      zones.push_back(region(l,i,zeros));
    }
    ++i;
  }

  std::vector<region> mergedZones;
  //greedy merge
  i=0;
  while (i < (int)zones.size()){
    region curRegion = zones[i];
    ++i;
    int onesBtwn = zones[i].l - curRegion.r - 1;
    while (i<(int)zones.size() && onesBtwn < zones[i].zeros && onesBtwn < curRegion.zeros){
      curRegion.zeros += zones[i].zeros - onesBtwn;
      curRegion.r = zones[i].r;
      ++i;
      if (i<(int)zones.size())
        onesBtwn = zones[i].l - curRegion.r - 1;
    }
    mergedZones.push_back(curRegion);
  }


  /*
  //of each mutually exclusive zone, select the max one
  int max=-1;
  std::pair<int,int> ret;
  for (region r : mergedZones){
    if (r.zeros > max){
      max = r.zeros;
      ret.first = r.l;
      ret.second = r.r;
    }
  }*/

  int max=-1;
  std::pair<int,int> ret;
  region c;
  //consider all n*(n+1)/2 partitions of super-regions for picking a max
  for (int chunksize=1; chunksize <= (int)mergedZones.size(); ++chunksize){
    for (int i=0; i<=(int)mergedZones.size()-chunksize; ++i){
      c = mergedZones[i];
      for ( int j=1; j<chunksize; ++j){
        c.zeros += mergedZones[i+j].zeros - (mergedZones[i+j].l - c.r - 1);
        c.r = mergedZones[i+j].r;
      }
      if (c.zeros > max){
        max = c.zeros;
        ret.first  = c.l;
        ret.second = c.r;
      }
    }
  }
  return ret;
}

int main(){
  int n;
  std::scanf("%i", &n);
  bool ones[n];
  std::fill(ones,ones+n,false);
  for (int i=0; i<n; ++i)
    std::cin >> ones[i];

  std::pair<int,int> r = getmaxrng(ones,n);
  //std::cout << "Max l: " << r.first << "  Max r: " << r.second << "\n"; //debug
  //perform transformation
  while (r.first <= r.second){
    ones[r.first] = !ones[r.first];
    ++r.first;
  }

  int onz=0;
  //get number of ones
  for (int i=0; i<n; ++i){
    onz += ones[i];
    //std::cout << ones[i] << " ";  //debug
  }
  std::cout << onz;
}
