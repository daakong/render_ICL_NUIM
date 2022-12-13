/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Main scene file

	The scene has to be rendered on two steps:

	1) Saving radiosity data, using quick textures, no normals, no glass,
           without area light, blur nor the window shaders. The control
           switches below are set for this first pass by default. This first 
           pass render can be done at half the resolution, or even lower.
        2) Final render loading radiosity data from previous pass and using
           full textures with normal, glass, area light, blur and all objects.

	Note: this scene uses other includes that you must also download:

	http://www.ignorancia.org/zips/lightsys4.zip
	http://www.ignorancia.org/zips/bookplacer.zip
	http://www.ignorancia.org/zips/meshlath.zip

*/
#version 3.7;

// *** CONTROL CENTER ***
/*#declare use_radiosity=1; // 1st pass: 2 / final: 1
#declare use_area     =1; // 1st pass: 0 / final: 1
#declare use_blur     =80; // 1st pass: 0 / final: >50 at least
#declare use_textures =1; // 1st pass: 0 / final: 1
#declare use_normals  =1; // 1st pass: 0 / final: 1
#declare use_glass    =1; // 1st pass: 0 / final: 1
#declare use_wshaders =1; // 1st pass: 0 / final: 1
#declare use_photons  =1; // 1st pass: 0 / final: 1
*/

#declare use_clock    =1;
#declare use_dandw    =0;
#declare use_dlamps   =0; 
#declare use_tables   =1;
#declare use_plants   =1; 
#declare use_radio    =1;
#declare use_phones   =1;
#declare use_wchairs  =0;
#declare use_nchairs  =0;
#declare use_computers=1;
#declare use_bookcases=1;
#declare use_books    =1;
#declare use_filers   =1;
#declare use_clothrack=0;
#declare use_pictures =1;
#declare use_boxes    =1;
#declare use_calc     =1;
#declare use_papercans=1;
#declare use_paperwork=1;
#declare use_calendars=1;
#declare use_penpots  =1;
#declare use_post_it  =1;
#declare use_coffemugs=1;
#declare use_fluoresc =1; 
#declare use_daylight =0;

#declare use_oranges =1;
#declare use_bottles =0;
#declare use_waterb = 0;
#declare use_smoking  =0; //NO SMOKING!



#declare camera_select=3; // see eof


// *** COMMON DATA ***
#declare room_height=250;
#declare room_width=500;
#declare room_length=740;
#declare wall_width=40;
#declare win_width=150;
#declare win_height=100;
#declare office_height=300; // The height from the world coordinate frame.
#declare table1_pos=<room_width*.5-80-5,0,room_length*.5-150>;
#declare table2_pos=<40,0,-200+10>;
#declare table3_pos=<room_width*.5-80-5,0,room_length*.5-550>;
#declare table4_pos=<-(room_width*.5-80-5),0,room_length*.5-150>;
#declare table5_pos=<-(room_width*.5-80-5),0,room_length*.5-150-5-80>;
#declare table6_pos=<-(room_width*.5-80-5),0,room_length*.5-150-350>;
#declare table7_pos=<-(room_width*.5-80-5),0,room_length*.5-150-5-80-350>;
#declare r_sun=seed(100);


// *** GLOBAL ***
global_settings{
 assumed_gamma 1.0
 #if (use_radiosity)
  #include "i_rad.inc"
 #end
}
#default{
 texture{
  finish{ambient 0}  // before any finish definition
 }
}


// *** STANDARD INCLUDES ***
#include "colors.inc"  
#include "textures.inc"  
#include "metals.inc"
#include "woods.inc"
#include "stones.inc"
#include "glass.inc"
#include "functions.inc"
#include "transforms.inc"


// *** LIGHTSYS ***
#include "CIE.inc"
#include "CIE_tools.inc"
#include "lightsys.inc"
#include "lightsys_constants.inc"
// *** lighting settings ***
CIE_ColorSystemWhitepoint(CIE_ColSys,Blackbody2Whitepoint(4250)) 
CIE_ChromaticAdaption(off)
// setup some light colors and intensities
#declare Lightsys_Brightness=.1;
#declare c_fluor=EmissiveSpectrum(ES_Mitsubishi_Standard_Fluorescent);
#declare lm_fluor=800;
#declare c_halog=EmissiveSpectrum(ES_Compact_White_Fluor);
#declare lm_halog=400;
#declare c_compact=EmissiveSpectrum(ES_Incandescent_60w);
#declare lm_compact=500;
// daylight setup
#if (use_daylight)
#include "i_sky.inc"
#end


