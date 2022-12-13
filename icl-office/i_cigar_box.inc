/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Cigarretes box

*/

// *** medidas ***
#declare alto_caja=8.2;
#declare anch_caja=5;
#declare hond_caja=2.35;
#declare alt_corte=6.3;
#declare grosor=.002;

// *** texturas ***

#declare t_carton=
texture{
 pigment{White}
 finish{Dull}
}

#declare t_front=
texture{
 pigment{image_map{png "maps/lucky2/im_front"}}
 finish{Phong_Dull}
 translate -.5
 scale <anch_caja,alto_caja,1>
}
#declare t_tras=
texture{
 pigment{image_map{png "maps/lucky2/im_tras"}}
 finish{Phong_Dull}
 translate -.5
 scale <anch_caja,alto_caja,1>
}
#declare t_ladoi=
texture{
 pigment{image_map{png "maps/lucky2/im_ladoi"}}
 finish{Phong_Dull}
 translate -.5
 scale <hond_caja,alto_caja,1>
}
#declare t_ladod=
texture{
 pigment{image_map{png "maps/lucky2/im_ladod"}}
 finish{Phong_Dull}
 translate -.5
 scale <hond_caja,alto_caja,1>
}
#declare t_arrib=
texture{
 pigment{image_map{png "maps/lucky2/im_arrib"}}
 finish{Phong_Dull}
 translate -.5
 scale <anch_caja,hond_caja,1>
}
#declare t_abajo=
texture{
 pigment{image_map{png "maps/lucky2/im_abajo"}}
 finish{Phong_Dull}
 translate -.5
 scale <anch_caja,hond_caja,1>
}



// *** componentes ***

#declare c_frontal=
box{
 <-anch_caja*.5,-alto_caja*.5,-grosor>
 < anch_caja*.5, alto_caja*.5, grosor>
 texture{t_front}
}
#declare c_trasero=
box{
 <-anch_caja*.5,-alto_caja*.5,-grosor>
 < anch_caja*.5, alto_caja*.5, grosor>
 texture{t_tras}
}          
#declare c_lado_izq=
box{
 <-hond_caja*.5,-alto_caja*.5,-grosor>
 < hond_caja*.5, alto_caja*.5, grosor>
 texture{t_ladoi}
}
#declare c_lado_der=
box{
 <-hond_caja*.5,-alto_caja*.5,-grosor>
 < hond_caja*.5, alto_caja*.5, grosor>
 texture{t_ladod}
}
#declare c_abajo=
box{
 <-anch_caja*.5,-hond_caja*.5,-grosor>
 < anch_caja*.5, hond_caja*.5, grosor>
 texture{t_abajo}
}
#declare c_arriba=
box{
 <-anch_caja*.5,-hond_caja*.5,-grosor>
 < anch_caja*.5, hond_caja*.5, grosor>
 texture{t_arrib}
}                 
#declare c_plastico=
box{
 <-anch_caja*.51,-alto_caja*.51,-hond_caja*.51>
 < anch_caja*.51, alto_caja*.20, hond_caja*.51>
 texture{Glass2 normal{dents turbulence .2 scale 2} finish{ior 1.1}}
}
#declare caja_base=
union{
 object{c_frontal translate (-hond_caja*.5)*z}
 object{c_trasero translate ( hond_caja*.5)*z}
 object{c_lado_izq rotate  90*y translate (-anch_caja*.5)*x}
 object{c_lado_der rotate -90*y translate ( anch_caja*.5)*x}
 object{c_abajo  rotate -90*x translate -alto_caja*.5*y}
 object{c_arriba rotate  90*x translate  alto_caja*.5*y}
 object{c_plastico}
}


// *** composicion del objeto ***

#declare cajetilla=
object{caja_base}
