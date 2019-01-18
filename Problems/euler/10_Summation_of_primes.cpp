#include <iostream>
#include <vector>

const size_t primeSieveSize=2000001;

std::vector<bool> isPrime(primeSieveSize, true);

int main()
{
  for (size_t i=2; i<isPrime.size(); ++i)
  {
    if (isPrime[i])
      for (size_t j=i*2; j<isPrime.size(); j+=i)
        isPrime[j] = false;
  }
  unsigned long long sum=0;
  for (size_t i=2; i<2000000; ++i)
  {
    if (isPrime[i])
      sum += i;
  }
  std::cout << sum << std::endl;
}
