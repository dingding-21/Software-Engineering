#include <iostream>
#include <fstream>
#include <string>

#include "SignUp.h"
#include "DeleteAccount.h"
#include "Login.h"
#include "Logout.h"
#include "AddProduct.h"

#include "SearchProduct.h"
//#include "PurchaseProduct.h"

#include "Member.h"
#include "Product.h"

using namespace std;

ifstream in_fp;
ofstream out_fp;

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();

void signUp();
void deleteAccount();
void login();
void logout();
void addProduct();

void searchProduct();
//void purchaseProduct();
//void inquireProduct();
//void evaluateProduct();

// List
Member* memberArry[MAX_MEMBER_NUM] = { NULL };
Product* productArray[MAX_PRODUCT_NUM] = { NULL };
//Member* productPurchaseArray[MAX_PRODUCT_NUM] = { NULL };

// Current Mem
Member* loggedInMem = NULL;

// Current Product Number
int currentProductNum = 0;

string productName = "";

// Control
SignUp* signUpControl;
DeleteAccount* deleteAccountControl;
Login* loginControl;
Logout* logoutControl;
AddProduct* addProductControl;
SearchProduct* searchProductControl;
//PurchaseProduct* purchaseProductControl;
//InquirePurchaseHistory* inquirePurchaseHistoryCon/trol;
//EvaluatePurchaseSatisfaction* evaluatePurchaseSatisfactionControl;


int main()
{
    // 파일 입출력을 위한 초기화

    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);

    if (!in_fp.is_open()) {
        cerr << "Could not open the file - '"
            << INPUT_FILE_NAME << "'" << endl;
        return EXIT_FAILURE;
    }


    doTask();

    in_fp.close();
    out_fp.close();


    return 0;
}

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        in_fp >> menu_level_1;
        in_fp >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행

        // 1. 회원가입 & 회원탈퇴
        if (menu_level_1 == 1) {
            if (menu_level_2 == 1)
            {
                signUp();
            }
            else if (menu_level_2 == 2)
            {
                deleteAccount();
            }
        }

        // 2. 로그인 & 로그아웃
        else if (menu_level_1 == 2) {
            if (menu_level_2 == 1)
            {
                login();
            }
            else if (menu_level_2 == 2)
            {
                logout();

            }
        }

        else if (menu_level_1 == 3) {
            if (menu_level_2 == 1)
            {
                addProduct();
            }
        }


        else if (menu_level_1 == 4) {
            if (menu_level_2 == 1)
            {
                searchProduct();
            }
            else if (menu_level_2 == 2)
            {
                //purchaseProduct();
            }
            else if (menu_level_2 == 3)
            {
                //inquirePurchaseHistory();
            }
            else if (menu_level_2 == 4)
            {
                //evaluatePurchaseSatisfaction();
            }
        }

        else if (menu_level_1 == 6) {
            if (menu_level_2 == 1)
            {
                cout << "종료" << endl;
                is_program_exit = 1;
            }
        }

    }
    return;
}


void signUp()
{
    signUpControl = new SignUp();

    SignUpUI signUpUI;
    signUpUI.enterUserInfo();

}

void deleteAccount()
{
    deleteAccountControl = new DeleteAccount();

    DeleteAccountUI deleteAccountUI;
    deleteAccountUI.clickDeleteAccount();
}

void login()
{
    loginControl = new Login();

    LoginUI loginUI;
    loginUI.enterIdPw();
}

void logout()
{
    logoutControl = new Logout();

    LogoutUI logoutUI;
    logoutUI.clickLogout();
}

void addProduct()
{
    addProductControl = new AddProduct();

    AddProductUI addProductUI;
    addProductUI.enterProductInfo();
}

void searchProduct() {
    searchProductControl = new SearchProduct();

    SearchProductUI searchProductUI;
    searchProductUI.enterProductName();
}

//void purchaseProduct() 
//{
//    purchaseProductControl = new PurchaseProduct();
//
//    PurchaseProductUI purchaseProductUI;
//    purchaseProductUI.confirmPurchase();
//}
//
//void inquirePurchaseHistory() 
//{
//    inquirePurchaseHistory = new inquirePurchaseHistory();
//
//    InquirePurchaseHistoryUI inquirePurchaseHistoryUI;
//    inquirePurchaseHistoryUI. 
//}
//
//void evaluatePurchaseSatisfaction() 
//{
//
//}