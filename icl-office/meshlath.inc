/*

  Lathe-2-mesh macros. Jaime Vives, no(C)1998.

  Thanks to Jerry Anning for his good explanation about the process (see it at
  bottom of this file!). My poor implementation here does not make justice to
  his great advices. The maths involved on this exceeds my skills, but finally
  worked. I really don't know well how it works, so I don't know if it's well
  implemented, but anyhow, results are decent and quite fast to trace.

*/

// catmull-rom matrix for cubic interpolation
#declare a_cr=array[4][4]
#declare a_cr[0][0]=-.5;
#declare a_cr[0][1]=1.5;
#declare a_cr[0][2]=-1.5;
#declare a_cr[0][3]=0.5;
#declare a_cr[1][0]=1.0;
#declare a_cr[1][1]=-2.5;
#declare a_cr[1][2]=2.0;
#declare a_cr[1][3]=-.5;
#declare a_cr[2][0]=-.5;
#declare a_cr[2][1]=0;
#declare a_cr[2][2]=.5;
#declare a_cr[2][3]=0;
#declare a_cr[3][0]=0;
#declare a_cr[3][1]=1;
#declare a_cr[3][2]=0;
#declare a_cr[3][3]=0;

// horner's rule
#macro Horner(T,row,hpoint)

 #local result=
  (T* (T* (T*a_cr[0][row]+a_cr[1][row]) +a_cr[2][row]) +a_cr[3][row]) *hpoint;

 (result)

#end

// cubic interpolation
#macro Cubic_Interpolation(T,ttt)

 #local result=
  Horner(T, 0, a_lathe[ttt-1]) +
  Horner(T, 1, a_lathe[ttt]  ) +
  Horner(T, 2, a_lathe[ttt+1]) +
  Horner(T, 3, a_lathe[ttt+2]);

 (result)

#end
     
// normal calculation
#macro get_normal(X,A,B,C,D,E,F,G,H)     
            
 #local gn=vcross(X - B, X - A) + vcross(X - A, X - D) + vcross(X - D, X - G) + 
          vcross(X - G, X - H) + vcross(X - H, X - E) + vcross(X - E, X - B);
           
 #if ((gn.x=0)&(gn.y=0)&(gn.z=0))
 <0,0,0>
 #else
 vnormalize(gn)
 #end
 
#end

