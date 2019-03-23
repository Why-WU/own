

var http=require('http');
urls=['www.baidu.com','www.qq.com','www.sohu.com'];

function fetchPage(url){
	var start=new Date();
	http.get({'host':url},function(res){
		console.log("Get respone from "+url);
		console.log("Request took:",new Date()-start,'ms');
	});
}

for(var i=0;i<urls.length;i++){
	//console.log(urls[i]);
	fetchPage(urls[i]);
}


/*
function bb(){
	url="12345";
	console.log(567);
}

bb();
console.log(url);*/