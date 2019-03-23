var http=require('http');
var fs=require('fs');
var url=require('url');
var querystring=require('querystring');

http.createServer(function(req,res){
	var pathname=url.parse(req.url).pathname;
	switch(pathname){
		case '/' :
			goIndex(res);
			break;
		case '/parse':
			resAdd(res,req);
			break;
		default :
			res.writeHead(404,{'Content-type':'text/plain'});
			res.end('not found page');
	}
}).listen(3000);

console.log("server start");

function goIndex(res){
	var pathname=__dirname+'/module/'+url.parse('index.html').pathname;
	var data=fs.readFileSync(pathname,'utf-8');
	res.writeHead(200,{'Content-type':'text/html'});
	res.end(data);
}

function resAdd(res,req){
	var postData="";
	req.setEncoding('utf8');
	req.addListener('data',function(postChunk){
		postData+=postChunk;
	});
	req.addListener('end',function(){
		//console.log(postData);
		var dnsobj=querystring.parse(postData);
		//console.log(dnsobj);
		var dnsstr=dnsobj.search_dns;
		res.writeHead(200,{'Content-type':'text/plain'});
		res.end(dnsstr);
	});

}