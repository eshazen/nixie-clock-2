//
// IN-12 nixie
//

spd = 80;

module pin() {
     cylinder( d=1, h=6);
}

module nixie() {
     % intersection() {
	  cylinder( r=29/2, h=28);
	  translate( [-19.7/2, -30/2, 0])
	       cube( [19.7, 30, 28]);
	  translate( [0, 0, -(spd/2-27)])
	       sphere( d=spd);
     }
     translate( [0, 0, -6]) {
	  for( x=[0:1]) {
	       for( y=[0:2]) {
		    translate( [-11.5/2+x*11.5, -4.5+y*4.5, 0])
			 pin();
	       }
	  }
	  for( x=[0:1]) {
	       for( y=[0:1]) {
		    translate( [-8/2+x*8, -8+y*16, 0])
			 pin();
	       }
	  }
	  translate( [0, -9, 0]) pin();
	  translate( [0, 9, 0]) pin();
     }
}

nixie();
