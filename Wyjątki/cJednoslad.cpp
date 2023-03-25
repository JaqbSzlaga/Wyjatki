#include "cJednoslad.h"



cJednoslad::cJednoslad()
{
	rozmiar_kola = 0;
	strcpy_s(nazwa, "unknown");
}

cJednoslad::cJednoslad(float rk, const char* n) : rozmiar_kola(rk)
{
	strcpy_s(nazwa, n);
}

void cJednoslad::wypiszDane()
{
	cout << endl << rozmiar_kola << "Rozmiar kola: " << endl << "Nazwa" << nazwa << endl;
}

void cJednoslad::sprawdz()
{
}


cJednoslad::~cJednoslad()
{
}

cRower::cRower()
{
	przerzutki_przod = 0;
	przerzutki_tyl = 0;
}

cRower::cRower(float rk, const char* n, int pt, int pp) :
	cJednoslad(rk, n), przerzutki_tyl(pt), przerzutki_przod(pp)
{}

void cRower::wypiszDane()
{
	cout << endl << "Rozmiar kola: " << rozmiar_kola << endl << "Nazwa: " << nazwa<<endl << "Przerzutki_przod: "
		<< przerzutki_przod <<endl<< "Przerzutki_tyl:  " << przerzutki_tyl << endl;
}

cRower::~cRower()
{
}

cMotor::cMotor()
{
	rozmiar_kola = 0;
	strcpy_s(nazwa, "unknown");
	poj_silnika = 0;
	max_predkosc = 0;
}

cMotor::cMotor(int ps, int mp, float rk,const char* n)
{
	rozmiar_kola = rk;
	strcpy_s(nazwa, n);
	poj_silnika = ps;
	max_predkosc = mp;
	try
	{
		if (max_predkosc > 290 || max_predkosc < 0)
		{
			throw out_of_range("\nNiepoprawna predkosc dla motoru, przypisanie wartosci domyslnej");
		}
	}
	catch (std::exception& e)
	{
		cerr << e.what();
		max_predkosc=0;
	}
	
}

cMotor::~cMotor()
{
}

void cMotor::wypiszMotor()
{
	cout << "\n\nDane Motoru: ";
	cout << "\nRozmiar kola: " << rozmiar_kola;
	cout << "\nNazwa motoru: " << nazwa;
	cout << "\nPojemnosc silnika: " << poj_silnika;
	cout << "\nMaksymalna predkosc: " << max_predkosc;

}

int cMotor::getPojSilnika()
{
	return poj_silnika;
}

void cMotor::setPojSilnika(int ps)
{
	poj_silnika = ps;
}

int cMotor::getMaxPredkosc()
{
	return max_predkosc;
}

void cMotor::setMaxPredkosc(int mp)
{
	max_predkosc = mp;
}



cGorski::cGorski()
{
	rozmiar_ramy = 0;
}

cGorski::cGorski(int rr, float rk, const char* n, int pt, int pp)
{
	rozmiar_kola = rk;
	rozmiar_ramy = rr;
	strcpy_s(nazwa, n);
	przerzutki_przod = pp;
	przerzutki_tyl = pt;
	try
	{
		if (rozmiar_ramy > 22 || rozmiar_ramy < 19)
		{
			throw EXCEPTION_CODE::rozmiarError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		switch (error)
		{
		case EXCEPTION_CODE::rozmiarError:
			cerr << "\n\nNiepoprawny rozmiar ramy dla roweru, przypisanie wartosci domyslnej. ";

			break;
		default:
			cerr << "\nNieznany blad: ";
			break;
		}
		rozmiar_ramy = 19;
	}
}

cGorski::~cGorski()
{
}

void cGorski::wypiszGorski()
{
	cout << "\n\nDane roweru gorskiego: ";
	cRower::wypiszDane();
	cout << "Rozmiar ramy: " << rozmiar_ramy;
	
}

int cGorski::getRozmiarRamy()
{
	return rozmiar_ramy;
}

void cGorski::setRozmiarRamy(int rr)
{
	rozmiar_ramy = rr;
}

cMotorower::cMotorower()
{
	dodNaped = "unknown";
}

cMotorower::cMotorower(string dodNap, int ps, int mp, float rk, const char* n, int pt, int pp):cRower(rk,n,pt,pp),cMotor(ps,mp,rk,n)
{
	dodNaped =dodNap;
}

void cMotorower::wypiszMotorower()
{
	cout << "\n\nDane motoroweru: ";
	cRower::wypiszDane();
	cout << "Pojemnosc silnika: " << poj_silnika << "\nMaksymalna predkosc: " << max_predkosc << "\nDodatkwy naped: " << dodNaped;
	
	
}

string cMotorower::getDodatkowyNaped()
{
	return string(dodNaped);
}

void cMotorower::setDodatkowyNaped(string dn)
{
	dodNaped = dn;
}