// *** CUSTOM TEXTURES ***
#include "rspd_jvp.inc"      // my own database of reflective spsctrums
#include "rspd_aster.inc"    // aster databse
#include "i_rspd_office.inc" // some colors measured in a real office
// setup CIE system for reflective spectrums
CIE_ColorSystemWhitepoint(CIE_ColSys,Illuminant_D50) 
// create textures
#include "i_textures.inc"


// *** ROOM ***
#include "i_constr.inc"
// this office
object{office_room
 translate office_height*y
}
// other copies outside to simulate buildings
object{office_room rotate 180*y
 translate <-room_width*3,office_height,room_length>
}
object{office_room rotate 180*y
 translate <-room_width*3,office_height,room_length*3>
}
// rodapies (english term uknown)
object{rodapies
 translate office_height*y
}
// ceil grilles
#declare grille=
difference{
 cylinder{<0,0,0>,<0,1,0>,15}
 torus{12,1}
 torus{8,1}
 torus{4,1}
 texture{t_pintura_metalizada}
}
union{
 object{grille translate <   0,0, 200>}
 object{grille translate <   0,0,-200>}
 object{grille translate < 200,0,   0>}
 object{grille translate <-200,0,   0>}
 translate (room_height-11)*y
 translate office_height*y
}


// *** DOOR & WINDOWS ***
#include "i_doors-windows.inc"
#if (use_dandw)
union{
 // door
 object{puerta_aluminio(win_width,room_height*3/4,4,3)
  rotate 90*y
  translate <room_width*.5+4,.5*room_height*3/4,room_length*.5-150-win_width>
 }
 // windows
 
 object{ventana_aluminio(win_width*.5,win_height,4,3)
  rotate 90*y 
  translate <-room_width*.5-wall_width*.5,wall_win*2/3+.5*win_height,-win_width*.25>
 }
 object{ventana_aluminio(win_width*.5,win_height,4,3) 
  rotate 90*y 
  translate <-room_width*.5-wall_width*.5,wall_win*2/3+.5*win_height,win_width*.25>
 }
 object{ventana_aluminio(win_width*.5,win_height,4,3) 
  rotate 90*y 
  translate <-room_width*.5-wall_width*.5,wall_win*2/3+.5*win_height,-room_length*.5+win_sep+win_width*.5-win_width*.25>
 }
 object{ventana_aluminio(win_width*.5,win_height,4,3) 
  rotate 90*y 
  translate <-room_width*.5-wall_width*.5,wall_win*2/3+.5*win_height,-room_length*.5+win_sep+win_width*.5+win_width*.25>
 }
 object{ventana_aluminio(win_width*.5,win_height,4,3) 
  rotate 90*y 
  translate <-room_width*.5-wall_width*.5,wall_win*2/3+.5*win_height,room_length*.5-win_sep-win_width*.5-win_width*.25>
 }
 object{ventana_aluminio(win_width*.5,win_height,4,3) 
  rotate 90*y 
  translate <-room_width*.5-wall_width*.5,wall_win*2/3+.5*win_height,room_length*.5-win_sep-win_width*.5+win_width*.25>
 }
 // window shaders
 #if (use_wshaders)
 object{persiana(win_width*1.1,win_height,30)
  translate <-room_width*.5+3,wall_win*2/3+win_height*.5,0>
 }
 object{persiana(win_width*1.1,win_height,25)
  translate <-room_width*.5+3,wall_win*2/3+win_height*.5,-room_length*.5+win_sep+win_width*.5>
 }
 object{persiana(win_width*1.1,win_height,35)
  translate <-room_width*.5+3,wall_win*2/3+win_height*.5,room_length*.5-win_sep-win_width*.5>
 }
 #end
 translate office_height*y
}
#end



