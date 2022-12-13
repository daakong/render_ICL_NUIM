/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Decorative plants with pots

*/

// textures
#declare ff=.2;
#declare t_leaf=
texture{
 pigment{
  gradient x
  cubic_wave
  turbulence .1
  color_map{
   [0.00 White filter ff]
   [0.01 DarkGreen filter ff]
   [1.00 Bronze filter ff]
  }
 }
 scale 2
}
#declare t_leaf2=
texture{
 pigment{
  bumps
  color_map{
   [0.0 Gray*.1+DarkGreen*.9 filter ff]
   [1.0 ForestGreen*.5+Gold*.25 filter ff]
  }
 }
 finish{Shiny}
 scale 2
}
#declare t_leaf3=
texture{
 pigment{
  gradient x
  cubic_wave
  turbulence .1
  color_map{
   [0.0 DarkOliveGreen filter ff]
   [0.4 DarkOliveGreen filter ff]
   [0.5 Gold filter ff]
   [0.6 DarkGreen filter ff]
   [1.0 DarkGreen filter ff]
  }
 }
 scale 2
}
#declare t_leaf4=
texture{
 pigment{
  bumps
  color_map{
   [0.0 Gray*.2+DarkGreen*.8 filter ff]
   [1.0 Green*.2+Gold*.5 filter ff]
  }
 }
 finish{Phong_Shiny}
 scale 3
}

// *** pots ***
#declare pot1=
union{
 difference{
  cone{<0,0,0>,7,<0,16,0>,10}
  cone{<0,1,0>,6,<0,17,0>,10}
  pigment{Tan*.5+Firebrick*.5}
  #if (use_normals)
  normal{granite scale 2}
  #end
 }
}
#declare pot2=
union{
 difference{
  cone{<0,0,0>,7,<0,16,0>,10}
  cone{<0,1,0>,6,<0,17,0>,10}
 }
 cone{<0,15,0>,10.4,<0,16,0>,10.5}
 texture{t_computer1}
}
#declare pot3=
union{
 difference{
  cone{<0,0,0>,7,<0,16,0>,10}
  cone{<0,1,0>,6,<0,17,0>,10}
 }
 cone{<0,15,0>,10.4,<0,16,0>,10.5}
 pigment{Gray20+DarkGreen*.1}
}
#declare pot4=
union{
 difference{
  cone{<0,0,0>,7,<0,16,0>,10}
  cone{<0,1,0>,6,<0,17,0>,10}
 }
 cone{<0,13,0>,10,<0,16,0>,10.1}
 texture{
  pigment{
   image_map{
    png "im_maceta1"
    map_type 2
   }
   scale 16
  }
  #if (use_textures)
  finish{Shiny reflection .1}
  #end
 }
 texture{
  pigment{
   crackle
   turbulence .1
   color_map{
    [0.00 DarkBrown]
    [0.02 DarkBrown]
    [0.03 Clear]
    [1.00 Clear]
   }
  }
  scale 6
 }
}
#declare pot5=
difference{
 cone{<0,0,0>,7,<0,16,0>,10}
 cone{<0,1,0>,6,<0,17,0>,10}
 texture{
  pigment{Firebrick}
  normal{crackle turbulence .1 scale 3}
  #if (use_textures)
  finish{Shiny reflection .1}
  #end
 }
 texture{
  pigment{
   crackle
   turbulence .1
   color_map{
    [0.00 DarkBrown]
    [0.02 DarkBrown]
    [0.03 Clear]
    [1.00 Clear]
   }
  }
  #if (use_normals)
  normal{crackle turbulence .1}
  #end
  scale 3
 }
}
#declare pot6=
union{
 difference{
  cone{<0,0,0>,7,<0,16,0>,10}
  cone{<0,1,0>,6,<0,17,0>,10}
 }
 cone{<0,13,0>,10,<0,16,0>,10.1}
 texture{
  pigment{
   image_map{
    png "im_maceta2"
    map_type 2
   }
   scale 16
  }
  #if (use_textures)
  finish{Shiny reflection .1}
  #end
 }
 texture{
  pigment{
   crackle
   turbulence .1
   color_map{
    [0.00 DarkBrown]
    [0.02 DarkBrown]
    [0.03 Clear]
    [1.00 Clear]
   }
  }
  #if (use_normals)
  normal{crackle turbulence .1}
  #end
  scale 3
 }
}
#declare pot7=
union{
 difference{
  cone{<0,0,0>,7,<0,16,0>,10}
  cone{<0,1,0>,6,<0,17,0>,10}
 }
 cone{<0,13,0>,10,<0,16,0>,10.1}
 texture{
  pigment{
   image_map{
    png "im_maceta3"
    map_type 2
   }
   scale 16
  }
  #if (use_textures)
  finish{Shiny reflection .1}
  #end
 }
 texture{
  pigment{
   crackle
   turbulence .1
   color_map{
    [0.00 DarkBrown]
    [0.02 DarkBrown]
    [0.03 Clear]
    [1.00 Clear]
   }
  }
  #if (use_normals)
  normal{crackle turbulence .1}
  #end
  scale 3
 }
}

