var http=require('http');
var fs=require('fs');
var url=require('url');
var querystring=require('querystring');

http.createServer(function(req,res){
	//console.log(__dirname);
	//console.log(__filename);
	//console.log(url.parse(req.url));
	//var str=url.parse(req.url).query;
	//var obj=querystring.parse(str);
	//console.log(obj.name);
	//var urlpath=__dirname+"/module/"+url.parse('1.html').pathname;
	//var realpath=fs.readFileSync(urlpath,"utf-8");
	//console.log(urlpath);
	res.writeHead(200,{'Content-type':'text/html'});
	res.end("<h1>hello</h1>");
	//res.end(realpath)
}).listen(3000);


console.log("server start port 3000");