//
// bracket thing to hold ESP wifi module on top
//

e = 0.1;			/* interference delta */
g = 0.25;			/* mechanical gap */

slot_dep = 6;

slot_wid_left = 4.3;
slot_wid_right = 2.3;
slot_offset_right = 0.7;

pcb_len_x = 34;
pcb_hgt_z = 26;

wall_thk = 2;			/* general wall thickness */

base_len_x = pcb_len_x + 2*wall_thk;
base_wid_y = 20;
base_hgt_z = pcb_hgt_z + wall_thk;

cube( [base_len_x, base_wid_y, wall_thk]);

// sides
translate( [0, 0, wall_thk-e]) {

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

