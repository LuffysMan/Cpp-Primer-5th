#include "12.33.h"


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


std::ostream& print(std::ostream &os, const QueryResult &qr) {
    os << qr.m_target << " occurs " << qr.mp_line_nos->size() << " time(s)";

    for (line_no lno: *(qr.mp_line_nos)) {
        os << "\n" << "(line " << lno+1 << " ) " << *(qr.mp_text->begin()+lno);
    }
    return os;
}