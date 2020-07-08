#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holodos.h"

using namespace std;

Holodos::Holodos() : Holod_obr()
{
	height = 0;
}
Holodos::Holodos(const Holodos& holod) :Holod_obr(holod)
{
	height = holod.height;
}
void Holodos::print_information()
{
	Holod_obr::print_information();
	cout << "Высота: " << height << endl;
}
int Holodos::get_kam()const
{
	return height;
}
void Holodos::set_kam(int kam)
{
	this->height = kam;
}
Holodos& Holodos::operator=(const Holodos& comp)
{
	Holod_obr::operator=(comp);
	height = comp.height;
	return *this;
}
void Holodos::write_file(string word)
{
	Holod_obr::write_file(word);
	ofstream file(word, ios::app);
	file << "Высота: ";
	file << height << endl;
	file.close();
}
void Holodos::read_file(ifstream& file)
{
	Holod_obr::read_file(file);
	file >> height;
}
void Holodos::zapis()
{
	Holod_obr::zapis();
	cout << "Высота: ";
	cin >> height;
}