#include "AddProduct.h"
#include "Product.h"
#include "Member.h"

extern Member* loggedInMem;
extern int currentProductNum;

bool AddProduct::addNewProduct(string sellerId, string name, string company, int price, int quantity, double averagePurchaseSatisfaction) {
	if (loggedInMem == NULL) return false;

	Product* newProduct = new Product(sellerId, name, company, price, quantity, averagePurchaseSatisfaction);
	bool pNameCheck = false;

	pNameCheck = newProduct->productNameCheck();


	if (pNameCheck == true) {
		newProduct->createNewProduct();
		currentProductNum++;
		return true;
	}
	else {
		return false;
	}
}