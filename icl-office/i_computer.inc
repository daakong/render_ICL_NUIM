/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Computer & other equipment

*/

// wings cable
#include "i_mcable.inc"

// trademark logo
#declare trademark=
height_field{
 png "hf_pcmark"
 translate -.5
 rotate -90*x
}

// image for the screen
#declare screen_img=
box{-.5,.5
 texture{
  pigment{image_map{jpeg "im_screen.jpg"} translate -.5} 
  #if (use_radiosity=2)
  finish{ambient 1.5 diffuse 0}
  #else
  finish{ambient .6 diffuse 0}
  #end
 }
 scale <31,24,.1>
}

// computer monitor
#declare monitor=
union{
 union{
  // front frame
  difference{
   intersection{
    superellipsoid{<.1,.06> rotate 90*x scale .5 scale <40,36,10>}
    plane{z,0}
    translate 2.5*z
   }
   box{-.5,.5 scale <31,24,4> translate <0,1,-1.1>}
   sphere{0,.45 translate <-3,-15,-2.5>}
   sphere{0,.45 translate < 3,-15,-2.5>}
   cylinder{<0,0,-.1>,<0,0,.5>,.35 translate <-3,-15,-2.5>}
   cylinder{<0,0,-.1>,<0,0,.5>,.35 translate < 3,-15,-2.5>}
   sphere{0,.8 scale <1,1,.5> translate <14,-15,-2.5>}
   cylinder{<0,0,-.1>,<0,0,1>,.75 translate <14,-15,-2.5>}
   cylinder{<0,0,-.1>,<0,0,1>,.3 translate <12,-15,-2.5>}
   sphere{0,.6 scale <2.4,1,.5> translate <0,-15,-2.5>}
   translate (36*.5+8)*y
  }
  // back
  difference{
   intersection{
    superellipsoid{<.1,1> scale .5 scale <40,36,30>}
    plane{z,0 inverse}
   }
   cylinder{<0,0,0>,<0,0,30>,.5 translate <-19,16,0>}
   cylinder{<0,0,0>,<0,0,30>,.5 translate < 19,16,0>}
   cylinder{<0,0,0>,<0,0,30>,.5 translate <-19,-16,0>}
   cylinder{<0,0,0>,<0,0,30>,.5 translate < 19,-16,0>}
   translate <0,(36*.5+8),2.4>
  }
  intersection{
   superellipsoid{<.05,.05> rotate 90*x scale .5 scale <24,8,30>}
   plane{z,0 inverse}
   translate <0,0,12>
   translate <0,(36*.5+8)-14,0>
  }
  difference{
  union{
  intersection{
   union{
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <24,28,38>}
     plane{z,0 inverse}
     translate <0,0,12>
    }
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <30,28,38>}
     plane{z,0 inverse}
     plane{x,0}
     rotate 9*y
     translate <0,0,10>
    }
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <30,28,38>}
     plane{z,0 inverse}
     plane{x,0 inverse}
     rotate -9*y
     translate <0,0,10>
    }
   }
   plane{y,0 inverse}
   rotate 6*x
   translate <0,0,-1>
  }
  intersection{
   union{
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <24,28,38>}
     plane{z,0 inverse}
     translate <0,0,12>
    }
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <30,28,38>}
     plane{z,0 inverse}
     plane{x,0}
     rotate 9*y
     translate <0,0,10>
    }
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <30,28,38>}
     plane{z,0 inverse}
     plane{x,0 inverse}
     rotate -9*y
     translate <0,0,10>
    }
   }
   plane{y,0}
   rotate -9*x
   translate <0,0,-2>
  }
  union{
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <24,28,38>}
     plane{z,0 inverse}
     translate <0,0,12>
    }
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <30,28,38>}
     plane{z,0 inverse}
     plane{x,0}
     rotate 9*y
     translate <0,0,10>
    }
    intersection{
     superellipsoid{<.05,.05> rotate 90*x scale .5 scale <30,28,38>}
     plane{z,0 inverse}
     plane{x,0 inverse}
     rotate -9*y
     translate <0,0,10>
    }
    scale <1,.7,1.07>
   translate <0,0,-2>
  }
  }
  // holes
  box{-.5,.5 scale <10,.2,20> translate < 15,-1,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-1,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,-2,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-2,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,-3,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-3,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,-4,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-4,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,-5,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-5,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,-6,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-6,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,-7,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,-7,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,0,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,0,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,1,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,1,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,2,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,2,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,3,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,3,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,4,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,4,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,5,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,5,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,6,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,6,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,7,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,7,20>}
  box{-.5,.5 scale <10,.2,20> translate < 15,8,20>}
  box{-.5,.5 scale <10,.2,20> translate <-15,8,20>}
  translate <0,(36*.5+8)-1,0>
  }
  // stand
  union{
   cylinder{<0,0,0>,<0,.6,0>,14}
   cone{<0,.6,0>,14,<0,4,0>,5}
   intersection{
    sphere{0,10.8}
    plane{y,0}
    scale <1,.4,1>
    translate (10.8*.4*2)*y
   }
   torus{6,.5
    translate (10.8*.4)*y
   }
   translate (11+2.5)*z
  }
  texture{t_computer1}
 }
 // logo
 object{trademark
  scale <2,2,.1>
  texture{
   gradient z
   texture_map{
    [0 t_bote2]
    [1 t_lamp]
   }
   scale <1,1,.11>
  }
  translate <-14.4,(36*.5+8)-12.6,-2.51>
 }
 // buttons
 union{
  sphere{0,.4 scale <1,1,.25> translate <-3,-15,-2.5>}
  sphere{0,.4 scale <1,1,.25> translate < 3,-15,-2.5>}
  sphere{0,.75 scale <1,1,.25> translate <14,-15,-2.5>}
  box{-.5,.5 scale <.1,.6,.2> translate <0,-15,-2.4>}
  difference{
   sphere{0,.6 scale <2.4,1,.25> scale .95 translate <0,-15,-2.4>}
   box{-.5,.5 scale <.1,.6,.2> translate <0,-15,-2.5>}
  }
  texture{t_ac_plastic}
  translate (36*.5+8)*y
 }
 sphere{0,.3 scale <1,1,.25>
  texture{t_green_led}
  translate <12,-15,-2.5>
  translate (36*.5+8)*y
 }
 // screen
 object{screen_img
  scale .95
  translate <0,(36*.5+8)+1,-1.4>
 }
 box{-.5,.5 scale <32,25,.1>
  pigment{Gray10+Violet*.1}
  translate <0,(36*.5+8)+1,-1.3>
 }
 // cables
 object{mcable2(t_black_plastic) rotate 180*y scale <-1.5,1.5,1.5> translate <8,36*.5-7,27.5>}
 object{mcable2(t_computer1) rotate 180*y scale 1.4 translate <-8,36*.5-7,25.5>}
}

