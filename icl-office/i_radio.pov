/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Radio-casette

*/

// textures
#declare use_test_texture=0;
#declare use_normals=0;
#declare t_plastico_carcasa=texture{
    pigment{rgb ReferenceRGB(Gray10)}
    finish{Phong_Shiny metallic ambient 0}
}

#declare t_metal_rejilla=texture{
    pigment{brick color Gold color Clear scale 0.05}
    finish{Phong_Shiny ambient 0}
    rotate 90*x
}
#declare t_purp_logo=texture{pigment{Gold} finish{Phong_Shiny metallic ambient
0}}
#declare t_metal_aro=texture{Silver_Texture finish{ ambient 0}}
#declare t_cromo=texture{Polished_Chrome finish{ ambient 0}}
#declare t_membrana=texture{pigment{Gray20} finish{Dull ambient 0}}
#declare t_plastico_trans=texture{Glass2 finish{reflection 0.1 ambient 0}}
#declare t_plastico_mate=texture{t_plastico_carcasa finish{Dull metallic ambient 0}}


// *** ALTAVOZ ***
// +++ medidas (cm) +++
#declare ancho_altvz=14.5;
#declare alto_altvz=21;
#declare hondo_altvz=16;
// +++ caja acustica +++
#declare caja=
difference{
 superellipsoid{<.1,.1>
  scale <ancho_altvz/2,alto_altvz/2,hondo_altvz/2>
 }
 box{
  <-(ancho_altvz/2)+1,-(alto_altvz/2)+4,-hondo_altvz>
  < (ancho_altvz/2)-1, (alto_altvz/2)-2,-(hondo_altvz/2)+2>
 }
 sphere{<0,0,0>,1
  scale <-(ancho_altvz/2)+2,1,0.5>
  translate <0,-(alto_altvz/2)+2.5,-hondo_altvz/2>
 }
 cylinder{<0,0,(hondo_altvz/2)-1>,<0,0,-hondo_altvz>,4.6
  translate -1*y
 }
 box{
  <-ancho_altvz/4+1,-1.2,-ancho_altvz/4+1>
  < ancho_altvz/4-1, 1.2, ancho_altvz/4-1>
  rotate 45*y
  translate <0,6,-(hondo_altvz/2)+2>
 }
 texture{t_plastico_carcasa}
}
// +++ rejilla +++
#declare rejilla=
intersection{
 superellipsoid{<.1,.1>
  scale <(ancho_altvz/2)-1,(alto_altvz/2)-3,2>
 }
 plane{z,0}
 texture{t_metal_rejilla}
}
// +++ bafle +++
#declare aro_bafle=
difference{
 sphere{<0,0,0>,6 scale <1,1,0.2>}
 cylinder{<0,0,6>,<0,0,-6>,4.5}
 plane{y, 5 inverse}
 plane{y,-5 }
 plane{x, 5 inverse}
 plane{x,-5 }
 sphere{<0,0,0>,0.30 translate <-3.7, 3.7,-1>}
 sphere{<0,0,0>,0.30 translate < 3.7, 3.7,-1>}
 sphere{<0,0,0>,0.30 translate <-3.7,-3.7,-1>}
 sphere{<0,0,0>,0.30 translate < 3.7,-3.7,-1>}
 texture{t_metal_aro}
}
#declare tornillo=
sphere{<0,0,0>,.25
 texture{t_cromo}
}
#declare cono_bafle=
union{
 intersection{
  sphere{<0,0,0>,1}
  plane{z,0}
 }
 intersection{
  sphere{<0,0,0>,1.2}
  plane{z,0 inverse}
 }
 texture{t_cromo}
}
#declare membrana=
cone{
 <0,0,0>,4.51
 <0,0,1>,1.19
 open
 texture{t_membrana}
}
#declare bafle=
union{
  object{aro_bafle}
  object{tornillo translate <-3.7, 3.7,-1>}
  object{tornillo translate < 3.7, 3.7,-1>}
  object{tornillo translate <-3.7,-3.7,-1>}
  object{tornillo translate < 3.7,-3.7,-1>}
  object{membrana}
  object{cono_bafle translate 1*z}
}
// +++ logotipo de la marca +++
#declare t2p_thr =          0.5;
#declare t2p_frz =          0.5;
#declare t2p_rad =          1.5;
// caracter A
#declare Car_65 = blob{ threshold t2p_thr
    component t2p_frz, t2p_rad, <        -2.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -1.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         5.5,0>
    component t2p_frz, t2p_rad, <         0.5,         5.5,0>
    component t2p_frz, t2p_rad, <         1.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         4.5,0>
    component t2p_frz, t2p_rad, <         1.5,         4.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         3.5,0>
    component t2p_frz, t2p_rad, <         1.5,         3.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         2.5,0>
    component t2p_frz, t2p_rad, <         1.5,         2.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -1.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         1.5,0>
    component t2p_frz, t2p_rad, <         0.5,         1.5,0>
    component t2p_frz, t2p_rad, <         1.5,         1.5,0>
    component t2p_frz, t2p_rad, <         2.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         0.5,0>
    component t2p_frz, t2p_rad, <         2.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -0.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -1.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -2.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -2.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -2.5,0>
}


