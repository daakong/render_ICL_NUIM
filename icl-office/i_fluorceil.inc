/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Fluorescent panels

*/

// wings grille
#include "i_lampcase_fl.inc"

// panel case
#declare f_lampcase=
union{
 object{fluor_lamp_case 
  no_shadow hollow 
  rotate 180*x rotate 90*y scale <25,10,25> translate -2.5*y
 }
 difference{
  box{-.5,.5}
  box{-.5,.5 scale <.9,1.01,.9>}
  scale <50,1.2,50>
  texture{t_aluminum}
  translate -5*y
 }
 box{-1,1
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission c_fluor*lm_fluor*Lightsys_Brightness*.001
     }
   }
  hollow
  no_shadow
  double_illuminate
  scale <24,5,24>
 }
 union{
 cylinder{<0,0,-24>,<0,0,24>,3
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission c_fluor*lm_fluor*Lightsys_Brightness*.002
     }
   }
   hollow no_shadow double_illuminate
   translate -6.25*3*x
 }
 cylinder{<0,0,-24>,<0,0,24>,3
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission c_fluor*lm_fluor*Lightsys_Brightness*.002
     }
   }
   hollow no_shadow double_illuminate
   translate -6.25*x
 }
 cylinder{<0,0,-24>,<0,0,24>,3
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission c_fluor*lm_fluor*Lightsys_Brightness*.002
     }
   }
   hollow no_shadow double_illuminate
   translate 6.25*x
 }
 cylinder{<0,0,-24>,<0,0,24>,3
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission c_fluor*lm_fluor*Lightsys_Brightness*.002
     }
   }
   hollow no_shadow double_illuminate
   translate 6.25*3*x
 }
 translate 3*y
 }
}

// whole panel
#declare fluorescent=
union{
 object{f_lampcase}
 object{Light(c_fluor,lm_fluor*2,<8,0,0>,<0,0,8>,use_area*2,use_area*2,1) translate <0,-5,0>}
}

// all the panels
#declare fluorescent_panels=
union{
#if (use_fluoresc<2)
object{fluorescent translate <-125,245, 275>}
object{fluorescent translate <-125,245,  75>}
object{fluorescent translate <-125,245, -75>}
object{fluorescent translate < -75,245,-275>}
object{fluorescent translate < -75,245, 275>}
object{fluorescent translate <-125,245, 125>}
object{fluorescent translate <-125,245,-125>}
object{fluorescent translate <-125,245,-275>}
#end
object{fluorescent translate <  75,245,-275>}
object{fluorescent translate <  75,245, 275>}
object{fluorescent translate < 125,245, 275>}
object{fluorescent translate < 125,245,  75>}
object{fluorescent translate < 125,245, -75>}
object{fluorescent translate < 125,245, 125>}
object{fluorescent translate < 125,245,-125>}
object{fluorescent translate < 125,245,-275>}
}
