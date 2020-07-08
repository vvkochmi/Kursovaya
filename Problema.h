#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>

using namespace std;

class Problema {
public:
	Problema()
	{
		oshibka = "Îøèáêà";
	}
	Problema(const string oshibka)
	{
		this->oshibka = oshibka;
	}
	const string get_error() const
	{
		return oshibka;
	}
private:
	string oshibka;
};