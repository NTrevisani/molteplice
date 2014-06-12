//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: ExN01DetectorConstruction.cc,v 1.9 2006-06-29 17:47:19 gunter Exp $
// GEANT4 tag $Name: geant4-09-04-patch-02 $
//

#include "ExN01DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "ExN01CreateTree.hh"

ExN01DetectorConstruction::ExN01DetectorConstruction()
 :  worldLog(0), absLog(0),
    worldPhys(0), absPhys(0)
{;}

ExN01DetectorConstruction::~ExN01DetectorConstruction()
{
}

G4VPhysicalVolume* ExN01DetectorConstruction::Construct()
{

  //------------------------------------------------------ materials

G4String name, symbol;
G4double z, a, density,fractionmass;
G4int ncomponents, natoms;
double X_0 = 0.0143;

//defining Cu
density = 8.96*g/cm3;
a = 63.546*g/mole;
G4Element* elCu  = new G4Element(name="Copper"  ,symbol="Cu" , z= 29., a);
G4Material* Cu = new G4Material(name="Cu", z=29., a, density);

//defining O and O2
density = 0.001429*g/cm3;
a = 15.9994*g/mole;
G4Element* elO  = new G4Element(name="Oxygen"  ,symbol="O" , z= 8., a);

//defining N and N2
density = 0.001251*g/cm3;
a = 14.0067*g/mole;
G4Element* elN  = new G4Element(name="Nitrogen"  ,symbol="N" , z= 7., a);

//defining air
density = 0.001275*g/cm3;
G4Material* Air = new G4Material(name="Air",density,ncomponents=2);

Air->AddElement(elN, fractionmass=70.*perCent);
Air->AddElement(elO, fractionmass=30.*perCent);

  //------------------------------------------------------ experimental apparatus

//defining world environment
G4double world_hx = 0.2*m;
G4double world_hy = 0.2*m;
G4double world_hz = 100*X_0*m;

G4Box* worldBox = new G4Box("World", world_hx, world_hy, world_hz);
G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, Air, "World");
G4PVPlacement* worldPhys = new G4PVPlacement(0,G4ThreeVector(),worldLog,"World",0,false,0);

//defining absorber

G4double abs_hx = 0.2*m;
G4double abs_hy = 0.2*m;
G4double abs_hz = 0.5*X_0*m;

G4Box* absBox = new G4Box("Abs", abs_hx, abs_hy, abs_hz);
G4LogicalVolume* absLog = new G4LogicalVolume(absBox, Cu, "Abs");

G4double pos_x =  0.0*meter;
G4double pos_y =  0.0*meter;
G4double pos_z =  0.5*0.5*X_0*meter;

G4PVPlacement* absPhys = new G4PVPlacement(0,G4ThreeVector(pos_x, pos_y, pos_z),absLog,"Abs",worldLog,false,0);

//defining detector

G4double innerRadius = 0.*cm;
G4double outerRadius = 0.9*cm;
G4double hz = 3*X_0*m;
G4double startAngle = 0.*deg;
G4double spanningAngle = 360.*deg;

G4Tubs* detTube = new G4Tubs("Det", innerRadius, outerRadius, hz, startAngle, spanningAngle);
G4LogicalVolume* detLog = new G4LogicalVolume(detTube, Air, "Det");

pos_x =  0.*meter;
pos_y =  0.*meter;
pos_z =  (1.75*X_0 + 0.03)*meter;

G4PVPlacement* detPhys = new G4PVPlacement(0,G4ThreeVector(pos_x, pos_y, pos_z),detLog,"Det",worldLog,false,0);


  //------------------------------------------------------------------

  return worldPhys;
}

