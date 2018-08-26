#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#define ll long long



//there will be at most 48/3=16 groups
std::vector< std::vector<ll> > Groups(16,std::vector<ll>());
ll Members[49];
int main(){
  ll n,m,a,b;
  std::cin >> n >> m;
  ll cur_group=1;
  for (int i=0; i<m; ++i){
    std::cin >> a >> b;

    //same group already?
    if (Members[a] != 0 && Members[a] == Members[b])
       continue;

    //are these both already part of a different group?
    if (Members[a] != 0 && Members[b] != 0 && Members[a] != Members[b]){
      std::cout << "-1\n"; return 0;
    }

    //ok, are either of these in a group already?
    if (Members[a] != 0 || Members[b] != 0){
        ll groupno = std::max(Members[a],Members[b]);
        if (Members[a] != groupno){
          Members[a] = groupno;
          Groups[groupno-1].push_back(a);
        } else {
          Members[b] = groupno;
          Groups[groupno-1].push_back(b);
        }
        if (Groups[groupno-1].size() > 3){
          std::cout << "-1\n"; return 0;
        }
    } else {
      if (cur_group > n/3){
        std::cout << "-1\n";
        return 0;
      }
      Groups[cur_group-1] = {a,b};
      Members[a] = cur_group;
      Members[b] = cur_group;
      ++cur_group;
    }
  }
  auto firstOpenGroup = std::find_if(Groups.begin(),Groups.end(), [](auto it){return it.size()<3;});
  //resolve rest of preferences
  for (int i=0; i<n; ++i){
    //have I not been assigned a group yet?
    if (Members[i+1] == 0){
      firstOpenGroup->push_back(i+1);
      while(firstOpenGroup->size() >= 3)
        ++firstOpenGroup;
    }
  }

  for (int i=0; i<n/3; ++i){
    for (int j=0; j<3; ++j){
      std::cout << Groups[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
