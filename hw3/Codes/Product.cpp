#include "./entity/Product.h"
#include "./entity/Member.h"

extern Product* productArry[MAX_PRPDUCT_NUM];
extern Member* loggedInMem;

bool Product::productNameCheck()
{
	for (int i = 0; i < MAX_PRPDUCT_NUM; i++) {
		if (!productArry[i] == NULL) {
			if (this->name == productArry[i]->name) {
				return false;
			}
		}
	}
	return true;
}

void Product::createNewProduct()
{
	for (int i = 0; i < MAX_PRPDUCT_NUM; i++) {
		if (productArry[i] == NULL) {
			this->arryNum = i;
			this->seller = loggedInMem->getId();
			productArry[i] = this;
			break;
		}
	}
}