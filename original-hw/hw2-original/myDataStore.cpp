#include "myDataStore.h"
#include "util.h"
#include <deque>
#include <stack>

myDataStore::myDataStore(){
}

myDataStore::~myDataStore(){
    //free uList
    std::set<User*>::iterator it1 = uList.begin();
    while(it1!= uList.end()){
        std::set<User*>::iterator temp = it1++;
        delete *temp;
    }
    //free pList
    std::set<Product*>::iterator it2 = pList.begin();
    while(it2!= pList.end()){
        std::set<Product*>::iterator temp = it2++;
        delete *temp;
    }
}

void myDataStore::addUser(User *u){
    uList.insert(u);
    //adding empty shopping cart
    std::deque<Product*> empty;
    std::pair<std::string, std::deque<Product*>> p;
    p = std::make_pair(u->getName(), empty);
    carts.insert(p);
}

void myDataStore::addProduct(Product *p){
    pList.insert(p);
    //adds it to the words map
    std::set<std::string> temp = p->keywords();
    for(std::set<std::string>::iterator it = temp.begin() ; it != temp.end() ; it++){
        //if doesn't already have this entry, create it
        if(words.find(*it) == words.end()){
            words[*it] = {};
        }
        words[*it].insert(p);
    }
}

/**
 * type: 0 = AND
 * type: 1  = Or
 * */

std::vector<Product*> myDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> ans;
    //AND
    if(type == 0){
        std::stack<std::set<Product*>> all;
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); it++){
            if(words.find(*it) != words.end()){
                all.push(words[*it]);
            } else{
                all.push({});
            }
        }
        std::set<Product*> temp = {};
        if(all.size() > 0){temp = all.top();}
        while(all.size() > 0){
            temp = setIntersection<Product*>(temp, all.top());
            all.pop();
        }
        std::vector<Product*> ans = std::vector<Product*>(temp.begin(), temp.end());
        return ans;
    }
    //OR
     else if(type ==1){
        std::stack<std::set<Product*>> all;
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); it++){
            if(words.find(*it) != words.end()){
                all.push(words[*it]);
            }
        }
        std::set<Product*> temp = {};
        while(all.size() > 0){
            temp = setUnion<Product*>(temp, all.top());
            all.pop();
        }
        std::vector<Product*> ans = std::vector<Product*>(temp.begin(), temp.end());
        return ans;

    }
    return ans;
}

void myDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << std::endl;
    for(std::set<Product*>::iterator it = pList.begin() ; it != pList.end() ; it++){
        (*it)->dump(ofile);
        std::set<Product*>::iterator temp = it;
        temp++;
        if(temp != pList.end()){
            ofile << std::endl;
        }
    }
    ofile << std::endl << "</products>" << std::endl;
    ofile << "<users>" << std::endl;
    for(std::set<User*>::iterator it = uList.begin() ; it != uList.end() ; it++){
        (*it)->dump(ofile);
    }
    ofile << "</users>";
}

/**
 * This adds products to the user's shopping carts
 * returns true if added successfuly
 * returns false if error occurs (no such user, no such product)
 * */
bool myDataStore::addToCart(std::string usrname, Product* p){
    User* u = findUser(usrname);
    if(uList.find(u) != uList.end() && pList.find(p) != pList.end()){
        carts[u->getName()].push_back(p);
        return true;
    } else {
        return false;
    }
}

/**
 * This views a user's cart
 * returns true if viewed successfully
 * returns false if username incorrect
 * */

bool myDataStore::viewCart(std::string username){
    User* u = findUser(username);
    if(u != NULL){
        int counter = 1;
        for(std::deque<Product*>::iterator it = carts[username].begin() ;
         it != carts[username].end() ; it++){
             std::cout << "Item " << counter << std::endl;
             counter++;
             std::cout << (*it)->displayString() << std::endl << std::endl;
         }
         return true;
    }
    return false;
}

/**
 * This buys the content of a user's cart
 * returns true if no username error
 * returns false if there error
 * */
bool myDataStore::buyCart(std::string username){
    User* u = findUser(username);
    if(u != NULL){
        std::deque<Product*> leftover = {};
        for(std::deque<Product*>::iterator it = carts[username].begin(); it != carts[username].end() ; it++){
            if((*it)->getQty() > 0 && u->getBalance() >= (*it)->getPrice()){
                u->deductAmount((*it)->getPrice());
                (*it)->subtractQty(1);
            } else {
                leftover.push_back(*it);
            }
        }
        carts[username] = leftover;
        return true;
    } else {
        return false;
    }

}



/**
 * helper 
 * finds user by name and returns the pointer
 * if can't find user, returns NULL
 * */
User* myDataStore::findUser(std::string username){
    for(std::set<User*>::iterator it = uList.begin() ; it != uList.end() ; it++){
        if((*it)->getName() == username){
            return *it;
        }
    }
    return NULL;
}
