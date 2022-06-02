#include "./classes/DeleteAccount.h"
#include "./entity/Member.h"


extern Member* loggedInMem;

string DeleteAccount::deleteAccount()
{
	if (loggedInMem == NULL)
		return "";
	else {
		return loggedInMem->deleteMember();
	}

}