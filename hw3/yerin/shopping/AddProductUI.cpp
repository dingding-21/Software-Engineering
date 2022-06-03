#include "AddProductUI.h"
#include "AddProduct.h"
#include "Member.h"

extern ifstream in_fp;
extern ofstream out_fp;

extern AddProduct* addProductControl;
extern Member* loggedInMem;

void AddProductUI::startInterface() {
    out_fp << "3.1. 판매 의류 등록" << endl;
    cout << "3.1. 판매 의류 등록" << endl;
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

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> name; ss >> company;
    ss >> price; ss >> quantity;

    if (!loggedInMem == NULL) {
        sellerId = loggedInMem->getId();
    }

    if (name == "" || company == "" || price == NULL || quantity == NULL) {
        cout << "상품 등록 실패" << endl << endl;
        return;
    }

    AddProductOk = addProductControl->addNewProduct(sellerId, name, company, price, quantity, averagePurchaseSatisfaction);

    if (AddProductOk == true) {
        out_fp << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
        cout << "> " << name << " " << company << " " << price << " " << quantity << " " << sellerId << endl << endl;
        return;
    }
    else {
        out_fp << "상품 등록 실패" << endl << endl;
        cout << "상품 등록 실패" << endl << endl;
        return;
    }


    // 성공 시 결과 출력
    out_fp << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
    cout << "> " << name << " " << company << " " << price << " " << quantity << endl << endl;
}
