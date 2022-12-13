/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Office building construction

*/

// measures
#declare win_sep=(room_length-win_width*3)/4;
#declare wall_win=room_height-win_height; 

// ceil tiles
#declare ceil_tile=
union{
 #if (use_radiosity=1)
 box{-.5,.5
/* height_field{
  function 150,150{f_granite(x*4,y,z*4)*.25}
  translate -.5 rotate 180*x*/
 #else
 box{-.5,.5
 #end
  scale <49,1,49>
  texture{t_pintura_blanca}
 }
 difference{
  box{-.5,.5}
  box{-.5,.5 scale <.95,1.01,.95>}
  scale <50,1.2,50>
  texture{t_pintura_metalizada}
 }
 translate .5*y
}
#declare ceil_tile_row1=
union{
 object{ceil_tile translate -225*x}
 object{ceil_tile translate  225*x}
 object{ceil_tile rotate 90*y translate -175*x}
 object{ceil_tile rotate 90*y translate  175*x}
 object{ceil_tile rotate 180*y translate -125*x}
 object{ceil_tile rotate 180*y translate  125*x}
 object{ceil_tile rotate 270*y translate  -75*x}
 object{ceil_tile rotate 270*y translate   75*x}
 object{ceil_tile translate  -25*x}
 object{ceil_tile translate   25*x}
}
#declare ceil_tile_row2=
union{
 object{ceil_tile translate -225*x}
 object{ceil_tile translate  225*x}
 object{ceil_tile translate -175*x}
 object{ceil_tile translate  175*x}
 object{ceil_tile translate  -25*x}
 object{ceil_tile translate   25*x}
}
#declare ceil_tile_row3=
union{
 object{ceil_tile translate -225*x}
 object{ceil_tile translate  225*x}
 object{ceil_tile rotate 90*y translate -175*x}
 object{ceil_tile rotate 90*y translate  175*x}
 object{ceil_tile rotate 270*y translate  -75*x}
 object{ceil_tile rotate 270*y translate   75*x}
 object{ceil_tile translate  -25*x}
 object{ceil_tile translate   25*x}
}

// floor tiles
#declare r_floor=seed(6237);
#declare nff=0;
#declare nfr=0;
#declare ift=0;
#declare nft=10*16;
#declare tiles_floor=
union{
 #while (ift<nft)
  box{-.5,.5 
   scale <49.99,1,49.99>
   #if (mod(ift+nff,2)=0)
    texture{t_suelo1 translate 1000*rand(r_floor)}
   #else
    texture{t_suelo2 translate 1000*rand(r_floor)}
   #end
   rotate (-.5+rand(r_floor))*x
   rotate (-.5+rand(r_floor))*z
   translate <25,-.5,25>
   translate <50*nff,0,50*nfr>
  }
  #declare ift=ift+1;
  #declare nfr=nfr+1;
  #if (nfr>15)
   #declare nfr=0;
   #declare nff=nff+1;
  #end
 #end
}

// office room
#declare office_room=
union{
 // floor
 object{tiles_floor
  translate <-room_width*.5,-room_height*.5,-room_length*.5>
 }
 box{-.5,.5 
  scale <room_width*1.1,.1,room_length*1.1> 
  pigment{rgb ReferenceRGB(Gray10)}
  translate -room_height*.5*y
  translate -.9*y
 }
 // ceil
 #if (camera_select<99)    
 box{-.5,.5
  scale <room_width,.1,room_length>
  texture{t_pintura_blanca}
  translate room_height*.5*y
 }
 union{
  object{ceil_tile_row1 translate  375*z}
  object{ceil_tile_row1 translate  325*z}
  object{ceil_tile_row2 translate  275*z}
  object{ceil_tile_row1 translate  225*z}
  object{ceil_tile_row1 translate  175*z}
  object{ceil_tile_row3 translate  125*z}
  object{ceil_tile_row3 translate   75*z}
  object{ceil_tile_row1 translate   25*z}
  object{ceil_tile_row1 translate -375*z}
  object{ceil_tile_row1 translate -325*z}
  object{ceil_tile_row2 translate -275*z}
  object{ceil_tile_row1 translate -225*z}
  object{ceil_tile_row1 translate -175*z}
  object{ceil_tile_row3 translate -125*z}
  object{ceil_tile_row3 translate  -75*z}
  object{ceil_tile_row1 translate  -25*z}
  translate (room_height*.5-10)*y
 }
 #end
 // walls
 union{
 box{-.5,.5
  scale <room_width,room_height,wall_width>
  translate (room_length*.5+wall_width*.5)*z
 }
 box{-.5,.5
  scale <room_width,room_height,wall_width>
  translate (room_length*.5+wall_width*.5)*z
  translate room_width*x
 }
 box{-.5,.5
  scale <room_width,room_height,wall_width>
  translate -(room_length*.5+wall_width*.5)*z
 }
 //difference{
  box{-.5,.5 scale <wall_width,room_height,room_length> //}
 // box{-.5,.5 scale <wall_width*1.01,room_height*3/4,win_width> 
 //  translate <0,-room_height*.5+(room_height*3/4)*.5,room_length*.5-150-win_width>
  //}
  translate (room_width*.5+wall_width*.5)*x
 }
 
