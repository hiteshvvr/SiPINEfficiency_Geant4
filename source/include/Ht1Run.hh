





























#ifndef Ht1Run_h
#define Ht1Run_h 1

#include "G4Run.hh"
#include "globals.hh"
#include <fstream>
using namespace std;
class G4Event;




class Ht1Run : public G4Run
{
  public:
  	Ht1Run();
	virtual ~Ht1Run();


	virtual void Merge(const G4Run*);

	void AddEdep (G4double edep);
        void AddKEnergy(G4double Kenergy);
        void AddStepLength(G4double stepl);


	G4double GetEdep() const { return fEdep;}
	G4double GetEdep2() const {return fEdep2;}
        G4double GetKE() const {return KEtotal;}
        G4double GetStepL() const {return SLTot;}
	ofstream file1;

  private:
  	G4double fEdep;
	G4double fEdep2;
        G4double KEtotal;
        G4double SLTot;
};



#endif
//==================================================================//
