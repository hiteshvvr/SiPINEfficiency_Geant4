//---------------------------------------------------
//---------------------------------------------------


#include "Ht1DetectorConstruction.hh"
#include "Ht1ActionIni.hh"
#include "Ht1RAction.hh"
#include "Ht1EAction.hh"
#include "Ht1SAction.hh"
#include "Ht1PGAction.hh"
#include "XrayFluoPhysicsList.hh"
//#include "G4EmPenelopePhysics.hh"
//Adding PhysicsList 
//#include "PhysicsList.hh"
//#include "PhysicsListMessenger.hh"

//#include "PhysListEmStandard.hh"
//#include "PhysListEmLivermore.hh"
//#include "PhysListEmPenelope.hh"
//#include "Ht1PhysicsList.hh"
//#include "HistoManager.hh"
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
//#include "QBBC.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "Randomize.hh"
#include "G4LossTableManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

int main(int argc, char** argv)
{
  //Choosing the random engine
  //
  G4Random::setTheEngine(new CLHEP::RanecuEngine);
// Randomizeing 
long seeds[2]={3833889,309430948};
time_t systime = time(NULL);
seeds[0] = (long) systime;
seeds[1] = (long) (systime*G4UniformRand());
G4cout << "seed1: " << seeds[0] << "; seed2: " << seeds[1] << G4endl;
CLHEP::HepRandom::setTheSeeds(seeds);
CLHEP::HepRandom::showEngineStatus();
	

  //Constructing the default run manager
  //
#ifdef G4MULTITHREADED
  G4MTRunManager *RManager = new G4MTRunManager;
#else
  G4RunManager *RManager = new G4RunManager;
#endif
  
  // Setting Mandatory initialization classes
 
 // Constructing Detector
  RManager->SetUserInitialization(new Ht1DetectorConstruction());

  //Physics List
//  G4VModularPhysicsList *Ht1physicsList = new QBBC;
//  Ht1physicsList->SetVerboseLevel(1);
//  RManager->SetUserInitialization(Ht1physicsList);
// New PhysicsList:
//XrayFluoPhysicsList *xrayList = new XrayFluoPhysicsList();
//G4EmPenelopePhysics  *Ht1physicsList = new G4EmPenelopePhysics();
//Giving PhysicsList to RunManager:
//RManager->SetUserInitialization(new G4EmPenelopePhysics);
//RManager->SetUserInitialization(new PhysListEmPenelope);
RManager->SetUserInitialization(new XrayFluoPhysicsList());
//User action initializing
RManager->SetUserInitialization( new Ht1ActionIni());

  // Initiating G4 Kernel

//RManager->Initialize();

#ifdef G4VIS_USE
  // Initializing visualization
  G4VisManager *VManager = new G4VisExecutive;


  VManager->Initialize();
#endif

//Getting pointer to User Interface manager
  G4UImanager *UIManager = G4UImanager::GetUIpointer();

  if (argc!=1) {

  	G4String command = "/control/execute ";
  	G4String filename = argv[1];
  	UIManager->ApplyCommand(command+filename);
  }
  else {

#ifdef G4UI_USE
	G4UIExecutive *ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
	UIManager->ApplyCommand("/control/execute init_vis.mac");
#else
	UIManager->ApplyCommand("/control/execute init.mac");
#endif 
	ui->SessionStart();
//	delete ui;
#endif
  }





  //Terminating job
#ifdef G4VIS_USE
	delete VManager;
#endif
	delete RManager;

	return 0;
}

//========================================================//
