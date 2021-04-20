#include "MultiMap.h"
#include <algorithm>
#include <string>
typedef multimap<string,CMultiMapItem> cmulti;
typedef CMultiMapItem cmitem;
CMultiMap::CMultiMap(){
	this->items.clear();
}

CMultiMap::~CMultiMap(){
	this->items.clear();
}

int CMultiMap::insert(string key,CMultiMapItem item){
	this->items.insert(pair<string,CMultiMapItem>(key,item));
	return this->items.count(key)-1;
}

void CMultiMap::clear(){
	this->items.clear();
}

int CMultiMap::get_type(string key,int idx){
	if(!contains(key,idx)) return -1;
	multimap<string,CMultiMapItem>::iterator it = items.find(key);
	for(int i=0; i<idx; i++){
		it++;
	}
	return it->second.type;
}

CMultiMapItem CMultiMap::find(string key,int idx){
	multimap<string,CMultiMapItem>::iterator it = items.find(key);
	for(int i=0; i<idx; i++){
		it++;
	}
	return it->second;
}

void CMultiMap::set(string key,int idx,CMultiMapItem item){
	int idx_f = 0;
	pair<cmulti::iterator,cmulti::iterator> equ = items.equal_range(key);
	for(cmulti::iterator it = equ.first; it!=equ.second; ++it){
		if(idx_f == idx){
			it->second = item;
			break;
		}
		idx_f ++;
	}
}

multimap<string,CMultiMapItem>::iterator CMultiMap::find(string key,int idx,bool iter){
	multimap<string,CMultiMapItem>::iterator it = items.find(key);
	
	for(int i=0; i<idx; i++){
		it++;
	}
	return it;
}

int CMultiMap::contains(string key,int idx){
	if(idx==-1){
		if(items.find(key) != items.end()) return 1;
	}else{
		int idx_f = 0;
		//multimap<string,CMultiMapItem>::iterator it = items.find(key);
		pair<cmulti::iterator,cmulti::iterator> equ = items.equal_range(key);
		for(cmulti::iterator it = equ.first; it!=equ.second; ++it){
			if(idx_f == idx){
				return 1;
			}
			idx_f ++;
		}
		/*for(int i=0; i<idx; i++){
			it++;
		}
		if(it != items.end()){
			if(!strcmp(it->first.c_str(),key.c_str()))
				return 1;
		}*/
	}
	return 0;
}