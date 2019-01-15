#include <iostream>

int main()
{
  using ull = unsigned long long;
  ull ret=0;
  for (int i=1; i<=100; ++i)
  {
    for (int j=1; j<=100; ++j)
    {
      if (i!=j)
        ret += i*j;
    }
  }
  std::cout << ret;
}
