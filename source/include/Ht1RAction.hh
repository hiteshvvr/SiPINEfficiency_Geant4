

#ifndef Ht1RAction_h
#define Ht1RAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <fstream>

class G4Run;
class G4LogicalVolume;
class HistoManager;


class Ht1RAction : public G4UserRunAction
{
  public:
  	Ht1RAction();
	virtual ~Ht1RAction();

	virtual G4Run* GenerateRun();
	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
//        void StepLength(G4double event, G4double stepl);
	std::ofstream output;
        std::ofstream runo;

  private:
  HistoManager* fHistoManager;
//	void GetHRAction();
 //private:
  //      static G4ThreadLocal Ht1RAction* hrunaction;

};



#endif

