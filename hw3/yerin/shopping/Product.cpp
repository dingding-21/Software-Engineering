#include "Product.h"
#include "Member.h"

extern Product* productArray[MAX_PRODUCT_NUM];
extern Member* loggedInMem;
extern int currentProductNum;

extern ifstream in_fp;
extern ofstream out_fp;

bool Product::productNameCheck()
{
	for (int i = 0; i < currentProductNum; i++) {
		if (!productArray[i] == NULL) {
			if (this->name == productArray[i]->name) {
				return false;
			}
		}
	}
	return true;
}

void Product::createNewProduct()
{
	for (int i = 0; i < MAX_PRODUCT_NUM; i++) {
		if (productArray[i] == NULL) {
			this->arrayNum = i;
			this->sellerId = loggedInMem->getId();
			productArray[i] = this;
			break;
		}
	}
}

void Product::getProductDetails()
{
	for (int i = 0; i < currentProductNum; i++) {
		if (!productArray[i] == NULL) {
			if (this->name == productArray[i]->name) {
				this->sellerId = productArray[i]->sellerId;
				this->name = productArray[i]->name;
				this->company = productArray[i]->company;
				this->price = productArray[i]->price;
				this->quantity = productArray[i]->quantity;
				this->averagePurchaseSatisfaction = productArray[i]->averagePurchaseSatisfaction;
				//out_fp << "> " << productArray[i]->getSellerId() << " " << this->getName() << " " << this->getCompany() << " " << this->getPrice() << " " << this->getQuantity() << this->getAveragePurchaseSatisfaction() << " " << endl << endl;
				//cout << "> " << productArray[i]->getSellerId() << " " << this->getName() << " " << this->getCompany() << " " << this->getPrice() << " " << this->getQuantity() << this->getAveragePurchaseSatisfaction() << " " << endl << endl;
			}
		}
	}
}

string Product::getSellerId()
{
	return sellerId;
}

string Product::getName() {
	return name;
}

string Product::getCompany() {
	return company;
}

int Product::getPrice() {
	return price;
}

int Product::getQuantity() {
	return quantity;
}

double Product::getAveragePurchaseSatisfaction() {
	return averagePurchaseSatisfaction;
}

