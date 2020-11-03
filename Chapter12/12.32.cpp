#include "12.32.h"


TextQuery::TextQuery(std::ifstream &ifs) {
    std::string line;
    line_no lno = 0;

    while (std::getline(ifs, line)) {
        mp_text.push_back(line);
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


QueryResult TextQuery::query(const std::string &word) const{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    auto loc = m_word2line_nos.find(word);
    if (m_word2line_nos.end() != loc) {
        return QueryResult(word, loc->second, mp_text);
    }else{
        return QueryResult(word, nodata, mp_text);
    }
}


std::ostream& print(std::ostream &os, const QueryResult &qr) {
    os << qr.m_target << " occurs " << qr.mp_line_nos->size() << " time(s)";

    ConstStrBlobPtr cptr(qr.mp_text);
    for (line_no lno: *(qr.mp_line_nos)) {
        os << "\n" << "(line " << lno+1 << " ) " << cptr.deref(lno);
        
    }

    return os;
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