setTimeout(function C() {
    console.log(3);
}, 0);
process.nextTick(function A() {
    console.log(1);
    process.nextTick(function B(){console.log(2);});
});