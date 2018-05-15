#include <cstdio>
#include <cstdint>

int sarr[5][5] = {
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0}
};

//I can just brute-force this?
int computeHappiness(int a, int b, int c, int d, int e){
  return (sarr[a][b] + sarr[b][a] + sarr[c][d] + sarr[d][c]) + (sarr[b][c] + sarr[c][b] + sarr[d][e] + sarr[e][d]) + (sarr[c][d] + sarr[d][c]) + (sarr[d][e] + sarr[e][d]);

}

//Strategy: find the most powerful pairs
//Other Strat: find most powerful sets of pairs(where the pairs are disjoint), then maximize the largest pair by being the last 2
//-> or make a function to evaluate the eqn then do all 5! orderings with it
int main(){
  for (int i=0; i<5; ++i){
    for (int j=0; j<5; ++j){
      std::scanf("%i", sarr[i]+j);
    }
  }

  int maxHap=-999999;
  for (int a=1; a<=5; ++a){
    for (int b=1; b<=5; ++b){
      for (int c=1; c<=5; ++c){
        for (int d=1; d<=5;++d){
          for (int e=1; e<=5;++e){
            if (b!=a&&c!=b&&c!=a&&d!=a&&d!=b&&d!=c&&e!=a&&e!=b&&e!=c&&e!=d){
            int v = computeHappiness(a-1,b-1,c-1,d-1,e-1);
            if (v>maxHap)
              maxHap=v;
            }
          }
        }
      }
    }
  }
  std::printf("%i", maxHap);
}
