#include "SearchProduct.h"
#include "Product.h"
#include <string>

extern int currentProductNum;

Product* SearchProduct::showProduct(string name) {
	Product* getProduct = new Product(name);
	getProduct->getProductDetails();

	return getProduct;
}