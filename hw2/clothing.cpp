#include "clothing.h"
#include "util.h"


Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
const std::string size, const std::string brand)
 : Product(category, name, price, qty){
     size_ = size;
     brand_ = brand;
}

Clothing::~Clothing(){}

std::set<std::string> Clothing::keywords() const{
     std::set<std::string> ans = parseStringToWords(convToLower(name_));
     ans.insert(convToLower(brand_)); ans.insert(convToLower(size_));
     return ans;
}

std::string Clothing::displayString() const{
    std::string ans;
    ans += (name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n");
    ans += (std::to_string(price_) + " " + std::to_string(qty_) + " left.");
    return ans;
}

void Clothing::dump(std::ostream& os) const{
    os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl;
    os << size_ << std::endl << brand_ << std::endl;
}