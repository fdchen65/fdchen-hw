#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> ans;
    rawWords = trim(rawWords);
    rawWords += ' ';
    int temp = 0;
    for(unsigned int i = 0; i < rawWords.length() ; i++){
        if(ispunct(rawWords[i]) || rawWords[i] == ' ' || i == rawWords.length()-1){
            std::string str = std::string(&rawWords[temp], &rawWords[i]);
            ans.insert(trim(str));
            temp = i+1;
        }
    }

    //delete words with <2 characters
    set<string>::iterator it = ans.begin();
    while(it != ans.end()){
        if(it->length() < 2){
            ans.erase(it++);
        } else {
            it++;
        }
    }

    return ans;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
