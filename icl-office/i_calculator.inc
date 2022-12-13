/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Calculator

*/

// material map texture
#declare t_calc=
 texture{
  material_map{
   tga "mm_sccal"
   texture{pigment{Gray10} finish{Phong_Shiny reflection 0.1}}
   texture{pigment{Gray10} finish{Phong_Shiny reflection 0.1}}
   texture{pigment{Gray10} finish{Phong_Shiny reflection 0.1}}
   texture{pigment{Gray10} finish{Phong_Shiny}}
   texture{Brushed_Aluminum scale <1,0.1,0.1>}
   texture{pigment{Thistle} finish{Phong_Dull}}
   texture{pigment{Gray20} finish{Phong_Shiny reflection 0.1}}
   texture{Silver_Texture}
   texture{pigment{White} finish{Phong_Shiny}}
   texture{pigment{Red} finish{Phong_Shiny}}
   texture{pigment{Black}}
  }
  translate <-0.5,-0.5,0>
  rotate 90*x
 }

// calculator
#declare calculadora=
union{
 height_field{
  png "hf_sccal"
  translate <-0.5,-0.5,-0.5>
  texture{t_calc}
  scale <7.2,3,14.2>
 }
 box{<-0.5,-0.5,-0.5>,<0.5,0.5,0.5>
  scale <7.2,1,14.2>
  translate -2*y
  texture{pigment{Black} finish{Phong_Dull}}
 }
}
