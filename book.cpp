
#include <sstream>
#include <iomanip>
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string isbn) :
    Product(category,name,price,qty)
{
    author_=author;
    isbn_=isbn;
}


std::string Book::getAuthor() const
{
    return author_;
}


std::string Book::getISBN() const
{
    return isbn_;
}

 /**
  * Returns the appropriate keywords that this product should be associated with
  */
   std::set<std::string> Book::keywords() const{
    set<std::string> words;
    words = parseStringToWords(convToLower(author_));
    set<std::string> words2;
    words2= parseStringToWords(convToLower(name_));
    words = setUnion(words,words2);
    words.insert(isbn_);

    return words;
   }

/**
  * Allows for a more detailed search beyond simple keywords
 */
  bool Book::isMatch(std::vector<std::string>& searchTerms) const{
      set<std::string> keys = keywords();

      for(typename std::vector<std::string>::iterator it=searchTerms.begin(); it != searchTerms.end(); ++it){//for each in keys
        if(keys.find(*it)!=keys.end()){ //if its contained in s2 (logN)
           return true;
         }
      } 
      return false;
  }

 /**
  * Returns a string to display the product info for hits of the search
  */
  std::string Book::displayString() const {
    return name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left."; //might be missing newline at end
  }

/**
  * Outputs the product info in the database format
  */
  void Book::dump(std::ostream& os) const{
     os << "book\n" + name_ + "\n" + to_string(price_) + "\n" + to_string(qty_) + "\n" +isbn_ + "\n"  + author_ + "\n";
  }




