#include "Logout.h"
#include "Member.h"

extern Member* loggedInMem;

string Logout::logoutReq()
{
	string id = "";
	if (!loggedInMem == NULL) {
		id = loggedInMem->getId();
		loggedInMem = NULL;
		return id;
	}
	return id;
}