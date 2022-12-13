/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Office desks

*/

// texture
#declare t_desk_metal=
texture{t_normal_chrome}

// drawers
#macro cajonera(r_caj)
union{
 union{
  difference{
   box{-.5,.5 scale <44,50,70>}
   box{-.5,.5 scale <40,46,70> translate -2*z}
  }
  box{-.5,.5 scale <39.8,int(46/3),70>}
  box{-.5,.5 scale <39.8,int(46/3),70> translate (46/3)*y}
  box{-.5,.5 scale <39.8,int(46/3),70> translate -(46/3)*y}
  texture{t_azul_mesas rotate 90*y translate rand(r_caj)*100}
 }
 union{
  cylinder{<-4,0,0>,<4,0,0>,.9 translate <0,0,-35.9>}
  cylinder{<-4,0,0>,<4,0,0>,.9 translate <0,46/3,-35.9>}
  cylinder{<-4,0,0>,<4,0,0>,.9 translate <0,-46/3,-35.9>}
  texture{t_desk_metal}
 }
}
#end

// wood board
#declare rbox=
box{-.5,.5}
//superellipsoid{<.01,.02> scale .5 rotate 90*x}

// short desk 
#declare table_s=
union{
 object{rbox
  scale <120,2,80> translate 79*y
  texture{t_mesas rotate 90*y translate 78}
 }
 union{
  box{-.5,.5 scale <2,50,76> translate <-58,53,0>}
  box{-.5,.5 scale <2,50,76> translate < 58,53,0>}
  texture{t_mesas rotate 90*x}
 }
 box{-.5,.5 scale <120,50,2> translate <0,54,38>
  texture{t_mesas rotate 90*y}
 }
 union{
  box{-.5,.5 scale <3,78,3> translate <-58,37, 38>}
  box{-.5,.5 scale <3,78,3> translate < 58,37, 38>}
  box{-.5,.5 scale <3,78,3> translate <-58,37,-38>}
  box{-.5,.5 scale <3,78,3> translate < 58,37,-38>}
  box{-.5,.5 scale <3,50,3> translate <60-44-1.5,79-25,-38>}
  box{-.5,.5 scale <50,3,3> translate <60-2-22,79-50-1.5,-38>}
  box{-.5,.5 scale <120,3,3> translate <0,77,-38>}
  box{-.5,.5 scale <120,3,3> translate <0,77,38>}
  box{-.5,.5 scale <120,3,3> translate <0,79-50-1.5,38>}
  box{-.5,.5 scale <3,3,80> translate <-58,79-50-1.5,0>}
  box{-.5,.5 scale <3,3,80> translate <58,79-50-1.5,0>}
  box{-.5,.5 scale <3,3,80> translate <-58,77,0>}
  box{-.5,.5 scale <3,3,80> translate <58,77,0>}
  texture{t_desk_metal}
 }
 union{
  box{-.5,.5 scale <3.1,2,3.1> translate <-58,1, 38>}
  box{-.5,.5 scale <3.1,2,3.1> translate < 58,1, 38>}
  box{-.5,.5 scale <3.1,2,3.1> translate <-58,1,-38>}
  box{-.5,.5 scale <3.1,2,3.1> translate < 58,1,-38>}
  texture{t_black_plastic}
 }
 object{cajonera(seed(23)) translate <60-2-22,79-25,-40+35+1>}
}

// long desk
#declare table_l=
union{
 object{rbox
  scale <160,2,80> translate 79*y
  texture{t_mesas rotate 90*y translate 68}
 }
 union{
  box{-.5,.5 scale <2,50,76> translate <-78,53,0>}
  box{-.5,.5 scale <2,50,76> translate < 78,53,0>}
  texture{t_azul_mesas rotate 90*x}
 }
 box{-.5,.5 scale <160,50,2> translate <0,54,38>
  texture{t_mesas rotate 90*y}
 }
 union{
  box{-.5,.5 scale <3,78,3> translate <-78,37, 38>}
  box{-.5,.5 scale <3,78,3> translate < 78,37, 38>}
  box{-.5,.5 scale <3,78,3> translate <-78,37,-38>}
  box{-.5,.5 scale <3,78,3> translate < 78,37,-38>}
//  box{-.5,.5 scale <3,50,3> translate <80-44-1.5,79-25,-38>}
  box{-.5,.5 scale <3,50,3> translate <-80+44+1.5,79-25,-38>}
  box{-.5,.5 scale <45,3,3> translate <-80+2+22,79-50-1.5,-38>}
//  box{-.5,.5 scale <45,3,3> translate <80-2-22,79-50-1.5,-38>}
  box{-.5,.5 scale <160,3,3> translate <0,77,-38>}
  box{-.5,.5 scale <160,3,3> translate <0,77,38>}
  box{-.5,.5 scale <160,3,3> translate <0,79-50-1.5,38>}
  box{-.5,.5 scale <3,3,79> translate <-78,79-50-1.5,0>}
  box{-.5,.5 scale <3,3,79> translate <78,79-50-1.5,0>}
  box{-.5,.5 scale <3,3,79> translate <-78+44,79-50-1.5,0>}
//  box{-.5,.5 scale <3,3,79> translate <78-44,79-50-1.5,0>}
  box{-.5,.5 scale <3,3,79> translate <-78,77,0>}
  box{-.5,.5 scale <3,3,79> translate <78,77,0>}
  texture{t_desk_metal}
 }
 union{
  box{-.5,.5 scale <3.1,3,3.1> translate <-78,1.5, 38>}
  box{-.5,.5 scale <3.1,3,3.1> translate < 78,1.5, 38>}
  box{-.5,.5 scale <3.1,3,3.1> translate <-78,1.5,-38>}
  box{-.5,.5 scale <3.1,3,3.1> translate < 78,1.5,-38>}
  texture{t_black_plastic}
 }
 object{cajonera(seed(8)) translate <-80+2+22,79-25,-40+35+1>}
// object{cajonera(seed(76)) translate <80-2-22,79-25,-40+35+1>}
}

