#include "Login.h"
#include "Member.h"

bool Login::checkIdPw(string id, string pw) {

	Member* member = new Member(id, pw);
	bool checkMember = false;

	checkMember = member->checkIdPw();

	return checkMember;
	
}