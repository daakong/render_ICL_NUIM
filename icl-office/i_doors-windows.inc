/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Door and windows

*/

// aluminum window
#macro ventana_aluminio(va_ancho,va_alto,va_hondo,va_marco)
union{
 difference{
  box{-.5,.5 scale <va_ancho,va_alto,va_hondo>}
  box{-.5,.5 scale <va_ancho-va_marco*2,va_alto-va_marco*2,va_hondo+.1>}
  texture{t_aluminum}
 }
 difference{
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.5,va_alto-va_marco*2,va_hondo>}
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.5-va_marco*2,va_alto-va_marco*4,va_hondo+.1>}
  texture{t_aluminum}
  translate -va_ancho*.23*x
 }
 difference{
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.5,va_alto-va_marco*2,va_hondo>}
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.5-va_marco*2,va_alto-va_marco*4,va_hondo+.1>}
  texture{t_aluminum}
  translate va_ancho*.23*x
 }
 box{-.5,.5 scale <2,10,.2> translate <va_marco,-10,-va_hondo*.6>
  texture{t_aluminum}
 }
 #if (use_glass)
 box{-.5,.5 scale <va_ancho-va_marco*2,va_alto-va_marco*2,.4>
  texture{t_quilted_glass}
  interior{i_sep_glass}
 }
 #end
}
#end

// aluminum door
#macro puerta_aluminio(va_ancho,va_alto,va_hondo,va_marco)
union{
 difference{
  box{-.5,.5 scale <va_ancho,va_alto,va_hondo>}
  box{-.5,.5 scale <va_ancho-va_marco*2,va_alto-va_marco*2,va_hondo+.1>}
  texture{t_aluminum}
 }
 difference{
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.495,va_alto-va_marco*2,va_hondo*.9>}
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.495-va_marco*3,va_alto-va_marco*5,va_hondo+.1>}
  texture{t_aluminum}
  translate -va_ancho*.24*x
 }
 difference{
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.495,va_alto-va_marco*2,va_hondo*.9>}
  box{-.5,.5 scale <(va_ancho-va_marco*2)*.495-va_marco*3,va_alto-va_marco*5,va_hondo+.1>}
  texture{t_aluminum}
  translate va_ancho*.24*x
 }
 box{-.5,.5 scale <(va_ancho-va_marco*2)*.5,va_marco*2,va_hondo> translate <-va_ancho*.25,0,0>
  texture{t_aluminum}
 }
 box{-.5,.5 scale <(va_ancho-va_marco*2)*.5,va_marco*2,va_hondo> translate <va_ancho*.25,0,0>
  texture{t_aluminum}
 }
 box{-.5,.5 scale <va_ancho-va_marco*2,(va_alto-va_marco*2)*.5,.5>
  #if (use_glass)
  texture{t_quilted_glass}
  interior{i_sep_glass}
  #else
  pigment{White}
  #end
  translate va_alto*.25*y
 }
 box{-.5,.5 scale <va_ancho-va_marco*2,(va_alto-va_marco*2)*.5,.5>
  texture{t_azul_mesas}
  translate -va_alto*.25*y
 }
 union{
  cylinder{<-va_marco,6,0>,<-va_marco,6,-5>,1}
  cylinder{< va_marco,6,0>,< va_marco,6,-5>,1}
  cylinder{<-va_marco,-6,0>,<-va_marco,-6,-5>,1}
  cylinder{< va_marco,-6,0>,< va_marco,-6,-5>,1}
  cylinder{<-va_marco,9,-5>,<-va_marco,-9,-5>,1.5}
  cylinder{< va_marco,9,-5>,< va_marco,-9,-5>,1.5}
  sphere{<va_marco,9,-5>,1.5}
  sphere{<va_marco,-9,-5>,1.5}
  sphere{<-va_marco,9,-5>,1.5}
  sphere{<-va_marco,-9,-5>,1.5}
  texture{t_aluminum}
 }
}
#end

// window shaders
#macro persiana(anchop,altop,aperp)
#local nh=25;
#local ih=0;
union{
#while (ih<nh)
// box{-.5,.5 scale <anchop,.1,2>
 cylinder{<-anchop*.5,0,0>,<anchop*.5,0,0>,1 scale <1,.1,1.5>
  rotate -aperp*x
  translate ((altop*.5)-(altop/nh)*ih)*y
 }
 #local ih=ih+1;
#end
 box{-.5,.5 scale <anchop,.5,2> translate <0,-altop*.5,0>}
 box{-.5,.5 scale <anchop,2,2> translate <0,altop*.5,0>}
 cylinder{<0,-altop*.5,0>,<0,altop*.5,0>,.1 translate <-anchop*.45,0, 1>}
 cylinder{<0,-altop*.5,0>,<0,altop*.5,0>,.1 translate < anchop*.45,0, 1>}
 cylinder{<0,-altop*.5,0>,<0,altop*.5,0>,.1 translate <          0,0, 1>}
 cylinder{<0,-altop*.5,0>,<0,altop*.5,0>,.1 translate <-anchop*.45,0,-1>}
 cylinder{<0,-altop*.5,0>,<0,altop*.5,0>,.1 translate < anchop*.45,0,-1>}
 cylinder{<0,-altop*.5,0>,<0,altop*.5,0>,.1 translate <          0,0,-1>}
 cylinder{<0,-altop*.3,0>,<0,altop*.5,0>,.3 translate <-anchop*.45,0,-2>}
 pigment{Flesh*.1+White*.9}
 finish{Shiny reflection{.05,.2}}
 rotate 90*y
 translate 2*y
}
#end