// *** achmea-like leaf ***
#macro achmea_leaf(lsize,lthick,lwidth)

intersection{
 difference{
  sphere{0,1 scale lsize}
  sphere{0,1 scale lsize-lthick}
 }
 plane{y,0 inverse}
 sphere{0,1 scale <lwidth,lsize*2+.1,lsize*2-.1> translate -lsize*z}
 translate (lsize+lwidth)*z
}

#end

// *** achema flower ***
#macro achmea_flor(rad_flor,t_caliz,t_estambres,t_petal,r_flor)
//sphere{0,4 pigment{Red} translate 4*y}
#local n_caliz=8;
#local n_petal=8;
#local caliz=
sphere{0,.5
 scale <1,2,.1>
 translate 1*y
 texture{t_caliz}
 rotate -45*x
}
#local petal=
sphere{0,.5
 scale <2,6,.1>
 rotate <-1+2*rand(r_flor),-1+2*rand(r_flor),-1+2*rand(r_flor)>
 translate 3*y
 texture{t_petal}
}

union{
 // caliz
 #local i_caliz=0;
 #while (i_caliz<n_caliz)
  object{caliz rotate (360*i_caliz/n_caliz)*y}
  #local i_caliz=i_caliz+1;
 #end
 // petalos
 #local i_petal=0;
 #while (i_petal<n_petal)
  object{petal
   scale 1.5
   rotate (-45-30*rand(r_flor))*x
   rotate (360*i_petal/n_petal)*y
   translate 1*y
  }
  object{petal
   scale 1.25
   rotate (-35-30*rand(r_flor))*x
   rotate -(360*i_petal/n_petal)*y
   rotate (360/n_petal)*.5*y
   translate 2*y
  }
  object{petal
   rotate (-25-30*rand(r_flor))*x
   rotate -(360*i_petal/n_petal)*y
   rotate (360/n_petal)*.5*y
   translate 3*y
  }
  #local i_petal=i_petal+1;
 #end
 sphere{0,1
  scale <1,.5,1>
  texture{t_estambres}
  translate 1.6*y
 }
}
#end

// *** achmea-like plant ***
#macro achmea_plant1(lsize,lthick,lwidth,nleafs,nchilds,t_leaf,rplant)

#local ichilds=0;
#local rp=seed(rplant);
#local lw=lwidth;
#local nl=nleafs;
#local t_est=
texture{
 pigment{Gold}
 #if (use_normals)
  normal{granite scale .1}
 #end
}
#local t_pet=
texture{
 pigment{Pink+Red*.1 filter 0.5}
 finish{metallic}
}

union{
#while (ichilds<nchilds)
 #local ileafs=0;
 #while (ileafs<nl)
  object{
   achmea_leaf(lsize,lthick,lw)
   scale (1-.5*(ichilds/nchilds))
   scale <1,1,.25+rand(rp)>
   texture{t_leaf}
   rotate -10*(sin(pi*ichilds/nchilds))*x
   rotate (360*(ileafs/nl)-5+10*rand(rp))*y
   translate lw*ichilds*y
  }
  #debug "."
  #local ileafs=ileafs+1;
 #end
 #local nl=nleafs*.5+nleafs*.5*(ichilds/nchilds);
 #local lw=lwidth*.5+lwidth*.5*(ichilds/nchilds);
 #local ichilds=ichilds+1;
#end
 object{
  achmea_flor(3+rand(rp),t_leaf,t_est,t_pet,rplant) rotate 360*rand(rp)*y
  translate (lw*ichilds+2)*y
 }
}

#end

#macro achmea_plant2(lsize,lthick,lwidth,nleafs,nchilds,t_leaf,rplant)

#local ichilds=0;
#local rp=seed(rplant);
#local lw=lwidth;
#local nl=nleafs;

union{
#while (ichilds<nchilds)
 #local ileafs=0;
 #while (ileafs<nl)
  object{
   achmea_leaf(lsize,lthick,lw)
   scale (1-.5*(ichilds/nchilds))
   scale <1,1,.25+rand(rp)>
   texture{t_leaf}
   rotate -10*(sin(pi*ichilds/nchilds))*x
   rotate (360*(ileafs/nl)-5+10*rand(rp))*y
   translate lw*ichilds*y
  }
  #debug "."
  #local ileafs=ileafs+1;
 #end
 #local lw=lwidth*.5+lwidth*.5*(ichilds/nchilds);
 #local ichilds=ichilds+1;
#end
}

