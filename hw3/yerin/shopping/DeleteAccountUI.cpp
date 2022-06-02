#include "DeleteAccountUI.h"
#include "DeleteAccount.h"

extern DeleteAccount* deleteAccountControl;
extern ifstream in_fp;
extern ofstream out_fp;

void DeleteAccountUI::startInterface()
{ 
    out_fp << "1.2. ȸ��Ż��" << endl; 
    cout << "1.2. ȸ��Ż��" << endl;
}

void DeleteAccountUI::clickDeleteAccount() {

    string id = "";
    id = deleteAccountControl->deleteAccount();

    if (id == "") {
        out_fp << "> ȸ��Ż�� ����" << endl << endl;
        cout << "> ȸ��Ż�� ����" << endl << endl;
    }
    else {
        // ���� �� ��� ���
        out_fp << "> " << id << endl << endl;
        cout << "> " << id << endl << endl;
    }
}
