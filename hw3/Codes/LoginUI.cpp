#include "./classes/Login.h"
#include "./classes/LoginUI.h"

extern ifstream in_fp;
extern ofstream out_fp;
extern Login* loginControl;

void LoginUI::startInterface()
{
    out_fp << "2.1. �α���" << endl;
    cout << "2.1. �α���" << endl;
}

void LoginUI::enterIdPw()
{
    string line;
    string word;

    string id = "";
    string password = "";
    bool loginOk = false;
       
    // �Է� ���� : ID, Password�� ���Ϸκ��� ����
    getline(in_fp, line);

    stringstream ss(line);
    ss.str(line);

    ss >> id; ss >> password;

    if (id == "" || password == "") {
        cout << "��Ŀ� �°� �Է��ϼ���" << endl << endl;
        return;
    }

    loginOk = loginControl->checkIdPw(id, password);

    if (loginOk == true) {
        // ���� �� ��� ���
        out_fp << "> " << id << " " << password << endl << endl;
        cout << "> " << id << " " << password << endl << endl;
    }
    else {
        out_fp << "> �α��ο� �����Ͽ����ϴ�." << endl << endl;
        cout << "> �α��ο� �����Ͽ����ϴ�." << endl << endl;
    }
}