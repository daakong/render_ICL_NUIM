/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Wall clock

*/

// * esfera *
#declare esfera=
union{
 // * aro *
 intersection{
  difference{
   torus{
    1.4,0.4
    scale <1,0.6,1>
   }
   cylinder{
    <0,-.5,0>,<0,0.5,0>,1.5
   }
   bounded_by{cylinder{<0,-.4,0>,<0,.4,0>,2}}
  }
  plane{y,-.1 inverse}
//  texture{t_black_plastic}
  texture{t_lamp}
 }
 // * fondo *
 cylinder{
  <0,-.3,0>,<0,0,0>,1.5
  texture{pigment{Gray30} finish{Glossy}}
 }
 // * cristal *
 #if (use_textures)
 intersection{
  difference{
   sphere{0,1}
   sphere{0,0.95}
  }
  plane{y,0 inverse}
  scale <1.5,.1,1.5>
  translate 0.3*y
  texture{Glass pigment{rgbf <1,1,0.99,0.99>}}
 }
 #end
 // * numeros *
 cylinder{
  <0,0,0>,<0,0.2,0>,1.45
  #if (use_textures=0)
  texture{pigment{White}}
  #else
  texture{
   material_map{
    png "im_numeros"
    //texture{pigment{Black} finish{Shiny reflection 0.1}}
    texture{t_pintura_blanca}
    texture{t_black_plastic}
    texture{t_bote2}
    texture{t_lamp}
   }
   translate -.5
   rotate 90*x
   scale 3
  }
  #end
 }
 // * manecillas *
 union{
  // * minutero *
  union{
   intersection{
    union{
     cylinder{<0,0,0>,<0,0,1.2>,0.06}
     sphere{0,.06 translate 1.2*z}
     sphere{0,.06}
    }
    plane{y,0 inverse}
    scale <1,0.05,1>
   }
   texture{pigment{Gray10}
    #if (use_textures)
    finish{Phong_Shiny reflection{.01,.1}}
    #end
   }
   translate -.2*z
   translate 0.24*y
   rotate 60*y
  }
  // * horaria *
  union{
   intersection{
    union{
     cylinder{<0,0,0>,<0,0,1>,0.07}
     sphere{0,.07 translate 1*z}
     sphere{0,.07}
    }
    plane{y,0 inverse}
    scale <1,0.05,1>
   }
   texture{t_black_plastic
    #if (use_textures)
    finish{Phong_Shiny reflection{.01,.1}}
    #end
   }
   translate -.2*z
   translate 0.23*y
   rotate -90*y
  }
  // * segundero *
  union{
   intersection{
    union{
     cylinder{<0,0,0>,<0,0,1.1>,0.04}
     sphere{0,.04 translate 1.1*z}
     sphere{0,.04}
    }
    plane{y,0 inverse}
    scale <1,0.05,1>
   }
   sphere{<0,0,0>,0.04 scale 0.1*y translate .2*z}
   texture{t_bote2
    #if (use_textures)
    finish{Phong_Shiny reflection{.01,.1}}
    #end
   }
   translate -.2*z
   translate 0.25*y
   rotate 150*y
  }
 }
 // fin de la esfera
}
#declare reloj=
union{
 object{esfera}
}
