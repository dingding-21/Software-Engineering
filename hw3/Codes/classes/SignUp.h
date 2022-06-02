#include "../common.h"
#include "SignUpUI.h"

class SignUp {
private:
public:
    SignUp()
    {
        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->startInterface();
    }
    bool addNewMember(string name, string socialNum, string id, string password);

};

 