// *** FLUORESCENT PANELS ***
#if (use_fluoresc)
#include "i_fluorceil.inc"
object{fluorescent_panels
 translate office_height*y
}
#end


// *** DESKS ***
#if (use_tables)
#include "i_desks.inc"
union{
 object{table_l rotate 180*y translate table1_pos}
 object{table_l translate table3_pos}
 object{table_l rotate 180*y translate table4_pos}
 object{table_l translate table5_pos}
 object{table_l rotate 180*y translate table6_pos}
 object{table_l translate table7_pos}
 translate office_height*y
}
#end


// *** DESK LAMPS ***
#if (use_dlamps)
#include "i_dlamps.inc"
union{
 object{flexo_2 rotate -195*y translate table1_pos+<6,81,-29>}
 object{flexo_1 rotate -15*y translate table3_pos+<6,81,25>}
 object{flexo_3 rotate -195*y translate table6_pos+<6,81,-29>}
 translate office_height*y
}
#end



// *** PLANTS ***
#if (use_plants)
#include "i_plants.inc"
union{
object{planta1 scale .8 translate table6_pos+<62,80.1,-22>}
object{planta2 rotate 34*y translate <8,132,room_length*.5-25>}
object{planta3 rotate 100*y scale .9 translate table4_pos+<62,80.1,-22>}
object{cactus1 translate <-room_width*.5-5,100,-22>}
object{cactus2 translate <-room_width*.5-5,100,-34>}
 translate office_height*y
}
#end


// *** OFFICE TRAYS ***
#if (use_boxes)
#include "i_tray.inc"
object{bandeja(t_bote1) rotate -90*y translate table7_pos+<-60,office_height+80,-2>}
object{bandeja(t_bote2) rotate -90*y translate table7_pos+<-60,office_height+80,-25>}
object{bandeja(t_black_plastic) translate table3_pos+<25,office_height+80,20>}
object{bandeja(t_bote1) translate table5_pos+<-5,office_height+80,20>}
object{bandeja(t_bote2) translate table5_pos+<20,office_height+80,20>}
object{bandeja(t_bote2) translate <-27,office_height+132,room_length*.5-20>}
object{bandeja(t_bote2) translate <-27,office_height+132+7,room_length*.5-20+3>}
object{bandeja(t_bote1) rotate 180*y translate table1_pos+<-55,office_height+80.1,-20>}
object{bandeja(t_bote1) rotate 180*y translate table1_pos+<-55,office_height+80.1+7,-20-3>}
object{bandeja(t_black_plastic) rotate 180*y translate table1_pos+<-30,office_height+80.1,-20>}
object{bandeja(t_black_plastic) rotate 180*y translate table1_pos+<-30,office_height+80.1+7,-20-3>}
object{bandeja(t_black_plastic) rotate 180*y translate table1_pos+<-30,office_height+80.1+7+7,-20-6>}
#end


// *** PAPERCANS ***
#if (use_papercans)
#include "i_papercan.inc"
#include "i_paperballs.inc"
object{papelera(t_pintura_verde) rotate 78*y scale <24,18,24> translate table5_pos+<-59,0,-69> translate office_height*y}
object{papelera(t_pintura_verde) rotate 95*y scale <24,18,24> translate table6_pos+<103,0,-40> translate office_height*y}
object{wrinkled_paper(seed(19),2) translate table6_pos+<111,2,-57> translate office_height*y}
#end


