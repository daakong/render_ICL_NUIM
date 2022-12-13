/*
  Persistence of Vision Ray Tracer Scene Description File

  Tierra v1.0 - Sky & Sun include

  --   
  Jaime Vives Piqueres, Apr-2003.

  Notes:
   + scene scale : 1 unit = 1 km

*/

// *** sky sphere and sun using CIE_Skylight and sunpos.inc ***
// random position
#ifndef(Al)    #declare Al=int(90*rand(r_sun)); #end
#ifndef(Az)    #declare Az=int(360*rand(r_sun)); #end
#ifndef(North) #declare North=<-1+2*rand(r_sun),0,-1+2*rand(r_sun)>; #end
#declare Current_Turbidity=3;
#declare Intensity_Mult   =50; 
#declare Max_Vertices=   500; 
#include "CIE_Skylight"
#declare c_sun=Blackbody(2500+5000*Al/90);
light_source{ 
 SolarPosition, Light_Color(c_sun,1000)
 parallel point_at 0
}
