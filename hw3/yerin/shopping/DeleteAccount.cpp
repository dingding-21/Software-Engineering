#include "DeleteAccount.h"
#include "Member.h"


extern Member* loggedInMem;

string DeleteAccount::deleteAccount()
{
	if (loggedInMem == NULL)
		return "";
	else {
		return loggedInMem->deleteMember();
	}
}