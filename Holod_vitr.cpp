#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_vitr.h"

using namespace std;

Holod_vitr::Holod_vitr() : Holod_obr()
{
	kompress = "";
}
Holod_vitr::Holod_vitr(const Holod_vitr& holod) :Holod_obr(holod)
{
	kompress = holod.kompress;
}
void Holod_vitr::print_information()
{
	Holod_obr::print_information();
	cout << "Наличие компрессора: " << kompress << endl;
}
string Holod_vitr::get_kompress()const
{
	return kompress;
}
void Holod_vitr::set_kompress(string kompress)
{
	this->kompress = kompress;
}
Holod_vitr& Holod_vitr::operator=(const Holod_vitr& comp)
{
	Holod_obr::operator=(comp);
	kompress = comp.kompress;
	return *this;
}
void Holod_vitr::write_file(string word)
{
	Holod_obr::write_file(word);
	ofstream file(word, ios::app);
	file << "Наличие компрессора: ";
	file << kompress << endl;
	file.close();
}
void Holod_vitr::read_file(ifstream& file)
{
	Holod_obr::read_file(file);
	getline(file, kompress);
}
void Holod_vitr::zapis()
{
	Holod_obr::zapis();
	cout << "Наличие компрессора: ";
	cin >> kompress;
}