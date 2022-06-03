#include "AddProductUI.h"
#include "AddProduct.h"
#include "Member.h"

extern ifstream in_fp;
extern ofstream out_fp;

extern AddProduct* addProductControl;
extern Member* loggedInMem;

void AddProductUI::startInterface() {
    out_fp << "3.1. �Ǹ� �Ƿ� ���" << endl;
    cout << "3.1. �Ǹ� �Ƿ� ���" << endl;
}
void AddProductUI::enterProductInfo()
{
    string line;
    string word;

    string sellerId = "";
    string name = "";
    string company = "";
    int price = NULL;
    int quantity = NULL;
    double averagePurchaseSatisfaction = 0;

    bool AddProductOk = false;

    // �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> name; ss >> company;
    ss >> price; ss >> quantity;

    if (!loggedInMem == NULL) {
        sellerId = loggedInMem->getId();
    }

    if (name == "" || company == "" || price == NULL || quantity == NULL) {
        cout << "��ǰ ��� ����" << endl << endl;
        return;
    }

    AddProductOk = addProductControl->addNewProduct(sellerId, name, company, price, quantity, averagePurchaseSatisfaction);

    if (AddProductOk == true) {
        out_fp << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
        cout << "> " << name << " " << company << " " << price << " " << quantity << " " << sellerId << endl << endl;
        return;
    }
    else {
        out_fp << "��ǰ ��� ����" << endl << endl;
        cout << "��ǰ ��� ����" << endl << endl;
        return;
    }


    // ���� �� ��� ���
    out_fp << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
    cout << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
}
