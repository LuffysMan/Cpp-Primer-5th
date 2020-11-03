#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <memory>


using line_no = std::vector<std::string>::size_type;

class QueryResult;
class TextQuery {
public:

    TextQuery(std::ifstream &ifs);
    QueryResult query(std::string &word);

private:
    std::shared_ptr<std::vector<std::string>> mp_text;
    std::unordered_map<std::string, std::shared_ptr<std::set<line_no>>> m_word2line_nos;
};


class QueryResult {
friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:

    QueryResult(std::string s, 
                std::shared_ptr<std::set<line_no>> lnos,
                std::shared_ptr<std::vector<std::string>> p_text):
    m_target(s), mp_line_nos(lnos), mp_text(p_text) { }
    std::set<line_no>::iterator begin() { return mp_line_nos->begin(); }
    std::set<line_no>::iterator end() { return mp_line_nos->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return mp_text; }

private:
    std::string m_target;
    std::shared_ptr<std::set<line_no>> mp_line_nos;
    std::shared_ptr<std::vector<std::string>> mp_text;
};

