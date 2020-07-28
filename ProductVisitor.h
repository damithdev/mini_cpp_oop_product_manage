#ifndef _PRODUCT_VISITOR_H
#define _PRODUCT_VISITOR_H

class Product;
class Item;
class CannedItem;
class FreshVegetable;
class Package;

#include <vector>

class ProductVisitor
{
 public:
  ProductVisitor() {};
  virtual void visit(FreshVegetable *p)= 0;
  virtual void visit(CannedItem *p) = 0;
  void visit(Package *p);
};

class CheapestVisitor : public ProductVisitor
{
 public:
  // ... TO BE COMPLETED
  double getMinPrice(); // Return the price of the cheapest item 
  Item *getMinItem();   // Return the item with the cheapest price
  void reset();         // Reset before visiting a different product
  void setPrice(const double Price) { dPrice = Price; }// .. COMPLETED

  void visit(FreshVegetable *p);
  void visit(CannedItem *p);
 private:
  // .. TO BE COMPLETED
  double dPrice; // .. COMPLETED
  std::vector<Item*> Itemvector; // .. COMPLETED
};

class ReducePriceVisitor : public ProductVisitor
{
 public:
  // .. TO BE COMPLETED
  ReducePriceVisitor(double dfreshveg, double dcanneditm){ this->canneditm = dcanneditm; this->freshveg = dfreshveg;  } // .. COMPLETED
  void visit(FreshVegetable *p);
  void visit(CannedItem *p);
 private:
  // .. TO BE COMPLETED
  double freshveg;// .. COMPLETED
  double canneditm;// .. COMPLETED
};
#endif


