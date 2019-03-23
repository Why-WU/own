var http=require('http');
var url=require('url');
var fs=require('fs');

http.createServer(function(req,res){
	var pathname=url.parse(req.url).pathname;
	var realPath=__dirname+'/static'+pathname;
	if(pathname=='/favicon.ico'){
		return;
	}else if(pathname=='/'){
		goIndex(res);
	}else{
		dealWithStatic(pathname,realPath,res);
	}
}).listen(3000);

console.log("server start");

function goIndex(res){
	var readPath=__dirname+'/static/'+url.parse('newindex.html').pathname;
	var indexPage=fs.readFileSync(readPath,"utf-8");
	res.writeHead(200,{'Content-type':'text/html'});
	res.end(indexPage);
}

function dealWithStatic(pathname,realPath,res){
	//console.log(realPath);
	fs.exists(realPath,function(exists){
		if(!exists){
			res.writeHead(404,{'Content-type':'text/plain'});
			res.end("this request was wrong");
		}else{
			//console.log(pathname);
			var pointPosition=pathname.lastIndexOf('.');
			//console.log(pointPosition);
			var mmieString=pathname.substring(pointPosition+1);
			//console.log(mmieString);
			var mmietype;
			switch(mmieString){
				case 'css':
					mmietype="text/css";
					break;
				case 'jpg':
					mmietype="image/jpeg";
					break;
				default:
					mmietype="text/plain";
					break;
			}

			fs.readFile(realPath,"binary",function(err,file){
				if(err){
					res.writeHead(500,{"Content-type":"text/plain"});
					res.end(err);
				}else{
					res.writeHead(200,{"Content-type":mmietype});
					res.write(file,'binary');
					res.end();
				}

			})
		}
	})
}



