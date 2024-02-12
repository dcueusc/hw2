
#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
    Product(category,name,price,qty)
{
    size_=size;
    brand_=brand;
}




std::string Clothing::getSize() const
{
    return size_;
}


std::string Clothing::getBrand() const
{
    return brand_;
}

 /**
  * Returns the appropriate keywords that this product should be associated with
  */
   std::set<std::string> Clothing::keywords() const{
    set<std::string> words;

    words = parseStringToWords(convToLower(brand_));
    set<std::string> words2;
    words2= parseStringToWords(convToLower(name_));
    words = setUnion(words,words2);
    words.insert(convToLower(size_));

    return words;
   }

/**
  * Allows for a more detailed search beyond simple keywords
 */
  bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
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
  std::string Clothing::displayString() const {
      return name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left."; //might be missing newline at end
  }

/**
  * Outputs the product info in the database format
  */
  void Clothing::dump(std::ostream& os) const{
     os << "clothing\n" + name_ + "\n" + to_string(price_) + "\n" + to_string(qty_) + "\n" + size_ + "\n"  + brand_ + "\n";
  }




