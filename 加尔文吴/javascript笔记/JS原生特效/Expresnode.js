Express   M-V-C

M cmodel.js

funcntion cmodel(){

}

cmodel.prototype.get_all=function(username,callback){

}

Controller

var Cmodel=require('../model/cmodel.js');


requrie 把文件转化成模块 1:加载系统模块  2：加载自定义模块 3：加载第三方模块

var fs=require('fs');  不需要写路径 直接写模块名
存放系统模块和第三方模块的路径  node_module

如何把第三方模块 系统模块 全局 安装在全局路径下的node_module

npm install 包名  当前路径下的node_module
npm install -g 包名 安装在系统路径下的node_module
npm install 包名  -save  package.json写入包的版本号 
dependice   dev-dependice

npm cnpm bower yoman bower.json

npm uninstall 包名
npm search 包名
npm init  创建一个包   npmjs.com 有npm使用文档

var http=require('http')  http.js  http文件夹下面的index.js
var ss=require('cc.js')

选择使用express 写web 比原生node有什么好处
1：结构清晰
2：writeHead end express高度封装了http下的原生方法
   处理get post操作有高级函数res.render res.send res.redirect
3：提供了静态资源管理器 发送css js image 或其他二进制文件
   Content-type

入口文件：全局环境变量设置、加载所需的第三方模块、加载静态资源管理器
          加载路由、默认系统设置、加载模板解析
路由文件：app.post/get(url,控制器名/方法名)

cookie-session：用于处理cookie session 
moment：用于处理js 时间
formidable、express-formidable：node下处理上传
async：处理异步深渊
mysql：处理数据库包

apache：80 http  https 443 mysql 3306 php.ini(error_reporting、upload max、session)
//gd gd2

var http=require('http');

http.createServer(function(req,res){
	res.writeHead(200,{'Content-type':'text/html'});
	res.end('<h1>hello</h1>');
}).listen(3000);
MIME--409

site_url  读取网络源地址
c:\12\123.txt  本地源地址  getcwd()  __FILES__
move_upload_file(base address,str address)

ngnix  反向代理 

var ss=require('../aa/cc.js');  写绝对路径

cmodel.js   exports  module.exports  把类公布给外部 把方法公布给外部  ----CommonJS规范

Cmodel.get_all(username,function(err,data){

})

