#include "./classes/SignUpUI.h"
#include "./classes/SignUp.h"

extern ifstream in_fp;
extern ofstream out_fp;
extern SignUp* signUpControl;

// ȸ������ SignUp
void SignUpUI::startInterface() 
{ 
    out_fp << "1.1. ȸ������" << endl;
    cout << "1.1. ȸ������" << endl;
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

    // �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> name; ss >> socialNum;
    ss >> id; ss >> password;

    if (name == "" || socialNum == "" || id == ""|| password == "") {
        cout << "��Ŀ� �°� �Է��ϼ���" << endl << endl; 
        return; 
    }

    signUpOk = signUpControl->addNewMember(name, socialNum, id, password);

    if (signUpOk == true) {
        out_fp << "> " << name << " " << socialNum << " " << id << " " << password << endl << endl;
        cout << "> " << name << " " << socialNum << " " << id << " " << password << endl << endl;
        return;
    }
    else {
        out_fp << "ȸ�� ���� ����" << endl;
        cout << "ȸ�� ���� ����" << endl;
        return;
    }

}