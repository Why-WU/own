function haveLunch(food,drink,callback){
	console.log("dating lunch of "+food+','+drink);
	if(callback && typeof(callback)==='function'){
		//callback();
		setTimeout(function(){
			callback();
		},5000);
	}
}


haveLunch('toast','coffee',function(){
	console.log("Finished Lunch");
})


