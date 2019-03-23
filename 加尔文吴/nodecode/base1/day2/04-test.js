var http=require("http");
var url=require('url');
var fs=require('fs');

http.createServer(function(req,res){
	//1、先把index.html读入到内存（文件路径、读取方法）
	//2、把内存的数据编程数据包
	//3、把数据包发送给chrome
	//var pathname=url.parse(req.url).query;
	//console.log(pathname);
	/*
	var str="name=laoshan"
	var arr=str.split("=");
	console.log(arr);*/
	//console.log(__dirname);
	var pathname=__dirname+'/module/'+url.parse("index.html").pathname;
	var pathobj=fs.readFileSync(pathname,"utf-8");
	//console.log(pathname);

	res.writeHead(200,{'Content-type':'text/html'});
	res.end(pathobj);
}).listen(3000);

console.log("server start");