#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_obr.h"

using namespace std;

class Moroz_shkaf :public Moroz_obr
{
public:
	Moroz_shkaf();
	Moroz_shkaf(const Moroz_shkaf& holod);
	void print_information()override;
	string get_material()const;
	void set_material(string material);
	Moroz_shkaf& operator=(const Moroz_shkaf& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string material;
};