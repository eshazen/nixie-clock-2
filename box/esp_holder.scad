//
// bracket thing to hold ESP wifi module on top
// 2022-12-05:  3rd try with adjusted fit
//

e = 0.1;			/* interference delta */
g = 0.25;			/* mechanical gap */
mm = 25.4;

$fn = 32;

slot_dep = 6;

slot_wid_left = 4.75;
slot_wid_right = 2.75;
slot_offset_right = 0.7;

pcb_len_x = 36;
pcb_hgt_z = 26;

wall_thk = 1.6;			/* general wall thickness */
base_thk = 2.4;

base_len_x = pcb_len_x + 2*wall_thk;
base_wid_y = 25;
base_hgt_z = pcb_hgt_z + base_thk;

hole_x1 = base_len_x / 4;
hole_x2 = hole_x1*3;
hole_y = base_wid_y-hole_x1;

hole_dia = 0.15*mm;

module hole( x, y, d1, d2, thk, head) {
     translate( [x, y, -e]) {
	  cylinder( h=thk+2*e, d=d1);
	  translate( [0, 0, head])
	       cylinder( h=thk, d=d2);
     }
}

// base with mounting holes
difference() {
     cube( [base_len_x, base_wid_y, base_thk]);
     hole( hole_x1, hole_y, 0.15*mm, 7, base_thk, base_thk/2);
     hole( hole_x2, hole_y, 0.15*mm, 7, base_thk, base_thk/2);
}

// sides
translate( [0, 0, base_thk-e]) {

     difference() {
	  cube( [wall_thk+slot_dep, base_wid_y, pcb_hgt_z]);
	  // left slot for PCB
	  translate( [wall_thk, wall_thk, -e])
	       cube( [slot_dep+e, slot_wid_left, pcb_hgt_z+2*e]);
	  // cut extra stuff away
	  translate( [wall_thk, wall_thk*2+slot_wid_left, -e])
	       cube( [slot_dep+e, base_wid_y-wall_thk*2+slot_wid_left+e, pcb_hgt_z+2*e]);
	  // cutout for reset button
	  translate( [-e, -e, pcb_hgt_z-7])
	       cube( [wall_thk+slot_dep+2*e, wall_thk+slot_wid_left, 7+e]);
     }

     translate( [base_len_x-slot_dep-wall_thk, 0, 0])
     difference() {
	  cube( [wall_thk+slot_dep, base_wid_y, pcb_hgt_z]);
	  // right slot for PCB
	  translate( [-e, wall_thk+slot_offset_right, -e])
	       cube( [slot_dep+e, slot_wid_right, pcb_hgt_z+2*e]);
	  // cut extra stuff away
	  translate( [-e, wall_thk+2*slot_wid_right, -e])
	       cube( [slot_dep+e, base_wid_y-wall_thk*2+slot_wid_right+e, pcb_hgt_z+2*e]);
     }

     
     
}

