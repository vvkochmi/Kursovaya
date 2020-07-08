#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_obr.h"

using namespace std;

class Holodos : public Holod_obr
{
public:
	Holodos();
	Holodos(const Holodos& holod);
	void print_information()override;
	int get_kam()const;
	void set_kam(int kam);
	Holodos& operator=(const Holodos& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int height;
};