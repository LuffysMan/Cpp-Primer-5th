#include "16.4.h"


int main() {
    std::vector<int> v = {1,2,3};
    std::list<std::string> lst = {"hello", "cook", "book"};
    
    int n_target = 0;

    if (std::cin >> n_target) {
        std::vector<int>::iterator loc1 = myfind(v.begin(), v.end(), n_target);
        std::cout << n_target << " " <<  (loc1 != v.end() ? "found" : "not found") << std::endl;
    }
    
    std::string s_target;
    if (std::cin >> s_target) {
        std::list<std::string>::iterator loc2 =myfind(lst.begin(), lst.end(), s_target);
        std::cout << s_target << " " << (loc2 != lst.end() ? "found" : "not found") << std::endl;
    }
}