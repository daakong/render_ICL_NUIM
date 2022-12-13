/*

  The Kitchen - Jaime Vives Piqueres 2004-2005

  Entry for the POVCOMP 2004

  i_orange.inc : isosurface orange

*/

// *** ORANGES ***
#if (use_oranges)
#declare sk=20;
#declare orange=
union{
isosurface{
 function{
  f_sphere(x,y,z,1)*f_ph(x,y,z)
  -cos(f_th(x,y,z)*4)*.02
  +f_bumps(x*2,y*2,z*2)*.1+f_granite(x,y,z)*.005 //-f_bumps(x*sk,y*sk,z*sk)*.01
 }
 max_gradient 3
 contained_by{sphere{0,1}}
 hollow
 scale 3.1
 #if (use_textures)
 texture{
  pigment{rgbt <1,.5,0>}
  normal{granite scale .4}
  finish{Phong_Shiny reflection{.01,.1} diffuse .9}
 }
 #else
 texture{pigment{Orange} finish{diffuse .9}}
 #end
}
cylinder{<0,0,0>,<0,2.9,0>,.1 pigment{DarkGreen}}
}
#end

