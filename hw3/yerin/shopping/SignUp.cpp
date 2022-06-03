#include "SignUp.h"
#include "Member.h"

bool SignUp::addNewMember(string name, string socialNum, string id, string password)
{
	Member* member = new Member(name,socialNum,id, password);
	bool idCheck;


	idCheck = member->checkId();

	if (idCheck == true) {
		member->createNewMember();
		return true;
	}
	else {
		return false;
	}
}