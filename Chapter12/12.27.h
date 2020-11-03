#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>


class QueryResult;
class TextQuery {
public:
    typedef unsigned int line_no;

    TextQuery(std::ifstream &ifs);
    QueryResult query(std::string &word);

private:
    std::vector<std::string> m_text;
    std::unordered_map<std::string, std::set<line_no>> m_word2line_nos;
};


class QueryResult {
public:
    typedef unsigned int line_no;
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);

    QueryResult(std::string &s, std::set<line_no> &lnos, std::vector<std::string> &text):
    m_target(s), m_line_nos(lnos), m_text(text) { }

private:
    std::string m_target;
    std::set<line_no> m_line_nos;
    std::vector<std::string> m_text;
};


std::ostream& print(std::ostream &os, const QueryResult &qr) {
    os << qr.m_target << " occurs " << qr.m_line_nos.size() << " time(s)";

    for (QueryResult::line_no lno: qr.m_line_nos) {
        os << "\n" << "(line " << lno+1 << " ) " << qr.m_text[lno];
    }
    return os;
}
