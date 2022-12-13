// *** BOOKPLACER DEMO ***

// *** control variables ***
#declare dbg=0;  // debug mode?
#declare num_books=11;  // number of books
#declare r_books=seed(40);  // random seed for the books

// *** standard ***
global_settings{
 radiosity{count 50 error_bound 1 nearest_count 5}
}
#include "colors.inc"
#include "textures.inc"


// *** scenery ***
plane{y,0 pigment{White}}
plane{y,250 pigment{White}}
plane{x,-100 pigment{White}}
plane{x,100 pigment{White}}
plane{z,0 pigment{White}}
box{-.5,.5 scale <1,20,20>
 pigment{White}
 translate <-20.6,10,-10>
}

camera{
 location <-1,25,-100>
 up <0,2.4,0>
 right <3.6,0,0>
 direction 5*z
 look_at <0,10,0>
}

light_source{
 <20,200,-50>
 White
}


// *** simple book ***
#macro book(t_lomo)

union{
 difference{
  superellipsoid{<.01,.01> rotate 90*x scale .5}
  box{-.5,.5 scale <.9,1.1,1> translate .05*z}
  texture{t_lomo}
 }
 box{-.5,.5
  texture{pigment{White*.9}}
  scale <.9,.98,.9> translate .05*z
 }
 rotate 180*y
}

#end


// *** demo ***
#include "i_bookplacer_v2.inc"
#declare a_books=array[num_books]; // array for the books row
#if (dbg) // debugging placement
 object{
  books_row(a_books,<1,15,10>,<4,20,15>,1,4,.1,.1,r_books,1)
  translate -20*x
 }
#else // final books
 books_row(a_books,<1,15,10>,<4,20,15>,1,4,.1,.1,r_books,0)
 #declare i_books=0;
 union{
 #while (i_books<num_books)
  #declare book_size=a_books[i_books][0];
  #declare book_pos=a_books[i_books][1];
  #declare book_ang=a_books[i_books][2];
  #declare sg=1;
  #if (book_ang.z<0)
   #declare sg=-1;
  #end
  #declare t_book=
  texture{
   pigment{rgb vnormalize(<rand(r_books),rand(r_books),rand(r_books)>*.5+.5)}
  }
  object{book(t_book)
   rotate 180*y
   scale book_size*.99
   translate book_pos.y*y
   translate sg*book_size.x*.5*x
   rotate book_ang.z*z
   #if (book_ang.z<0)
    translate book_size.x*x
   #end
   translate book_pos.x*x
   translate book_pos.z*z
  }
  #declare i_books=i_books+1;
 #end
  translate -20*x
 }
#end


