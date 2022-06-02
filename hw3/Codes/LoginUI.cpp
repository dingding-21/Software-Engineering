#include "./classes/Login.h"
#include "./classes/LoginUI.h"

extern ifstream in_fp;
extern ofstream out_fp;
extern Login* loginControl;

void LoginUI::startInterface()
{
    out_fp << "2.1. 로그인" << endl;
    cout << "2.1. 로그인" << endl;
}

void LoginUI::enterIdPw()
{
    string line;
    string word;

    string id = "";
    string password = "";
    bool loginOk = false;
       
    // 입력 형식 : ID, Password를 파일로부터 읽음
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> id; ss >> password;

    if (id == "" || password == "") {
        cout << "양식에 맞게 입력하세요" << endl << endl;
        return;
    }

    loginOk = loginControl->checkIdPw(id, password);

    if (loginOk == true) {
        // 성공 시 결과 출력
        out_fp << "> " << id << " " << password << endl << endl;
        cout << "> " << id << " " << password << endl << endl;
    }
    else {
        out_fp << "> 로그인에 실패하였습니다." << endl << endl;
        cout << "> 로그인에 실패하였습니다." << endl << endl;
    }
}