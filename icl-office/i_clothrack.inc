/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Clothrack

*/

#declare perchero=
union{
 sphere{0,1 scale <17,3,17>}
 cylinder{<0,0,0>,<0,170,0>,2}
 cylinder{<-16,0,0>,<16,0,0>,.8 translate 145*y}
 sphere{0,2 translate <-16,145,0>}
 sphere{0,2 translate <16,145,0>}
 cylinder{<-16,0,0>,<16,0,0>,.8 rotate 90*y translate 160*y}
 sphere{0,2 translate <0,160,-16>}
 sphere{0,2 translate <0,160,16>}
 cylinder{<-10,0,0>,<10,0,0>,.8 rotate 90*y translate 150*y}
 sphere{0,2 translate <0,150,-10>}
 sphere{0,2 translate <0,150,10>}
 cylinder{<-10,0,0>,<10,0,0>,.8 translate 155*y}
 sphere{0,2 translate <-10,155,0>}
 sphere{0,2 translate <10,155,0>}
 sphere{0,3 translate <0,172,0>}
 texture{t_lamp}
}