// *** PAPERS, MAGAZINES...***
#if (use_paperwork)
#include "i_paperwork.inc"
object{povmag
 rotate -25*y
 translate table3_pos+<-27,80.8,-17>
 translate office_height*y
}
union{
 object{pile_of_paper rotate 5*y}
 object{pile_of_paper rotate 0*y translate 1*y}
 object{pile_of_paper rotate 3*y translate 2*y}
 object{pile_of_paper rotate 6*y translate 3*y}
 translate table7_pos+<-11,81,17> 
 translate office_height*y
}
union{
 object{pile_of_paper rotate 15*y}
 object{pile_of_paper rotate 40*y translate 1*y}
 translate table5_pos+<-34,81,-16>
 translate office_height*y
}
union{
 object{pile_of_paper rotate 15*y}
 object{pile_of_paper rotate -20*y translate 1*y}
 translate table6_pos+<44,81,16>
 translate office_height*y
}
union{
 object{pile_of_paper scale .9 rotate 5*y}
 object{pile_of_paper scale .9 rotate -2*y translate 1*y}
 translate table1_pos+<-55,80.1+7+3,-20-3>
 translate office_height*y
}
union{
 object{pile_of_paper scale .9 rotate 1*y}
 object{pile_of_paper scale .9 rotate -2*y translate 1*y}
 translate table1_pos+<-30,80.1+7+7+3,-20-6>
 translate office_height*y
}
union{
 object{pile_of_paper rotate 5*y}
 object{pile_of_paper rotate 0*y translate 1*y}
 object{pile_of_paper rotate 3*y translate 2*y}
 object{pile_of_paper rotate 6*y translate 3*y}
 object{pile_of_paper rotate -2*y translate 4*y}
 object{pile_of_paper rotate -4*y translate 5*y}
 translate <27,office_height+132,room_length*.5-20+3>
}
union{
 object{bills rotate 1*y}
 object{bills rotate 0*y translate <1,1,-1>}
 object{bills rotate -2*y translate <0,2,1>}
 scale .8
 translate table3_pos+<25,office_height+82,20>
}
union{
 object{bills rotate 1*y}
 object{bills rotate 0*y translate <1,1,-1>}
 object{bills rotate -2*y translate <0,2,1>}
 scale .9 rotate 90*y
 translate table7_pos+<-60,office_height+82,-2>
}
union{
 object{bills rotate 1*y}
 object{bills rotate 0*y translate <1,1,-1>}
 object{bills rotate -2*y translate <0,2,1>}
 object{bills rotate 0*y translate <-1,3,0>}
 scale .9
 translate <-27,office_height+132+7+2,room_length*.5-20+3>
}
union{
 object{bills rotate 1*y}
 object{bills rotate 0*y translate <1,1,-1>}
 object{bills rotate -2*y translate <0,2,1>}
 scale .9
 translate <-27,office_height+132+2,room_length*.5-20+3>
}
#end


// *** CALENDARS ***
#if (use_calendars)
#include "i_calendar.inc"
#declare t_calendar=
texture{
 pigment{
  image_map{jpeg "im_calendar.jpg"} 
  translate -.5
  scale <3.5,1.6,1>
 }
 #if (use_textures)
 finish{Glossy ambient 0}
 #end
}
object{calendario(t_normal_chrome,t_calendar)
 scale 5 rotate -20*y
 translate table3_pos+<-61,85.1,22>
 translate office_height*y
}
object{calendario(t_normal_chrome,t_calendar)
 scale 5 rotate -10*y
 translate table5_pos+<-40,85.1,23>
 translate office_height*y
}
#end


// *** PENS POT ***
#if (use_penpots)
#include "i_penpot.inc"
#declare t_bote = 
texture{
 #if (use_textures)
 T_Stone27 scale 5 
 finish{Glossy}
 #else
 pigment{White}
 #end
}
#declare t_boli3 = texture{t_bote1}
#declare t_boli2 = texture{t_bote2}
#declare t_boli1 = texture{t_normal_chrome}
object{bote_bolis(t_bote,t_boli1,t_boli2,t_boli3)
 scale 4
 translate table3_pos+<1,85.5,3>
 translate office_height*y
}
#declare t_bote = texture{pigment{rgb ReferenceRGB(Orange)} 
 #if (use_textures)
 finish{Glossy}
 #end
}
#declare t_boli3 = texture{t_pintura_verde}
#declare t_boli2 = texture{t_normal_chrome}
#declare t_boli1 = texture{t_pintura_blanca}
object{bote_bolis(t_bote,t_boli1,t_boli2,t_boli3)
 scale 4
 translate table7_pos+<10,85.5,9>
 translate office_height*y
}
#declare t_bote = 
texture{
 #if (use_textures)
 T_Stone26 
 finish{Glossy}
 #else
 pigment{White}
 #end
}
#declare t_boli3 = texture{t_pintura_marron}
#declare t_boli1 = texture{t_normal_chrome}
#declare t_boli2 = texture{t_pintura_blanca}
object{bote_bolis(t_bote,t_boli1,t_boli2,t_boli3)
 scale 4
 translate table6_pos+<13,85.5,-15>
 translate office_height*y
}
#declare t_bote = 
texture{
 #if (use_textures)
 T_Stone25 scale 5 
 finish{Glossy}
 #else
 pigment{White}
 #end
}
#declare t_boli3 = texture{t_bote1}
#declare t_boli2 = texture{t_bote2}
#declare t_boli1 = texture{t_normal_chrome}
object{bote_bolis(t_bote,t_boli1,t_boli2,t_boli3)
 scale 4
 translate table4_pos+<64,85.5,0>
 translate office_height*y
}
#end