#end

#macro hoja1(rleaf)
height_field{
 png "hf_hoja"
 water_level .1
 translate -.5
 rotate <-90,0,180>
 translate -.5*y
 scale <6,8,.2>
}
#end

#macro hoja2(rleaf)
height_field{
 png "hf_hoja2"
 water_level .1
 translate -.5
 rotate <-90,0,180>
 translate -.5*y
 scale <6,8,.5>
}
#end

#macro flor(rad_flor,t_caliz,t_estambres,t_petal,r_flor)
//sphere{0,4 pigment{Red} translate 4*y}
#local n_caliz=8;
#local n_petal=8;
#local caliz=
sphere{0,.5
 scale <1,2,.1>
 translate 1*y
 texture{t_caliz}
 rotate -45*x
}
#local petal=
sphere{0,.5
 scale <2,4,.1>
 rotate <-1+2*rand(r_flor),-1+2*rand(r_flor),-1+2*rand(r_flor)>
 translate 2*y
 texture{t_petal}
}

union{
 // caliz
 #local i_caliz=0;
 #while (i_caliz<n_caliz)
  object{caliz rotate (360*i_caliz/n_caliz)*y}
  #local i_caliz=i_caliz+1;
 #end
 // petalos
 #local i_petal=0;
 #while (i_petal<n_petal)
  object{petal
   rotate (-45-30*rand(r_flor))*x
   rotate (360*i_petal/n_petal)*y
   translate 1*y
  }
  #local i_petal=i_petal+1;
 #end
 sphere{0,1
  scale <1,.5,1>
  texture{t_estambres}
  translate 1.6*y
 }
}
#end

// *** HANGING PLANT ***
#macro hanging_plant(ntall,nnodo,radio,t_leaf,rplant)

 #local rp=seed(rplant);
 #local itall=0;
 #local yr=-65;
 #local t_est=
 texture{
  pigment{Orange}
  #if (use_normals)
  normal{granite scale .1}
  #end
 }
 #local t_pet=
 texture{
  pigment{White filter 0.3}
  #if (use_normals)
  normal{bumps scale 4}
  #end
  finish{Phong_Dull}
 }

 union{
 #while (itall<ntall)
  union{
  #local inodo=1;
  #local yant=0;
  #local zant=0;
  #local k=1.1;
  #while (inodo<=(nnodo*.75+nnodo*.25*rand(rp)))
   #local yact=(radio*.8+radio*.2*rand(rp))*sin(k*pi*(inodo/nnodo));
   #local zact=-inodo*.5;
   cylinder{<0,yant,zant>,<0,yact,zact>,.25}
   #if ((inodo>nnodo*.25) & (mod(inodo,2)=0))
    object{hoja1(rand(rp))
     scale (1.2-.4*sin(.5*pi*inodo/nnodo))
     rotate (90*(sin(pi*inodo/nnodo))-10)*x
     rotate yr*y
     translate <0,yact,zact>
    }
    object{
     flor(3+rand(rp),t_leaf,t_est,t_pet,rplant) rotate 360*rand(rp)*y
     scale .7
     rotate (90*(sin(pi*inodo/nnodo)))*x
     rotate -yr*y
     translate <0,yact,zact>
    }
    #if (yr=-65)
     #local yr=65;
    #else
     #local yr=-65;
    #end
   #end
   #local yant=yact;
   #local zant=zact;
   #local inodo=inodo+1;
  #end
   texture{t_leaf}
   rotate (360*(itall/ntall)-10+20*rand(rp))*y
  }
  #local itall=itall+1;
 #end
 }

#end

// *** HANGING PLANT 2 ***
#macro hanging_plant2(ntall,nnodo,radio,t_leaf,rplant)

 #local rp=seed(rplant);
 #local itall=0;
 #local yr=-65;
 #local t_est=
 texture{
  pigment{Orange}
  #if (use_normals)
  normal{granite scale .1}
  #end
 }
 #local t_pet=
 texture{
  pigment{Violet}
  #if (use_normals)
  normal{bumps scale 4}
  #end
  finish{Phong_Dull}
 }

 union{
 #while (itall<ntall)
  union{
  #local inodo=1;
  #local yant=0;
  #local zant=0;
  #local k=1;
  #while (inodo<=(nnodo*.75+nnodo*.25*rand(rp)))
   #local yact=radio*sin(k*pi*(inodo/nnodo));
   #local zact=-inodo*.5;
   cylinder{<0,yant,zant>,<0,yact,zact>,.25}
   #if ((inodo>nnodo*.25) & (mod(inodo,2)=0))
    object{hoja2(rand(rp))
     scale (1.2-.4*sin(.5*pi*inodo/nnodo))
     rotate (90*(sin(pi*inodo/nnodo))-20)*x
     rotate (yr)*y
     translate <0,yact,zact>
    }
    #if (inodo<nnodo*.6)
    object{
     flor(3+rand(rp),t_leaf,t_est,t_pet,rplant) rotate 360*rand(rp)*y
     rotate (90*(sin(pi*inodo/nnodo)))*x
     rotate -(yr)*y
     translate <0,yact,zact>
    }
    #end
    #if (yr=-65)
     #local yr=65;
    #else
     #local yr=-65;
    #end
   #end
   #local yant=yact;
   #local zant=zact;
   #local inodo=inodo+1;
  #end
   texture{t_leaf}
   rotate (360*(itall/ntall)-10+20*rand(rp))*y
  }
  #local itall=itall+1;
 #end
 }