// lathe to mesh conversion 
#macro meshlathe(a_lathe,inc,num_seccs)

 // evaluate final lathe size
 #declare i=0;
 #declare ttt=1;
 #while (ttt<dimension_size(a_lathe,1)-2)
  #declare T=0;
  #while (T<1)
   #declare T=T+inc;
   #declare i=i+1;
  #end
  #declare ttt=ttt+1;
 #end
 #declare num_points=i;

 // generate it now
 #declare a_lshape=array[num_points]
 #declare i=0;
 #declare ttt=1;
 #while (ttt<dimension_size(a_lathe,1)-2)
  #declare T=0;
  #while (T<1)
   #declare a_lshape[i]=Cubic_Interpolation(T,ttt);
   #declare T=T+inc;
   #declare i=i+1;
  #end
  #declare ttt=ttt+1;
 #end

 // create the mesh points rotating the lathe
 #declare n=0;
 #declare a_pmesh=array[num_points*num_seccs]
 #declare cnt_seccs=0;
 #while (cnt_seccs<num_seccs)
  #declare cnt_points=0;
  #while (cnt_points<num_points)
   #declare a_pmesh[n]=
    vaxis_rotate(a_lshape[cnt_points],<0,1,0>,360*(cnt_seccs-1)/num_seccs);
   #declare cnt_points=cnt_points+1;
   #declare n=n+1;
  #end
  #declare cnt_seccs=cnt_seccs+1;
 #end

 // create and return the triangle mesh
 #declare cnt_seccs=0;
 mesh{
  // for each vertical section
  #while (cnt_seccs<num_seccs)
   // special case control (joints)
   #switch (cnt_seccs)
    #case (0)
      #declare cnt_scant=num_seccs-1;     // anterior
      #declare cnt_scpst=1;               // posterior
      #declare cnt_scps2=2;               // posterior 2
      #break
    #case (num_seccs-1)
      #declare cnt_scant=num_seccs-2;
      #declare cnt_scpst=0;
      #declare cnt_scps2=1;
      #break
    #case (num_seccs-2)
      #declare cnt_scant=num_seccs-3;
      #declare cnt_scpst=num_seccs-1;
      #declare cnt_scps2=0;
      #break
    #else // normal case
      #declare cnt_scant=cnt_seccs-1;
      #declare cnt_scpst=cnt_seccs+1;
      #declare cnt_scps2=cnt_seccs+2;
      #break
   #end
   #debug str(cnt_seccs,5,0)
   // for each vertical point
   #declare cnt_points=0;
   #while (cnt_points<num_points)
    // special cases
    #switch (cnt_points)
     #case (0)
       #declare cnt_pant=0;
       #declare cnt_ppst=1;
       #declare cnt_pps2=2;
       #break
     #case (num_points-1)
       #declare cnt_pant=num_points-2;
       #declare cnt_ppst=num_points-1;
       #declare cnt_pps2=num_points-1;
       #break
     #case (num_points-2)
       #declare cnt_pant=num_points-3;
       #declare cnt_ppst=num_points-1;
       #declare cnt_pps2=num_points-2;
       #break
     #else  // normal case
       #declare cnt_pant=cnt_points-1;
       #declare cnt_ppst=cnt_points+1;
       #declare cnt_pps2=cnt_points+2;
       #break
    #end
    // finally, make the smothed triangles, using get_normal
    smooth_triangle{
      a_pmesh[cnt_seccs*num_points+cnt_points],
       get_normal(
                  a_pmesh[cnt_seccs*num_points+cnt_points], // X
                  a_pmesh[cnt_scant*num_points+cnt_ppst],   // A
                  a_pmesh[cnt_seccs*num_points+cnt_ppst],   // B
                  a_pmesh[cnt_scpst*num_points+cnt_ppst],   // C
                  a_pmesh[cnt_scant*num_points+cnt_points], // D
                  a_pmesh[cnt_scpst*num_points+cnt_points], // E
                  a_pmesh[cnt_scant*num_points+cnt_pant],   // F
                  a_pmesh[cnt_seccs*num_points+cnt_pant],   // G
                  a_pmesh[cnt_scpst*num_points+cnt_pant]    // H
                 )
      a_pmesh[cnt_scpst*num_points+cnt_points],
       get_normal(
                  a_pmesh[cnt_scpst*num_points+cnt_points],
                  a_pmesh[cnt_seccs*num_points+cnt_ppst],
                  a_pmesh[cnt_scpst*num_points+cnt_ppst],
                  a_pmesh[cnt_scps2*num_points+cnt_ppst],
                  a_pmesh[cnt_seccs*num_points+cnt_points],
                  a_pmesh[cnt_scps2*num_points+cnt_points],
                  a_pmesh[cnt_seccs*num_points+cnt_pant],
                  a_pmesh[cnt_scpst*num_points+cnt_pant],
                  a_pmesh[cnt_scps2*num_points+cnt_pant]
                 )
      a_pmesh[cnt_seccs*num_points+cnt_ppst],
       get_normal(
                  a_pmesh[cnt_seccs*num_points+cnt_ppst],
                  a_pmesh[cnt_scant*num_points+cnt_pps2],
                  a_pmesh[cnt_seccs*num_points+cnt_pps2],
                  a_pmesh[cnt_scpst*num_points+cnt_pps2],
                  a_pmesh[cnt_scant*num_points+cnt_ppst],
                  a_pmesh[cnt_scpst*num_points+cnt_ppst],
                  a_pmesh[cnt_scant*num_points+cnt_points],
                  a_pmesh[cnt_seccs*num_points+cnt_points],
                  a_pmesh[cnt_scpst*num_points+cnt_points]
                 )
    }
    smooth_triangle{
      a_pmesh[cnt_scpst*num_points+cnt_points],
       get_normal(
                  a_pmesh[cnt_scpst*num_points+cnt_points],
                  a_pmesh[cnt_seccs*num_points+cnt_ppst],
                  a_pmesh[cnt_scpst*num_points+cnt_ppst],
                  a_pmesh[cnt_scps2*num_points+cnt_ppst],
                  a_pmesh[cnt_seccs*num_points+cnt_points],
                  a_pmesh[cnt_scps2*num_points+cnt_points],
                  a_pmesh[cnt_seccs*num_points+cnt_pant],
                  a_pmesh[cnt_scpst*num_points+cnt_pant],
                  a_pmesh[cnt_scps2*num_points+cnt_pant]
                 )
      a_pmesh[cnt_seccs*num_points+cnt_ppst],
       get_normal(
                  a_pmesh[cnt_seccs*num_points+cnt_ppst],
                  a_pmesh[cnt_scant*num_points+cnt_pps2],
                  a_pmesh[cnt_seccs*num_points+cnt_pps2],
                  a_pmesh[cnt_scpst*num_points+cnt_pps2],
                  a_pmesh[cnt_scant*num_points+cnt_ppst],
                  a_pmesh[cnt_scpst*num_points+cnt_ppst],
                  a_pmesh[cnt_scant*num_points+cnt_points],
                  a_pmesh[cnt_seccs*num_points+cnt_points],
                  a_pmesh[cnt_scpst*num_points+cnt_points]
                 )
      a_pmesh[cnt_scpst*num_points+cnt_ppst],
       get_normal(
                  a_pmesh[cnt_scpst*num_points+cnt_ppst],
                  a_pmesh[cnt_seccs*num_points+cnt_pps2],
                  a_pmesh[cnt_scpst*num_points+cnt_pps2],
                  a_pmesh[cnt_scps2*num_points+cnt_pps2],
                  a_pmesh[cnt_seccs*num_points+cnt_ppst],
                  a_pmesh[cnt_scps2*num_points+cnt_ppst],
                  a_pmesh[cnt_seccs*num_points+cnt_points],
                  a_pmesh[cnt_scpst*num_points+cnt_points],
                  a_pmesh[cnt_scps2*num_points+cnt_points]
                 )
    }
    #declare cnt_points=cnt_points+1;
   #end
   #declare cnt_seccs=cnt_seccs+1;
  #end
 }

