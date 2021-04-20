#include "SDK/plugin.h"
#include <vector>
#include <map>
#include <string>
using namespace std;
struct CMapItem{
	//void* item;
	cell item;
	string itemstr;
	int type;
};

class CMap{
public:
	CMap();
	~CMap();
	map<string,CMapItem> items;
	void insert(string key,CMapItem item);
	void clear();
	int get_type(string key);
	int contains(string key);
};
