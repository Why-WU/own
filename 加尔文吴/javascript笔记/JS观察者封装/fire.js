var EventTarget = function() {
    this._listener = {};
};

EventTarget.prototype = {
    constructor: this,
    addEvent: function(type, fn) {
        if (typeof type === "string" && typeof fn === "function") {
            if (typeof this._listener[type] === "undefined") {
                this._listener[type] = [fn];
            } else {
                this._listener[type].push(fn);
            }
        }
        return this;
    },
    addEvents: function(obj) {
        obj = typeof obj === "object"? obj : {};
        var type;
        for (type in obj) {
            if ( type && typeof obj[type] === "function") {
                this.addEvent(type, obj[type]);
            }
        }
        return this;
    },
    fireEvent: function(type) {
        if (type && this._listener[type]) {
            //event参数设置
            var events = {
                type: type,
                target: this
            };

            for (var length = this._listener[type].length, start=0; start<length; start+=1) {
                //改变this指向
                this._listener[type][start].call(this, events);
            }
        }
        return this;
    },
    fireEvents: function(array) {
        if (array instanceof Array) {
            for (var i=0, length = array.length; i<length; i+=1) {
                this.fireEvent(array[i]);
            }
        }
        return this;
    },
    removeEvent: function(type, key) {
        var listeners = this._listener[type];
        if (listeners instanceof Array) {
            if (typeof key === "function") {
                for (var i=0, length=listeners.length; i<length; i+=1){
                    if (listeners[i] === key){
                        listeners.splice(i, 1);
                        break;
                    }
                }
            } else if (key instanceof Array) {
                for (var lis=0, lenkey = key.length; lis<lenkey; lis+=1) {
                    this.removeEvent(type, key[lenkey]);
                }
            } else {
                delete this._listener[type];
            }
        }
        return this;
    },
    removeEvents: function(params) {
        if (params instanceof Array) {
            for (var i=0, length = params.length; i<length; i+=1) {
                this.removeEvent(params[i]);
            }
        } else if (typeof params === "object") {
            for (var type in params) {
                this.removeEvent(type, params[type]);
            }
        }
        return this;
    }
};


var myEvents = new EventTarget();
myEvents.addEvents({
    "once": function() {
        alert("该弹框只会出现一次！");    
        this.removeEvent("once");
    },
    "infinity": function() {
        alert("每次点击页面，该弹框都会出现！");    
    }
});

document.onclick = function(e) {
    e = e || window.event;
    var target = e.target || e.srcElement;
    if (!target || !/input|pre/i.test(target.tagName)) {
        myEvents.fireEvents(["once", "infinity"]);
    }
};