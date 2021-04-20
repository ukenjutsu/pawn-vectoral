#include "Vector.h"
#include <algorithm>
#include<string.h>
#include <iostream>
using namespace std;
CVector::CVector(){
	this->items.clear();
}

CVector::~CVector(){
	this->items.clear();
}

void CVector::push_back(CItem item){
	this->items.push_back(item);
}

void CVector::pop_back(){
	this->items.pop_back();
}

void CVector::push_front(CItem item){
	this->items.insert(this->items.begin(), item);
}

void CVector::clear(){
	this->items.clear();
}
bool operator ==(const CItem& it, const CItem& item)
{
	if (it.type != item.type)
		return 0;
	if(it.type == 0){
		if (strcmp(it.itemstr.c_str(), item.itemstr.c_str())!=0)
			return 0;
	}else{
		if(it.item != item.item)
			return 0;
	}
	return 1;
}
int CVector::find(CItem item,unsigned int fromItem,int endItem){
	if (endItem==-1)
		endItem = distance(items.begin(),items.end());
	if (!is_exists(fromItem) || !is_exists(endItem-1))
		return -1;
	vector<CItem>::iterator it = std::find(this->items.begin()+fromItem, this->items.begin()+endItem, item);
	
	if (it == items.end())
		return -1;
	
	return distance(items.begin(),it);
}

int CVector::get_type(int id){
	return this->items[id].type;
}

int CVector::is_exists(unsigned int elem){
	if (0<=elem && elem<this->items.size())
		return 1;
	return 0;
}
