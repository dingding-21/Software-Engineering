#include "LogoutUI.h"
#include "Logout.h"

extern ifstream in_fp;
extern ofstream out_fp;
extern Logout* logoutControl;

void LogoutUI::startInterface() 
{ 
    out_fp << "2.2. 로그아웃" << endl;
    cout << "2.2. 로그아웃" << endl;
}

void LogoutUI::clickLogout()
{
    string id = "";
    id = logoutControl->logoutReq();


    if (id == "") {
        out_fp << "> 로그아웃 실패" << endl << endl;
        cout << "> 로그아웃 실패" << endl << endl;
    }
    else {
        // 성공 시 결과 출력
        out_fp << "> " << id << endl << endl;
        cout << "> " << id << endl << endl;
    }
}