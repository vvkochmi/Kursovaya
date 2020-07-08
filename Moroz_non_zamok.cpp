#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Moroz_non_zamok.h"

using namespace std;

Moroz_non_zamok::Moroz_non_zamok() :Moroz_lar()
{
	block = "";
}
Moroz_non_zamok::Moroz_non_zamok(const Moroz_non_zamok& holod) :Moroz_lar(holod)
{
	block = holod.block;
}
void Moroz_non_zamok::print_information()
{
	Moroz_lar::print_information();
	cout << "Наличие блокировки от детей: " << block << endl;
}
string Moroz_non_zamok::get_block()const
{
	return block;
}
void Moroz_non_zamok::set_block(string block)
{
	this->block = block;
}
Moroz_non_zamok& Moroz_non_zamok::operator=(const Moroz_non_zamok& comp)
{
	Moroz_lar::operator=(comp);
	block = comp.block;
	return *this;
}
void Moroz_non_zamok::write_file(string word)
{
	Moroz_lar::write_file(word);
	ofstream file(word, ios::app);
	file << "Наличие блокировки от детей: ";
	file << block << endl;
	file.close();
}
void Moroz_non_zamok::read_file(ifstream& file)
{
	Moroz_lar::read_file(file);
	getline(file, block);
}
void Moroz_non_zamok::zapis()
{
	Moroz_lar::zapis();
	cout << "Наличие блокировки от детей: ";
	cin >> block;
}