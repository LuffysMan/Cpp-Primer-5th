#ifndef s16_62_h
#define s16_62_h

#include <functional>
#include <iostream>
#include <string>


// template <class T> class std::hash;
struct Sales_data{
    friend class std::hash<Sales_data>;

    Sales_data() = default;
    Sales_data(const std::string& s):bookNo(s){}
    Sales_data(const std::string& s, unsigned int n, double p):bookNo(s), units_sold(n), revenue(n*p){}
    Sales_data(std::istream&);

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    bool operator==(const Sales_data& rhs) const {
        return bookNo == rhs.bookNo && units_sold == rhs.units_sold && revenue == rhs.revenue;
    }
    
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};


std::istream& read(std::istream &is, Sales_data &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price*item.units_sold;
    return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


Sales_data::Sales_data(std::istream& is){
    read(is, *this);
}

double Sales_data::avg_price() const{
    if (units_sold){
        return revenue/units_sold;
    }else{
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


namespace std {
    template <>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator() (const Sales_data& s) const;
    };

    size_t hash<Sales_data>::operator() (const Sales_data& s) const {
        return std::hash<std::string>()(s.bookNo) ^ std::hash<unsigned>()(s.units_sold) ^ std::hash<double>()(s.revenue);
    }
};

#endif