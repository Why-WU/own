

 setTimeout(function(){
 		console.log(123);
 },0);
 process.nextTick(() => console.log(1)); 
 Promise.resolve().then(() => console.log(2)); 
 process.nextTick(() => console.log(3)); 
 Promise.resolve().then(() => console.log(4)); // 1 // 3 // 2 // 4
 console.log("end");