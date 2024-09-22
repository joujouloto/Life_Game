#include "Position.h"

#include <sstream>


Position::Position()
{
	abscisse = 0 ;
	ordonnee = 0 ;
}


Position::Position(int pAbs, int pOrd)
{
	abscisse = pAbs;
	ordonnee = pOrd;
	
}


int Position::getAbscisse()
{
	return abscisse;
}

int Position::getOrdonnee()
{
	return ordonnee;
}

string Position::toString()
{
	stringstream ss;
	
	
	ss << getAbscisse();
	ss << "x";
	ss << getOrdonnee();
	

	return ss.str();
}

bool Position::operator < (const Position &other ) const
{
	
	if(abscisse != other.abscisse )
	{
		return abscisse < other.abscisse;
	}
	else
	{
		return ordonnee < other.ordonnee;
	}
	
	
	
	
	
}




