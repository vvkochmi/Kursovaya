#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_vitr.h"

using namespace std;

class Holod_vitr_cam :public Holod_vitr
{
public:
	Holod_vitr_cam();
	Holod_vitr_cam(const Holod_vitr_cam& holod);
	void print_information()override;
	int get_kam()const;
	void set_kam(int kam);
	Holod_vitr_cam& operator=(const Holod_vitr_cam& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int kam;
};