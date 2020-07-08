#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_vitr.h"

using namespace std;

class Holod_vitr_razmoroz :public Holod_vitr
{
public:
	Holod_vitr_razmoroz();
	Holod_vitr_razmoroz(const Holod_vitr_razmoroz& holod);
	void print_information()override;
	string get_razmoroz()const;
	void set_razmoroz(string razmoroz);
	Holod_vitr_razmoroz& operator=(const Holod_vitr_razmoroz& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string razmoroz;
};