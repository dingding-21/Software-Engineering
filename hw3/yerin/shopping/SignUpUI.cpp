#include "SignUpUI.h"
#include "SignUp.h"

extern ifstream in_fp;
extern ofstream out_fp;
extern SignUp* signUpControl;

// 회원가입 SignUp
void SignUpUI::startInterface() 
{ 
    out_fp << "1.1. 회원가입" << endl;
    cout << "1.1. 회원가입" << endl;
}

void SignUpUI::enterUserInfo()
{
    string line;
    string word;

    string name = "";
    string socialNum = "";
    string id = "";
    string password = "";
    bool signUpOk = false;

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> name; ss >> socialNum;
    ss >> id; ss >> password;

    if (name == "" || socialNum == "" || id == ""|| password == "") {
        cout << "양식에 맞게 입력하세요" << endl << endl; 
        return; 
    }

    signUpOk = signUpControl->addNewMember(name, socialNum, id, password);

    if (signUpOk == true) {
        out_fp << "> " << name << " " << socialNum << " " << id << " " << password << endl << endl;
        cout << "> " << name << " " << socialNum << " " << id << " " << password << endl << endl;
        return;
    }
    else {
        out_fp << "회원 가입 실패" << endl;
        cout << "회원 가입 실패" << endl;
        return;
    }

}