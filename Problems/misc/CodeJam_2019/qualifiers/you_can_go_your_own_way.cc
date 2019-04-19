#include <iostream>
#include <string>
#include <cstdint>

int main()
{
    size_t T, len;
    std::string lydiaPath, ourPath;
    
    std::cin >> T;
    for (size_t t = 0; t < T; ++t)
    {
        ourPath = "";
        lydiaPath = "";
        std::cin >> len;
        std::cin >> lydiaPath;
        for (const char &t : lydiaPath)
            ourPath += (t == 'S' ? 'E' : 'S');
        std::cout << "Case #" << (t+1) << ": "
            << ourPath << "\n";
    }
}
