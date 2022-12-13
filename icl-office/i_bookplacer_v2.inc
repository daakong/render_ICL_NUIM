/*

  "i_bookplacer_v2.inc", Jaime Vives Piqueres, 2001.
  --------------------------------------------------

  * Description:

    + Macro that places a row of books like in a library shelf.

  * Parameters:

    + array for books      : array[num_of_books] (sub-elements will be created)
    + min book dimensions  : vector
    + max book dimensions  : vector
    + sign of displacement : -1/1 (left/right)
    + mean separation      : float
    + sep. disorder pct    : float (0-1)
    + sign disorder pct    : float (0-1)
    + random seed          : seed
    + debug mode           : int 0/1 (off/on)

  * Usage:

    + Just call it from your scene, passing the appropiate book properties array to be filled.
      See the file "books_test.pov" included with the archive for more details.

  * Notes:

    + The inner working of this macro is rather complicated to explain, mainly bcos I do not
      speak enlgish as fluently as is needed... Anyhow, here is the explanation:

  * To-do list:

    + Weight accumulator to slide books when reaching some degrees
    + initial angle, useful to continue an existant row with other parameters...
    + sligty rotation around x on the front-lower corner, to simulate "not well pushed" books.

  * Disclaimer:

    + This code was done unconsciously, so any responsability is declined.

*/

#macro books_row(
 books_array,
 minbd,
 maxbd,
 disp_sign,
 mean_sep,
 sep_disorder,
 sgn_disorder,
 books_seed,
 debug_mode
)

// some work variables
#local book_num=dimension_size(books_array,1); // number of books
#local book_cnt=0;                             // books counter
#local cur_book_ang=0;                         // starting current book angle
#local pre_book_ang=0;                         // starting previous book angle
#local cur_book_pos=<0,0,0>;                   // starting current book position
#local pre_book_size=<0,0,0>;                  // starting previous book size
#local acc_weight=0;                           // accumulated books weight
#local r_book=books_seed;                      // random seed

// if debugging create aunion of test boxes
#if (debug_mode)
union{
#end

// construct the row
#while (book_cnt<book_num)

