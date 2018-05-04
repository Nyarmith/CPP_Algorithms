#include <cstdio>
#include <cstdint>

char chessArr[101][101];
uint32_t n, m;

void populateSegment(int row, int col, bool white=false){  //dflt color is black
  if (row < 0 || row >= n || col < 0 || col >= m || chessArr[row][col] != '.')
    return;

  chessArr[row][col] = white ? 'W' : 'B';

  populateSegment(row-1,col  , !white);
  populateSegment(row  ,col-1, !white);
  populateSegment(row+1,col  , !white);
  populateSegment(row  ,col+1, !white);
}

int main(){
  std::scanf("%u %u", &n, &m);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%s", chessArr[i]);
  }

  for (uint32_t r=0; r<n; ++r){
    for (uint32_t c=0; c<m; ++c){
      if (chessArr[r][c] == '.')
        populateSegment(r,c);
    }
  }

  for (uint32_t i=0; i<n; ++i){
    std::printf("%s\n",chessArr[i]);
  }
}
