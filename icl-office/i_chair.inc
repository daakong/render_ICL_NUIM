/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Normal chair

*/

#declare chair=
union{
 intersection{
 #if (use_radiosity=2)
 box{-1,1
 #else
 superellipsoid{
  <.3,.3>
 #end
  rotate 90*x
  scale <20,4,21>
 }
 plane{y,0 inverse}
  texture{t_silla}
  translate <0,46,-2>
 }
 intersection{
 #if (use_radiosity=2)
 box{-1,1
 #else
 superellipsoid{
  <.3,.1>
 #end
  rotate 90*x
  scale <20,4,21>
 }
 plane{y,0}
  texture{t_silla}
  translate <0,46,-2>
 }
 #if (use_radiosity=2)
 box{-1,1
 #else
 superellipsoid{
  <.3,.3>
 #end
  rotate 90*x
  scale <44*.5,16*.5,2>
  rotate 9.3*x
  texture{t_silla}
  translate <0,75,19>
 }
 // tornillos respaldo
 union{
  sphere{<0,0,0>,1 scale <1,1,0.25> translate <-19,80,19.5>}
  sphere{<0,0,0>,1 scale <1,1,0.25> translate <-18.75,70,18>}
  sphere{<0,0,0>,1 scale <1,1,0.25> translate < 19,80,19.5>}
  sphere{<0,0,0>,1 scale <1,1,0.25> translate < 18.75,70,18>}
  sphere{<0,0,0>,1 scale <1,0.25,1> translate < 18,43.6,-16>}
  sphere{<0,0,0>,1 scale <1,0.25,1> translate <-18,43.6,-16>}
  texture{t_lamp}
 }
 union{
  cone{<-18,43,-16>,2,<-21,0,-19>,1}
  cone{< 18,43,-16>,2,< 21,0,-19>,1}
  cone{<-18,43,16>,2,<-21,0,19>,1}
  cone{< 18,43,16>,2,< 21,0,19>,1}
  cylinder{<-18,42,16>,<-19,78,22>,1.5}
  cylinder{< 18,42,16>,< 19,78,22>,1.5}
  cylinder{<-18,37,-16>,<0,40,0>,1}
  cylinder{< 18,37,-16>,<0,40,0>,1}
  cylinder{<-18,37, 16>,<0,40,0>,1}
  cylinder{< 18,37, 16>,<0,40,0>,1}
  texture{t_lamp}
 }
 union{
  cone{<-21,0,-19>,1.2,<-20.80,2,-18.80>,1.1}
  cone{< 21,0,-19>,1.2,< 20.80,2,-18.80>,1.1}
  cone{<-21,0, 19>,1.2,<-20.80,2, 18.80>,1.1}
  cone{< 21,0, 19>,1.2,< 20.80,2, 18.80>,1.1}
  //texture{t_black_plastic finish{Phong_Shiny}}
  texture{t_black_plastic finish{phong 0.1}}
 }
}
