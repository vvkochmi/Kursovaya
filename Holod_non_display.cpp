#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_non_display.h"

using namespace std;

Holod_non_display::Holod_non_display() :Holodos()
{
	dver = 0;
}
Holod_non_display::Holod_non_display(const Holod_non_display& holod) :Holodos(holod)
{
	dver = holod.dver;
}
void Holod_non_display::print_information()
{
	Holodos::print_information();
	cout << "Количество дверей: " << dver << endl;
}
int Holod_non_display::get_dver()const
{
	return dver;
}
void Holod_non_display::set_dver(int dver)
{
	this->dver = dver;
}
Holod_non_display& Holod_non_display::operator=(const Holod_non_display& comp)
{
	Holodos::operator=(comp);
	dver = comp.dver;
	return *this;
}
void Holod_non_display::write_file(string word)
{
	Holodos::write_file(word);
	ofstream file(word, ios::app);
	file << "Количество дверей: ";
	file << dver << endl;
	file.close();
}
void Holod_non_display::read_file(ifstream& file)
{
	Holodos::read_file(file);
	file >> dver;
}
void Holod_non_display::zapis()
{
	Holodos::zapis();
	cout << "Количество дверей: ";
	cin >> dver;
}