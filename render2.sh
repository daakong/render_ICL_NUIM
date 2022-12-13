echo "This is the 2nd pass using ICL code to render the office room dataset. Da Kong, 12-8-2022"

cd icl-office/

"/usr/local/bin/povray" +Ioffice1.pov +Oscene_000.png +W640 +H480 \
 +wt64 +RFradiosity_first_pass/scene_radiosity_000.txt +RFI -d \
 +L/usr/local/bin/povray/include +LLightsysIV +Lmaps +HIsecond_pass_settings.inc  +FN16

# + Declare=val00=0.998739 + Declare=val01=0.00725321 + Declare=val02=-0.0496855 \ 
# + Declare=val10=0.00725319 + Declare=val11=0.958294 + Declare=val12=0.285692  \
# + Declare=val20=0.0496855 + Declare=val21=-0.285692 + Declare=val22=0.957033  \
# + Declare=val30=91 + Declare=val31=465 + Declare=val32=-292 \
