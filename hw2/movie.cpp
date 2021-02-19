#include "movie.h"
#include "util.h"


Movie::Movie(const std::string category, const std::string name, double price, int qty, 
const std::string genre, const std::string rating)
 : Product(category, name, price, qty){
     genre_ = genre;
     rating_ = rating;
}

Movie::~Movie(){}

std::set<std::string> Movie::keywords() const{
     std::set<std::string> ans = parseStringToWords(convToLower(name_));
     ans.insert(convToLower(genre_)); ans.insert(convToLower(rating_));
     return ans;
}

std::string Movie::displayString() const{
    std::string ans;
    ans += (name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n");
    ans += (std::to_string(price_) + " " + std::to_string(qty_) + " left.");
    return ans;
}

void Movie::dump(std::ostream& os) const{
    os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl;
    os << genre_ << std::endl << rating_ << std::endl;
}