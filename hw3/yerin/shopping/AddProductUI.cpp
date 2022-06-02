#include "AddProductUI.h"
#include "AddProduct.h"

extern ifstream in_fp;
extern ofstream out_fp;

extern AddProduct* addProductControl;

void AddProductUI::startInterface() { 
    out_fp << "3.1. �Ǹ� �Ƿ� ���" << endl;
    cout << "3.1. �Ǹ� �Ƿ� ���" << endl;
}
void AddProductUI::enterProductInfo()
{
    string line;
    string word;

    string name = "";
    string company = "";
    int price = NULL;
    int quantity = NULL;

    bool AddProductOk = false;

    // �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> name; ss >> company;
    ss >> price; ss >> quantity;

    if (name == "" || company == "" || price == NULL || quantity == NULL) {
        cout << "��ǰ ��� ����" << endl << endl;
        return;
    }

    AddProductOk = addProductControl->addNewProduct(name, company, price, quantity);

    if (AddProductOk == true) {
        out_fp << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
        cout << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
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
