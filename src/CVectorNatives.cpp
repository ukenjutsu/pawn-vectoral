#include "SDK/plugin.h"
#include "CVectorNatives.h"
//#include "Vector.h"
#include <stddef.h>
#include <algorithm>
#include "SortVector.h"
using namespace std;

typedef void (*logprintf_t)(char* format, ...);
extern logprintf_t logprintf;

AMX* global_amx = NULL;

map<AMX*,vector<CVector> > local_vectors;
//vector <CVector> global_vectors;

cell AMX_NATIVE_CALL CVectorNatives::vector(AMX* amx, cell* params){
	local_vectors[amx].push_back(CVector());
	return local_vectors[amx].size()-1;
}

cell AMX_NATIVE_CALL CVectorNatives::push_back_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_vectors[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::push_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_vectors[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::push_back_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_vectors[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::push_front_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_vectors[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::push_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	//local_vectors[amx][pawnid].push_front(c);
	local_vectors[amx][pawnid].items.insert(local_vectors[amx][pawnid].items.begin(),c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::push_front_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_vectors[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell itemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,itemid))
		return -1;
	return local_vectors[amx][pawnid].get_type(itemid);
}

cell AMX_NATIVE_CALL CVectorNatives::pop_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_vectors[amx][pawnid].pop_back();
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::pop_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	local_vectors[amx][pawnid].pop_back();
	std::reverse(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::clear(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_vectors[amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::size(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_vectors[amx][pawnid].items.size();
	
}

cell AMX_NATIVE_CALL CVectorNatives::capacity(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_vectors[amx][pawnid].items.capacity();
}

cell AMX_NATIVE_CALL CVectorNatives::empty(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_vectors[amx][pawnid].items.empty();
	
}

cell AMX_NATIVE_CALL CVectorNatives::resize(AMX* amx, cell* params){
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell size = params[2];
	cell flv = params[3];
	if (flv == -1){
		CItem c;
		c.item=0;
		c.type=1;
		local_vectors[amx][pawnid].items.resize(size,c);
	}
	else{
		CItem c;
		c.item=flv;
		c.type=1;
		local_vectors[amx][pawnid].items.resize(size,c);
	}
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::remove(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell remid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,remid))
		return -1;
	cell endid = params[3];
	if (endid == -1)
		local_vectors[amx][pawnid].items.erase(local_vectors[amx][pawnid].items.begin() + remid);
	else{
		if (!sdk_is_exists(amx,pawnid,endid))
			return -1;
		local_vectors[amx][pawnid].items.erase(local_vectors[amx][pawnid].items.begin() + remid, local_vectors[amx][pawnid].items.begin() + endid);
	}
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::swap(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell secondid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_vector_exists(amx,secondid))
		return -1;
	local_vectors[amx][pawnid].items.swap(local_vectors[amx][secondid].items);	
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::swap_index(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell elem1 = params[2];
	cell elem2 = params[3];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem1) || !sdk_is_exists(amx,pawnid,elem2))
		return -1;
	std::iter_swap(local_vectors[amx][pawnid].items.begin()+elem1,local_vectors[amx][pawnid].items.end()+elem2);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::reverse(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::get(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_vectors[amx][pawnid].get_type(elem) != 1)
		return -2;
	CItem items = local_vectors[amx][pawnid].items.at(elem);
	int item = (int)(items.item);
	return item;
}

cell AMX_NATIVE_CALL CVectorNatives::get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_vectors[amx][pawnid].get_type(elem) != 2)
		return -2;
	CItem items = local_vectors[amx][pawnid].items.at(elem);
	cell item = (cell)(items.item);
	return item;
}

cell AMX_NATIVE_CALL CVectorNatives::get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	
	if (local_vectors[amx][pawnid].get_type(elem) != 0)
		return -2;
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	cell size = params[4];
	CItem items = local_vectors[amx][pawnid].items.at(elem);
	amx_SetString(addr,items.itemstr.c_str(),0,0,size);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::shrink_to_fit(AMX* amx, cell* params){

	cell pawnid = params[1];
	//local_vectors[amx][pawnid].items.shrink_to_fit();
	std::vector<CItem> item(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	item.swap(local_vectors[amx][pawnid].items);
	local_vectors[amx][pawnid].items.clear();
	local_vectors[amx][pawnid].items = item;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::is_exists(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	return local_vectors[amx][pawnid].is_exists(elem);
}

cell AMX_NATIVE_CALL CVectorNatives::is_vector_exists(AMX* amx, cell* params){

	cell pawnid = params[1];
	return CVectorNatives::sdk_is_vector_exists(amx,pawnid);
}

cell AMX_NATIVE_CALL CVectorNatives::find(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -2;
	cell val = params[2];
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.item = val;
	item.type = 1;
	return local_vectors[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CVectorNatives::find_float(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -2;
	cell val = params[2];
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.item = val;
	item.type = 2;
	return local_vectors[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CVectorNatives::find_arr(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -2;
	char* itemstr = NULL;
	amx_StrParam(amx,params[2],itemstr);
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.itemstr = itemstr;
	item.type = 0;
	return local_vectors[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CVectorNatives::set_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	int elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[3],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_vectors[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::set(AMX* amx, cell* params){

	cell pawnid = params[1];
	int elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	int item = params[3];
	CItem c;
	c.item = item;
	c.type=1;
	local_vectors[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::set_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	cell item = params[3];
	CItem c;
	c.item = item;
	c.type=2;
	local_vectors[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::reserve(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	cell reserve_size = params[3];
	local_vectors[amx][pawnid].items.reserve(reserve_size);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::assign(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=1;
	local_vectors[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::assign_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=2;
	local_vectors[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::assign_arr(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=1;
	local_vectors[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::sort(AMX* amx, cell* params){
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* function = NULL;
	amx_StrParam(amx,params[2],function);

	SortVector sort_me(amx,(int)pawnid,function);
	sort_me.pawnid = pawnid;
	CItem temp;
	for(int nIter = local_vectors[amx][pawnid].items.size() -1;
			nIter > 0 ; nIter--){
		int nSmallest = 0;
		for(int nCurrent = 1;
				nCurrent <= nIter; nCurrent++){
			if (sort_me.compare(nCurrent,nSmallest)){
				nSmallest=nCurrent;
			}
		}
		//temp = local_vectors[amx][pawnid].items[nIter];
		//local_vectors[amx][pawnid].items[nIter] = local_vectors[amx][pawnid].items[nSmallest];
		//local_vectors[amx][pawnid].items[nSmallest] = temp;
		std::swap(local_vectors[amx][pawnid].items[nIter],local_vectors[amx][pawnid].items[nSmallest]);
	}
	return 1;
}
/* Global */

cell AMX_NATIVE_CALL CVectorNatives::global(AMX* amx, cell* params){
	local_vectors[global_amx].push_back(CVector());
	return local_vectors[global_amx].size()-1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_push_back_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	amx = global_amx;
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_vectors[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_push_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_vectors[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_push_back_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_vectors[amx][pawnid].push_back(c);
	return 1;
}


cell AMX_NATIVE_CALL CVectorNatives::g_push_front_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	amx = global_amx;
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_vectors[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_push_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_vectors[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_push_front_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_vectors[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell itemid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,itemid))
		return -1;
	return local_vectors[amx][pawnid].get_type(itemid);
}

cell AMX_NATIVE_CALL CVectorNatives::g_pop_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_vectors[amx][pawnid].pop_back();
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_pop_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	local_vectors[amx][pawnid].pop_back();
	std::reverse(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_clear(AMX* amx, cell* params){
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_vectors[amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_size(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_vectors[amx][pawnid].items.size();
	
}

cell AMX_NATIVE_CALL CVectorNatives::g_capacity(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_vectors[amx][pawnid].items.capacity();
	return -1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_empty(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_vectors[amx][pawnid].items.empty();
	
}

cell AMX_NATIVE_CALL CVectorNatives::g_resize(AMX* amx, cell* params){
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell size = params[2];
	cell flv = params[3];
	if (flv == -1){
		CItem c;
		c.item=0;
		c.type=1;
		local_vectors[amx][pawnid].items.resize(size,c);
	}
	else{
		CItem c;
		c.item=flv;
		c.type=1;
		local_vectors[amx][pawnid].items.resize(size,c);
	}
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_remove(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell remid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,remid))
		return -1;
	cell endid = params[3];
	if (endid == -1)
		local_vectors[amx][pawnid].items.erase(local_vectors[amx][pawnid].items.begin() + remid);
	else{
		if (!sdk_is_exists(amx,pawnid,endid))
			return -1;
		local_vectors[amx][pawnid].items.erase(local_vectors[amx][pawnid].items.begin() + remid, local_vectors[amx][pawnid].items.begin() + endid);
	}
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_swap(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell secondid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_vector_exists(amx,secondid))
		return -1;
	local_vectors[amx][pawnid].items.swap(local_vectors[amx][secondid].items);	
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_swap_index(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell elem1 = params[2];
	cell elem2 = params[3];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem1) || !sdk_is_exists(amx,pawnid,elem2))
		return -1;
	iter_swap(local_vectors[amx][pawnid].items.begin()+elem1,local_vectors[amx][pawnid].items.begin()+elem2);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_reverse(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_get(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_vectors[amx][pawnid].get_type(elem) != 1)
		return -2;
	CItem items = local_vectors[amx][pawnid].items.at(elem);
	int item = (int)(items.item);
	return item;
}

cell AMX_NATIVE_CALL CVectorNatives::g_get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_vectors[amx][pawnid].get_type(elem) != 2)
		return -2;
	CItem items = local_vectors[amx][pawnid].items.at(elem);
	cell item = items.item;
	return item;
}

cell AMX_NATIVE_CALL CVectorNatives::g_get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid) || !sdk_is_exists(global_amx,pawnid,elem))
		return -1;
	
	if (local_vectors[global_amx][pawnid].get_type(elem) != 0)
		return -2;
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	cell size = params[4];
	CItem items = local_vectors[global_amx][pawnid].items.at(elem);
	amx_SetString(addr,items.itemstr.c_str(),0,0,size);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_shrink_to_fit(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	//local_vectors[amx][pawnid].items.shrink_to_fit();
	std::vector<CItem> item(local_vectors[amx][pawnid].items.begin(),local_vectors[amx][pawnid].items.end());
	item.swap(local_vectors[amx][pawnid].items);
	local_vectors[amx][pawnid].items.clear();
	local_vectors[amx][pawnid].items = item;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_is_exists(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	amx = global_amx;
	return local_vectors[amx][pawnid].is_exists(elem);
}

cell AMX_NATIVE_CALL CVectorNatives::g_is_vector_exists(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	return CVectorNatives::sdk_is_vector_exists(amx,pawnid);
}

cell AMX_NATIVE_CALL CVectorNatives::g_find(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -2;
	
	cell val = params[2];
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.item = val;
	item.type = 1;
	return local_vectors[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CVectorNatives::g_find_float(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -2;
	cell val = params[2];
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.item = val;
	item.type = 2;
	return local_vectors[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CVectorNatives::g_find_arr(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -2;
	char* itemstr = NULL;
	amx_StrParam(amx,params[2],itemstr);
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.itemstr = itemstr;
	item.type = 0;
	return local_vectors[global_amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CVectorNatives::g_set_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	int elemid = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid) || !sdk_is_exists(global_amx,pawnid,elemid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[3],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_vectors[global_amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_set(AMX* amx, cell* params){

	cell pawnid = params[1];
	int elemid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	int item = params[3];
	CItem c;
	c.item = item;
	c.type=1;
	local_vectors[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_set_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell elemid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	cell item = params[3];
	CItem c;
	c.item = item;
	c.type=2;
	local_vectors[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_reserve(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	cell reserve_size = params[3];
	local_vectors[amx][pawnid].items.reserve(reserve_size);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_assign(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	amx=global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=1;
	local_vectors[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_assign_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=2;
	local_vectors[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_assign_arr(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=1;
	local_vectors[global_amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CVectorNatives::g_sort(AMX* amx, cell* params){
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* function = NULL;
	amx_StrParam(amx,params[2],function);

	SortVector sort_me(amx,(int)pawnid,function);
	sort_me.pawnid = pawnid;
	CItem temp;
	for(int nIter = local_vectors[global_amx][pawnid].items.size() -1;
			nIter > 0 ; nIter--){
		int nSmallest = 0;
		for(int nCurrent = 1;
				nCurrent <= nIter; nCurrent++){
			if (sort_me.compare(nCurrent,nSmallest)){
				nSmallest=nCurrent;
			}
		}
		//temp = local_vectors[amx][pawnid].items[nIter];
		//local_vectors[amx][pawnid].items[nIter] = local_vectors[amx][pawnid].items[nSmallest];
		//local_vectors[amx][pawnid].items[nSmallest] = temp;
		std::swap(local_vectors[global_amx][pawnid].items[nIter],local_vectors[global_amx][pawnid].items[nSmallest]);
	}
	return 1;
}






/* SDK */
int CVectorNatives::sdk_is_vector_exists(AMX* amx,unsigned int pawnvec){
	if (0<=pawnvec && pawnvec<local_vectors[amx].size())
		return 1;
	return 0;
}

int CVectorNatives::sdk_is_exists(AMX* amx,int pawnvec,int elem){
	return local_vectors[amx][pawnvec].is_exists(elem);
}


void CVectorNatives::Unload(AMX* amx){
	local_vectors[amx].clear();
	std::vector<CVector> item(local_vectors[amx].begin(),local_vectors[amx].end());
	item.swap(local_vectors[amx]);
	local_vectors[amx].clear();
	local_vectors[amx] = item;
}
