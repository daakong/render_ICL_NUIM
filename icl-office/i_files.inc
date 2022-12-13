/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Rows of files (uses bookplacer.inc)

*/
#declare r_file=seed(27);
#declare fim1=pigment{image_map{png "im_archiv"} translate -.5}
#declare fim2=pigment{image_map{png "im_archiv2"} translate -.5}
#declare fim3=pigment{image_map{png "im_archiv3"} translate -.5}

#macro build_row(a_books)

  #local ib=0;
  #local nb=dimension_size(a_books,1);
  union{
  #while (ib<nb)
   #local book_size=a_books[ib][0];
   #local book_pos=a_books[ib][1];
   #local book_ang=a_books[ib][2];
   #local sg=1;
   box{-.5,.5
    #if (rand(r_file)<.33)
     CIE_Imagemap(fim1)
    #else
    #if (rand(r_file)<.5)
      CIE_Imagemap(fim2)
     #else
      CIE_Imagemap(fim3)
     #end
    #end
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
   #local ib=ib+1;
  #end
  }

#end

#declare ab=array[12];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(354),0)
#declare brow1=object{build_row(ab)}
#declare ab=array[9];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(355),0)
#declare brow2=object{build_row(ab)}
#declare ab=array[10];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(356),0)
#declare brow3=object{build_row(ab)}
#declare ab=array[8];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(357),0)
#declare brow4=object{build_row(ab)}
#declare ab=array[10];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(358),0)
#declare brow5=object{build_row(ab)}
#declare ab=array[12];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(359),0)
#declare brow6=object{build_row(ab)}
#declare ab=array[7];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(360),0)
#declare brow7=object{build_row(ab)}
#declare ab=array[11];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(361),0)
#declare brow8=object{build_row(ab)}
#declare ab=array[4];
#declare whole_book_rows1=
union{
 object{brow1 }
 object{brow2 translate 30*y}
 object{brow3 translate 60*y}
 object{brow4 translate -30*y}
}
#declare whole_book_rows2=
union{
 object{brow5 }
 object{brow6 translate 30*y}
 object{brow7 translate 60*y}
 object{brow8 translate -30*y}
}
#declare whole_book_rows3=
union{
 object{brow2 }
 object{brow5 translate 30*y}
 object{brow4 translate 60*y}
 object{brow7 translate -30*y}
}
#declare whole_book_rows4=
union{
 object{brow4 }
 object{brow8 translate 30*y}
 object{brow6 translate 60*y}
 object{brow1 translate -30*y}
}


#declare ab=array[5];
books_row(ab,<8,26,20>,<8,26,20>,1,5,.1,0,seed(623),0)
#declare files_at_table=object{build_row(ab)}
