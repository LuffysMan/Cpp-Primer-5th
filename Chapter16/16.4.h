#include <iostream>

#include <algorithm>
#include <vector>
#include <list>
#include <string>


template <typename A, typename B>
A myfind(const A& begin, const A& end, const B& t) {
    A curr = begin;
    while (curr != end) {
        if (*curr == t) 
            break;
        ++curr;
    }
    return curr;
}

