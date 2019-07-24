





























#ifndef Ht1DetectorConstruction_h
#define Ht1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;



class Ht1DetectorConstruction : public G4VUserDetectorConstruction
{
   public:
     Ht1DetectorConstruction();
     virtual ~Ht1DetectorConstruction();

     virtual G4VPhysicalVolume *Construct();

     G4LogicalVolume *GetScoringVolume() const { return fScoringVolume;}
   
   protected:
     G4LogicalVolume *fScoringVolume;
};



#endif

