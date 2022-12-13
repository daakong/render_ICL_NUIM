/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Gas Lighter

*/

// *** desposito ***
#declare dpst =
difference{
 superellipsoid{<0.3,0.3>
  scale <1.25,7,1.3/2>
  translate 3.5*y
 }
 plane{y,0 }
 plane{y,6.5 inverse}
}

#declare deposito =
difference{
 object{dpst}
 object{dpst scale 0.9}
}

// *** junta ***
#declare junta =
difference{
 superellipsoid{<0.3,0.3>
  scale <1.25,7,1.3/2>
 }
 plane{y,0 }
 plane{y,0.4 inverse}
}

// *** carcasa ***
#declare tp =
difference{
 superellipsoid{<0.3,0.3>
  scale <1.25,7,1.3/2>
 }
 plane{y,0 }
 plane{y,1.2 inverse}
}
#declare carcasa =
difference{
 object{tp}
 object{tp scale <0.9,0.9,0.9>}
 plane{x,0.5 inverse}
 plane{y,0.25 inverse rotate -45*z translate <0.5,0.2,0>}
 cylinder{<-0.4,0,0>,<-0.4,1.3,0>,0.6}
 cylinder{<-1.05,0,0>,<-1.05,1.3,0>,0.1 scale 3.5*z}
}

// *** pulsador ***
#declare pulsador =
difference{
 superellipsoid{<0.3,0.3>
  scale <1.2,7,1.2/2>
 }
 plane{y,0 }
 plane{y,0.4 inverse}
 box{<0.5,0,-1>,<1.5,0.2,1>}
}

// *** rueda ***
#declare rueda=
union{
 cylinder{<-0.1,7.8,-1.1/2>,<-0.1,7.8,(-1.1/2)+0.2>,0.4 }
 cylinder{<-0.1,7.8,(-1.1/2)+0.2>,<-0.1,7.8,(1.1/2)-0.2>,0.3 }
 cylinder{<-0.1,7.8,(1.1/2)-0.2>,<-0.1,7.8,1.1/2>,0.4 }
}
// *** espita ***

// *** toma de gas ***

// *** regulador ***

// *** junta interior ***

// *** mechero ***
#declare mechero =
union
{
 object{deposito
 #if (use_textures)
  texture{Ruby_Glass finish{caustics .9}}
  interior{I_Glass1}
 #else
  texture{pigment{Red} finish{Phong_Shiny}}
 #end
 }
 object{junta
  translate 6.5*y
  texture{Polished_Chrome}
 }
 object{pulsador
  translate (6.5+0.4)*y
  pigment {Gray20}
  finish{Shiny}
 }
 object{carcasa
  translate (6.5+0.4)*y
  texture{Polished_Chrome}
 }
 object{rueda
  texture{Brushed_Aluminum scale 0.5}
 }
}