// computer keyboard
#declare keyboard=
union{
 difference{
  superellipsoid{<.05,.1> rotate 90*x
   scale <23.5,.6,7.5>
  }
  superellipsoid{<.05,.1> rotate 90*x
   scale <23,.6,7>
   translate .1*y
  }
  texture{t_computer1}
  translate -.5*y
 }
 height_field{
  png "hf_kbsp_blur"
  water_level .1
  smooth
  translate -.5
  texture{
   material_map{
    png "im_kbsp_clean"
    texture{t_computer1}
    texture{t_black_plastic finish{Phong_Shiny}}
   }
   translate -.5
   rotate 90*x
  }
  scale <23*2,2,14>
  translate -.4*y
 }
 height_field{
  png "hf_kbsp_hole"
  water_level .1
  translate -.5
  texture{t_computer1}
  scale <23*2,.1,14>
  translate -.05*y
 }
 box{-.5,.5
  hollow
  texture{pigment{Clear}}
  interior{
   media{
    emission 1
    intervals 10
    samples 1, 10
    density {
     boxed
     color_map {
       [0.0 Green*2]
       [1.0 Green]
     }
    }
   }
  }
  scale <8,.2,1.6>
  translate <18.1,-.3,6>
 }
 difference{
  box{-.5,.5}
  box{<-.4,-.6,-.4>,<-.3,.6,-.2>}
  box{<-.05,-.6,-.4>,<.05,.6,-.2>}
  hollow
  texture{
   pigment{image_map{tga "im_kbsp_leds"}}
   finish{diffuse 0.4}
   translate -.5
   rotate 90*x
  }
  scale <8.01,.05,1.7>
  translate <18.1,-.2,5.9>
 }
 rotate -7*x
}

