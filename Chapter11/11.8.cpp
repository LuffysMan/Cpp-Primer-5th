#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>


int main(){
// 使用vector保存不重复的元素有以下两个问题: 1.如果一直保持vector有序, 则查找效率高, 但是插入效率低; 2.如果不要求有序, 则插入效率高, 但查找效率低 
#if 0
    std::vector<std::string> unique_words;
    std::string word;
    while (std::cin >> word){
        if (std::find(unique_words.cbegin(), unique_words.cend(), word) == unique_words.cend()){
            unique_words.push_back(word);
        }
    }

    for(std::string word: unique_words){
        std::cout << word << std::endl;
    }
#endif

//使用set可以使得插入新元素时查找效率和插入效率均比较高, 均为O(log(n)), 因为底层是红黑树实现的;
#if 1
    std::set<std::string> unique_words;
    std::string word;
    while (std::cin >> word){
        unique_words.insert(word);
    }

    for(auto word: unique_words){
        std::cout << word << std::endl;
    }

#endif
    return 0;
}