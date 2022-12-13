#declare  Skin=
 texture{
    pigment{
      gradient -y
      scale 1.5
      color_map{
	[0.0 color rgbt <.296, .283, .030, 0>] 
	[.2 color rgbt <.485, .337, .042, 0>] 
	[.4 color rgbt <.753, .503, .067, 0>] 
	[1 color rgbt <.386, .223, .005, 0>] 	
      }
    }
    normal{
	marble .2
	turbulence .3 
	scale <.01, .01, .01>
    }
 
    finish{
      specular .05
      roughness .2
    }
  }
 
 
#declare Dents =
  texture{
    pigment{ 
      rgb <.258, .091, .0> 
    }
  }
 
#declare BananaSkin =
	texture{
          granite
      	  scale 1.5
          //turbulence .5
      	  texture_map{
		[0.0  Dents]
		[0.07 Dents]
		[0.13 Skin]
		[1.0  Skin]
      	  }
	}