 union{
  box{-.5,.5 scale <wall_width,room_height,win_sep> 
   translate (-room_length*.5+win_sep*.5)*z
  }
  box{-.5,.5 scale <wall_width,room_height,win_sep> 
   translate (room_length*.5-win_sep*.5)*z
  }
  box{-.5,.5 scale <wall_width,room_height,win_sep> 
   translate (-win_width*.5-win_sep*.5)*z
  }
  box{-.5,.5 scale <wall_width,room_height,win_sep> 
   translate (win_width*.5+win_sep*.5)*z
  }
  union{
   box{-.5,.5 scale <wall_width,wall_win*2/3,win_width> 
    translate (-room_height*.5+(wall_win*2/3)*.5)*y
   }
   box{-.5,.5 scale <wall_width,wall_win/3,win_width> 
    translate (room_height*.5-(wall_win/3)*.5)*y
   }
  }
  union{
   box{-.5,.5 scale <wall_width,wall_win*2/3,win_width> 
    translate (-room_height*.5+(wall_win*2/3)*.5)*y
   }
   box{-.5,.5 scale <wall_width,wall_win/3,win_width> 
    translate (room_height*.5-(wall_win/3)*.5)*y
   }
   translate (-room_length*.5+win_sep+win_width*.5)*z
  }
  union{
   box{-.5,.5 scale <wall_width,wall_win*2/3,win_width> 
    translate (-room_height*.5+(wall_win*2/3)*.5)*y
   }
   box{-.5,.5 scale <wall_width,wall_win/3,win_width> 
    translate (room_height*.5-(wall_win/3)*.5)*y
   }
   translate (room_length*.5-win_sep-win_width*.5)*z
  }
  translate -(room_width*.5+wall_width*.5)*x 
 }
 box{-.5,.5
  scale <30,room_height,30>
 }
 texture{t_pintura_pared}
 }
 translate room_height*.5*y
}

// rodapies
#declare t_rp_wood=texture{T_Wood8}
#declare rodapies=
union{
 /*difference{
  box{-.5,.5 scale <1,6,room_length> texture{t_rp_wood} }
  box{-.5,.5 scale <1.1,7,win_width-1> 
   translate <0,0,room_length*.5-150-win_width>
  }
  translate <room_width*.5-.5,3,0>
 }*/
 box{-.5,.5 scale <4,6,1> texture{t_rp_wood rotate 90*y} translate <room_width*.5+1,3,room_length*.5-150-win_width*.5-.5>}
 box{-.5,.5 scale <4,6,1> texture{t_rp_wood rotate 90*y} translate <room_width*.5+1,3,room_length*.5-150-win_width*.5-win_width+.5>}
 box{-.5,.5 scale <1,6,room_length> texture{t_rp_wood} translate <-room_width*.5+.5,3,0>}
 box{-.5,.5 scale <room_width,6,1> texture{t_rp_wood rotate 90*y} translate <0,3,room_length*.5-.5>}
 box{-.5,.5 scale <room_width,6,1> texture{t_rp_wood rotate 90*y} translate <0,3,-room_length*.5+.5>}
 cylinder{<0,0,-.5>,<0,0,.5>,1 scale <2,.2,win_width> texture{t_aluminum} translate <room_width*.5,0,room_length*.5-150-win_width>}
}
