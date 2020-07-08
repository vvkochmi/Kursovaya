#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_obr.h"

using namespace std;

class Moroz_lar :public Moroz_obr
{
public:
	Moroz_lar();
	Moroz_lar(const Moroz_lar& holod);
	void print_information()override;
	int get_depth()const;
	void set_depth(int depth);
	Moroz_lar& operator=(const Moroz_lar& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int depth;
};