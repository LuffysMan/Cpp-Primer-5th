#include <vector>
#include <list>
#include <map>


int main(){
    std::vector<int> vec = {1,2,3,4,5};
    std::list<int> lst = {1,2,3,4,5};

    // vector<int>::iterator类型实现了 < 操作符的重载, 所以可以作为map的关键字
    std::map<std::vector<int>::iterator, int> veciter_to_int;
    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter){
        veciter_to_int.insert(std::pair<std::vector<int>::iterator, int>(iter, *iter));
    }

    // list<int>::iterator类型没有实现 < 操作符重载, 所以不可以作为map的关键字
    std::map<std::list<int>::iterator, int> lstiter_to_int;
    for (std::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter){
        lstiter_to_int.insert(std::pair<std::list<int>::iterator, int>(iter, *iter));
    }

    return 0;
}