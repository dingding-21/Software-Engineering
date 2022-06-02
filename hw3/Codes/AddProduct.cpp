#include "./classes/AddProduct.h"
#include "./entity/Product.h"
#include "./entity/Member.h"

extern Member* loggedInMem;

bool AddProduct::addNewProduct(string name, string company, int price, int quantity) {
	if (loggedInMem == NULL) return false;

	Product* newProduct = new Product(name, company, price, quantity);
	bool pNameCheck = false;

	pNameCheck = newProduct->productNameCheck();


	if (pNameCheck == true) {
		newProduct->createNewProduct();
		return true;
	}
	else {
		return false;
	}
}