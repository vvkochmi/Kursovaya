#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_obr.h"

using namespace std;

Moroz_obr::Moroz_obr() :Holod_tech()
{
	v = 0;
}
Moroz_obr::Moroz_obr(const Moroz_obr& holod) :Holod_tech(holod)
{
	v = holod.v;
}
void Moroz_obr::print_information()
{
	Holod_tech::print_information();
	cout << "Общий полезный объём: " << v << endl;
}
double Moroz_obr::get_v()const
{
	return v;
}
void Moroz_obr::set_v(double v)
{
	this->v = v;
}
Moroz_obr& Moroz_obr::operator=(const Moroz_obr& comp)
{
	Holod_tech::operator=(comp);
	v = comp.v;
	return *this;
}
void Moroz_obr::write_file(string word)
{
	Holod_tech::write_file(word);
	ofstream file(word, ios::app);
	file << "Общий полезный объём: ";
	file << v << endl;
	file.close();
}
void Moroz_obr::read_file(ifstream& file)
{
	Holod_tech::read_file(file);
	file >> v;
}
void Moroz_obr::zapis()
{
	Holod_tech::zapis();
	cout << "Общий полезный объём: ";
	cin >> v;
}