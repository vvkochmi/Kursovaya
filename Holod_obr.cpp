#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_obr.h"

using namespace std;

Holod_obr::Holod_obr() : Holod_tech()
{
	potreb = 0;
}
Holod_obr::Holod_obr(const Holod_obr& holod) : Holod_tech(holod)
{
	potreb = holod.potreb;
}
void Holod_obr::print_information()
{
	Holod_tech::print_information();
	cout << "Ёнергопотребление: " << potreb << endl;
}
int Holod_obr::get_potreb()const
{
	return potreb;
}
void Holod_obr::set_potreb(int potreb)
{
	this->potreb = potreb;
}

Holod_obr& Holod_obr::operator=(const Holod_obr& comp)
{
	Holod_tech::operator=(comp);
	potreb = comp.potreb;
	return *this;
}
void Holod_obr::write_file(string word)
{
	Holod_tech::write_file(word);
	ofstream file(word, ios::app);
	file << "Ёнергопотребление: ";
	file << potreb << endl;
	file.close();
}
void Holod_obr::read_file(ifstream& file)
{
	Holod_tech::read_file(file);
	file >> potreb;
}
void Holod_obr::zapis()
{
	Holod_tech::zapis();
	cout << "Ёнергопотребление: ";
	cin >> potreb;
}