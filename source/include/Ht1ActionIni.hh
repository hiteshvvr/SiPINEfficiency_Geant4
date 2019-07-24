





























#ifndef Ht1ActionIni_h
#define Ht1ActionIni_h 1

#include "G4VUserActionInitialization.hh"



class Ht1ActionIni : public G4VUserActionInitialization
{
	public:
		Ht1ActionIni();
		virtual ~Ht1ActionIni();

		virtual void BuildForMaster() const;
		virtual void Build() const;
};



#endif

//==================================================================