// *** POST-IT NOTES ***
#if (use_post_it)
#declare t_post_it=
texture{
 pigment{rgb ReflectiveSpectrum(RS_PostIt_LightYellow)}
}
#declare t_post_it_note=
texture{
 material_map{
  png "im_postit"
  texture{pigment{rgb 0}}
  texture{pigment{rgb ReflectiveSpectrum(RS_PostIt_LightYellow)}}
 }
}
#include "i_post-it.inc"
#include "i_post-it_note.inc"
union{
 object{post_it_block(t_post_it) rotate 90*y scale 3.5 translate table3_pos+<8,80.3,9>}
 object{post_it_sheet(t_post_it_note) rotate 180*y scale 3.5 rotate 40*y translate table3_pos+<40,80.1,10>+<-8,9,3.1>}
 translate office_height*y
}
#end


// *** CALCULATOR ***
#if (use_calc)
#include "i_calculator.inc"
object{calculadora scale <1.5,1.5,1> rotate -13*y 
 translate table7_pos+<-23,84,-21>
 translate office_height*y
}
#end


// *** COFFE MUGS ***
#if (use_coffemugs)
#declare t_mug1=
texture{
 t_pintura_blanca 
 #if (use_textures)
 finish{Glossy}
 #end
}
#declare t_mug2=texture{pigment{rgb ReferenceRGB(Violet)} 
 #if (use_textures)
 finish{Glossy}
 #end
}
#include "i_coffemug.inc"
object{coffe_mug(t_mug1) rotate -73*y scale 3.5
 translate table3_pos+<-11,80.1,-11>
 translate office_height*y
}
object{coffe_mug(t_mug2) rotate -163*y scale 3.5
 translate table7_pos+<-12,80.1,-8>
 translate office_height*y
}
#end


// *** ASHTRAY & TOBBACO ***
#if (use_smoking)
#declare t_cenicero=
texture{pigment{rgb ReferenceRGB(Brown)} 
 #if (use_textures)
 finish{Glossy}
 #end
}
#include "i_ashtray.inc"
union{
 object{cenicero}
 object{ash translate .5*y}
 translate table3_pos+<-10,80.1,1>
 translate office_height*y
}
#include "i_cigar_box.inc"
object{cajetilla rotate 90*x rotate -15*y
 translate table3_pos+<-45,81.4,-16>
 translate office_height*y
}
#include "i_lighter.inc"
object{mechero rotate 90*x rotate 5*y
 translate table3_pos+<-46,82.6,-19>
 translate office_height*y
}
#include "i_cigar.inc"
union{
 object{cigarrillo
  rotate 76*x
  translate 1.1*y
 }
 object{cig_smoke
  scale <12,50,12>
  translate <-.4,-36.5,-1.7>
 }
 rotate 110*y
 translate table3_pos+<-10,80.1,1>
 translate office_height*y
}
#end


// *** WHEELS CHAIRS ***
#if (use_wchairs)
#include "i_chaise.inc"
union{
 object{chaise(p_chaise_tisu,42) rotate 10*y translate table1_pos+<5,0,65>}
 object{chaise(p_chaise_tisu,42) rotate 190*y translate table3_pos-<5,0,65>}
 object{chaise(p_chaise_tisu,42) rotate 0*y translate table4_pos+<5,0,65>}
 object{chaise(p_chaise_tisu,42) rotate 200*y translate table5_pos-<5,0,65>}
 object{chaise(p_chaise_tisu,42) rotate 20*y translate table6_pos+<5,0,65>}
 object{chaise(p_chaise_tisu,42) rotate 170*y translate table7_pos-<5,0,65>}
 translate office_height*y
}
#end


