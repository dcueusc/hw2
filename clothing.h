#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Clothing : public Product { //ISBN Author
public:
    Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
    //virtual ~Clothing();

    std::string displayString() const;
    void dump(std::ostream& os) const;
    bool isMatch(std::vector<std::string>& searchTerms) const;
    std::set<std::string> keywords() const;

    /**
     * Accessors and mutators
     */
    std::string getSize() const;
    std::string getBrand() const;


protected:
    
    std::string size_;
    std::string brand_;

};
#endif