// floppy drive
#declare floppy_drive=
union{
 height_field{
  png "hf_fd144"
  water_level 0.1
  translate -.5
  rotate -90*x
  scale <10.5,2.5,1>
  texture{t_floppy}
 }
 box{-.5,.5
  scale <1,.5,1>
  translate <-3,-.5,.1>
  texture{t_green_led}
 }
 scale .97
}

// cdrom drive
#declare cdrom_drive=
union{
 height_field{
  png "hf_cdrom"
  water_level 0.1
  translate -.5
  rotate -90*x
  scale <15,4,1>
  texture{t_cdrom}
 }
 box{-.5,.5 scale <.5,.5,1> translate <-4.8,-.7,.1>
  texture{t_green_led}
 }
 cylinder{<0,-.1,0>,<0,.1,0>,1 translate <-3,-.7,.3>
  texture{t_computer1}
 }
 scale .97
}

// cpu case
#declare cpu=
union{
 // main case
 difference{
  //box{-.5,.5
  superellipsoid{<.1,.1> rotate 90*x scale .5
   scale <20,45,45>
  }
  // cuts and holes
  box{-.5,.5 scale <15,12.4,1> translate <-.5,45*.5-6-4,-45*.5>}
  box{-.5,.5 scale <10.5,5.2,1> translate <-.5-4.5*.5,45*.5-6-4.1-4.1-3.5-1.3,-45*.5>}
  cylinder{<0,0,-.5>,<0,0,.5>,1 translate <5,45*.5-6-4.1-4.1-3.5-.3,-45*.5>}
  cylinder{<0,0,-.5>,<0,0,.5>,.5 translate <5,45*.5-6-4.1-4.1-3.5-.3-2.5,-45*.5>}
  box{-.5,.5 scale <15,2,1> translate <-.5,-1,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*2,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*3,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*4,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*5,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*6,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*7,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*8,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*9,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*10,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate <-4,-15-.5*11,-45*.5>}
  box{-.5,.5 scale <7,.2,2> translate <-4,-15-.5*12,-45*.5>}
  box{-.5,.5 scale <7,.2,3> translate <-4,-15-.5*13,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*2,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*3,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*4,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*5,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*6,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*7,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*8,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*9,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*10,-45*.5>}
  box{-.5,.5 scale <7,.2,1> translate < 4,-15-.5*11,-45*.5>}
  box{-.5,.5 scale <7,.2,2> translate < 4,-15-.5*12,-45*.5>}
  box{-.5,.5 scale <7,.2,3> translate < 4,-15-.5*13,-45*.5>}
  box{-.5,.5 scale <20,.1,1> translate <0,45*.5-2,-45*.5>}
  box{-.5,.5 scale <.1,41,1> translate <8.9,0,-45*.5>}
  box{-.5,.5 scale <.1,41,1> translate <-8.9,0,-45*.5>}
  box{-.5,.5 scale <1,46,.1> translate <10,0,-45*.5+2>}
  box{-.5,.5 scale <1,46,.1> translate <-10,0,-45*.5+2>}
  box{-.5,.5 scale <2,.2,46> translate <10,45*.5-2,0>}
  box{-.5,.5 scale <2,.2,46> translate <10,-45*.5+2,0>}
  box{-.5,.5 scale <2,.2,46> translate <-10,45*.5-2,0>}
  box{-.5,.5 scale <2,.2,46> translate <-10,-45*.5+2,0>}
  box{-.5,.5 scale <2,.2,40> translate <10,19,0>}
  box{-.5,.5 scale <2,.2,40> translate <10,18,0>}
  box{-.5,.5 scale <2,.2,40> translate <10,17,0>}
  box{-.5,.5 scale <2,.2,40> translate <10,16,0>}
  box{-.5,.5 scale <2,.2,40> translate <10,15,0>}
  box{-.5,.5 scale <2,.2,40> translate <-10,19,0>}
  box{-.5,.5 scale <2,.2,40> translate <-10,18,0>}
  box{-.5,.5 scale <2,.2,40> translate <-10,17,0>}
  box{-.5,.5 scale <2,.2,40> translate <-10,16,0>}
  box{-.5,.5 scale <2,.2,40> translate <-10,15,0>}
  box{-.5,.5 scale <3,3,1> translate <-6.5,-4,-45*.5>}
  // rear
  box{-.5,.5 scale <15,9,20> translate <1,45*.5-7,45*.5+9>}
  //box{-.5,.5 scale <18,40,2> translate <0,-1,45*.5>}
  texture{t_computer1}
 }
 // drive covers
 union{
  superellipsoid{<.1,.1> rotate 90*x scale .49 scale <15,4,1> translate <0,45*.5-6-4.1,-45*.5+.6>}
  superellipsoid{<.1,.1> rotate 90*x scale .49 scale <15,4,1> translate <0,45*.5-6-4.1-4.1,-45*.5+.6>}
  superellipsoid{<.1,.1> rotate 90*x scale .49 scale <10.5,2.5,1> translate <-4.5*.5,45*.5-6-4.1-4.1-3.5-2.6,-45*.5+.6>}
  texture{t_computer1}
  translate -.5*x
 }
 // drive units
 object{cdrom_drive
  translate <-.5,45*.5-6,-45*.5+.6>
 }
 object{floppy_drive
  translate <-.5-4.5*.5,45*.5-6-4.1-4.1-3.5,-45*.5+.6>
 }
 height_field{
  png "hf_ps"
  water_level 0.1
  translate -.5
  rotate -90*x
  texture{pigment{image_map{jpeg "im_ps"} translate -.5}}
  scale <15,9,1>
  scale .98
  rotate 180*y
  translate <1,45*.5-7,45*.5-.2>
 }
 // buttons
 sphere{0,.9 scale <1,1,.5>
  texture{t_ac_plastic}
  translate <5,45*.5-6-4.1-4.1-3.5-.3,-45*.5+.6>
 }
 sphere{0,.9 scale <1,1,.5>
  texture{t_ac_plastic}
  translate <5,45*.5-6-4.1-4.1-3.5-.3-2.5,-45*.5+.6>
 }
 // leds panel
 box{-.5,.5
  pigment{
   image_map{png "im_ledpanel"}
   translate -.5
  }
  scale <15,2,.1>
  scale .98
  translate <-.5,-1,-45*.5+.3>
 }
 // trademark
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
  translate <-6.5,-4,-45*.5+.1>
 }
 // patas
 union{
  cylinder{<0,-.3,0>,<0,1,0>,2 translate <-6,-45*.5-.3,-45*.5+4>}
  cylinder{<0,-.3,0>,<0,1,0>,2 translate < 6,-45*.5-.3,-45*.5+4>}
  cylinder{<0,-.3,0>,<0,1,0>,2 translate <-6,-45*.5-.3, 45*.5-3>}
  cylinder{<0,-.3,0>,<0,1,0>,2 translate < 6,-45*.5-.3, 45*.5-3>}
  texture{t_ac_plastic}
 }
 // go to plane y,0
 translate (45*.5+.3)*y
}

