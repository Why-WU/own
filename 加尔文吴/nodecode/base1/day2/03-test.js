function waitFive(name,function_name){
	var pus=0;
	var currentDate=new Date();
	function_name(name);
	while(pus<5000){
		var now=new Date();
		pus=now-currentDate;
	}

	
}

function echo(name){
	console.log(name);
}

waitFive("laoshan",echo);
console.log("its over");


