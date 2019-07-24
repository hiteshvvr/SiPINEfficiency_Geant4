//---------------------------------------------------------//
//--------------EVENT ACTION-------------------------------//
//---------------------------------------------------------//



#include "Ht1EAction.hh"
#include "Ht1Run.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include <fstream>
#include "HistoManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include <stdio.h>
#include <time.h>

Ht1EAction::Ht1EAction()
:G4UserEventAction()
{
output.open("output");
output << "This is Photon " << G4endl;
//output<<"EID  SID  TID  SL  edep K.E. material"<<G4endl;

}



Ht1EAction::~Ht1EAction()
{}



void Ht1EAction::BeginOfEventAction(const G4Event* event) 
{
//    clock_t t;
//    t = clock();
//    G4int eventid = event->GetEventID();
//    t = clock() - t;
//    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
//    G4cout << "Time for getting event:\t" <<  time_taken << G4endl;
//    
//    t = clock();
//    if(eventid%5==0)
//    t = clock() - t;
//    double time_ataken = ((double)t)/CLOCKS_PER_SEC; // in seconds
// G4cout <<"Time for if : \t "<<  time_ataken << G4endl;
//
//    t = clock();
//    G4cout<<"Event is \t " << eventid << G4endl;
//    t = clock() - t;
//    double time_btaken = ((double)t)/CLOCKS_PER_SEC; // in seconds
// G4cout <<" Time for printing eventid: \t " << time_btaken << G4endl;
//
   G4int eventid = event->GetEventID();
   if(eventid%50000==0)
   G4cout<<"Event is \t " << eventid << G4endl;
}



void Ht1EAction::EndOfEventAction(const G4Event* event)
{
}


//======================================================//
