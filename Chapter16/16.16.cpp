#include "16.16.h"


StrVec::StrVec(const StrVec &s) {
    std::pair<std::string*, std::string*> newData = alloc_n_copy(s.elements, s.first_free);
    elements = newData.first;
    first_free = newData.second;
    cap = newData.second;
}