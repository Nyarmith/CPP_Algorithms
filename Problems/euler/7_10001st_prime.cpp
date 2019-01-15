#include <iostream>
#include <vector>

std::vector<bool> isPrime(1000000,true);
std::vector<int> primes;

int main()
{
  int i=2;
  while (i < isPrime.size())
  {
    if (isPrime[i])
    {
      primes.push_back(i);
      for (int j=i*2; j < isPrime.size(); j+=i)
        isPrime[j] = false;
    }
    ++i;
  }
  std::cout << primes[10000] << std::endl;
}
