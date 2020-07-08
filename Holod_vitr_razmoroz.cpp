#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_vitr_razmoroz.h"

using namespace std;

Holod_vitr_razmoroz::Holod_vitr_razmoroz() :Holod_vitr()
{
	razmoroz = "";
}
Holod_vitr_razmoroz::Holod_vitr_razmoroz(const Holod_vitr_razmoroz& holod) :Holod_vitr(holod)
{
	razmoroz = holod.razmoroz;
}
void Holod_vitr_razmoroz::print_information()
{
	Holod_vitr::print_information();
	cout << "Тип разморозки: " << razmoroz << endl;
}
string Holod_vitr_razmoroz::get_razmoroz()const
{
	return razmoroz;
}
void Holod_vitr_razmoroz::set_razmoroz(string razmoroz)
{
	this->razmoroz = razmoroz;
}
Holod_vitr_razmoroz& Holod_vitr_razmoroz::operator=(const Holod_vitr_razmoroz& comp)
{
	Holod_vitr::operator=(comp);
	razmoroz = comp.razmoroz;
	return *this;
}
void Holod_vitr_razmoroz::write_file(string word)
{
	Holod_vitr::write_file(word);
	ofstream file(word, ios::app);
	file << "Тип разморозки: ";
	file << razmoroz << endl;
	file.close();
}
void Holod_vitr_razmoroz::read_file(ifstream& file)
{
	Holod_vitr::read_file(file);
	getline(file, razmoroz);
}
void Holod_vitr_razmoroz::zapis()
{
	Holod_vitr::zapis();
	cout << "Тип разморозки: ";
	cin >> razmoroz;
}