#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_tech.h"

using namespace std;

class Moroz_obr :public Holod_tech
{
public:
	Moroz_obr();
	Moroz_obr(const Moroz_obr& holod);
	void print_information()override;
	double get_v()const;
	void set_v(double v);
	Moroz_obr& operator=(const Moroz_obr& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	double v;
};