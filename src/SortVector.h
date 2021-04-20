#include "SDK/plugin.h"
#include <string>
using namespace std;
class SortVector{
public:
	AMX* amx;
	string funcName;
	int pawnid;
	SortVector(AMX* amx,int pawnid, string funcName);
	~SortVector();
	bool compare (int firstidx,int secondidx);
};