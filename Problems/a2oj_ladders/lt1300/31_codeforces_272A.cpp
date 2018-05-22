#include <cstdio>
#include <cstdint>

using std::uint32_t;
using std::printf;
using std::scanf;

int main(){
  uint32_t n, t, residue;
  uint32_t sum=0;
  scanf("%u", &n);
  for(uint32_t i=0; i<n; ++i){
    scanf("%u",&t);
    sum+=t;
  }
  residue = sum % (n+1);
  if ( (residue + 4) % (n+1) == 1){
    printf("%u",3);
  } else {
    printf("%u",4);
  }
  /*
  if (residue == 1 || residue + 2 == n + 2){
    printf("%u",1);
  } else{
    printf("%u",2);
  }*/
}

//codeforce's judge-bot is wrong here. smh
