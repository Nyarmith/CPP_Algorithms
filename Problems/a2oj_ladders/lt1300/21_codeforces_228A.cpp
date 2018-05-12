#include <cstdio>
#include <cstdint>
#include <map>

std::map<uint32_t,int> hs;

int main(){
  std::uint32_t s1,s2,s3,s4;
  std::scanf("%u %u %u %u",&s1,&s2,&s3,&s4);
  ++hs[s1];
  ++hs[s2];
  ++hs[s3];
  ++hs[s4];
  int newsh=0;
  for (auto it=hs.begin(); it!=hs.end(); ++it){
    if (it->second > 1){
      newsh += it->second-1;
    }
  }
  std::printf("%i",newsh);
}
