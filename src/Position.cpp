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


Position Position::a_gauche()
{
	return Position(abscisse-1,ordonnee);
}

Position Position::a_droite()
{
	return Position(abscisse+1,ordonnee);
}

Position Position::en_haut()
{
	return Position(abscisse,ordonnee-1);
}

Position Position::en_bas()
{
	return Position(abscisse,ordonnee+1);
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




