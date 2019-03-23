function Person(){
	this.think=function(callback){
		console.log("thinking ~~~~~~");
		setTimeout(function(){
			callback();
		},5000);
	};

	this.anwser=function(){
		console.log("I am anwsering other question");
	}
}

var person=new Person();
person.think(function(){
	console.log("thinking 5 seconds get the right answer");
});

person.anwser();

//fs.readFile('./1.txt',function(){})
//fs.readFileSync('./1.txt')

/*
"thinking ~~~~~~"
I am anwsering other question
thinking 5 seconds get the right answer*/