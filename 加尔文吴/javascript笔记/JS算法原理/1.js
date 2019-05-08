var str="hello world";
var arr=[];
var ustr="";
for(var i=str.length-1;i>=0;i--){
	arr.push(str(i));
}

for(var j=0;j<arr.length;j++){
	ustr+=arr[j];
}

console.log(ustr);

var str="hello world";
function Reverse(str){
	if (str.Length == 1)
	return str;
	else
	return str.Substring(1).Reverse() + str[0];
}

