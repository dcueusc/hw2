#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Movie : public Product { //ISBN Author
public:
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
    //virtual ~Movie();

    std::string displayString() const;
    void dump(std::ostream& os) const;
    bool isMatch(std::vector<std::string>& searchTerms) const;
    std::set<std::string> keywords() const;

    /**
     * Accessors and mutators
     */
    std::string getGenre() const;
    std::string getRating() const;


protected:
    
    std::string genre_;
    std::string rating_;

};
#endif
