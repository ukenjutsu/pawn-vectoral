#include "SDK/plugin.h"
#include "CMultiMapNatives.h"
#include "MultiMap.h"
#include "Vector.h"
#include <sstream>
#include <stddef.h>
using namespace std;
extern AMX* global_amx;

std::map<AMX*,vector<CMultiMap> > multi_maps;

cell AMX_NATIVE_CALL CMultiMapNatives::l_multimap(AMX* amx, cell* params){
	multi_maps[amx].push_back(CMultiMap());
	return multi_maps[amx].size() -1;
}
extern string itos(int cfx);
extern string itos(float cfx);
/* =============== INSERT =============== */
/* Key Array */
cell AMX_NATIVE_CALL CMultiMapNatives::insert(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=1;
	return multi_maps[amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::insert_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=2;
	return multi_maps[amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::insert_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMultiMapItem c;
	c.itemstr=val;
	c.type=0;
	return multi_maps[amx][pawnid].insert(key,c);
}

/* Key Int */

cell AMX_NATIVE_CALL CMultiMapNatives::insert_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	
	CMultiMapItem c;
	c.item=val;
	c.type=1;
	return multi_maps[amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::insert_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=2;
	return multi_maps[amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::insert_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMultiMapItem c;
	c.itemstr=val;
	c.type=0;
	return multi_maps[amx][pawnid].insert(key,c);
}

/* Key Float */

cell AMX_NATIVE_CALL CMultiMapNatives::insert_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=1;
	return multi_maps[amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::insert_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=2;
	return multi_maps[amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::insert_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMultiMapItem c;
	c.itemstr=val;
	c.type=0;
	return multi_maps[amx][pawnid].insert(key,c);
}
/* =============== GET =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::get(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell id = params[3];
	if(!multi_maps[amx][pawnid].contains(key,id))
		return -1;

	return multi_maps[amx][pawnid].find(key,id).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell id = params[3];
	if(!multi_maps[amx][pawnid].contains(key,id))
		return -1;

	return multi_maps[amx][pawnid].find(key,id).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!multi_maps[amx][pawnid].contains(key))
		return -1;
	cell idx = params[3];
	cell size = params[5];
	cell* addr = NULL;
	amx_GetAddr(amx,params[4],&addr);
	amx_SetString(addr,multi_maps[amx][pawnid].find(key,idx).itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Int */
cell AMX_NATIVE_CALL CMultiMapNatives::get_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell size = params[5];
	cell* addr = NULL;
	amx_GetAddr(amx,params[4],&addr);
	amx_SetString(addr,multi_maps[amx][pawnid].find(key,idx).itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Float */
cell AMX_NATIVE_CALL CMultiMapNatives::get_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell size = params[5];
	cell* addr = NULL;
	amx_GetAddr(amx,params[4],&addr);
	amx_SetString(addr,multi_maps[amx][pawnid].find(key,idx).itemstr.c_str(),0,0,size);
	return 1;
}

/* =============== CONTAINS =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::contains(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	return multi_maps[amx][pawnid].contains(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::contains_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	return multi_maps[amx][pawnid].contains(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::contains_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	return multi_maps[amx][pawnid].contains(key,idx);
}

/* =============== GET_TYPE =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	return multi_maps[amx][pawnid].get_type(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_type_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	return multi_maps[amx][pawnid].get_type(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::get_type_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	return multi_maps[amx][pawnid].get_type(key,idx);
}
cell AMX_NATIVE_CALL CMultiMapNatives::clear(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	multi_maps[amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::size(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	return multi_maps[amx][pawnid].items.size();
}

/* =============== REMOVE =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::remove(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	if (idx == -1)
		multi_maps[amx][pawnid].items.erase(key);
	else
		multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].find(key,idx,true));
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::remove_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	if (idx == -1)
		multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].items.find(key));
	else
		multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].find(key,idx,true));
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::remove_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key))
		return -1;
	if (idx == -1)
		multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].items.find(key));
	else
		multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].find(key,idx,true));
	return 1;
}

/* =============== SWAP & EMPTY =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::swap(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell otherid = params[2];
	if(!sdk_is_map_exists(amx,pawnid) || !sdk_is_map_exists(amx,otherid))
		return -1;
	multi_maps[amx][pawnid].items.swap(multi_maps[amx][otherid].items);
	
	return 1;
}
cell AMX_NATIVE_CALL CMultiMapNatives::empty(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	return multi_maps[amx][pawnid].items.empty();
}

/* =============== COUNT =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::count(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!multi_maps[amx][pawnid].contains(key))
		return -1;
	return multi_maps[amx][pawnid].items.count(key);
}

cell AMX_NATIVE_CALL CMultiMapNatives::count_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!multi_maps[amx][pawnid].contains(key))
		return -1;
	return multi_maps[amx][pawnid].items.count(key);
}

cell AMX_NATIVE_CALL CMultiMapNatives::count_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!multi_maps[amx][pawnid].contains(key))
		return -1;
	return multi_maps[amx][pawnid].items.count(key);
}
/* =============== SET =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::set(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 1;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::set_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	char* item = NULL; amx_StrParam(amx,params[4],item);
	CMultiMapItem c;
	c.itemstr = item;
	c.type = 0;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::set_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 2;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}
/* Key Int */
cell AMX_NATIVE_CALL CMultiMapNatives::set_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 1;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::set_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	char* item = NULL; amx_StrParam(amx,params[4],item);
	CMultiMapItem c;
	c.itemstr = item;
	c.type = 0;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::set_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 2;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}
/* Key Float */
cell AMX_NATIVE_CALL CMultiMapNatives::set_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 1;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::set_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	char* item = NULL; amx_StrParam(amx,params[4],item);
	CMultiMapItem c;
	c.itemstr = item;
	c.type = 0;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::set_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 2;
	multi_maps[amx][pawnid].set(key,idx,c);
	return 1;
}
/* =============== SWAP KEY =============== */ // (Swap keysiz iyi �imdilik :P)
/* Key Str 
#ifndef cmulti
typedef multimap<string,CMultiMapItem> cmulti;
#endif
cell AMX_NATIVE_CALL CMultiMapNatives::swap_key(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	pair<cmulti::iterator,cmulti::iterator> c = multi_maps[amx][pawnid].items.equal_range(key);
	pair<cmulti::iterator,cmulti::iterator> c2 = multi_maps[amx][pawnid].items.equal_range(key2);
	
	//multi_maps[amx][pawnid].items.erase(key);
	//multi_maps[amx][pawnid].items.erase(key2);

	int size1 = multi_maps[amx][pawnid].items.count(key);
	int size2 = multi_maps[amx][pawnid].items.count(key2);

	for(cmulti::iterator it = c.first; it!=c.second; ++it){
		multi_maps[amx][pawnid].insert(key2,it->second);
	}
	for(cmulti::iterator it = c2.first; it!=c2.second; ++it){
		multi_maps[amx][pawnid].insert(key,it->second);
	}
	multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].items.find(key),multi_maps[amx][pawnid].find(key,size1,true));
	multi_maps[amx][pawnid].items.erase(multi_maps[amx][pawnid].items.find(key2),multi_maps[amx][pawnid].find(key2,size2,true));
	
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::swap_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	string key2 = itos(params[3]);
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::swap_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	string key2 = itos(amx_ctof(params[3]));
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}
// Key Int

cell AMX_NATIVE_CALL CMultiMapNatives::swap_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(params[2]);
	string key2 = itos(params[3]);
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::swap_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(params[2]);
	string key2 = itos(amx_ctof(params[3]));
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::swap_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(params[2]);
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}
// Key Float

cell AMX_NATIVE_CALL CMultiMapNatives::swap_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	string key2 = itos(amx_ctof(params[3]));
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::swap_key_float_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	string key2 = itos(params[3]);
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::swap_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!multi_maps[amx][pawnid].contains(key) || !multi_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = multi_maps[amx][pawnid].items[key];
	CMapItem c2 = multi_maps[amx][pawnid].items[key2];
	multi_maps[amx][pawnid].items[key]=c2;
	multi_maps[amx][pawnid].items[key2]=c;
	return 1;
}*/

/* SDK */
int CMultiMapNatives::sdk_is_map_exists(AMX* amx,unsigned int pawnvec){
	if (0<=pawnvec && pawnvec<multi_maps[amx].size())
		return 1;
	return 0;
}

void CMultiMapNatives::Unload(AMX* amx){
	multi_maps[amx].clear();
}


/* GLOBAL */
cell AMX_NATIVE_CALL CMultiMapNatives::g_multimap(AMX* amx, cell* params){
	multi_maps[global_amx].push_back(CMultiMap());
	return multi_maps[global_amx].size() -1;
}
/* =============== INSERT =============== */
/* Key Array */
cell AMX_NATIVE_CALL CMultiMapNatives::g_insert(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=1;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=2;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMultiMapItem c;
	c.itemstr=val;
	c.type=0;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

/* Key Int */

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	
	CMultiMapItem c;
	c.item=val;
	c.type=1;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=2;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMultiMapItem c;
	c.itemstr=val;
	c.type=0;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

/* Key Float */

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=1;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMultiMapItem c;
	c.item=val;
	c.type=2;
	return multi_maps[global_amx][pawnid].insert(key,c);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_insert_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMultiMapItem c;
	c.itemstr=val;
	c.type=0;
	return multi_maps[global_amx][pawnid].insert(key,c);
}
/* =============== GET =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_get(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell id = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,id))
		return -1;

	return multi_maps[global_amx][pawnid].find(key,id).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell id = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,id))
		return -1;

	return multi_maps[global_amx][pawnid].find(key,id).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!multi_maps[global_amx][pawnid].contains(key))
		return -1;
	cell idx = params[3];
	cell size = params[5];
	cell* addr = NULL;
	amx_GetAddr(amx,params[4],&addr);
	amx_SetString(addr,multi_maps[global_amx][pawnid].find(key,idx).itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Int */
cell AMX_NATIVE_CALL CMultiMapNatives::g_get_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[global_amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[global_amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell size = params[5];
	cell* addr = NULL;
	amx_GetAddr(amx,params[4],&addr);
	amx_SetString(addr,multi_maps[global_amx][pawnid].find(key,idx).itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Float */
cell AMX_NATIVE_CALL CMultiMapNatives::g_get_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[global_amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;

	return multi_maps[global_amx][pawnid].find(key,idx).item;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell size = params[5];
	cell* addr = NULL;
	amx_GetAddr(amx,params[4],&addr);
	amx_SetString(addr,multi_maps[global_amx][pawnid].find(key,idx).itemstr.c_str(),0,0,size);
	return 1;
}

/* =============== CONTAINS =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_contains(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	return multi_maps[global_amx][pawnid].contains(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_contains_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	return multi_maps[global_amx][pawnid].contains(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_contains_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	return multi_maps[global_amx][pawnid].contains(key,idx);
}

/* =============== GET_TYPE =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	return multi_maps[global_amx][pawnid].get_type(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_type_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	return multi_maps[global_amx][pawnid].get_type(key,idx);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_get_type_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	return multi_maps[global_amx][pawnid].get_type(key,idx);
}
cell AMX_NATIVE_CALL CMultiMapNatives::g_clear(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	multi_maps[global_amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_size(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	return multi_maps[global_amx][pawnid].items.size();
}

/* =============== REMOVE =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_remove(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	if (idx == -1)
		multi_maps[global_amx][pawnid].items.erase(key);
	else
		multi_maps[global_amx][pawnid].items.erase(multi_maps[global_amx][pawnid].find(key,idx,true));
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_remove_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	if (idx == -1)
		multi_maps[global_amx][pawnid].items.erase(multi_maps[global_amx][pawnid].items.find(key));
	else
		multi_maps[global_amx][pawnid].items.erase(multi_maps[global_amx][pawnid].find(key,idx,true));
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_remove_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key))
		return -1;
	if (idx == -1)
		multi_maps[global_amx][pawnid].items.erase(multi_maps[global_amx][pawnid].items.find(key));
	else
		multi_maps[global_amx][pawnid].items.erase(multi_maps[global_amx][pawnid].find(key,idx,true));
	return 1;
}

/* =============== SWAP & EMPTY =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_swap(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell otherid = params[2];
	if(!sdk_is_map_exists(global_amx,pawnid) || !sdk_is_map_exists(amx,otherid))
		return -1;
	multi_maps[global_amx][pawnid].items.swap(multi_maps[global_amx][otherid].items);
	
	return 1;
}
cell AMX_NATIVE_CALL CMultiMapNatives::g_empty(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	return multi_maps[global_amx][pawnid].items.empty();
}

/* =============== COUNT =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_count(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!multi_maps[global_amx][pawnid].contains(key))
		return -1;
	return multi_maps[global_amx][pawnid].items.count(key);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_count_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!multi_maps[global_amx][pawnid].contains(key))
		return -1;
	return multi_maps[global_amx][pawnid].items.count(key);
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_count_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!multi_maps[global_amx][pawnid].contains(key))
		return -1;
	return multi_maps[global_amx][pawnid].items.count(key);
}

/* =============== SET =============== */
cell AMX_NATIVE_CALL CMultiMapNatives::g_set(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 1;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_set_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	char* item = NULL; amx_StrParam(amx,params[4],item);
	CMultiMapItem c;
	c.itemstr = item;
	c.type = 0;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_set_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 2;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}
/* Key Int */
cell AMX_NATIVE_CALL CMultiMapNatives::g_set_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 1;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_set_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	char* item = NULL; amx_StrParam(amx,params[4],item);
	CMultiMapItem c;
	c.itemstr = item;
	c.type = 0;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_set_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 2;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}
/* Key Float */
cell AMX_NATIVE_CALL CMultiMapNatives::g_set_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 1;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_set_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	char* item = NULL; amx_StrParam(amx,params[4],item);
	CMultiMapItem c;
	c.itemstr = item;
	c.type = 0;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}

cell AMX_NATIVE_CALL CMultiMapNatives::g_set_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell idx = params[3];
	if(!multi_maps[global_amx][pawnid].contains(key,idx))
		return -1;
	cell item = params[4];
	CMultiMapItem c;
	c.item = item;
	c.type = 2;
	multi_maps[global_amx][pawnid].set(key,idx,c);
	return 1;
}
