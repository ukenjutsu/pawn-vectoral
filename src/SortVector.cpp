#include "SortVector.h"
#include "SDK/plugin.h"
#include <string>
using namespace std;
SortVector::SortVector(AMX* amx,int pawnid, string funcName){
	this->amx = amx;
	this->pawnid = pawnid;
	this->funcName=funcName;
}

SortVector::~SortVector(){}
bool SortVector::compare (int firstidx,int secondidx){
	int addr;
	if (amx_FindPublic(this->amx,this->funcName.c_str(),&addr)==AMX_ERR_NONE){
		amx_Push(amx,secondidx);
		amx_Push(amx,firstidx);
		amx_Push(amx,pawnid);
		cell ret;
		amx_Exec(amx,&ret,addr);
		return ret;
	}else{
		return false;
	}
};