//--------------------------------------------------------//
//----------RUN      ACTION-------------------------------//
//--------------------------------------------------------//


#include "Ht1RAction.hh"
#include "Ht1PGAction.hh"
#include "Ht1DetectorConstruction.hh"
#include "Ht1Run.hh"
#include "HistoManager.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <fstream>


Ht1RAction::Ht1RAction()
: G4UserRunAction(), fHistoManager(0)
{
output.open("routput");
output<< "EID  SID  TID SL EDep  K.E material" << G4endl;
runo.open("Average.txt");
    runo<<"This File Contains Average Quantitites\n";
fHistoManager = new HistoManager();
}



Ht1RAction::~Ht1RAction()
{
	delete fHistoManager;
}

G4Run *Ht1RAction::GenerateRun()
{
	return new Ht1Run;
}



void Ht1RAction::BeginOfRunAction(const G4Run*)
{

  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
//Starting histograms:
 G4AnalysisManager *analysisManager =G4AnalysisManager::Instance();
 if ( analysisManager->IsActive())
 {
 analysisManager->OpenFile();
 }
}




void Ht1RAction::EndOfRunAction(const G4Run* run)
{
  G4int NEvents = run->GetNumberOfEvent();
  if (NEvents == 0) return;

  const Ht1Run *HRun = static_cast<const Ht1Run*>(run);
  G4double KEf = HRun->GetKE();
  KEf = KEf/NEvents;
  G4double StepLength = HRun->GetStepL();
  StepLength = StepLength/NEvents;


//Writing to histograms
G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

// Saving histograms:
if (analysisManager ->IsActive())
{
  analysisManager->Write();
  analysisManager->CloseFile();
}
 const Ht1PGAction* generatorAction
   = static_cast<const Ht1PGAction*>
     (G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
  G4String runCondition;
  if (generatorAction)
  {
    const G4ParticleGun* particleGun = generatorAction->GetParticleGun();
    runCondition += particleGun->GetParticleDefinition()->GetParticleName();
    runCondition += " of ";
    G4double particleEnergy = particleGun->GetParticleEnergy();
    runCondition += G4BestUnit(particleEnergy,"Energy");
  }
        
  // Print
  //  
  if (IsMaster()) {
    G4cout
     << "\n--------------------End of Global Run-----------------------";
  }
  else {
    G4cout
     << "\n--------------------End of Local Run------------------------";
  }
  
}

//========================================================//

