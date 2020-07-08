#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holodos.h"

using namespace std;

class Holod_non_display : public Holodos
{
public:
	Holod_non_display();
	Holod_non_display(const Holod_non_display& holod);
	void print_information()override;
	int get_dver()const;
	void set_dver(int dver);
	Holod_non_display& operator=(const Holod_non_display& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int dver;
};