#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <ios>
#include <limits>
#include <set>
#include <map>

int adjMat[200][200];

bool overlap(std::set<int>& s1, std::set<int>& s2) {
  auto first1 = s1.begin(), last1 = s1.end();
  auto first2 = s2.begin(), last2 = s2.end();
  while (first1 != last1 && first2 != last2) {
    if (*first1 < *first2)
      ++first1;
    else if (*first2 < *first1)
      ++first2;
    else
      return true;
  }
  return false;
}

void exploreConnected(std::map<int,std::set<int>> p, int k, bool *t, int n){
  t[k] = true;
  for (int i=0; i<n; ++i){
    if (!t[i] && overlap(p[k],p[i])){
      exploreConnected(p,i,t,n);
    }
  }
}

int main(){
  int n,m;
  std::cin >> n >> m;
  bool explored[n];
  int learn=0;
  int i=0;
  bool allZeros=true;
  std::fill(explored, explored+n, false);
  std::map<int,std::set<int>> people;

  for (int i=0; i<n; ++i){
    int langs,tmp;
    std::cin >> langs;
    if (langs == 0){
      ++learn;
      explored[i] = true;
    }
    for (int j=0; j<langs; ++j){
      std::cin >> tmp;
      people[i].insert(tmp);
      allZeros=false;
    }
  }

  int newLangs = -1;
  while (i<n){
    if (!explored[i]){
      exploreConnected(people,i,explored,n);
      ++newLangs;
    }
    ++i;
  }
  newLangs = std::max(newLangs,0);
  learn += newLangs;

  std::cout << learn;
}