// *** NORMAL CHAIRS ***
#if (use_nchairs)
#include "i_chair.inc"
union{
 object{chair rotate 30*y translate table3_pos+<25,0,90>}
 object{chair rotate -40*y translate table3_pos+<-55,0,90>}
 object{chair rotate 110*y translate table4_pos+<115,0,-10>}
 object{chair rotate -92*y translate <-220,0,20>}
 object{chair rotate 170*y translate table1_pos+<-25,0,-90>}
 translate office_height*y
}
#end


// *** COMPUTERS & PERIFERICS ***
#if (use_computers)
#include "i_computer.inc"
#include "i_printer.pov"
#include "i_orange.inc"
//#include "i_bottles.inc"
union{
 object{monitor     rotate  165*y translate table1_pos+<45,80.1,-10>}
 object{keyboard    rotate  170*y translate table1_pos+<40,82.1, 19>}
 object{mouse_cable1 rotate 180*y translate table1_pos+<40,80,18>}
// object{keyb_cable5 rotate  199*y translate table1_pos+<40,81.1,19-3>}
 object{cpu         rotate  1*y translate table3_pos+<56,.1,2>}
 object{monitor     rotate  25*y translate table3_pos+<42,80.1,12>}
 object{keyboard    rotate  0*y translate table3_pos+<20,82.1,-19>}  // This is the keyboard visible in this view.
 object{keyboard    rotate  20*y scale <0.8, 0.8, 0.8> translate table3_pos+<60,82.1,-23> }  // This is the keyboard visible in this view.
 object{orange      rotate  0*y translate table3_pos+<10,83.5,-25>}  // This is the keyboard visible in this view.
 object{keyb_cable5 rotate  0*y translate table3_pos+<28,80.1,-19-5>}
 object{jvp_printer rotate  0*y translate table3_pos+<-26,80.1,24>}
 object{monitor     rotate  199*y translate table4_pos+<-45,80.1,-10>}
 object{keyboard    rotate  190*y translate table4_pos+<-15,82.1, 19>}
 object{monitor     rotate  20*y translate table5_pos+<40,80.1,10>}
 object{keyboard    rotate  10*y translate table5_pos+<20,82.1,-19>}
 object{keyb_cable5 rotate  0*y translate table5_pos+<20,80.1,-19-5>}
 object{cpu         rotate  1*y translate table5_pos+<-26,.1,2>}
 object{monitor     rotate  190*y translate table6_pos+<-40,80.1,-10>}
 object{keyboard    rotate  199*y translate table6_pos+<-30,82.1, 19>}
 object{keyb_cable5 rotate  199*y translate table6_pos+<-30,81.1,19-3>}
 object{cpu         rotate  1*y translate table6_pos+<-56,.1,-2>}
 object{monitor     rotate  25*y translate table7_pos+<40,80.1,10>}
 object{keyboard    rotate  0*y translate table7_pos+<20,82.1,-19>}
 object{keyb_cable5 rotate  0*y translate table7_pos+<20,80.1,-19-5>}
 object{cpu         rotate  1*y translate table7_pos+<54,.1,-1>}
 object{mouse        translate table7_pos+<55,80.4,-15>}
 object{mouse_cable1 translate table7_pos+<55,80,-15>}
 object{mouse_pad    translate table7_pos+<54,80,-16>}
 translate office_height*y
}
#end


/*#if (use_waterb)
#include "i_waterbottle.inc"
object{waterbottle scale 8
 #if (use_glass)
 interior{I_Glass ior 1.2}
 #end
 #if (use_photons)
 photons{
  target
  refraction on
  reflection off
  collect off
 }
 #end
translate table3_pos+<20,102.1,-19>
translate office_height*y
}

object{waterbottle scale 8
 #if (use_glass)
 interior{I_Glass ior 1.2}
 #end
 #if (use_photons)
 photons{
  target
  refraction on
  reflection off
  collect off
 }
 #end
translate table3_pos+<-70,90.1,-19>
translate office_height*y
}
#end
*/


