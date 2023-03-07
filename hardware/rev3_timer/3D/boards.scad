//
// test assembly for Nixie timer v3
// "control" and "display" boards hacked from combo board
// > exported as "VRML" from pcbnew
// > converted using imagetostl.com website
//

// two options, "flat" model with sloping control panel
// and "vertical" display model presented side-by-side

module display() {
     translate( [-34.5, 103, 0])
     scale( [1000, 1000, 1000]) import("display.stl");
}

module control() {
     translate( [-34.5, 103+83.4, 0])
     scale( [1000, 1000, 1000]) import("control.stl");
}


translate( [150, 0, 0]) {

// slant controls
color("orange") display();
translate( [0, -45, -5])
rotate([15, 0, 0])
color("green") control();
}

// vertical display
rotate( [90, 0, 0])
color("orange") display();
translate( [0, -70, -27])
rotate( [45, 0, 0])
color("green") control();

// base
translate( [0, -70, -30]) {
     cube( [114.3, 90, 1.6]);
     translate( [0, 90, 0])
     cube( [114.3, 1.6, 120]);
}
