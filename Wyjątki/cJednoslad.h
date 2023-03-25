#pragma once
#include <iostream>
#include <exception>
using namespace std;

enum class EXCEPTION_CODE
{
	rozmiarError
};

class cJednoslad
{
protected:
	float rozmiar_kola;
	char nazwa[30];

public:
	cJednoslad();
	cJednoslad(float rk, const char* n);
	virtual void wypiszDane();
	void sprawdz();
	~cJednoslad();
};

class cRower : protected cJednoslad
{
protected:
	int przerzutki_tyl, przerzutki_przod;

public:
	cRower();
	cRower(float rk, const char* n, int pt, int pp);
	void wypiszDane();
	~cRower();
	cJednoslad::sprawdz;
};

class cMotor :public cJednoslad
{
protected:
	int poj_silnika, max_predkosc;

public:
	cMotor();
	cMotor(int ps, int mp, float rk,const char* n);
	~cMotor();
	void wypiszMotor();
	int getPojSilnika();
	void setPojSilnika(int ps);
	int getMaxPredkosc();
	void setMaxPredkosc(int mp);
	
};

class cGorski :public cRower
{
private:
		int rozmiar_ramy;

public:
	cGorski();
	cGorski(int rr, float rk, const char* n, int pt, int pp) ;
	~cGorski();
	void wypiszGorski();
	int getRozmiarRamy();
	void setRozmiarRamy(int rr);

};

class cMotorower : protected cMotor, protected cRower
{
private:
	string dodNaped;
public:
	cMotorower();
	cMotorower(string dodNap, int ps, int mp, float rk, const char* n, int pt, int pp) ;
	void wypiszMotorower();
	string getDodatkowyNaped();
	void setDodatkowyNaped(string dn);


};


namespace MyRuntimeExceptions
{
	
	class out_of_range : public runtime_error {
	public:
		out_of_range() :runtime_error("\nNiepoprawna predkosc dla motoru")
		{}
	};	
}

