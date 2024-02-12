#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Book : public Product { //ISBN Author
public:
    Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
    //virtual ~Book();

    std::string displayString() const;
    void dump(std::ostream& os) const;
    bool isMatch(std::vector<std::string>& searchTerms) const;
    std::set<std::string> keywords() const;

    /**
     * Accessors and mutators
     */
    std::string getISBN() const;
    std::string getAuthor() const;


protected:
    
    std::string isbn_;
    std::string author_;

};
#endif
