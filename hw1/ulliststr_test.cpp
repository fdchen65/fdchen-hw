/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  // ULListStr dat;
  // dat.push_back("hello ");
  // dat.push_back("there ");
  // dat.push_back("my name is felix chen what's your name?");
  // cout << "printing out the entire linked list:" << endl;
  // for(unsigned int i = 0 ; i < dat.size() ; i++){
  //   cout << dat.get(i);
  // }
  // cout << endl;
  // cout << "should be h e l r:" << endl;
  // cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(9) << endl;
  // cout << "size of unrolled list: " << endl;
  // cout << dat.size() << endl;
  // dat.pop_front();
  // cout <<"TESTING POP_FRONT Should print out e: " << endl << dat.get(0) << endl;
  // dat.pop_back(); dat.pop_back();
  // cout << "TESTING POP_BACK Should printout m: " << endl << dat.get(dat.size()-1) << endl;
  // dat.push_back("blahblahblahblah");
  // cout << "should add blahblahblahblah at the end of the string: " << endl;
  // for(unsigned int i = 0 ; i < dat.size() ; i++){
  //   cout << dat.get(i);
  // }
  // cout << endl;
  // dat.push_front("uwuwuwuwuwuw");
  // cout << "should add uwuwuwuwuwuw in front of the string: " << endl;
  // for(unsigned int i = 0 ; i < dat.size() ; i++){
  //   cout << dat.get(i);
  // }
  // cout << endl;

  ULListStr dat;
  // -----------------
  // Testing push_back
  // -----------------
    // List is empty
    dat.push_back("1");
    cout << dat.get(0) << endl; // prints: 1

    // List has one or more value
    for (int i = 1; i <= 9; i++) {
      dat.push_back("2");
    }
    cout << dat.size() << endl; // prints: 10

    // No space in back of array, new Item created
    dat.push_back("3");
    cout << dat.get(10) << endl; // prints: 3
  
  // ----------------------
  // Testing front and back
  // ----------------------
    //cout << dat.front() << endl; // prints: 1
    //cout << dat.back() << endl; // prints: 3

  // ----------------
  // Testing pop_back
  // ----------------
    // Last item only has one value
    dat.pop_back();
    cout << dat.size() << endl; // prints: 10

    // Last item has more than one value
    for (int i = 1; i <= 9; i++) {
      dat.pop_back();
    }
    cout << dat.size() << endl; // prints: 1
    
    // // List only has one value
    dat.pop_back();
    cout << dat.size() << endl; // prints: 0

  // ------------------
  // Testing push_front
  // ------------------
    // List is empty
    dat.push_front("1");
    cout << dat.get(0) << endl; // prints: 1

    // List has one or more value
    for (int i = 1; i <= 9; i++) {
      dat.push_front("2");
    }
    cout << dat.size() << endl; // prints: 10

    // No space in front of array, new Item created
    dat.push_front("3");
    cout << dat.get(0) << endl; // prints: 3  
    
  // ----------------
  // Testing pop_back
  // ----------------
    // Front item only has one value
    dat.pop_front();
    cout << dat.size() << endl; // prints: 10

    // Front item has more than one value
    for (int i = 1; i <= 9; i++) {
      dat.pop_front();
    }
    cout << dat.size() << endl; // prints: 1
    
    // // List only has one value
    dat.pop_front();
    cout << dat.size() << endl; // prints: 0


  return 0;
}
