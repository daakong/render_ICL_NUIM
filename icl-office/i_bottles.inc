/*

  The Kitchen - Jaime Vives Piqueres 2004-2005

  Entry for the POVCOMP 2004

  i_bottles.inc : some old bottles created with meshlat.inc

*/

// --- lathe points (a bottle) ---
#declare a_rbott=array[32]
#declare a_rbott[0]=<0,0,0>;
#declare a_rbott[1]=<0,1.2,0>;
#declare a_rbott[2]=<.3,1.2,0>;
#declare a_rbott[3]=<1,1,0>;
#declare a_rbott[4]=<2,.5,0>;
#declare a_rbott[5]=<3,0,0>;
#declare a_rbott[6]=<4,.4,0>;
#declare a_rbott[7]=<4,6,0>;
#declare a_rbott[8]=<4,12,0>;
#declare a_rbott[9]=<4,17,0>;
#declare a_rbott[10]=<2,20,0>;
#declare a_rbott[11]=<1.9,21,0>;
#declare a_rbott[12]=<1.5,22,0>;
#declare a_rbott[13]=<1.3,26,0>;
#declare a_rbott[14]=<1.42,26.1,0>;
#declare a_rbott[15]=<1.4,28,0>;
#declare a_rbott[16]=<1.2,28,0>;
#declare a_rbott[17]=<1.2,26.1,0>;
#declare a_rbott[18]=<1.1,26,0>;
#declare a_rbott[19]=<1.3,22,0>;
#declare a_rbott[20]=<1.7,21,0>;
#declare a_rbott[21]=<1.8,20,0>;
#declare a_rbott[22]=<3.7,16,0>;
#declare a_rbott[23]=<3.7,12,0>;
#declare a_rbott[24]=<3.8,6,0>;
#declare a_rbott[25]=<3.8,.8,0>;
#declare a_rbott[26]=<3,.4,0>;
#declare a_rbott[27]=<2,.9,0>;
#declare a_rbott[28]=<1,1.4,0>;
#declare a_rbott[29]=<0.3,1.6,0>;
#declare a_rbott[30]=<0,1.6,0>;
#declare a_rbott[31]=<0,1.6,0>;

// --- bottle textures ---
#if (use_glass<1)
#declare m_bottle1=
material{
 texture{
  pigment{DarkGreen}
 }
}
#declare m_bottle2=
material{
 texture{
  pigment{White}
 }
}
#else
#declare m_bottle1=
material{
 texture{
  T_Glass3
  pigment{DarkGreen filter .999}
  finish{ambient 0}
 }
 interior{I_Glass}
}
#declare m_bottle2=
material{
 texture{
  T_Glass3
  finish{ambient 0}
 }
 interior{I_Glass}
}
#end

#declare cork_tap=
cone{<0,0,0>,1.15,<0,4,0>,1.2
 texture{Cork finish{ambient 0}}
}

// --- here is the call ---
#declare bottle=
 // params: lathe array, horiz. resolution, vert. sections
 object{meshlathe(a_rbott,.3,12)
 }
#declare bottle1=
union{
 object{bottle scale 1.1 material{m_bottle1}}
 object{cork_tap translate 29.5*y}
}
#declare bottle2=
union{
 object{bottle scale 1.1 material{m_bottle2}}
 object{cork_tap translate 29*y}
}

