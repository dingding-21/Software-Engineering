#include "./classes/Logout.h"
#include "./entity/Member.h"

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