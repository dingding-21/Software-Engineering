#include "SearchProductUI.h"
#include "SearchProduct.h"
#include "Product.h"

extern ifstream in_fp;
extern ofstream out_fp;

extern SearchProduct* searchProductControl;

void SearchProductUI::startInterface() {
    out_fp << "4.1. ��ǰ ���� �˻�" << endl;
    cout << "4.1. ��ǰ ���� �˻�" << endl;
}
void SearchProductUI::enterProductName()
{
    Product* findProduct = NULL;

    string line;
    string word;

    string name = "";

    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> name;

    if (name == "") {
        cout << "��ǰ �˻� ����" << endl << endl;
        return;
    }

    findProduct = searchProductControl->showProduct(name);
    out_fp << "> " << findProduct->getSellerId() << " " << findProduct->getName() << " " << findProduct->getCompany() << " " << findProduct->getPrice() << " " << findProduct->getQuantity() << findProduct->getAveragePurchaseSatisfaction() << " " << endl << endl;
    cout << "> " << findProduct->getSellerId() << " " << findProduct->getName() << " " << findProduct->getCompany() << " " << findProduct->getPrice() << " " << findProduct->getQuantity() << findProduct->getAveragePurchaseSatisfaction() << " " << endl << endl;
}
