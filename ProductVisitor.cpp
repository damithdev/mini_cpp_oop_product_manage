#include "ProductVisitor.h"
#include "Product.h"

// Accept() method for all products that accept a
// ProductVisitor

void FreshVegetable::accept(ProductVisitor *v)
{
  v->visit(this);
};


void CannedItem::accept(ProductVisitor *v)
{
  v->visit(this);
};


void Package::accept(ProductVisitor *v)
{
  v->visit(this);
};

// Visit method for ProductVisitor class on Package class
void ProductVisitor::visit(Package *p)
{
  // .. TO BE COMPLETED
  for (size_t index = 0;index < p->size(); index++)
  {
    p->getProduct(index)->accept(this);
  }
}


// Visit Method for the CheapestVisitor class on CannedItem class

void CheapestVisitor::visit(CannedItem *p)
{
  // .. TO BE COMPLETED
  if (p->getPrice() < dPrice)
  {
    dPrice = p->getPrice();
  }
  Itemvector.push_back(p);
}

// Visit Method for the CheapestVisitor class on FreshVegetable class
void CheapestVisitor::visit(FreshVegetable *p)
{
  // .. TO BE COMPLETED
  if (p->getPrice() < dPrice)
  {
    dPrice = p->getPrice();
  }
  Itemvector.push_back(p);
}

// Visit Method for ReducePriceVisitor class on FreshVegetable class

void ReducePriceVisitor::visit(FreshVegetable *p)
{
  // .. TO BE COMPLETED
  p->setPrice(freshveg * p->getPrice());
}

// Visit Method for ReducePriceVisitor class on CannedItem class

void ReducePriceVisitor::visit(CannedItem *p)
{
  // .. TO BE COMPLETED
  p->setPrice(canneditm * p->getPrice());
}

// CheapestVisitor Method to return the price of the cheapest item
double CheapestVisitor::getMinPrice()
{
  // TO BE COMPLETED
  return dPrice;
}

// CheapestVisitor Method to return the cheapest Item
Item *CheapestVisitor::getMinItem()
{
  // TO BE COMPLETED
  auto iterator = find_if(Itemvector.begin(), Itemvector.end(), [this](Item* item)->bool {
      return item->getPrice() == dPrice;
  });

  if (iterator == Itemvector.end())
  {
    return nullptr;
  }

  return static_cast<Item*>(*iterator);
}

// CheapestVisitor Method to reset before finding the minimum item
void CheapestVisitor::reset()
{
  // TO BE COMPLETED
  Itemvector.clear();
}







