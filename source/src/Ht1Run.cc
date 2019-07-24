


#include "Ht1Run.hh"
#include <fstream>
using namespace std;


Ht1Run::Ht1Run()
: G4Run(),
  fEdep(0.),
  fEdep2(0.),
  KEtotal(0.),
  SLTot(0.)
{
//file1.open("out.txt");
}



Ht1Run::~Ht1Run()
{}



void Ht1Run::Merge(const G4Run* run)
{
  const Ht1Run* LRun = static_cast<const Ht1Run*>(run);
  fEdep += LRun->fEdep;
  fEdep2 += LRun->fEdep2;
  KEtotal += LRun->KEtotal;
  SLTot += LRun->SLTot;

  G4Run::Merge(run);
}



void Ht1Run::AddEdep (G4double edep)
{
   //fG4int NEvnt = run->GetNumberOfEvent();
   fEdep += edep;
   fEdep2 += edep*edep;
 //  file1<< "Energy in local run  : "<< edep << "\t Energy in complete run:" << fEdep << endl;
}

void Ht1Run::AddKEnergy(G4double Kenergy)
{
    KEtotal += Kenergy;
}

void Ht1Run::AddStepLength(G4double stepl)
{
    SLTot += stepl;
}


//========================================================//
