#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_non_indikat.h"

using namespace std;

Moroz_non_indikat::Moroz_non_indikat() :Moroz_shkaf()
{
	shum = 0;
}
Moroz_non_indikat::Moroz_non_indikat(const Moroz_non_indikat& holod) :Moroz_shkaf(holod)
{
	shum = holod.shum;
}
void Moroz_non_indikat::print_information()
{
	Moroz_shkaf::print_information();
	cout << "Уровень шума: " << shum << endl;
}
int Moroz_non_indikat::get_shum()const
{
	return shum;
}
void Moroz_non_indikat::set_shum(int shum)
{
	this->shum = shum;
}
Moroz_non_indikat& Moroz_non_indikat::operator=(const Moroz_non_indikat& comp)
{
	Moroz_shkaf::operator=(comp);
	shum = comp.shum;
	return *this;
}
void Moroz_non_indikat::write_file(string word)
{
	Moroz_shkaf::write_file(word);
	ofstream file(word, ios::app);
	file << "Уровень шума: ";
	file << shum << endl;
	file.close();
}
void Moroz_non_indikat::read_file(ifstream& file)
{
	Moroz_shkaf::read_file(file);
	file >> shum;
}
void Moroz_non_indikat::zapis()
{
	Moroz_shkaf::zapis();
	cout << "Уровень шума: ";
	cin >> shum;
}