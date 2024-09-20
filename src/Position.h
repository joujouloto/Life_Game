#ifndef POSITION_H
#define POSITION_H


//-------------------------------------------------

#include <string>



//------------------------------------------------

using namespace std;


class Position
{
	protected:
	
	int abscisse;
	int ordonnee;
	
	public:
	
	Position();
	Position(int abs, int ord);
	int getAbscisse();
	int getOrdonnee();
	string toString();
	
	
	
};



#endif