#include "Product.h"
#include "ProductVisitor.h"


#include <iostream>
using namespace std;


void test1(double freshVegReduction, double cannedItemReduction)
{
  // Declare a couple of fresh vegetables and
  // a canned item, giving their name and their price.
  FreshVegetable carrot("carrot", 50.0), peas("peas", 60.0), parsnips("parsnips", 55.0);
  CannedItem mushyPeas("mushyPeas", 80.0), bakedbeans("bakedBeans", 100.0);
  
  // Declare a package to contain multiple products
  Package pack1("package1");

  // Add products to the package
  pack1.addProduct(&carrot);
  pack1.addProduct(&peas);
  pack1.addProduct(&bakedbeans);

  // The Cheapest Visitor calculates the price of the cheapest
  // item in the package
  CheapestVisitor cheap;
  cheap.setPrice(pack1.getProduct(0)->getPrice());
  pack1.accept(&cheap);

  cout << "The cheapest item is "
       << cheap.getMinItem()->getName() << " at price "
       << cheap.getMinPrice() << " rupies." << endl;

  // The ReducePriceVisitor takes two arguments - a percentage (0.80) by
  // which to reduce the price of FreshVegetable products and
  // a percentage (0.50) by which to reduce CannedItem products

  ReducePriceVisitor priceModifier(freshVegReduction, cannedItemReduction);
  pack1.accept(&priceModifier);

  // Use CheapestVisitor to re-calculate price of cheapest item

  cheap.reset();       // re-set to compute a new minimum price
  pack1.accept(&cheap);
  cout << "The cheapest item is "
       << cheap.getMinItem()->getName() << " at price "
       << cheap.getMinPrice() << " rupies." << endl;

}


void test2(double freshVegReduction, double cannedItemReduction)
{
  // Declare a couple of fresh vegetables and
  // a canned item, giving their name and their price.
  FreshVegetable carrot("carrot", 50.0), peas("peas", 60.0), parsnips("parsnips", 55.0);
  CannedItem mushyPeas("mushyPeas", 80.0), bakedbeans("bakedBeans", 100.0);
  // Declare a package to contain multiple items

  Package pack1("package1");

  // Declare a second package that will contain pack1

  Package pack2("package2");

  // Add products to the packages - pack2 contains pack1 
  pack1.addProduct(&carrot);
  pack1.addProduct(&peas);
  pack1.addProduct(&mushyPeas);
  pack2.addProduct(&pack1);
  pack2.addProduct(&bakedbeans);
  pack2.addProduct(&parsnips);
  // The Cheapest Visitor calculates the price of the cheapest
  // item in the package
  CheapestVisitor cheap;
  cheap.setPrice(pack2.getProduct(0)->getPrice()); // .. COMPLETED
  pack2.accept(&cheap);

  cout << "The cheapest item is "
       << cheap.getMinItem()->getName() << " at price "
       << cheap.getMinPrice() << " rupies." << endl;

  // The ReducePriceVisitor takes two arguments - a percentage (0.80) by
  // which to reduce the price of FreshVegetable products and
  // a percentage (0.50) by which to reduce CannedItem products

  ReducePriceVisitor priceModifier(freshVegReduction, cannedItemReduction);
  pack2.accept(&priceModifier);

  // Use CheapestVisitor to re-calculate price of cheapest item

  cheap.reset();       // re-set to compute a new minimum price
  pack2.accept(&cheap);
  cout << "The cheapest item is "
       << cheap.getMinItem()->getName() << " at price "
       << cheap.getMinPrice() << " rupies." << endl;

}

int main()
{
  test1(0.8,0.5);
  test1(0.5,0.8);
  test1(1.0,0.4);
  test2(0.8,0.5);
  test2(0.5,0.8);
  test2(1.0,0.4);
  return 0;
}
