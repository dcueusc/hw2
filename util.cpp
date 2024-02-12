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
  set<std::string> sample;
  rawWords= trim(rawWords);
   rawWords = convToLower(rawWords);
 //split around spaces, punctuation, words must be >=2 chars
  std::string currW="";
  int curr=0;
  while(true){
    if(curr==rawWords.length()){
      if(currW.length()<2){currW="";}
      else{
        if(sample.find(currW)==sample.end()){sample.insert(currW); currW="";}
      }
      break;}
    if(rawWords.at(curr)!=' ' && rawWords.at(curr)!='.' &&rawWords.at(curr)!='!'&&rawWords.at(curr)!=',' &&rawWords.at(curr)!='?' &&rawWords.at(curr)!='\''){
      currW+=rawWords.at(curr);
    }
    else{
      if(currW.length()<2){currW="";}
      else{
        if(sample.find(currW)==sample.end()){sample.insert(currW); currW="";}
      }
    }
    curr++;
  }

  return sample;
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
