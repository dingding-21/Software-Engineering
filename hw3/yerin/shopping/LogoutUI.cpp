#include "LogoutUI.h"
#include "Logout.h"

extern ifstream in_fp;
extern ofstream out_fp;
extern Logout* logoutControl;

void LogoutUI::startInterface() 
{ 
    out_fp << "2.2. �α׾ƿ�" << endl;
    cout << "2.2. �α׾ƿ�" << endl;
}

void LogoutUI::clickLogout()
{
    string id = "";
    id = logoutControl->logoutReq();


    if (id == "") {
        out_fp << "> �α׾ƿ� ����" << endl << endl;
        cout << "> �α׾ƿ� ����" << endl << endl;
    }
    else {
        // ���� �� ��� ���
        out_fp << "> " << id << endl << endl;
        cout << "> " << id << endl << endl;
    }
}