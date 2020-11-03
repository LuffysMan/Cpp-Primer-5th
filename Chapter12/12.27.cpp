#include "12.27.h"


TextQuery::TextQuery(std::ifstream &ifs) {
    std::string line;
    unsigned int lineno = 0;

    while (std::getline(ifs, line)) {
        m_text.push_back(line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            m_word2line_nos[word].insert(lineno);
        }
        ++lineno;
    }
}


QueryResult TextQuery::query(std::string &word) {
    static std::set<line_no> lnos;

    if (m_word2line_nos.end() != m_word2line_nos.find(word)) {
        return QueryResult(word, m_word2line_nos[word], m_text);
    }else{
        return QueryResult(word, lnos, m_text);
    }
}


void runQueries(std::ifstream &infile) {
    // infile 是一个ifstream， 指向我们要处理的文件
    TextQuery tq(infile);               //保存文件并建立查询map
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}


int main() {
    std::ifstream ifs("12.27.txt");
    runQueries(ifs);
    ifs.close();

    return 0;
}