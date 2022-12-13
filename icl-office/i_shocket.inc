/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Wall electrical shocket

*/

#declare shocket_sp=
union{
union{
 difference{
  box{
   <-3,-7,0>
   <3,7,5>
  }
  cylinder{<0,-3.75,-2>,<0,-3.75,3>,2.5}
  box{<-.2,-2.9,-.6><.2,-2.4,2.5> translate -3.75*y}
  box{<-.2, 2.9,-.6><.2, 2.4,2.5> translate -3.75*y}
  cylinder{<-1.1,0,0>,<-1.1,0,5>,0.3 translate -3.75*y}
  cylinder{<1.1,0,0>,<1.1,0,5>,0.3 translate -3.75*y}
 }
 difference{
  superellipsoid{
   <.1,.1>
   rotate -90*x
   scale <4,7.5,.5>
  }
  cylinder{<0,-3.75,-2>,<0,-3.75,3>,2.5}
 }
 difference{
  cylinder{<0,3.75,-.7>,<0,3.75,.6>,3}
  box{
   <-1.75,-1.75,-1>
   < 1.75, 1.75, 1>
   translate 3.75*y
  }
 }
 difference{
  box{
   <-1.7,-1.7,-.75>
   < 1.7, 1.7,   1>
   translate 3.75*y
  }
  cylinder{<0,3.75,-1>,<0,3.75,.7>,0.7}
 }
 difference{
  cylinder{<0,3.75,-.7>,<0,3.75,.7>,0.65}
  box{<-.05,3.45,-1>,<.05,4.05,-.5>}
 }
 difference{
  cylinder{<0,-3.75,-.7>,<0,-3.75,.6>,3}
  cylinder{<0,-3.75,-1>,<0,-3.75,2>,2.5}
  box{<-.2,-2.9,-.6><.2,-2.4,2.5> translate -3.75*y}
  box{<-.2, 2.9,-.6><.2, 2.4,2.5> translate -3.75*y}
  cylinder{<-1.1,0,0>,<-1.1,0,5>,0.3 translate -3.75*y}
  cylinder{<1.1,0,0>,<1.1,0,5>,0.3 translate -3.75*y}
 }
 box{<-2.8,-1,-.5><-2.2,-.25,1> translate -3.7*y}
 box{<-2.8,.25,-.5><-2.2,1,1> translate -3.7*y}
 box{< 2.8,-1,-.5>< 2.2,-.25,1> translate -3.7*y}
 box{< 2.8,.25,-.5>< 2.2,1,1> translate -3.7*y}
 torus{3.1,.1 rotate -90*x translate <0,3.75,-.6>}
 torus{3.1,.1 rotate -90*x translate <0,-3.75,-.6>}
 texture{t_pintura_blanca finish{Glossy}}
}
union{
 union{
  box{
   <-.17,0,-.2>
   < .17,-.05,3>
  }
  difference{
   cylinder{<-.17,-.2,0>,<.17,-.2,0>,.2}
   cylinder{<-.17,-.2,0>,<.17,-.2,0>,.15}
  }
  rotate 10*x
  translate -2.2*y
 }
 union{
  box{
   <-.17,0,-.2>
   < .17,.05,3>
  }
  difference{
   cylinder{<-.17,.2,0>,<.17,.2,0>,.2}
   cylinder{<-.17,.2,0>,<.17,.2,0>,.15}
  }
  rotate -10*x
  translate 2.2*y
 }
 difference{
  cylinder{<0,0,0>,<0,0,1>,0.2}
  box{<-.05,-.15,-.1>,<.05,.15,.1>}
  translate <0,-1.5,2.89>
 }
 difference{
  cylinder{<0,0,0>,<0,0,1>,0.2}
  box{<-.05,-.15,-.1>,<.05,.15,.1>}
  translate <0,1.5,2.89>
 }
 difference{
  union{
   cylinder{<-1.1,0,3>,<-1.1,0,5>,0.29 translate -3.75*y}
   cylinder{<1.1,0,3>,<1.1,0,5>,0.29 translate -3.75*y}
  }
  union{
   cylinder{<-1.1,0,3>,<-1.1,0,5>,0.28 translate -3.75*y}
   cylinder{<1.1,0,3>,<1.1,0,5>,0.28 translate -3.75*y}
  }
 }
 translate -3.75*y
 texture{t_normal_chrome}
}
}


