#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_shkaf.h"

using namespace std;

class Moroz_indikat :public Moroz_shkaf
{
public:
	Moroz_indikat();
	Moroz_indikat(const Moroz_indikat& holod);
	void print_information()override;
	string get_indikat()const;
	void set_indikat(string indikat);
	Moroz_indikat& operator=(const Moroz_indikat& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string indikat;
};