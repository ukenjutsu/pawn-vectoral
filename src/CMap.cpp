#include "CMap.h"
#include <algorithm>
#include <string>
CMap::CMap(){
	this->items.clear();
}

CMap::~CMap(){
	this->items.clear();
}

void CMap::insert(string key,CMapItem item){
	this->items[key] = item;
}

void CMap::clear(){
	this->items.clear();
}

int CMap::get_type(string key){
	if(!contains(key)) return -1;
	return items[key].type;
}


int CMap::contains(string key){
	if(items.find(key) != items.end()) return 1;
	return 0;
}