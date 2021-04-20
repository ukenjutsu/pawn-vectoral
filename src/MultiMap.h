#include "SDK/plugin.h"
#include <vector>
#include <map>
#include <string>
using namespace std;
struct CMultiMapItem{
	//void* item;
	cell item;
	string itemstr;
	int type;
};

class CMultiMap{
public:
	CMultiMap();
	~CMultiMap();
	multimap<string,CMultiMapItem> items;
	int insert(string key,CMultiMapItem item);
	void set(string key, int idx, CMultiMapItem item);
	void clear();
	int get_type(string key,int idx);
	CMultiMapItem find(string key,int idx);
	multimap<string,CMultiMapItem>::iterator find(string key,int idx,bool iter);
	int contains(string key,int idx=-1);
};
