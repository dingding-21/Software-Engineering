#include "./classes/DeleteAccountUI.h"
#include "./classes/DeleteAccount.h"

extern DeleteAccount* deleteAccountControl;
extern ifstream in_fp;
extern ofstream out_fp;

void DeleteAccountUI::startInterface()
{ 
    out_fp << "1.2. È¸¿øÅ»Åð" << endl; 
    cout << "1.2. È¸¿øÅ»Åð" << endl;
}

void DeleteAccountUI::clickDeleteAccount() {

    string id = "";
    id = deleteAccountControl->deleteAccount();

    if (id == "") {
        out_fp << "> È¸¿øÅ»Åð ½ÇÆÐ" << endl << endl;
        cout << "> È¸¿øÅ»Åð ½ÇÆÐ" << endl << endl;
    }
    else {
        // ¼º°ø ½Ã °á°ú Ãâ·Â
        out_fp << "> " << id << endl << endl;
        cout << "> " << id << endl << endl;
    }
}
