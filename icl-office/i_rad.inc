/*
	The Office - Jaime Vives Piqueres, 2004.

	POV-Ray 3.5, 3.6, 3.6.1

	Radiosity settings (load/save)

*/

radiosity{
  #if (use_radiosity=2)
  // save settigns
  // hq
//  pretrace_start .05 pretrace_end .01
  pretrace_start .05 pretrace_end .005
  count 200
//  nearest_count 10 error_bound .5
  nearest_count 20 error_bound .5
  recursion_limit 1
  /*pretrace_start .05 pretrace_end .001
  count 900
  nearest_count 20 error_bound .5
  recursion_limit 1*/

  /*pretrace_start .05 pretrace_end .01
  count 200
  nearest_count 20 error_bound .3
  recursion_limit 1*/
  //save_file "office_rad_custom"
  #else
  // load settings
  pretrace_start 1 pretrace_end 1
  always_sample off
  error_bound .75
  recursion_limit 1
  //load_file "office_rad_custom"
  #end
}
