/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Desk lamps

*/

// *** warm-white fluorescents at the desks ***
#include "i_flexo.inc"
// create bulb
#declare h_bulb_off=
sphere{0,1 scale <3,4,3>
 #if (use_textures=0)
 pigment{White}
 #else
 texture{Glass2}
 #end
}
#declare h_bulb_on=
union{
 object{Light(c_halog,lm_halog,9*x,9*z,0,0,1) translate -4.01*z}
 #if (use_textures)
 sphere{0,1 scale <3,4,3>
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission c_halog*lm_halog*Lightsys_Brightness/(100*pi)
     }
   }
  hollow
  no_shadow
  translate -1*y
 }
 intersection{
  sphere{<0,0,0>,1}
  plane{z,-.3}
   pigment { color rgbt <1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission .05
      density {
        spherical
        cubic_wave
        color_map {
          [0.0 Black]
          [1.0 rgb c_halog]
        }
        frequency 1
      }
     }
   }
   no_shadow
   hollow
   scale 10
  }
 #end
}
#declare flexo_1=
object{flexo(h_bulb_on,20,-50,-30)}
#declare flexo_2=
object{flexo(h_bulb_off,25,-75,-30)}
#declare flexo_3=
object{flexo(h_bulb_off,20,-50,-30)}
#declare flexo_4=
object{flexo(h_bulb_off,20,-55,-25)}
