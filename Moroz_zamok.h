#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_lar.h"

using namespace std;

class Moroz_zamok :public Moroz_lar
{
public:
	Moroz_zamok();
	Moroz_zamok(const Moroz_zamok& holod);
	void print_information()override;
	string get_zamok()const;
	void set_zamok(string zamok);
	Moroz_zamok& operator=(const Moroz_zamok& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string zamok;
};