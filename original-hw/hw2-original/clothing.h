#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing: public Product{
public:
    Clothing(const std::string category, const std::string name, double price, int qty,
     const std::string size,const std::string brand);

    ~Clothing();

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
    std::string size_;
    std::string brand_;
};

#endif