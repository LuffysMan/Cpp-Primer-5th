#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <memory>

#include "12.22.h"


using line_no = std::vector<std::string>::size_type;

class QueryResult;
class TextQuery {
public:

    TextQuery(std::ifstream &ifs);
    QueryResult query(const std::string &word) const;

private:
    StrBlob mp_text;
    std::unordered_map<std::string, std::shared_ptr<std::set<line_no>>> m_word2line_nos;
};


class QueryResult {
friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:

    QueryResult(std::string s, 
                std::shared_ptr<std::set<line_no>> p,
                StrBlob f):
    m_target(s), mp_line_nos(p), mp_text(f) { }

private:
    std::string m_target;
    std::shared_ptr<std::set<line_no>> mp_line_nos;
    StrBlob mp_text;
};