// *** TELEPHONES ***
#if (use_phones)
#include "i_phone.pov"
#declare telefono=object{jvp_telefono translate 2*y scale 1.1}
union{
 object{telefono rotate 193*y translate table1_pos+<-55,80.9,18>}
 object{telefono rotate 190*y translate table6_pos+<35,80.9,-18>}
 object{keyb_cable5 rotate  180*y translate table6_pos+<35,80.3,-10>}
 object{telefono rotate -13*y translate table3_pos+<-57,80.9,-15>}
 object{mouse_cable1 translate table3_pos+<-57,80.3,-15>}
 object{telefono rotate 170*y translate table4_pos+<35,80.9,-18>}
 translate office_height*y
}
#end


// *** RADIOCASETTE ***
#if (use_radio)
#include "i_radio.pov"
object{jvp_combo 
 scale <.8,.8,1>
 rotate -90*y translate table5_pos+<-70,80.1,12>
 translate office_height*y
}
#end


// *** BOOKCASES WITH FILES ***
#if (use_bookcases)
#include "i_bookcase.inc"
union{
 object{armario1(seed(167),0) translate <125,0,room_length*.5-22>}
 object{armario1(seed(167),0) translate <-125,0,room_length*.5-22>}
 object{armario1(seed(167),0) rotate 180*y translate <180,0,-room_length*.5+22>}
 object{armario1(seed(167),0) rotate 180*y translate <60,0,-room_length*.5+22>}
 object{armario1(seed(167),0) rotate 180*y translate <-60,0,-room_length*.5+22>}
 object{armario1(seed(167),0) rotate 180*y translate <-180,0,-room_length*.5+22>}
 translate office_height*y
}
#end
#if (use_books)
#include "i_bookplacer_v2.inc"
#include "i_files.inc"
union{
 object{whole_book_rows1 translate <125,0,room_length*.5-22>+<-52,107,8>}
 object{whole_book_rows2 translate <-125,0,room_length*.5-22>+<-52,107,8>}
 object{files_at_table translate table7_pos+<-79,80,32>}
 object{whole_book_rows1 rotate 180*y translate <163,0,-room_length*.5+22>+<-52,107,-8>}
 object{whole_book_rows2 rotate 180*y translate <44,0,-room_length*.5+22>+<-52,107,-8>}
 object{whole_book_rows3 rotate 180*y translate <283,0,-room_length*.5+22>+<-52,107,-8>}
 object{whole_book_rows4 rotate 180*y translate <-74,0,-room_length*.5+22>+<-52,107,-8>}
 translate office_height*y
}
#end


// *** FILERS ***
#if (use_filers)
#include "i_filers.inc"
union{
 object{archivador1 translate <-24,0,room_length*.5-30>}
 object{archivador2 translate <24,0,room_length*.5-30>}
 translate office_height*y
}
#end


// *** CLOTHRACK ***
#if (use_clothrack)
#include "i_clothrack.inc"
object{perchero rotate 123*y translate <room_width*.5-20,office_height,-10>}
#end


// *** WALL CLOCK ***
#if (use_clock)
#include "i_wallclock.inc"
object{reloj rotate -90*x scale 9 translate <0,190,room_length*.5-3>
 translate office_height*y
}
#end


// *** WALL PICTURES ***
#if (use_pictures)
#include "i_frames.inc"
object{frame1 rotate -1*x scale .5
 rotate -90*y 
 translate <-room_width*.5+2,150,win_width*.5+win_sep*.5>
 translate office_height*y
}
object{frame2 rotate -1*x scale <.5,.7,.5>
 rotate -90*y 
 translate <-room_width*.5+2,150,-win_width*.5-win_sep*.5>
 translate office_height*y
}
object{frame3 rotate -1*x scale <.9,.5,.5>
 rotate 90*y 
 translate <room_width*.5-2,150,-80>
 translate office_height*y
}


object{frame4 rotate -1*x scale <.5,.7,.5>*<2.4,2.4,2>
 rotate 90*y 
 translate <room_width*.5-2,150,20>
 translate office_height*y
}


