#pragma once
#include <iostream>
#include <string>
using namespace std;

class HashEntidad {
private:
	string key;
	int value;

public:
	HashEntidad() {}
	HashEntidad(string key, int value) {
		this->key = key;
		this->value = value;
	}
	string getKey() {
		return key;
	}
	int getValue() {
		return value;
	}
};