#pragma once

namespace CalcDescompt 
{
	class Operacio 
	{
	public: 
		//Retorna resultat
		static double OperDescompt(double descompte, double resultat);
		static double NumDescompte(double preu, double descompteimport, double resultat);
	};
}
