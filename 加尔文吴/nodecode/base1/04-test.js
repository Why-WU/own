for(var i=0;i<=6;i++){
	setTimeout(function(){
		console.log(i);
	},0);
}

console.log("end");


//process.nextTick(() => console.log(1)); 
 Promise.resolve().then(() => console.log(2)); 
//process.nextTick(() => console.log(3)); 
 Promise.resolve().then(() => console.log(4));
