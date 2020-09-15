#include <iostream>
#include <fstream>
#include <iterator>


int main(){
    std::ifstream is("./10.33.input.txt");
    std::istream_iterator<int> in_iter(is), eof;

    std::ofstream odd_os("./10.33.odd.txt");
    std::ostream_iterator<int> odd_out_iter(odd_os, " ");
    std::ofstream even_os("./10.33.even.txt");
    std::ostream_iterator<int> even_out_iter(even_os, "\n");
    
    while (in_iter != eof){
        std::cout << *in_iter << std::endl;
        *in_iter%2 == 0 ? even_out_iter = *in_iter++ : odd_out_iter = *in_iter++;
    }

    odd_os.close();
    even_os.close();
    return 0;
}