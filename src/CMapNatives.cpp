#include "SDK/plugin.h"
#include "CMapNatives.h"
#include "CMap.h"
#include "Vector.h"

#include <sstream>
#include <stddef.h>
using namespace std;
extern AMX* global_amx;
std::map<AMX*,vector<CMap> > local_maps;

cell AMX_NATIVE_CALL CMapNatives::l_map(AMX* amx, cell* params){
	local_maps[amx].push_back(CMap());
	return local_maps[amx].size() -1;
}
string itos(int cfx){
	stringstream is; is<<cfx;
	return is.str();
}

string itos(float cfx){
	stringstream is; is<<cfx;
	return is.str();
}
/* =============== INSERT =============== */
/* Key Array */
cell AMX_NATIVE_CALL CMapNatives::insert(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=1;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::insert_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=2;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::insert_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMapItem c;
	c.itemstr=val;
	c.type=0;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

/* Key Int */

cell AMX_NATIVE_CALL CMapNatives::insert_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	
	CMapItem c;
	c.item=val;
	c.type=1;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::insert_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=2;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::insert_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMapItem c;
	c.itemstr=val;
	c.type=0;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

/* Key Float */

cell AMX_NATIVE_CALL CMapNatives::insert_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=1;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::insert_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=2;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::insert_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMapItem c;
	c.itemstr=val;
	c.type=0;
	local_maps[amx][pawnid].insert(key,c);
	return 1;
}
/* =============== GET =============== */
cell AMX_NATIVE_CALL CMapNatives::get(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;

	return local_maps[amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;

	return local_maps[amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	cell size = params[4];
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	amx_SetString(addr,local_maps[amx][pawnid].items[key].itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Int */
cell AMX_NATIVE_CALL CMapNatives::get_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;

	return local_maps[amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::get_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;

	return local_maps[amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::get_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	cell size = params[4];
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	amx_SetString(addr,local_maps[amx][pawnid].items[key].itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Float */
cell AMX_NATIVE_CALL CMapNatives::get_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[amx][pawnid].contains(key))
		return -1;

	return local_maps[amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::get_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[amx][pawnid].contains(key))
		return -1;

	return local_maps[amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::get_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	cell size = params[4];
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	amx_SetString(addr,local_maps[amx][pawnid].items[key].itemstr.c_str(),0,0,size);
	return 1;
}

/* =============== CONTAINS =============== */
cell AMX_NATIVE_CALL CMapNatives::contains(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	return local_maps[amx][pawnid].contains(key);
}

cell AMX_NATIVE_CALL CMapNatives::contains_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	return local_maps[amx][pawnid].contains(key);
}

cell AMX_NATIVE_CALL CMapNatives::contains_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	return local_maps[amx][pawnid].contains(key);
}

/* =============== GET_TYPE =============== */
cell AMX_NATIVE_CALL CMapNatives::get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	return local_maps[amx][pawnid].get_type(key);
}

cell AMX_NATIVE_CALL CMapNatives::get_type_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	return local_maps[amx][pawnid].get_type(key);
}

cell AMX_NATIVE_CALL CMapNatives::get_type_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	return local_maps[amx][pawnid].get_type(key);
}
/* =============== CLEAR & SIZE =============== */
cell AMX_NATIVE_CALL CMapNatives::clear(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	local_maps[amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::size(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	return local_maps[amx][pawnid].items.size();
}
/* =============== REMOVE =============== */
cell AMX_NATIVE_CALL CMapNatives::remove(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	local_maps[amx][pawnid].items.erase(local_maps[amx][pawnid].items.find(key));
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::remove_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	local_maps[amx][pawnid].items.erase(local_maps[amx][pawnid].items.find(key));
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::remove_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[amx][pawnid].contains(key))
		return -1;
	local_maps[amx][pawnid].items.erase(local_maps[amx][pawnid].items.find(key));
	return 1;
}

/* =============== SWAP & EMPTY =============== */
cell AMX_NATIVE_CALL CMapNatives::swap(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell otherid = params[2];
	if(!sdk_is_map_exists(amx,pawnid) || !sdk_is_map_exists(amx,otherid))
		return -1;
	local_maps[amx][pawnid].items.swap(local_maps[amx][otherid].items);
	return 1;
}
cell AMX_NATIVE_CALL CMapNatives::empty(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	return local_maps[amx][pawnid].items.empty();
}

/* =============== SWAP KEY =============== */
/* Key Str */

cell AMX_NATIVE_CALL CMapNatives::swap_key(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::swap_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	string key2 = itos((int)params[3]);
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::swap_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	string key2 = itos(amx_ctof(params[3]));
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}


/* Key Int */

cell AMX_NATIVE_CALL CMapNatives::swap_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	string key2 = itos((int)params[3]);
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::swap_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	string key2 = itos(amx_ctof(params[3]));
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::swap_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

/* Key Float */

cell AMX_NATIVE_CALL CMapNatives::swap_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	string key2 = itos(amx_ctof(params[3]));
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::swap_key_float_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	string key2 = itos((int)params[3]);
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::swap_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!local_maps[amx][pawnid].contains(key) || !local_maps[amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[amx][pawnid].items[key];
	CMapItem c2 = local_maps[amx][pawnid].items[key2];
	local_maps[amx][pawnid].items[key]=c2;
	local_maps[amx][pawnid].items[key2]=c;
	return 1;
}


/* SDK */
int CMapNatives::sdk_is_map_exists(AMX* amx,unsigned int pawnvec){
	if (0<=pawnvec && pawnvec<local_maps[amx].size())
		return 1;
	return 0;
}

void CMapNatives::Unload(AMX* amx){
	local_maps[amx].clear();
}

/* GLOBAL */
cell AMX_NATIVE_CALL CMapNatives::g_map(AMX* amx, cell* params){
	amx=global_amx;
	local_maps[global_amx].push_back(CMap());
	return local_maps[global_amx].size() -1;
}

/* =============== INSERT =============== */
/* Key Array */
cell AMX_NATIVE_CALL CMapNatives::g_insert(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=1;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_insert_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=2;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_insert_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMapItem c;
	c.itemstr=val;
	c.type=0;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

/* Key Int */

cell AMX_NATIVE_CALL CMapNatives::g_insert_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	
	CMapItem c;
	c.item=val;
	c.type=1;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_insert_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=2;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_insert_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMapItem c;
	c.itemstr=val;
	c.type=0;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

/* Key Float */

cell AMX_NATIVE_CALL CMapNatives::g_insert_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=1;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_insert_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	cell val = params[3];
	CMapItem c;
	c.item=val;
	c.type=2;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_insert_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* val = NULL; amx_StrParam(amx,params[3],val);
	CMapItem c;
	c.itemstr=val;
	c.type=0;
	local_maps[global_amx][pawnid].insert(key,c);
	return 1;
}
/* =============== GET =============== */
cell AMX_NATIVE_CALL CMapNatives::g_get(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;

	return local_maps[global_amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::g_get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;

	return local_maps[global_amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::g_get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	cell size = params[4];
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	amx_SetString(addr,local_maps[global_amx][pawnid].items[key].itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Int */
cell AMX_NATIVE_CALL CMapNatives::g_get_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;

	return local_maps[global_amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::g_get_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;

	return local_maps[global_amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::g_get_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	cell size = params[4];
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	amx_SetString(addr,local_maps[global_amx][pawnid].items[key].itemstr.c_str(),0,0,size);
	return 1;
}

/* Key Float */
cell AMX_NATIVE_CALL CMapNatives::g_get_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;

	return local_maps[global_amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::g_get_key_float_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;

	return local_maps[global_amx][pawnid].items[key].item;
}

cell AMX_NATIVE_CALL CMapNatives::g_get_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	cell size = params[4];
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	amx_SetString(addr,local_maps[global_amx][pawnid].items[key].itemstr.c_str(),0,0,size);
	return 1;
}

/* =============== CONTAINS =============== */
cell AMX_NATIVE_CALL CMapNatives::g_contains(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	return local_maps[global_amx][pawnid].contains(key);
}

cell AMX_NATIVE_CALL CMapNatives::g_contains_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	return local_maps[global_amx][pawnid].contains(key);
}

cell AMX_NATIVE_CALL CMapNatives::g_contains_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	return local_maps[global_amx][pawnid].contains(key);
}

/* =============== GET_TYPE =============== */
cell AMX_NATIVE_CALL CMapNatives::g_get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	return local_maps[global_amx][pawnid].get_type(key);
}

cell AMX_NATIVE_CALL CMapNatives::g_get_type_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	return local_maps[global_amx][pawnid].get_type(key);
}

cell AMX_NATIVE_CALL CMapNatives::g_get_type_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	return local_maps[global_amx][pawnid].get_type(key);
}
/* =============== CLEAR & SIZE =============== */
cell AMX_NATIVE_CALL CMapNatives::g_clear(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	local_maps[global_amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_size(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	return local_maps[global_amx][pawnid].items.size();
}
/* =============== REMOVE =============== */
cell AMX_NATIVE_CALL CMapNatives::g_remove(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	local_maps[global_amx][pawnid].items.erase(local_maps[global_amx][pawnid].items.find(key));
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_remove_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	local_maps[global_amx][pawnid].items.erase(local_maps[global_amx][pawnid].items.find(key));
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_remove_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	if(!local_maps[global_amx][pawnid].contains(key))
		return -1;
	local_maps[global_amx][pawnid].items.erase(local_maps[global_amx][pawnid].items.find(key));
	return 1;
}

/* =============== SWAP & EMPTY =============== */
cell AMX_NATIVE_CALL CMapNatives::g_swap(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell otherid = params[2];
	if(!sdk_is_map_exists(global_amx,pawnid) || !sdk_is_map_exists(amx,otherid))
		return -1;
	local_maps[global_amx][pawnid].items.swap(local_maps[global_amx][otherid].items);
	return 1;
}
cell AMX_NATIVE_CALL CMapNatives::g_empty(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	return local_maps[global_amx][pawnid].items.empty();
}

/* =============== SWAP KEY =============== */
/* Key Str */

cell AMX_NATIVE_CALL CMapNatives::g_swap_key(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_swap_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	string key2 = itos((int)params[3]);
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_swap_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	char* key = NULL; amx_StrParam(amx,params[2],key);
	string key2 = itos(amx_ctof(params[3]));
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}


/* Key Int */

cell AMX_NATIVE_CALL CMapNatives::g_swap_key_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	string key2 = itos((int)params[3]);
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_swap_key_int_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	string key2 = itos(amx_ctof(params[3]));
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_swap_key_int_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos((int)params[2]);
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

/* Key Float */

cell AMX_NATIVE_CALL CMapNatives::g_swap_key_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	string key2 = itos(amx_ctof(params[3]));
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_swap_key_float_int(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	string key2 = itos((int)params[3]);
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}

cell AMX_NATIVE_CALL CMapNatives::g_swap_key_float_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	if(!sdk_is_map_exists(global_amx,pawnid))
		return -1;
	string key = itos(amx_ctof(params[2]));
	char* key2 = NULL; amx_StrParam(amx,params[3],key2);
	if(!local_maps[global_amx][pawnid].contains(key) || !local_maps[global_amx][pawnid].contains(key2))
		return -1;
	CMapItem c = local_maps[global_amx][pawnid].items[key];
	CMapItem c2 = local_maps[global_amx][pawnid].items[key2];
	local_maps[global_amx][pawnid].items[key]=c2;
	local_maps[global_amx][pawnid].items[key2]=c;
	return 1;
}
