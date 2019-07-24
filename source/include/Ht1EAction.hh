//---------------------------------------------------------//
//--------------EVENT ACTION  HEADER-----------------------//
//---------------------------------------------------------//


#ifndef Ht1EAction_h
#define Ht1EAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include <fstream>




class Ht1EAction : public G4UserEventAction
{
	public:
	 Ht1EAction();
	 virtual ~Ht1EAction();

	 virtual void BeginOfEventAction(const G4Event *event);
	 virtual void EndOfEventAction(const G4Event *event);
	 
         std::ofstream output; 
	private:
};



#endif

//==================================================================//
