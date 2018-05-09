#include <cstdio>
#include <cstdint>

uint32_t days[7];

int main(){
  int n;
  int pagesPerWeek=0;
  std::scanf("%i", &n);

  for(int i=0; i<7; ++i){
    std::scanf("%u", days+i);
    pagesPerWeek+=days[i];
  }


  //skip to the last week
  int day=7;
  int pagesLeft = n % pagesPerWeek;
  if (pagesLeft == 0){
    //find last day with a number
    for (int i=6; i>=0; --i){
      if (days[i] > 0){
        printf("%i", (i+1));
        return 0;
      }
    }
  }

  while (pagesLeft > 0){
    day = day%7;
    pagesLeft -= days[day];
    ++day;
  }

  printf("%i",day);
}