// caracter I
#declare Car_73 = blob{ threshold t2p_thr
    component t2p_frz, t2p_rad, <        -0.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         4.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         3.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         2.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         1.5,0>
    component t2p_frz, t2p_rad, <         0.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         0.5,0>
    component t2p_frz, t2p_rad, <         0.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -0.5,        -0.5,0>
    component t2p_frz, t2p_rad, <         0.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -0.5,        -1.5,0>
    component t2p_frz, t2p_rad, <         0.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -0.5,        -2.5,0>
    component t2p_frz, t2p_rad, <         0.5,        -2.5,0>
}


// caracter G
#declare Car_71 = blob{ threshold t2p_thr
    component t2p_frz, t2p_rad, <        -2.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -1.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -0.5,         5.5,0>
    component t2p_frz, t2p_rad, <         0.5,         5.5,0>
    component t2p_frz, t2p_rad, <         1.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         4.5,0>
    component t2p_frz, t2p_rad, <         2.5,         4.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         3.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         2.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         1.5,0>
    component t2p_frz, t2p_rad, <         0.5,         1.5,0>
    component t2p_frz, t2p_rad, <         1.5,         1.5,0>
    component t2p_frz, t2p_rad, <         2.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         0.5,0>
    component t2p_frz, t2p_rad, <         2.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -0.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -1.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -2.5,0>
    component t2p_frz, t2p_rad, <        -1.5,        -2.5,0>
    component t2p_frz, t2p_rad, <        -0.5,        -2.5,0>
    component t2p_frz, t2p_rad, <         0.5,        -2.5,0>
    component t2p_frz, t2p_rad, <         1.5,        -2.5,0>
}


// caracter U
#declare Car_85 = blob{ threshold t2p_thr
    component t2p_frz, t2p_rad, <        -3.5,         5.5,0>
    component t2p_frz, t2p_rad, <         2.5,         5.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         4.5,0>
    component t2p_frz, t2p_rad, <         2.5,         4.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         3.5,0>
    component t2p_frz, t2p_rad, <         2.5,         3.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         2.5,0>
    component t2p_frz, t2p_rad, <         2.5,         2.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         1.5,0>
    component t2p_frz, t2p_rad, <         2.5,         1.5,0>
    component t2p_frz, t2p_rad, <        -3.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -2.5,         0.5,0>
    component t2p_frz, t2p_rad, <         2.5,         0.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -0.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -0.5,0>
    component t2p_frz, t2p_rad, <        -3.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -1.5,0>
    component t2p_frz, t2p_rad, <         2.5,        -1.5,0>
    component t2p_frz, t2p_rad, <        -2.5,        -2.5,0>
    component t2p_frz, t2p_rad, <        -1.5,        -2.5,0>
    component t2p_frz, t2p_rad, <        -0.5,        -2.5,0>
    component t2p_frz, t2p_rad, <         0.5,        -2.5,0>
    component t2p_frz, t2p_rad, <         1.5,        -2.5,0>
}


#declare LOGO = union{
// caracter A
  object{ Car_65
  translate <       -16.00,         0,0>}
// caracter I
  object{ Car_73
  translate <        -8.00,         0,0>}
// caracter G
  object{ Car_71
  translate <         0.00,         0,0>}
// caracter U
  object{ Car_85
  translate <         8.00,         0,0>}
// caracter A
  object{ Car_65
  translate <        16.00,         0,0>}
}


