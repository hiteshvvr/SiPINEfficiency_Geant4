//--------------------------------------------------------//
//----------STEPPING ACTION-------------------------------//
//--------------------------------------------------------//


#include "Ht1RAction.hh"
#include "Ht1SAction.hh"
#include "Ht1EAction.hh"
#include "Ht1DetectorConstruction.hh"
#include "Ht1Run.hh"
#include "HistoManager.hh"
#include <fstream>
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
//#include "G4PhysicalConstants.hh"
//#include "G4Material.hh"
//#include "G4Element.hh"

using namespace std;

Ht1SAction::Ht1SAction(Ht1RAction* runaction, Ht1EAction* EAction )
: G4UserSteppingAction(),
  hRAction(runaction),
  fEventAction(EAction),
  fScoringVolume(0)
{
}



Ht1SAction::~Ht1SAction()
{}



void Ht1SAction::UserSteppingAction(const G4Step* step)
{
 if (!fScoringVolume)
{
   const Ht1DetectorConstruction* DConstruction 
    = static_cast<const Ht1DetectorConstruction*>
      (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
   fScoringVolume = DConstruction->GetScoringVolume();
}

G4LogicalVolume* volume
   = step->GetPreStepPoint()->GetTouchableHandle()
     ->GetVolume()->GetLogicalVolume();

//Getting track
G4Track *track =step->GetTrack();
//G4double stepl = step->GetStepLength();
//G4double stepid = track->GetCurrentStepNumber();
//Getting particle definition
G4ParticleDefinition *fpParticleDefinition = track->GetDefinition();
int PDGEncoding = fpParticleDefinition->GetPDGEncoding();

//if(PDGEncoding == 11 ){
//        G4double Kenergy = track->GetKineticEnergy();
//    fEventAction->output<<stepl/meter<<G4endl;
//    G4cout<<Kenergy/keV<<"\t"<<stepid<<"\t"<<stepl/meter<<G4endl;
//}
//Kinetic Energy of X-rays:
 if(PDGEncoding == 22 )
{
 if(step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()=="Env" && step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetName() == "detector")
 {
  G4double Kenergy = track->GetKineticEnergy();
  G4AnalysisManager::Instance()->FillH1(5,Kenergy);
 // fEventAction->output<<"Track \t" <<trackid<< "\t" << track->GetCreatorProcess()->GetProcessName()<<G4endl;
 // fEventAction->output<<"Step \t" <<stepid<<"\t"<< step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName()<<G4endl;
//fEventAction-> output << Kenergy << /*"\t" << mat1 << "\t" << mat2 << "\t" <<*/ G4endl;
 }
} 

// IF ITS NOT SCORING VOLUME THEN EXIT 
    if (volume != fScoringVolume) return;
}  //======================================================//
