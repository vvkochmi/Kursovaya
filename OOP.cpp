// курсача ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"IHolod.h"
#include"Holod_tech.h"
#include"Holod_obr.h"
#include"Holodos.h"
#include"Holod_vitr.h"
#include"Holod_display.h"
#include"Holod_non_display.h"
#include"Holod_vitr_cam.h"
#include"Holod_vitr_razmoroz.h"
#include"Moroz_obr.h"
#include"Moroz_shkaf.h"
#include"Moroz_lar.h"
#include"Moroz_indikat.h"
#include"Moroz_non_indikat.h"
#include"Moroz_zamok.h"
#include"Moroz_non_zamok.h"
#include"Vector.h"
#include"Problema.h"

using namespace std;

template<class T>
bool sort_price(const T& stat1, const T& stat2) {
	if (stat1->get_price() < stat2->get_price()) return true;
	return false;
}
template<class T>
bool FindByName(string value, const T& stat) {
	if (value == stat->get_name()) return true;
	return false;
}
/*
class Problema {
public:
	Problema() 
	{
		oshibka = "Ошибка";
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

class IHolod {
public:
	virtual void print_information() = 0;
	virtual double get_price() const = 0;
	virtual string get_name() const = 0;
	virtual string get_brand() const = 0;
	virtual void set_price(double price) = 0;
	virtual void set_name(string name) = 0;
	virtual void set_brand(string brand) = 0;
	virtual void write_file(string word) = 0;
	virtual void read_file(ifstream& file) = 0;
	virtual void zapis() = 0;
};

class Holod_tech : public IHolod{
public:
	Holod_tech()
	{
		name = "";
		brand = "";
		color = "";
		price = 0;
		moch = 0;
	}
	Holod_tech(const Holod_tech& holod)
	{
		name = holod.name;
		brand = holod.brand;
		color = holod.color;
		price = holod.price;
		moch = holod.moch;
	}
	void print_information() override
	{
		cout << "Название: " << name << endl;
		cout << "Бренд: " << brand << endl;
		cout << "Цвет: " << color << endl;
		cout << "Цена: " << price << endl;
		cout << "Мощность: " << moch << endl;
	}
	double get_price() const override
	{
		return price;
	}
	string get_name() const override
	{
		return name;
	}
	string get_brand() const override
	{
		return brand;
	}
	void set_price(double price) override
	{
		this->price = price;
	}
	void set_name(string name) override
	{
		this->name = name;
	}
	void set_brand(string brand) override
	{
		this->brand = brand;
	}
	int get_moch()const
	{
		return moch;
	}
	string get_color()const
	{
		return color;
	}
	void set_moch(int moch)
	{
		this->moch = moch;
	}
	void set_color(string color)
	{
		this->color = color;
	}
	Holod_tech& operator=(const Holod_tech& comp)
	{
		price = comp.price;
		name = comp.name;
		brand = comp.brand;
		moch = comp.moch;
		color = comp.color;
		return *this;
	}
	void write_file(string word)override
	{
		ofstream file(word, ios::app);
		file << "Название: ";
		file << name << endl;
		file << "Бренд: ";
		file << brand << endl;
		file << "Цена: ";
		file << price << endl;
		file << "Мощность: ";
		file << moch << endl;
		file << "Цвет: ";
		file << color << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		getline(file, name);
		getline(file, brand);
		getline(file, color);
		file >> price;
		file >> moch;
	}
	void zapis()override
	{
		cout << "Название: ";
		cin >> name;
		cout << "Бренд: ";
		cin >> brand;
		cout << "Цена: ";
		cin >> price;
		cout << "Мощность: ";
		cin >> moch;
		cout << "Цвет: ";
		cin >> color;
	}
protected:
	string name;
	string brand;
	string color;
	double price;
	int moch;
};

///////////////Холодильники/////////////////////

class Holod_obr :public Holod_tech
{
public:
	Holod_obr() : Holod_tech()
	{
		potreb = 0;
	}
	Holod_obr(const Holod_obr& holod) : Holod_tech(holod)
	{
		potreb = holod.potreb;
	}
	void print_information()override
	{
		Holod_tech::print_information();
		cout << "Энергопотребление: " << potreb << endl;
	}
	int get_potreb()const
	{
		return potreb;
	}
	void set_potreb(int potreb)
	{
		this->potreb = potreb;
	}

	Holod_obr& operator=(const Holod_obr& comp)
	{
		Holod_tech::operator=(comp);
		potreb = comp.potreb;
	}
	void write_file(string word)override
	{
		Holod_tech::write_file(word);
		ofstream file(word, ios::app);
		file << "Энергопотребление: ";
		file << potreb << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holod_tech::read_file(file);
		file >> potreb;
	}
	void zapis()override
	{
		Holod_tech::zapis();
		cout << "Энергопотребление: ";
		cin >> potreb;
	}
protected:
	int potreb;
};

class Holodos : public Holod_obr
{
public:
	Holodos() : Holod_obr()
	{
		height = 0;
	}
	Holodos(const Holodos& holod) :Holod_obr(holod)
	{
		height = holod.height;
	}
	void print_information()override
	{
		Holod_obr::print_information();
		cout << "Высота: " << height << endl;
	}
	int get_kam()const
	{
		return height;
	}
	void set_kam(int kam)
	{
		this->height = kam;
	}
	Holodos& operator=(const Holodos& comp)
	{
		Holod_obr::operator=(comp);
		height = comp.height;
	}
	void write_file(string word)override
	{
		Holod_obr::write_file(word);
		ofstream file(word, ios::app);
		file << "Высота: ";
		file << height << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holod_obr::read_file(file);
		file >> height;
	}
	void zapis()override
	{
		Holod_obr::zapis();
		cout << "Высота: ";
		cin >> height;
	}
protected:
	int height;
};

class Holod_vitr : public Holod_obr
{
public:
	Holod_vitr() : Holod_obr()
	{
		kompress = "";
	}
	Holod_vitr(const Holod_vitr& holod) :Holod_obr(holod)
	{
		kompress = holod.kompress;
	}
	void print_information()override
	{
		Holod_obr::print_information();
		cout << "Наличие компрессора: " << kompress << endl;
	}
	string get_kompress()const
	{
		return kompress;
	}
	void set_kompress(string kompress)
	{
		this->kompress = kompress;
	}
	Holod_vitr& operator=(const Holod_vitr& comp)
	{
		Holod_obr::operator=(comp);
		kompress = comp.kompress;
	}
	void write_file(string word)override
	{
		Holod_obr::write_file(word);
		ofstream file(word, ios::app);
		file << "Наличие компрессора: ";
		file << kompress << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holod_obr::read_file(file);
		getline(file, kompress);
	}
	void zapis()override
	{
		Holod_obr::zapis();
		cout << "Наличие компрессора: ";
		cin >> kompress;
	}
protected:
	string kompress;
};

class Holod_display :public Holodos
{
public:
	Holod_display() :Holodos()
	{
		display = "";
	}
	Holod_display(const Holod_display& holod) :Holodos(holod)
	{
		display = holod.display;
	}
	void print_information()override
	{
		Holodos::print_information();
		cout << "Наличие дисплея: " << display << endl;
	}
	string get_display()const
	{
		return display;
	}
	void set_display(string display)
	{
		this->display = display;
	}
	Holod_display& operator=(const Holod_display& comp)
	{
		Holodos::operator=(comp);
		display = comp.display;
	}
	void write_file(string word)override
	{
		Holodos::write_file(word);
		ofstream file(word, ios::app);
		file << "Наличие дисплея: ";
		file << display << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holodos::read_file(file);
		getline(file, display);
	}
	void zapis()override
	{
		Holodos::zapis();
		cout << "Наличие дисплея: ";
		cin >> display;
	}
protected:
	string display;
};

class Holod_non_display : public Holodos
{
public:
	Holod_non_display() :Holodos()
	{
		dver = 0;
	}
	Holod_non_display(const Holod_non_display& holod) :Holodos(holod)
	{
		dver = holod.dver;
	}
	void print_information()override
	{
		Holodos::print_information();
		cout << "Количество дверей: " << dver << endl;
	}
	int get_dver()const
	{
		return dver;
	}
	void set_dver(int dver)
	{
		this->dver = dver;
	}
	Holod_non_display& operator=(const Holod_non_display& comp)
	{
		Holodos::operator=(comp);
		dver = comp.dver;
	}
	void write_file(string word)override
	{
		Holodos::write_file(word);
		ofstream file(word, ios::app);
		file << "Количество дверей: ";
		file << dver << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holodos::read_file(file);
		file >> dver;
	}
	void zapis()override
	{
		Holodos::zapis();
		cout << "Количество дверей: ";
		cin >> dver;
	}
protected:
	int dver;
};

class Holod_vitr_cam :public Holod_vitr
{
public:
	Holod_vitr_cam() :Holod_vitr()
	{
		kam = 0;
	}
	Holod_vitr_cam(const Holod_vitr_cam& holod) :Holod_vitr(holod)
	{
		kam = holod.kam;
	}
	void print_information()override
	{
		Holod_vitr::print_information();
		cout << "Количество камер: " << kam << endl;
	}
	int get_kam()const
	{
		return kam;
	}
	void set_kam(int kam)
	{
		this->kam = kam;
	}
	Holod_vitr_cam& operator=(const Holod_vitr_cam& comp)
	{
		Holod_vitr::operator=(comp);
		kam = comp.kam;
	}
	void write_file(string word)override
	{
		Holod_vitr::write_file(word);
		ofstream file(word, ios::app);
		file << "Количество камер: ";
		file << kam << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holod_vitr::read_file(file);
		file >> kam;
	}
	void zapis()override
	{
		Holod_vitr::zapis();
		cout << "Количество камер: ";
		cin >> kam;
	}
protected:
	int kam;
};

class Holod_vitr_razmoroz :public Holod_vitr
{
public:
	Holod_vitr_razmoroz() :Holod_vitr()
	{
		razmoroz = "";
	}
	Holod_vitr_razmoroz(const Holod_vitr_razmoroz& holod) :Holod_vitr(holod)
	{
		razmoroz = holod.razmoroz;
	}
	void print_information()override
	{
		Holod_vitr::print_information();
		cout << "Тип разморозки: " << razmoroz << endl;
	}
	string get_razmoroz()const
	{
		return razmoroz;
	}
	void set_razmoroz(string razmoroz)
	{
		this->razmoroz = razmoroz;
	}
	Holod_vitr_razmoroz& operator=(const Holod_vitr_razmoroz& comp)
	{
		Holod_vitr::operator=(comp);
		razmoroz = comp.razmoroz;
	}
	void write_file(string word)override
	{
		Holod_vitr::write_file(word);
		ofstream file(word, ios::app);
		file << "Тип разморозки: ";
		file << razmoroz << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holod_vitr::read_file(file);
		getline(file, razmoroz);
	}
	void zapis()override
	{
		Holod_vitr::zapis();
		cout << "Тип разморозки: ";
		cin >> razmoroz;
	}
protected:
	string razmoroz;
};

/////////////////Морозилки////////////////////

class Moroz_obr :public Holod_tech
{
public:
	Moroz_obr() :Holod_tech()
	{
		v = 0;
	}
	Moroz_obr(const Moroz_obr& holod) :Holod_tech(holod)
	{
		v = holod.v;
	}
	void print_information()override
	{
		Holod_tech::print_information();
		cout << "Общий полезный объём: " << v << endl;
	}
	double get_v()const
	{
		return v;
	}
	void set_v(double v)
	{
		this->v = v;
	}
	Moroz_obr& operator=(const Moroz_obr& comp)
	{
		Holod_tech::operator=(comp);
		v = comp.v;
	}
	void write_file(string word)override
	{
		Holod_tech::write_file(word);
		ofstream file(word, ios::app);
		file << "Общий полезный объём: ";
		file << v << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Holod_tech::read_file(file);
		file >> v;
	}
	void zapis()override
	{
		Holod_tech::zapis();
		cout << "Общий полезный объём: ";
		cin >> v;
	}
protected:
	double v;
};

class Moroz_shkaf :public Moroz_obr
{
public:
	Moroz_shkaf() :Moroz_obr()
	{
		material = "";
	}
	Moroz_shkaf(const Moroz_shkaf& holod) :Moroz_obr(holod)
	{
		material = holod.material;
	}
	void print_information()override
	{
		Moroz_obr::print_information();
		cout << "Материал: " << material << endl;
	}
	string get_material()const
	{
		return material;
	}
	void set_material(string material)
	{
		this->material = material;
	}
	Moroz_shkaf& operator=(const Moroz_shkaf& comp)
	{
		Moroz_obr::operator=(comp);
		material = comp.material;
	}
	void write_file(string word)override
	{
		Moroz_obr::write_file(word);
		ofstream file(word, ios::app);
		file << "Материал: ";
		file << material << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Moroz_obr::read_file(file);
		getline(file, material);
	}
	void zapis()override
	{
		Moroz_obr::zapis();
		cout << "Материал: ";
		cin >> material;
	}
protected:
	string material;
};

class Moroz_lar :public Moroz_obr
{
public:
	Moroz_lar() :Moroz_obr()
	{
		depth = 0;
	}
	Moroz_lar(const Moroz_lar& holod) :Moroz_obr(holod)
	{
		depth = holod.depth;
	}
	void print_information()override
	{
		Moroz_obr::print_information();
		cout << "Глубина: " << depth << endl;
	}
	int get_depth()const
	{
		return depth;
	}
	void set_depth(int depth)
	{
		this->depth = depth;
	}
	Moroz_lar& operator=(const Moroz_lar& comp)
	{
		Moroz_obr::operator=(comp);
		depth = comp.depth;
	}
	void write_file(string word)override
	{
		Moroz_obr::write_file(word);
		ofstream file(word, ios::app);
		file << "Глубина: ";
		file << depth << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Moroz_obr::read_file(file);
		file >> depth;
	}
	void zapis()override
	{
		Moroz_obr::zapis();
		cout << "Глубина: ";
		cin >> depth;
	}
protected:
	int depth;
};

class Moroz_indikat :public Moroz_shkaf
{
public:
	Moroz_indikat() :Moroz_shkaf()
	{
		indikat = "";
	}
	Moroz_indikat(const Moroz_indikat& holod) :Moroz_shkaf(holod)
	{
		indikat = holod.indikat;
	}
	void print_information()override
	{
		Moroz_shkaf::print_information();
		cout << "Наличие индикации температуры: " << indikat << endl;
	}
	string get_indikat()const
	{
		return indikat;
	}
	void set_indikat(string indikat)
	{
		this->indikat = indikat;
	}
	Moroz_indikat& operator=(const Moroz_indikat& comp)
	{
		Moroz_shkaf::operator=(comp);
		indikat = comp.indikat;
	}
	void write_file(string word)override
	{
		Moroz_indikat::write_file(word);
		ofstream file(word, ios::app);
		file << "Наличие индикации температуры: ";
		file << indikat << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Moroz_indikat::read_file(file);
		getline(file, indikat);
	}
	void zapis()override
	{
		Moroz_shkaf::zapis();
		cout << "Наличие индикации температуры: ";
		cin >> indikat;
	}
protected:
	string indikat;
};

class Moroz_non_indikat :public Moroz_shkaf
{
public:
	Moroz_non_indikat() :Moroz_shkaf()
	{
		shum = 0;
	}
	Moroz_non_indikat(const Moroz_non_indikat& holod) :Moroz_shkaf(holod)
	{
		shum = holod.shum;
	}
	void print_information()override
	{
		Moroz_shkaf::print_information();
		cout << "Уровень шума: " << shum << endl;
	}
	int get_shum()const
	{
		return shum;
	}
	void set_shum(int shum)
	{
		this->shum = shum;
	}
	Moroz_non_indikat& operator=(const Moroz_non_indikat& comp)
	{
		Moroz_shkaf::operator=(comp);
		shum = comp.shum;
	}
	void write_file(string word)override
	{
		Moroz_shkaf::write_file(word);
		ofstream file(word, ios::app);
		file << "Уровень шума: ";
		file << shum << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Moroz_shkaf::read_file(file);
		file >> shum;
	}
	void zapis()override
	{
		Moroz_shkaf::zapis();
		cout << "Уровень шума: ";
		cin >> shum;
	}
protected:
	int shum;
};

class Moroz_zamok :public Moroz_lar
{
public:
	Moroz_zamok() :Moroz_lar()
	{
		zamok = "";
	}
	Moroz_zamok(const Moroz_zamok& holod) :Moroz_lar(holod)
	{
		zamok = holod.zamok;
	}
	void print_information()override
	{
		Moroz_lar::print_information();
		cout << "Наличие замка: " << zamok << endl;
	}
	string get_zamok()const
	{
		return zamok;
	}
	void set_zamok(string zamok)
	{
		this->zamok = zamok;
	}
	Moroz_zamok& operator=(const Moroz_zamok& comp)
	{
		Moroz_lar::operator=(comp);
		zamok = comp.zamok;
	}
	void write_file(string word)override
	{
		Moroz_lar::write_file(word);
		ofstream file(word, ios::app);
		file << "Наличие замка: ";
		file << zamok << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Moroz_lar::read_file(file);
		getline(file, zamok);
	}
	void zapis()override
	{
		Moroz_lar::zapis();
		cout << "Наличие замка: ";
		cin >> zamok;
	}
protected:
	string zamok;
};

class Moroz_non_zamok :public Moroz_lar
{
public:
	Moroz_non_zamok() :Moroz_lar()
	{
		block = "";
	}
	Moroz_non_zamok(const Moroz_non_zamok& holod) :Moroz_lar(holod)
	{
		block = holod.block;
	}
	void print_information()override
	{
		Moroz_lar::print_information();
		cout << "Наличие блокировки от детей: " << block << endl;
	}
	string get_block()const
	{
		return block;
	}
	void set_block(string block)
	{
		this->block = block;
	}
	Moroz_non_zamok& operator=(const Moroz_non_zamok& comp)
	{
		Moroz_lar::operator=(comp);
		block = comp.block;
	}
	void write_file(string word)override
	{
		Moroz_lar::write_file(word);
		ofstream file(word, ios::app);
		file << "Наличие блокировки от детей: ";
		file << block << endl;
		file.close();
	}
	void read_file(ifstream& file)override
	{
		Moroz_lar::read_file(file);
		getline(file, block);
	}
	void zapis()override
	{
		Moroz_lar::zapis();
		cout << "Наличие блокировки от детей: ";
		cin >> block;
	}
protected:
	string block;
};

//////////////////////////////////////////////////////

template <class T>
class Vector
{
private:
	T* mas;
public:
	int i;
	Vector(int i)
	{
		this->i = i;
		mas = new T[i];
	}
	Vector(const Vector<T>& other)
	{
		i = other.i;
		mas = new T[i];
	}
	void Plus(T&& elem, int j)
	{
		mas[j] = elem;
		cout << endl;
	}
	T& operator()(int number)
	{
		if (number < 0 || number >= i)throw Problema("Выход за границы массива");
		return mas[number];
	}
	void sort(bool(*cmp)(const T& a, const T& b)) 
	{
		if (i == 0) throw Problema("Объектов нет");
		for (int j = 0; j < i - 1; j++)
		{
			for (int k = i - 1; k > j; k--)
			{
				if (sort_price(mas[k], mas[k - 1]))
				{
					swap(mas[k], mas[k - 1]);
				}
			}
		}
	}
	int length() const
	{
		return i;
	}
	void clear()
	{
		for (int j = 0; j < i; j++)
		{
			mas[j] = 0;
		}
		i = 0;
	}
	void print() 
	{
		if (i == 0) throw Problema("Объектов нет");
		for (int j = 0; j < i; j++) 
		{
			mas[j]->print_information();
		}
	}
	template<class C>
	T* Search(C value, bool(*finder)(C value, const T& comp))
	{
		if (i == 0) throw Problema("Объектов нет");
		for (int j = 0; j < i; j++) {
			if (FindByName(value, mas[j])) return &mas[j];
		}
		return nullptr;
	}
};
*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int	vibor, poka = 1, kol, i = 0, num_oshibka = 1;
	cout << "Введите количество элементов, которые хотите ввести: ";
	cin >> kol;
	Vector<IHolod*>vector(kol);
	cout << "Выберите, как хотите добавить элементы:" << endl;
	cout << "1 - ввод с клавиатуры" << endl;
	cout << "2 - ввод из файла" << endl;
	cout << "0 - выход из программы" << endl;
	cin >> vibor;
	switch (vibor)
	{
	case 0:
		return 0;
	case 1:
		while (i < kol)
		{
			cout << "Выберите, что хотите ввести:" << endl;
			cout << "1 - Холодильник" << endl;
			cout << "2 - Холодильная витрина" << endl;
			cout << "3 - Холодильник с дисплеем" << endl;
			cout << "4 - Холодильник без дисплея" << endl;
			cout << "5 - Холодильная витрина" << endl;
			cout << "6 - Холодильная витрина с камерами" << endl;
			cout << "7 - Холодильная витрина с разморозкой" << endl;
			cout << "8 - Морозильный шкаф" << endl;
			cout << "9 - Морозильный шкаф с индикацией температуры" << endl;
			cout << "10 - Морозильный шкаф без индикации температуры" << endl;
			cout << "11 - Морозильный ларь" << endl;
			cout << "12 - Морозильный ларь с замком" << endl;
			cout << "13 - Морозильный ларь с блокировкой от детей" << endl;
			int obekt;
			cin >> obekt;
			switch (obekt)
			{
			case 1:
				vector.Plus(new Holodos(), i);
				vector(i)->zapis();
				break;
			case 2:
				vector.Plus(new Holod_vitr(), i);
				vector(i)->zapis();
				break;
			case 3:
				vector.Plus(new Holod_display(), i);
				vector(i)->zapis();
				break;
			case 4:
				vector.Plus(new Holod_non_display(), i);
				vector(i)->zapis();
				break;
			case 5:
				vector.Plus(new Holod_vitr(), i);
				vector(i)->zapis();
				break;
			case 6:
				vector.Plus(new Holod_vitr_cam(), i);
				vector(i)->zapis();
				break;
			case 7:
				vector.Plus(new Holod_vitr_razmoroz(), i);
				vector(i)->zapis();
				break;
			case 8:
				vector.Plus(new Moroz_shkaf(), i);
				vector(i)->zapis();
				break;
			case 9:
				vector.Plus(new Moroz_indikat(), i);
				vector(i)->zapis();
				break;
			case 10:
				vector.Plus(new Moroz_non_indikat(), i);
				vector(i)->zapis();
				break;
			case 11:
				vector.Plus(new Moroz_lar(), i);
				vector(i)->zapis();
				break;
			case 12:
				vector.Plus(new Moroz_zamok(), i);
				vector(i)->zapis();
				break;
			case 13:
				vector.Plus(new Moroz_non_zamok(), i);
				vector(i)->zapis();
				break;
			}
			i++;
		}
		break;
	case 2:
		string put;
		cout << "Введите путь до файла: ";
		cin >> put;
		while (i < kol)
		{
			cout << "Выберите класс файла:" << endl;
			cout << "1 - Холодильник" << endl;
			cout << "2 - Холодильная витрина" << endl;
			cout << "3 - Холодильник с дисплеем" << endl;
			cout << "4 - Холодильник без дисплея" << endl;
			cout << "5 - Холодильная витрина" << endl;
			cout << "6 - Холодильная витрина с камерами" << endl;
			cout << "7 - Холодильная витрина с разморозкой" << endl;
			cout << "8 - Морозильный шкаф" << endl;
			cout << "9 - Морозильный шкаф с индикацией температуры" << endl;
			cout << "10 - Морозильный шкаф без индикации температуры" << endl;
			cout << "11 - Морозильный ларь" << endl;
			cout << "12 - Морозильный ларь с замком" << endl;
			cout << "13 - Морозильный ларь с блокировкой от детей" << endl;
			int obekt;
			cin >> obekt;
			try {
				switch (obekt)
				{
				case 1:
				{
					vector.Plus(new Holodos(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 2:
				{
					vector.Plus(new Holod_vitr(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 3:
				{
					vector.Plus(new Holod_display(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 4:
				{
					vector.Plus(new Holod_non_display(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 5:
				{
					vector.Plus(new Holod_vitr(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 6:
				{
					vector.Plus(new Holod_vitr_cam(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 7:
				{
					vector.Plus(new Holod_vitr_razmoroz(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 8:
				{
					vector.Plus(new Moroz_shkaf(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 9:
				{
					vector.Plus(new Moroz_indikat(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 10:
				{
					vector.Plus(new Moroz_non_indikat(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 11:
				{
					vector.Plus(new Moroz_lar(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 12:
				{
					vector.Plus(new Moroz_zamok(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				case 13:
				{
					vector.Plus(new Moroz_non_zamok(), i);
					ifstream is(put.c_str());
					if (!is) throw Problema("Не удаётся открыть файл");
					else
					{
						vector(i)->read_file(is);
						is.close();
					}
					break;
				}
				}
			}
			catch(Problema& beda_file)
			{
				cout << "Ошибка " << num_oshibka << endl;
				cout << beda_file.get_error() << endl;
				num_oshibka++;
			}
			i++;
		}
		break;
	}
	
	while (poka != 0)
	{
		cout << "Выберите действие:" << endl;
		cout << "1 - очистка объектов" << endl;
		cout << "2 - отсортировать по цене" << endl;
		cout << "3 - вывод всей информации об объекте" << endl;
		cout << "4 - поиск объекта" << endl;
		cout << "5 - запись в файл" << endl;
		cout << "0 - выход" << endl;
		cin >> vibor;
		string number;
		try {
			switch (vibor)
			{
			case 0:
				poka = 0;
				break;
			case 1:
				vector.clear();
				cout << "Очищено" << endl;
				break;
			case 2:
				vector.sort(sort_price);
				break;
			case 3:
				cout << "Всего элементов: " << vector.length() << endl;
				vector.print();
				break;
			case 4:
			{
				cout << "Введите название объекта: " << endl;
				cin >> number;
				IHolod** temp = vector.Search(number, FindByName);
				if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;
				else (*temp)->print_information();
				break;
			}
			case 5:
				if (vector.i == 0)throw Problema("Элементов нет");
				int num;
				string put;
				cout << "Введите номер, записываемого объекта: ";
				cin >> num;
				cout << "Укажите путь для сохранения файла: ";
				cin >> put;
				vector(num - 1)->write_file(put);
				break;
			}
		}
		catch (Problema& beda)
		{
			cout << "Ошибка " << num_oshibka << endl;
			cout << beda.get_error() << endl;
			num_oshibka++;
		}
	}
	system("pause");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
