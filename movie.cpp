
#include <sstream>
#include <iomanip>
#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
    Product(category,name,price,qty)
{
    genre_=genre;
    rating_=rating;
}



std::string Movie::getGenre() const
{
    return genre_;
}


std::string Movie::getRating() const
{
    return rating_;
}

 /**
  * Returns the appropriate keywords that this product should be associated with
  */
   std::set<std::string> Movie::keywords() const{
    set<std::string> words;

    words = parseStringToWords(convToLower(genre_));
    set<std::string> words2;
    words2= parseStringToWords(convToLower(name_));
    words = setUnion(words,words2);
    words.insert(convToLower(genre_));

    return words;
   }

/**
  * Allows for a more detailed search beyond simple keywords
 */
  bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
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
  std::string Movie::displayString() const {
      return name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left."; //might be missing newline at end
  }

/**
  * Outputs the product info in the database format
  */
  void Movie::dump(std::ostream& os) const{
     os << "movie\n" + name_ + "\n" + to_string(price_) + "\n" + to_string(qty_) + "\n" + genre_ + "\n"  + rating_ + "\n";
  }




