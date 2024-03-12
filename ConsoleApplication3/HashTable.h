#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "HashEntidad.h"
using namespace std;
typedef unsigned int size_t;

class HashTablaA {
private:
	vector<list<HashEntidad>> theLists;
	int  currentSize;

public:
	explicit HashTablaA(int size = 101) : currentSize{ 0 }
	{
		theLists.resize(101);
	}

	void makeEmpty()
	{
		for (auto& thisList : theLists)
			thisList.clear();
	}

	bool insert(HashEntidad&& x)
	{
		auto& whichList = theLists[myhash(x.getKey())]; 

		whichList.push_back(x); 

		return true;
	}

	void DispAll() {
		int pos = 0;
		for (auto& thisList : theLists) {
			cout << "Key: " + to_string(pos) << " | ";
			for (auto& it : theLists[pos]) {
				cout << it.getValue() << ",";
			}
			cout << endl;
			pos++;
		}
	}

private:

	size_t myhash(string key) {
		int sum = 0;
		for (int k = 0; k < key.length(); k++)
			sum = sum + int(key[k]);
		return  sum % theLists.size();
	}
};
