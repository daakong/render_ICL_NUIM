/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Wrinkled paper ball

*/

#macro wrinkled_paper(rseed,sc)
#local rp=rseed;
#local nb=128;
#local cnt=1;
difference{
 sphere{0,1}
 #while (cnt<=nb)
  box{-.5,.5
   rotate 360*rand(rp)*y
   rotate 360*rand(rp)*x
   rotate 360*rand(rp)*z
   scale .25+.5*rand(rp)
   translate -1.1*z
   rotate 360*rand(rp)*y
   rotate 360*rand(rp)*x
  }
  #local cnt=cnt+1;
 #end
 texture{
  pigment{White}
  scale 1
  translate 1000*rand(rp)
 }
 scale sc*3
 rotate rand(rp)*360
}
#end