 // inserts an array of 3 elem for the properties of this book (size, position and angle)
 #declare books_array[book_cnt]=array[3]
 // initialize displacement sign
 #local cur_disp_sign=disp_sign;
 // random color for text boxes
 #local rand_color1=rgb <.5*rand(r_book),.5*rand(r_book),.5*rand(r_book)>;
 // obtain random size based on min and max values provided, and then calculate weight
 #local cur_book_size=
  <minbd.x+(maxbd.x-minbd.x)*rand(r_book),
   minbd.y+(maxbd.y-minbd.y)*rand(r_book),
   minbd.z+(maxbd.z-minbd.z)*rand(r_book)>;
 #local cur_weight=cur_book_size.x;
 // test if there is probability for separation disorder (increased separation)
 #if (rand(r_book)<=sep_disorder)
  #local cur_sep=mean_sep+mean_sep*sep_disorder*rand(r_book);
 #else
  #local cur_sep=mean_sep;
 #end
 // always randomize book separation within the limits
 #local dbb=cur_sep*sep_disorder*rand(r_book)+cur_sep*(1-sep_disorder)*rand(r_book);
 // if this is the first book, place it without previous separation
 #if (book_cnt=0)
  #local cur_book_pos=
   <cur_book_pos.x,
    cur_book_size.y*.5,
    -cur_book_size.z*.5>;
  // and set a very high weight for the shelf/object suposedly supporting the row
  #local last_standing_weight=cur_weight*1000;
 #else
  // if not, use randomized separation and previous book size to increase book position
  #local cur_book_pos=
   <cur_book_pos.x+pre_book_size.x+dbb,
    cur_book_size.y*.5,
    -cur_book_size.z*.5>;
  // if previous book has inverted sign, increase x book pos to "pass" the previous book
  #if (pre_disp_sign=-1)
   #local cur_book_pos=cur_book_pos+<vrotate(<0,pre_book_size.y,0>,<0,0,pre_disp_sign*pre_book_ang>).x,0,0>;
  #end
  // if there is a probailitie for sign disorder, just set a random opposed angle
//  #if (book_cnt<book_num-1 & cur_book_size.x<maxbd.x*.5 & rand(r_book)<sgn_disorder & pre_disp_sign=1)
  #if (book_cnt<book_num-1 & rand(r_book)<sgn_disorder & pre_disp_sign=1)
   #local cur_book_ang=15*sgn_disorder*rand(r_book)+15*sgn_disorder*rand(r_book)+15*sgn_disorder*rand(r_book)+15*sgn_disorder*rand(r_book);
   #local cur_disp_sign=cur_disp_sign*-1;
   #local last_standing_weight=cur_weight;
  #else  // if not, continue with book placement...
   // there is chance to stand up due to size (weight), unbelievable angle or previous inverted?
   #if (book_cnt<book_num-1 & ((acc_weight+cur_weight>=last_standing_weight) | (cur_book_size.x>maxbd.x*.9 & (pre_book_ang<5)) | (pre_disp_sign=-1)))
    // ...set angle=0, previous contact point to book height and substracts separation
    #local cur_book_ang=0;
    #local p2=<0,cur_book_size.y,0>;
    #local cur_book_pos=cur_book_pos-<dbb*.99,0,0>;
    #local acc_weight=0;
    #if (pre_book_ang=0 | pre_disp_sign=-1)
     #local last_standing_weight=last_standing_weight+cur_weight;
    #else
     #local last_standing_weight=cur_weight;
    #end
   #else
    // if not, enter the falling routine
    #local found=0;
    // set test contact direction as opposed to row direction
    #local Direc = <-1*cur_disp_sign,0,0>;
    // find previous contact point
    #local p2=vrotate(<pre_disp_sign*pre_book_size.x,pre_book_size.y,0>,<0,0,pre_disp_sign*pre_book_ang>);
    // if current book height is higher than previous contact point...
    #if (cur_book_size.y>p2.y+pre_book_size.x*(pre_book_ang/180))
     // set current contact point start to previous
     #local v1=<0,p2.y+pre_book_size.x*(pre_book_ang/180)-.01,0>;
     #if (debug_mode)
      #local p_testp=pigment{Red}
     #end
    #else
     // if not, simply set start contact point to current book height
     #local v1=<0,cur_book_size.y,0>;
     #if (debug_mode)
      #local p_testp=pigment{Green}
     #end
    #end
    // test starts from 0
    #local cur_book_ang=0;
    // run test while no contact point found
    #while (found=0)
     #local cur_book_ang=cur_book_ang+.05*cur_disp_sign;
     #local Norm = <0, 0, 0>;
     #local v2=<0,0,cur_disp_sign*cur_book_ang>;
     #local temp=vrotate(v1,v2);
     #local p=<temp.x+cur_disp_sign*cur_book_pos.x,temp.y,-cur_book_size.z*.5>;
     #local Inter=trace ( last_book, p, Direc, Norm );
     #if ((debug_mode) & (book_cnt=book_num-1)) // debug mode helps to visualize last book path
      #debug str(p.y,5,2)
      #debug "-"
      #debug str(Inter.y,5,2)
      sphere{p+1*z,.1 pigment{p_testp}}
      #debug "\n"
     #end
     #if ( ((Direc.x!=0) & (p.x-Inter.x<.1)) | ((Direc.y!=0) & (p.y-Inter.y<.1)))
      #local found=1;
     #end
    #end // test while
    #local acc_weight=acc_weight+cur_weight;
   #end // if not stand-up
  #end // if not inverted
 #end // if not first book
 #if (debug_mode)
  #debug "\n"
 #end
 // declare this book for tests on next book
 #local last_book=
 box{-.5,.5
  scale cur_book_size
  texture{pigment{Gray20+Gray50*rand(r_book)+rand_color1}}
  translate cur_book_pos.y*y
  translate cur_disp_sign*cur_book_size.x*.5*x
  rotate cur_disp_sign*cur_book_ang*z
  #if (cur_disp_sign=-1)
  translate cur_book_size.x*x
  #end
  translate cur_book_pos.x*x
  translate cur_book_pos.z*z
 }
 // if debugging use boxes to show books placement
 #if (debug_mode)
   object{last_book}
 #end
 // fill the returned array (via parameter, remember...)
 #declare books_array[book_cnt][0]=cur_book_size;
 #declare books_array[book_cnt][1]=cur_book_pos;
 #declare books_array[book_cnt][2]=<0,0,cur_disp_sign*cur_book_ang>;
 // update work variables
 #local pre_book_size=cur_book_size;
 #local pre_book_ang=cur_book_ang;
 #local pre_disp_sign=cur_disp_sign;
 #local book_cnt=book_cnt+1;
#end
// close the union if debugging
#if (debug_mode)
}
#end

#end // macro end!

