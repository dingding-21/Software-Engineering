#include "common.h"
#include "Product.h"
#define MAX_MEMBER_NUM 1000
#define MAX_PRODUCT_NUM 1000

class Member
{
private:
    string memName;
    string memSocialNum;
    string memId;
    string memPassword;
    int purchaseProductList[MAX_PRODUCT_NUM];
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
    Member(string id) {
        this->memId = id;
    }

    bool checkId();
    bool checkIdPw();
    void createNewMember();
    void addNewProductPurchase();

    string deleteMember();
    string getId();
};

