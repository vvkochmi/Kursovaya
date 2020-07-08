#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>

using namespace std;

class IHolod {
public:
	virtual void print_information() = 0;
	virtual double get_price() const = 0;
	virtual string get_name() const = 0;
	virtual string get_brand() const = 0;
	virtual void set_price(double price) = 0;
	virtual void set_name(string name) = 0;
	virtual void set_brand(string brand) = 0;
	virtual void write_file(string word) = 0;
	virtual void read_file(ifstream& file) = 0;
	virtual void zapis() = 0;
};
