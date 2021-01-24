// unoptimized
function getLongestCollartzSequence() {
	function collartzCount ( number ) {
	  if ( number == 1 ) {
	    return 1;
	  }
	  
	  if ( number % 2 == 0 ) {
	    return 1 + collartzCount ( number / 2 );
	  }
	  
	  if ( number % 2 == 1 ) {
	    return 1 + collartzCount ( 3 * number + 1 ) ;
	  }
	}
	//slightly optimized using maps
	function collartzOptimized ( number , cc ) {
	  // Case of 1 or no ?
	  if ( number == 1 ) {
	    return 1;
	  }
	  if ( !cc.has(number) ) {
	 		if (number % 2 == 0 ) {
	      cc.set ( number , 1 + collartzCount(number / 2 ));
	    }
	    else {
	      cc.set ( number , 1 + collartzCount(3 * number + 1 ));
	    }
	  }
	  
	  return cc.get(number);
	}
	let maxChain = 0, maxChainNumber = 0;
	let collartzNumbers = new Map() ;
	collartzNumbers.set ( 1 , 1 );
	for ( let testNumber = 1  ; testNumber < 1000000 ; ++testNumber) {
	  let termsInChain = collartzOptimized(testNumber, collartzNumbers);
	  if ( termsInChain > maxChain) {
	    maxChain = termsInChain;
	    maxChainNumber = testNumber;
	  }
	}
	//console.log(maxChainNumber);
	//test cases
	/*console.log(collartzCount ( 1)); //=>1
	console.log(collartzCount ( 3)); //=>8
	console.log(collartzCount ( 13)); //=>10
	*/
	return maxChainNumber;
}
