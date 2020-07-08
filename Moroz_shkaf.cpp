#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_shkaf.h"

using namespace std;

Moroz_shkaf::Moroz_shkaf() :Moroz_obr()
{
	material = "";
}
Moroz_shkaf::Moroz_shkaf(const Moroz_shkaf& holod) :Moroz_obr(holod)
{
	material = holod.material;
}
void Moroz_shkaf::print_information()
{
	Moroz_obr::print_information();
	cout << "Материал: " << material << endl;
}
string Moroz_shkaf::get_material()const
{
	return material;
}
void Moroz_shkaf::set_material(string material)
{
	this->material = material;
}
Moroz_shkaf& Moroz_shkaf::operator=(const Moroz_shkaf& comp)
{
	Moroz_obr::operator=(comp);
	material = comp.material;
	return *this;
}
void Moroz_shkaf::write_file(string word)
{
	Moroz_obr::write_file(word);
	ofstream file(word, ios::app);
	file << "Материал: ";
	file << material << endl;
	file.close();
}
void Moroz_shkaf::read_file(ifstream& file)
{
	Moroz_obr::read_file(file);
	getline(file, material);
}
void Moroz_shkaf::zapis()
{
	Moroz_obr::zapis();
	cout << "Материал: ";
	cin >> material;
}