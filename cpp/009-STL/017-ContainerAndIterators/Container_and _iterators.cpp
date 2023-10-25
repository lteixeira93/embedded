#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main(void)
{
    std::vector<int> v {0,1,2};
    std::map<int, std::string> m {{ 0, "0" }, { 1, "1" }, { 2, "2" }};

    std::vector<int>::iterator vit = v.begin();
    // OR auto vit = v.begin();
    while (vit != v.end())
    {
        std::cout << *vit << std::endl;
        vit++;
    }

    auto mit = m.begin();
    while (mit != m.end())
    {
        std::cout << mit->first << ":" << mit->second << std::endl;
        mit++;
    }
    
    auto loc = std::find(v.begin(), v.end(), 1);

    if(loc != v.end()) std::cout << *loc << std::endl;
    return 0;
}
