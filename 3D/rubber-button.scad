//
// CK K12C sealed rubber button
//

$fn=64;

module button() {
     color("black") {
	  translate( [0, 0, 5.5])
	       cylinder( r1=6.4, r2=5.4, h=6.5);
	  cylinder( h=5.5, r=10.9/2);
     }
     translate( [-7.5/2, -2.5/2, -1.2])     cylinder( r=1.1/2, h=1.2);
     translate( [7.5/2, 2.5/2, -1.2])    cylinder( r=1.1/2, h=1.2);
     translate( [-2.3/2, -0.1, -2.9])   cylinder( h=2.9, r=0.9/2);
     translate( [2.3/2, 0.1, -2.9])   cylinder( h=2.9, r=0.9/2);
}

button();


