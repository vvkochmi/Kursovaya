#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_obr.h"

using namespace std;

class Holod_vitr : public Holod_obr
{
public:
	Holod_vitr();
	Holod_vitr(const Holod_vitr& holod);
	void print_information()override;
	string get_kompress()const;
	void set_kompress(string kompress);
	Holod_vitr& operator=(const Holod_vitr& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string kompress;
};