/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Wall framed pictures

*/

// images
#declare p_frame1=
pigment{
     image_map{jpeg "im_pic1"}
     translate -.5 
     scale <138,88,1>
}
#declare p_frame2=
pigment{
    image_map{jpeg "im_pic2"}
    translate -.5
    scale <88,88,1>
}
#declare p_frame3=
pigment{
    image_map{jpeg "im_pic3"}
    translate -.5
    scale <88,88,1>
}
#declare p_frame4=
pigment{
    image_map{jpeg "im_pic4"}
    translate -.5
    scale <88,88,1>
}
#declare p_frame5=
pigment{
    image_map{jpeg "im_pic5"}
    translate -.5
    scale <88,88,1>
}

// framed pictures
#declare frame1=
union{
 difference{
  box{-.5,.5 scale <150,100,1>}
  box{-.5,.5 scale <148,98,1.1>}
  texture{t_black_plastic}
 }
 box{-.5,.5 scale <148,98,.1>
  texture{t_white_paper}
 }
 box{-.5,.5 scale <138,88,.11>
  texture{CIE_Imagemap(p_frame1)}
 }
 #if (use_glass)
 box{-.5,.5 scale <148,98,.1>
  texture{pigment{White filter 0.99} finish{Glass_Finish}}
  translate .15*z
 }
 #end
 scale <.9,.9,1>
}
#declare frame2=
union{
 difference{
  box{-.5,.5 scale <100,100,1>}
  box{-.5,.5 scale <98,98,1.1>}
  texture{t_black_plastic}
 }
 box{-.5,.5 scale <98,98,.1>
  texture{t_white_paper}
 }
 box{-.5,.5 scale <88,88,.11>
  texture{CIE_Imagemap(p_frame2)}
 }
 #if (use_glass)
 box{-.5,.5 scale <98,98,.1>
  texture{pigment{White filter 0.99} finish{Glass_Finish}}
  translate .15*z
 }
 #end
 scale <.9,.9,1>
 scale <.9,.9,1>
}
#declare frame3=
union{
 difference{
  box{-.5,.5 scale <100,100,1>}
  box{-.5,.5 scale <98,98,1.1>}
  texture{t_black_plastic}
 }
 box{-.5,.5 scale <98,98,.1>
  texture{t_white_paper}
 }
 box{-.5,.5 scale <88,88,.11>
  texture{CIE_Imagemap(p_frame3)}
 }
 #if (use_glass)
 box{-.5,.5 scale <98,98,.1>
  texture{pigment{White filter 0.99} finish{Glass_Finish}}
  translate .15*z
 }
 #end
 scale <.9,.9,1>
 scale <.9,.9,1>
}
#declare frame4=
union{
 difference{
  box{-.5,.5 scale <100,100,1>}
  box{-.5,.5 scale <98,98,1.1>}
  texture{t_black_plastic}
 }
 box{-.5,.5 scale <98,98,.1>
  texture{t_white_paper}
 }
 box{-.5,.5 scale <88,88,.11>
  texture{CIE_Imagemap(p_frame4)}
 }
 #if (use_glass)
 box{-.5,.5 scale <98,98,.1>
  texture{pigment{White filter 0.99} finish{Glass_Finish}}
  translate .15*z
 }
 #end
 scale <.9,.9,1>
 scale <.9,.9,1>
}
#declare frame5=
union{
 difference{
  box{-.5,.5 scale <100,100,1>}
  box{-.5,.5 scale <98,98,1.1>}
  texture{t_black_plastic}
 }
 box{-.5,.5 scale <98,98,.1>
  texture{t_white_paper}
 }
 box{-.5,.5 scale <88,88,.11>
  texture{CIE_Imagemap(p_frame5)}
 }
 #if (use_glass)
 box{-.5,.5 scale <98,98,.1>
  texture{pigment{White filter 0.99} finish{Glass_Finish}}
  translate .15*z
 }
 #end
 scale <.9,.9,1>
 scale <.9,.9,1>
}
