#include <iostream>
#include <fstream>
#include <string>

#include "./classes/SignUp.h"
#include "./classes/DeleteAccount.h"
#include "./classes/Login.h"
#include "./classes/Logout.h"
#include "./classes/AddProduct.h"
#include "./entity/Member.h"
#include "./entity/Product.h"

using namespace std;

ifstream in_fp;
ofstream out_fp;

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();

void signUp();
void deleteAccount();
void login();
void logout();
void addProduct();

// List
Member* memberArry[MAX_MEMBER_NUM] = { NULL };
Product* productArry[MAX_PRPDUCT_NUM] = { NULL };

// Current Mem
Member* loggedInMem = NULL;

// Control
SignUp* signUpControl;
DeleteAccount* deleteAccountControl;
Login* loginControl;
Logout* logoutControl;
AddProduct* addProductControl;

int main()
{
    // ���� ������� ���� �ʱ�ȭ

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
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        in_fp >> menu_level_1;
        in_fp >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����

        // 1. ȸ������ & ȸ��Ż��
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

        // 2. �α��� & �α׾ƿ�
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
                cout << "��ǰ �˻�" << endl;
            }
            else if (menu_level_2 == 2)
            {
                cout << "��ǰ ����" << endl;
            }
            else if (menu_level_2 == 3)
            {
                cout << "��ǰ ���� ���� ��ȸ" << endl;
            }
            else if (menu_level_2 == 4)
            {
                cout << "��ǰ ���Ÿ����� ��" << endl;
            }
        }

        else if (menu_level_1 == 6) {
            if (menu_level_2 == 1)
            {
                out_fp << "6.1. ����" << endl;
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