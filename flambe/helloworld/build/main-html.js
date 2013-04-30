(function () { "use strict";
var $hxClasses = {},$estr = function() { return js.Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	return proto;
}
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
$hxClasses["EReg"] = EReg;
EReg.__name__ = ["EReg"];
EReg.prototype = {
	match: function(s) {
		if(this.r.global) this.r.lastIndex = 0;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,__class__: EReg
}
var Hash = function() {
	this.h = { };
};
$hxClasses["Hash"] = Hash;
Hash.__name__ = ["Hash"];
Hash.prototype = {
	iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref["$" + i];
		}};
	}
	,keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key.substr(1));
		}
		return HxOverrides.iter(a);
	}
	,remove: function(key) {
		key = "$" + key;
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,exists: function(key) {
		return this.h.hasOwnProperty("$" + key);
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,set: function(key,value) {
		this.h["$" + key] = value;
	}
	,__class__: Hash
}
var HelloworldMain = function() { }
$hxClasses["HelloworldMain"] = HelloworldMain;
HelloworldMain.__name__ = ["HelloworldMain"];
HelloworldMain.onSuccess = function(pack) {
}
HelloworldMain.main = function() {
	flambe.System.init();
	var manifest = flambe.asset.Manifest.build("bootstrap");
	var loader = flambe.System.loadAssetPack(manifest);
	loader.get(HelloworldMain.onSuccess);
}
var HxOverrides = function() { }
$hxClasses["HxOverrides"] = HxOverrides;
HxOverrides.__name__ = ["HxOverrides"];
HxOverrides.dateStr = function(date) {
	var m = date.getMonth() + 1;
	var d = date.getDate();
	var h = date.getHours();
	var mi = date.getMinutes();
	var s = date.getSeconds();
	return date.getFullYear() + "-" + (m < 10?"0" + m:"" + m) + "-" + (d < 10?"0" + d:"" + d) + " " + (h < 10?"0" + h:"" + h) + ":" + (mi < 10?"0" + mi:"" + mi) + ":" + (s < 10?"0" + s:"" + s);
}
HxOverrides.strDate = function(s) {
	switch(s.length) {
	case 8:
		var k = s.split(":");
		var d = new Date();
		d.setTime(0);
		d.setUTCHours(k[0]);
		d.setUTCMinutes(k[1]);
		d.setUTCSeconds(k[2]);
		return d;
	case 10:
		var k = s.split("-");
		return new Date(k[0],k[1] - 1,k[2],0,0,0);
	case 19:
		var k = s.split(" ");
		var y = k[0].split("-");
		var t = k[1].split(":");
		return new Date(y[0],y[1] - 1,y[2],t[0],t[1],t[2]);
	default:
		throw "Invalid date format : " + s;
	}
}
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
}
HxOverrides.remove = function(a,obj) {
	var i = 0;
	var l = a.length;
	while(i < l) {
		if(a[i] == obj) {
			a.splice(i,1);
			return true;
		}
		i++;
	}
	return false;
}
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
}
var IntHash = function() {
	this.h = { };
};
$hxClasses["IntHash"] = IntHash;
IntHash.__name__ = ["IntHash"];
IntHash.prototype = {
	keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key | 0);
		}
		return HxOverrides.iter(a);
	}
	,remove: function(key) {
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,exists: function(key) {
		return this.h.hasOwnProperty(key);
	}
	,get: function(key) {
		return this.h[key];
	}
	,set: function(key,value) {
		this.h[key] = value;
	}
	,__class__: IntHash
}
var Lambda = function() { }
$hxClasses["Lambda"] = Lambda;
Lambda.__name__ = ["Lambda"];
Lambda.array = function(it) {
	var a = new Array();
	var $it0 = $iterator(it)();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		a.push(i);
	}
	return a;
}
Lambda.has = function(it,elt,cmp) {
	if(cmp == null) {
		var $it0 = $iterator(it)();
		while( $it0.hasNext() ) {
			var x = $it0.next();
			if(x == elt) return true;
		}
	} else {
		var $it1 = $iterator(it)();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			if(cmp(x,elt)) return true;
		}
	}
	return false;
}
Lambda.count = function(it,pred) {
	var n = 0;
	if(pred == null) {
		var $it0 = $iterator(it)();
		while( $it0.hasNext() ) {
			var _ = $it0.next();
			n++;
		}
	} else {
		var $it1 = $iterator(it)();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			if(pred(x)) n++;
		}
	}
	return n;
}
var List = function() {
	this.length = 0;
};
$hxClasses["List"] = List;
List.__name__ = ["List"];
List.prototype = {
	iterator: function() {
		return { h : this.h, hasNext : function() {
			return this.h != null;
		}, next : function() {
			if(this.h == null) return null;
			var x = this.h[0];
			this.h = this.h[1];
			return x;
		}};
	}
	,add: function(item) {
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
	}
	,__class__: List
}
var Reflect = function() { }
$hxClasses["Reflect"] = Reflect;
Reflect.__name__ = ["Reflect"];
Reflect.field = function(o,field) {
	var v = null;
	try {
		v = o[field];
	} catch( e ) {
	}
	return v;
}
Reflect.setField = function(o,field,value) {
	o[field] = value;
}
Reflect.callMethod = function(o,func,args) {
	return func.apply(o,args);
}
Reflect.fields = function(o) {
	var a = [];
	if(o != null) {
		var hasOwnProperty = Object.prototype.hasOwnProperty;
		for( var f in o ) {
		if(hasOwnProperty.call(o,f)) a.push(f);
		}
	}
	return a;
}
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(js.Boot.isClass(f) || js.Boot.isEnum(f));
}
var Std = function() { }
$hxClasses["Std"] = Std;
Std.__name__ = ["Std"];
Std["is"] = function(v,t) {
	return js.Boot.__instanceof(v,t);
}
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
}
Std["int"] = function(x) {
	return x | 0;
}
Std.parseFloat = function(x) {
	return parseFloat(x);
}
var StringBuf = function() {
	this.b = "";
};
$hxClasses["StringBuf"] = StringBuf;
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	toString: function() {
		return this.b;
	}
	,add: function(x) {
		this.b += Std.string(x);
	}
	,__class__: StringBuf
}
var StringTools = function() { }
$hxClasses["StringTools"] = StringTools;
StringTools.__name__ = ["StringTools"];
StringTools.urlEncode = function(s) {
	return encodeURIComponent(s);
}
StringTools.urlDecode = function(s) {
	return decodeURIComponent(s.split("+").join(" "));
}
StringTools.startsWith = function(s,start) {
	return s.length >= start.length && HxOverrides.substr(s,0,start.length) == start;
}
StringTools.fastCodeAt = function(s,index) {
	return s.charCodeAt(index);
}
StringTools.isEOF = function(c) {
	return c != c;
}
var ValueType = $hxClasses["ValueType"] = { __ename__ : ["ValueType"], __constructs__ : ["TNull","TInt","TFloat","TBool","TObject","TFunction","TClass","TEnum","TUnknown"] }
ValueType.TNull = ["TNull",0];
ValueType.TNull.toString = $estr;
ValueType.TNull.__enum__ = ValueType;
ValueType.TInt = ["TInt",1];
ValueType.TInt.toString = $estr;
ValueType.TInt.__enum__ = ValueType;
ValueType.TFloat = ["TFloat",2];
ValueType.TFloat.toString = $estr;
ValueType.TFloat.__enum__ = ValueType;
ValueType.TBool = ["TBool",3];
ValueType.TBool.toString = $estr;
ValueType.TBool.__enum__ = ValueType;
ValueType.TObject = ["TObject",4];
ValueType.TObject.toString = $estr;
ValueType.TObject.__enum__ = ValueType;
ValueType.TFunction = ["TFunction",5];
ValueType.TFunction.toString = $estr;
ValueType.TFunction.__enum__ = ValueType;
ValueType.TClass = function(c) { var $x = ["TClass",6,c]; $x.__enum__ = ValueType; $x.toString = $estr; return $x; }
ValueType.TEnum = function(e) { var $x = ["TEnum",7,e]; $x.__enum__ = ValueType; $x.toString = $estr; return $x; }
ValueType.TUnknown = ["TUnknown",8];
ValueType.TUnknown.toString = $estr;
ValueType.TUnknown.__enum__ = ValueType;
var Type = function() { }
$hxClasses["Type"] = Type;
Type.__name__ = ["Type"];
Type.getClassName = function(c) {
	var a = c.__name__;
	return a.join(".");
}
Type.getEnumName = function(e) {
	var a = e.__ename__;
	return a.join(".");
}
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || !js.Boot.isClass(cl)) return null;
	return cl;
}
Type.resolveEnum = function(name) {
	var e = $hxClasses[name];
	if(e == null || !js.Boot.isEnum(e)) return null;
	return e;
}
Type.createEmptyInstance = function(cl) {
	function empty() {}; empty.prototype = cl.prototype;
	return new empty();
}
Type.createEnum = function(e,constr,params) {
	var f = Reflect.field(e,constr);
	if(f == null) throw "No such constructor " + constr;
	if(Reflect.isFunction(f)) {
		if(params == null) throw "Constructor " + constr + " need parameters";
		return Reflect.callMethod(e,f,params);
	}
	if(params != null && params.length != 0) throw "Constructor " + constr + " does not need parameters";
	return f;
}
Type.getEnumConstructs = function(e) {
	var a = e.__constructs__;
	return a.slice();
}
Type["typeof"] = function(v) {
	switch(typeof(v)) {
	case "boolean":
		return ValueType.TBool;
	case "string":
		return ValueType.TClass(String);
	case "number":
		if(Math.ceil(v) == v % 2147483648.0) return ValueType.TInt;
		return ValueType.TFloat;
	case "object":
		if(v == null) return ValueType.TNull;
		var e = v.__enum__;
		if(e != null) return ValueType.TEnum(e);
		var c = js.Boot.getClass(v);
		if(c != null) return ValueType.TClass(c);
		return ValueType.TObject;
	case "function":
		if(js.Boot.isClass(v) || js.Boot.isEnum(v)) return ValueType.TObject;
		return ValueType.TFunction;
	case "undefined":
		return ValueType.TNull;
	default:
		return ValueType.TUnknown;
	}
}
var flambe = {}
flambe.util = {}
flambe.util.Disposable = function() { }
$hxClasses["flambe.util.Disposable"] = flambe.util.Disposable;
flambe.util.Disposable.__name__ = ["flambe","util","Disposable"];
flambe.util.Disposable.prototype = {
	__class__: flambe.util.Disposable
}
flambe.Component = function() { }
$hxClasses["flambe.Component"] = flambe.Component;
flambe.Component.__name__ = ["flambe","Component"];
flambe.Component.__interfaces__ = [flambe.util.Disposable];
flambe.Component.prototype = {
	_internal_init: function(owner,next) {
		this.owner = owner;
		this.next = next;
	}
	,get_name: function() {
		return null;
	}
	,dispose: function() {
		if(this.owner != null) this.owner.remove(this);
	}
	,onUpdate: function(dt) {
	}
	,onRemoved: function() {
	}
	,onAdded: function() {
	}
	,__class__: flambe.Component
}
flambe.Entity = function() {
	this.firstComponent = null;
	this.next = null;
	this.firstChild = null;
	this.parent = null;
	this._compMap = { };
};
$hxClasses["flambe.Entity"] = flambe.Entity;
flambe.Entity.__name__ = ["flambe","Entity"];
flambe.Entity.__interfaces__ = [flambe.util.Disposable];
flambe.Entity.prototype = {
	toStringImpl: function(indent) {
		var output = "";
		var p = this.firstComponent;
		while(p != null) {
			output += p.get_name();
			if(p.next != null) output += ", ";
			p = p.next;
		}
		output += "\n";
		var u2514 = String.fromCharCode(9492);
		var u241c = String.fromCharCode(9500);
		var u2500 = String.fromCharCode(9472);
		var u2502 = String.fromCharCode(9474);
		var p1 = this.firstChild;
		while(p1 != null) {
			var last = p1.next == null;
			output += indent + (last?u2514:u241c) + u2500 + u2500 + " ";
			output += p1.toStringImpl(indent + (last?" ":u2502) + "   ");
			p1 = p1.next;
		}
		return output;
	}
	,toString: function() {
		return this.toStringImpl("");
	}
	,dispose: function() {
		if(this.parent != null) this.parent.removeChild(this);
		while(this.firstComponent != null) this.firstComponent.dispose();
		this.disposeChildren();
	}
	,disposeChildren: function() {
		while(this.firstChild != null) this.firstChild.dispose();
	}
	,removeChild: function(entity) {
		var prev = null, p = this.firstChild;
		while(p != null) {
			var next = p.next;
			if(p == entity) {
				if(prev == null) this.firstChild = next; else prev.next = next;
				p.parent = null;
				p.next = null;
				return;
			}
			prev = p;
			p = next;
		}
	}
	,addChild: function(entity,append) {
		if(append == null) append = true;
		if(entity.parent != null) entity.parent.removeChild(entity);
		entity.parent = this;
		if(append) {
			var tail = null, p = this.firstChild;
			while(p != null) {
				tail = p;
				p = p.next;
			}
			if(tail != null) tail.next = entity; else this.firstChild = entity;
		} else {
			entity.next = this.firstChild;
			this.firstChild = entity;
		}
		return this;
	}
	,getComponent: function(name) {
		return this._compMap[name];
	}
	,remove: function(component) {
		var prev = null, p = this.firstComponent;
		while(p != null) {
			var next = p.next;
			if(p == component) {
				if(prev == null) this.firstComponent = next; else prev._internal_init(this,next);
				delete(this._compMap[p.get_name()]);
				p.onRemoved();
				p._internal_init(null,null);
				return;
			}
			prev = p;
			p = next;
		}
	}
	,__class__: flambe.Entity
}
flambe.util.PackageLog = function() { }
$hxClasses["flambe.util.PackageLog"] = flambe.util.PackageLog;
flambe.util.PackageLog.__name__ = ["flambe","util","PackageLog"];
flambe.platform = {}
flambe.platform.Platform = function() { }
$hxClasses["flambe.platform.Platform"] = flambe.platform.Platform;
flambe.platform.Platform.__name__ = ["flambe","platform","Platform"];
flambe.platform.Platform.prototype = {
	__class__: flambe.platform.Platform
}
flambe.platform.html = {}
flambe.platform.html.HtmlPlatform = function() {
};
$hxClasses["flambe.platform.html.HtmlPlatform"] = flambe.platform.html.HtmlPlatform;
flambe.platform.html.HtmlPlatform.__name__ = ["flambe","platform","html","HtmlPlatform"];
flambe.platform.html.HtmlPlatform.__interfaces__ = [flambe.platform.Platform];
flambe.platform.html.HtmlPlatform.prototype = {
	createRenderer: function(canvas) {
		return new flambe.platform.html.CanvasRenderer(canvas);
	}
	,getY: function(event,bounds) {
		return this._stage.scaleFactor * (event.clientY - bounds.top);
	}
	,getX: function(event,bounds) {
		return this._stage.scaleFactor * (event.clientX - bounds.left);
	}
	,getRenderer: function() {
		return this._renderer;
	}
	,getExternal: function() {
		if(this._external == null) this._external = new flambe.platform.html.HtmlExternal();
		return this._external;
	}
	,getWeb: function() {
		if(this._web == null) this._web = new flambe.platform.html.HtmlWeb(this._container);
		return this._web;
	}
	,getKeyboard: function() {
		return this._keyboard;
	}
	,getTouch: function() {
		return this._touch;
	}
	,getMouse: function() {
		return this._mouse;
	}
	,getPointer: function() {
		return this._pointer;
	}
	,update: function(now) {
		var dt = (now - this._lastUpdate) / 1000;
		this._lastUpdate = now;
		if(this._skipFrame) {
			this._skipFrame = false;
			return;
		}
		this.mainLoop.update(dt);
		this.mainLoop.render(this._renderer);
	}
	,getTime: function() {
		return flambe.platform.html.HtmlUtil.now() / 1000;
	}
	,createLogHandler: function(tag) {
		if(flambe.platform.html.HtmlLogHandler.isSupported()) return new flambe.platform.html.HtmlLogHandler(tag);
		return null;
	}
	,getLocale: function() {
		return js.Lib.window.navigator.language;
	}
	,getStorage: function() {
		if(this._storage == null) {
			var localStorage = null;
			try {
				localStorage = js.Lib.window.localStorage;
			} catch( error ) {
			}
			if(localStorage != null) this._storage = new flambe.platform.html.HtmlStorage(localStorage); else {
				flambe.Log.warn("localStorage is unavailable, falling back to unpersisted storage");
				this._storage = new flambe.platform.DummyStorage();
			}
		}
		return this._storage;
	}
	,getStage: function() {
		return this._stage;
	}
	,loadAssetPack: function(manifest) {
		return new flambe.platform.html.HtmlAssetPackLoader(this,manifest).promise;
	}
	,init: function() {
		var _g = this;
		flambe.Log.info("Initializing HTML platform");
		var canvas = null;
		try {
			canvas = js.Lib.window.flambe.canvas;
		} catch( error ) {
		}
		flambe.util.Assert.that(canvas != null,"Could not find a Flambe canvas! Are you embedding with flambe.js?");
		canvas.setAttribute("tabindex","0");
		canvas.style.outlineStyle = "none";
		canvas.setAttribute("moz-opaque","true");
		this._stage = new flambe.platform.html.HtmlStage(canvas);
		this._pointer = new flambe.platform.BasicPointer();
		this._mouse = new flambe.platform.html.HtmlMouse(this._pointer,canvas);
		this._keyboard = new flambe.platform.BasicKeyboard();
		this._renderer = this.createRenderer(canvas);
		flambe.System.hasGPU.set__(true);
		this.mainLoop = new flambe.platform.MainLoop();
		this._container = canvas.parentNode;
		this._container.style.overflow = "hidden";
		this._container.style.position = "relative";
		this._container.style.msTouchAction = "none";
		var lastTouchTime = 0;
		var onMouse = function(event) {
			if(event.timeStamp - lastTouchTime < 1000) return;
			var bounds = canvas.getBoundingClientRect();
			var x = _g.getX(event,bounds);
			var y = _g.getY(event,bounds);
			switch(event.type) {
			case "mousedown":
				if(event.target == canvas) {
					event.preventDefault();
					_g._mouse.submitDown(x,y,event.button);
					event.target.focus();
				}
				break;
			case "mousemove":
				_g._mouse.submitMove(x,y);
				break;
			case "mouseup":
				_g._mouse.submitUp(x,y,event.button);
				break;
			case "mousewheel":case "DOMMouseScroll":
				var velocity = event.type == "mousewheel"?event.wheelDelta / 40:-event.detail;
				if(_g._mouse.submitScroll(x,y,velocity)) event.preventDefault();
				break;
			}
		};
		window.addEventListener("mousedown",onMouse,false);
		window.addEventListener("mousemove",onMouse,false);
		window.addEventListener("mouseup",onMouse,false);
		canvas.addEventListener("mousewheel",onMouse,false);
		canvas.addEventListener("DOMMouseScroll",onMouse,false);
		var standardTouch = 'ontouchstart' in window;
		var msTouch = 'msMaxTouchPoints' in window.navigator && (window.navigator.msMaxTouchPoints > 1);
		if(standardTouch || msTouch) {
			var basicTouch = new flambe.platform.BasicTouch(this._pointer,msTouch?window.navigator.msMaxTouchPoints:4);
			this._touch = basicTouch;
			var onTouch = function(event) {
				var changedTouches = standardTouch?event.changedTouches:[event];
				var bounds = event.target.getBoundingClientRect();
				lastTouchTime = event.timeStamp;
				switch(event.type) {
				case "touchstart":case "MSPointerDown":
					event.preventDefault();
					if(flambe.platform.html.HtmlUtil.SHOULD_HIDE_MOBILE_BROWSER) flambe.platform.html.HtmlUtil.hideMobileBrowser();
					var _g1 = 0;
					while(_g1 < changedTouches.length) {
						var touch = changedTouches[_g1];
						++_g1;
						var x = _g.getX(touch,bounds);
						var y = _g.getY(touch,bounds);
						var id = Std["int"](standardTouch?touch.identifier:touch.pointerId);
						basicTouch.submitDown(id,x,y);
					}
					break;
				case "touchmove":case "MSPointerMove":
					event.preventDefault();
					var _g1 = 0;
					while(_g1 < changedTouches.length) {
						var touch = changedTouches[_g1];
						++_g1;
						var x = _g.getX(touch,bounds);
						var y = _g.getY(touch,bounds);
						var id = Std["int"](standardTouch?touch.identifier:touch.pointerId);
						basicTouch.submitMove(id,x,y);
					}
					break;
				case "touchend":case "touchcancel":case "MSPointerUp":
					var _g1 = 0;
					while(_g1 < changedTouches.length) {
						var touch = changedTouches[_g1];
						++_g1;
						var x = _g.getX(touch,bounds);
						var y = _g.getY(touch,bounds);
						var id = Std["int"](standardTouch?touch.identifier:touch.pointerId);
						basicTouch.submitUp(id,x,y);
					}
					break;
				}
			};
			if(standardTouch) {
				canvas.addEventListener("touchstart",onTouch,false);
				canvas.addEventListener("touchmove",onTouch,false);
				canvas.addEventListener("touchend",onTouch,false);
				canvas.addEventListener("touchcancel",onTouch,false);
			} else {
				canvas.addEventListener("MSPointerDown",onTouch,false);
				canvas.addEventListener("MSPointerMove",onTouch,false);
				canvas.addEventListener("MSPointerUp",onTouch,false);
			}
		} else this._touch = new flambe.platform.DummyTouch();
		var onKey = function(event) {
			switch(event.type) {
			case "keydown":
				if(_g._keyboard.submitDown(event.keyCode)) event.preventDefault();
				break;
			case "keyup":
				_g._keyboard.submitUp(event.keyCode);
				break;
			}
		};
		canvas.addEventListener("keydown",onKey,false);
		canvas.addEventListener("keyup",onKey,false);
		var oldErrorHandler = js.Lib.window.onerror;
		js.Lib.window.onerror = function(message,url,line) {
			flambe.System.uncaughtError.emit(message);
			return oldErrorHandler != null?oldErrorHandler(message,url,line):false;
		};
		var hiddenApi = flambe.platform.html.HtmlUtil.loadExtension("hidden",js.Lib.document);
		if(hiddenApi.value != null) {
			var onVisibilityChanged = function() {
				flambe.System.hidden.set__(Reflect.field(js.Lib.document,hiddenApi.field));
			};
			onVisibilityChanged();
			js.Lib.document.addEventListener(hiddenApi.prefix + "visibilitychange",onVisibilityChanged,false);
			flambe.System.hidden.get_changed().connect(function(hidden,_) {
				if(!hidden) _g._skipFrame = true;
			});
		}
		this._lastUpdate = flambe.platform.html.HtmlUtil.now();
		this._skipFrame = false;
		var requestAnimationFrame = flambe.platform.html.HtmlUtil.loadExtension("requestAnimationFrame").value;
		if(requestAnimationFrame != null) {
			var performance = js.Lib.window.performance;
			var hasPerfNow = performance != null && flambe.platform.html.HtmlUtil.polyfill("now",performance);
			if(hasPerfNow) this._lastUpdate = performance.now(); else flambe.Log.warn("No monotonic timer support, falling back to the system date");
			var updateFrame = null;
			updateFrame = function(now) {
				_g.update(hasPerfNow?performance.now():now);
				requestAnimationFrame(updateFrame,canvas);
			};
			requestAnimationFrame(updateFrame,canvas);
		} else {
			flambe.Log.warn("No requestAnimationFrame support, falling back to setInterval");
			js.Lib.window.setInterval(function() {
				_g.update(flambe.platform.html.HtmlUtil.now());
			},1000 / 60);
		}
	}
	,__class__: flambe.platform.html.HtmlPlatform
}
flambe.util.Value = function(value,listener) {
	this._value = value;
	if(listener != null) this._changed = new flambe.util.Signal2(listener);
};
$hxClasses["flambe.util.Value"] = flambe.util.Value;
flambe.util.Value.__name__ = ["flambe","util","Value"];
flambe.util.Value.prototype = {
	toString: function() {
		return this._value;
	}
	,get_changed: function() {
		if(this._changed == null) this._changed = new flambe.util.Signal2();
		return this._changed;
	}
	,set__: function(newValue) {
		var oldValue = this._value;
		if(newValue != oldValue) {
			this._value = newValue;
			if(this._changed != null) this._changed.emit(newValue,oldValue);
		}
		return newValue;
	}
	,get__: function() {
		return this._value;
	}
	,watch: function(listener) {
		listener(this._value,this._value);
		return this.get_changed().connect(listener);
	}
	,__class__: flambe.util.Value
}
flambe.util.SignalConnection = function(signal,listener) {
	this._internal_next = null;
	this._signal = signal;
	this._internal_listener = listener;
	this.stayInList = true;
};
$hxClasses["flambe.util.SignalConnection"] = flambe.util.SignalConnection;
flambe.util.SignalConnection.__name__ = ["flambe","util","SignalConnection"];
flambe.util.SignalConnection.__interfaces__ = [flambe.util.Disposable];
flambe.util.SignalConnection.prototype = {
	dispose: function() {
		if(this._signal != null) {
			this._signal._internal_disconnect(this);
			this._signal = null;
		}
	}
	,once: function() {
		this.stayInList = false;
		return this;
	}
	,__class__: flambe.util.SignalConnection
}
flambe.util.SignalBase = function(listener) {
	this._head = listener != null?new flambe.util.SignalConnection(this,listener):null;
	this._deferredTasks = null;
};
$hxClasses["flambe.util.SignalBase"] = flambe.util.SignalBase;
flambe.util.SignalBase.__name__ = ["flambe","util","SignalBase"];
flambe.util.SignalBase.prototype = {
	dispatching: function() {
		return this._head == flambe.util.SignalBase.DISPATCHING_SENTINEL;
	}
	,listRemove: function(conn) {
		var prev = null, p = this._head;
		while(p != null) {
			if(p == conn) {
				var next = p._internal_next;
				if(prev == null) this._head = next; else prev._internal_next = next;
				return;
			}
			prev = p;
			p = p._internal_next;
		}
	}
	,listAdd: function(conn,prioritize) {
		if(prioritize) {
			conn._internal_next = this._head;
			this._head = conn;
		} else {
			var tail = null, p = this._head;
			while(p != null) {
				tail = p;
				p = p._internal_next;
			}
			if(tail != null) tail._internal_next = conn; else this._head = conn;
		}
	}
	,didEmit: function(head) {
		this._head = head;
		while(this._deferredTasks != null) {
			this._deferredTasks.fn();
			this._deferredTasks = this._deferredTasks.next;
		}
	}
	,willEmit: function() {
		flambe.util.Assert.that(!this.dispatching(),"Cannot emit while already emitting!");
		var snapshot = this._head;
		this._head = flambe.util.SignalBase.DISPATCHING_SENTINEL;
		return snapshot;
	}
	,defer: function(fn) {
		var tail = null, p = this._deferredTasks;
		while(p != null) {
			tail = p;
			p = p.next;
		}
		var task = new flambe.util._SignalBase.Task(fn);
		if(tail != null) tail.next = task; else this._deferredTasks = task;
	}
	,emit2: function(arg1,arg2) {
		var head = this.willEmit();
		var p = head;
		while(p != null) {
			p._internal_listener(arg1,arg2);
			if(!p.stayInList) p.dispose();
			p = p._internal_next;
		}
		this.didEmit(head);
	}
	,emit1: function(arg1) {
		var head = this.willEmit();
		var p = head;
		while(p != null) {
			p._internal_listener(arg1);
			if(!p.stayInList) p.dispose();
			p = p._internal_next;
		}
		this.didEmit(head);
	}
	,emit0: function() {
		var head = this.willEmit();
		var p = head;
		while(p != null) {
			p._internal_listener();
			if(!p.stayInList) p.dispose();
			p = p._internal_next;
		}
		this.didEmit(head);
	}
	,_internal_disconnect: function(conn) {
		var _g = this;
		if(this.dispatching()) this.defer(function() {
			_g.listRemove(conn);
		}); else this.listRemove(conn);
	}
	,connectImpl: function(listener,prioritize) {
		var _g = this;
		var conn = new flambe.util.SignalConnection(this,listener);
		if(this.dispatching()) this.defer(function() {
			_g.listAdd(conn,prioritize);
		}); else this.listAdd(conn,prioritize);
		return conn;
	}
	,hasListeners: function() {
		return this._head != null;
	}
	,__class__: flambe.util.SignalBase
}
flambe.util.Signal2 = function(listener) {
	flambe.util.SignalBase.call(this,listener);
};
$hxClasses["flambe.util.Signal2"] = flambe.util.Signal2;
flambe.util.Signal2.__name__ = ["flambe","util","Signal2"];
flambe.util.Signal2.__super__ = flambe.util.SignalBase;
flambe.util.Signal2.prototype = $extend(flambe.util.SignalBase.prototype,{
	emit: function(arg1,arg2) {
		this.emit2(arg1,arg2);
	}
	,connect: function(listener,prioritize) {
		if(prioritize == null) prioritize = false;
		return this.connectImpl(listener,prioritize);
	}
	,__class__: flambe.util.Signal2
});
flambe.util.Signal1 = function(listener) {
	flambe.util.SignalBase.call(this,listener);
};
$hxClasses["flambe.util.Signal1"] = flambe.util.Signal1;
flambe.util.Signal1.__name__ = ["flambe","util","Signal1"];
flambe.util.Signal1.__super__ = flambe.util.SignalBase;
flambe.util.Signal1.prototype = $extend(flambe.util.SignalBase.prototype,{
	emit: function(arg1) {
		this.emit1(arg1);
	}
	,connect: function(listener,prioritize) {
		if(prioritize == null) prioritize = false;
		return this.connectImpl(listener,prioritize);
	}
	,__class__: flambe.util.Signal1
});
flambe.animation = {}
flambe.animation.AnimatedFloat = function(value,listener) {
	flambe.util.Value.call(this,value,listener);
};
$hxClasses["flambe.animation.AnimatedFloat"] = flambe.animation.AnimatedFloat;
flambe.animation.AnimatedFloat.__name__ = ["flambe","animation","AnimatedFloat"];
flambe.animation.AnimatedFloat.__super__ = flambe.util.Value;
flambe.animation.AnimatedFloat.prototype = $extend(flambe.util.Value.prototype,{
	set_behavior: function(behavior) {
		this._behavior = behavior;
		this.update(0);
		return behavior;
	}
	,update: function(dt) {
		if(this._behavior != null) {
			flambe.util.Value.prototype.set__.call(this,this._behavior.update(dt));
			if(this._behavior.isComplete()) this._behavior = null;
		}
	}
	,set__: function(value) {
		this._behavior = null;
		return flambe.util.Value.prototype.set__.call(this,value);
	}
	,__class__: flambe.animation.AnimatedFloat
});
flambe.System = function() { }
$hxClasses["flambe.System"] = flambe.System;
flambe.System.__name__ = ["flambe","System"];
flambe.System.init = function() {
	if(!flambe.System._calledInit) {
		flambe.System._platform.init();
		flambe.System._calledInit = true;
	}
}
flambe.System.loadAssetPack = function(manifest) {
	flambe.System.assertCalledInit();
	return flambe.System._platform.loadAssetPack(manifest);
}
flambe.System.createLogger = function(tag) {
	return new flambe.util.Logger(flambe.System._platform.createLogHandler(tag));
}
flambe.System.get_stage = function() {
	flambe.System.assertCalledInit();
	return flambe.System._platform.getStage();
}
flambe.System.assertCalledInit = function() {
	flambe.util.Assert.that(flambe.System._calledInit,"You must call System.init() first");
}
flambe.util.Logger = function(handler) {
	this._handler = handler;
};
$hxClasses["flambe.util.Logger"] = flambe.util.Logger;
flambe.util.Logger.__name__ = ["flambe","util","Logger"];
flambe.util.Logger.prototype = {
	log: function(level,text,args) {
		if(this._handler == null) return;
		if(text == null) text = "";
		if(args != null) text = flambe.util.Strings.withFields(text,args);
		this._handler.log(level,text);
	}
	,warn: function(text,args) {
		this.log(flambe.util.LogLevel.Warn,text,args);
	}
	,info: function(text,args) {
		this.log(flambe.util.LogLevel.Info,text,args);
	}
	,__class__: flambe.util.Logger
}
flambe.Log = function() { }
$hxClasses["flambe.Log"] = flambe.Log;
flambe.Log.__name__ = ["flambe","Log"];
flambe.Log.info = function(text,args) {
	flambe.Log.logger.info(text,args);
}
flambe.Log.warn = function(text,args) {
	flambe.Log.logger.warn(text,args);
}
flambe.Log.__super__ = flambe.util.PackageLog;
flambe.Log.prototype = $extend(flambe.util.PackageLog.prototype,{
	__class__: flambe.Log
});
flambe.SpeedAdjuster = function(scale) {
	if(scale == null) scale = 1;
	this._internal_realDt = 0;
	this.scale = new flambe.animation.AnimatedFloat(scale);
};
$hxClasses["flambe.SpeedAdjuster"] = flambe.SpeedAdjuster;
flambe.SpeedAdjuster.__name__ = ["flambe","SpeedAdjuster"];
flambe.SpeedAdjuster.getFrom = function(entity) {
	return entity.getComponent("SpeedAdjuster_3");
}
flambe.SpeedAdjuster.__super__ = flambe.Component;
flambe.SpeedAdjuster.prototype = $extend(flambe.Component.prototype,{
	onUpdate: function(dt) {
		if(this._internal_realDt > 0) {
			dt = this._internal_realDt;
			this._internal_realDt = 0;
		}
		this.scale.update(dt);
	}
	,get_name: function() {
		return "SpeedAdjuster_3";
	}
	,__class__: flambe.SpeedAdjuster
});
flambe.animation.Behavior = function() { }
$hxClasses["flambe.animation.Behavior"] = flambe.animation.Behavior;
flambe.animation.Behavior.__name__ = ["flambe","animation","Behavior"];
flambe.animation.Behavior.prototype = {
	__class__: flambe.animation.Behavior
}
flambe.animation.Binding = function() { }
$hxClasses["flambe.animation.Binding"] = flambe.animation.Binding;
flambe.animation.Binding.__name__ = ["flambe","animation","Binding"];
flambe.animation.Binding.__interfaces__ = [flambe.animation.Behavior];
flambe.animation.Binding.prototype = {
	isComplete: function() {
		return false;
	}
	,update: function(dt) {
		var value = this._target.get__();
		if(this._fn != null) return this._fn(value); else return value;
	}
	,__class__: flambe.animation.Binding
}
flambe.asset = {}
flambe.asset.AssetType = $hxClasses["flambe.asset.AssetType"] = { __ename__ : ["flambe","asset","AssetType"], __constructs__ : ["Image","Audio","Data"] }
flambe.asset.AssetType.Image = ["Image",0];
flambe.asset.AssetType.Image.toString = $estr;
flambe.asset.AssetType.Image.__enum__ = flambe.asset.AssetType;
flambe.asset.AssetType.Audio = ["Audio",1];
flambe.asset.AssetType.Audio.toString = $estr;
flambe.asset.AssetType.Audio.__enum__ = flambe.asset.AssetType;
flambe.asset.AssetType.Data = ["Data",2];
flambe.asset.AssetType.Data.toString = $estr;
flambe.asset.AssetType.Data.__enum__ = flambe.asset.AssetType;
flambe.asset.AssetEntry = function(name,url,type,bytes) {
	this.name = name;
	this.url = url;
	this.type = type;
	this.bytes = bytes;
};
$hxClasses["flambe.asset.AssetEntry"] = flambe.asset.AssetEntry;
flambe.asset.AssetEntry.__name__ = ["flambe","asset","AssetEntry"];
flambe.asset.AssetEntry.prototype = {
	getUrlExtension: function() {
		return flambe.util.Strings.getFileExtension(this.url.split("?")[0]).toLowerCase();
	}
	,__class__: flambe.asset.AssetEntry
}
flambe.asset.AssetPack = function() { }
$hxClasses["flambe.asset.AssetPack"] = flambe.asset.AssetPack;
flambe.asset.AssetPack.__name__ = ["flambe","asset","AssetPack"];
flambe.asset.AssetPack.prototype = {
	__class__: flambe.asset.AssetPack
}
var js = {}
js.Boot = function() { }
$hxClasses["js.Boot"] = js.Boot;
js.Boot.__name__ = ["js","Boot"];
js.Boot.isClass = function(o) {
	return o.__name__;
}
js.Boot.isEnum = function(e) {
	return e.__ename__;
}
js.Boot.getClass = function(o) {
	return o.__class__;
}
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (js.Boot.isClass(o) || js.Boot.isEnum(o))) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2, _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i;
			var str = "[";
			s += "\t";
			var _g = 0;
			while(_g < l) {
				var i1 = _g++;
				str += (i1 > 0?",":"") + js.Boot.__string_rec(o[i1],s);
			}
			str += "]";
			return str;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) { ;
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
}
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0, _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
}
js.Boot.__instanceof = function(o,cl) {
	try {
		if(o instanceof cl) {
			if(cl == Array) return o.__enum__ == null;
			return true;
		}
		if(js.Boot.__interfLoop(js.Boot.getClass(o),cl)) return true;
	} catch( e ) {
		if(cl == null) return false;
	}
	switch(cl) {
	case Int:
		return Math.ceil(o%2147483648.0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return o === true || o === false;
	case String:
		return typeof(o) == "string";
	case Dynamic:
		return true;
	default:
		if(o == null) return false;
		if(cl == Class && o.__name__ != null) return true; else null;
		if(cl == Enum && o.__ename__ != null) return true; else null;
		return o.__enum__ == cl;
	}
}
flambe.util.Strings = function() { }
$hxClasses["flambe.util.Strings"] = flambe.util.Strings;
flambe.util.Strings.__name__ = ["flambe","util","Strings"];
flambe.util.Strings.getFileExtension = function(fileName) {
	var dot = fileName.lastIndexOf(".");
	return dot > 0?HxOverrides.substr(fileName,dot + 1,null):null;
}
flambe.util.Strings.removeFileExtension = function(fileName) {
	var dot = fileName.lastIndexOf(".");
	return dot > 0?HxOverrides.substr(fileName,0,dot):fileName;
}
flambe.util.Strings.joinPath = function(base,relative) {
	if(StringTools.fastCodeAt(base,base.length - 1) != 47) base += "/";
	return base + relative;
}
flambe.util.Strings.withFields = function(message,fields) {
	var ll = fields.length;
	if(ll > 0) {
		message += message.length > 0?" [":"[";
		var ii = 0;
		while(ii < ll) {
			if(ii > 0) message += ", ";
			var name = fields[ii];
			var value = fields[ii + 1];
			if(Std["is"](value,Error)) {
				var stack = value.stack;
				if(stack != null) value = stack;
			}
			message += name + "=" + Std.string(value);
			ii += 2;
		}
		message += "]";
	}
	return message;
}
js.Lib = function() { }
$hxClasses["js.Lib"] = js.Lib;
js.Lib.__name__ = ["js","Lib"];
flambe.asset.Manifest = function() {
	this._entries = [];
};
$hxClasses["flambe.asset.Manifest"] = flambe.asset.Manifest;
flambe.asset.Manifest.__name__ = ["flambe","asset","Manifest"];
flambe.asset.Manifest.build = function(packName,required) {
	if(required == null) required = true;
	var manifest = flambe.asset.Manifest._buildManifest.get(packName);
	if(manifest == null) {
		if(required) throw flambe.util.Strings.withFields("Missing asset pack",["name",packName]);
		return null;
	}
	return manifest.clone();
}
flambe.asset.Manifest.inferType = function(url) {
	var extension = flambe.util.Strings.getFileExtension(url.split("?")[0]);
	if(extension != null) switch(extension.toLowerCase()) {
	case "png":case "jpg":case "gif":
		return flambe.asset.AssetType.Image;
	case "ogg":case "m4a":case "mp3":case "wav":
		return flambe.asset.AssetType.Audio;
	}
	return flambe.asset.AssetType.Data;
}
flambe.asset.Manifest.createBuildManifests = function() {
	var macroData = new Hash();
	macroData.set("bootstrap",[]);
	var manifests = new Hash();
	var $it0 = macroData.keys();
	while( $it0.hasNext() ) {
		var packName = $it0.next();
		var manifest = new flambe.asset.Manifest();
		manifest.set_relativeBasePath("assets");
		var _g = 0, _g1 = macroData.get(packName);
		while(_g < _g1.length) {
			var asset = _g1[_g];
			++_g;
			var name = asset.name;
			var path = packName + "/" + name + "?v=" + Std.string(asset.md5);
			var type = flambe.asset.Manifest.inferType(name);
			if(type == flambe.asset.AssetType.Image || type == flambe.asset.AssetType.Audio) name = flambe.util.Strings.removeFileExtension(name);
			manifest.add(name,path,asset.bytes,type);
		}
		manifests.set(packName,manifest);
	}
	return manifests;
}
flambe.asset.Manifest.prototype = {
	set_externalBasePath: function(basePath) {
		this._externalBasePath = basePath;
		if(basePath != null) flambe.util.Assert.that(StringTools.startsWith(basePath,"http://") || StringTools.startsWith(basePath,"https://"),"externalBasePath must be on an external domain, starting with http(s)://");
		return basePath;
	}
	,get_externalBasePath: function() {
		return this._externalBasePath;
	}
	,set_relativeBasePath: function(basePath) {
		this._relativeBasePath = basePath;
		if(basePath != null) flambe.util.Assert.that(!StringTools.startsWith(basePath,"http://") && !StringTools.startsWith(basePath,"https://"),"relativeBasePath must be a relative path on the same domain, NOT starting with http(s)://");
		return basePath;
	}
	,get_relativeBasePath: function() {
		return this._relativeBasePath;
	}
	,getFullURL: function(entry) {
		var restricted = this.get_externalBasePath() != null && flambe.asset.Manifest._supportsCrossOrigin?this.get_externalBasePath():this.get_relativeBasePath();
		var unrestricted = this.get_externalBasePath() != null?this.get_externalBasePath():this.get_relativeBasePath();
		var base = unrestricted;
		if(entry.type == flambe.asset.AssetType.Data) base = restricted;
		return base != null?flambe.util.Strings.joinPath(base,entry.url):entry.url;
	}
	,clone: function() {
		var copy = new flambe.asset.Manifest();
		copy.set_relativeBasePath(this.get_relativeBasePath());
		copy.set_externalBasePath(this.get_externalBasePath());
		copy._entries = this._entries.slice();
		return copy;
	}
	,iterator: function() {
		return HxOverrides.iter(this._entries);
	}
	,add: function(name,url,bytes,type) {
		if(bytes == null) bytes = 0;
		if(type == null) type = flambe.asset.Manifest.inferType(url);
		var entry = new flambe.asset.AssetEntry(name,url,type,bytes);
		this._entries.push(entry);
		return entry;
	}
	,__class__: flambe.asset.Manifest
}
flambe.display = {}
flambe.display.BlendMode = $hxClasses["flambe.display.BlendMode"] = { __ename__ : ["flambe","display","BlendMode"], __constructs__ : ["Normal","Add","CopyExperimental"] }
flambe.display.BlendMode.Normal = ["Normal",0];
flambe.display.BlendMode.Normal.toString = $estr;
flambe.display.BlendMode.Normal.__enum__ = flambe.display.BlendMode;
flambe.display.BlendMode.Add = ["Add",1];
flambe.display.BlendMode.Add.toString = $estr;
flambe.display.BlendMode.Add.__enum__ = flambe.display.BlendMode;
flambe.display.BlendMode.CopyExperimental = ["CopyExperimental",2];
flambe.display.BlendMode.CopyExperimental.toString = $estr;
flambe.display.BlendMode.CopyExperimental.__enum__ = flambe.display.BlendMode;
flambe.display.Graphics = function() { }
$hxClasses["flambe.display.Graphics"] = flambe.display.Graphics;
flambe.display.Graphics.__name__ = ["flambe","display","Graphics"];
flambe.display.Graphics.prototype = {
	__class__: flambe.display.Graphics
}
flambe.display.Orientation = $hxClasses["flambe.display.Orientation"] = { __ename__ : ["flambe","display","Orientation"], __constructs__ : ["Portrait","Landscape"] }
flambe.display.Orientation.Portrait = ["Portrait",0];
flambe.display.Orientation.Portrait.toString = $estr;
flambe.display.Orientation.Portrait.__enum__ = flambe.display.Orientation;
flambe.display.Orientation.Landscape = ["Landscape",1];
flambe.display.Orientation.Landscape.toString = $estr;
flambe.display.Orientation.Landscape.__enum__ = flambe.display.Orientation;
flambe.math = {}
flambe.math.Point = function(x,y) {
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
};
$hxClasses["flambe.math.Point"] = flambe.math.Point;
flambe.math.Point.__name__ = ["flambe","math","Point"];
flambe.math.Point.prototype = {
	toString: function() {
		return "(" + this.x + "," + this.y + ")";
	}
	,__class__: flambe.math.Point
}
flambe.display.Sprite = function() {
	this.scissor = null;
	this.blendMode = null;
	var _g = this;
	this._flags = 1 << 0 | 1 << 1 | 1 << 3;
	this._localMatrix = new flambe.math.Matrix();
	var dirtyMatrix = function(_,_1) {
		_g._flags = flambe.util.BitSets.add(_g._flags,1 << 2 | 1 << 3);
	};
	this.x = new flambe.animation.AnimatedFloat(0,dirtyMatrix);
	this.y = new flambe.animation.AnimatedFloat(0,dirtyMatrix);
	this.rotation = new flambe.animation.AnimatedFloat(0,dirtyMatrix);
	this.scaleX = new flambe.animation.AnimatedFloat(1,dirtyMatrix);
	this.scaleY = new flambe.animation.AnimatedFloat(1,dirtyMatrix);
	this.anchorX = new flambe.animation.AnimatedFloat(0,dirtyMatrix);
	this.anchorY = new flambe.animation.AnimatedFloat(0,dirtyMatrix);
	this.alpha = new flambe.animation.AnimatedFloat(1);
};
$hxClasses["flambe.display.Sprite"] = flambe.display.Sprite;
flambe.display.Sprite.__name__ = ["flambe","display","Sprite"];
flambe.display.Sprite.getFrom = function(entity) {
	return entity.getComponent("Sprite_1");
}
flambe.display.Sprite.hitTest = function(entity,x,y) {
	var sprite = flambe.display.Sprite.getFrom(entity);
	if(sprite != null) {
		if(!flambe.util.BitSets.containsAll(sprite._flags,1 << 0 | 1 << 1)) return null;
		if(sprite.getLocalMatrix().inverseTransform(x,y,flambe.display.Sprite._scratchPoint)) {
			x = flambe.display.Sprite._scratchPoint.x;
			y = flambe.display.Sprite._scratchPoint.y;
		}
		var scissor = sprite.scissor;
		if(scissor != null && !scissor.contains(x,y)) return null;
	}
	var result = flambe.display.Sprite.hitTestBackwards(entity.firstChild,x,y);
	if(result != null) return result;
	return sprite != null && sprite.containsLocal(x,y)?sprite:null;
}
flambe.display.Sprite.render = function(entity,g) {
	var sprite = flambe.display.Sprite.getFrom(entity);
	if(sprite != null) {
		var alpha = sprite.alpha.get__();
		if(!sprite.get_visible() || alpha <= 0) return;
		g.save();
		if(alpha < 1) g.multiplyAlpha(alpha);
		if(sprite.blendMode != null) g.setBlendMode(sprite.blendMode);
		var matrix = sprite.getLocalMatrix();
		g.transform(matrix.m00,matrix.m10,matrix.m01,matrix.m11,matrix.m02,matrix.m12);
		var scissor = sprite.scissor;
		if(scissor != null) g.applyScissor(scissor.x,scissor.y,scissor.width,scissor.height);
		sprite.draw(g);
	}
	var director = flambe.scene.Director.getFrom(entity);
	if(director != null) {
		var scenes = director.occludedScenes;
		var _g = 0;
		while(_g < scenes.length) {
			var scene = scenes[_g];
			++_g;
			flambe.display.Sprite.render(scene,g);
		}
	}
	var p = entity.firstChild;
	while(p != null) {
		var next = p.next;
		flambe.display.Sprite.render(p,g);
		p = next;
	}
	if(sprite != null) g.restore();
}
flambe.display.Sprite.hitTestBackwards = function(entity,x,y) {
	if(entity != null) {
		var result = flambe.display.Sprite.hitTestBackwards(entity.next,x,y);
		return result != null?result:flambe.display.Sprite.hitTest(entity,x,y);
	}
	return null;
}
flambe.display.Sprite.__super__ = flambe.Component;
flambe.display.Sprite.prototype = $extend(flambe.Component.prototype,{
	set_pointerEnabled: function(pointerEnabled) {
		this._flags = flambe.util.BitSets.set(this._flags,1 << 1,pointerEnabled);
		return pointerEnabled;
	}
	,set_visible: function(visible) {
		this._flags = flambe.util.BitSets.set(this._flags,1 << 0,visible);
		return visible;
	}
	,get_visible: function() {
		return flambe.util.BitSets.contains(this._flags,1 << 0);
	}
	,get_pointerUp: function() {
		if(this._internal_pointerUp == null) this._internal_pointerUp = new flambe.util.Signal1();
		return this._internal_pointerUp;
	}
	,get_pointerMove: function() {
		if(this._internal_pointerMove == null) this._internal_pointerMove = new flambe.util.Signal1();
		return this._internal_pointerMove;
	}
	,get_pointerDown: function() {
		if(this._internal_pointerDown == null) this._internal_pointerDown = new flambe.util.Signal1();
		return this._internal_pointerDown;
	}
	,draw: function(g) {
	}
	,onUpdate: function(dt) {
		this.x.update(dt);
		this.y.update(dt);
		this.rotation.update(dt);
		this.scaleX.update(dt);
		this.scaleY.update(dt);
		this.alpha.update(dt);
		this.anchorX.update(dt);
		this.anchorY.update(dt);
	}
	,getLocalMatrix: function() {
		if(flambe.util.BitSets.contains(this._flags,1 << 2)) {
			this._flags = flambe.util.BitSets.remove(this._flags,1 << 2);
			this._localMatrix.compose(this.x.get__(),this.y.get__(),this.scaleX.get__(),this.scaleY.get__(),flambe.math.FMath.toRadians(this.rotation.get__()));
			this._localMatrix.translate(-this.anchorX.get__(),-this.anchorY.get__());
		}
		return this._localMatrix;
	}
	,containsLocal: function(localX,localY) {
		return localX >= 0 && localX < this.getNaturalWidth() && localY >= 0 && localY < this.getNaturalHeight();
	}
	,getNaturalHeight: function() {
		return 0;
	}
	,getNaturalWidth: function() {
		return 0;
	}
	,get_name: function() {
		return "Sprite_1";
	}
	,__class__: flambe.display.Sprite
});
flambe.display.Stage = function() { }
$hxClasses["flambe.display.Stage"] = flambe.display.Stage;
flambe.display.Stage.__name__ = ["flambe","display","Stage"];
flambe.display.Stage.prototype = {
	__class__: flambe.display.Stage
}
flambe.display.Texture = function() { }
$hxClasses["flambe.display.Texture"] = flambe.display.Texture;
flambe.display.Texture.__name__ = ["flambe","display","Texture"];
flambe.display.Texture.prototype = {
	__class__: flambe.display.Texture
}
flambe.external = {}
flambe.external.External = function() { }
$hxClasses["flambe.external.External"] = flambe.external.External;
flambe.external.External.__name__ = ["flambe","external","External"];
flambe.external.External.prototype = {
	__class__: flambe.external.External
}
flambe.input = {}
flambe.input.Key = $hxClasses["flambe.input.Key"] = { __ename__ : ["flambe","input","Key"], __constructs__ : ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","Number0","Number1","Number2","Number3","Number4","Number5","Number6","Number7","Number8","Number9","Numpad0","Numpad1","Numpad2","Numpad3","Numpad4","Numpad5","Numpad6","Numpad7","Numpad8","Numpad9","NumpadAdd","NumpadDecimal","NumpadDivide","NumpadEnter","NumpadMultiply","NumpadSubtract","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","F13","F14","F15","Left","Up","Right","Down","Alt","Backquote","Backslash","Backspace","CapsLock","Comma","Command","Control","Delete","End","Enter","Equals","Escape","Home","Insert","LeftBracket","Minus","PageDown","PageUp","Period","Quote","RightBracket","Semicolon","Shift","Slash","Space","Tab","Menu","Search","Unknown"] }
flambe.input.Key.A = ["A",0];
flambe.input.Key.A.toString = $estr;
flambe.input.Key.A.__enum__ = flambe.input.Key;
flambe.input.Key.B = ["B",1];
flambe.input.Key.B.toString = $estr;
flambe.input.Key.B.__enum__ = flambe.input.Key;
flambe.input.Key.C = ["C",2];
flambe.input.Key.C.toString = $estr;
flambe.input.Key.C.__enum__ = flambe.input.Key;
flambe.input.Key.D = ["D",3];
flambe.input.Key.D.toString = $estr;
flambe.input.Key.D.__enum__ = flambe.input.Key;
flambe.input.Key.E = ["E",4];
flambe.input.Key.E.toString = $estr;
flambe.input.Key.E.__enum__ = flambe.input.Key;
flambe.input.Key.F = ["F",5];
flambe.input.Key.F.toString = $estr;
flambe.input.Key.F.__enum__ = flambe.input.Key;
flambe.input.Key.G = ["G",6];
flambe.input.Key.G.toString = $estr;
flambe.input.Key.G.__enum__ = flambe.input.Key;
flambe.input.Key.H = ["H",7];
flambe.input.Key.H.toString = $estr;
flambe.input.Key.H.__enum__ = flambe.input.Key;
flambe.input.Key.I = ["I",8];
flambe.input.Key.I.toString = $estr;
flambe.input.Key.I.__enum__ = flambe.input.Key;
flambe.input.Key.J = ["J",9];
flambe.input.Key.J.toString = $estr;
flambe.input.Key.J.__enum__ = flambe.input.Key;
flambe.input.Key.K = ["K",10];
flambe.input.Key.K.toString = $estr;
flambe.input.Key.K.__enum__ = flambe.input.Key;
flambe.input.Key.L = ["L",11];
flambe.input.Key.L.toString = $estr;
flambe.input.Key.L.__enum__ = flambe.input.Key;
flambe.input.Key.M = ["M",12];
flambe.input.Key.M.toString = $estr;
flambe.input.Key.M.__enum__ = flambe.input.Key;
flambe.input.Key.N = ["N",13];
flambe.input.Key.N.toString = $estr;
flambe.input.Key.N.__enum__ = flambe.input.Key;
flambe.input.Key.O = ["O",14];
flambe.input.Key.O.toString = $estr;
flambe.input.Key.O.__enum__ = flambe.input.Key;
flambe.input.Key.P = ["P",15];
flambe.input.Key.P.toString = $estr;
flambe.input.Key.P.__enum__ = flambe.input.Key;
flambe.input.Key.Q = ["Q",16];
flambe.input.Key.Q.toString = $estr;
flambe.input.Key.Q.__enum__ = flambe.input.Key;
flambe.input.Key.R = ["R",17];
flambe.input.Key.R.toString = $estr;
flambe.input.Key.R.__enum__ = flambe.input.Key;
flambe.input.Key.S = ["S",18];
flambe.input.Key.S.toString = $estr;
flambe.input.Key.S.__enum__ = flambe.input.Key;
flambe.input.Key.T = ["T",19];
flambe.input.Key.T.toString = $estr;
flambe.input.Key.T.__enum__ = flambe.input.Key;
flambe.input.Key.U = ["U",20];
flambe.input.Key.U.toString = $estr;
flambe.input.Key.U.__enum__ = flambe.input.Key;
flambe.input.Key.V = ["V",21];
flambe.input.Key.V.toString = $estr;
flambe.input.Key.V.__enum__ = flambe.input.Key;
flambe.input.Key.W = ["W",22];
flambe.input.Key.W.toString = $estr;
flambe.input.Key.W.__enum__ = flambe.input.Key;
flambe.input.Key.X = ["X",23];
flambe.input.Key.X.toString = $estr;
flambe.input.Key.X.__enum__ = flambe.input.Key;
flambe.input.Key.Y = ["Y",24];
flambe.input.Key.Y.toString = $estr;
flambe.input.Key.Y.__enum__ = flambe.input.Key;
flambe.input.Key.Z = ["Z",25];
flambe.input.Key.Z.toString = $estr;
flambe.input.Key.Z.__enum__ = flambe.input.Key;
flambe.input.Key.Number0 = ["Number0",26];
flambe.input.Key.Number0.toString = $estr;
flambe.input.Key.Number0.__enum__ = flambe.input.Key;
flambe.input.Key.Number1 = ["Number1",27];
flambe.input.Key.Number1.toString = $estr;
flambe.input.Key.Number1.__enum__ = flambe.input.Key;
flambe.input.Key.Number2 = ["Number2",28];
flambe.input.Key.Number2.toString = $estr;
flambe.input.Key.Number2.__enum__ = flambe.input.Key;
flambe.input.Key.Number3 = ["Number3",29];
flambe.input.Key.Number3.toString = $estr;
flambe.input.Key.Number3.__enum__ = flambe.input.Key;
flambe.input.Key.Number4 = ["Number4",30];
flambe.input.Key.Number4.toString = $estr;
flambe.input.Key.Number4.__enum__ = flambe.input.Key;
flambe.input.Key.Number5 = ["Number5",31];
flambe.input.Key.Number5.toString = $estr;
flambe.input.Key.Number5.__enum__ = flambe.input.Key;
flambe.input.Key.Number6 = ["Number6",32];
flambe.input.Key.Number6.toString = $estr;
flambe.input.Key.Number6.__enum__ = flambe.input.Key;
flambe.input.Key.Number7 = ["Number7",33];
flambe.input.Key.Number7.toString = $estr;
flambe.input.Key.Number7.__enum__ = flambe.input.Key;
flambe.input.Key.Number8 = ["Number8",34];
flambe.input.Key.Number8.toString = $estr;
flambe.input.Key.Number8.__enum__ = flambe.input.Key;
flambe.input.Key.Number9 = ["Number9",35];
flambe.input.Key.Number9.toString = $estr;
flambe.input.Key.Number9.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad0 = ["Numpad0",36];
flambe.input.Key.Numpad0.toString = $estr;
flambe.input.Key.Numpad0.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad1 = ["Numpad1",37];
flambe.input.Key.Numpad1.toString = $estr;
flambe.input.Key.Numpad1.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad2 = ["Numpad2",38];
flambe.input.Key.Numpad2.toString = $estr;
flambe.input.Key.Numpad2.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad3 = ["Numpad3",39];
flambe.input.Key.Numpad3.toString = $estr;
flambe.input.Key.Numpad3.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad4 = ["Numpad4",40];
flambe.input.Key.Numpad4.toString = $estr;
flambe.input.Key.Numpad4.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad5 = ["Numpad5",41];
flambe.input.Key.Numpad5.toString = $estr;
flambe.input.Key.Numpad5.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad6 = ["Numpad6",42];
flambe.input.Key.Numpad6.toString = $estr;
flambe.input.Key.Numpad6.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad7 = ["Numpad7",43];
flambe.input.Key.Numpad7.toString = $estr;
flambe.input.Key.Numpad7.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad8 = ["Numpad8",44];
flambe.input.Key.Numpad8.toString = $estr;
flambe.input.Key.Numpad8.__enum__ = flambe.input.Key;
flambe.input.Key.Numpad9 = ["Numpad9",45];
flambe.input.Key.Numpad9.toString = $estr;
flambe.input.Key.Numpad9.__enum__ = flambe.input.Key;
flambe.input.Key.NumpadAdd = ["NumpadAdd",46];
flambe.input.Key.NumpadAdd.toString = $estr;
flambe.input.Key.NumpadAdd.__enum__ = flambe.input.Key;
flambe.input.Key.NumpadDecimal = ["NumpadDecimal",47];
flambe.input.Key.NumpadDecimal.toString = $estr;
flambe.input.Key.NumpadDecimal.__enum__ = flambe.input.Key;
flambe.input.Key.NumpadDivide = ["NumpadDivide",48];
flambe.input.Key.NumpadDivide.toString = $estr;
flambe.input.Key.NumpadDivide.__enum__ = flambe.input.Key;
flambe.input.Key.NumpadEnter = ["NumpadEnter",49];
flambe.input.Key.NumpadEnter.toString = $estr;
flambe.input.Key.NumpadEnter.__enum__ = flambe.input.Key;
flambe.input.Key.NumpadMultiply = ["NumpadMultiply",50];
flambe.input.Key.NumpadMultiply.toString = $estr;
flambe.input.Key.NumpadMultiply.__enum__ = flambe.input.Key;
flambe.input.Key.NumpadSubtract = ["NumpadSubtract",51];
flambe.input.Key.NumpadSubtract.toString = $estr;
flambe.input.Key.NumpadSubtract.__enum__ = flambe.input.Key;
flambe.input.Key.F1 = ["F1",52];
flambe.input.Key.F1.toString = $estr;
flambe.input.Key.F1.__enum__ = flambe.input.Key;
flambe.input.Key.F2 = ["F2",53];
flambe.input.Key.F2.toString = $estr;
flambe.input.Key.F2.__enum__ = flambe.input.Key;
flambe.input.Key.F3 = ["F3",54];
flambe.input.Key.F3.toString = $estr;
flambe.input.Key.F3.__enum__ = flambe.input.Key;
flambe.input.Key.F4 = ["F4",55];
flambe.input.Key.F4.toString = $estr;
flambe.input.Key.F4.__enum__ = flambe.input.Key;
flambe.input.Key.F5 = ["F5",56];
flambe.input.Key.F5.toString = $estr;
flambe.input.Key.F5.__enum__ = flambe.input.Key;
flambe.input.Key.F6 = ["F6",57];
flambe.input.Key.F6.toString = $estr;
flambe.input.Key.F6.__enum__ = flambe.input.Key;
flambe.input.Key.F7 = ["F7",58];
flambe.input.Key.F7.toString = $estr;
flambe.input.Key.F7.__enum__ = flambe.input.Key;
flambe.input.Key.F8 = ["F8",59];
flambe.input.Key.F8.toString = $estr;
flambe.input.Key.F8.__enum__ = flambe.input.Key;
flambe.input.Key.F9 = ["F9",60];
flambe.input.Key.F9.toString = $estr;
flambe.input.Key.F9.__enum__ = flambe.input.Key;
flambe.input.Key.F10 = ["F10",61];
flambe.input.Key.F10.toString = $estr;
flambe.input.Key.F10.__enum__ = flambe.input.Key;
flambe.input.Key.F11 = ["F11",62];
flambe.input.Key.F11.toString = $estr;
flambe.input.Key.F11.__enum__ = flambe.input.Key;
flambe.input.Key.F12 = ["F12",63];
flambe.input.Key.F12.toString = $estr;
flambe.input.Key.F12.__enum__ = flambe.input.Key;
flambe.input.Key.F13 = ["F13",64];
flambe.input.Key.F13.toString = $estr;
flambe.input.Key.F13.__enum__ = flambe.input.Key;
flambe.input.Key.F14 = ["F14",65];
flambe.input.Key.F14.toString = $estr;
flambe.input.Key.F14.__enum__ = flambe.input.Key;
flambe.input.Key.F15 = ["F15",66];
flambe.input.Key.F15.toString = $estr;
flambe.input.Key.F15.__enum__ = flambe.input.Key;
flambe.input.Key.Left = ["Left",67];
flambe.input.Key.Left.toString = $estr;
flambe.input.Key.Left.__enum__ = flambe.input.Key;
flambe.input.Key.Up = ["Up",68];
flambe.input.Key.Up.toString = $estr;
flambe.input.Key.Up.__enum__ = flambe.input.Key;
flambe.input.Key.Right = ["Right",69];
flambe.input.Key.Right.toString = $estr;
flambe.input.Key.Right.__enum__ = flambe.input.Key;
flambe.input.Key.Down = ["Down",70];
flambe.input.Key.Down.toString = $estr;
flambe.input.Key.Down.__enum__ = flambe.input.Key;
flambe.input.Key.Alt = ["Alt",71];
flambe.input.Key.Alt.toString = $estr;
flambe.input.Key.Alt.__enum__ = flambe.input.Key;
flambe.input.Key.Backquote = ["Backquote",72];
flambe.input.Key.Backquote.toString = $estr;
flambe.input.Key.Backquote.__enum__ = flambe.input.Key;
flambe.input.Key.Backslash = ["Backslash",73];
flambe.input.Key.Backslash.toString = $estr;
flambe.input.Key.Backslash.__enum__ = flambe.input.Key;
flambe.input.Key.Backspace = ["Backspace",74];
flambe.input.Key.Backspace.toString = $estr;
flambe.input.Key.Backspace.__enum__ = flambe.input.Key;
flambe.input.Key.CapsLock = ["CapsLock",75];
flambe.input.Key.CapsLock.toString = $estr;
flambe.input.Key.CapsLock.__enum__ = flambe.input.Key;
flambe.input.Key.Comma = ["Comma",76];
flambe.input.Key.Comma.toString = $estr;
flambe.input.Key.Comma.__enum__ = flambe.input.Key;
flambe.input.Key.Command = ["Command",77];
flambe.input.Key.Command.toString = $estr;
flambe.input.Key.Command.__enum__ = flambe.input.Key;
flambe.input.Key.Control = ["Control",78];
flambe.input.Key.Control.toString = $estr;
flambe.input.Key.Control.__enum__ = flambe.input.Key;
flambe.input.Key.Delete = ["Delete",79];
flambe.input.Key.Delete.toString = $estr;
flambe.input.Key.Delete.__enum__ = flambe.input.Key;
flambe.input.Key.End = ["End",80];
flambe.input.Key.End.toString = $estr;
flambe.input.Key.End.__enum__ = flambe.input.Key;
flambe.input.Key.Enter = ["Enter",81];
flambe.input.Key.Enter.toString = $estr;
flambe.input.Key.Enter.__enum__ = flambe.input.Key;
flambe.input.Key.Equals = ["Equals",82];
flambe.input.Key.Equals.toString = $estr;
flambe.input.Key.Equals.__enum__ = flambe.input.Key;
flambe.input.Key.Escape = ["Escape",83];
flambe.input.Key.Escape.toString = $estr;
flambe.input.Key.Escape.__enum__ = flambe.input.Key;
flambe.input.Key.Home = ["Home",84];
flambe.input.Key.Home.toString = $estr;
flambe.input.Key.Home.__enum__ = flambe.input.Key;
flambe.input.Key.Insert = ["Insert",85];
flambe.input.Key.Insert.toString = $estr;
flambe.input.Key.Insert.__enum__ = flambe.input.Key;
flambe.input.Key.LeftBracket = ["LeftBracket",86];
flambe.input.Key.LeftBracket.toString = $estr;
flambe.input.Key.LeftBracket.__enum__ = flambe.input.Key;
flambe.input.Key.Minus = ["Minus",87];
flambe.input.Key.Minus.toString = $estr;
flambe.input.Key.Minus.__enum__ = flambe.input.Key;
flambe.input.Key.PageDown = ["PageDown",88];
flambe.input.Key.PageDown.toString = $estr;
flambe.input.Key.PageDown.__enum__ = flambe.input.Key;
flambe.input.Key.PageUp = ["PageUp",89];
flambe.input.Key.PageUp.toString = $estr;
flambe.input.Key.PageUp.__enum__ = flambe.input.Key;
flambe.input.Key.Period = ["Period",90];
flambe.input.Key.Period.toString = $estr;
flambe.input.Key.Period.__enum__ = flambe.input.Key;
flambe.input.Key.Quote = ["Quote",91];
flambe.input.Key.Quote.toString = $estr;
flambe.input.Key.Quote.__enum__ = flambe.input.Key;
flambe.input.Key.RightBracket = ["RightBracket",92];
flambe.input.Key.RightBracket.toString = $estr;
flambe.input.Key.RightBracket.__enum__ = flambe.input.Key;
flambe.input.Key.Semicolon = ["Semicolon",93];
flambe.input.Key.Semicolon.toString = $estr;
flambe.input.Key.Semicolon.__enum__ = flambe.input.Key;
flambe.input.Key.Shift = ["Shift",94];
flambe.input.Key.Shift.toString = $estr;
flambe.input.Key.Shift.__enum__ = flambe.input.Key;
flambe.input.Key.Slash = ["Slash",95];
flambe.input.Key.Slash.toString = $estr;
flambe.input.Key.Slash.__enum__ = flambe.input.Key;
flambe.input.Key.Space = ["Space",96];
flambe.input.Key.Space.toString = $estr;
flambe.input.Key.Space.__enum__ = flambe.input.Key;
flambe.input.Key.Tab = ["Tab",97];
flambe.input.Key.Tab.toString = $estr;
flambe.input.Key.Tab.__enum__ = flambe.input.Key;
flambe.input.Key.Menu = ["Menu",98];
flambe.input.Key.Menu.toString = $estr;
flambe.input.Key.Menu.__enum__ = flambe.input.Key;
flambe.input.Key.Search = ["Search",99];
flambe.input.Key.Search.toString = $estr;
flambe.input.Key.Search.__enum__ = flambe.input.Key;
flambe.input.Key.Unknown = function(keyCode) { var $x = ["Unknown",100,keyCode]; $x.__enum__ = flambe.input.Key; $x.toString = $estr; return $x; }
flambe.input.Keyboard = function() { }
$hxClasses["flambe.input.Keyboard"] = flambe.input.Keyboard;
flambe.input.Keyboard.__name__ = ["flambe","input","Keyboard"];
flambe.input.Keyboard.prototype = {
	__class__: flambe.input.Keyboard
}
flambe.input.KeyboardEvent = function() {
	this._internal_init(0,null);
};
$hxClasses["flambe.input.KeyboardEvent"] = flambe.input.KeyboardEvent;
flambe.input.KeyboardEvent.__name__ = ["flambe","input","KeyboardEvent"];
flambe.input.KeyboardEvent.prototype = {
	_internal_init: function(id,key) {
		this.id = id;
		this.key = key;
	}
	,__class__: flambe.input.KeyboardEvent
}
flambe.input.Mouse = function() { }
$hxClasses["flambe.input.Mouse"] = flambe.input.Mouse;
flambe.input.Mouse.__name__ = ["flambe","input","Mouse"];
flambe.input.Mouse.prototype = {
	__class__: flambe.input.Mouse
}
flambe.input.MouseButton = $hxClasses["flambe.input.MouseButton"] = { __ename__ : ["flambe","input","MouseButton"], __constructs__ : ["Left","Middle","Right","Unknown"] }
flambe.input.MouseButton.Left = ["Left",0];
flambe.input.MouseButton.Left.toString = $estr;
flambe.input.MouseButton.Left.__enum__ = flambe.input.MouseButton;
flambe.input.MouseButton.Middle = ["Middle",1];
flambe.input.MouseButton.Middle.toString = $estr;
flambe.input.MouseButton.Middle.__enum__ = flambe.input.MouseButton;
flambe.input.MouseButton.Right = ["Right",2];
flambe.input.MouseButton.Right.toString = $estr;
flambe.input.MouseButton.Right.__enum__ = flambe.input.MouseButton;
flambe.input.MouseButton.Unknown = function(buttonCode) { var $x = ["Unknown",3,buttonCode]; $x.__enum__ = flambe.input.MouseButton; $x.toString = $estr; return $x; }
flambe.input.MouseCursor = $hxClasses["flambe.input.MouseCursor"] = { __ename__ : ["flambe","input","MouseCursor"], __constructs__ : ["Default","Button","None"] }
flambe.input.MouseCursor.Default = ["Default",0];
flambe.input.MouseCursor.Default.toString = $estr;
flambe.input.MouseCursor.Default.__enum__ = flambe.input.MouseCursor;
flambe.input.MouseCursor.Button = ["Button",1];
flambe.input.MouseCursor.Button.toString = $estr;
flambe.input.MouseCursor.Button.__enum__ = flambe.input.MouseCursor;
flambe.input.MouseCursor.None = ["None",2];
flambe.input.MouseCursor.None.toString = $estr;
flambe.input.MouseCursor.None.__enum__ = flambe.input.MouseCursor;
flambe.input.MouseEvent = function() {
	this._internal_init(0,0,0,null);
};
$hxClasses["flambe.input.MouseEvent"] = flambe.input.MouseEvent;
flambe.input.MouseEvent.__name__ = ["flambe","input","MouseEvent"];
flambe.input.MouseEvent.prototype = {
	_internal_init: function(id,viewX,viewY,button) {
		this.id = id;
		this.viewX = viewX;
		this.viewY = viewY;
		this.button = button;
	}
	,__class__: flambe.input.MouseEvent
}
flambe.input.Pointer = function() { }
$hxClasses["flambe.input.Pointer"] = flambe.input.Pointer;
flambe.input.Pointer.__name__ = ["flambe","input","Pointer"];
flambe.input.Pointer.prototype = {
	__class__: flambe.input.Pointer
}
flambe.input.EventSource = $hxClasses["flambe.input.EventSource"] = { __ename__ : ["flambe","input","EventSource"], __constructs__ : ["Mouse","Touch"] }
flambe.input.EventSource.Mouse = function(event) { var $x = ["Mouse",0,event]; $x.__enum__ = flambe.input.EventSource; $x.toString = $estr; return $x; }
flambe.input.EventSource.Touch = function(point) { var $x = ["Touch",1,point]; $x.__enum__ = flambe.input.EventSource; $x.toString = $estr; return $x; }
flambe.input.PointerEvent = function() {
	this._internal_init(0,0,0,null,null);
};
$hxClasses["flambe.input.PointerEvent"] = flambe.input.PointerEvent;
flambe.input.PointerEvent.__name__ = ["flambe","input","PointerEvent"];
flambe.input.PointerEvent.prototype = {
	_internal_init: function(id,viewX,viewY,hit,source) {
		this.id = id;
		this.viewX = viewX;
		this.viewY = viewY;
		this.hit = hit;
		this.source = source;
		this._internal_stopped = false;
	}
	,__class__: flambe.input.PointerEvent
}
flambe.input.Touch = function() { }
$hxClasses["flambe.input.Touch"] = flambe.input.Touch;
flambe.input.Touch.__name__ = ["flambe","input","Touch"];
flambe.input.Touch.prototype = {
	__class__: flambe.input.Touch
}
flambe.input.TouchPoint = function(id) {
	this.id = id;
	this._internal_source = flambe.input.EventSource.Touch(this);
};
$hxClasses["flambe.input.TouchPoint"] = flambe.input.TouchPoint;
flambe.input.TouchPoint.__name__ = ["flambe","input","TouchPoint"];
flambe.input.TouchPoint.prototype = {
	_internal_init: function(viewX,viewY) {
		this.viewX = viewX;
		this.viewY = viewY;
	}
	,__class__: flambe.input.TouchPoint
}
flambe.math.FMath = function() { }
$hxClasses["flambe.math.FMath"] = flambe.math.FMath;
flambe.math.FMath.__name__ = ["flambe","math","FMath"];
flambe.math.FMath.toRadians = function(degrees) {
	return degrees * 3.141592653589793 / 180;
}
flambe.math.Matrix = function() {
	this.identity();
};
$hxClasses["flambe.math.Matrix"] = flambe.math.Matrix;
flambe.math.Matrix.__name__ = ["flambe","math","Matrix"];
flambe.math.Matrix.prototype = {
	toString: function() {
		return this.m00 + " " + this.m01 + " " + this.m02 + " \\ " + this.m10 + " " + this.m11 + " " + this.m12;
	}
	,inverseTransform: function(x,y,result) {
		var det = this.determinant();
		if(det == 0) return false;
		x -= this.m02;
		y -= this.m12;
		result.x = (x * this.m11 - y * this.m01) / det;
		result.y = (y * this.m00 - x * this.m10) / det;
		return true;
	}
	,determinant: function() {
		return this.m00 * this.m11 - this.m01 * this.m10;
	}
	,translate: function(x,y) {
		this.m02 += this.m00 * x + this.m01 * y;
		this.m12 += this.m11 * y + this.m10 * x;
	}
	,compose: function(x,y,scaleX,scaleY,rotation) {
		var sin = Math.sin(rotation);
		var cos = Math.cos(rotation);
		this.set(cos * scaleX,sin * scaleX,-sin * scaleY,cos * scaleY,x,y);
	}
	,identity: function() {
		this.set(1,0,0,1,0,0);
	}
	,set: function(m00,m10,m01,m11,m02,m12) {
		this.m00 = m00;
		this.m01 = m01;
		this.m02 = m02;
		this.m10 = m10;
		this.m11 = m11;
		this.m12 = m12;
	}
	,__class__: flambe.math.Matrix
}
flambe.math.Rectangle = function() { }
$hxClasses["flambe.math.Rectangle"] = flambe.math.Rectangle;
flambe.math.Rectangle.__name__ = ["flambe","math","Rectangle"];
flambe.math.Rectangle.prototype = {
	toString: function() {
		return "(" + this.x + "," + this.y + " " + this.width + "x" + this.height + ")";
	}
	,contains: function(x,y) {
		x -= this.x;
		y -= this.y;
		return x >= 0 && y >= 0 && x <= this.width && y <= this.height;
	}
	,__class__: flambe.math.Rectangle
}
flambe.platform.BasicAssetPackLoader = function(platform,manifest) {
	this._platform = platform;
	this.promise = new flambe.util.Promise();
	this._bytesLoaded = new Hash();
	this._pack = new flambe.platform._BasicAssetPackLoader.BasicAssetPack(manifest);
	var entries = Lambda.array(manifest);
	if(entries.length == 0) this.handleSuccess(); else {
		var bytesTotal = 0;
		var groups = new Hash();
		var _g = 0;
		while(_g < entries.length) {
			var entry = entries[_g];
			++_g;
			var group = groups.get(entry.name);
			if(group == null) {
				group = [];
				groups.set(entry.name,group);
			}
			group.push(entry);
		}
		this._assetsRemaining = Lambda.count(groups);
		var $it0 = groups.iterator();
		while( $it0.hasNext() ) {
			var group = $it0.next();
			var bestEntry = group.length > 1?this.pickBestEntry(group):group[0];
			var placeholder = this.createPlaceholder(bestEntry);
			if(placeholder != null) {
				flambe.Log.warn("Using an asset placeholder",["name",bestEntry.name,"type",bestEntry.type]);
				this.handleLoad(bestEntry,placeholder);
			} else {
				bytesTotal += bestEntry.bytes;
				var url = manifest.getFullURL(bestEntry);
				try {
					this.loadEntry(url,bestEntry);
				} catch( error ) {
					this.handleError(bestEntry,"Unexpected error: " + Std.string(error));
				}
			}
		}
		this.promise.set_total(bytesTotal);
	}
};
$hxClasses["flambe.platform.BasicAssetPackLoader"] = flambe.platform.BasicAssetPackLoader;
flambe.platform.BasicAssetPackLoader.__name__ = ["flambe","platform","BasicAssetPackLoader"];
flambe.platform.BasicAssetPackLoader.prototype = {
	handleTextureError: function(entry) {
		this.handleError(entry,"Failed to create texture. Is the GPU context unavailable?");
	}
	,handleError: function(entry,message) {
		flambe.Log.warn("Error loading asset pack",["error",message,"url",entry.url]);
		this.promise.error.emit(flambe.util.Strings.withFields(message,["url",entry.url]));
	}
	,handleSuccess: function() {
		this.promise.set_result(this._pack);
	}
	,handleProgress: function(entry,bytesLoaded) {
		this._bytesLoaded.set(entry.name,bytesLoaded);
		var bytesTotal = 0;
		var $it0 = this._bytesLoaded.iterator();
		while( $it0.hasNext() ) {
			var bytes = $it0.next();
			bytesTotal += bytes;
		}
		this.promise.set_progress(bytesTotal);
	}
	,handleLoad: function(entry,asset) {
		var name = entry.name;
		switch( (entry.type)[1] ) {
		case 0:
			this._pack.textures.set(name,asset);
			break;
		case 1:
			this._pack.sounds.set(name,asset);
			break;
		case 2:
			this._pack.files.set(name,asset);
			break;
		}
		this._assetsRemaining -= 1;
		if(this._assetsRemaining <= 0) this.handleSuccess();
	}
	,getAudioFormats: function() {
		return [];
	}
	,loadEntry: function(url,entry) {
	}
	,createPlaceholder: function(entry) {
		switch( (entry.type)[1] ) {
		case 1:
			if(!Lambda.has(this.getAudioFormats(),entry.getUrlExtension())) return flambe.platform.DummySound.getInstance();
			break;
		default:
		}
		return null;
	}
	,pickBestEntry: function(entries) {
		switch( (entries[0].type)[1] ) {
		case 1:
			var extensions = this.getAudioFormats();
			var _g = 0;
			while(_g < extensions.length) {
				var extension = extensions[_g];
				++_g;
				var _g1 = 0;
				while(_g1 < entries.length) {
					var entry = entries[_g1];
					++_g1;
					if(entry.getUrlExtension() == extension) return entry;
				}
			}
			break;
		default:
		}
		return entries[0];
	}
	,__class__: flambe.platform.BasicAssetPackLoader
}
flambe.platform._BasicAssetPackLoader = {}
flambe.platform._BasicAssetPackLoader.BasicAssetPack = function(manifest) {
	this._manifest = manifest;
	this.textures = new Hash();
	this.sounds = new Hash();
	this.files = new Hash();
};
$hxClasses["flambe.platform._BasicAssetPackLoader.BasicAssetPack"] = flambe.platform._BasicAssetPackLoader.BasicAssetPack;
flambe.platform._BasicAssetPackLoader.BasicAssetPack.__name__ = ["flambe","platform","_BasicAssetPackLoader","BasicAssetPack"];
flambe.platform._BasicAssetPackLoader.BasicAssetPack.__interfaces__ = [flambe.asset.AssetPack];
flambe.platform._BasicAssetPackLoader.BasicAssetPack.warnOnExtension = function(path) {
	var ext = flambe.util.Strings.getFileExtension(path);
	if(ext != null && ext.length == 3) flambe.Log.warn("Requested asset \"" + path + "\" should not have a file extension," + " did you mean \"" + flambe.util.Strings.removeFileExtension(path) + "\"?");
}
flambe.platform._BasicAssetPackLoader.BasicAssetPack.prototype = {
	get_manifest: function() {
		return this._manifest;
	}
	,getFile: function(name,required) {
		if(required == null) required = true;
		var file = this.files.get(name);
		if(file == null && required) throw flambe.util.Strings.withFields("Missing file",["name",name]);
		return file;
	}
	,getSound: function(name,required) {
		if(required == null) required = true;
		flambe.platform._BasicAssetPackLoader.BasicAssetPack.warnOnExtension(name);
		var sound = this.sounds.get(name);
		if(sound == null && required) throw flambe.util.Strings.withFields("Missing sound",["name",name]);
		return sound;
	}
	,getTexture: function(name,required) {
		if(required == null) required = true;
		flambe.platform._BasicAssetPackLoader.BasicAssetPack.warnOnExtension(name);
		var texture = this.textures.get(name);
		if(texture == null && required) throw flambe.util.Strings.withFields("Missing texture",["name",name]);
		return texture;
	}
	,__class__: flambe.platform._BasicAssetPackLoader.BasicAssetPack
}
flambe.platform.BasicKeyboard = function() {
	this.down = new flambe.util.Signal1();
	this.up = new flambe.util.Signal1();
	this.backButton = new flambe.util.Signal0();
	this._keyStates = new IntHash();
};
$hxClasses["flambe.platform.BasicKeyboard"] = flambe.platform.BasicKeyboard;
flambe.platform.BasicKeyboard.__name__ = ["flambe","platform","BasicKeyboard"];
flambe.platform.BasicKeyboard.__interfaces__ = [flambe.input.Keyboard];
flambe.platform.BasicKeyboard.prototype = {
	submitUp: function(keyCode) {
		if(this.isCodeDown(keyCode)) {
			this._keyStates.remove(keyCode);
			flambe.platform.BasicKeyboard._sharedEvent._internal_init(flambe.platform.BasicKeyboard._sharedEvent.id + 1,flambe.platform.KeyCodes.toKey(keyCode));
			this.up.emit(flambe.platform.BasicKeyboard._sharedEvent);
		}
	}
	,submitDown: function(keyCode) {
		if(keyCode == 16777238) {
			if(this.backButton.hasListeners()) {
				this.backButton.emit();
				return true;
			}
			return false;
		}
		if(!this.isCodeDown(keyCode)) {
			this._keyStates.set(keyCode,true);
			flambe.platform.BasicKeyboard._sharedEvent._internal_init(flambe.platform.BasicKeyboard._sharedEvent.id + 1,flambe.platform.KeyCodes.toKey(keyCode));
			this.down.emit(flambe.platform.BasicKeyboard._sharedEvent);
		}
		return true;
	}
	,isCodeDown: function(keyCode) {
		return this._keyStates.exists(keyCode);
	}
	,isDown: function(key) {
		return this.isCodeDown(flambe.platform.KeyCodes.toKeyCode(key));
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.BasicKeyboard
}
flambe.platform.BasicMouse = function(pointer) {
	this._pointer = pointer;
	this._source = flambe.input.EventSource.Mouse(flambe.platform.BasicMouse._sharedEvent);
	this.down = new flambe.util.Signal1();
	this.move = new flambe.util.Signal1();
	this.up = new flambe.util.Signal1();
	this.scroll = new flambe.util.Signal1();
	this._x = 0;
	this._y = 0;
	this._cursor = flambe.input.MouseCursor.Default;
	this._buttonStates = new IntHash();
};
$hxClasses["flambe.platform.BasicMouse"] = flambe.platform.BasicMouse;
flambe.platform.BasicMouse.__name__ = ["flambe","platform","BasicMouse"];
flambe.platform.BasicMouse.__interfaces__ = [flambe.input.Mouse];
flambe.platform.BasicMouse.prototype = {
	prepare: function(viewX,viewY,button) {
		this._x = viewX;
		this._y = viewY;
		flambe.platform.BasicMouse._sharedEvent._internal_init(flambe.platform.BasicMouse._sharedEvent.id + 1,viewX,viewY,button);
	}
	,isCodeDown: function(buttonCode) {
		return this._buttonStates.exists(buttonCode);
	}
	,submitScroll: function(viewX,viewY,velocity) {
		this._x = viewX;
		this._y = viewY;
		if(!this.scroll.hasListeners()) return false;
		this.scroll.emit(velocity);
		return true;
	}
	,submitUp: function(viewX,viewY,buttonCode) {
		if(this.isCodeDown(buttonCode)) {
			this._buttonStates.remove(buttonCode);
			this.prepare(viewX,viewY,flambe.platform.MouseCodes.toButton(buttonCode));
			this._pointer.submitUp(viewX,viewY,this._source);
			this.up.emit(flambe.platform.BasicMouse._sharedEvent);
		}
	}
	,submitMove: function(viewX,viewY) {
		this.prepare(viewX,viewY,null);
		this._pointer.submitMove(viewX,viewY,this._source);
		this.move.emit(flambe.platform.BasicMouse._sharedEvent);
	}
	,submitDown: function(viewX,viewY,buttonCode) {
		if(!this.isCodeDown(buttonCode)) {
			this._buttonStates.set(buttonCode,true);
			this.prepare(viewX,viewY,flambe.platform.MouseCodes.toButton(buttonCode));
			this._pointer.submitDown(viewX,viewY,this._source);
			this.down.emit(flambe.platform.BasicMouse._sharedEvent);
		}
	}
	,isDown: function(button) {
		return this.isCodeDown(flambe.platform.MouseCodes.toButtonCode(button));
	}
	,set_cursor: function(cursor) {
		return this._cursor = cursor;
	}
	,get_cursor: function() {
		return this._cursor;
	}
	,get_y: function() {
		return this._y;
	}
	,get_x: function() {
		return this._x;
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.BasicMouse
}
flambe.platform.BasicPointer = function(x,y,isDown) {
	if(isDown == null) isDown = false;
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.down = new flambe.util.Signal1();
	this.move = new flambe.util.Signal1();
	this.up = new flambe.util.Signal1();
	this._x = x;
	this._y = y;
	this._isDown = isDown;
};
$hxClasses["flambe.platform.BasicPointer"] = flambe.platform.BasicPointer;
flambe.platform.BasicPointer.__name__ = ["flambe","platform","BasicPointer"];
flambe.platform.BasicPointer.__interfaces__ = [flambe.input.Pointer];
flambe.platform.BasicPointer.prototype = {
	prepare: function(viewX,viewY,hit,source) {
		this._x = viewX;
		this._y = viewY;
		flambe.platform.BasicPointer._sharedEvent._internal_init(flambe.platform.BasicPointer._sharedEvent.id + 1,viewX,viewY,hit,source);
	}
	,submitUp: function(viewX,viewY,source) {
		if(!this._isDown) return;
		this._isDown = false;
		var chain = [];
		var hit = flambe.display.Sprite.hitTest(flambe.System.root,viewX,viewY);
		if(hit != null) {
			var entity = hit.owner;
			do {
				var sprite = flambe.display.Sprite.getFrom(entity);
				if(sprite != null) chain.push(sprite);
				entity = entity.parent;
			} while(entity != null);
		}
		this.prepare(viewX,viewY,hit,source);
		var _g = 0;
		while(_g < chain.length) {
			var sprite = chain[_g];
			++_g;
			var signal = sprite._internal_pointerUp;
			if(signal != null) {
				signal.emit(flambe.platform.BasicPointer._sharedEvent);
				if(flambe.platform.BasicPointer._sharedEvent._internal_stopped) return;
			}
		}
		this.up.emit(flambe.platform.BasicPointer._sharedEvent);
	}
	,submitMove: function(viewX,viewY,source) {
		var chain = [];
		var hit = flambe.display.Sprite.hitTest(flambe.System.root,viewX,viewY);
		if(hit != null) {
			var entity = hit.owner;
			do {
				var sprite = flambe.display.Sprite.getFrom(entity);
				if(sprite != null) chain.push(sprite);
				entity = entity.parent;
			} while(entity != null);
		}
		this.prepare(viewX,viewY,hit,source);
		var _g = 0;
		while(_g < chain.length) {
			var sprite = chain[_g];
			++_g;
			var signal = sprite._internal_pointerMove;
			if(signal != null) {
				signal.emit(flambe.platform.BasicPointer._sharedEvent);
				if(flambe.platform.BasicPointer._sharedEvent._internal_stopped) return;
			}
		}
		this.move.emit(flambe.platform.BasicPointer._sharedEvent);
	}
	,submitDown: function(viewX,viewY,source) {
		if(this._isDown) return;
		this._isDown = true;
		var chain = [];
		var hit = flambe.display.Sprite.hitTest(flambe.System.root,viewX,viewY);
		if(hit != null) {
			var entity = hit.owner;
			do {
				var sprite = flambe.display.Sprite.getFrom(entity);
				if(sprite != null) chain.push(sprite);
				entity = entity.parent;
			} while(entity != null);
		}
		this.prepare(viewX,viewY,hit,source);
		var _g = 0;
		while(_g < chain.length) {
			var sprite = chain[_g];
			++_g;
			var signal = sprite._internal_pointerDown;
			if(signal != null) {
				signal.emit(flambe.platform.BasicPointer._sharedEvent);
				if(flambe.platform.BasicPointer._sharedEvent._internal_stopped) return;
			}
		}
		this.down.emit(flambe.platform.BasicPointer._sharedEvent);
	}
	,isDown: function() {
		return this._isDown;
	}
	,get_y: function() {
		return this._y;
	}
	,get_x: function() {
		return this._x;
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.BasicPointer
}
flambe.platform.BasicTouch = function(pointer,maxPoints) {
	if(maxPoints == null) maxPoints = 4;
	this._pointer = pointer;
	this._maxPoints = maxPoints;
	this._pointMap = new IntHash();
	this._points = [];
	this.down = new flambe.util.Signal1();
	this.move = new flambe.util.Signal1();
	this.up = new flambe.util.Signal1();
};
$hxClasses["flambe.platform.BasicTouch"] = flambe.platform.BasicTouch;
flambe.platform.BasicTouch.__name__ = ["flambe","platform","BasicTouch"];
flambe.platform.BasicTouch.__interfaces__ = [flambe.input.Touch];
flambe.platform.BasicTouch.prototype = {
	submitUp: function(id,viewX,viewY) {
		var point = this._pointMap.get(id);
		if(point != null) {
			point._internal_init(viewX,viewY);
			this._pointMap.remove(id);
			HxOverrides.remove(this._points,point);
			if(this._pointerTouch == point) {
				this._pointerTouch = null;
				this._pointer.submitUp(viewX,viewY,point._internal_source);
			}
			this.up.emit(point);
		}
	}
	,submitMove: function(id,viewX,viewY) {
		var point = this._pointMap.get(id);
		if(point != null) {
			point._internal_init(viewX,viewY);
			if(this._pointerTouch == point) this._pointer.submitMove(viewX,viewY,point._internal_source);
			this.move.emit(point);
		}
	}
	,submitDown: function(id,viewX,viewY) {
		if(!this._pointMap.exists(id)) {
			var point = new flambe.input.TouchPoint(id);
			point._internal_init(viewX,viewY);
			this._pointMap.set(id,point);
			this._points.push(point);
			if(this._pointerTouch == null) {
				this._pointerTouch = point;
				this._pointer.submitDown(viewX,viewY,point._internal_source);
			}
			this.down.emit(point);
		}
	}
	,get_points: function() {
		return this._points.slice();
	}
	,get_maxPoints: function() {
		return this._maxPoints;
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.BasicTouch
}
flambe.sound = {}
flambe.sound.Sound = function() { }
$hxClasses["flambe.sound.Sound"] = flambe.sound.Sound;
flambe.sound.Sound.__name__ = ["flambe","sound","Sound"];
flambe.sound.Sound.prototype = {
	__class__: flambe.sound.Sound
}
flambe.platform.DummySound = function() {
	this._playback = new flambe.platform.DummyPlayback(this);
};
$hxClasses["flambe.platform.DummySound"] = flambe.platform.DummySound;
flambe.platform.DummySound.__name__ = ["flambe","platform","DummySound"];
flambe.platform.DummySound.__interfaces__ = [flambe.sound.Sound];
flambe.platform.DummySound.getInstance = function() {
	if(flambe.platform.DummySound._instance == null) flambe.platform.DummySound._instance = new flambe.platform.DummySound();
	return flambe.platform.DummySound._instance;
}
flambe.platform.DummySound.prototype = {
	get_duration: function() {
		return 0;
	}
	,loop: function(volume) {
		if(volume == null) volume = 1.0;
		return this._playback;
	}
	,play: function(volume) {
		if(volume == null) volume = 1.0;
		return this._playback;
	}
	,__class__: flambe.platform.DummySound
}
flambe.sound.Playback = function() { }
$hxClasses["flambe.sound.Playback"] = flambe.sound.Playback;
flambe.sound.Playback.__name__ = ["flambe","sound","Playback"];
flambe.sound.Playback.__interfaces__ = [flambe.util.Disposable];
flambe.sound.Playback.prototype = {
	__class__: flambe.sound.Playback
}
flambe.platform.DummyPlayback = function(sound) {
	this._sound = sound;
	this.volume = new flambe.animation.AnimatedFloat(0);
};
$hxClasses["flambe.platform.DummyPlayback"] = flambe.platform.DummyPlayback;
flambe.platform.DummyPlayback.__name__ = ["flambe","platform","DummyPlayback"];
flambe.platform.DummyPlayback.__interfaces__ = [flambe.sound.Playback];
flambe.platform.DummyPlayback.prototype = {
	dispose: function() {
	}
	,get_position: function() {
		return 0;
	}
	,get_ended: function() {
		return true;
	}
	,set_paused: function(paused) {
		return true;
	}
	,get_paused: function() {
		return true;
	}
	,get_sound: function() {
		return this._sound;
	}
	,__class__: flambe.platform.DummyPlayback
}
flambe.storage = {}
flambe.storage.Storage = function() { }
$hxClasses["flambe.storage.Storage"] = flambe.storage.Storage;
flambe.storage.Storage.__name__ = ["flambe","storage","Storage"];
flambe.storage.Storage.prototype = {
	__class__: flambe.storage.Storage
}
flambe.platform.DummyStorage = function() {
	this.clear();
};
$hxClasses["flambe.platform.DummyStorage"] = flambe.platform.DummyStorage;
flambe.platform.DummyStorage.__name__ = ["flambe","platform","DummyStorage"];
flambe.platform.DummyStorage.__interfaces__ = [flambe.storage.Storage];
flambe.platform.DummyStorage.prototype = {
	clear: function() {
		this._hash = new Hash();
	}
	,remove: function(key) {
		this._hash.remove(key);
	}
	,get: function(key,defaultValue) {
		return this._hash.exists(key)?this._hash.get(key):defaultValue;
	}
	,set: function(key,value) {
		this._hash.set(key,value);
		return true;
	}
	,get_supported: function() {
		return false;
	}
	,__class__: flambe.platform.DummyStorage
}
flambe.platform.DummyTouch = function() {
	this.down = new flambe.util.Signal1();
	this.move = new flambe.util.Signal1();
	this.up = new flambe.util.Signal1();
};
$hxClasses["flambe.platform.DummyTouch"] = flambe.platform.DummyTouch;
flambe.platform.DummyTouch.__name__ = ["flambe","platform","DummyTouch"];
flambe.platform.DummyTouch.__interfaces__ = [flambe.input.Touch];
flambe.platform.DummyTouch.prototype = {
	get_points: function() {
		return [];
	}
	,get_maxPoints: function() {
		return 0;
	}
	,get_supported: function() {
		return false;
	}
	,__class__: flambe.platform.DummyTouch
}
flambe.platform.EventGroup = function() {
	this._entries = [];
};
$hxClasses["flambe.platform.EventGroup"] = flambe.platform.EventGroup;
flambe.platform.EventGroup.__name__ = ["flambe","platform","EventGroup"];
flambe.platform.EventGroup.__interfaces__ = [flambe.util.Disposable];
flambe.platform.EventGroup.prototype = {
	dispose: function() {
		var _g = 0, _g1 = this._entries;
		while(_g < _g1.length) {
			var entry = _g1[_g];
			++_g;
			entry.dispatcher.removeEventListener(entry.type,entry.listener,false);
		}
		this._entries = [];
	}
	,addDisposingListener: function(dispatcher,type,listener) {
		var _g = this;
		this.addListener(dispatcher,type,function(event) {
			_g.dispose();
			listener(event);
		});
	}
	,addListener: function(dispatcher,type,listener) {
		dispatcher.addEventListener(type,listener,false);
		this._entries.push(new flambe.platform._EventGroup.Entry(dispatcher,type,listener));
	}
	,__class__: flambe.platform.EventGroup
}
flambe.platform._EventGroup = {}
flambe.platform._EventGroup.Entry = function(dispatcher,type,listener) {
	this.dispatcher = dispatcher;
	this.type = type;
	this.listener = listener;
};
$hxClasses["flambe.platform._EventGroup.Entry"] = flambe.platform._EventGroup.Entry;
flambe.platform._EventGroup.Entry.__name__ = ["flambe","platform","_EventGroup","Entry"];
flambe.platform._EventGroup.Entry.prototype = {
	__class__: flambe.platform._EventGroup.Entry
}
flambe.platform.KeyCodes = function() { }
$hxClasses["flambe.platform.KeyCodes"] = flambe.platform.KeyCodes;
flambe.platform.KeyCodes.__name__ = ["flambe","platform","KeyCodes"];
flambe.platform.KeyCodes.toKey = function(keyCode) {
	switch(keyCode) {
	case 65:
		return flambe.input.Key.A;
	case 66:
		return flambe.input.Key.B;
	case 67:
		return flambe.input.Key.C;
	case 68:
		return flambe.input.Key.D;
	case 69:
		return flambe.input.Key.E;
	case 70:
		return flambe.input.Key.F;
	case 71:
		return flambe.input.Key.G;
	case 72:
		return flambe.input.Key.H;
	case 73:
		return flambe.input.Key.I;
	case 74:
		return flambe.input.Key.J;
	case 75:
		return flambe.input.Key.K;
	case 76:
		return flambe.input.Key.L;
	case 77:
		return flambe.input.Key.M;
	case 78:
		return flambe.input.Key.N;
	case 79:
		return flambe.input.Key.O;
	case 80:
		return flambe.input.Key.P;
	case 81:
		return flambe.input.Key.Q;
	case 82:
		return flambe.input.Key.R;
	case 83:
		return flambe.input.Key.S;
	case 84:
		return flambe.input.Key.T;
	case 85:
		return flambe.input.Key.U;
	case 86:
		return flambe.input.Key.V;
	case 87:
		return flambe.input.Key.W;
	case 88:
		return flambe.input.Key.X;
	case 89:
		return flambe.input.Key.Y;
	case 90:
		return flambe.input.Key.Z;
	case 48:
		return flambe.input.Key.Number0;
	case 49:
		return flambe.input.Key.Number1;
	case 50:
		return flambe.input.Key.Number2;
	case 51:
		return flambe.input.Key.Number3;
	case 52:
		return flambe.input.Key.Number4;
	case 53:
		return flambe.input.Key.Number5;
	case 54:
		return flambe.input.Key.Number6;
	case 55:
		return flambe.input.Key.Number7;
	case 56:
		return flambe.input.Key.Number8;
	case 57:
		return flambe.input.Key.Number9;
	case 96:
		return flambe.input.Key.Numpad0;
	case 97:
		return flambe.input.Key.Numpad1;
	case 98:
		return flambe.input.Key.Numpad2;
	case 99:
		return flambe.input.Key.Numpad3;
	case 100:
		return flambe.input.Key.Numpad4;
	case 101:
		return flambe.input.Key.Numpad5;
	case 102:
		return flambe.input.Key.Numpad6;
	case 103:
		return flambe.input.Key.Numpad7;
	case 104:
		return flambe.input.Key.Numpad8;
	case 105:
		return flambe.input.Key.Numpad9;
	case 107:
		return flambe.input.Key.NumpadAdd;
	case 110:
		return flambe.input.Key.NumpadDecimal;
	case 111:
		return flambe.input.Key.NumpadDivide;
	case 108:
		return flambe.input.Key.NumpadEnter;
	case 106:
		return flambe.input.Key.NumpadMultiply;
	case 109:
		return flambe.input.Key.NumpadSubtract;
	case 112:
		return flambe.input.Key.F1;
	case 113:
		return flambe.input.Key.F2;
	case 114:
		return flambe.input.Key.F3;
	case 115:
		return flambe.input.Key.F4;
	case 116:
		return flambe.input.Key.F5;
	case 117:
		return flambe.input.Key.F6;
	case 118:
		return flambe.input.Key.F7;
	case 119:
		return flambe.input.Key.F8;
	case 120:
		return flambe.input.Key.F9;
	case 121:
		return flambe.input.Key.F10;
	case 122:
		return flambe.input.Key.F11;
	case 123:
		return flambe.input.Key.F12;
	case 37:
		return flambe.input.Key.Left;
	case 38:
		return flambe.input.Key.Up;
	case 39:
		return flambe.input.Key.Right;
	case 40:
		return flambe.input.Key.Down;
	case 18:
		return flambe.input.Key.Alt;
	case 192:
		return flambe.input.Key.Backquote;
	case 220:
		return flambe.input.Key.Backslash;
	case 8:
		return flambe.input.Key.Backspace;
	case 20:
		return flambe.input.Key.CapsLock;
	case 188:
		return flambe.input.Key.Comma;
	case 15:
		return flambe.input.Key.Command;
	case 17:
		return flambe.input.Key.Control;
	case 46:
		return flambe.input.Key.Delete;
	case 35:
		return flambe.input.Key.End;
	case 13:
		return flambe.input.Key.Enter;
	case 187:
		return flambe.input.Key.Equals;
	case 27:
		return flambe.input.Key.Escape;
	case 36:
		return flambe.input.Key.Home;
	case 45:
		return flambe.input.Key.Insert;
	case 219:
		return flambe.input.Key.LeftBracket;
	case 189:
		return flambe.input.Key.Minus;
	case 34:
		return flambe.input.Key.PageDown;
	case 33:
		return flambe.input.Key.PageUp;
	case 190:
		return flambe.input.Key.Period;
	case 222:
		return flambe.input.Key.Quote;
	case 221:
		return flambe.input.Key.RightBracket;
	case 186:
		return flambe.input.Key.Semicolon;
	case 16:
		return flambe.input.Key.Shift;
	case 191:
		return flambe.input.Key.Slash;
	case 32:
		return flambe.input.Key.Space;
	case 9:
		return flambe.input.Key.Tab;
	case 16777234:
		return flambe.input.Key.Menu;
	case 16777247:
		return flambe.input.Key.Search;
	}
	return flambe.input.Key.Unknown(keyCode);
}
flambe.platform.KeyCodes.toKeyCode = function(key) {
	var $e = (key);
	switch( $e[1] ) {
	case 0:
		return 65;
	case 1:
		return 66;
	case 2:
		return 67;
	case 3:
		return 68;
	case 4:
		return 69;
	case 5:
		return 70;
	case 6:
		return 71;
	case 7:
		return 72;
	case 8:
		return 73;
	case 9:
		return 74;
	case 10:
		return 75;
	case 11:
		return 76;
	case 12:
		return 77;
	case 13:
		return 78;
	case 14:
		return 79;
	case 15:
		return 80;
	case 16:
		return 81;
	case 17:
		return 82;
	case 18:
		return 83;
	case 19:
		return 84;
	case 20:
		return 85;
	case 21:
		return 86;
	case 22:
		return 87;
	case 23:
		return 88;
	case 24:
		return 89;
	case 25:
		return 90;
	case 26:
		return 48;
	case 27:
		return 49;
	case 28:
		return 50;
	case 29:
		return 51;
	case 30:
		return 52;
	case 31:
		return 53;
	case 32:
		return 54;
	case 33:
		return 55;
	case 34:
		return 56;
	case 35:
		return 57;
	case 36:
		return 96;
	case 37:
		return 97;
	case 38:
		return 98;
	case 39:
		return 99;
	case 40:
		return 100;
	case 41:
		return 101;
	case 42:
		return 102;
	case 43:
		return 103;
	case 44:
		return 104;
	case 45:
		return 105;
	case 46:
		return 107;
	case 47:
		return 110;
	case 48:
		return 111;
	case 49:
		return 108;
	case 50:
		return 106;
	case 51:
		return 109;
	case 52:
		return 112;
	case 53:
		return 113;
	case 54:
		return 114;
	case 55:
		return 115;
	case 56:
		return 116;
	case 57:
		return 117;
	case 58:
		return 118;
	case 59:
		return 119;
	case 60:
		return 120;
	case 61:
		return 121;
	case 62:
		return 122;
	case 63:
		return 123;
	case 64:
		return 124;
	case 65:
		return 125;
	case 66:
		return 126;
	case 67:
		return 37;
	case 68:
		return 38;
	case 69:
		return 39;
	case 70:
		return 40;
	case 71:
		return 18;
	case 72:
		return 192;
	case 73:
		return 220;
	case 74:
		return 8;
	case 75:
		return 20;
	case 76:
		return 188;
	case 77:
		return 15;
	case 78:
		return 17;
	case 79:
		return 46;
	case 80:
		return 35;
	case 81:
		return 13;
	case 82:
		return 187;
	case 83:
		return 27;
	case 84:
		return 36;
	case 85:
		return 45;
	case 86:
		return 219;
	case 87:
		return 189;
	case 88:
		return 34;
	case 89:
		return 33;
	case 90:
		return 190;
	case 91:
		return 222;
	case 92:
		return 221;
	case 93:
		return 186;
	case 94:
		return 16;
	case 95:
		return 191;
	case 96:
		return 32;
	case 97:
		return 9;
	case 98:
		return 16777234;
	case 99:
		return 16777247;
	case 100:
		var keyCode = $e[2];
		return keyCode;
	}
}
flambe.platform.MainLoop = function() {
	this._tickables = [];
};
$hxClasses["flambe.platform.MainLoop"] = flambe.platform.MainLoop;
flambe.platform.MainLoop.__name__ = ["flambe","platform","MainLoop"];
flambe.platform.MainLoop.updateEntity = function(entity,dt) {
	var speed = flambe.SpeedAdjuster.getFrom(entity);
	if(speed != null) {
		speed._internal_realDt = dt;
		dt *= speed.scale.get__();
		if(dt <= 0) {
			speed.onUpdate(dt);
			return;
		}
	}
	var p = entity.firstComponent;
	while(p != null) {
		var next = p.next;
		p.onUpdate(dt);
		p = next;
	}
	var p1 = entity.firstChild;
	while(p1 != null) {
		var next = p1.next;
		flambe.platform.MainLoop.updateEntity(p1,dt);
		p1 = next;
	}
}
flambe.platform.MainLoop.prototype = {
	addTickable: function(t) {
		this._tickables.push(t);
	}
	,render: function(renderer) {
		var graphics = renderer.willRender();
		if(graphics != null) {
			flambe.display.Sprite.render(flambe.System.root,graphics);
			renderer.didRender();
		}
	}
	,update: function(dt) {
		if(dt <= 0) {
			flambe.Log.warn("Zero or negative time elapsed since the last frame!",["dt",dt]);
			return;
		}
		if(dt > 1) dt = 1;
		var ii = 0;
		while(ii < this._tickables.length) {
			var t = this._tickables[ii];
			if(t == null || t.update(dt)) this._tickables.splice(ii,1); else ++ii;
		}
		flambe.System.volume.update(dt);
		flambe.platform.MainLoop.updateEntity(flambe.System.root,dt);
	}
	,__class__: flambe.platform.MainLoop
}
flambe.platform.ManifestBuilder = function() { }
$hxClasses["flambe.platform.ManifestBuilder"] = flambe.platform.ManifestBuilder;
flambe.platform.ManifestBuilder.__name__ = ["flambe","platform","ManifestBuilder"];
flambe.platform.MouseCodes = function() { }
$hxClasses["flambe.platform.MouseCodes"] = flambe.platform.MouseCodes;
flambe.platform.MouseCodes.__name__ = ["flambe","platform","MouseCodes"];
flambe.platform.MouseCodes.toButton = function(buttonCode) {
	switch(buttonCode) {
	case 0:
		return flambe.input.MouseButton.Left;
	case 1:
		return flambe.input.MouseButton.Middle;
	case 2:
		return flambe.input.MouseButton.Right;
	}
	return flambe.input.MouseButton.Unknown(buttonCode);
}
flambe.platform.MouseCodes.toButtonCode = function(button) {
	var $e = (button);
	switch( $e[1] ) {
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		var buttonCode = $e[2];
		return buttonCode;
	}
}
flambe.platform.Renderer = function() { }
$hxClasses["flambe.platform.Renderer"] = flambe.platform.Renderer;
flambe.platform.Renderer.__name__ = ["flambe","platform","Renderer"];
flambe.platform.Renderer.prototype = {
	__class__: flambe.platform.Renderer
}
flambe.platform.Tickable = function() { }
$hxClasses["flambe.platform.Tickable"] = flambe.platform.Tickable;
flambe.platform.Tickable.__name__ = ["flambe","platform","Tickable"];
flambe.platform.Tickable.prototype = {
	__class__: flambe.platform.Tickable
}
flambe.platform.html.CanvasGraphics = function(canvas) {
	this._firstDraw = false;
	this._canvasCtx = canvas.getContext("2d");
};
$hxClasses["flambe.platform.html.CanvasGraphics"] = flambe.platform.html.CanvasGraphics;
flambe.platform.html.CanvasGraphics.__name__ = ["flambe","platform","html","CanvasGraphics"];
flambe.platform.html.CanvasGraphics.__interfaces__ = [flambe.display.Graphics];
flambe.platform.html.CanvasGraphics.prototype = {
	willRender: function() {
		this._firstDraw = true;
	}
	,applyScissor: function(x,y,width,height) {
		this._canvasCtx.beginPath();
		this._canvasCtx.rect(Std["int"](x),Std["int"](y),Std["int"](width),Std["int"](height));
		this._canvasCtx.clip();
	}
	,setBlendMode: function(blendMode) {
		var op;
		switch( (blendMode)[1] ) {
		case 0:
			op = "source-over";
			break;
		case 1:
			op = "lighter";
			break;
		case 2:
			op = "source-over";
			break;
		}
		this._canvasCtx.globalCompositeOperation = op;
	}
	,setAlpha: function(alpha) {
		this._canvasCtx.globalAlpha = alpha;
	}
	,multiplyAlpha: function(factor) {
		this._canvasCtx.globalAlpha *= factor;
	}
	,fillRect: function(color,x,y,width,height) {
		if(this._firstDraw) {
			this._firstDraw = false;
			this._canvasCtx.globalCompositeOperation = "copy";
			this.fillRect(color,x,y,width,height);
			this._canvasCtx.globalCompositeOperation = "source-over";
			return;
		}
		this._canvasCtx.fillStyle = "#" + ("00000" + color.toString(16)).slice(-6);
		this._canvasCtx.fillRect(Std["int"](x),Std["int"](y),Std["int"](width),Std["int"](height));
	}
	,drawPattern: function(texture,x,y,width,height) {
		if(this._firstDraw) {
			this._firstDraw = false;
			this._canvasCtx.globalCompositeOperation = "copy";
			this.drawPattern(texture,x,y,width,height);
			this._canvasCtx.globalCompositeOperation = "source-over";
			return;
		}
		var texture1 = texture;
		if(texture1.pattern == null) texture1.pattern = this._canvasCtx.createPattern(texture1.image,"repeat");
		this._canvasCtx.fillStyle = texture1.pattern;
		this._canvasCtx.fillRect(Std["int"](x),Std["int"](y),Std["int"](width),Std["int"](height));
	}
	,drawSubImage: function(texture,destX,destY,sourceX,sourceY,sourceW,sourceH) {
		if(this._firstDraw) {
			this._firstDraw = false;
			this._canvasCtx.globalCompositeOperation = "copy";
			this.drawSubImage(texture,destX,destY,sourceX,sourceY,sourceW,sourceH);
			this._canvasCtx.globalCompositeOperation = "source-over";
			return;
		}
		var texture1 = texture;
		this._canvasCtx.drawImage(texture1.image,Std["int"](sourceX),Std["int"](sourceY),Std["int"](sourceW),Std["int"](sourceH),Std["int"](destX),Std["int"](destY),Std["int"](sourceW),Std["int"](sourceH));
	}
	,drawImage: function(texture,x,y) {
		if(this._firstDraw) {
			this._firstDraw = false;
			this._canvasCtx.globalCompositeOperation = "copy";
			this.drawImage(texture,x,y);
			this._canvasCtx.globalCompositeOperation = "source-over";
			return;
		}
		var texture1 = texture;
		this._canvasCtx.drawImage(texture1.image,Std["int"](x),Std["int"](y));
	}
	,restore: function() {
		this._canvasCtx.restore();
	}
	,transform: function(m00,m10,m01,m11,m02,m12) {
		this._canvasCtx.transform(m00,m10,m01,m11,Std["int"](m02),Std["int"](m12));
	}
	,rotate: function(rotation) {
		this._canvasCtx.rotate(flambe.math.FMath.toRadians(rotation));
	}
	,scale: function(x,y) {
		this._canvasCtx.scale(x,y);
	}
	,translate: function(x,y) {
		this._canvasCtx.translate(Std["int"](x),Std["int"](y));
	}
	,save: function() {
		this._canvasCtx.save();
	}
	,clear: function() {
		this._canvasCtx.fillStyle = "#ffffff";
		this._canvasCtx.fillRect(0,0,this._canvasCtx.canvas.width,this._canvasCtx.canvas.height);
	}
	,__class__: flambe.platform.html.CanvasGraphics
}
flambe.platform.html.CanvasRenderer = function(canvas) {
	this._graphics = new flambe.platform.html.CanvasGraphics(canvas);
	this._graphics.clear();
};
$hxClasses["flambe.platform.html.CanvasRenderer"] = flambe.platform.html.CanvasRenderer;
flambe.platform.html.CanvasRenderer.__name__ = ["flambe","platform","html","CanvasRenderer"];
flambe.platform.html.CanvasRenderer.__interfaces__ = [flambe.platform.Renderer];
flambe.platform.html.CanvasRenderer.prototype = {
	didRender: function() {
	}
	,willRender: function() {
		this._graphics.willRender();
		return this._graphics;
	}
	,createEmptyTexture: function(width,height) {
		return new flambe.platform.html.CanvasTexture(flambe.platform.html.HtmlUtil.createEmptyCanvas(width,height));
	}
	,createTexture: function(image) {
		return new flambe.platform.html.CanvasTexture(flambe.platform.html.CanvasRenderer.CANVAS_TEXTURES?flambe.platform.html.HtmlUtil.createCanvas(image):image);
	}
	,__class__: flambe.platform.html.CanvasRenderer
}
flambe.platform.html.CanvasTexture = function(image) {
	this._graphics = null;
	this.image = image;
};
$hxClasses["flambe.platform.html.CanvasTexture"] = flambe.platform.html.CanvasTexture;
flambe.platform.html.CanvasTexture.__name__ = ["flambe","platform","html","CanvasTexture"];
flambe.platform.html.CanvasTexture.__interfaces__ = [flambe.display.Texture];
flambe.platform.html.CanvasTexture.prototype = {
	getContext2d: function() {
		if(!Std["is"](this.image,HTMLCanvasElement)) this.image = flambe.platform.html.HtmlUtil.createCanvas(this.image);
		return this.image.getContext("2d");
	}
	,get_graphics: function() {
		if(this._graphics == null) {
			this.getContext2d();
			this._graphics = new flambe.platform.html._CanvasTexture.InternalGraphics(this);
		}
		return this._graphics;
	}
	,get_height: function() {
		return this.image.height;
	}
	,get_width: function() {
		return this.image.width;
	}
	,dirtyContents: function() {
		this.pattern = null;
	}
	,writePixels: function(pixels,x,y,sourceW,sourceH) {
		var ctx2d = this.getContext2d();
		var imageData = ctx2d.createImageData(sourceW,sourceH);
		var data = imageData.data;
		if(data.set != null) data.set(pixels.getData()); else {
			var size = 4 * sourceW * sourceH;
			var _g = 0;
			while(_g < size) {
				var ii = _g++;
				data[ii] = pixels.get(ii);
			}
		}
		ctx2d.putImageData(imageData,x,y);
		this.dirtyContents();
	}
	,readPixels: function(x,y,width,height) {
		return haxe.io.Bytes.ofData(this.getContext2d().getImageData(x,y,width,height).data);
	}
	,__class__: flambe.platform.html.CanvasTexture
}
flambe.platform.html._CanvasTexture = {}
flambe.platform.html._CanvasTexture.InternalGraphics = function(renderTarget) {
	flambe.platform.html.CanvasGraphics.call(this,renderTarget.image);
	this._renderTarget = renderTarget;
};
$hxClasses["flambe.platform.html._CanvasTexture.InternalGraphics"] = flambe.platform.html._CanvasTexture.InternalGraphics;
flambe.platform.html._CanvasTexture.InternalGraphics.__name__ = ["flambe","platform","html","_CanvasTexture","InternalGraphics"];
flambe.platform.html._CanvasTexture.InternalGraphics.__super__ = flambe.platform.html.CanvasGraphics;
flambe.platform.html._CanvasTexture.InternalGraphics.prototype = $extend(flambe.platform.html.CanvasGraphics.prototype,{
	fillRect: function(color,x,y,width,height) {
		flambe.platform.html.CanvasGraphics.prototype.fillRect.call(this,color,x,y,width,height);
		this._renderTarget.dirtyContents();
	}
	,drawPattern: function(texture,x,y,width,height) {
		flambe.platform.html.CanvasGraphics.prototype.drawPattern.call(this,texture,x,y,width,height);
		this._renderTarget.dirtyContents();
	}
	,drawSubImage: function(texture,destX,destY,sourceX,sourceY,sourceW,sourceH) {
		flambe.platform.html.CanvasGraphics.prototype.drawSubImage.call(this,texture,destX,destY,sourceX,sourceY,sourceW,sourceH);
		this._renderTarget.dirtyContents();
	}
	,drawImage: function(texture,x,y) {
		flambe.platform.html.CanvasGraphics.prototype.drawImage.call(this,texture,x,y);
		this._renderTarget.dirtyContents();
	}
	,__class__: flambe.platform.html._CanvasTexture.InternalGraphics
});
flambe.platform.html.HtmlAssetPackLoader = function(platform,manifest) {
	flambe.platform.BasicAssetPackLoader.call(this,platform,manifest);
};
$hxClasses["flambe.platform.html.HtmlAssetPackLoader"] = flambe.platform.html.HtmlAssetPackLoader;
flambe.platform.html.HtmlAssetPackLoader.__name__ = ["flambe","platform","html","HtmlAssetPackLoader"];
flambe.platform.html.HtmlAssetPackLoader.detectAudioFormats = function() {
	var element = js.Lib.document.createElement("audio");
	if(element == null || element.canPlayType == null) return [];
	var blacklist = new EReg("\\b(iPhone|iPod|iPad|Android)\\b","");
	if(!flambe.platform.html.WebAudioSound.get_supported() && blacklist.match(js.Lib.window.navigator.userAgent)) return [];
	var formats = [{ extension : "m4a", type : "audio/mp4; codecs=mp4a"},{ extension : "mp3", type : "audio/mpeg"},{ extension : "ogg", type : "audio/ogg; codecs=vorbis"},{ extension : "wav", type : "audio/wav"}];
	var result = [];
	var _g = 0;
	while(_g < formats.length) {
		var format = formats[_g];
		++_g;
		if(element.canPlayType(format.type) != "") result.push(format.extension);
	}
	return result;
}
flambe.platform.html.HtmlAssetPackLoader.__super__ = flambe.platform.BasicAssetPackLoader;
flambe.platform.html.HtmlAssetPackLoader.prototype = $extend(flambe.platform.BasicAssetPackLoader.prototype,{
	handleLoad: function(entry,asset) {
		this.handleProgress(entry,entry.bytes);
		flambe.platform.BasicAssetPackLoader.prototype.handleLoad.call(this,entry,asset);
	}
	,getAudioFormats: function() {
		if(flambe.platform.html.HtmlAssetPackLoader._audioFormats == null) flambe.platform.html.HtmlAssetPackLoader._audioFormats = flambe.platform.html.HtmlAssetPackLoader.detectAudioFormats();
		return flambe.platform.html.HtmlAssetPackLoader._audioFormats;
	}
	,loadEntry: function(url,entry) {
		var _g = this;
		switch( (entry.type)[1] ) {
		case 0:
			var image = new Image();
			image.onload = function(_) {
				if(image.width > 1024 || image.height > 1024) flambe.Log.warn("Images larger than 1024px on a side will prevent GPU acceleration" + " on some platforms (iOS)",["url",url,"width",image.width,"height",image.height]);
				var texture = _g._platform.getRenderer().createTexture(image);
				if(texture != null) _g.handleLoad(entry,texture); else _g.handleTextureError(entry);
			};
			image.onerror = function(_) {
				_g.handleError(entry,"Failed to load image");
			};
			image.src = url;
			break;
		case 1:
			if(flambe.platform.html.WebAudioSound.get_supported()) {
				var req = new XMLHttpRequest();
				req.open("GET",url,true);
				req.responseType = "arraybuffer";
				req.onload = function() {
					flambe.platform.html.WebAudioSound.ctx.decodeAudioData(req.response,function(buffer) {
						_g.handleLoad(entry,new flambe.platform.html.WebAudioSound(buffer));
					},function() {
						flambe.Log.warn("Couldn't decode Web Audio, ignoring this asset." + " Is this a buggy browser?",["url",url]);
						_g.handleLoad(entry,flambe.platform.DummySound.getInstance());
					});
				};
				req.onerror = function() {
					_g.handleError(entry,"Failed to load audio");
				};
				req.send();
			} else {
				var audio = js.Lib.document.createElement("audio");
				audio.preload = "auto";
				var ref = ++flambe.platform.html.HtmlAssetPackLoader._mediaRefCount;
				if(flambe.platform.html.HtmlAssetPackLoader._mediaElements == null) flambe.platform.html.HtmlAssetPackLoader._mediaElements = new IntHash();
				flambe.platform.html.HtmlAssetPackLoader._mediaElements.set(ref,audio);
				var events = new flambe.platform.EventGroup();
				events.addDisposingListener(audio,"canplaythrough",function(_) {
					flambe.platform.html.HtmlAssetPackLoader._mediaElements.remove(ref);
					_g.handleLoad(entry,new flambe.platform.html.HtmlSound(audio));
				});
				events.addDisposingListener(audio,"error",function(_) {
					flambe.platform.html.HtmlAssetPackLoader._mediaElements.remove(ref);
					_g.handleError(entry,"Failed to load audio: " + Std.string(audio.error.code));
				});
				audio.src = url;
				audio.load();
			}
			break;
		case 2:
			var http = new haxe.Http(url);
			http.onData = function(data) {
				_g.handleLoad(entry,data);
			};
			http.onError = function(error) {
				_g.handleError(entry,"Failed to load data: " + error);
			};
			http.request(false);
			break;
		}
	}
	,__class__: flambe.platform.html.HtmlAssetPackLoader
});
flambe.platform.html.HtmlExternal = function() {
};
$hxClasses["flambe.platform.html.HtmlExternal"] = flambe.platform.html.HtmlExternal;
flambe.platform.html.HtmlExternal.__name__ = ["flambe","platform","html","HtmlExternal"];
flambe.platform.html.HtmlExternal.__interfaces__ = [flambe.external.External];
flambe.platform.html.HtmlExternal.prototype = {
	bind: function(name,fn) {
		Reflect.setField(js.Lib.window,name,fn);
	}
	,call: function(name,params) {
		if(params == null) params = [];
		var method = Reflect.field(js.Lib.window,name);
		return Reflect.callMethod(null,method,params);
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.html.HtmlExternal
}
flambe.util.LogHandler = function() { }
$hxClasses["flambe.util.LogHandler"] = flambe.util.LogHandler;
flambe.util.LogHandler.__name__ = ["flambe","util","LogHandler"];
flambe.util.LogHandler.prototype = {
	__class__: flambe.util.LogHandler
}
flambe.platform.html.HtmlLogHandler = function(tag) {
	this._tagPrefix = tag + ": ";
};
$hxClasses["flambe.platform.html.HtmlLogHandler"] = flambe.platform.html.HtmlLogHandler;
flambe.platform.html.HtmlLogHandler.__name__ = ["flambe","platform","html","HtmlLogHandler"];
flambe.platform.html.HtmlLogHandler.__interfaces__ = [flambe.util.LogHandler];
flambe.platform.html.HtmlLogHandler.isSupported = function() {
	return typeof console == "object" && console.info != null;
}
flambe.platform.html.HtmlLogHandler.prototype = {
	log: function(level,message) {
		message = this._tagPrefix + message;
		switch( (level)[1] ) {
		case 0:
			console.info(message);
			break;
		case 1:
			console.warn(message);
			break;
		case 2:
			console.error(message);
			break;
		}
	}
	,__class__: flambe.platform.html.HtmlLogHandler
}
flambe.platform.html.HtmlMouse = function(pointer,canvas) {
	flambe.platform.BasicMouse.call(this,pointer);
	this._canvas = canvas;
};
$hxClasses["flambe.platform.html.HtmlMouse"] = flambe.platform.html.HtmlMouse;
flambe.platform.html.HtmlMouse.__name__ = ["flambe","platform","html","HtmlMouse"];
flambe.platform.html.HtmlMouse.__super__ = flambe.platform.BasicMouse;
flambe.platform.html.HtmlMouse.prototype = $extend(flambe.platform.BasicMouse.prototype,{
	set_cursor: function(cursor) {
		var name;
		switch( (cursor)[1] ) {
		case 0:
			name = "";
			break;
		case 1:
			name = "pointer";
			break;
		case 2:
			name = "none";
			break;
		}
		this._canvas.style.cursor = name;
		return flambe.platform.BasicMouse.prototype.set_cursor.call(this,cursor);
	}
	,__class__: flambe.platform.html.HtmlMouse
});
flambe.platform.html.HtmlSound = function(audioElement) {
	this.audioElement = audioElement;
};
$hxClasses["flambe.platform.html.HtmlSound"] = flambe.platform.html.HtmlSound;
flambe.platform.html.HtmlSound.__name__ = ["flambe","platform","html","HtmlSound"];
flambe.platform.html.HtmlSound.__interfaces__ = [flambe.sound.Sound];
flambe.platform.html.HtmlSound.prototype = {
	get_duration: function() {
		return this.audioElement.duration;
	}
	,loop: function(volume) {
		if(volume == null) volume = 1.0;
		return new flambe.platform.html._HtmlSound.HtmlPlayback(this,volume,true);
	}
	,play: function(volume) {
		if(volume == null) volume = 1.0;
		return new flambe.platform.html._HtmlSound.HtmlPlayback(this,volume,false);
	}
	,__class__: flambe.platform.html.HtmlSound
}
flambe.platform.html._HtmlSound = {}
flambe.platform.html._HtmlSound.HtmlPlayback = function(sound,volume,loop) {
	var _g = this;
	this._sound = sound;
	this._tickableAdded = false;
	this._clonedElement = js.Lib.document.createElement("audio");
	this._clonedElement.loop = loop;
	this._clonedElement.src = sound.audioElement.src;
	this.volume = new flambe.animation.AnimatedFloat(volume,function(_,_1) {
		_g.updateVolume();
	});
	this.updateVolume();
	this.playAudio();
};
$hxClasses["flambe.platform.html._HtmlSound.HtmlPlayback"] = flambe.platform.html._HtmlSound.HtmlPlayback;
flambe.platform.html._HtmlSound.HtmlPlayback.__name__ = ["flambe","platform","html","_HtmlSound","HtmlPlayback"];
flambe.platform.html._HtmlSound.HtmlPlayback.__interfaces__ = [flambe.platform.Tickable,flambe.sound.Playback];
flambe.platform.html._HtmlSound.HtmlPlayback.prototype = {
	updateVolume: function() {
		this._clonedElement.volume = flambe.System.volume.get__() * this.volume.get__();
	}
	,playAudio: function() {
		var _g = this;
		this._clonedElement.play();
		if(!this._tickableAdded) {
			flambe.platform.html.HtmlPlatform.instance.mainLoop.addTickable(this);
			this._tickableAdded = true;
			this._volumeBinding = flambe.System.volume.get_changed().connect(function(_,_1) {
				_g.updateVolume();
			});
		}
	}
	,dispose: function() {
		this.set_paused(true);
	}
	,update: function(dt) {
		this.volume.update(dt);
		if(this.get_ended() || this.get_paused()) {
			this._tickableAdded = false;
			this._volumeBinding.dispose();
			return true;
		}
		return false;
	}
	,get_position: function() {
		return this._clonedElement.currentTime;
	}
	,get_ended: function() {
		return this._clonedElement.ended;
	}
	,set_paused: function(paused) {
		if(this._clonedElement.paused != paused) {
			if(paused) this._clonedElement.pause(); else this.playAudio();
		}
		return paused;
	}
	,get_paused: function() {
		return this._clonedElement.paused;
	}
	,get_sound: function() {
		return this._sound;
	}
	,__class__: flambe.platform.html._HtmlSound.HtmlPlayback
}
flambe.platform.html.HtmlStage = function(canvas) {
	var _g = this;
	this._canvas = canvas;
	this.resize = new flambe.util.Signal0();
	this.scaleFactor = flambe.platform.html.HtmlStage.computeScaleFactor();
	if(this.scaleFactor != 1) {
		flambe.Log.info("Reversing device DPI scaling",["scaleFactor",this.scaleFactor]);
		flambe.platform.html.HtmlUtil.setVendorStyle(this._canvas,"transform-origin","top left");
		flambe.platform.html.HtmlUtil.setVendorStyle(this._canvas,"transform","scale(" + 1 / this.scaleFactor + ")");
	}
	if(flambe.platform.html.HtmlUtil.SHOULD_HIDE_MOBILE_BROWSER) {
		window.addEventListener("orientationchange",function() {
			flambe.platform.html.HtmlUtil.callLater($bind(_g,_g.hideMobileBrowser),200);
		},false);
		this.hideMobileBrowser();
	}
	window.addEventListener("resize",$bind(this,this.onWindowResize),false);
	this.onWindowResize();
	this.orientation = new flambe.util.Value(null);
	if(window.orientation != null) {
		window.addEventListener("orientationchange",$bind(this,this.onOrientationChange),false);
		this.onOrientationChange();
	}
	this.fullscreen = new flambe.util.Value(false);
	flambe.platform.html.HtmlUtil.addVendorListener(js.Lib.document,"fullscreenchange",function(_) {
		_g.updateFullscreen();
	},false);
	flambe.platform.html.HtmlUtil.addVendorListener(js.Lib.document,"fullscreenerror",function(_) {
		flambe.Log.warn("Error when requesting fullscreen");
	},false);
	this.updateFullscreen();
};
$hxClasses["flambe.platform.html.HtmlStage"] = flambe.platform.html.HtmlStage;
flambe.platform.html.HtmlStage.__name__ = ["flambe","platform","html","HtmlStage"];
flambe.platform.html.HtmlStage.__interfaces__ = [flambe.display.Stage];
flambe.platform.html.HtmlStage.computeScaleFactor = function() {
	var devicePixelRatio = window.devicePixelRatio;
	if(devicePixelRatio == null) devicePixelRatio = 1;
	var canvas = js.Lib.document.createElement("canvas");
	var ctx = canvas.getContext("2d");
	var backingStorePixelRatio = flambe.platform.html.HtmlUtil.loadExtension("backingStorePixelRatio",ctx).value;
	if(backingStorePixelRatio == null) backingStorePixelRatio = 1;
	var scale = devicePixelRatio / backingStorePixelRatio;
	var screenWidth = screen.width;
	var screenHeight = screen.height;
	if(scale * screenWidth > 1024 || scale * screenHeight > 1024) return 1;
	return scale;
}
flambe.platform.html.HtmlStage.prototype = {
	updateFullscreen: function() {
		var state = flambe.platform.html.HtmlUtil.loadFirstExtension(["fullscreen","fullScreen","isFullScreen"],js.Lib.document).value;
		this.fullscreen.set__(state == true);
	}
	,onOrientationChange: function() {
		var value = flambe.platform.html.HtmlUtil.orientation(window.orientation);
		this.orientation.set__(value);
	}
	,hideMobileBrowser: function() {
		var _g = this;
		var mobileAddressBar = 100;
		var htmlStyle = js.Lib.document.documentElement.style;
		htmlStyle.height = js.Lib.window.innerHeight + mobileAddressBar + "px";
		htmlStyle.width = js.Lib.window.innerWidth + "px";
		htmlStyle.overflow = "visible";
		flambe.platform.html.HtmlUtil.callLater(function() {
			flambe.platform.html.HtmlUtil.hideMobileBrowser();
			flambe.platform.html.HtmlUtil.callLater(function() {
				htmlStyle.height = js.Lib.window.innerHeight + "px";
				_g.onWindowResize();
			},100);
		});
	}
	,resizeCanvas: function(width,height) {
		var scaledWidth = this.scaleFactor * width;
		var scaledHeight = this.scaleFactor * height;
		if(this._canvas.width == scaledWidth && this._canvas.height == scaledHeight) return false;
		this._canvas.width = scaledWidth;
		this._canvas.height = scaledHeight;
		this.resize.emit();
		return true;
	}
	,onWindowResize: function() {
		var container = this._canvas.parentNode;
		var rect = container.getBoundingClientRect();
		this.resizeCanvas(rect.width,rect.height);
	}
	,requestFullscreen: function(enable) {
		if(enable == null) enable = true;
		if(enable) {
			var documentElement = js.Lib.document.documentElement;
			var requestFullscreen = flambe.platform.html.HtmlUtil.loadFirstExtension(["requestFullscreen","requestFullScreen"],documentElement).value;
			if(requestFullscreen != null) Reflect.callMethod(documentElement,requestFullscreen,[]);
		} else {
			var cancelFullscreen = flambe.platform.html.HtmlUtil.loadFirstExtension(["cancelFullscreen","cancelFullScreen"],js.Lib.document).value;
			if(cancelFullscreen != null) Reflect.callMethod(js.Lib.document,cancelFullscreen,[]);
		}
	}
	,requestResize: function(width,height) {
		if(this.resizeCanvas(width,height)) {
			var container = this._canvas.parentNode;
			container.style.width = width + "px";
			container.style.height = height + "px";
		}
	}
	,unlockOrientation: function() {
	}
	,lockOrientation: function(orient) {
	}
	,get_fullscreenSupported: function() {
		return flambe.platform.html.HtmlUtil.loadFirstExtension(["fullscreenEnabled","fullScreenEnabled"],js.Lib.document).value == true;
	}
	,get_height: function() {
		return this._canvas.height;
	}
	,get_width: function() {
		return this._canvas.width;
	}
	,__class__: flambe.platform.html.HtmlStage
}
flambe.platform.html.HtmlStorage = function(storage) {
	this._storage = storage;
};
$hxClasses["flambe.platform.html.HtmlStorage"] = flambe.platform.html.HtmlStorage;
flambe.platform.html.HtmlStorage.__name__ = ["flambe","platform","html","HtmlStorage"];
flambe.platform.html.HtmlStorage.__interfaces__ = [flambe.storage.Storage];
flambe.platform.html.HtmlStorage.prototype = {
	clear: function() {
		try {
			this._storage.clear();
		} catch( error ) {
			flambe.Log.warn("localStorage.clear failed",["message",error.message]);
		}
	}
	,remove: function(key) {
		try {
			this._storage.removeItem("flambe:" + key);
		} catch( error ) {
			flambe.Log.warn("localStorage.removeItem failed",["message",error.message]);
		}
	}
	,get: function(key,defaultValue) {
		var encoded = null;
		try {
			encoded = this._storage.getItem("flambe:" + key);
		} catch( error ) {
			flambe.Log.warn("localStorage.getItem failed",["message",error.message]);
		}
		if(encoded != null) try {
			return haxe.Unserializer.run(encoded);
		} catch( error ) {
			flambe.Log.warn("Storage unserialization failed",["message",error]);
		}
		return defaultValue;
	}
	,set: function(key,value) {
		var encoded;
		try {
			var serializer = new haxe.Serializer();
			serializer.useCache = true;
			serializer.useEnumIndex = false;
			serializer.serialize(value);
			encoded = serializer.toString();
		} catch( error ) {
			flambe.Log.warn("Storage serialization failed",["message",error]);
			return false;
		}
		try {
			this._storage.setItem("flambe:" + key,encoded);
		} catch( error ) {
			flambe.Log.warn("localStorage.setItem failed",["message",error.message]);
			return false;
		}
		return true;
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.html.HtmlStorage
}
flambe.platform.html.HtmlUtil = function() { }
$hxClasses["flambe.platform.html.HtmlUtil"] = flambe.platform.html.HtmlUtil;
flambe.platform.html.HtmlUtil.__name__ = ["flambe","platform","html","HtmlUtil"];
flambe.platform.html.HtmlUtil.callLater = function(func,delay) {
	if(delay == null) delay = 0;
	js.Lib.window.setTimeout(func,delay);
}
flambe.platform.html.HtmlUtil.hideMobileBrowser = function() {
	js.Lib.window.scrollTo(1,0);
}
flambe.platform.html.HtmlUtil.loadExtension = function(name,obj) {
	if(obj == null) obj = js.Lib.window;
	var extension = Reflect.field(obj,name);
	if(extension != null) return { prefix : null, field : name, value : extension};
	var capitalized = name.charAt(0).toUpperCase() + HxOverrides.substr(name,1,null);
	var _g = 0, _g1 = flambe.platform.html.HtmlUtil.VENDOR_PREFIXES;
	while(_g < _g1.length) {
		var prefix = _g1[_g];
		++_g;
		var field = prefix + capitalized;
		var extension1 = Reflect.field(obj,field);
		if(extension1 != null) return { prefix : prefix, field : field, value : extension1};
	}
	return { prefix : null, field : null, value : null};
}
flambe.platform.html.HtmlUtil.loadFirstExtension = function(names,obj) {
	var _g = 0;
	while(_g < names.length) {
		var name = names[_g];
		++_g;
		var extension = flambe.platform.html.HtmlUtil.loadExtension(name,obj);
		if(extension.field != null) return extension;
	}
	return { prefix : null, field : null, value : null};
}
flambe.platform.html.HtmlUtil.polyfill = function(name,obj) {
	if(obj == null) obj = js.Lib.window;
	var value = flambe.platform.html.HtmlUtil.loadExtension(name,obj).value;
	if(value == null) return false;
	Reflect.setField(obj,name,value);
	return true;
}
flambe.platform.html.HtmlUtil.setVendorStyle = function(element,name,value) {
	var style = element.style;
	var _g = 0, _g1 = flambe.platform.html.HtmlUtil.VENDOR_PREFIXES;
	while(_g < _g1.length) {
		var prefix = _g1[_g];
		++_g;
		style.setProperty("-" + prefix + "-" + name,value);
	}
	style.setProperty(name,value);
}
flambe.platform.html.HtmlUtil.addVendorListener = function(dispatcher,type,listener,useCapture) {
	var _g = 0, _g1 = flambe.platform.html.HtmlUtil.VENDOR_PREFIXES;
	while(_g < _g1.length) {
		var prefix = _g1[_g];
		++_g;
		dispatcher.addEventListener(prefix + type,listener,useCapture);
	}
	dispatcher.addEventListener(type,listener,useCapture);
}
flambe.platform.html.HtmlUtil.orientation = function(angle) {
	switch(angle) {
	case -90:case 90:
		return flambe.display.Orientation.Landscape;
	default:
		return flambe.display.Orientation.Portrait;
	}
}
flambe.platform.html.HtmlUtil.now = function() {
	return Date.now();
}
flambe.platform.html.HtmlUtil.createEmptyCanvas = function(width,height) {
	var canvas = js.Lib.document.createElement("canvas");
	canvas.width = width;
	canvas.height = height;
	return canvas;
}
flambe.platform.html.HtmlUtil.createCanvas = function(source) {
	var canvas = flambe.platform.html.HtmlUtil.createEmptyCanvas(source.width,source.height);
	var ctx = canvas.getContext("2d");
	ctx.save();
	ctx.globalCompositeOperation = "copy";
	ctx.drawImage(source,0,0);
	ctx.restore();
	return canvas;
}
flambe.web = {}
flambe.web.Web = function() { }
$hxClasses["flambe.web.Web"] = flambe.web.Web;
flambe.web.Web.__name__ = ["flambe","web","Web"];
flambe.web.Web.prototype = {
	__class__: flambe.web.Web
}
flambe.platform.html.HtmlWeb = function(container) {
	this._container = container;
};
$hxClasses["flambe.platform.html.HtmlWeb"] = flambe.platform.html.HtmlWeb;
flambe.platform.html.HtmlWeb.__name__ = ["flambe","platform","html","HtmlWeb"];
flambe.platform.html.HtmlWeb.__interfaces__ = [flambe.web.Web];
flambe.platform.html.HtmlWeb.prototype = {
	openBrowser: function(url) {
		js.Lib.window.open(url,"_blank");
	}
	,createView: function(x,y,width,height) {
		var iframe = js.Lib.document.createElement("iframe");
		iframe.style.position = "absolute";
		iframe.style.border = "0";
		iframe.scrolling = "no";
		this._container.appendChild(iframe);
		var view = new flambe.platform.html.HtmlWebView(iframe,x,y,width,height);
		flambe.platform.html.HtmlPlatform.instance.mainLoop.addTickable(view);
		return view;
	}
	,get_supported: function() {
		return true;
	}
	,__class__: flambe.platform.html.HtmlWeb
}
flambe.web.WebView = function() { }
$hxClasses["flambe.web.WebView"] = flambe.web.WebView;
flambe.web.WebView.__name__ = ["flambe","web","WebView"];
flambe.web.WebView.__interfaces__ = [flambe.util.Disposable];
flambe.web.WebView.prototype = {
	__class__: flambe.web.WebView
}
flambe.platform.html.HtmlWebView = function(iframe,x,y,width,height) {
	var _g = this;
	this.iframe = iframe;
	var onBoundsChanged = function(_,_1) {
		_g.updateBounds();
	};
	this.x = new flambe.animation.AnimatedFloat(x,onBoundsChanged);
	this.y = new flambe.animation.AnimatedFloat(y,onBoundsChanged);
	this.width = new flambe.animation.AnimatedFloat(width,onBoundsChanged);
	this.height = new flambe.animation.AnimatedFloat(height,onBoundsChanged);
	this.updateBounds();
	this.url = new flambe.util.Value(null,function(url,_) {
		_g.loadUrl(url);
	});
	this.error = new flambe.util.Signal1();
};
$hxClasses["flambe.platform.html.HtmlWebView"] = flambe.platform.html.HtmlWebView;
flambe.platform.html.HtmlWebView.__name__ = ["flambe","platform","html","HtmlWebView"];
flambe.platform.html.HtmlWebView.__interfaces__ = [flambe.platform.Tickable,flambe.web.WebView];
flambe.platform.html.HtmlWebView.prototype = {
	loadUrl: function(url) {
		if(this.iframe == null) return;
		this.iframe.src = url;
	}
	,updateBounds: function() {
		if(this.iframe == null) return;
		this.iframe.style.left = this.x.get__() + "px";
		this.iframe.style.top = this.y.get__() + "px";
		this.iframe.width = this.width.get__();
		this.iframe.height = this.height.get__();
	}
	,update: function(dt) {
		this.x.update(dt);
		this.y.update(dt);
		this.width.update(dt);
		this.height.update(dt);
		return this.iframe == null;
	}
	,dispose: function() {
		if(this.iframe == null) return;
		this.iframe.parentNode.removeChild(this.iframe);
		this.iframe = null;
	}
	,__class__: flambe.platform.html.HtmlWebView
}
flambe.platform.html.WebAudioSound = function(buffer) {
	this.buffer = buffer;
};
$hxClasses["flambe.platform.html.WebAudioSound"] = flambe.platform.html.WebAudioSound;
flambe.platform.html.WebAudioSound.__name__ = ["flambe","platform","html","WebAudioSound"];
flambe.platform.html.WebAudioSound.__interfaces__ = [flambe.sound.Sound];
flambe.platform.html.WebAudioSound.get_supported = function() {
	if(flambe.platform.html.WebAudioSound._detectSupport) {
		flambe.platform.html.WebAudioSound._detectSupport = false;
		var AudioContext = flambe.platform.html.HtmlUtil.loadExtension("AudioContext").value;
		if(AudioContext != null) {
			flambe.platform.html.WebAudioSound.ctx = new AudioContext();
			flambe.platform.html.WebAudioSound.gain = flambe.platform.html.WebAudioSound.ctx.createGainNode();
			flambe.platform.html.WebAudioSound.gain.connect(flambe.platform.html.WebAudioSound.ctx.destination);
			flambe.System.volume.watch(function(volume,_) {
				flambe.platform.html.WebAudioSound.gain.gain.value = volume;
			});
		}
	}
	return flambe.platform.html.WebAudioSound.ctx != null;
}
flambe.platform.html.WebAudioSound.prototype = {
	get_duration: function() {
		return this.buffer.duration;
	}
	,loop: function(volume) {
		if(volume == null) volume = 1.0;
		return new flambe.platform.html._WebAudioSound.WebAudioPlayback(this,volume,true);
	}
	,play: function(volume) {
		if(volume == null) volume = 1.0;
		return new flambe.platform.html._WebAudioSound.WebAudioPlayback(this,volume,false);
	}
	,__class__: flambe.platform.html.WebAudioSound
}
flambe.platform.html._WebAudioSound = {}
flambe.platform.html._WebAudioSound.WebAudioPlayback = function(sound,volume,loop) {
	var _g = this;
	this._sound = sound;
	this._head = flambe.platform.html.WebAudioSound.gain;
	this._sourceNode = flambe.platform.html.WebAudioSound.ctx.createBufferSource();
	this._sourceNode.buffer = sound.buffer;
	this._sourceNode.loop = loop;
	this._sourceNode.noteOn(0);
	this.playAudio();
	this.volume = new flambe.animation.AnimatedFloat(volume,function(v,_) {
		_g.setVolume(v);
	});
	if(volume != 1) this.setVolume(volume);
};
$hxClasses["flambe.platform.html._WebAudioSound.WebAudioPlayback"] = flambe.platform.html._WebAudioSound.WebAudioPlayback;
flambe.platform.html._WebAudioSound.WebAudioPlayback.__name__ = ["flambe","platform","html","_WebAudioSound","WebAudioPlayback"];
flambe.platform.html._WebAudioSound.WebAudioPlayback.__interfaces__ = [flambe.platform.Tickable,flambe.sound.Playback];
flambe.platform.html._WebAudioSound.WebAudioPlayback.prototype = {
	playAudio: function() {
		this._sourceNode.connect(this._head);
		this._startedAt = flambe.platform.html.WebAudioSound.ctx.currentTime;
		this._pausedAt = -1;
		if(!this._tickableAdded) {
			this._tickableAdded = true;
			flambe.platform.html.HtmlPlatform.instance.mainLoop.addTickable(this);
		}
	}
	,insertNode: function(head) {
		if(!this.get_paused()) {
			this._sourceNode.disconnect();
			this._sourceNode.connect(head);
		}
		head.connect(this._head);
		this._head = head;
	}
	,setVolume: function(volume) {
		if(this._gainNode == null) {
			this._gainNode = flambe.platform.html.WebAudioSound.ctx.createGainNode();
			this.insertNode(this._gainNode);
		}
		this._gainNode.gain.value = volume;
	}
	,dispose: function() {
		this.set_paused(true);
	}
	,update: function(dt) {
		this.volume.update(dt);
		if(this.get_ended() || this.get_paused()) {
			this._tickableAdded = false;
			return true;
		}
		return false;
	}
	,get_position: function() {
		if(this.get_ended()) return this._sound.get_duration(); else if(this.get_paused()) return this._pausedAt; else {
			var elapsed = flambe.platform.html.WebAudioSound.ctx.currentTime - this._startedAt;
			return elapsed % this._sound.get_duration();
		}
	}
	,get_ended: function() {
		return this._sourceNode.playbackState == 3;
	}
	,set_paused: function(paused) {
		if(paused != this.get_paused()) {
			if(paused) {
				this._sourceNode.disconnect();
				this._pausedAt = this.get_position();
			} else this.playAudio();
		}
		return paused;
	}
	,get_paused: function() {
		return this._pausedAt >= 0;
	}
	,get_sound: function() {
		return this._sound;
	}
	,__class__: flambe.platform.html._WebAudioSound.WebAudioPlayback
}
flambe.scene = {}
flambe.scene.Director = function() {
	this._height = -1;
	this._width = -1;
	this._transitor = null;
	this.scenes = [];
	this.occludedScenes = [];
	this._root = new flambe.Entity();
};
$hxClasses["flambe.scene.Director"] = flambe.scene.Director;
flambe.scene.Director.__name__ = ["flambe","scene","Director"];
flambe.scene.Director.getFrom = function(entity) {
	return entity.getComponent("Director_0");
}
flambe.scene.Director.__super__ = flambe.Component;
flambe.scene.Director.prototype = $extend(flambe.Component.prototype,{
	get_height: function() {
		return this._height < 0?flambe.System.get_stage().get_height():this._height;
	}
	,get_width: function() {
		return this._width < 0?flambe.System.get_stage().get_width():this._width;
	}
	,completeTransition: function() {
		if(this._transitor != null) {
			this._transitor.complete();
			this._transitor = null;
			this.invalidateVisibility();
		}
	}
	,invalidateVisibility: function() {
		var ii = this.scenes.length;
		while(ii > 0) {
			var scene = this.scenes[--ii];
			var comp = flambe.scene.Scene.getFrom(scene);
			if(comp == null || comp.opaque) break;
		}
		this.occludedScenes = this.scenes.length > 0?this.scenes.slice(ii,this.scenes.length - 1):[];
		var scene = this.get_topScene();
		if(scene != null) this.show(scene);
	}
	,show: function(scene) {
		var events = flambe.scene.Scene.getFrom(scene);
		if(events != null) events.shown.emit();
	}
	,get_topScene: function() {
		var ll = this.scenes.length;
		return ll > 0?this.scenes[ll - 1]:null;
	}
	,onUpdate: function(dt) {
		if(this._transitor != null && this._transitor.update(dt)) this.completeTransition();
	}
	,onRemoved: function() {
		this.completeTransition();
		var _g = 0, _g1 = this.scenes;
		while(_g < _g1.length) {
			var scene = _g1[_g];
			++_g;
			scene.dispose();
		}
		this.scenes = [];
		this.occludedScenes = [];
		this._root.dispose();
	}
	,onAdded: function() {
		this.owner.addChild(this._root);
	}
	,get_name: function() {
		return "Director_0";
	}
	,__class__: flambe.scene.Director
});
flambe.scene._Director = {}
flambe.scene._Director.Transitor = function() { }
$hxClasses["flambe.scene._Director.Transitor"] = flambe.scene._Director.Transitor;
flambe.scene._Director.Transitor.__name__ = ["flambe","scene","_Director","Transitor"];
flambe.scene._Director.Transitor.prototype = {
	complete: function() {
		this._transition.complete();
		this._onComplete();
	}
	,update: function(dt) {
		return this._transition.update(dt);
	}
	,__class__: flambe.scene._Director.Transitor
}
flambe.scene.Scene = function(opaque) {
	if(opaque == null) opaque = true;
	this.opaque = opaque;
	this.shown = new flambe.util.Signal0();
	this.hidden = new flambe.util.Signal0();
};
$hxClasses["flambe.scene.Scene"] = flambe.scene.Scene;
flambe.scene.Scene.__name__ = ["flambe","scene","Scene"];
flambe.scene.Scene.getFrom = function(entity) {
	return entity.getComponent("Scene_2");
}
flambe.scene.Scene.__super__ = flambe.Component;
flambe.scene.Scene.prototype = $extend(flambe.Component.prototype,{
	get_name: function() {
		return "Scene_2";
	}
	,__class__: flambe.scene.Scene
});
flambe.scene.Transition = function() { }
$hxClasses["flambe.scene.Transition"] = flambe.scene.Transition;
flambe.scene.Transition.__name__ = ["flambe","scene","Transition"];
flambe.scene.Transition.prototype = {
	complete: function() {
	}
	,update: function(dt) {
		return true;
	}
	,__class__: flambe.scene.Transition
}
flambe.util.Assert = function() { }
$hxClasses["flambe.util.Assert"] = flambe.util.Assert;
flambe.util.Assert.__name__ = ["flambe","util","Assert"];
flambe.util.Assert.that = function(condition,message,fields) {
	if(!condition) flambe.util.Assert.fail(message,fields);
}
flambe.util.Assert.fail = function(message,fields) {
	var error = "Assertion failed!";
	if(message != null) error += " " + message;
	if(fields != null) error = flambe.util.Strings.withFields(error,fields);
	throw error;
}
flambe.util.BitSets = function() { }
$hxClasses["flambe.util.BitSets"] = flambe.util.BitSets;
flambe.util.BitSets.__name__ = ["flambe","util","BitSets"];
flambe.util.BitSets.add = function(bits,mask) {
	return bits | mask;
}
flambe.util.BitSets.remove = function(bits,mask) {
	return bits & ~mask;
}
flambe.util.BitSets.contains = function(bits,mask) {
	return (bits & mask) != 0;
}
flambe.util.BitSets.containsAll = function(bits,mask) {
	return (bits & mask) == mask;
}
flambe.util.BitSets.set = function(bits,mask,enabled) {
	return enabled?flambe.util.BitSets.add(bits,mask):flambe.util.BitSets.remove(bits,mask);
}
flambe.util.LogLevel = $hxClasses["flambe.util.LogLevel"] = { __ename__ : ["flambe","util","LogLevel"], __constructs__ : ["Info","Warn","Error"] }
flambe.util.LogLevel.Info = ["Info",0];
flambe.util.LogLevel.Info.toString = $estr;
flambe.util.LogLevel.Info.__enum__ = flambe.util.LogLevel;
flambe.util.LogLevel.Warn = ["Warn",1];
flambe.util.LogLevel.Warn.toString = $estr;
flambe.util.LogLevel.Warn.__enum__ = flambe.util.LogLevel;
flambe.util.LogLevel.Error = ["Error",2];
flambe.util.LogLevel.Error.toString = $estr;
flambe.util.LogLevel.Error.__enum__ = flambe.util.LogLevel;
flambe.util.Promise = function() {
	this.success = new flambe.util.Signal1();
	this.error = new flambe.util.Signal1();
	this.progressChanged = new flambe.util.Signal0();
	this.hasResult = false;
	this._progress = 0;
	this._total = 0;
};
$hxClasses["flambe.util.Promise"] = flambe.util.Promise;
flambe.util.Promise.__name__ = ["flambe","util","Promise"];
flambe.util.Promise.prototype = {
	set_total: function(total) {
		this._total = total;
		this.progressChanged.emit();
		return total;
	}
	,set_progress: function(progress) {
		this._progress = progress;
		this.progressChanged.emit();
		return progress;
	}
	,get: function(fn) {
		if(this.hasResult) {
			fn(this._result);
			return null;
		}
		return this.success.connect(fn).once();
	}
	,set_result: function(result) {
		if(this.hasResult) throw "Promise result already assigned";
		this._result = result;
		this.hasResult = true;
		this.success.emit(result);
		return result;
	}
	,get_result: function() {
		if(!this.hasResult) throw "Promise result not yet available";
		return this._result;
	}
	,__class__: flambe.util.Promise
}
flambe.util.Signal0 = function(listener) {
	flambe.util.SignalBase.call(this,listener);
};
$hxClasses["flambe.util.Signal0"] = flambe.util.Signal0;
flambe.util.Signal0.__name__ = ["flambe","util","Signal0"];
flambe.util.Signal0.__super__ = flambe.util.SignalBase;
flambe.util.Signal0.prototype = $extend(flambe.util.SignalBase.prototype,{
	emit: function() {
		this.emit0();
	}
	,__class__: flambe.util.Signal0
});
flambe.util._SignalBase = {}
flambe.util._SignalBase.Task = function(fn) {
	this.next = null;
	this.fn = fn;
};
$hxClasses["flambe.util._SignalBase.Task"] = flambe.util._SignalBase.Task;
flambe.util._SignalBase.Task.__name__ = ["flambe","util","_SignalBase","Task"];
flambe.util._SignalBase.Task.prototype = {
	__class__: flambe.util._SignalBase.Task
}
var haxe = {}
haxe.Http = function(url) {
	this.url = url;
	this.headers = new Hash();
	this.params = new Hash();
	this.async = true;
};
$hxClasses["haxe.Http"] = haxe.Http;
haxe.Http.__name__ = ["haxe","Http"];
haxe.Http.prototype = {
	onStatus: function(status) {
	}
	,onError: function(msg) {
	}
	,onData: function(data) {
	}
	,request: function(post) {
		var me = this;
		var r = new js.XMLHttpRequest();
		var onreadystatechange = function() {
			if(r.readyState != 4) return;
			var s = (function($this) {
				var $r;
				try {
					$r = r.status;
				} catch( e ) {
					$r = null;
				}
				return $r;
			}(this));
			if(s == undefined) s = null;
			if(s != null) me.onStatus(s);
			if(s != null && s >= 200 && s < 400) me.onData(r.responseText); else switch(s) {
			case null: case undefined:
				me.onError("Failed to connect or resolve host");
				break;
			case 12029:
				me.onError("Failed to connect to host");
				break;
			case 12007:
				me.onError("Unknown host");
				break;
			default:
				me.onError("Http Error #" + r.status);
			}
		};
		if(this.async) r.onreadystatechange = onreadystatechange;
		var uri = this.postData;
		if(uri != null) post = true; else {
			var $it0 = this.params.keys();
			while( $it0.hasNext() ) {
				var p = $it0.next();
				if(uri == null) uri = ""; else uri += "&";
				uri += StringTools.urlEncode(p) + "=" + StringTools.urlEncode(this.params.get(p));
			}
		}
		try {
			if(post) r.open("POST",this.url,this.async); else if(uri != null) {
				var question = this.url.split("?").length <= 1;
				r.open("GET",this.url + (question?"?":"&") + uri,this.async);
				uri = null;
			} else r.open("GET",this.url,this.async);
		} catch( e ) {
			this.onError(e.toString());
			return;
		}
		if(this.headers.get("Content-Type") == null && post && this.postData == null) r.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		var $it1 = this.headers.keys();
		while( $it1.hasNext() ) {
			var h = $it1.next();
			r.setRequestHeader(h,this.headers.get(h));
		}
		r.send(uri);
		if(!this.async) onreadystatechange();
	}
	,__class__: haxe.Http
}
haxe.Serializer = function() {
	this.buf = new StringBuf();
	this.cache = new Array();
	this.useCache = haxe.Serializer.USE_CACHE;
	this.useEnumIndex = haxe.Serializer.USE_ENUM_INDEX;
	this.shash = new Hash();
	this.scount = 0;
};
$hxClasses["haxe.Serializer"] = haxe.Serializer;
haxe.Serializer.__name__ = ["haxe","Serializer"];
haxe.Serializer.prototype = {
	serialize: function(v) {
		var $e = (Type["typeof"](v));
		switch( $e[1] ) {
		case 0:
			this.buf.add("n");
			break;
		case 1:
			if(v == 0) {
				this.buf.add("z");
				return;
			}
			this.buf.add("i");
			this.buf.add(v);
			break;
		case 2:
			if(Math.isNaN(v)) this.buf.add("k"); else if(!Math.isFinite(v)) this.buf.add(v < 0?"m":"p"); else {
				this.buf.add("d");
				this.buf.add(v);
			}
			break;
		case 3:
			this.buf.add(v?"t":"f");
			break;
		case 6:
			var c = $e[2];
			if(c == String) {
				this.serializeString(v);
				return;
			}
			if(this.useCache && this.serializeRef(v)) return;
			switch(c) {
			case Array:
				var ucount = 0;
				this.buf.add("a");
				var l = v.length;
				var _g = 0;
				while(_g < l) {
					var i = _g++;
					if(v[i] == null) ucount++; else {
						if(ucount > 0) {
							if(ucount == 1) this.buf.add("n"); else {
								this.buf.add("u");
								this.buf.add(ucount);
							}
							ucount = 0;
						}
						this.serialize(v[i]);
					}
				}
				if(ucount > 0) {
					if(ucount == 1) this.buf.add("n"); else {
						this.buf.add("u");
						this.buf.add(ucount);
					}
				}
				this.buf.add("h");
				break;
			case List:
				this.buf.add("l");
				var v1 = v;
				var $it0 = v1.iterator();
				while( $it0.hasNext() ) {
					var i = $it0.next();
					this.serialize(i);
				}
				this.buf.add("h");
				break;
			case Date:
				var d = v;
				this.buf.add("v");
				this.buf.add(HxOverrides.dateStr(d));
				break;
			case Hash:
				this.buf.add("b");
				var v1 = v;
				var $it1 = v1.keys();
				while( $it1.hasNext() ) {
					var k = $it1.next();
					this.serializeString(k);
					this.serialize(v1.get(k));
				}
				this.buf.add("h");
				break;
			case IntHash:
				this.buf.add("q");
				var v1 = v;
				var $it2 = v1.keys();
				while( $it2.hasNext() ) {
					var k = $it2.next();
					this.buf.add(":");
					this.buf.add(k);
					this.serialize(v1.get(k));
				}
				this.buf.add("h");
				break;
			case haxe.io.Bytes:
				var v1 = v;
				var i = 0;
				var max = v1.length - 2;
				var charsBuf = new StringBuf();
				var b64 = haxe.Serializer.BASE64;
				while(i < max) {
					var b1 = v1.get(i++);
					var b2 = v1.get(i++);
					var b3 = v1.get(i++);
					charsBuf.add(b64.charAt(b1 >> 2));
					charsBuf.add(b64.charAt((b1 << 4 | b2 >> 4) & 63));
					charsBuf.add(b64.charAt((b2 << 2 | b3 >> 6) & 63));
					charsBuf.add(b64.charAt(b3 & 63));
				}
				if(i == max) {
					var b1 = v1.get(i++);
					var b2 = v1.get(i++);
					charsBuf.add(b64.charAt(b1 >> 2));
					charsBuf.add(b64.charAt((b1 << 4 | b2 >> 4) & 63));
					charsBuf.add(b64.charAt(b2 << 2 & 63));
				} else if(i == max + 1) {
					var b1 = v1.get(i++);
					charsBuf.add(b64.charAt(b1 >> 2));
					charsBuf.add(b64.charAt(b1 << 4 & 63));
				}
				var chars = charsBuf.toString();
				this.buf.add("s");
				this.buf.add(chars.length);
				this.buf.add(":");
				this.buf.add(chars);
				break;
			default:
				this.cache.pop();
				if(v.hxSerialize != null) {
					this.buf.add("C");
					this.serializeString(Type.getClassName(c));
					this.cache.push(v);
					v.hxSerialize(this);
					this.buf.add("g");
				} else {
					this.buf.add("c");
					this.serializeString(Type.getClassName(c));
					this.cache.push(v);
					this.serializeFields(v);
				}
			}
			break;
		case 4:
			if(this.useCache && this.serializeRef(v)) return;
			this.buf.add("o");
			this.serializeFields(v);
			break;
		case 7:
			var e = $e[2];
			if(this.useCache && this.serializeRef(v)) return;
			this.cache.pop();
			this.buf.add(this.useEnumIndex?"j":"w");
			this.serializeString(Type.getEnumName(e));
			if(this.useEnumIndex) {
				this.buf.add(":");
				this.buf.add(v[1]);
			} else this.serializeString(v[0]);
			this.buf.add(":");
			var l = v.length;
			this.buf.add(l - 2);
			var _g = 2;
			while(_g < l) {
				var i = _g++;
				this.serialize(v[i]);
			}
			this.cache.push(v);
			break;
		case 5:
			throw "Cannot serialize function";
			break;
		default:
			throw "Cannot serialize " + Std.string(v);
		}
	}
	,serializeFields: function(v) {
		var _g = 0, _g1 = Reflect.fields(v);
		while(_g < _g1.length) {
			var f = _g1[_g];
			++_g;
			this.serializeString(f);
			this.serialize(Reflect.field(v,f));
		}
		this.buf.add("g");
	}
	,serializeRef: function(v) {
		var vt = typeof(v);
		var _g1 = 0, _g = this.cache.length;
		while(_g1 < _g) {
			var i = _g1++;
			var ci = this.cache[i];
			if(typeof(ci) == vt && ci == v) {
				this.buf.add("r");
				this.buf.add(i);
				return true;
			}
		}
		this.cache.push(v);
		return false;
	}
	,serializeString: function(s) {
		var x = this.shash.get(s);
		if(x != null) {
			this.buf.add("R");
			this.buf.add(x);
			return;
		}
		this.shash.set(s,this.scount++);
		this.buf.add("y");
		s = StringTools.urlEncode(s);
		this.buf.add(s.length);
		this.buf.add(":");
		this.buf.add(s);
	}
	,toString: function() {
		return this.buf.toString();
	}
	,__class__: haxe.Serializer
}
haxe.Unserializer = function(buf) {
	this.buf = buf;
	this.length = buf.length;
	this.pos = 0;
	this.scache = new Array();
	this.cache = new Array();
	var r = haxe.Unserializer.DEFAULT_RESOLVER;
	if(r == null) {
		r = Type;
		haxe.Unserializer.DEFAULT_RESOLVER = r;
	}
	this.setResolver(r);
};
$hxClasses["haxe.Unserializer"] = haxe.Unserializer;
haxe.Unserializer.__name__ = ["haxe","Unserializer"];
haxe.Unserializer.initCodes = function() {
	var codes = new Array();
	var _g1 = 0, _g = haxe.Unserializer.BASE64.length;
	while(_g1 < _g) {
		var i = _g1++;
		codes[StringTools.fastCodeAt(haxe.Unserializer.BASE64,i)] = i;
	}
	return codes;
}
haxe.Unserializer.run = function(v) {
	return new haxe.Unserializer(v).unserialize();
}
haxe.Unserializer.prototype = {
	unserialize: function() {
		switch(this.get(this.pos++)) {
		case 110:
			return null;
		case 116:
			return true;
		case 102:
			return false;
		case 122:
			return 0;
		case 105:
			return this.readDigits();
		case 100:
			var p1 = this.pos;
			while(true) {
				var c = this.get(this.pos);
				if(c >= 43 && c < 58 || c == 101 || c == 69) this.pos++; else break;
			}
			return Std.parseFloat(HxOverrides.substr(this.buf,p1,this.pos - p1));
		case 121:
			var len = this.readDigits();
			if(this.get(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid string length";
			var s = HxOverrides.substr(this.buf,this.pos,len);
			this.pos += len;
			s = StringTools.urlDecode(s);
			this.scache.push(s);
			return s;
		case 107:
			return Math.NaN;
		case 109:
			return Math.NEGATIVE_INFINITY;
		case 112:
			return Math.POSITIVE_INFINITY;
		case 97:
			var buf = this.buf;
			var a = new Array();
			this.cache.push(a);
			while(true) {
				var c = this.get(this.pos);
				if(c == 104) {
					this.pos++;
					break;
				}
				if(c == 117) {
					this.pos++;
					var n = this.readDigits();
					a[a.length + n - 1] = null;
				} else a.push(this.unserialize());
			}
			return a;
		case 111:
			var o = { };
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 114:
			var n = this.readDigits();
			if(n < 0 || n >= this.cache.length) throw "Invalid reference";
			return this.cache[n];
		case 82:
			var n = this.readDigits();
			if(n < 0 || n >= this.scache.length) throw "Invalid string reference";
			return this.scache[n];
		case 120:
			throw this.unserialize();
			break;
		case 99:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o = Type.createEmptyInstance(cl);
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 119:
			var name = this.unserialize();
			var edecl = this.resolver.resolveEnum(name);
			if(edecl == null) throw "Enum not found " + name;
			var e = this.unserializeEnum(edecl,this.unserialize());
			this.cache.push(e);
			return e;
		case 106:
			var name = this.unserialize();
			var edecl = this.resolver.resolveEnum(name);
			if(edecl == null) throw "Enum not found " + name;
			this.pos++;
			var index = this.readDigits();
			var tag = Type.getEnumConstructs(edecl)[index];
			if(tag == null) throw "Unknown enum index " + name + "@" + index;
			var e = this.unserializeEnum(edecl,tag);
			this.cache.push(e);
			return e;
		case 108:
			var l = new List();
			this.cache.push(l);
			var buf = this.buf;
			while(this.get(this.pos) != 104) l.add(this.unserialize());
			this.pos++;
			return l;
		case 98:
			var h = new Hash();
			this.cache.push(h);
			var buf = this.buf;
			while(this.get(this.pos) != 104) {
				var s = this.unserialize();
				h.set(s,this.unserialize());
			}
			this.pos++;
			return h;
		case 113:
			var h = new IntHash();
			this.cache.push(h);
			var buf = this.buf;
			var c = this.get(this.pos++);
			while(c == 58) {
				var i = this.readDigits();
				h.set(i,this.unserialize());
				c = this.get(this.pos++);
			}
			if(c != 104) throw "Invalid IntHash format";
			return h;
		case 118:
			var d = HxOverrides.strDate(HxOverrides.substr(this.buf,this.pos,19));
			this.cache.push(d);
			this.pos += 19;
			return d;
		case 115:
			var len = this.readDigits();
			var buf = this.buf;
			if(this.get(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid bytes length";
			var codes = haxe.Unserializer.CODES;
			if(codes == null) {
				codes = haxe.Unserializer.initCodes();
				haxe.Unserializer.CODES = codes;
			}
			var i = this.pos;
			var rest = len & 3;
			var size = (len >> 2) * 3 + (rest >= 2?rest - 1:0);
			var max = i + (len - rest);
			var bytes = haxe.io.Bytes.alloc(size);
			var bpos = 0;
			while(i < max) {
				var c1 = codes[StringTools.fastCodeAt(buf,i++)];
				var c2 = codes[StringTools.fastCodeAt(buf,i++)];
				bytes.set(bpos++,c1 << 2 | c2 >> 4);
				var c3 = codes[StringTools.fastCodeAt(buf,i++)];
				bytes.set(bpos++,c2 << 4 | c3 >> 2);
				var c4 = codes[StringTools.fastCodeAt(buf,i++)];
				bytes.set(bpos++,c3 << 6 | c4);
			}
			if(rest >= 2) {
				var c1 = codes[StringTools.fastCodeAt(buf,i++)];
				var c2 = codes[StringTools.fastCodeAt(buf,i++)];
				bytes.set(bpos++,c1 << 2 | c2 >> 4);
				if(rest == 3) {
					var c3 = codes[StringTools.fastCodeAt(buf,i++)];
					bytes.set(bpos++,c2 << 4 | c3 >> 2);
				}
			}
			this.pos += len;
			this.cache.push(bytes);
			return bytes;
		case 67:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o = Type.createEmptyInstance(cl);
			this.cache.push(o);
			o.hxUnserialize(this);
			if(this.get(this.pos++) != 103) throw "Invalid custom data";
			return o;
		default:
		}
		this.pos--;
		throw "Invalid char " + this.buf.charAt(this.pos) + " at position " + this.pos;
	}
	,unserializeEnum: function(edecl,tag) {
		if(this.get(this.pos++) != 58) throw "Invalid enum format";
		var nargs = this.readDigits();
		if(nargs == 0) return Type.createEnum(edecl,tag);
		var args = new Array();
		while(nargs-- > 0) args.push(this.unserialize());
		return Type.createEnum(edecl,tag,args);
	}
	,unserializeObject: function(o) {
		while(true) {
			if(this.pos >= this.length) throw "Invalid object";
			if(this.get(this.pos) == 103) break;
			var k = this.unserialize();
			if(!Std["is"](k,String)) throw "Invalid object key";
			var v = this.unserialize();
			Reflect.setField(o,k,v);
		}
		this.pos++;
	}
	,readDigits: function() {
		var k = 0;
		var s = false;
		var fpos = this.pos;
		while(true) {
			var c = this.get(this.pos);
			if(StringTools.isEOF(c)) break;
			if(c == 45) {
				if(this.pos != fpos) break;
				s = true;
				this.pos++;
				continue;
			}
			if(c < 48 || c > 57) break;
			k = k * 10 + (c - 48);
			this.pos++;
		}
		if(s) k *= -1;
		return k;
	}
	,get: function(p) {
		return StringTools.fastCodeAt(this.buf,p);
	}
	,setResolver: function(r) {
		if(r == null) this.resolver = { resolveClass : function(_) {
			return null;
		}, resolveEnum : function(_) {
			return null;
		}}; else this.resolver = r;
	}
	,__class__: haxe.Unserializer
}
haxe.io = {}
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
$hxClasses["haxe.io.Bytes"] = haxe.io.Bytes;
haxe.io.Bytes.__name__ = ["haxe","io","Bytes"];
haxe.io.Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
}
haxe.io.Bytes.ofData = function(b) {
	return new haxe.io.Bytes(b.length,b);
}
haxe.io.Bytes.prototype = {
	getData: function() {
		return this.b;
	}
	,set: function(pos,v) {
		this.b[pos] = v & 255;
	}
	,get: function(pos) {
		return this.b[pos];
	}
	,__class__: haxe.io.Bytes
}
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; };
var $_;
function $bind(o,m) { var f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; return f; };
if(Array.prototype.indexOf) HxOverrides.remove = function(a,o) {
	var i = a.indexOf(o);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
}; else null;
Math.__name__ = ["Math"];
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
$hxClasses.Math = Math;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i) {
	return isNaN(i);
};
String.prototype.__class__ = $hxClasses.String = String;
String.__name__ = ["String"];
Array.prototype.__class__ = $hxClasses.Array = Array;
Array.__name__ = ["Array"];
Date.prototype.__class__ = $hxClasses.Date = Date;
Date.__name__ = ["Date"];
var Int = $hxClasses.Int = { __name__ : ["Int"]};
var Dynamic = $hxClasses.Dynamic = { __name__ : ["Dynamic"]};
var Float = $hxClasses.Float = Number;
Float.__name__ = ["Float"];
var Bool = $hxClasses.Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = $hxClasses.Class = { __name__ : ["Class"]};
var Enum = { };
if(typeof document != "undefined") js.Lib.document = document;
if(typeof window != "undefined") {
	js.Lib.window = window;
	js.Lib.window.onerror = function(msg,url,line) {
		var f = js.Lib.onerror;
		if(f == null) return false;
		return f(msg,[url + ":" + line]);
	};
}
js.XMLHttpRequest = window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function() {
	try {
		return new ActiveXObject("Msxml2.XMLHTTP");
	} catch( e ) {
		try {
			return new ActiveXObject("Microsoft.XMLHTTP");
		} catch( e1 ) {
			throw "Unable to create XMLHttpRequest object.";
		}
	}
}:(function($this) {
	var $r;
	throw "Unable to create XMLHttpRequest object.";
	return $r;
}(this));
flambe.platform.html.HtmlPlatform.instance = new flambe.platform.html.HtmlPlatform();
flambe.util.SignalBase.DISPATCHING_SENTINEL = new flambe.util.SignalConnection(null,null);
flambe.System.root = new flambe.Entity();
flambe.System.uncaughtError = new flambe.util.Signal1();
flambe.System.hidden = new flambe.util.Value(false);
flambe.System.hasGPU = new flambe.util.Value(false);
flambe.System.volume = new flambe.animation.AnimatedFloat(1);
flambe.System._platform = flambe.platform.html.HtmlPlatform.instance;
flambe.System._calledInit = false;
flambe.Log.logger = flambe.System.createLogger("flambe");
flambe.asset.Manifest._buildManifest = flambe.asset.Manifest.createBuildManifests();
flambe.asset.Manifest._supportsCrossOrigin = (function() {
	var blacklist = new EReg("\\b(Android)\\b","");
	if(blacklist.match(js.Lib.window.navigator.userAgent)) return false;
	var xhr = new XMLHttpRequest();
	return xhr.withCredentials != null;
})();
flambe.display.Sprite._scratchPoint = new flambe.math.Point();
flambe.platform.BasicKeyboard._sharedEvent = new flambe.input.KeyboardEvent();
flambe.platform.BasicMouse._sharedEvent = new flambe.input.MouseEvent();
flambe.platform.BasicPointer._sharedEvent = new flambe.input.PointerEvent();
flambe.platform.html.CanvasRenderer.CANVAS_TEXTURES = (function() {
	var pattern = new EReg("(iPhone|iPod|iPad)","");
	return pattern.match(js.Lib.window.navigator.userAgent);
})();
flambe.platform.html.HtmlAssetPackLoader._mediaRefCount = 0;
flambe.platform.html.HtmlUtil.VENDOR_PREFIXES = ["webkit","moz","ms","o","khtml"];
flambe.platform.html.HtmlUtil.SHOULD_HIDE_MOBILE_BROWSER = js.Lib.window.top == js.Lib.window && new EReg("Mobile(/.*)? Safari","").match(js.Lib.window.navigator.userAgent);
flambe.platform.html.WebAudioSound._detectSupport = true;
haxe.Serializer.USE_CACHE = false;
haxe.Serializer.USE_ENUM_INDEX = false;
haxe.Serializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
haxe.Unserializer.DEFAULT_RESOLVER = Type;
haxe.Unserializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
HelloworldMain.main();
})();

//@ sourceMappingURL=main-html.js.map