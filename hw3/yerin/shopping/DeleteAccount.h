#include "common.h"
#include "DeleteAccountUI.h"

class DeleteAccount {
private:
public:
    DeleteAccount()
    {
        DeleteAccountUI* deleteAccountUI = new DeleteAccountUI;
        deleteAccountUI->startInterface();
    }
    string deleteAccount();
};