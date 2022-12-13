/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Classic filer

*/

#declare arch_asa=
intersection{
 cylinder{<-8,0,0>,<8,0,0>,2}
 plane{y,0 inverse}
 scale <1,1,.5>
}
#macro arch_placa(im)
#local p_im=
pigment{
    image_map{jpeg im}
    translate -.5
}
union{
 difference{
  box{-.5,.5}
  box{-.5,.5 scale <.95,.95,1.01>}
  scale <8.2,5.2,.15>
  texture{sb_gold}
 }
 box{-.5,.5 
  texture{CIE_Imagemap(p_im)}
  scale <8,5,.1>
 }
}
#end
#declare archivador1=
union{
 union{
  difference{
   box{-.5,.5 scale <46,130,70>}
   box{-.5,.5 scale <40,124,70> translate -2*z}
  }
  box{-.5,.5 scale <39,int(123/3),70>}
  box{-.5,.5 scale <39,int(123/3),70> translate <0,(124/3),-2>}
  box{-.5,.5 scale <39,int(123/3),70> translate -(124/3)*y}
  texture{t_pintura_marron}
 }
 union{
  object{arch_asa translate <0,-10,-35.1>}
  object{arch_asa translate <0,124/3-10,-35.1-2>}
  object{arch_asa translate <0,-124/3-10,-35.1>}
  texture{t_pintura_metalizada}
 }
 union{
  object{arch_placa("im_ft_e-h.jpg") translate <12,11,-35.1>}
  object{arch_placa("im_ft_a-d.jpg") translate <12,124/3+11,-35.1-2>}
  object{arch_placa("im_ft_i-l.jpg") translate <12,-124/3+11,-35.1>}
 }
 translate 66*y
}
#declare archivador2=
union{
 union{
  difference{
   box{-.5,.5 scale <46,130,70>}
   box{-.5,.5 scale <40,124,70> translate -2*z}
  }
  box{-.5,.5 scale <39,int(123/3),70> translate -4*z}
  box{-.5,.5 scale <39,int(123/3),70> translate <0,(124/3),0>}
  box{-.5,.5 scale <39,int(123/3),70> translate <0,-(124/3),0>}
  texture{t_pintura_marron}
 }
 union{
  object{arch_asa translate <0,-10,-35.1-4>}
  object{arch_asa translate <0,124/3-10,-35.1>}
  object{arch_asa translate <0,-124/3-10,-35.1>}
  texture{t_pintura_metalizada}
 }
 union{
  object{arch_placa("im_ft_q-t.jpg") translate <12,11,-35.1-4>}
  object{arch_placa("im_ft_m-p.jpg") translate <12,124/3+11,-35.1>}
  object{arch_placa("im_ft_u-z.jpg") translate <12,-124/3+11,-35.1>}
 }
 translate 66*y
}

