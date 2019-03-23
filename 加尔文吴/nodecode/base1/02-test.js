var aa=function(){
	console.log(123);
}

function aa(){
	console.log(456);
}

aa();

解释器、预编译、作用域、上下文、运行时（runtime）

1：  var aa=undefined
     function aa(){}  //先加载内存
2：  代码执行 var aa undefined--> function aa(){}  覆盖掉了上一个aa()
3:   aa();