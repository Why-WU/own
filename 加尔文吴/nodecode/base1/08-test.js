var http=require('http');

http.createServer(function(req,res){
	res.writeHead(200,{'Content-type':'text/html'});
	res.end("<h1>hello</h1>");
}).listen(3000);


console.log("server start");



/*
Date: Sat, 16 Mar 2019 07:30:47 GMT
Expires: Sat, 16 Mar 2019 07:32:07 GMT
Etag:dshfkjshi&*8u2jdsjk*/

//MIME  409  text/css  image/png  image/jpeg
/*
setcookie('name','laoshan',3600)
setcookie('name','laoshan')*/


/*select * from user where name="laoshan" and pass= or 1%3c1*/

/*
1.php
<?php
	if(isset($_POST['sub'])){

	}

?>

<form action="1.php" method="post">
	username:<input type="text" name="name" value="<?php echo $name?>"><br />
	password:<input type="password" name="pass"><br />
	<input type="submit" name="sub" value="登录">
</form>*/