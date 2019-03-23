1、先执行同步宏任务
2、process.nextTick
3、promise

4、调用微任务 setTimeout setInterval
5、setImmediate

//同步程序代码最快
//process.nextTick(Fn)  第二快
//setTimeout(Fn,0) 第三快
//setImmediate(Fn) 事件队列最后执行


for(var i=0;i<=3;i++){
	setTimeout(function(){
		console.log(i);
	},0);
}


process.nextTick(function(){
	console.log(345);
});
//process.nextTick(() => console.log(345));

console.log("end");

/*
 process.nextTick(() => console.log(1)); 
 Promise.resolve().then(() => console.log(2)); 
 process.nextTick(() => console.log(3)); 
 Promise.resolve().then(() => console.log(4)); // 1 // 3 // 2 // 4
*/

process.nextTick(){
	process.nextTick(){

	}
}

setTimeout(function(){
	Promise.resolve().then(() => console.log(4));
	console.log(123);
},0);

setTimeout(function(){
	consoe.log(456);
},0);


function climb(n){
	return climb(n-1)
}


/*
string  xiaohong 18 harbin
<des>
	<name>xiaohong</name>
    <age>18</age>
    <city>harbin</city>
</des>

"{'name':'xiaohong','age':18}"

eval()

JSON.stringfy
JSON.parse*/

/*
public static void climb(int n,String  way){
	if(n==1){
		System.out.println("way="+1);
		return 
	}

	if(n==2){
		System.out.println("way="+2);
		System.out.println("way="+1+1);
		return;
	}

	String way1=way+1;
	climb(n-1,way1);
	String=way2=way+2
	climb(n-2,way2);
}


public static void sum(node head){
	if(head==null){
		return 0;
	}else{
		return head.value+sum(head.next);
	}
}


1+2+3+4+5

var arr=[1,2,3,4,5];
var sum=0;
for(int i=0;a<=4;i++){
	sum+=arr[i];
}

function add(i){
	//var n=arr[i];
	sum=add(i)+add(i+1);
	if(i==4){
		return sum;
	}
}


node.next.next=node.next;
node.next=null;

你们首先要明白
链表和数组不一样

链表的逆序和数组的逆序不一样
数组的逆序是索引的逆序
链表的逆序是指针反向

枚举是 enum的方法
递归 不是 枚举

条件1  包满   东西还有
条件2  包不满 东西没有了

条件1演化出条件三 包满正好是20  东西还有
条件2演化出条件四 包不满但是已经超过20 东西还有*/