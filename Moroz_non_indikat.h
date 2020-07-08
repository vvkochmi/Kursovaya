#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_shkaf.h"

using namespace std;

class Moroz_non_indikat :public Moroz_shkaf
{
public:
	Moroz_non_indikat();
	Moroz_non_indikat(const Moroz_non_indikat& holod);
	void print_information()override;
	int get_shum()const;
	void set_shum(int shum);
	Moroz_non_indikat& operator=(const Moroz_non_indikat& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int shum;
};