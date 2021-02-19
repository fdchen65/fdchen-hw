#ifndef BOOK_H
#define BOOK_H
#include "product.h"
class Book : public Product{
public:
    Book(const std::string category, const std::string name, double price, int qty,
     const std::string isbn, const std::string author);

    ~Book();

    /**
     * Returns tags this product should be associated with
     * */
    std::set<std::string> keywords() const;

    /**
     * Returns a string that describes this product
     * */
    std::string displayString() const;

    /**
     * outputs the databse format of the product info
     * */
    virtual void dump(std::ostream& os) const;

protected:
    std::string isbn_;
    std::string author_;
};
#endif