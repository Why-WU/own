var dns=require('dns');

dns.resolve4("www.taobao.com",function(err,addresses){
	if(err){
		console.log(err);
	}else{
		console.log(addresses);
	}
});

/*
var str="{'name':'laoshan','age':'19'}";

var obj=eval("("+str+")");

console.log(obj.name);*/

//JSON.parse