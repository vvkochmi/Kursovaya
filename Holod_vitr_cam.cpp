#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Holod_vitr_cam.h"

using namespace std;

Holod_vitr_cam::Holod_vitr_cam() :Holod_vitr()
{
	kam = 0;
}
Holod_vitr_cam::Holod_vitr_cam(const Holod_vitr_cam& holod) :Holod_vitr(holod)
{
	kam = holod.kam;
}
void Holod_vitr_cam::print_information()
{
	Holod_vitr::print_information();
	cout << "Количество камер: " << kam << endl;
}
int Holod_vitr_cam::get_kam()const
{
	return kam;
}
void Holod_vitr_cam::set_kam(int kam)
{
	this->kam = kam;
}
Holod_vitr_cam& Holod_vitr_cam::operator=(const Holod_vitr_cam& comp)
{
	Holod_vitr::operator=(comp);
	kam = comp.kam;
	return *this;
}
void Holod_vitr_cam::write_file(string word)
{
	Holod_vitr::write_file(word);
	ofstream file(word, ios::app);
	file << "Количество камер: ";
	file << kam << endl;
	file.close();
}
void Holod_vitr_cam::read_file(ifstream& file)
{
	Holod_vitr::read_file(file);
	file >> kam;
}
void Holod_vitr_cam::zapis()
{
	Holod_vitr::zapis();
	cout << "Количество камер: ";
	cin >> kam;
}