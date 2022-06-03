#include "Member.h"

extern Member* memberArry[MAX_MEMBER_NUM];
extern Member* loggedInMem;

/*SignUp*/
bool Member::checkId()
{
	for (int i = 0; i < MAX_MEMBER_NUM; i++) {
		if (!memberArry[i] == NULL) {
			if (this->memId == memberArry[i]->memId) {
				return false;
			}
		}
	}
	return true;
}
void Member::createNewMember()
{
	for (int i = 0; i < MAX_MEMBER_NUM; i++) {
		if (memberArry[i] == NULL) {
			this->arryNum = i;
			memberArry[i] = this;
			break;
		}
	}
}

/*Delete Account*/
string Member::deleteMember()
{
	string id = loggedInMem->memId;

	memberArry[this->arryNum] = NULL;
	loggedInMem = NULL;
	return id;
}

/*Login*/
bool Member::checkIdPw()
{
	for (int i = 0; i < MAX_MEMBER_NUM; i++) {
		if (!memberArry[i] == NULL) {
			if (this->memId == memberArry[i]->memId && this->memPassword == memberArry[i]->memPassword) {
				loggedInMem = memberArry[i];
				loggedInMem->arryNum = i;
				return true;
			}
		}
	}
	return false;
}

/*Logout*/
string Member::getId()
{
	return this->memId;
}

//void Member::addNewProductPurchase() {
//	for (int i = 0; i < MAX_MEMBER_NUM; i++) {
//		if (!memberArry[i] == NULL) {
//			if (this->memId == memberArry[i]->memId && this->memPassword == memberArry[i]->memPassword) {
//				loggedInMem = memberArry[i];
//				loggedInMem->arryNum = i;
//				return true;
//			}
//		}
//	}
//}