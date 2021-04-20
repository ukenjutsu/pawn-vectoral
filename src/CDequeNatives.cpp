#include "SDK/plugin.h"
#include "CDequeNatives.h"
#include "Deque.h"
#include "SortVector.h"
#include <stddef.h>
#include <deque>
#include <algorithm>
using namespace std;

extern AMX* global_amx;

map<AMX*,vector<CDeque> > local_deques;
//vector <CDeque> global_vectors;

cell AMX_NATIVE_CALL CDequeNatives::deque(AMX* amx, cell* params){
	local_deques[amx].push_back(CDeque());
	return local_deques[amx].size()-1;
}

cell AMX_NATIVE_CALL CDequeNatives::push_back_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_deques[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::push_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_deques[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::push_back_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_deques[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::push_front_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_deques[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::push_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_deques[amx][pawnid].push_front(c);
	//local_deques[amx][pawnid].items.insert(local_deques[amx][pawnid].items.begin(),c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::push_front_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_deques[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell itemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,itemid))
		return -1;
	return local_deques[amx][pawnid].get_type(itemid);
}

cell AMX_NATIVE_CALL CDequeNatives::pop_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_deques[amx][pawnid].pop_back();
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::pop_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	local_deques[amx][pawnid].pop_back();
	std::reverse(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::clear(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_deques[amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::size(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_deques[amx][pawnid].items.size();
	
}

cell AMX_NATIVE_CALL CDequeNatives::empty(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_deques[amx][pawnid].items.empty();
	
}

cell AMX_NATIVE_CALL CDequeNatives::resize(AMX* amx, cell* params){
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell size = params[2];
	cell flv = params[3];
	if (flv == -1){
		CItem c;
		c.item=0;
		c.type=1;
		local_deques[amx][pawnid].items.resize(size,c);
	}
	else{
		CItem c;
		c.item=flv;
		c.type=1;
		local_deques[amx][pawnid].items.resize(size,c);
	}
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::remove(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell remid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,remid))
		return -1;
	cell endid = params[3];
	if (endid == -1)
		local_deques[amx][pawnid].items.erase(local_deques[amx][pawnid].items.begin() + remid);
	else{
		if (!sdk_is_exists(amx,pawnid,endid))
			return -1;
		local_deques[amx][pawnid].items.erase(local_deques[amx][pawnid].items.begin() + remid, local_deques[amx][pawnid].items.begin() + endid);
	}
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::swap(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell secondid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_vector_exists(amx,secondid))
		return -1;
	local_deques[amx][pawnid].items.swap(local_deques[amx][secondid].items);	
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::swap_index(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell elem1 = params[2];
	cell elem2 = params[3];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem1) || !sdk_is_exists(amx,pawnid,elem2))
		return -1;
	std::iter_swap(local_deques[amx][pawnid].items.begin()+elem1,local_deques[amx][pawnid].items.end()+elem2);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::reverse(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::get(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_deques[amx][pawnid].get_type(elem) != 1)
		return -2;
	CItem items = local_deques[amx][pawnid].items.at(elem);
	int item = (int)(items.item);
	return item;
}

cell AMX_NATIVE_CALL CDequeNatives::get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_deques[amx][pawnid].get_type(elem) != 2)
		return -2;
	CItem items = local_deques[amx][pawnid].items.at(elem);
	cell item = (cell)(items.item);
	return item;
}

cell AMX_NATIVE_CALL CDequeNatives::get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	
	if (local_deques[amx][pawnid].get_type(elem) != 0)
		return -2;
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	cell size = params[4];
	CItem items = local_deques[amx][pawnid].items.at(elem);
	amx_SetString(addr,items.itemstr.c_str(),0,0,size);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::shrink_to_fit(AMX* amx, cell* params){

	cell pawnid = params[1];
	//local_deques[amx][pawnid].items.shrink_to_fit();
	std::deque<CItem> item(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	item.swap(local_deques[amx][pawnid].items);
	local_deques[amx][pawnid].items.clear();
	local_deques[amx][pawnid].items = item;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::is_exists(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	return local_deques[amx][pawnid].is_exists(elem);
}

cell AMX_NATIVE_CALL CDequeNatives::is_vector_exists(AMX* amx, cell* params){

	cell pawnid = params[1];
	return CDequeNatives::sdk_is_vector_exists(amx,pawnid);
}

cell AMX_NATIVE_CALL CDequeNatives::find(AMX* amx, cell* params){

	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -2;
	cell val = params[2];
	cell from = params[3];
	cell end = params[4];
	CItem item;
	item.item = val;
	item.type = 1;
	return local_deques[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CDequeNatives::find_float(AMX* amx, cell* params){

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
	return local_deques[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CDequeNatives::find_arr(AMX* amx, cell* params){

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
	return local_deques[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CDequeNatives::set_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	int elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[3],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_deques[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::set(AMX* amx, cell* params){

	cell pawnid = params[1];
	int elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	int item = params[3];
	CItem c;
	c.item = item;
	c.type=1;
	local_deques[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::set_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell elemid = params[2];
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	cell item = params[3];
	CItem c;
	c.item = item;
	c.type=2;
	local_deques[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::assign(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=1;
	local_deques[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::assign_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=2;
	local_deques[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::assign_arr(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=1;
	local_deques[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::sort(AMX* amx, cell* params){
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	char* function = NULL;
	amx_StrParam(amx,params[2],function);

	SortVector sort_me(amx,(int)pawnid,function);
	
	sort_me.pawnid = pawnid;
	CItem temp;
	for(int nIter = local_deques[amx][pawnid].items.size() -1;
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
		std::swap(local_deques[amx][pawnid].items[nIter],local_deques[amx][pawnid].items[nSmallest]);
	}
	return 1;
}
/* Global */

cell AMX_NATIVE_CALL CDequeNatives::global(AMX* amx, cell* params){
	local_deques[global_amx].push_back(CDeque());
	return local_deques[global_amx].size()-1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_push_back_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	amx = global_amx;
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_deques[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_push_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_deques[amx][pawnid].push_back(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_push_back_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_deques[amx][pawnid].push_back(c);
	return 1;
}


cell AMX_NATIVE_CALL CDequeNatives::g_push_front_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	amx = global_amx;
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_deques[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_push_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	int item = params[2];
	CItem c;
	c.item = item;
	c.type=1;
	local_deques[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_push_front_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell item = params[2];
	CItem c;
	c.item = item;
	c.type=2;
	local_deques[amx][pawnid].push_front(c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_get_type(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell itemid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,itemid))
		return -1;
	return local_deques[amx][pawnid].get_type(itemid);
}

cell AMX_NATIVE_CALL CDequeNatives::g_pop_back(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_deques[amx][pawnid].pop_back();
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_pop_front(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	local_deques[amx][pawnid].pop_back();
	std::reverse(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_clear(AMX* amx, cell* params){
	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	local_deques[amx][pawnid].clear();
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_size(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_deques[amx][pawnid].items.size();
	
}

cell AMX_NATIVE_CALL CDequeNatives::g_empty(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	return local_deques[amx][pawnid].items.empty();
	
}

cell AMX_NATIVE_CALL CDequeNatives::g_resize(AMX* amx, cell* params){
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
		local_deques[amx][pawnid].items.resize(size,c);
	}
	else{
		CItem c;
		c.item=flv;
		c.type=1;
		local_deques[amx][pawnid].items.resize(size,c);
	}
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_remove(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell remid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,remid))
		return -1;
	cell endid = params[3];
	if (endid == -1)
		local_deques[amx][pawnid].items.erase(local_deques[amx][pawnid].items.begin() + remid);
	else{
		if (!sdk_is_exists(amx,pawnid,endid))
			return -1;
		local_deques[amx][pawnid].items.erase(local_deques[amx][pawnid].items.begin() + remid, local_deques[amx][pawnid].items.begin() + endid);
	}
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_swap(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell secondid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_vector_exists(amx,secondid))
		return -1;
	local_deques[amx][pawnid].items.swap(local_deques[amx][secondid].items);	
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_swap_index(AMX* amx, cell* params){

	cell pawnid = params[1];
	cell elem1 = params[2];
	cell elem2 = params[3];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem1) || !sdk_is_exists(amx,pawnid,elem2))
		return -1;
	iter_swap(local_deques[amx][pawnid].items.begin()+elem1,local_deques[amx][pawnid].items.begin()+elem2);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_reverse(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	std::reverse(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_get(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_deques[amx][pawnid].get_type(elem) != 1)
		return -2;
	CItem items = local_deques[amx][pawnid].items.at(elem);
	int item = (int)(items.item);
	return item;
}

cell AMX_NATIVE_CALL CDequeNatives::g_get_float(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elem))
		return -1;
	if (local_deques[amx][pawnid].get_type(elem) != 2)
		return -2;
	CItem items = local_deques[amx][pawnid].items.at(elem);
	cell item = items.item;
	return item;
}

cell AMX_NATIVE_CALL CDequeNatives::g_get_arr(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid) || !sdk_is_exists(global_amx,pawnid,elem))
		return -1;
	
	if (local_deques[global_amx][pawnid].get_type(elem) != 0)
		return -2;
	cell* addr = NULL;
	amx_GetAddr(amx,params[3],&addr);
	cell size = params[4];
	CItem items = local_deques[global_amx][pawnid].items.at(elem);
	amx_SetString(addr,items.itemstr.c_str(),0,0,size);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_shrink_to_fit(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	//local_deques[amx][pawnid].items.shrink_to_fit();
	std::deque<CItem> item(local_deques[amx][pawnid].items.begin(),local_deques[amx][pawnid].items.end());
	item.swap(local_deques[amx][pawnid].items);
	local_deques[amx][pawnid].items.clear();
	local_deques[amx][pawnid].items = item;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_is_exists(AMX* amx, cell* params){
	cell pawnid = params[1];
	cell elem = params[2];
	amx = global_amx;
	return local_deques[amx][pawnid].is_exists(elem);
}

cell AMX_NATIVE_CALL CDequeNatives::g_is_vector_exists(AMX* amx, cell* params){

	cell pawnid = params[1];
	amx = global_amx;
	return CDequeNatives::sdk_is_vector_exists(amx,pawnid);
}

cell AMX_NATIVE_CALL CDequeNatives::g_find(AMX* amx, cell* params){

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
	return local_deques[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CDequeNatives::g_find_float(AMX* amx, cell* params){

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
	return local_deques[amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CDequeNatives::g_find_arr(AMX* amx, cell* params){

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
	return local_deques[global_amx][pawnid].find(item,from,end);
}

cell AMX_NATIVE_CALL CDequeNatives::g_set_arr(AMX* amx, cell* params){
	int pawnid = params[1];
	int elemid = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid) || !sdk_is_exists(global_amx,pawnid,elemid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[3],item);
	CItem c;
	c.itemstr = item;
	c.type=0;
	local_deques[global_amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_set(AMX* amx, cell* params){

	cell pawnid = params[1];
	int elemid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	int item = params[3];
	CItem c;
	c.item = item;
	c.type=1;
	local_deques[amx][pawnid].items[elemid] = c;
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_set_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell elemid = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid) || !sdk_is_exists(amx,pawnid,elemid))
		return -1;
	cell item = params[3];
	CItem c;
	c.item = item;
	c.type=2;
	local_deques[amx][pawnid].items[elemid] = c;
	return 1;
}


cell AMX_NATIVE_CALL CDequeNatives::g_assign(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	amx=global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=1;
	local_deques[amx][pawnid].items.assign(repeat,c);
	return 1;
}


cell AMX_NATIVE_CALL CDequeNatives::g_assign_float(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	amx = global_amx;
	if (!sdk_is_vector_exists(amx,pawnid))
		return -1;
	cell val = params[3];
	CItem c;
	c.item = val;
	c.type=2;
	local_deques[amx][pawnid].items.assign(repeat,c);
	return 1;
}

cell AMX_NATIVE_CALL CDequeNatives::g_assign_arr(AMX* amx, cell* params){
	
	cell pawnid = params[1];
	cell repeat = params[2];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* item = NULL;
	amx_StrParam(amx,params[2],item);
	CItem c;
	c.itemstr = item;
	c.type=1;
	local_deques[global_amx][pawnid].items.assign(repeat,c);
	return 1;
}


cell AMX_NATIVE_CALL CDequeNatives::g_sort(AMX* amx, cell* params){
	cell pawnid = params[1];
	if (!sdk_is_vector_exists(global_amx,pawnid))
		return -1;
	char* function = NULL;
	amx_StrParam(amx,params[2],function);

	SortVector sort_me(amx,(int)pawnid,function);
	
	sort_me.pawnid = pawnid;
	CItem temp;
	for(int nIter = local_deques[global_amx][pawnid].items.size() -1;
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
		std::swap(local_deques[global_amx][pawnid].items[nIter],local_deques[global_amx][pawnid].items[nSmallest]);
	}
	return 1;
}




/* SDK */
int CDequeNatives::sdk_is_vector_exists(AMX* amx,unsigned int pawnvec){
	if (0<=pawnvec && pawnvec<local_deques[amx].size())
		return 1;
	return 0;
}

int CDequeNatives::sdk_is_exists(AMX* amx,int pawnvec,int elem){
	return local_deques[amx][pawnvec].is_exists(elem);
}


void CDequeNatives::Unload(AMX* amx){
	local_deques[amx].clear();
	std::vector<CDeque> item(local_deques[amx].begin(),local_deques[amx].end());
	item.swap(local_deques[amx]);
	local_deques[amx].clear();
	local_deques[amx] = item;
}
