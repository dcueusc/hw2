#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include <queue>
#include <map>

class myDataStore : public DataStore {
public:
   myDataStore();
   ~myDataStore();
   void addProduct(Product* p);
   void addUser(User* u);
   std::vector<Product*> search(std::vector<std::string>& terms, int type);
   void dump(std::ostream& ofile);
   bool addToCart(std::string use, Product* p);
   void viewCart(std::string givenU);
   void buyCart(std::string givenU);

 protected:
 std::map<std::string, std::set<Product*>> prodMap;
 std::map<std::string, User*> userMap;
 std::map<std::string, std::queue<Product*>> cartMap;
 std::set<Product*> products;


};


#endif
