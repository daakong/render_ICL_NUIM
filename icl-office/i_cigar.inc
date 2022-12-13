/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Cigarretes

*/

// cigarrete texture
#declare t_cigarrillo=
texture{
 pigment{
  image_map {png "im_cigar" interpolate 2 }
  translate <-0.5,-0.5,0>
  scale <0.8,8.55,1>
  translate <0,8.5/2,0>
 }
}

// cigarrete
#declare cigarrillo=
union{
 cylinder{
  <0,0,0>
  <0,8.5,0>
  0.4
  texture {t_cigarrillo}
 }
 sphere{
  <0,0,0>,1
  texture{
   pigment { color rgbf<1, 1, 1, 1> }
   finish { ambient 0 diffuse 0 }
  }
  interior{
   media {
    emission 4
    density{
     cylindrical
     turbulence .7
     color_map{
      [0.0 rgb <0,0,0>]
      [0.5 Red]
      [0.5 Orange]
      [1.0 rgb <0,0,0>]
     }
     frequency 4
    }
   }
  }
  hollow 
  scale <0.5,0.25,.5>
  translate 0.3*y
 }
}

// smoke column
#declare cig_smoke=
cylinder{
  <0,0,0>, <0,2,0>,.2
  pigment { color rgbf<1, 1, 1, 1> }
  finish { ambient 0 diffuse 0 }
   interior{
     media {
      emission 0.4
      intervals 30 samples 1, 30
      confidence 0.9999
      variance 1/1000
      density {
        function{1.0-min(1, sqrt(pow(x,2) + pow(z,2))*y)}
        turbulence .3
        color_map {
          [0.000 Black]
          [0.980 Black]
          [0.991 White]
          [0.995 SteelBlue]
          [0.996 Black]
          [0.997 White]
          [1.000 White]
        }
      }
     }
    }
  hollow
}

// cigarrette butts for the ashtray
#declare t_cigar1=
texture{
 pigment{
  image_map {png "im_ciga1" interpolate 2 }
  translate -0.5
  rotate 180*z
  scale <0.8,3.05,1>
  translate <0,3/2,0>
 }
}
#declare t_cigar2=
texture{
 pigment{
  image_map {png "im_ciga2" interpolate 2 }
  translate <-0.5,-0.5,0>
  scale <0.8,1.55,1>
  translate <0,1.5/2,0>
 }
}
#declare t_cigar3=
texture{
 pigment{
  image_map {png "im_ciga3" interpolate 2 }
  translate <-0.5,-0.5,0>
  rotate 180*z
  scale <0.8,1.05,1>
  translate <0,1/2,0>
 }
}

#declare cig_butt_1=
union{
 cylinder{
  <0,0,0>
  <0,3,0>
  0.4
  texture {t_cigar1}
 }
 cylinder{
  <0,0,0>
  <0,1.5,0>
  0.4
  texture {t_cigar2}
  rotate <15,4,0>
  translate <0,2.9,0>
 }
 cylinder{
  <0,0,0>
  <0,1,0>
  0.4
  texture {t_cigar3}
  rotate <24,35,0>
  translate <0,(3+1.4),.4> 
 }
}


