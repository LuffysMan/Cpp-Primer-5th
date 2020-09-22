#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


int main(){
//第一种情况是合法的, inserter调用multiset的insert方法, 将元素按字典序插入multiset
#if 0     
    std::cout << " " << std::endl;
    std::vector<std::string> v = {"the", "fox", "deceit", "the", "crowl", "into", "singing"};
    std::multiset<std::string> c;

    std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
    std::copy(c.begin(), c.end(), std::ostream_iterator<std::string>(std::cout, " "));
#endif

//第二种情况是不合法的, back_inserter要求作为其参数的容器实现了push_back方法, multiset没有此方法;
#if 0
    std::cout << " " << std::endl;
    std::vector<std::string> v = {"the", "fox", "deceit", "the", "crowl", "into", "singing"};
    std::multiset<std::string> c;

    std::copy(v.begin(), v.end(), std::back_inserter(c));
    std::copy(c.begin(), c.end(), std::ostream_iterator<std::string>(std::cout, " "));
#endif

//第三种和第四种情况都合法, vector适用于insert和back_inserter.
#if 1
    std::cout << " " << std::endl;
    std::multiset<std::string> c = {"the", "fox", "deceit", "the", "crowl", "into", "singing"};
    std::vector<std::string> v;

    std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
    // std::copy(c.begin(), c.end(), std::back_inserter(v));
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));
#endif
    return 0;
}