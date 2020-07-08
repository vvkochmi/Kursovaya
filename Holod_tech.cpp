#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include "Holod_tech.h"

using namespace std;
Holod_tech::Holod_tech()
{
	name = "";
	brand = "";
	color = "";
	price = 0;
	moch = 0;
}
Holod_tech::Holod_tech(const Holod_tech& holod)
{
	name = holod.name;
	brand = holod.brand;
	color = holod.color;
	price = holod.price;
	moch = holod.moch;
}
void Holod_tech::print_information()
{
	cout << "��������: " << name << endl;
	cout << "�����: " << brand << endl;
	cout << "����: " << color << endl;
	cout << "����: " << price << endl;
	cout << "��������: " << moch << endl;
}
double Holod_tech::get_price() const
{
	return price;
}
string Holod_tech::get_name() const
{
	return name;
}
string Holod_tech::get_brand() const
{
	return brand;
}
void Holod_tech::set_price(double price)
{
	this->price = price;
}
void Holod_tech::set_name(string name)
{
	this->name = name;
}
void Holod_tech::set_brand(string brand)
{
	this->brand = brand;
}
int Holod_tech::get_moch()const
{
	return moch;
}
string Holod_tech::get_color()const
{
	return color;
}
void Holod_tech::set_moch(int moch)
{
	this->moch = moch;
}
void Holod_tech::set_color(string color)
{
	this->color = color;
}
Holod_tech& Holod_tech::operator=(const Holod_tech& comp)
{
	price = comp.price;
	name = comp.name;
	brand = comp.brand;
	moch = comp.moch;
	color = comp.color;
	return *this;
}
void Holod_tech::write_file(string word)
{
	ofstream file(word, ios::app);
	file << "��������: ";
	file << name << endl;
	file << "�����: ";
	file << brand << endl;
	file << "����: ";
	file << price << endl;
	file << "��������: ";
	file << moch << endl;
	file << "����: ";
	file << color << endl;
	file.close();
}
void Holod_tech::read_file(ifstream& file)
{
	getline(file, name);
	getline(file, brand);
	getline(file, color);
	file >> price;
	file >> moch;
}
void Holod_tech::zapis()
{
	cout << "��������: ";
	cin >> name;
	cout << "�����: ";
	cin >> brand;
	cout << "����: ";
	cin >> price;
	cout << "��������: ";
	cin >> moch;
	cout << "����: ";
	cin >> color;
}