#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_lar.h"

using namespace std;

class Moroz_non_zamok :public Moroz_lar
{
public:
	Moroz_non_zamok();
	Moroz_non_zamok(const Moroz_non_zamok& holod);
	void print_information()override;
	string get_block()const;
	void set_block(string block);
	Moroz_non_zamok& operator=(const Moroz_non_zamok& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string block;
};