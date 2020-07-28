#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAME_LEN = 200;

class ProductVisitor;

class Product
{
 public:
 Product() {};
  virtual void accept(ProductVisitor *v) = 0;
  virtual double getPrice() = 0;
  char *getName() {return name;};
 protected:
  char name[MAX_NAME_LEN];
};

class Item : public Product
{
 public:
 Item(const char *n) : price(0.0) {strcpy(name, n);};
 Item(const char *n, double p) : price(p) {strcpy(name, n);};
  virtual void accept(ProductVisitor *v) = 0;
  double getPrice() {return price;};
  void setPrice(double p) { price = p;};

 private:
  double price;
};



class FreshVegetable : public Item
{
 public:
 FreshVegetable(const char *n) : Item(n) {};
 FreshVegetable(const char *n, double p) : Item(n,p) {};
  
  void accept(ProductVisitor *v);
};

class CannedItem : public Item
{
 public:
 CannedItem(const char *n) : Item(n) {};
 CannedItem(const char *n, double p) : Item(n,p) {};
  void accept(ProductVisitor *v);
};


class Package : public Product
{
 public:
  Package(const char pname[]) {strcpy(name, pname);};
  Package& addProduct(Product *product) { contents.push_back(product); return *this; };
  Product *getProduct(int i) { return contents[i];};
  int size() {return contents.size();};
  virtual void accept(ProductVisitor *v);
  double getPrice() { double p=0.0; for (unsigned int i=0;i<contents.size();i++) { p+=contents[i]->getPrice();} return p;};
 private:
  vector<Product *> contents;
};



#endif
    
