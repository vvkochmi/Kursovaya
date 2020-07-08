#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holodos.h"

using namespace std;

class Holod_display :public Holodos
{
public:
	Holod_display();
	Holod_display(const Holod_display& holod);
	void print_information()override;
	string get_display()const;
	void set_display(string display);
	Holod_display& operator=(const Holod_display& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	string display;
};