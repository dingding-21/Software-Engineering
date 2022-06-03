#include "AddProductUI.h"

class AddProduct {
private:
public:
    AddProduct() {
        AddProductUI* addProductUI = new AddProductUI;
        addProductUI->startInterface();
    }

    bool addNewProduct(string name, string company, int price, int quantity);
};