

#include "Ht1ActionIni.hh"
#include "Ht1PGAction.hh"
#include "Ht1RAction.hh"
#include "Ht1EAction.hh"
#include "Ht1SAction.hh"



Ht1ActionIni::Ht1ActionIni()
 : G4VUserActionInitialization()
 {}



 Ht1ActionIni::~Ht1ActionIni()
 {}



 void Ht1ActionIni::BuildForMaster() const
 {
 	SetUserAction(new Ht1RAction);
 }



 void Ht1ActionIni::Build() const
 {
 	SetUserAction(new Ht1PGAction);

         Ht1RAction *raction = new Ht1RAction;
         SetUserAction(raction);

	Ht1EAction *eAction = new Ht1EAction;
	SetUserAction(eAction);

	SetUserAction(new Ht1SAction(raction, eAction));
}

//================================================================

