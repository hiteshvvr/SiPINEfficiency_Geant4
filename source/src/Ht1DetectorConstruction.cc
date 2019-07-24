//
//
//
//

























#include "Ht1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4Cons.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4UnitsTable.hh"
#include "G4PhysicalConstants.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

Ht1DetectorConstruction::Ht1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

Ht1DetectorConstruction::~Ht1DetectorConstruction()
{ }


G4VPhysicalVolume* Ht1DetectorConstruction::Construct()
{ G4double atomicNumber =1.;
  G4double massOfMole = 1.008*g/mole;
  G4double temperature = 2.73*kelvin;
  G4double pressure = 3.e-18*pascal;
  G4double density = universe_mean_density;

  G4NistManager* nist = G4NistManager::Instance();
  G4double env_SXY = 30*cm, env_SZ=40*cm;
  G4Material *env_M = new G4Material("E_InterGalactic", atomicNumber,massOfMole,density,kStateGas,temperature,pressure);
  // G4Material *env_M = nist->FindOrBuildMaterial("G4_AIR");
  G4bool checkOverlaps = true;

//-------------------------------------------------------
//			WORLD
//------------------------------------------------------

  G4double world_SXY = 1.2*env_SXY;
  G4double world_SZ = 1.2*env_SZ;
  //G4Material *world_M= nist->FindOrBuildMaterial("G4_AIR");
  G4Material *world_M= new G4Material("W_InterGalactic", atomicNumber,massOfMole,density,kStateGas,temperature,pressure);

  G4Box *SWorld=
	 new G4Box("World",0.5*world_SXY,0.5*world_SXY,0.5*world_SZ);
  
  G4LogicalVolume *LWorld=
	 new G4LogicalVolume(SWorld,
	 		     world_M,
			     "World");
  G4VPhysicalVolume *PWorld=
  	new G4PVPlacement(0,
			     G4ThreeVector(),
			     LWorld,
			     "World",
			     0,
			     false,
			     0,
			     checkOverlaps);

//-----------------------------------------------------------
//			ENVELOPE
//-----------------------------------------------------------
  G4Box *SEnv=
       new G4Box("Env",0.5*env_SXY,0.5*env_SXY,0.5*env_SZ);
  G4LogicalVolume *LEnv = 
       new G4LogicalVolume(SEnv,
       			   env_M,
			   "Env");
			   
  	 new G4PVPlacement(0,
       			   G4ThreeVector(),
			   LEnv,
			   "Env",
			   LWorld,
			   false,
			   0,
			   checkOverlaps);
//--------------------------------------------------------------
//                      DETECTOR 
//--------------------------------------------------------------
// G4Material *Target_M = nist->FindOrBuildMaterial("G4_Pb");
G4ThreeVector pos2 = G4ThreeVector(0*cm, 0*cm, 0*cm);
G4Material *Det_M= nist->FindOrBuildMaterial("G4_Al");

// G4Box *STarget= new G4Box("target",10*mm,10*mm,0.000003616*mm);
// G4Sphere* pmt_window = new G4Sphere("pmt_sphere", 0.*cm, 2.*pmtRadius, 0.*deg, 360.*deg, 0.*deg, 30.0*deg);
// G4Sphere *STarget= new G4Sphere("target",0.*cm, 2.*cm, 0.*deg, 360.*deg, 0.*deg, 30.0*deg);
// G4Sphere* STarget= new G4Sphere("target", 0.*cm, 2.*pmtRadius, 0.*deg, 360.*deg, 0.*deg, 30.0*deg);
//G4VSolid *SDet= new G4Sphere("detector" , 70.6 * cm , 70.7 * cm , 0 * deg, 360.0 * deg, 50.0 * deg, 10.0 * deg);
G4Sphere *SDet= new G4Sphere("detector" , 77.0000 * mm , 77.0101 * mm , 0 * deg, 360.0 * deg, 47.5 * deg, 15.0 * deg);
// G4double shape1_rmina =  0.*cm, shape1_rmaxa = 2.*cm;
//  G4double shape1_rminb =  0.*cm, shape1_rmaxb = 4.*cm;
//  G4double shape1_hz = 0.1*cm;
//  G4double shape1_phimin = 0.*deg, shape1_phimax = 360.*deg;
//  G4Cons* SDet=    
//    new G4Cons("detector", 
//    shape1_rmina, shape1_rmaxa, shape1_rminb, shape1_rmaxb, shape1_hz,
//    shape1_phimin, shape1_phimax);
 
G4LogicalVolume *LDet= 
	new G4LogicalVolume(SDet,
			    Det_M,
			    "detector");
	new G4PVPlacement(0,
			 pos2,
			 LDet,
			 "detector",
			 LEnv,
			 false,
			 0,
			 checkOverlaps);
//--------------------------------------------------------------
//                       TARGET
//--------------------------------------------------------------
G4Material *Target_M = nist->FindOrBuildMaterial("G4_C");
G4ThreeVector pos1 = G4ThreeVector(0*cm, 0*cm, 0*cm);

G4Box *STarget= new G4Box("target",5*mm,5*mm,0.5*mm);
//visAttributes = new G4VisAttributes(G4Colour(1.0,0.0,1.0));
// G4Sphere* pmt_window = new G4Sphere("pmt_sphere", 0.*cm, 2.*pmtRadius, 0.*deg, 360.*deg, 0.*deg, 30.0*deg);
// G4Sphere *STarget= new G4Sphere("target",0.*cm, 2.*cm, 0.*deg, 360.*deg, 0.*deg, 30.0*deg);
// G4Sphere* STarget= new G4Sphere("target", 0.*cm, 2.*pmtRadius, 0.*deg, 360.*deg, 0.*deg, 30.0*deg);
// G4VSolid *STarget= new G4Sphere("target" , 1.6 * cm , 2.0 * cm , 0.0 * deg, 270.0 * deg, 0.0 * deg, 100.0 * deg);
G4LogicalVolume *LTarget = 
	new G4LogicalVolume(STarget,
			    Target_M,
			    "target");
	new G4PVPlacement(0,
			 pos1,
			 LTarget,
			 "target",
			 LEnv,
			 false,
			 0,
			 checkOverlaps);
 //       LTarget->SetVisAttributes(visAttributes);


//-----------------------------------------------------------------
//			SCORING VOLUME
//-----------------------------------------------------------------

fScoringVolume = LDet;
fScoringVolume = LTarget;

//-----------------------------------------------------------------
//		Return physical world
//----------------------------------------------------------------

return PWorld;
}
//===================================================================

