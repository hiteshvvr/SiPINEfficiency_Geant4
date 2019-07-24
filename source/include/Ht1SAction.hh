





























#ifndef Ht1SAction_h
#define Ht1SAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include "Ht1RAction.hh"
#include <fstream>
class Ht1EAction;

class G4LogicalVolume;




class Ht1SAction : public G4UserSteppingAction
{
  public:
  	Ht1SAction(Ht1RAction *runaction, Ht1EAction *eventAction );
	virtual ~Ht1SAction();


	virtual void UserSteppingAction(const G4Step*);

  private:
	Ht1RAction *hRAction;
  	Ht1EAction *fEventAction;
	G4LogicalVolume *fScoringVolume;
};



#endif
