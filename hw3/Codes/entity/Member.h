#include "../common.h"
#include "Product.h"
#define MAX_MEMBER_NUM 1000

class Member
{
private:
    string memName;
    string memSocialNum;
    string memId;
    string memPassword;
    int arryNum;
public:
    Member(string name, string socialNum, string id, string password) {
       this->memName = name;
       this->memSocialNum = socialNum;
       this->memId = id;
       this->memPassword = password;
    }
    Member(string id, string password) {
        this->memId = id;
        this->memPassword = password;
    }

    bool checkId();
    bool checkIdPw();
    void createNewMember();
    string deleteMember();
    string getId();
};

