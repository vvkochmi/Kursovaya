#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_lar.h"

using namespace std;

Moroz_lar::Moroz_lar() :Moroz_obr()
{
	depth = 0;
}
Moroz_lar::Moroz_lar(const Moroz_lar& holod) :Moroz_obr(holod)
{
	depth = holod.depth;
}
void Moroz_lar::print_information()
{
	Moroz_obr::print_information();
	cout << "Глубина: " << depth << endl;
}
int Moroz_lar::get_depth()const
{
	return depth;
}
void Moroz_lar::set_depth(int depth)
{
	this->depth = depth;
}
Moroz_lar& Moroz_lar::operator=(const Moroz_lar& comp)
{
	Moroz_obr::operator=(comp);
	depth = comp.depth;
	return *this;
}
void Moroz_lar::write_file(string word)
{
	Moroz_obr::write_file(word);
	ofstream file(word, ios::app);
	file << "Глубина: ";
	file << depth << endl;
	file.close();
}
void Moroz_lar::read_file(ifstream& file)
{
	Moroz_obr::read_file(file);
	file >> depth;
}
void Moroz_lar::zapis()
{
	Moroz_obr::zapis();
	cout << "Глубина: ";
	cin >> depth;
}