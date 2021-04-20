#include "SDK/plugin.h"
#include <vector>
#include<string>
using namespace std;
struct CItem{
	//void* item;
	cell item;
	string itemstr;
	int type;
};
class CVector{
public:
	CVector();
	~CVector();
	vector<CItem> items;
	void push_back(CItem item);
	void push_front(CItem item);
	void pop_back();
	void clear();
	int get_type(int id);
	int find(CItem item,unsigned int fromItem=0,int endItem=-1);
	int is_exists(unsigned int cid);
};
