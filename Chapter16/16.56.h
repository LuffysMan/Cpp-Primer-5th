#include "16.48.h"
#include "16.53.h"


template <typename...Args>
std::ostream& errorMsg(std::ostream& os, const Args&... rest) {
    return print(os, debug_rep(rest)...);
}