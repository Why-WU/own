function aa(){
	var xx="laoshan";
	this.b=1;
	this.bb=function(){
		console.log(123);
	}
}

aa.prototype.write=function(){
	console.log(456);
}

var AA=new aa();
//AA.bb();
//console.log(AA.__proto__);
console.log(AA.__proto__==aa.prototype);
AA.write();

/*
function cc(a,callback){
	if(callback !=null && callback==function)

}*/

