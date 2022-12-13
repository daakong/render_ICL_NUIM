/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Textures for the office

*/

// wall texture
//#include "glass_old.inc"
#declare t_pintura_pared=
texture{
 pigment{
  rgb ReflectiveSpectrum(RS_White_Paint_1)
 }
 finish{diffuse .8}
}

// furniture wood
#declare p_madera_mesa=ReflectiveSpectrum(RS_madera_mesa);
#declare n_mesa=
normal{crackle -.05 scale .01}
#declare t_mesas=
texture{
 #if (use_textures)
 T_Wood2 scale 20
 finish{reflection {.05,.15}}
 #else
 pigment{rgb p_madera_mesa}
 #end
 #if (use_normals)
 normal{n_mesa}
 #end
}

#declare t_azul_mesas=
texture{
 pigment{rgb ReflectiveSpectrum(RS_pintura_armario)}
 finish{phong 1 phong_size 10}
}

// floor checker
#declare t_suelo1=
texture{
 T_Stone29 scale 4
 #if (use_textures)
 normal{bumps .05 scale 50}
 finish{reflection{.01,.2}}
 #end
}
#declare t_suelo2=
texture{
 T_Grnt15 scale 8 rotate 90*x
 #if (use_textures)
 normal{bumps .05 scale 50}
 finish{reflection{.01,.2}}
 #end
}

// water bottle 
 #declare t_white_plastic=
 texture{
  pigment{rgb ReflectiveSpectrum(RS_White_Shiny_Plastic)}
  finish{diffuse .9}
 }

#declare t_wb_tap=t_white_plastic
 #declare t_wb_label=
 texture{
  pigment{image_map{png "im_wblabel" map_type 2}}
  scale .45
  translate .2*y
 }
 #declare t_wb_pet=texture{T_Glass4 finish{ambient 0}}

// glasses
#declare t_normal_glass=
texture{
 T_Glass1
 #if (use_normals)
 normal{bumps .01 scale 24}
 #end
 finish{diffuse .1}
}
#declare i_sep_glass=
interior{I_Glass1}
#declare t_quilted_glass=
texture{
 Glass
 normal{quilted scale 5}
}

// others
#declare t_black_plastic=
texture{
 pigment{rgb ReflectiveSpectrum(RS_BlackDiskettePlastic)}
 #if (use_textures)
 finish{phong 1 phong_size 24}
 #end
}

#declare t_normal_chrome=
texture{
 pigment{rgb ReflectiveSpectrum(RS_BoltMetal2)}
 #if (use_textures)
 #if (use_normals)
 normal{bumps .02 scale .1}
 #end
 finish{Metal ambient 0}
 #end
}

#declare t_pintura_metalizada=
texture{
 pigment{rgb ReflectiveSpectrum(RS_BoltMetal1)}
 #if (use_textures)
 #if (use_normals)
 normal{bumps .02 scale .1}
 #end
 finish{Metal ambient 0}
 #end
}

#declare t_pintura_marron=
texture{
 pigment{rgb ReflectiveSpectrum(RS_Tan_Plastic)}
 #if (use_textures)
 #if (use_normals)
 normal{bumps .01 scale 8}
 #end
 finish{Phong_Shiny reflection{.01,.2} ambient 0}
 #end
}

#declare t_pintura_verde=
texture{
 pigment{rgb ReflectiveSpectrum(RS_OldJohnDeere_Paint)}
 #if (use_textures)
 #if (use_normals)
 normal{bumps .01 scale 8}
 #end
 finish{Phong_Shiny reflection{.01,.1} ambient 0}
 #end
}

#declare t_pintura_blanca=
texture{
 pigment{rgb ReflectiveSpectrum(RS_White_Paint_1)}
 finish{diffuse .7}
}

#declare t_lamp=
texture{
 pigment{rgb ReflectiveSpectrum(RS_BoltMetal2)}
 #if (use_textures)
 finish{F_MetalE ambient 0}
 #end
}

#declare t_aluminum=
texture{
 pigment{rgb ReflectiveSpectrum(RS_WindowAluminum)}
 #if (use_textures)
 finish{Metal ambient 0}
 #end
}

// chairs
#declare t_silla=
texture{
 pigment{rgb ReflectiveSpectrum(RS_BlackLeather)}
 #if (use_textures)
 #if (use_normals)
 normal{crackle .1 turbulence .3 scale 2}
 #end
 finish{phong 1 phong_size 24 reflection{.01,.05}}
 #end
}
#declare t_silla_gir=
texture{
 pigment{rgb ReflectiveSpectrum(RS_TanLeather)}
 #if (use_normals)
 normal{quilted scale .1}
 #end
}
#declare p_chaise_tisu=
pigment{rgb ReflectiveSpectrum(RS_pintura_armario)}

