





























#ifndef Ht1PGAction_h
#define Ht1PGAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4Box;






class Ht1PGAction : public G4VUserPrimaryGeneratorAction
{
  public:
  	Ht1PGAction();
	virtual ~Ht1PGAction();


	virtual void GeneratePrimaries(G4Event*);


	const G4ParticleGun *GetParticleGun() const { return fParticleGun;}

  private:
  	G4ParticleGun *fParticleGun;
	G4Box *fEnvelopeBox;
};



#endif