#end

/*

  And here goes Jerry great explanation:

-------------------------------------------------------------------------------

  From : Jerry Anning <clem@dhol.com>
  To   : jaime@ctav.es
  Subj.: Re: Lathe problem

  Here is a quick explanation of how I would go about turning a lathe into
  a mesh.  This should give you enough to get started.  If it is more than
  you need, I apologize.  For theory, check Foley and van Dam.

  To generate your starting points, you need to explicitly do the
  Catmull-Rom spline calculations that the lathe implicitly does.  First
  set up an array containing the control points from your lathe object.
  Then set up an array as the Catmull-Rom basis matrix.  This array is as
  follows:

  -0.5, 1.5, -1.5, 0.5
  1.0, -2.5, 2.0, -0.5
  -0.5, 0.0, 0.5, 0.0
  0.0, 1.0, 0.0, 0.0

  (You can use any uniform cubic spline basis you like with minimal
  changes to the code, but the shape you get will vary.)  Next, set up
  macros to carry out the spline calculation.  I use a simple macro to do
  the basic multiplications with Horner's Rule:
  (Param *(Param * (Param * Basis[0][Row] + Basis[1][Row]) +
  Basis[2][Row]) + Basis[3][Row]) * Point

  Then I set up another simple macro to use the Horner macro for cubic
  interpolation:
  Horner(T, 0, Points[This - 1]) + Horner(T, 1, Points[This]) + Horner(T,
  2, Points[This + 1]) + Horner[T, 3, Points[This + 2])

  Then I would use a loop to generate the actual points along the lathe
  shape from the control points with pseudocode something like this:

  Increment = .2 (or more or less, depending on the detail of the object -
  this should be fine for a bottle)
  Index = 0
  This = 1
  while (This < sizeof[Points])
  T = 0
  while (T < 1)
  Actualpoint[Index] = Cubic_interpolate(T, This)
  T = T + Incr
  Index =Index + 1
  endwhile
  This = This + 1
  endwhile

  Now you have the actual points that you will rotate around the y axis to
  form your bottle. Just use vrotate to get the points, say ten degrees
  clockwise from your spline and ten degrees counterclockwise.  Go all the
  way around and you have a sort of rectangular mesh (you need the points
  behind to calculate the normals - later).  Define two triangles for each
  rectangle.  At the base of the bottle, you will have to take into
  account that you have a single center point with a "pie" of triangles
  connected to it.  For each vertex, calculate the normal at that vertex
  thus:

  Take in turn the vector differences of the point you are working on and
  the other two points of each triangle it is part of, and vcross those
  differences.  Add up these cross products and vnormalize the result.
  This will give you the normal for your smooth_triangle at that point.
  Always work, say, clockwise to keep your normals consistent.  Like so:

  A  -  B  -  C

  |  \  |  \  |

  D  -  X  -  E

  |  \  |  \  |

  F  -  G  -  H

  vnormalize(vcross(X - B, X - A) + vcross(X - A, X - D) + vcross(X - D, X
  - G) + vcross(X - G, X - H) + vcross(X - H, X - E) + vcross(X - E, X -
  B))

  You then have the points and normals, so you can put together a mesh of
  smooth_triangles.  The whole process isn't as complex as this poor
  explanation may make it sound.  I have done it successfully, so you
  should have no trouble at all.  Let me know if you need more information
  or code snippets.  Good luck.

  Jerry Anning
  clem@dhol.com

-------------------------------------------------------------------------------
*/

