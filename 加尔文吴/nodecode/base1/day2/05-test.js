//  路由接收地址 / --> index.html  /parse --->laoshan loves laoxie 
//                 其他的 404

var http=require('http');
var fs=require('fs');
var url=require('url');

http.createServer(function(req,res){
	var pathname=url.parse(req.url).pathname;
	switch(pathname){
		case "/" :
			goIndex(res);
			break;
		case "/parse":
			goString(res);
			break;
		case "/img":
			goImg(res);
			break;
		default:
			res.writeHead(404,{"Content-type":"text/plain"});
			res.end("not found page");
	}
	
}).listen(3000);

console.log("server start");

function goImg(res){
	var imgname=__dirname+"/module/"+url.parse("1.jpg").pathname;
	var imgdata=fs.readFileSync(imgname);
	res.writeHead(200,{"Content-type":"image/jpeg"});
	res.end(imgdata);
}

function goIndex(res){
	var realname=__dirname+"/module/"+url.parse("index.html").pathname;
	var data=fs.readFileSync(realname,"utf-8");
	res.writeHead(200,{"Content-type":"text/html"});
	res.end(data);
}

function goString(res){
	res.writeHead(200,{'Content-type':'text/plain'});
	res.end("laoshan loves laoxie");
}