/*
setTimeout(function(){
	console.log(1);
},0);

console.log("end");


1: JS解释器先扫描同步代码和异步代码
2：把异步代码抛给事件循环
3：当前线程必须空闲，同时满足触发条件（磁盘I/O  网络I/O 时间 
             on addListener emit ）*/
/*
var a=123;
function bb(){
	console.log(a);
}

bb();*/