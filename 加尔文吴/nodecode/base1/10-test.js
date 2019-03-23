var fs=require('fs');


//var data=fs.readFileSync('./1.txt','utf-8');
fs.readFile('./1.txt','utf-8',function(err,data){
	if(err){
		console.log(err);
	}else{
		console.log(data);
	}
})

console.log("end");
console.log(__dirname);


//setTimeout setInterval setImmediate promise process.nextTick