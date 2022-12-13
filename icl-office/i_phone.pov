/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Telephone

*/

// - earpiece -
// hang
#declare aur_trans=
transform{
 rotate <0,0,0>
 translate <0,0,0>
}
#declare P1=vtransform(<-6.4,1.8,-9>,aur_trans);
#declare P2=<-7,.1,-10>;
#declare P3=<-7,-1.5,-24>;
// placed at the right
/*
#declare aur_trans=
transform{
 rotate <9,0,0>
 translate <15,-3.5,0>
}
#declare P1=vtransform(<-6.4,1.8,-9>,aur_trans);
#declare P2=<-7,.1,-10>;
#declare P3=<-5,-.4,-24>;
*/
// floating bellow
/*
#declare aur_trans=
transform{
 rotate <-23,15,10>
 translate <5,13.5,-4>
}
#declare P1=vtransform(<-6.4,1.8,-9>,aur_trans);
#declare P2=<-7,.1,-10>;
#declare P3=<-5,-.4,-24>;
*/

// curved spline between two point p1 and p2, and has a middle point p3
#macro random_curved_spline(p1,p2,p3,sp_res,xsc,ysc,xmag,ymag)
 #local cnt=sp_res;
 // guide path
 #local tmp_sp=spline{natural_spline 0,p1 0.5,p3 1,p2}
 spline{natural_spline
 -sp_res,p1
 0,p1
 #while (cnt<(1))
  cnt,tmp_sp(cnt)+<xsc*sin(xmag*cnt)*abs(sin(pi*cnt)),ysc*cos(ymag*cnt)*abs(sin(pi*cnt)),0>
  #declare cnt=cnt+sp_res;
 #end
 1,p2
 1+sp_res,p2
 }
#end

// macro cable helicoidal
#macro helicoidal_cable(cable_rad,spl_cable,t_cable)
#local cable_step=0.01;
#local ctr=cable_step;
#local ant=(spl_cable(0));
#local nb=200;
#local epsilon=0.00001;
sphere_sweep{
 b_spline,int(1/cable_step)+3,
 spl_cable(-.1),cable_rad
 spl_cable(0),cable_rad
 #while (ctr<1-cable_step)
  #local tg=vnormalize((spl_cable(ctr+epsilon))-(spl_cable(ctr-epsilon))); // tangent
  // helicoidal transform along the tangent
  #local kk=(spl_cable(ctr))+vtransform(<cos(nb*ctr),0,sin(nb*ctr)>,Point_At_Trans(tg));
  kk,cable_rad
  #local ctr = ctr + cable_step;
 #end
 spl_cable(1-cable_step),cable_rad
 spl_cable(1),cable_rad
 spl_cable(1.1),cable_rad
 texture{t_cable}
}
#end

// make random curved path
#declare spl_telef=random_curved_spline(P1,P2,P3,0.1,4,.5,5,10)

// create an helicoidal cable along the path
#declare tel_cable=
helicoidal_cable(.2,spl_telef,t_telefono)

#declare tel_num=
height_field{
 gif "hf_tfno"
 translate -.5
}

#declare jvp_telefono=
union{
 intersection{
  superellipsoid{<.2,.2> rotate 90*x scale .5
   scale <15,4,20>
  }
  plane{y,0}
  texture{t_telefono}
 }
 superellipsoid{<.2,.2> rotate 90*x scale .5
  scale <15,.5,20>
  texture{t_telefono}
  translate .25*y
 }
 intersection{
  difference{
   superellipsoid{<.2,.2> rotate 90*x scale .5
    scale <15,4,20>
   }
   superellipsoid{<.2,.2> rotate 90*x scale .5
    scale <4,2,18>
    translate <-4,2,0>
   }
   object{tel_num
    scale <150*.05,.5,260*.05>
    rotate -8*x
    translate <2.5,2,-1>
        rotate 8*x
   }
   rotate -8*x
  }
  plane{y,0 inverse}
  texture{t_telefono}
 }
 union{
  superellipsoid{<.1,.5> rotate 90*x scale .5 scale <4,2,18>}
  superellipsoid{<.1,.9> rotate 90*x scale .5 scale <4,2,18> translate .4*y}
  superellipsoid{<.2,.5> rotate 90*x scale .49 scale <4,2,4> translate <0,-.5,(-18*.5+2)>}
  superellipsoid{<.2,.5> rotate 90*x scale .49 scale <4,2,4> translate <0,-.5,(18*.5-2)>}
  texture{t_telefono}
  rotate -9*x
  translate <-4,3,0>
  transform aur_trans
}
 object{tel_num
  pigment{
   image_map{gif "im_tfno"}
   translate -.5
   rotate 90*x
  }
  finish{reflection .2}
  scale <150*.05,.5,260*.05>
  rotate -8*x
  translate <2.5,1.8,-1>
 }
 object{tel_cable translate <2,-.5,0>}
 object{tel_cable translate <2,-.5,0>}
}

