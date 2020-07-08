#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"IHolod.h"

using namespace std;

class Holod_tech : public IHolod {
public:
	Holod_tech();
	Holod_tech(const Holod_tech& holod);
	void print_information() override;
	double get_price() const override;
	string get_name() const override;
	string get_brand() const override;
	void set_price(double price) override;
	void set_name(string name) override;
	void set_brand(string brand) override;
	int get_moch()const;
	string get_color()const;
	void set_moch(int moch);
	void set_color(string color);
	Holod_tech& operator=(const Holod_tech& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string name;
	string brand;
	string color;
	double price;
	int moch;
};