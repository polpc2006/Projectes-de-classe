//CalculadoraDescomptes.cpp

#include "CalculadoraDescomptes.h"

namespace CalcDescompt 
{
	double Operacio::OperDescompt(double preu, double descompte)
	{
		double resultat;

		descompte = descompte / 100;
		resultat = preu * descompte;
		resultat = preu - resultat;

		return resultat;
	}
	double Operacio::NumDescompte(double preu, double descompteimport, double resultat) 
	{
		descompteimport = preu - resultat;

		return descompteimport;
	}

}