#include <iostream>
#include <set>
#include <cstdint>
#include <vector>


bool isPrime[10001] = {};
std::vector<uint64_t> primes {};

void populatePrimes()
{
    int sz=10001;
    for (int i=0; i<sz; ++i)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    int i=2;
    while (i < sz)
    {
        if (isPrime[i])
        {
            for (int k=i*2; k<sz; k+=i)
                isPrime[k] = false;
        }
        ++i;
    }
    for (int i=2; i<sz; ++i)
        if (isPrime[i]) primes.push_back(i); 
}

int main()
{
    size_t T, N, size;
    populatePrimes();
    
    std::cin >> T;
    for (int i=0; i<T; ++i)
    {
        std::cin >> N >> size;
        
        std::vector<uint64_t> output;
        output.reserve(size + 1);
        
        uint64_t v;
        
        //get first primes
        std::cin >> v;
        
        int a,b;
        for (const auto &p : primes)
        {
            if (p > N)
            {
                std::cerr << "should never break\n";
                break;
            }
            if (v % p == 0)
            {
                std::cout << "v : " << v << " p : " << p << " b: " << b << "\n";
                a = p;
                b = v / p;
                break;
            }
        }
        
        // figure out which prime is "b"
        std::cin >> v;
        if (v % a == 0)
            output.push_back(a);
        else
            output.push_back(b);
        
        
        // continue as per normal
        for (int i=2; i<size; ++i)
        {
            std::cin >> v;
            output.push_back(v / *output.rbegin());
        }
        
        for (const auto &g : output)
            std::cout << g << " ";
/*
        //make letter map
        std::set<uint64_t> letterMap(output.begin(), output.end());
        char charMap[10001];
        char letter='a';
        for (const auto itr : letterMap)
        {
            charMap[itr] = letter;
            ++letter;
        }
        
        std::string outstr = "";
        outstr.reserve(size + 1);
        for (const auto& num : output)
        {
            outstr += charMap[num];
        }
        std::cout << "Case #" << i+1 << ": " << outstr << "\n";
*/
    }
}
