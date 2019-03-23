var http=require('http');
var url=require('url');
var querystring=require("querystring");

http.createServer(function(req,res){
	var urlstr=url.parse(req.url).query;
	var newobj=querystring.parse(urlstr);
	console.log(newobj);
	//console.log(urlstr);
}).listen(3000);

console.log("server start");