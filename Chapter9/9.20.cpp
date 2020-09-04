#include <iostream>
#include <list>
#include <deque>
using namespace std;

template<typename T>
    void print(const T &container){
        for (typename T::const_iterator citer = container.cbegin(); citer != container.cend(); ++citer){
            cout << *citer << " ";
        }
        cout << endl;
    }


int main(){
    list<int> numbers;
    deque<int> odd_numbers;
    deque<int> even_numbers;
    
    for (int i = 0; i < 10; ++i){
        numbers.push_back(i);
    }    

    for (list<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter){
        if (*iter%2 == 0){
            even_numbers.push_back(*iter);
        }
        else{
            odd_numbers.push_back(*iter);
        }
    }

    print(numbers);
    print(even_numbers);
    print(odd_numbers);

    return 0;
}