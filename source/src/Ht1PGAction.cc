





























#include "Ht1PGAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"



Ht1PGAction::Ht1PGAction()
:G4VUserPrimaryGeneratorAction(),
 fParticleGun(0),
 fEnvelopeBox(0)
{
 G4int n_P = 1;
 fParticleGun = new G4ParticleGun(n_P);


 G4ParticleTable *PTable = G4ParticleTable::GetParticleTable();
 G4String PName;
 G4ParticleDefinition *P 
     = PTable->FindParticle(PName="e-");
 fParticleGun->SetParticleDefinition(P);
 fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
 fParticleGun->SetParticleEnergy(100.*keV);
}



Ht1PGAction::~Ht1PGAction()
{
	delete fParticleGun;
}



void Ht1PGAction::GeneratePrimaries(G4Event* anEvent)
{







  G4double Env_SXY = 0;
  G4double Env_SZ = 0;

  if (!fEnvelopeBox)
  {
  	G4LogicalVolume *Env_LV
	  = G4LogicalVolumeStore::GetInstance()->GetVolume("Env");
	if ( Env_LV) fEnvelopeBox = dynamic_cast<G4Box*>(Env_LV->GetSolid());
  }

  if ( fEnvelopeBox ) {
  	Env_SXY = fEnvelopeBox->GetXHalfLength()*2.;
	Env_SZ = fEnvelopeBox->GetZHalfLength()*2.;
  }

/*  else	{
   G4ExceptionDescription msg;
   msg << "Envelope volume of box shape not found. \n";
   msg << " Perhaps you have changed Geometry. \n";
   msg << " The gun will be placed at the centre. \n ";
   G4Exception("Ht1PGAction::GeneratePrimaries()",
     "MyCode0002",JustWarning,msg);
  }
*/
  G4double size = 4.0*mm;
  G4double x0 = size *  (G4UniformRand()-0.5);
  G4double y0 = size *  (G4UniformRand()-0.5);
  G4double z0 = 25*cm +  0*0.5 * Env_SZ;
  G4double r= x0*x0+y0*y0;
  if(r<4)
  {
      fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  }
  else
  {
 //     G4cout<< "I have writtedn this\n";
      fParticleGun->SetParticlePosition(G4ThreeVector(0,0,z0));
  }

  fParticleGun->GeneratePrimaryVertex(anEvent);
  }
  

  //======================================================//
