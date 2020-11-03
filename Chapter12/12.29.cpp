#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>


typedef unsigned int line_no;


void query(std::string file) {
    std::ifstream ifs(file);
    std::vector<std::string> m_text;
    std::unordered_map<std::string, std::set<line_no>> m_word2line_nos;

    std::string line;
    line_no lno = 0;
    while (std::getline(ifs, line)) {
        m_text.push_back(line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            m_word2line_nos[word].insert(lno);
        }
        ++lno;
    }

    std::string target;
    std::string confirm;
    //使用do while方便给予用户提示， 对用户比较友好。
    do {
        std::cout << "Please enter the word you want to check" << std::endl;
        std::cin >> target;
        auto p_lnos = m_word2line_nos.find(target);
        std::cout << target << " occurs " << (p_lnos != m_word2line_nos.end() ? p_lnos->second.size() : 0) << " time(s)";
        if (p_lnos != m_word2line_nos.end()) {
            for (line_no lno: p_lnos->second) {
                std::cout << "\n" << "(line " << lno+1 << " ) " << m_text[lno];
            }
        }

        std::cout << "Go on or quit? Please enter yes or no" << std::endl;
        std::cin >> confirm;

    }while(!confirm.empty() && confirm[0] != 'n');

}


int main() {
    query("12.27.txt");
    return 0;
}