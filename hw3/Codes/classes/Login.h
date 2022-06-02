#include "../common.h"
#include "LoginUI.h"


class Login
{
private:
public:
    Login()
    {
        LoginUI* loginUI = new LoginUI;
        loginUI->startInterface();
    }
    bool checkIdPw(string id, string pw);
};

