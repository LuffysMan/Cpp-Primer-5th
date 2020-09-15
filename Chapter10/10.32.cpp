#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "../Chapter1/Sales_item.h"


int main(){
    std::istream_iterator<Sales_item> in_iter(std::cin), eof;
    std::vector<Sales_item> transVec(in_iter, eof);

    std::sort(transVec.begin(), transVec.end(), compareIsbn);

    for_each(transVec.cbegin(), transVec.cend(), [](const Sales_item &item){std::cout << item << std::endl;});

    std::vector<Sales_item>::iterator begin = transVec.begin(), end = begin;

    while (begin != transVec.end()){
        end = std::find_if(begin, transVec.end(), [begin](const Sales_item &item){return begin->isbn() != item.isbn();});
        std::cout << std::accumulate(begin, end, Sales_item(begin->isbn())) << std::endl;
        begin = end;
    }

    return 0;
}