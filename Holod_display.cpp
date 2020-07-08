#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_display.h"

using namespace std;

Holod_display::Holod_display() :Holodos()
{
	display = "";
}
Holod_display::Holod_display(const Holod_display& holod) :Holodos(holod)
{
	display = holod.display;
}
void Holod_display::print_information()
{
	Holodos::print_information();
	cout << "Наличие дисплея: " << display << endl;
}
string Holod_display::get_display()const
{
	return display;
}
void Holod_display::set_display(string display)
{
	this->display = display;
}
Holod_display& Holod_display::operator=(const Holod_display& comp)
{
	Holodos::operator=(comp);
	display = comp.display;
	return *this;
}
void Holod_display::write_file(string word)
{
	Holodos::write_file(word);
	ofstream file(word, ios::app);
	file << "Наличие дисплея: ";
	file << display << endl;
	file.close();
}
void Holod_display::read_file(ifstream& file)
{
	Holodos::read_file(file);
	getline(file, display);
}
void Holod_display::zapis()
{
	Holodos::zapis();
	cout << "Наличие дисплея: ";
	cin >> display;
}