object{frame3 rotate -1*x scale <.9,.7,.5> /// This is the new picture added to the wall by me!
 rotate 90*y 
 translate <room_width*.5-2,150,-180>
 translate office_height*y
}
object{frame4 rotate -1*x scale <.5,.7,.5>*<1.2,1.2,1>
 rotate 90*y 
 translate <room_width*.5-2,140,-260>
 translate office_height*y
}
object{frame5 rotate -1*x scale .5*<1.3,1.3,1>
 rotate 90*y 
 translate <room_width*.5-2,145,290>
 translate office_height*y
}
// no-poving and no-smokig signs
#declare no_poving_sign=
box{-.5,.5
 texture{
  pigment{
   image_map{png "im_nopoving"}
   translate -.5
  }
  #if (use_radiosity=2)
  finish{diffuse .8 reflection{.05,.2}}
  #end
 }
 scale <20,20,.1>
}
#declare no_smoking_sign=
box{-.5,.5
 texture{
  pigment{
   image_map{png "im_nosmoking"}
   translate -.5
  }
  #if (use_radiosity=2)
  finish{diffuse .8 reflection{.05,.2}}
  #end
 }
 scale <20,20,.1>
}
object{no_poving_sign
 translate <0,140,-15-.01>
 translate office_height*y
}
object{no_smoking_sign
 translate <0,161,-15-.01>
 translate office_height*y
}
#end


// *** EXTERIOR ***
plane{y,-.1 hollow pigment{rgb ReferenceRGB(White)}}
plane{x,1000 hollow pigment{rgb 0}}


// *** CAMERA ***
#switch (camera_select)
 #case (0) // spherical
  #declare cl=<50,125,50>;
  #declare la=<50,125,51>;
  #declare cd=1*z;
  #break
 #case (1) // final shot
  #declare cl=<-30,168,-350>;
  #declare la=<-100,110,20>;
  #declare cd=2.8*z;
  #break
 #case (2) // other general view
  #declare cl=<230,168,-350>;
  #declare la=<-100,110,20>;
  #declare cd=2.8*z;
  #break
 #case (3) // looking to the right side
  //#declare cl=<-230,168,-350>;
  #declare cl=<0,0,-165>;
  // #declare la=<100,110,120>;
  #declare la=<0,0,10>;		
  //#declare cd=8.5*z;
  #declare cd=1.8*z; 
  #break
 #case (4) // looking to the rear bookcases
  #declare cl=<-30,168,-50>;
  #declare la=<10,110,-320>;
  #declare cd=3.5*z;
  #break
 #case (98) // exterior
  #declare cl=<230,168,-3500>;
  #declare la=<-100,110,20>;
  #declare cd=2.8*z;
  #break
 #case (99) // top view
  #declare cl=<0,900,0>;
  #declare la=<0,0,0>;
  #declare cd=2.8*z;
  #break
#end
camera{
 /*#if (camera_select=0)
  spherical
 #end
 location cl
 #if (camera_select=0)
 up y*1.8
 right x*3.6
 #else
 up y*2.4
 right x*3.6
 #end
 direction cd
 look_at la
 #if (camera_select=99)
  rotate 90*y
 #end
// translate (office_height+100)*y
 /*translate tx*x
 translate ty*y
 translate tz*z*/
/*matrix < 1.0000,    0.0017,   -0.0023,         
   -0.0016,    1.0000,    0.0051,         
    0.0023,   -0.0051,    1.0000,         
    0.0,  (office_height+100),   -0.004>*/
matrix <    val00,    val01,  val02,
   val10,   val11,    val12,
   val20,   val21,    val22,
   val30,   val31, val32>
*/

//perspective 
transform {
/*matrix <    1,    0,  0,
   0,   1,    0,
   0,   0,    1,
   val30,val31,val32>
*/
matrix <    val00,    val01,  val02,
   val10,   val11,    val12,
   val20,   val21,    val22,
   val30,   val31, val32>
}

 #if (use_blur)
 focal_point la aperture .001 blur_samples use_blur
 #end
/*location <val30, val31, val32>

direction <val20,val21,val22>

up <val10, val11, val12>*/

//right <val00, val01, val02>*1.33

}
