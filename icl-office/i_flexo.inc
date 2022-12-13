/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Main scene file

*/

// reflector
#include "meshlath.inc"
#local a_pant=array[7]
#local a_pant[0]=<0,0,0>;
#local a_pant[1]=<0,0,0>;
#local a_pant[2]=<2,1,0>;
#local a_pant[3]=<5,3,0>;
#local a_pant[4]=<7,6,0>;
#local a_pant[5]=<8,8,0>;
#local a_pant[6]=<8,8,0>;
##declare pantalla=
object{meshlathe(a_pant,.2,18)}

// Lamp macro
// params: bulb object, rotation angles 1 2 & 3
#macro flexo(bulb,r1,r2,r3)

union{
 union{
  superellipsoid{<.2,.8> scale <7,2,7>
   texture{t_lamp}
  }
  sphere{0,2.5 scale <1,0.8,1>
   texture{t_lamp}
   translate 2*y
  }
  superellipsoid{<.8,.2> scale <.5,1,.5>
   texture{t_normal_chrome}
   translate <0,2,-5>
  }
  union{
   cylinder{<1,0,0>,<1,15,0>,.5
    texture{t_lamp}
   }
   cylinder{<-1,0,0>,<-1,15,0>,.5
    texture{t_lamp}
   }
   sphere{0,2
    texture{t_lamp}
    translate 16.5*y
   }
   union{
    cylinder{<1,0,0>,<1,25,0>,.5
     texture{t_lamp}
    }
    cylinder{<-1,0,0>,<-1,25,0>,.5
     texture{t_lamp}
    }
    sphere{0,2
     texture{t_lamp}
     translate 26.5*y
    }
    union{
     cylinder{<0,0,-1>,<0,0,1>,1.1
      texture{t_lamp}
     }
     union{
      union{
       object{pantalla}
       sphere{0,2 translate -.5*y}
       rotate -90*x translate 8*z
       texture{t_lamp}
      }
      translate -11*z
     }
     object{bulb
      translate <0,0,-7>
     }
     rotate r3*x
     translate 28.5*y
    }
    rotate r2*x
    translate 18.5*y
   }
   rotate r1*x
   translate 4*y
  }
 }
}
#end
