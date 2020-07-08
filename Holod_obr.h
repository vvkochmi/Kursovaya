#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_tech.h"

using namespace std;

class Holod_obr :public Holod_tech
{
public:
	Holod_obr();
	Holod_obr(const Holod_obr& holod);
	void print_information()override;
	int get_potreb()const;
	void set_potreb(int potreb);
	Holod_obr& operator=(const Holod_obr& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int potreb;
};