#end

// *** HANGING PLANT 3 ***
#macro hanging_plant3(ntall,nnodo,radio,t_leaf,rplant)

 #local rp=seed(rplant);
 #local itall=0;
 #local t_est=
 texture{
  pigment{Gold}
  #if (use_normals)
  normal{granite scale .1}
  #end
 }
 #local t_pet=
 texture{
  pigment{Tan}
  finish{metallic}
 }

 union{
 #while (itall<ntall)
  union{
  #local inodo=1;
  #local yant=0;
  #local zant=0;
  #local k=.2+rand(rp);
  #while (inodo<=(nnodo*.75+nnodo*.25*rand(rp)))
   #local yact=+inodo;
   #local zact=-radio*.5*(sin(k*pi*(inodo/nnodo)));
   cylinder{<0,yant,zant>,<0,yact,zact>,.25
    texture{t_leaf}
   }
   #if (inodo>nnodo*.4 & (mod(inodo,2)=0))
    object{hoja2(rand(rp))
     scale <.5,(1.2-.4*sin(.5*pi*inodo/nnodo)),1>
     texture{t_leaf}
     rotate (40+10*rand(rp))*x
     rotate (4*360*inodo/nnodo)*y
     translate <0,yact,zact>
    }
   #end
   #local yant=yact;
   #local zant=zact;
   #local inodo=inodo+1;
  #end
   object{
    flor(3+rand(rp),t_leaf,t_est,t_pet,rplant) rotate 360*rand(rp)*y
    translate <0,yact,zact>
   }
   rotate (360*(itall/ntall)-10+20*rand(rp))*y
  }
  #local itall=itall+1;
 #end
 }

#end

// *** CACTUS 1 ***
#macro cactus_plant1(nnodo,radio,t_leaf,rplant)

 #local rp=seed(rplant);
 #local inodo=0;

 union{
 #while (inodo<nnodo)
  union{
   sphere{0,1 scale <radio*.5,radio,radio>
    texture{t_leaf}
   }
  #local npuas=16;
  #local ipuas=0;
  #while (ipuas<npuas)
   cone{<0,0,0>,.3,<0,0,-2>,.01
    pigment{Flesh}
    translate -radio*z
    rotate (180*ipuas/npuas)*x
   }
   #local ipuas=ipuas+1;
  #end
   scale <1,2,1>
   translate -radio*.5*z
   rotate (360*inodo/nnodo)*y
  }
  #local inodo=inodo+1;
 #end
 }

#end

#declare r_p1=seed(69);
#declare r_p2=seed(119);
#declare r_p3=seed(98);
#declare r_p4=seed(937);
#declare r_p5=seed(64);
#declare r_p6=seed(76);
#declare r_p7=seed(38);
#declare r_p8=seed(41);
#declare r_p9=seed(176);
#declare planta1=
union{
 object{achmea_plant1(10,.1,3,16,4,t_leaf,r_p1)
  rotate 360*rand(r_p1)*y
  translate 10*y
 }
 object{pot1 scale .9}
}
#declare planta2=
union{
 object{hanging_plant(10,32,16,t_leaf2,r_p3)
  rotate 90*y
  translate 6*y
 }
 object{pot1 scale .9}
}
#declare planta3=
union{
 object{achmea_plant2(10,.1,3,4,8,t_leaf,r_p8)
  scale 1.5
  rotate 70*y
  translate 10*y
 }
 object{pot2}
}
#declare cactus1=
union{
 object{cactus_plant1(6,5,t_leaf,r_p5)
  rotate 360*rand(r_p5)*y
  translate 16*y
 }
 object{pot6}
 scale .5
 rotate 50*y
}
#declare cactus2=
union{
 object{cactus_plant1(8,5,t_leaf2,r_p6)
  rotate 360*rand(r_p6)*y
  translate 16*y
 }
 object{pot4}
 scale .6
}