#declare aigua_logo=
object{
 LOGO
 texture {t_purp_logo}
 translate<0,         0.00,0>
}
// +++ tuiter +++
#declare tuiter=
union{
 difference{
  superellipsoid{<.1,.1>
   scale <ancho_altvz/2-2,1.8,1>
  }
  box{
   <-ancho_altvz/4+1,-1.2,-ancho_altvz/4+1>
   < ancho_altvz/4-1, 1.2, ancho_altvz/4-1>
   rotate 45*y
  }
  texture{t_metal_aro}
 }
 sphere{<0,0,4.5>,1.2 scale <1,1,0.3> texture{t_cromo}}
}
// +++ altavoz completo +++
#declare altavoz=
union{
 object{caja}
// object{rejilla
//  translate <0,1,-(hondo_altvz/2)+1.5>
// }
 object{tuiter
  translate <0,6,-(hondo_altvz/2)+2.5>
 }
 object{bafle
  translate <0,-1,-(hondo_altvz/2)+2>
 }
 /*object{aigua_logo
  scale 0.1
  translate <0,(alto_altvz/2)-1.3,-(hondo_altvz/2)>
 }*/
}
// *** CUERPO ***
// +++ medidas (cm) +++
#declare ancho_carca=33.5;
#declare alto_carca=20;
#declare hondo_carca=14;
// +++ carcasa +++
#declare carcasa=
difference{
 superellipsoid{<.1,.1>
  scale <ancho_carca/2,alto_carca/2,hondo_carca/2>
 }
 superellipsoid{<.1,.1>
  scale <ancho_carca/2-1,alto_carca/2-3,hondo_carca>
  translate <0,1,-hondo_carca+4>
 }
 texture{t_plastico_carcasa}
}
#declare patas=
union{
 cylinder{
  <-ancho_carca/2+3.5,0,0>
  <-ancho_carca/2+3.5,1,0>
  1.5
 }
 cylinder{
  < ancho_carca/2-3.5,0,0>
  < ancho_carca/2-3.5,1,0>
  1.5
 }
 texture{t_metal_aro}
}
#declare tapa_caset=
union{
 difference{
 superellipsoid{<.1,.1>
   scale <15.75/2,3.6,1>
  }
  box{
   <-4,-1,-2>
   < 4, 1, 2>
  }
  texture{t_plastico_carcasa}
 }
 box{
  <-4,-1,-0.1>
  < 4, 1, 0>
  texture{t_plastico_trans}
  translate -0.5*z
 }
}
#declare pulsador=
intersection{
 superellipsoid{<.1,.1>
  scale <1,2,0.5>
 }
 plane{y,.75 inverse}
 texture{t_plastico_mate}
}
#declare botonera=
union{
 object{pulsador translate 0*x}
 object{pulsador translate 2*x}
 object{pulsador translate 4*x}
 object{pulsador translate 6*x}
 object{pulsador translate 8*x}
 object{pulsador translate 10*x}
}
#declare panel_caset=
union{
 object{tapa_caset
  translate <(ancho_carca/2-1)-15.75/2,-alto_carca/2+4+3.5,-hondo_carca/2>
 }
 object{tapa_caset
  translate <(ancho_carca/2-1)-15.75/2-15.75,-alto_carca/2+4+3.5,-hondo_carca/2>
 }
 object{botonera
  translate <(ancho_carca/2-1)-15.75/2-5,-alto_carca/2+1,-hondo_carca/2+0.25>
 }
 object{botonera
  translate <(ancho_carca/2-1)-15.75/2-15.75-5,-alto_carca/2+1,-hondo_carca/2+0.25>
 }
}
#declare panel_base=
difference{
 superellipsoid{<.1,.1>
  scale <15.75,3.6,1>
 }
 superellipsoid{<.1,.1>
  scale <8,3.5,4>
 }
 texture{t_plastico_carcasa}
}
#declare leds=
box{
 <-7.9,-1.4,-1/3>
 < 7.9,1.4,1/3>
 texture{
  pigment{
   image_map{
    gif "leds_im.gif"
   }
   translate <-0.5,-0.5,0>
   scale <7.9*2,1.4*2,1>
  }
  finish{ambient 3 diffuse 0}
 }
}
#declare display=
intersection{
 superellipsoid{<.1,.1>
  scale <7.9,1.4,1>
 }
 plane{z,0}
 texture{t_plastico_trans}
}
#declare faders=
union{
 difference{
  intersection{
  superellipsoid{<.1,.1>
    scale <7.9,2,1.1>
   }
   plane{z,0}
  }
  box{<-7.1,-1.6,-2>,<-6.9,1.6,1>}
  box{<-6.1,-1.6,-2>,<-5.9,1.6,1>}
  box{<-5.1,-1.6,-2>,<-4.9,1.6,1>}
  box{<-4.1,-1.6,-2>,<-3.9,1.6,1>}
  box{<-3.1,-1.6,-2>,<-2.9,1.6,1>}
  box{<-2.1,-1.6,-2>,<-1.9,1.6,1>}
 }
 union{
  superellipsoid{<.1,.1> scale <0.3,0.2,0.5> translate <-7,1.6,-1>}
  superellipsoid{<.1,.1> scale <0.3,0.2,0.5> translate <-6,1.4,-1>}
  superellipsoid{<.1,.1> scale <0.3,0.2,0.5> translate <-5,1.1,-1>}
  superellipsoid{<.1,.1> scale <0.3,0.2,0.5> translate <-4,0.6,-1>}
  superellipsoid{<.1,.1> scale <0.3,0.2,0.5> translate <-3,0.8,-1>}
  superellipsoid{<.1,.1> scale <0.3,0.2,0.5> translate <-2,0.1,-1>}
  translate -1*y
 }
 object{pulsador scale <0.5,0.5,0.5> translate <0.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <1.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <2.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <3.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <4.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <5.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <6.5,0,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <0.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <1.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <2.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <3.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <4.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <5.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <6.5,-1,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <0.5,-2,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <1.5,-2,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <2.5,-2,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <3.5,-2,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <4.5,-2,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <5.5,-2,-1>}
 object{pulsador scale <0.5,0.5,0.5> translate <6.5,-2,-1>}
 texture{t_plastico_mate}
}
#declare rueda=
difference{
 cylinder{
  <0,0,-0.5>
  <0,0, 0.5>
  0.8
 }
 sphere{<-0.8,0,-0.2>,0.5}
 sphere{< 0.8,0,-0.2>,0.5}
 texture{t_plastico_mate}
}
#declare panel_radio=
union{
 object{panel_base translate <0,alto_carca/2-2-3.5+0.2,-hondo_carca/2>}
 object{display translate <0,alto_carca/2-2-3+1.7,-hondo_carca/2>}
 object{leds translate <0,alto_carca/2-2-3+1.7,-hondo_carca/2+1>}
 object{faders translate <0,alto_carca/2-2-3-1.7+0.2,-hondo_carca/2>}
 object{rueda translate <-ancho_carca/2+3,alto_carca/2-7,-hondo_carca/2-1.5>}
 object{rueda translate <-ancho_carca/2+6,alto_carca/2-7,-hondo_carca/2-1.5>}
 object{rueda translate < ancho_carca/2-3,alto_carca/2-7,-hondo_carca/2-1.5>}
 object{rueda translate < ancho_carca/2-6,alto_carca/2-7,-hondo_carca/2-1.5>}
// object{tuning}
}
#declare asa=
union{
 cylinder{
  <-ancho_carca/2+3.5,5,0>
  < ancho_carca/2-3.5,5,0>
  1.2
 }
 box{
  <-ancho_carca/2+3.5,0,-1>
  <-ancho_carca/2+3.5-1,6.2,1>
 }
 box{
  < ancho_carca/2-3.5,0,-1>
  < ancho_carca/2-3.5+1,6.2,1>
 }
 texture{t_plastico_mate}
}
#declare antena=
union{
 cylinder{
  <0,0,0>
  <0,1,0>
  0.30
 }
 union{
  cone{
   <0,0,0>,0.3
   <0,20,0>,0.27
  }
  cone{
   <0,20,0>,0.25
   <0,30,0>,0.22
  }
  cone{
   <0,30,0>,0.20
   <0,35,0>,0.17
  }
  cone{
   <0,35,0>,0.15
   <0,37,0>,0.12
  }
  cone{
   <0,37,0>,0.1
   <0,37.2,0>,0.3
  }
  rotate 60*z
  rotate -10*y
  translate 1*y
 }
 sphere{<0,1,0>,0.35}
 texture{t_metal_aro}
}
// +++ radio/casette +++
#declare jvp_combo=
union{
  object{altavoz
   translate (-(ancho_carca/2)-(ancho_altvz/2))*x
  }
  object{altavoz
   translate ((ancho_carca/2)+(ancho_altvz/2))*x
  }
 object{carcasa}
 object{panel_radio}
 object{panel_caset}
 object{patas
  translate <0,-alto_carca/2-1,-hondo_carca/2+1.5>
 }
 // object{rotores}
 object{asa
  translate <0,alto_carca/2,0>
 }
 object{antena translate <ancho_carca/2-2,alto_carca/2,3>}
 object{aigua_logo
  scale 0.1
  translate <-ancho_carca/2+5,(alto_carca/2)-3,-(hondo_carca/2)-1>
 }
 translate (alto_altvz/2)*y
}
