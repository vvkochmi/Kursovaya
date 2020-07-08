#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_zamok.h"

using namespace std;

Moroz_zamok::Moroz_zamok() :Moroz_lar()
{
	zamok = "";
}
Moroz_zamok::Moroz_zamok(const Moroz_zamok& holod) :Moroz_lar(holod)
{
	zamok = holod.zamok;
}
void Moroz_zamok::print_information()
{
	Moroz_lar::print_information();
	cout << "Наличие замка: " << zamok << endl;
}
string Moroz_zamok::get_zamok()const
{
	return zamok;
}
void Moroz_zamok::set_zamok(string zamok)
{
	this->zamok = zamok;
}
Moroz_zamok& Moroz_zamok::operator=(const Moroz_zamok& comp)
{
	Moroz_lar::operator=(comp);
	zamok = comp.zamok;
	return *this;
}
void Moroz_zamok::write_file(string word)
{
	Moroz_lar::write_file(word);
	ofstream file(word, ios::app);
	file << "Наличие замка: ";
	file << zamok << endl;
	file.close();
}
void Moroz_zamok::read_file(ifstream& file)
{
	Moroz_lar::read_file(file);
	getline(file, zamok);
}
void Moroz_zamok::zapis()
{
	Moroz_lar::zapis();
	cout << "Наличие замка: ";
	cin >> zamok;
}