#include <iostream>
#include <set>
#include <stack>
using namespace std;


// string next_element(const string &str, string::size_type &pos){
//     string snumbers = "0123456789";
//     string symbols = "+-*/";

//     if (symbols.find_first_of(str[pos]) != string::npos){
//         string symbol;
//         symbol.push_back(str[pos++]);
//         return symbol;
//     }else{
//         string::size_type begin = pos;
//         while (pos < str.size() && symbols.find_first_of(str[pos]) != string::npos){
//             ++pos;
//         }
//         return str.substr(begin, pos-begin);
//     }
// }


double eval(const string &exp_str, string::size_type &pos){
    stack<double> num_stk;
    
    while (pos < exp_str.size()){
        char sym = exp_str[pos];
        double num = 0;
        if (sym == '('){
            num = eval(exp_str, ++pos);
            num_stk.push(num);
        }else if (sym == ')'){
            pos++;
            break;
        }else if (sym == '*' || sym == '/'){
            string sub_str = exp_str.substr(++pos);
            string::size_type offset = 0;
            num = stod(sub_str, &offset);
            num = sym == '*' ? num_stk.top() * num : num_stk.top() / num;
            num_stk.pop();
            num_stk.push(num);
            pos += offset;
        }else if(sym == '+' || sym == '-'){
            if (exp_str[pos+1] == '('){
                pos += 2;
                num = eval(exp_str, pos);
                sym == '+' ? num_stk.push(num) : num_stk.push(-num);
            }else{
                string sub_str = exp_str.substr(pos);
                string::size_type offset = 0;
                num = stod(sub_str, &offset);
                num_stk.push(num);
                pos += offset;
            }
        }else{
            string sub_str = exp_str.substr(pos);
            string::size_type offset = 0;
            num = stod(sub_str, &offset);
            num_stk.push(num);
            pos += offset;
        }
    }

    double ret = 0;
    while (!num_stk.empty()){
        ret += num_stk.top();
        num_stk.pop();
    }

    return ret;
}


int main(){
    string expression_str;
    cin >> expression_str;

    string::size_type pos = 0;
    cout << eval(expression_str, pos) << endl;

    return 0;
}