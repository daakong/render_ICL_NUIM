/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Printer (epson stylus alike)

*/

// *** PARTS ***
#declare trademark=height_field{
    png "hf_pcmark"
    translate -.5
    rotate -90*x
}
#declare jvp_printer=
union{
 // lower chasis
 superellipsoid{<.05,.1> scale .5 rotate 90*x
  scale <40,1,25>
  texture{t_printer_plastic}
 }
 difference{
  superellipsoid{<.05,.1> scale .5 rotate 90*x scale <42,2,26.5>}
  box{-.5,.5 scale <22,2,12> translate <-.5,1,-26*.5+12*.5-1>}
  texture{t_printer_plastic}
  translate 1.5*y
 }
 intersection{
  superellipsoid{<.1,.05> scale .5 rotate 90*x scale <10,8.5,27>}
  plane{y,-8.5*.5+5.9}
  texture{t_printer_plastic}
  translate <43*.5-10*.5,(8.5*.5+.5),0>
 }
 intersection{
  difference{
   superellipsoid{<.1,.05> scale .5 rotate 90*x scale <7,11,27>}
   box{-.5,.5 scale <1,2.5,2> translate <-.5,-2.5,-27*.5>}
  }
  plane{y,-11*.5+5.9}
  texture{t_printer_plastic}
  translate <-43*.5+7*.5,(11*.5+.5),0>
 }
 // upper chasis
 intersection{
  superellipsoid{<.1,.05> scale .5 rotate 90*x scale <10,8.5,27>}
  plane{y,-8.5*.5+6 inverse}
  texture{t_printer_plastic}
  translate <43*.5-10*.5,(8.5*.5+.5),0>
 }
 intersection{
  difference{
   superellipsoid{<.1,.05> scale .5 rotate 90*x scale <10,8.5,27>}
   box{-.5,.5 scale <8,2,9> translate <0,8.5*.5,-27*.5+9*.5+.5>}
  }
  plane{y,-8.5*.5+6 inverse}
  texture{t_printer_plastic}
  translate 27*.5*z rotate -10*x translate -27*.5*z
  translate <43*.5-10*.5,(8.5*.5+.5),1>
 }
 intersection{
  superellipsoid{<.1,.05> scale .5 rotate 90*x scale <7,11,27>}
  plane{y,-11*.5+6 inverse}
  texture{t_printer_plastic}
  translate <-43*.5+7*.5,(11*.5+.5),0>
 }
 intersection{
  difference{
   superellipsoid{<.1,.05> scale .5 rotate 90*x scale <7,11,27>}
   superellipsoid{<.1,.05> scale .45 rotate 90*x scale <7,11,27>}
   union{
    box{-.5,.5 scale <.3,3,.3> translate <-2,11*.5,-3>}
    box{-.5,.5 scale <.3,3,.3> translate <-2,11*.5,-4>}
    box{-.5,.5 scale <.3,3,.3> translate <-2,11*.5,-5>}
    box{-.5,.5 scale <.3,3,.3> translate <-2,11*.5,-6>}
    box{-.5,.5 scale <.3,3,.3> translate <-2,11*.5,-7>}
    box{-.5,.5 scale <.3,3,.3> translate <-2,11*.5,-8>}
    box{-.5,.5 scale <.3,3,.3> translate <-1,11*.5,-3>}
    box{-.5,.5 scale <.3,3,.3> translate <-1,11*.5,-4>}
    box{-.5,.5 scale <.3,3,.3> translate <-1,11*.5,-5>}
    box{-.5,.5 scale <.3,3,.3> translate <-1,11*.5,-6>}
    box{-.5,.5 scale <.3,3,.3> translate <-1,11*.5,-7>}
    box{-.5,.5 scale <.3,3,.3> translate <-1,11*.5,-8>}
    box{-.5,.5 scale <.3,3,.3> translate <0,11*.5,-3>}
    box{-.5,.5 scale <.3,3,.3> translate <0,11*.5,-4>}
    box{-.5,.5 scale <.3,3,.3> translate <0,11*.5,-5>}
    box{-.5,.5 scale <.3,3,.3> translate <0,11*.5,-6>}
    box{-.5,.5 scale <.3,3,.3> translate <0,11*.5,-7>}
    box{-.5,.5 scale <.3,3,.3> translate <0,11*.5,-8>}
    box{-.5,.5 scale <.3,3,.3> translate <1,11*.5,-3>}
    box{-.5,.5 scale <.3,3,.3> translate <1,11*.5,-4>}
    box{-.5,.5 scale <.3,3,.3> translate <1,11*.5,-5>}
    box{-.5,.5 scale <.3,3,.3> translate <1,11*.5,-6>}
    box{-.5,.5 scale <.3,3,.3> translate <1,11*.5,-7>}
    box{-.5,.5 scale <.3,3,.3> translate <1,11*.5,-8>}
    box{-.5,.5 scale <.3,3,.3> translate <2,11*.5,-3>}
    box{-.5,.5 scale <.3,3,.3> translate <2,11*.5,-4>}
    box{-.5,.5 scale <.3,3,.3> translate <2,11*.5,-5>}
    box{-.5,.5 scale <.3,3,.3> translate <2,11*.5,-6>}
    box{-.5,.5 scale <.3,3,.3> translate <2,11*.5,-7>}
    box{-.5,.5 scale <.3,3,.3> translate <2,11*.5,-8>}
	scale 1.1
	translate -2*z
   }
  }
  plane{y,-11*.5+6 inverse}
  plane{z,-1}
  texture{t_printer_plastic}
  translate 27*.5*z rotate -10*x translate -27*.5*z
  translate <-43*.5+7*.5,(11*.5+.5),1>
 }
 intersection{
  difference{
   superellipsoid{<.1,.1> scale .5 rotate 90*x scale <43,13.5,16>}
   box{-.5,.5 scale <22,3,4> translate <-.5,13.5*.5-.5,16*.5>}
   box{-.5,.5 scale <27,3,5> translate <-1,-.5,-16*.5+2>}
   sphere{0,6 scale <3,.5,.2> translate <-.5,5,-16*.5-1>}
  }
  plane{y,-13.5*.5+6 inverse}
  texture{t_printer_plastic}
  translate <0,(13.5*.5+.5),27*.5-16*.5>
 }
 // interior
 cylinder{<-12,0,0>,<12,0,0>,2
  pigment{Gray20}
  translate <0,4.5,3>
 }
 // tap
 intersection{
  superellipsoid{<.05,.1> scale .5 scale <43,13.5,16.1>}
  plane{y,13.5*.5-3 inverse}
  texture{t_printer_plastic}
  translate <0,(13.5*.5+1),27*.5-16*.5>
 }
 // tray
 intersection{
  superellipsoid{<.05,.1> scale .5 rotate 90*x scale <26.5,.3,10>}
  rotate -1*x
  texture{t_printer_plastic}
  translate <-.5,3,-6>
 }
 intersection{
  superellipsoid{<.05,.1> scale .5 rotate 90*x scale <16,.5,14>}
  plane{x,0 rotate 10*y translate 5*x}
  plane{x,0 inverse rotate -10*y translate -5*x}
  rotate 4*x
  texture{t_printer_plastic}
  translate <-.5,1.8,-27*.5-14*.5>
 }
 // buttons
 box{-.5,.5
  pigment{image_map{png "im_printer1"} translate -.5 rotate 90*x}
  finish{Dull}
  scale <8,1,9>
  translate <0,8.5*.5,-27*.5+9*.5+.5>
  translate 27*.5*z rotate -10*x translate -27*.5*z
  translate <43*.5-10*.5,(8.5*.5+.5)-.5,1>
 }
 union{
  cylinder{<-.7,0,0>,<.7,0,0>,.3 translate <2,0,3>}
  cylinder{<-.7,0,0>,<.7,0,0>,.3 translate <2,0,1>}
  cylinder{<-.7,0,0>,<.7,0,0>,.3 translate <2,0,-1>}
  cylinder{<-.7,0,0>,<.7,0,0>,.3 translate <2,0,-3>}
  texture{t_printer_plastic}
  translate <0,8.5*.5,-27*.5+9*.5+.5>
  translate 27*.5*z rotate -10*x translate -27*.5*z
  translate <43*.5-10*.5,(8.5*.5+.5),1>
 }
 difference{
  cylinder{<-.4,0,0>,<.4,0,0>,2}
  cylinder{<-.5,0,0>,<.5,0,0>,1 translate <0,0,-2.5>}
  rotate -5*x
  texture{t_printer_plastic}
  translate <-18.4,3.5,-11.5>
 }
 // logos
 object{trademark
  scale <3,3,.2>
  texture{
   gradient z
   texture_map{
    [0 t_bote2]
    [1 t_lamp]
   }
   scale <1,1,.21>
  }
  rotate 90*x
  translate <-19,14.5,1>
 }
 // papers
}

