#include "SearchProductUI.h"
#include "common.h"
#include "Product.h"

class SearchProduct {
private:
public:
    SearchProduct() {
        SearchProductUI* searchProductUI = new SearchProductUI;
        searchProductUI->startInterface();
    }

    Product* showProduct(string name);
};