#include "book.h"
#include "util.h"


Book::Book(const std::string category, const std::string name, double price, int qty, 
const std::string isbn, const std::string author)
 : Product(category, name, price, qty){
     isbn_ = isbn;
     author_ = author;
}

Book::~Book(){}

std::set<std::string> Book::keywords() const{
     std::set<std::string> ans = parseStringToWords(convToLower(name_));
     ans.insert(convToLower(isbn_)); ans.insert(convToLower(author_));
     return ans;
}

std::string Book::displayString() const{
    std::string ans;
    ans += (name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n");
    ans += (std::to_string(price_) + " " + std::to_string(qty_) + " left.");
    return ans;
}

void Book::dump(std::ostream& os) const{
    os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl;
    os << isbn_ << std::endl << author_ << std::endl;
}

