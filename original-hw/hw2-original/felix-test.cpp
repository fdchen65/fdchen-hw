#include "util.h"

using namespace std;
 /*class utilTest : public testing::Test{
protected:
    string str;
    utilTest(){
    }

    virtual ~utilTest(){
    }

    virtual void SetUp(){
        str += "hello there this is testing code";
    }

};

TEST_F(utilTest, parseStringNominal){
    std::set<std::string> ans = parseStringToWords(str);
    EXPECT_EQ("hello", *(ans.begin()));
}
 */
int main(){


    //nominal cse
    string str1 = "Data Abstraction & Problem Solving with C++";
    set<string> s = parseStringToWords(str1);

    cout << s.size() << endl;
    for(set<string>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //edge
    string str2 = "hi,there,a;thing a thing a thing a thing/ping /pong  bruh momen't";
    s = parseStringToWords(str2);
    cout << s.size() << endl;
    for(set<string>::iterator it = s.begin() ; it != s.end() ; it++){
        cout << *it << " ";
    }
    cout << endl; 
    
    /*
    //util setIntersection
        //nominal
    set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    set<int> s2 = {2, 4, 6, 8, 3, 12, 13, 14, 15, 16};
    set<int> s3 = setIntersection<int>(s1, s2);
    for(set<int>::iterator it = s3.begin() ; it != s3.end() ; it++){
        cout << *it << " ";
    }
     cout << endl;
    //util setUnion
        //nominal
    s3 = setUnion<int>(s1, s2);
    for(set<int>::iterator it = s3.begin() ; it != s3.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
    */

    return 0;
}