// telephone 
#declare t_telefono=
texture{
 pigment{rgb ReflectiveSpectrum(RS_White_Paint_1)*.9}
 finish{Phong_Shiny reflection{.01,.1} ambient 0}
}

#declare t_bote1=
texture{
 pigment{rgb ReflectiveSpectrum(RS_BlueRubber)}
 #if (use_normals)
 normal{bumps 0.1 scale 8}
 #end
 #if (use_textures)
 finish{reflection .1}
 #end
}
#declare t_bote2=
texture{
 pigment{rgb ReflectiveSpectrum(RS_Red_Plastic1)}
 #if (use_normals)
  normal{bumps 0.1 scale 8}
 #end
 #if (use_textures)
 finish{reflection .1}
 #end
}

#declare t_calc=
 texture{
  material_map{
   gif "im_sccal.gif"
   texture{t_black_plastic}
   texture{pigment{Brown} finish{Metal}}
   texture{pigment{Green/3+Gray/2} finish{Metal}}
   texture{t_pintura_metalizada}
   texture{t_black_plastic finish{Phong_Shiny}}
   texture{t_aluminum}
   texture{t_pintura_marron}
   texture{t_black_plastic finish{Phong_Shiny reflection 0.1}}
   texture{t_lamp}
   texture{t_pintura_blanca}
   texture{t_bote2}
   texture{t_black_plastic}
  }
  translate <-0.5,-0.5,0>
  rotate 90*x
 }

// computer equipment
#declare f_jv_computer=finish{
  phong 1 phong_size 20
  diffuse 1
}
#declare t_cdrom=texture{
     pigment{rgb ReflectiveSpectrum(RS_ComputerPlastic2)}
     finish{f_jv_computer}
}
#declare t_computer1=texture{
     pigment{rgb ReflectiveSpectrum(RS_ComputerPlastic1)}
     finish{f_jv_computer}
}
#declare t_computer3=texture{
    pigment{rgb ReflectiveSpectrum(RS_ComputerPlastic2)}
    finish{f_jv_computer}
}
#declare t_floppy=texture{
 pigment{rgb ReflectiveSpectrum(RS_ComputerPlastic2)}
 finish{f_jv_computer}
}
#declare t_ac_plastic=texture{
 pigment{rgb ReflectiveSpectrum(RS_White_Shiny_Plastic)}
     finish{Shiny reflection{.05,.2}}
}
#declare t_printer_plastic=texture{
     pigment{rgb ReflectiveSpectrum(RS_ComputerPlastic2)}
     finish{specular .3 diffuse 1}
}
#declare t_green_led=texture{pigment{rgb Wavelength(555)}}

// other metals
#declare sb_gold=
texture{
 pigment{rgb ReflectiveSpectrum(RS_Gold)}
 #if (use_textures) 
 finish{Metal diffuse .8 ambient 0}
 #else
 finish{diffuse .8}
 #end
}
#declare t_copper=
texture{
 pigment{rgb ReflectiveSpectrum(RS_CopperNickel1)}
 #if (use_textures) 
 finish{Metal diffuse .7 ambient 0}
 #else
 finish{diffuse .7}
 #end
}

// *** boligrafos ***
#declare t_tapa_b_azul=
texture{
 pigment{NavyBlue}
 finish{Phong_Shiny reflection 0.1}
}
#declare t_tapa_b_rojo=
texture{
 pigment{OrangeRed}
 finish{Phong_Shiny reflection 0.1}
}
#declare t_tapa_b_verde=
texture{
 pigment{ForestGreen}
 finish{Phong_Shiny reflection 0.1}
}
#declare t_tapa_b_negro=
texture{
 pigment{Gray10}
 finish{Phong_Shiny reflection 0.1}
}
#declare t_plast_b=
texture{pigment{White} finish{Shiny reflection .1}}
#declare t_mina_b_azul=
texture{pigment{MidnightBlue filter 0.5} finish{Metal}}
#declare t_mina_b_rojo=
texture{pigment{Firebrick filter 0.5} finish{Metal}}
#declare t_mina_b_verde=
texture{pigment{ForestGreen filter 0.5} finish{Metal}}
#declare t_mina_b_negro=
texture{pigment{Gray20 filter 0.5} finish{Metal}}
#declare t_metal_b=
texture{Chrome_Texture}

#declare t_white_paper=
texture{pigment{rgb ReflectiveSpectrum(RS_White_A4_Paper)} finish{diffuse .7}}
