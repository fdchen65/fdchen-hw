#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <deque>
#include <map>

class myDataStore : public DataStore{
public:
    myDataStore();

    ~myDataStore();

    virtual void addUser(User *u);

    virtual void addProduct(Product *p);

    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);

    virtual void dump(std::ostream& ofile);

    bool addToCart(std::string usrname, Product* p);

    bool viewCart(std::string username);

    bool buyCart(std::string username);

private:
    User* findUser(std::string username);
    
    std::set<User*> uList;
    std::set<Product*> pList;
    std::map<std::string, std::set<Product*>> words;
    std::map<std::string, std::deque<Product*>> carts; 
};

#endif