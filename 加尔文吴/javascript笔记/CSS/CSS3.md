1：width与min-width、max-width的区别
答：max-width的作用就是限制最大宽度，width大于max-width的话max-width就取代了width的值，width小于max-width的话，宽度就是width，max-width是限制作用
min-width 属性设置元素的最小宽度
JavaScript 语法：        object.style.minWidth="50px"
值        描述
length   定义元素的最小宽度值。默认值：取决于浏览器。
%        定义基于包含它的块级对象的百分比最小宽度。
inherit  规定应该从父元素继承 min-width 属性的值。

max-width 定义元素的最大宽度
JavaScript 语法：        object.style.maxWidth="50px"
值        描述
none      默认。定义对元素的最大宽度没有限制。
length    定义元素的最大宽度值。
%         定义基于包含它的块级对象的百分比最大宽度。
inherit   规定应该从父元素继承 max-width 属性的值。

2：outline的作用
outline （轮廓）是绘制于元素周围的一条线，位于边框边缘的外围，可起到突出元素的作用。
注释：轮廓线不会占据空间，也不一定是矩形。
outline 简写属性在一个声明中设置所有的轮廓属性。
可以按顺序设置如下属性：
outline-color
outline-style
outline-width
如果不设置其中的某个值，也不会出问题，比如 outline:solid #ff0000; 也是允许的。

3：box-shadow的作用
.box-shadow{  
  
         //Firefox4.0-  
  
         -moz-box-shadow:投影方式 X轴偏移量 Y轴偏移量阴影模糊半径 阴影扩展半径 阴影颜色;  
  
         //Safariand Google chrome10.0-  
  
         -webkit-box-shadow:投影方式 X轴偏移量 Y轴偏移量阴影模糊半径 阴影扩展半径 阴影颜色;  
  
         //Firefox4.0+、 Google chrome 10.0+ 、 Oprea10.5+ and IE9  
  
         box-shadow:  投影方式 X轴偏移量 Y轴偏移量 阴影模糊半径 阴影扩展半径 阴影颜色;  
  
}  

.box-shadow-2{  
  -webkit-box-shadow:0 0 10px #0CC;  
  -moz-box-shadow:0 0 10px #0CC;  
  box-shadow:0 0 10px #0CC;  
} 

4：appearance使用方法：

.elmClass{
   -webkit-appearance: value;
   -moz-appearance:    value;
   appearance:         value;
}

http://www.w3cplus.com/css3/changing-appearance-of-element-with-css3.html
http://www.css88.com/book/css/properties/user-interface/appearance.htm

5：text-indent 首行缩进
文字相对于父元素缩进的距离

6：text-overflow
注意：overflow: hidden; text-overflow:ellipsis;white-space:nowrap;一定要一起用
1.一定要给容器定义宽度.
2.如果少了overflow: hidden;文字会横向撑到容易的外面
3.如果少了white-space:nowrap;文字会把容器的高度往下撑；即使你定义了高度，省略号也不会出现，多余的文字会被裁切掉
4.如果少了text-overflow:ellipsis;多余的文字会被裁切掉，就相当于你这样定义text-overflow:clip.
如果容器是table，当文字内容过多时，不换行，而是出现...
http://blog.sina.com.cn/s/blog_53d27b3a0100veuc.html


7：border-radius属性详解
用来实现圆角效果的，在没有border-radius之前 是用url的图片来解决的
http://www.cnblogs.com/wansimin/articles/4365040.html
http://blog.csdn.net/liuyan19891230/article/details/50724630

8：