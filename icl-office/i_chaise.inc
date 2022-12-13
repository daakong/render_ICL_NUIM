/*****************************************************************************\
*
* Persistence of Vision Raytracer MegaPov version alpha 0.6
*
* chaise.inc - F. Dispot - 9 dec 2000
*
* Objets pour G.Landfelder: tabouret, chaise et fauteuil de bureau
*
* Tailles en cm.
*
\*****************************************************************************/

#declare Schaise=seed(0);

/*****************************************************************************\
*
* chaise_pied(H)
*   H = hauteur du siège (roulettes non comprises) >= 35
*
\*****************************************************************************/

#macro chaise_pied(H)
  #local Bois_Clair=texture{t_black_plastic}
  #local Bois_Fonce=texture{t_black_plastic}
  #local chaiseMetal1=texture{t_lamp}
  #local chaiseMetal2=texture{t_normal_chrome}

  #local pied1=object{ // milieu de branche
    union{
      box{<-2, 0, 3>, <2, 4, 30>}
      cylinder {0, (30-3)*z, 1 scale <2, 1, 1> translate <0, 4, 3>}
    }
    texture{Bois_Clair}
  }
  #local pied2=object{ // extrêmité extérieure
    union{
      cylinder {<0, 0, 30>, <0, 4, 30>, 2}
      sphere {0, 1 scale <2, 1, 2> translate <0, 4, 30>}
    }
    texture{Bois_Fonce}
  }
  #local roulette=union{
    cylinder {-2*x, 2*x, 2.5 translate <0, 2.5, 1.5>}
    cylinder {2.5*y, 6*y, .6}
    texture{t_black_plastic}
  }
  #local pied0=union{ // branche complète
    object {pied1}
    object {pied2}
    object {roulette rotate y*360*rand(Schaise) translate <0, -5, 30>}
  }
  #local pied3=union{ // bas du piétement
    cylinder{-.5*y, 6*y, 5}
    sphere{0, 1 scale <5, 3, 5> translate 6*y}
    texture{Bois_Fonce}
  }
  #local pied4=cylinder{ // bas du cylindre
    5*y, 30*y, 3
    texture{chaiseMetal1}
  }
  #local pied5=cylinder { // haut du cylindre
    5*y, H*y, 2
    texture{chaiseMetal2}
  }
union{
  object{pied0 rotate 0*72*y}
  object{pied0 rotate 1*72*y}
  object{pied0 rotate 2*72*y}
  object{pied0 rotate 3*72*y}
  object{pied0 rotate 4*72*y}
  object {pied3}
  object {pied4}
  object {pied5}
}

#end

/*****************************************************************************\
*
* chaise(coul, H)
*   coul = pigment
*   H = hauteur du siège (roulettes non comprises) > 35
*
\*****************************************************************************/

#macro chaise(Coul, H)
  #local Tissu=texture{
    pigment {Coul}
    #if (use_normals)
    normal {leopard bump_size 10 scale .1}
    #end
    finish {phong 0.1 phong_size 0.3}
  }
  #local siege1=superellipsoid{ // Assise
    <.6, .4>
    rotate 90*x
    scale <25, 3, 25>
    texture {Tissu}
  }
  #local siege2=object{ // Attache du dossier
    union{
      box {<-3, -1, 0>, <3, 1, 20>}
      intersection{
	difference {
	  cylinder {<-3, 4, 20>, <3, 4, 20>, 5}
	  cylinder {<-4, 4, 20>, <4, 4, 20>, 3}
	}
	box {<-4, 4, 20>, <4, -1, 25>}
      }
      box {<-3, 4, 23>, <3, 34, 25>}
      cylinder {<-5, 34, 23>, <5, 34, 23>, 2}
      sphere {<-5, 34, 23>, 2}
      sphere {< 5, 34, 23>, 2}
      cylinder {<0, 30, 26>, <0, 30, 27>, 3}
      cylinder {<0, 30, 25>, <0, 30, 26>, .5}
    }
    texture{t_black_plastic}
  }
  #local siege3=superellipsoid{ // Dossier
    <.6, .4>
    scale <25, 20, 3>
    rotate 10*x
    texture {Tissu}
  }
  #local siege=union{
    object{siege1}
    object{siege2 translate <0, -2, 10>}
    object{siege3 translate <0, 34, 29>}
    translate H*y
    rotate -10*y
  }
  union{
    object {chaise_pied(H)}
    object {siege}
    translate 5*y
    scale .9
  }
#end

/*****************************************************************************\
*
* tabouret(coul, H)
*   coul = pigment
*   H = hauteur du siège (roulettes non comprises) > 35
*
\*****************************************************************************/

#macro tabouret(Coul, H)
  #local Tissu=texture{
    pigment {Coul}
    normal {leopard bump_size 10 scale .1}
    finish {phong 0.3 phong_size 0.3}
  }
  #local siege=superellipsoid{ // Assise
    <1, .4>
    rotate 90*x
    scale <20, 4, 20>
    texture {Tissu}
    translate H*y
  }
  union{
    object {chaise_pied(H)}
    object {siege}
    translate 5*y
  }
#end


/*****************************************************************************\
*
* fauteuil(coul, H)
*   coul = pigment
*   H = hauteur du siège (roulettes non comprises) > 35
*
\*****************************************************************************/

#macro fauteuil(Coul, H)
  #local Tissu=texture{
    pigment {Coul}
    normal {leopard bump_size 10 scale .1}
    finish {phong 0.3 phong_size 0.3}
  }
  #local acc1=object{ // Attache de l'accoudoir
    union{
      box {<-3, -1, 0>, <3, 1, 20>}
      intersection{
	difference {
	  cylinder {<-3, 4, 20>, <3, 4, 20>, 5}
	  cylinder {<-4, 4, 20>, <4, 4, 20>, 3}
	}
	box {<-4, 4, 20>, <4, -1, 25>}
      }
      box {<-3, 4, 23>, <3, 20, 25>}
    }
    texture{t_pintura_marron}
    rotate 90*y
  }
  #local acc2=superellipsoid{ // Accoudoir
    <.6, .8>
    rotate 90*x
    scale <5, 3, 10>
    texture {Tissu}
    translate <24, 19, 0>
  }
  #local acc=union{
    object {acc1}
    object {acc2}
    translate <3, 3, 2>
  }
  union{
    object {chaise(Coul, H)}
    object {acc rotate -10*y translate H*y}
    object {acc scale <-1, 1, 1> rotate -10*y translate H*y}
  }
#end

