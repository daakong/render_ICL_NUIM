/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Papers

*/

#declare newspaper_sheet=
union{
 box{-.5,.5 scale .4*y translate .25*y}
 box{-.5,.5 scale .4*y translate -.25*y}
}
#declare povmag=
union{
 object{newspaper_sheet
  texture{pigment{image_map{jpeg "im_periodico.jpg"} translate -.5 rotate 90*x}}
  scale <21,1,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.8,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.6,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.4,30>
 }
}
#declare pile_of_paper=
union{
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,1,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.8,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.6,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.4,30>
 }
}
#declare bills=
union{
 object{newspaper_sheet
  texture{
   pigment{image_map{jpeg "im_fra.jpg"} translate -.5 rotate 90*x}
   normal{wrinkles scale .2}
  }
  scale <21,1,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.8,32>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <20,.6,30>
 }
 object{newspaper_sheet
  texture{t_white_paper}
  scale <21,.4,30>*.9
 }
}

