#include "12.30.h"


TextQuery::TextQuery(std::ifstream &ifs):mp_text(new std::vector<std::string>) {
    std::string line;
    line_no lno = 0;

    while (std::getline(ifs, line)) {
        mp_text->push_back(line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            std::shared_ptr<std::set<line_no>> &lines = m_word2line_nos[word];
            if (!lines) 
                lines.reset(new std::set<line_no>);
            lines->insert(lno);
        }
        ++lno;
    }
}


QueryResult TextQuery::query(std::string &word) {
    static std::shared_ptr<std::set<line_no>> lnos(new std::set<line_no>);

    if (m_word2line_nos.end() != m_word2line_nos.find(word)) {
        return QueryResult(word, m_word2line_nos[word], mp_text);
    }else{
        return QueryResult(word, lnos, mp_text);
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