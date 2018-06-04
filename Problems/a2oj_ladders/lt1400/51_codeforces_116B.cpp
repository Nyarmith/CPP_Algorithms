#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

char grid[10][10];

std::vector<std::pair<int,int>> getPigs(int n,int m){
  std::vector<std::pair<int,int>> ret;
  for (int i=0; i<n; ++i){
    for (int j=0; j<m; ++j){
      if (grid[i][j] == 'P')
        ret.push_back(std::make_pair(i,j));
    }
  }
  return ret;
}

std::vector<std::pair<int,int>> getAdjacentWolves(std::pair<int,int> p, int n, int m){
  std::vector<std::pair<int,int>> ret;
  int r=p.first;
  int c=p.second;
  if (r-1 >= 0 && grid[r-1][c] == 'W')
    ret.push_back(std::make_pair(r-1,c));
  if (r+1 < n  && grid[r+1][c] == 'W')
    ret.push_back(std::make_pair(r+1,c));
  if (c-1 >= 0 && grid[r][c-1] == 'W')
    ret.push_back(std::make_pair(r,c-1));
  if (c+1 < m  && grid[r][c+1] == 'W')
    ret.push_back(std::make_pair(r,c+1));
  return ret;
}

bool hasOtherAdjPigs(std::pair<int,int> w, std::pair<int,int> p, int n, int m){
  std::vector<std::pair<int,int>> ret;
  int r=w.first;
  int c=w.second;
  if (r-1 >= 0 && grid[r-1][c] == 'P')
    ret.push_back(std::make_pair(r-1,c));
  if (r+1 < n  && grid[r+1][c] == 'P')
    ret.push_back(std::make_pair(r+1,c));
  if (c-1 >= 0 && grid[r][c-1] == 'P')
    ret.push_back(std::make_pair(r,c-1));
  if (c+1 < m && grid[r][c+1] == 'P')
    ret.push_back(std::make_pair(r,c+1));

  auto it = std::find(ret.begin(),ret.end(), p);
  ret.erase(it);
  return (ret.size() > 0);
}

int main(){
  int n,m;
  std::cin >> n >> m;
  for (int i=0; i<n; ++i){
    for (int j=0; j<m; ++j){
      std::cin >> grid[i][j];
    }
  }
  //algorithm: for each pig, if there is only one adjacent wolf, consume the pig. If there are multiple adjacent wolves, look for a wolf with no other adjacent pig, if none exist, pick any(in this case, the first wolf)

  std::vector<std::pair<int,int>> pigs = getPigs(n,m);

  int consumed=0;
  for (auto p : pigs){
    std::vector<std::pair<int,int>> adjWolves = getAdjacentWolves(p, n, m);
    if (adjWolves.size() == 1){
      ++consumed;
      grid[p.first][p.second] = '.';
      grid[adjWolves[0].first][adjWolves[0].second] = '.';
    } else {
      for (auto w : adjWolves){
        if (!hasOtherAdjPigs(w,p,n,m)){
          ++consumed;
          grid[p.first][p.second] = '.';
          grid[w.first][w.second] = '.';
        }
        if (grid[p.first][p.second] == 'P'){ //not yet consumed
          ++consumed;
          grid[p.first][p.second] = '.';
          grid[adjWolves[0].first][adjWolves[0].second] = '.';
        }
      }
    }
  }

  std::cout<< consumed;
}
