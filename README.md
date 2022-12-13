# Render ICL-NUIM

This is re-rendering of the [ICL-NUIM dataset](http://www.doc.ic.ac.uk/~ahanda/VaFRIC/iclnuim.html). 
Our aim is to make this dataset suitable for more flexible SLAM and visual odometry usage.
Code is based on the source code from ICL-NUIM and adopted by Da Kong. You can download from [here](http://www.doc.ic.ac.uk/~ahanda/VaFRIC/office_room.html).

> The data is released under Creative Commons 3.0 (CC BY 3.0), see http://creativecommons.org/licenses/by/3.0/. 


1. install pov_ray first. In this repo, we use 3.7-stable version.

```angular2html
git clone https://github.com/POV-Ray/povray.git
cd povray
git checkout 3.7-stable
cd unix/
./prebuild.sh
cd ../
./configure COMPILED_BY="your name <email@address>"
make 
sudo make install
```

2. Get the office scene of ICL-NUM

You can [download](ttp://www.doc.ic.ac.uk/~ahanda/VaFRIC/office_code.tgz) yourself. I have attached it to the git repo (icl-office/).

3. Make output folders at "icl-office/stereo_out/left" and "icl-office/stereo_out/right"

4. Run the python script.

```
python pyrender.py
```