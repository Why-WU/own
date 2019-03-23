//读取1.txt，停2S再结束
var fs=require('fs');

fs.readFile('./1.txt','utf-8',function(err,data){
	if(err){
		console.log(err);
	}else{
		//console.log(123);
		getData(data);

		/*
		setTimeout(function(data){
			console.log(data);
		},200);*/
	}
});


function getData(data){
	//console.log(data);
	//aa(data);
	setTimeout(function(){
		console.log(data);
	},200);
	/*
	setTimeout(function(data){
		console.log(data);
	},200);*/
}

/*
function returnData(data){
	console.log(data);
}*/

var data=123;

function aa(data){
	console.log(data);
}