// *** MOUSE ***
#declare mouse_pad=
intersection{
 superellipsoid{<.2,.2> rotate 90*x scale .5
  scale <22,1,19>
  scale .99
 }
 plane{y,.15}
 plane{y,-.15 inverse}
 texture{
  pigment{DarkGreen}
 }
}
#declare mouse=
merge{
 intersection{
  difference{
   sphere{0,1 scale <3.5,3,6.5>}
   sphere{0,3 translate <0,3,4>}
  }
  plane{y,0 inverse}
  plane{z,5.5}
  plane{x,-3 inverse}
  plane{x,3}
 }
 difference{
  merge{
   intersection{
    intersection{
     sphere{0,1 scale <3,3,6.5>}
     sphere{0,2.9 translate <0,3,4>}
    }
    plane{y,0 inverse}
    plane{x,-.05}
    plane{z,5.5}
   }
   intersection{
    intersection{
     sphere{0,1 scale <3,3,6.5>}
     sphere{0,2.9 translate <0,3,4>}
    }
    plane{y,0 inverse}
    plane{x,.05 inverse}
    plane{z,5.5}
   }
  }
  cylinder{<-.25,0,0>,<.25,0,0>,1.1 translate <0,2,3>}
 }
 cylinder{<-.2,0,0>,<.2,0,0>,1 translate <0,2,3>}
 texture{t_computer1}
}

