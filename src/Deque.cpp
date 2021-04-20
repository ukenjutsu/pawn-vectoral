#include "Deque.h"
#include <algorithm>
using namespace std;
CDeque::CDeque(){
	this->items.clear();
}

CDeque::~CDeque(){
	this->items.clear();
}

void CDeque::push_back(CItem item){
	this->items.push_back(item);
}

void CDeque::pop_back(){
	this->items.pop_back();
}

void CDeque::push_front(CItem item){
	this->items.push_front(item);
}

void CDeque::clear(){
	this->items.clear();
}
extern bool operator ==(const CItem& it, const CItem& item);
int CDeque::find(CItem item,unsigned int fromItem,int endItem){
	if (endItem==-1)
		endItem = distance(items.begin(),items.end());
	if (!is_exists(fromItem) || !is_exists(endItem-1))
		return -1;
	deque<CItem>::iterator it = std::find(this->items.begin()+fromItem, this->items.begin()+endItem, item);
	
	if (it == items.end())
		return -1;
	
	return distance(items.begin(),it);
}

int CDeque::get_type(int id){
	return this->items[id].type;
}

int CDeque::is_exists(unsigned int elem){
	if (0<=elem && elem<this->items.size())
		return 1;
	return 0;
}