#include "datastore.h"
#include "mydatastore.h"
#include "util.h"

using namespace std;

 myDataStore::myDataStore(){}

myDataStore::~myDataStore() {
//   std::map<std::string, std::set<Product*>> prodMap;
//  std::map<std::string, User*> userMap;
//  std::map<std::string, std::queue<Product*>> cartMap;



  // std::map<std::string, std::set<Product*>>::iterator it = prodMap.begin(); 
  // while(it!=prodMap.end()){
  //   set<Product*> temp = it->second;
  //   for (set<Product*>::iterator itr = temp.begin(); itr != temp.end(); itr++){
  //    delete *itr;
  //   }
  //   it++; 
  // }  

  for (Product* prod : products) {
     delete prod;
    }
    

    // Clean up memory allocated for users
    for (auto it = userMap.begin(); it != userMap.end(); ++it) {
        delete it->second;
    }

  
    
}





void myDataStore::addProduct(Product* p){
 set<string> keys = p->keywords(); //for each keyword, if it already has value, add product to that set. if not, create new set for product
  for(set<string>::iterator it=keys.begin(); it != keys.end(); ++it){
  prodMap[*it].insert(p);
  }
  products.insert(p);

//  set<Product*> withP;
//  withP.insert(p);
//   for(set<string>::iterator it=keys.begin(); it != keys.end(); ++it){
//     pair<map<string,set<Product*>>::iterator,bool> wasAdded = prodMap.insert(pair<string,set<Product*>>(*it,withP));
//     if(wasAdded->second==false){ //add product to exisiting set for keyword
//     }
//   }
}


void myDataStore::addUser(User* u){
  userMap[u->getName()] = u;
}


/**
    * Performs a search of products whose keywords match the given "terms"
    *  type 0 = AND search (intersection of results for each term) while
    *  type 1 = OR search (union of results for each term)
    */
std::vector<Product*> myDataStore::search(std::vector<std::string>& terms, int type){
    set<Product*> searchSet;
    bool first=true;

  for(vector<string>::iterator it=terms.begin(); it != terms.end(); ++it){
    map<string,set<Product*>>::iterator isThere = prodMap.find(*it);
    set<Product*> matches;
    if(isThere != prodMap.end()){
        matches = isThere->second;
    }
    if(first==true){searchSet=matches; first=false;}
    if(type==0){ //ANDsearch input is a vector of ind. lowercase strings
    //for every term, search map and add all its matching products. 
        searchSet= setIntersection(searchSet,matches);
    }
    else if(type==1){ //OR search 
        searchSet= setUnion(searchSet,matches);
    }

  }

  vector<Product*> vec(searchSet.begin(), searchSet.end());
  return vec;

}


void myDataStore::dump(std::ostream& ofile){
  ofile << "<products>" << endl;
  set<Product*> searchSet;
  bool first=true;
  for(map<string,set<Product*>>::iterator it=prodMap.begin(); it != prodMap.end(); ++it){
    set<Product*> currS = it->second;
    if(first==true){searchSet=currS; first=false;}
    else{searchSet=setUnion(searchSet,currS);}
  }
  for(set<Product*>::iterator ne=searchSet.begin(); ne != searchSet.end(); ++ne){
    (*ne)->dump(ofile);
  }

  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  for(map<string,User*>::iterator it=userMap.begin(); it != userMap.end(); ++it){
    (it->second)->dump(ofile);
  }
  ofile << "</users>" << endl;

}

bool myDataStore::addToCart(string use, Product* p){
  if(userMap.find(use)==userMap.end()){
    return false;
  }
  cartMap[use].push(p); 
  return true;
}

void myDataStore::viewCart(std::string givenU){
  map<string,User*>::iterator it = userMap.find(givenU);
  if(it==userMap.end()){
    cout << "Invalid username" << endl;
  }else{
    queue<Product*> prods = cartMap[givenU];
    int i=0;
    while(!prods.empty()){
      cout <<"Item "<< i+1 << endl << prods.front()->displayString() << endl;
      prods.pop();
      i++;
    }
  }
}

void myDataStore::buyCart(std::string givenU){
  map<string,User*>::iterator it = userMap.find(givenU);
  if(it==userMap.end()){
    cout << "Invalid username" << endl;
  }else{ 
    queue<Product*> prods = cartMap[givenU];
    while(!prods.empty()){ Product* temp = prods.front();
      if(temp->getQty()>=1 && (it->second->getBalance()-temp->getPrice() > 0)){
          it->second->deductAmount(temp->getPrice());
          temp -> subtractQty(1);
          cartMap[givenU].pop();
      }
      prods.pop();
    }
  }

}
