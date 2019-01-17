#include <iostream>


//lazy shit version
int main()
{
  using ull=unsigned long long;
  for (int a=1; a<(1000-3); ++a)
  {
    for (int b=a+1; b<(1000-2); ++b)
    {
      int c = 1000 - a - b;
      if (c > b && b > a && a*a + b*b == c*c)
        std::cout << c*b*a << std::endl;
    }
  }
}