// *** cables ***
// cable macro
#macro make_cable(cable_rad,spl_cable,t_cable)
#local cable_step=0.05;
#local ctr=0.01;
#local ant=(spl_cable(0));
sphere_sweep{
b_spline,int(1/.05)+1,
#while (ctr<1)
 #local kk=(spl_cable(ctr));
 kk,cable_rad
 #local ant=kk;
 #local ctr = ctr + cable_step;
#end
 spl_cable(1),cable_rad
 texture{t_cable}
}
#end
// --- monitor video signal ---
#declare spl_video=
spline{
 cubic_spline
 -.1,<25,20,40>
  .1,<25,20,46>
  .2,<22,19,48>
  .3,<19,4,49>
  .4,<15,.4,53>
  .5,<0,.5,50>
  .6,<-10,2,48>
  .7,<-18,4,47>
  .8,<-20,20,46>
  .9,<-20,21,45>
  1,<-20,21,44>
  1.1,<-20,21,43>
}
#declare video_cable=
make_cable(.35,spl_video,t_ac_plastic)
// --- keyboard cable ---
#declare keyb_rad=.25;
#declare spl_keyb=
spline{
 cubic_spline
 -.1,<27,30,-40>
  .1,<27,30,46>
  .2,<25,19,47>
  .3,<21,4,48>
  .4,<15,.3,47>
  .5,<5,.5,45>
  .6,<-5,.5,40>
  .7,<-2,1,27>
  .8,<4,.5,16>
  .9,<-10,.5,8>
  1,<-10,1.5,-8>
  1.1,<-10,1.5,-8>
}
#declare keyb_cable=
make_cable(.25,spl_keyb,t_ac_plastic)
//
#declare spl_keyb1=
spline{
 cubic_spline
 -.1,<0,1.5,5>
  .1,<0,1,5>
  .2,<1,1,9>
  .3,<2,.6,11>
  .4,<4,1,19>
  .5,<9,.5,24>
  .6,<10,.5,30>
  .7,<8,.5,39>
  .8,<6,.5,45>
  .9,<0,.5,52>
  1,<0,.5,60>
  1.1,<0,.5,60>
}
#declare keyb_cable1=
make_cable(.25,spl_keyb1,t_ac_plastic)
//
#declare spl_keyb5=
spline{
 cubic_spline
 -.1,<0,.5,5>
  .1,<0,.5,5>
  .2,<1,0.5,9>
  .3,<2,.6,11>
  .4,<4,1,16>
  .5,<9,.5,20>
  .6,<10,.5,24>
  .7,<8,.5,29>
  .8,<6,.5,35>
  .9,<0,1,42>
  1,<0,1,50>
  1.1,<0,1,50>
}
#declare keyb_cable5=
make_cable(.25,spl_keyb5,t_ac_plastic)
// --- mouse cables ---
#declare spl_mouse=
spline{
 cubic_spline
 -.1,<27,30,-40>
  .1,<27,30,46>
  .2,<25,19,47>
  .3,<21,4,48>
  .4,<15,1,47>
  .5,<5,.5,40>
  .6,<10,.5,20>
  .7,<3,.5,10>
  .8,<10,.5,0>
  .9,<19,1,-5>
  1,<20,1.5,-10>
  1.1,<20,1.5,-10>
}
#declare mouse_cable=
make_cable(.25,spl_mouse,t_ac_plastic)
//
#declare psp=17;
#declare spl_mouse1=
spline{
 cubic_spline
 -.1,<0,.5,5>
  1/psp,<0,.5,5>
  2/psp,<1,.5,8>
  3/psp,<3,.5,12>
  4/psp,<1,0.5,19>
  5/psp,<2,.6,21>
  6/psp,<8,1,26>
  7/psp,<9,.5,30>
  8/psp,<10,.5,34>
  9/psp,<8,.5,39>
  10/psp,<6,.5,43>
  11/psp,<2,.5,48>
  12/psp,<8,.5,52>
  13/psp,<10,0,58>
  14/psp,<10,-1,59>
  15/psp,<10,-5,60>
  16/psp,<12,-25,61>
  17/psp,<20,-85,60>
  1.1,<20,-85,60>
}
#declare mouse_cable1=
make_cable(.25,spl_mouse1,t_ac_plastic)
//
#declare spl_mouse5=
spline{
 cubic_spline
 -.1,<0,.5,5>
  .1,<0,.5,5>
  .2,<-1,0.5,9>
  .3,<-2,.6,11>
  .4,<-8,1,16>
  .5,<-9,.5,20>
  .6,<-10,.5,24>
  .7,<-8,.5,29>
  .8,<-6,.5,33>
  .9,<-10,1,38>
  1,<-10,1,40>
  1.1,<-10,1,40>
}
#declare mouse_cable5=
make_cable(.25,spl_mouse5,t_ac_plastic)

