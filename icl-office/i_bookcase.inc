/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Bookcase

*/

#macro armario1(rbc,tp)
union{
 difference{
  box{-.5,.5 scale <110,200,50>}
  box{-.5,.5 scale <106,196,50> translate -2*z}
  texture{t_mesas rotate 90*x translate rand(rbc)}
 }
 union{
  box{-.5,.5 scale <106,2,45> translate <0,0,5>}
  box{-.5,.5 scale <106,2,45> translate <0,30,5>}
  box{-.5,.5 scale <106,2,50> translate <0,-30,0>}
  box{-.5,.5 scale <106,2,45> translate <0,60,5>}
  texture{t_mesas rotate 90*y translate rand(rbc)}
 }
 union{
  box{-.5,.5 scale <54,68,2> translate <-55*.5,-100+35,-25>}
  box{-.5,.5 scale <54,68,2> translate < 55*.5,-100+35,-25>}
  #if (tp>0)  
  box{-.5,.5 scale <54,90,2> translate < 55*.5,-100+35+80,-25>}
  box{-.5,.5 scale <54,90,2> translate <-55*.5,-100+35+80,-25>}
  #end
  texture{t_azul_mesas}
 }
 union{
  cone{<0,0,0>,3,<0,-6,0>,1.5 translate <-50,-100,-20>}
  cone{<0,0,0>,3,<0,-6,0>,1.5 translate <-50,-100, 20>}
  cone{<0,0,0>,3,<0,-6,0>,1.5 translate < 50,-100,-20>}
  cone{<0,0,0>,3,<0,-6,0>,1.5 translate < 50,-100, 20>}
  texture{t_mesas rotate 90*x translate rand(rbc)}
 }
 union{
  sphere{0,1 scale <2,3,.5> translate <-5,-100+35,-26.5>}
  sphere{0,1 scale <2,3,.5> translate < 5,-100+35,-26.5>}
  #if (tp>0)  
  sphere{0,1 scale <2,3,.5> translate <-5,-100+35+80,-26.5>}
  sphere{0,1 scale <2,3,.5> translate < 5,-100+35+80,-26.5>}
  #end
  texture{t_lamp}
 }
 scale <1,1,.75>
 texture{t_mesas rotate 90*x translate rand(rbc)}
 translate 106*y
}
#end
