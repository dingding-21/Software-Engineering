#include "../common.h"
#include "LogoutUI.h"

class Logout {
private:
public:
    Logout()
    {
        LogoutUI* logoutUI = new LogoutUI;
        logoutUI->startInterface();
    }

    string logoutReq();
};
