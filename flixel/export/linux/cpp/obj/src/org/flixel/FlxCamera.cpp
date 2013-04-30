#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Tilesheet
#include <native/display/Tilesheet.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_org_flixel_FlxBasic
#include <org/flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_org_flixel_FlxCamera
#include <org/flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_org_flixel_FlxG
#include <org/flixel/FlxG.h>
#endif
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxRect
#include <org/flixel/FlxRect.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSprite
#include <org/flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_DrawStackItem
#include <org/flixel/system/layer/DrawStackItem.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_TileSheetData
#include <org/flixel/system/layer/TileSheetData.h>
#endif
namespace org{
namespace flixel{

Void FlxCamera_obj::__construct(int X,int Y,int Width,int Height,hx::Null< Float >  __o_Zoom)
{
HX_STACK_PUSH("FlxCamera::new","org/flixel/FlxCamera.hx",425);
Float Zoom = __o_Zoom.Default(0);
{
	HX_STACK_LINE(426)
	super::__construct();
	HX_STACK_LINE(428)
	this->_scrollTarget = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(430)
	this->x = X;
	HX_STACK_LINE(431)
	this->y = Y;
	HX_STACK_LINE(432)
	this->set_width(Width);
	HX_STACK_LINE(433)
	this->set_height(Height);
	HX_STACK_LINE(434)
	this->target = null();
	HX_STACK_LINE(435)
	this->deadzone = null();
	HX_STACK_LINE(436)
	this->scroll = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(437)
	this->_point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(438)
	this->bounds = null();
	HX_STACK_LINE(445)
	this->bgColor = ::org::flixel::FlxG_obj::get_bgColor();
	HX_STACK_LINE(452)
	this->_canvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(453)
	this->_canvas->set_x((-(this->width) * 0.5));
	HX_STACK_LINE(454)
	this->_canvas->set_y((-(this->height) * 0.5));
	HX_STACK_LINE(460)
	this->set_color((int)-1);
	HX_STACK_LINE(463)
	this->_flashSprite = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(464)
	this->set_zoom(Zoom);
	HX_STACK_LINE(466)
	this->_flashOffsetX = ((this->width * 0.5) * this->zoom);
	HX_STACK_LINE(467)
	this->_flashOffsetY = ((this->height * 0.5) * this->zoom);
	HX_STACK_LINE(469)
	this->_flashSprite->set_x((this->x + this->_flashOffsetX));
	HX_STACK_LINE(470)
	this->_flashSprite->set_y((this->y + this->_flashOffsetY));
	HX_STACK_LINE(475)
	this->_flashSprite->addChild(this->_canvas);
	HX_STACK_LINE(477)
	this->_flashRect = ::native::geom::Rectangle_obj::__new((int)0,(int)0,this->width,this->height);
	HX_STACK_LINE(478)
	this->_flashPoint = ::native::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(480)
	this->_fxFlashColor = (int)0;
	HX_STACK_LINE(481)
	this->_fxFlashDuration = 0.0;
	HX_STACK_LINE(482)
	this->_fxFlashComplete = null();
	HX_STACK_LINE(483)
	this->_fxFlashAlpha = 0.0;
	HX_STACK_LINE(485)
	this->_fxFadeColor = (int)0;
	HX_STACK_LINE(486)
	this->_fxFadeDuration = 0.0;
	HX_STACK_LINE(487)
	this->_fxFadeComplete = null();
	HX_STACK_LINE(488)
	this->_fxFadeAlpha = 0.0;
	HX_STACK_LINE(490)
	this->_fxShakeIntensity = 0.0;
	HX_STACK_LINE(491)
	this->_fxShakeDuration = 0.0;
	HX_STACK_LINE(492)
	this->_fxShakeComplete = null();
	HX_STACK_LINE(493)
	this->_fxShakeOffset = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(494)
	this->_fxShakeDirection = (int)0;
	HX_STACK_LINE(499)
	this->_canvas->set_scrollRect(::native::geom::Rectangle_obj::__new((int)0,(int)0,this->width,this->height));
	HX_STACK_LINE(501)
	this->_effectsLayer = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(502)
	this->_effectsLayer->set_x((-(this->width) * 0.5));
	HX_STACK_LINE(503)
	this->_effectsLayer->set_y((-(this->height) * 0.5));
	HX_STACK_LINE(504)
	this->_flashSprite->addChild(this->_effectsLayer);
	HX_STACK_LINE(506)
	this->red = 1.0;
	HX_STACK_LINE(507)
	this->green = 1.0;
	HX_STACK_LINE(508)
	this->blue = 1.0;
	HX_STACK_LINE(510)
	this->fog = 0.0;
	HX_STACK_LINE(512)
	this->_currentStackItem = ::org::flixel::system::layer::DrawStackItem_obj::__new();
	HX_STACK_LINE(513)
	this->_headOfDrawStack = this->_currentStackItem;
	HX_STACK_LINE(516)
	this->_fxFadeIn = false;
	HX_STACK_LINE(518)
	this->set_alpha(1.0);
	HX_STACK_LINE(519)
	this->set_angle(0.0);
	HX_STACK_LINE(520)
	this->set_antialiasing(false);
}
;
	return null();
}

FlxCamera_obj::~FlxCamera_obj() { }

Dynamic FlxCamera_obj::__CreateEmpty() { return  new FlxCamera_obj; }
hx::ObjectPtr< FlxCamera_obj > FlxCamera_obj::__new(int X,int Y,int Width,int Height,hx::Null< Float >  __o_Zoom)
{  hx::ObjectPtr< FlxCamera_obj > result = new FlxCamera_obj();
	result->__construct(X,Y,Width,Height,__o_Zoom);
	return result;}

Dynamic FlxCamera_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxCamera_obj > result = new FlxCamera_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

int FlxCamera_obj::set_height( int val){
	HX_STACK_PUSH("FlxCamera::set_height","org/flixel/FlxCamera.hx",1310);
	HX_STACK_THIS(this);
	HX_STACK_ARG(val,"val");
	HX_STACK_LINE(1311)
	if (((val > (int)0))){
		HX_STACK_LINE(1313)
		this->height = val;
		HX_STACK_LINE(1321)
		if (((this->_canvas != null()))){
			HX_STACK_LINE(1323)
			::native::geom::Rectangle rect = this->_canvas->get_scrollRect();		HX_STACK_VAR(rect,"rect");
			HX_STACK_LINE(1324)
			rect->height = val;
			HX_STACK_LINE(1325)
			this->_canvas->set_scrollRect(rect);
			HX_STACK_LINE(1327)
			this->_flashOffsetY = ((this->height * 0.5) * this->zoom);
			HX_STACK_LINE(1328)
			this->_effectsLayer->set_y(this->_canvas->set_y((-(this->height) * 0.5)));
		}
	}
	HX_STACK_LINE(1332)
	return val;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_height,return )

int FlxCamera_obj::set_width( int val){
	HX_STACK_PUSH("FlxCamera::set_width","org/flixel/FlxCamera.hx",1284);
	HX_STACK_THIS(this);
	HX_STACK_ARG(val,"val");
	HX_STACK_LINE(1285)
	if (((val > (int)0))){
		HX_STACK_LINE(1287)
		this->width = val;
		HX_STACK_LINE(1295)
		if (((this->_canvas != null()))){
			HX_STACK_LINE(1297)
			::native::geom::Rectangle rect = this->_canvas->get_scrollRect();		HX_STACK_VAR(rect,"rect");
			HX_STACK_LINE(1298)
			rect->width = val;
			HX_STACK_LINE(1299)
			this->_canvas->set_scrollRect(rect);
			HX_STACK_LINE(1301)
			this->_flashOffsetX = ((this->width * 0.5) * this->zoom);
			HX_STACK_LINE(1302)
			this->_effectsLayer->set_x(this->_canvas->set_x((-(this->width) * 0.5)));
		}
	}
	HX_STACK_LINE(1306)
	return val;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_width,return )

bool FlxCamera_obj::isColored( ){
	HX_STACK_PUSH("FlxCamera::isColored","org/flixel/FlxCamera.hx",1274);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1274)
	return (this->color < (int)16777215);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,isColored,return )

Void FlxCamera_obj::drawFX( ){
{
		HX_STACK_PUSH("FlxCamera::drawFX","org/flixel/FlxCamera.hx",1213);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1214)
		Float alphaComponent;		HX_STACK_VAR(alphaComponent,"alphaComponent");
		HX_STACK_LINE(1217)
		if (((this->_fxFlashAlpha > 0.0))){
			HX_STACK_LINE(1222)
			alphaComponent = (int((int(this->_fxFlashColor) >> int((int)24))) & int((int)255));
			HX_STACK_LINE(1228)
			this->fill((int(this->_fxFlashColor) & int((int)16777215)),true,(Float((((  (((alphaComponent <= (int)0))) ? Float((int)255) : Float(alphaComponent) )) * this->_fxFlashAlpha)) / Float((int)255)),this->_effectsLayer->get_graphics());
		}
		HX_STACK_LINE(1235)
		if (((this->_fxFadeAlpha > 0.0))){
			HX_STACK_LINE(1240)
			alphaComponent = (int((int(this->_fxFadeColor) >> int((int)24))) & int((int)255));
			HX_STACK_LINE(1246)
			this->fill((int(this->_fxFadeColor) & int((int)16777215)),true,(Float((((  (((alphaComponent <= (int)0))) ? Float((int)255) : Float(alphaComponent) )) * this->_fxFadeAlpha)) / Float((int)255)),this->_effectsLayer->get_graphics());
		}
		HX_STACK_LINE(1252)
		if (((bool((this->_fxShakeOffset->x != (int)0)) || bool((this->_fxShakeOffset->y != (int)0))))){
			HX_STACK_LINE(1254)
			{
				HX_STACK_LINE(1254)
				::native::display::Sprite _g = this->_flashSprite;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1254)
				_g->set_x((_g->get_x() + this->_fxShakeOffset->x));
			}
			HX_STACK_LINE(1255)
			{
				HX_STACK_LINE(1255)
				::native::display::Sprite _g = this->_flashSprite;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1255)
				_g->set_y((_g->get_y() + this->_fxShakeOffset->y));
			}
		}
		HX_STACK_LINE(1259)
		if (((this->fog > (int)0))){
			HX_STACK_LINE(1261)
			this->_effectsLayer->get_graphics()->beginFill((int)16777215,this->fog);
			HX_STACK_LINE(1262)
			this->_effectsLayer->get_graphics()->drawRect((int)0,(int)0,this->width,this->height);
			HX_STACK_LINE(1263)
			this->_effectsLayer->get_graphics()->endFill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,drawFX,(void))

Void FlxCamera_obj::fill( int Color,hx::Null< bool >  __o_BlendAlpha,hx::Null< Float >  __o_FxAlpha,::native::display::Graphics graphics){
bool BlendAlpha = __o_BlendAlpha.Default(true);
Float FxAlpha = __o_FxAlpha.Default(1.0);
	HX_STACK_PUSH("FlxCamera::fill","org/flixel/FlxCamera.hx",1171);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(BlendAlpha,"BlendAlpha");
	HX_STACK_ARG(FxAlpha,"FxAlpha");
	HX_STACK_ARG(graphics,"graphics");
{
		HX_STACK_LINE(1178)
		::native::display::Graphics targetGraphics = (  (((graphics == null()))) ? ::native::display::Graphics(this->_canvas->get_graphics()) : ::native::display::Graphics(graphics) );		HX_STACK_VAR(targetGraphics,"targetGraphics");
		HX_STACK_LINE(1181)
		Color = (int(Color) & int((int)16777215));
		HX_STACK_LINE(1182)
		if (((bool((bool((this->red != 1.0)) || bool((this->green != 1.0)))) || bool((this->blue != 1.0))))){
			HX_STACK_LINE(1184)
			int redComponent = ::Std_obj::_int((((int(Color) >> int((int)16))) * this->red));		HX_STACK_VAR(redComponent,"redComponent");
			HX_STACK_LINE(1185)
			int greenComponent = ::Std_obj::_int((((int((int(Color) >> int((int)8))) & int((int)255))) * this->green));		HX_STACK_VAR(greenComponent,"greenComponent");
			HX_STACK_LINE(1186)
			int blueComponent = ::Std_obj::_int((((int(Color) & int((int)255))) * this->blue));		HX_STACK_VAR(blueComponent,"blueComponent");
			HX_STACK_LINE(1187)
			Color = (int((int((int(redComponent) << int((int)16))) | int((int(greenComponent) << int((int)8))))) | int(blueComponent));
		}
		HX_STACK_LINE(1191)
		targetGraphics->beginFill(Color,FxAlpha);
		HX_STACK_LINE(1204)
		targetGraphics->drawRect((int)0,(int)0,this->width,this->height);
		HX_STACK_LINE(1205)
		targetGraphics->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,fill,(void))

::native::display::Sprite FlxCamera_obj::getContainerSprite( ){
	HX_STACK_PUSH("FlxCamera::getContainerSprite","org/flixel/FlxCamera.hx",1157);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1157)
	return this->_flashSprite;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,getContainerSprite,return )

Void FlxCamera_obj::setScale( Float X,Float Y){
{
		HX_STACK_PUSH("FlxCamera::setScale","org/flixel/FlxCamera.hx",1135);
		HX_STACK_THIS(this);
		HX_STACK_ARG(X,"X");
		HX_STACK_ARG(Y,"Y");
		HX_STACK_LINE(1137)
		this->_flashSprite->set_scaleX(X);
		HX_STACK_LINE(1138)
		this->_flashSprite->set_scaleY(Y);
		HX_STACK_LINE(1141)
		this->_flashOffsetX = ((this->width * 0.5) * X);
		HX_STACK_LINE(1142)
		this->_flashOffsetY = ((this->height * 0.5) * Y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxCamera_obj,setScale,(void))

::org::flixel::FlxPoint FlxCamera_obj::getScale( ){
	HX_STACK_PUSH("FlxCamera::getScale","org/flixel/FlxCamera.hx",1127);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::org::flixel::FlxPoint Block( ::org::flixel::FlxCamera_obj *__this){
			HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",1128);
			{
				HX_STACK_LINE(1128)
				::org::flixel::FlxPoint _this = __this->_point;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(1128)
				_this->x = __this->_flashSprite->get_scaleX();
				HX_STACK_LINE(1128)
				_this->y = __this->_flashSprite->get_scaleY();
				HX_STACK_LINE(1128)
				return _this;
			}
			return null();
		}
	};
	HX_STACK_LINE(1127)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,getScale,return )

bool FlxCamera_obj::set_antialiasing( bool Antialiasing){
	HX_STACK_PUSH("FlxCamera::set_antialiasing","org/flixel/FlxCamera.hx",1113);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Antialiasing,"Antialiasing");
	HX_STACK_LINE(1114)
	this->antialiasing = Antialiasing;
	HX_STACK_LINE(1118)
	return Antialiasing;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_antialiasing,return )

int FlxCamera_obj::set_color( int Color){
	HX_STACK_PUSH("FlxCamera::set_color","org/flixel/FlxCamera.hx",1077);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_LINE(1078)
	this->color = Color;
	HX_STACK_LINE(1091)
	this->red = (Float(((int(this->color) >> int((int)16)))) / Float((int)255));
	HX_STACK_LINE(1092)
	this->green = (Float(((int((int(this->color) >> int((int)8))) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1093)
	this->blue = (Float(((int(this->color) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1100)
	return Color;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_color,return )

Float FlxCamera_obj::set_angle( Float Angle){
	HX_STACK_PUSH("FlxCamera::set_angle","org/flixel/FlxCamera.hx",1053);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Angle,"Angle");
	HX_STACK_LINE(1054)
	this->angle = Angle;
	HX_STACK_LINE(1055)
	this->_flashSprite->set_rotation(Angle);
	HX_STACK_LINE(1056)
	return Angle;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_angle,return )

Float FlxCamera_obj::set_alpha( Float Alpha){
	HX_STACK_PUSH("FlxCamera::set_alpha","org/flixel/FlxCamera.hx",1035);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Alpha,"Alpha");
	struct _Function_1_1{
		inline static Float Block( Float &Alpha){
			HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",1036);
			{
				HX_STACK_LINE(1036)
				Float lowerBound = (  (((Alpha < (int)0))) ? Float((int)0) : Float(Alpha) );		HX_STACK_VAR(lowerBound,"lowerBound");
				HX_STACK_LINE(1036)
				return (  (((lowerBound > (int)1))) ? Float((int)1) : Float(lowerBound) );
			}
			return null();
		}
	};
	HX_STACK_LINE(1036)
	this->alpha = _Function_1_1::Block(Alpha);
	HX_STACK_LINE(1040)
	this->_canvas->set_alpha(Alpha);
	HX_STACK_LINE(1042)
	return Alpha;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_alpha,return )

Float FlxCamera_obj::set_zoom( Float Zoom){
	HX_STACK_PUSH("FlxCamera::set_zoom","org/flixel/FlxCamera.hx",1013);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Zoom,"Zoom");
	HX_STACK_LINE(1014)
	if (((Zoom == (int)0))){
		HX_STACK_LINE(1015)
		this->zoom = ::org::flixel::FlxCamera_obj::defaultZoom;
	}
	else{
		HX_STACK_LINE(1019)
		this->zoom = Zoom;
	}
	HX_STACK_LINE(1022)
	this->setScale(this->zoom,this->zoom);
	HX_STACK_LINE(1023)
	return this->zoom;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_zoom,return )

::org::flixel::FlxCamera FlxCamera_obj::copyFrom( ::org::flixel::FlxCamera Camera){
	HX_STACK_PUSH("FlxCamera::copyFrom","org/flixel/FlxCamera.hx",974);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_LINE(975)
	if (((Camera->bounds == null()))){
		HX_STACK_LINE(976)
		this->bounds = null();
	}
	else{
		HX_STACK_LINE(981)
		if (((this->bounds == null()))){
			HX_STACK_LINE(982)
			this->bounds = ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
		}
		HX_STACK_LINE(985)
		{
			HX_STACK_LINE(985)
			::org::flixel::FlxRect _this = this->bounds;		HX_STACK_VAR(_this,"_this");
			::org::flixel::FlxRect Rect = Camera->bounds;		HX_STACK_VAR(Rect,"Rect");
			HX_STACK_LINE(985)
			_this->x = Rect->x;
			HX_STACK_LINE(985)
			_this->y = Rect->y;
			HX_STACK_LINE(985)
			_this->width = Rect->width;
			HX_STACK_LINE(985)
			_this->height = Rect->height;
			HX_STACK_LINE(985)
			_this;
		}
	}
	HX_STACK_LINE(987)
	this->target = Camera->target;
	HX_STACK_LINE(988)
	if (((this->target != null()))){
		HX_STACK_LINE(989)
		if (((Camera->deadzone == null()))){
			HX_STACK_LINE(991)
			this->deadzone = null();
		}
		else{
			HX_STACK_LINE(996)
			if (((this->deadzone == null()))){
				HX_STACK_LINE(997)
				this->deadzone = ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
			}
			HX_STACK_LINE(1000)
			{
				HX_STACK_LINE(1000)
				::org::flixel::FlxRect _this = this->deadzone;		HX_STACK_VAR(_this,"_this");
				::org::flixel::FlxRect Rect = Camera->deadzone;		HX_STACK_VAR(Rect,"Rect");
				HX_STACK_LINE(1000)
				_this->x = Rect->x;
				HX_STACK_LINE(1000)
				_this->y = Rect->y;
				HX_STACK_LINE(1000)
				_this->width = Rect->width;
				HX_STACK_LINE(1000)
				_this->height = Rect->height;
				HX_STACK_LINE(1000)
				_this;
			}
		}
	}
	HX_STACK_LINE(1003)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,copyFrom,return )

Void FlxCamera_obj::stopFX( ){
{
		HX_STACK_PUSH("FlxCamera::stopFX","org/flixel/FlxCamera.hx",960);
		HX_STACK_THIS(this);
		HX_STACK_LINE(961)
		this->_fxFlashAlpha = 0.0;
		HX_STACK_LINE(962)
		this->_fxFadeAlpha = 0.0;
		HX_STACK_LINE(963)
		this->_fxShakeDuration = (int)0;
		HX_STACK_LINE(964)
		this->_flashSprite->set_x((this->x + this->_flashOffsetX));
		HX_STACK_LINE(965)
		this->_flashSprite->set_y((this->y + this->_flashOffsetY));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,stopFX,(void))

Void FlxCamera_obj::shake( hx::Null< Float >  __o_Intensity,hx::Null< Float >  __o_Duration,Dynamic OnComplete,hx::Null< bool >  __o_Force,hx::Null< int >  __o_Direction){
Float Intensity = __o_Intensity.Default(0.05);
Float Duration = __o_Duration.Default(0.5);
bool Force = __o_Force.Default(true);
int Direction = __o_Direction.Default(0);
	HX_STACK_PUSH("FlxCamera::shake","org/flixel/FlxCamera.hx",944);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Intensity,"Intensity");
	HX_STACK_ARG(Duration,"Duration");
	HX_STACK_ARG(OnComplete,"OnComplete");
	HX_STACK_ARG(Force,"Force");
	HX_STACK_ARG(Direction,"Direction");
{
		HX_STACK_LINE(945)
		if (((bool(!(Force)) && bool(((bool((this->_fxShakeOffset->x != (int)0)) || bool((this->_fxShakeOffset->y != (int)0)))))))){
			HX_STACK_LINE(946)
			return null();
		}
		HX_STACK_LINE(949)
		this->_fxShakeIntensity = Intensity;
		HX_STACK_LINE(950)
		this->_fxShakeDuration = Duration;
		HX_STACK_LINE(951)
		this->_fxShakeComplete = OnComplete;
		HX_STACK_LINE(952)
		this->_fxShakeDirection = Direction;
		HX_STACK_LINE(953)
		{
			HX_STACK_LINE(953)
			::org::flixel::FlxPoint _this = this->_fxShakeOffset;		HX_STACK_VAR(_this,"_this");
			Float X = (int)0;		HX_STACK_VAR(X,"X");
			Float Y = (int)0;		HX_STACK_VAR(Y,"Y");
			HX_STACK_LINE(953)
			_this->x = X;
			HX_STACK_LINE(953)
			_this->y = Y;
			HX_STACK_LINE(953)
			_this;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxCamera_obj,shake,(void))

Void FlxCamera_obj::fade( Dynamic Color,hx::Null< Float >  __o_Duration,hx::Null< bool >  __o_FadeIn,Dynamic OnComplete,hx::Null< bool >  __o_Force){
Float Duration = __o_Duration.Default(1);
bool FadeIn = __o_FadeIn.Default(false);
bool Force = __o_Force.Default(false);
	HX_STACK_PUSH("FlxCamera::fade","org/flixel/FlxCamera.hx",903);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Duration,"Duration");
	HX_STACK_ARG(FadeIn,"FadeIn");
	HX_STACK_ARG(OnComplete,"OnComplete");
	HX_STACK_ARG(Force,"Force");
{
		HX_STACK_LINE(905)
		if (((Color == null()))){
			HX_STACK_LINE(906)
			Color = (int)-16777216;
		}
		HX_STACK_LINE(911)
		if (((bool(!(Force)) && bool((this->_fxFadeAlpha > 0.0))))){
			HX_STACK_LINE(912)
			return null();
		}
		HX_STACK_LINE(915)
		this->_fxFadeColor = Color;
		HX_STACK_LINE(916)
		if (((Duration <= (int)0))){
			HX_STACK_LINE(917)
			Duration = 5e-324;
		}
		HX_STACK_LINE(921)
		this->_fxFadeIn = FadeIn;
		HX_STACK_LINE(922)
		this->_fxFadeDuration = Duration;
		HX_STACK_LINE(923)
		this->_fxFadeComplete = OnComplete;
		HX_STACK_LINE(925)
		if ((this->_fxFadeIn)){
			HX_STACK_LINE(926)
			this->_fxFadeAlpha = 0.999999;
		}
		else{
			HX_STACK_LINE(930)
			this->_fxFadeAlpha = 5e-324;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxCamera_obj,fade,(void))

Void FlxCamera_obj::flash( Dynamic Color,hx::Null< Float >  __o_Duration,Dynamic OnComplete,hx::Null< bool >  __o_Force){
Float Duration = __o_Duration.Default(1);
bool Force = __o_Force.Default(false);
	HX_STACK_PUSH("FlxCamera::flash","org/flixel/FlxCamera.hx",868);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Duration,"Duration");
	HX_STACK_ARG(OnComplete,"OnComplete");
	HX_STACK_ARG(Force,"Force");
{
		HX_STACK_LINE(870)
		if (((Color == null()))){
			HX_STACK_LINE(871)
			Color = (int)-1;
		}
		HX_STACK_LINE(876)
		if (((bool(!(Force)) && bool((this->_fxFlashAlpha > 0.0))))){
			HX_STACK_LINE(877)
			return null();
		}
		HX_STACK_LINE(880)
		this->_fxFlashColor = Color;
		HX_STACK_LINE(881)
		if (((Duration <= (int)0))){
			HX_STACK_LINE(882)
			Duration = 5e-324;
		}
		HX_STACK_LINE(885)
		this->_fxFlashDuration = Duration;
		HX_STACK_LINE(886)
		this->_fxFlashComplete = OnComplete;
		HX_STACK_LINE(887)
		this->_fxFlashAlpha = 1.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,flash,(void))

Void FlxCamera_obj::setBounds( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height,hx::Null< bool >  __o_UpdateWorld){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
bool UpdateWorld = __o_UpdateWorld.Default(false);
	HX_STACK_PUSH("FlxCamera::setBounds","org/flixel/FlxCamera.hx",843);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_ARG(Width,"Width");
	HX_STACK_ARG(Height,"Height");
	HX_STACK_ARG(UpdateWorld,"UpdateWorld");
{
		HX_STACK_LINE(844)
		if (((this->bounds == null()))){
			HX_STACK_LINE(845)
			this->bounds = ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
		}
		HX_STACK_LINE(848)
		{
			HX_STACK_LINE(848)
			::org::flixel::FlxRect _this = this->bounds;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(848)
			_this->x = X;
			HX_STACK_LINE(848)
			_this->y = Y;
			HX_STACK_LINE(848)
			_this->width = Width;
			HX_STACK_LINE(848)
			_this->height = Height;
			HX_STACK_LINE(848)
			_this;
		}
		HX_STACK_LINE(849)
		if ((UpdateWorld)){
			HX_STACK_LINE(851)
			::org::flixel::FlxRect _this = ::org::flixel::FlxG_obj::worldBounds;		HX_STACK_VAR(_this,"_this");
			::org::flixel::FlxRect Rect = this->bounds;		HX_STACK_VAR(Rect,"Rect");
			HX_STACK_LINE(851)
			_this->x = Rect->x;
			HX_STACK_LINE(851)
			_this->y = Rect->y;
			HX_STACK_LINE(851)
			_this->width = Rect->width;
			HX_STACK_LINE(851)
			_this->height = Rect->height;
			HX_STACK_LINE(851)
			_this;
		}
		HX_STACK_LINE(853)
		this->update();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxCamera_obj,setBounds,(void))

Void FlxCamera_obj::focusOn( ::org::flixel::FlxPoint point){
{
		HX_STACK_PUSH("FlxCamera::focusOn","org/flixel/FlxCamera.hx",830);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(831)
		::org::flixel::FlxPoint _this = this->scroll;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(831)
		_this->x = (point->x - (this->width * 0.5));
		HX_STACK_LINE(831)
		_this->y = (point->y - (this->height * 0.5));
		HX_STACK_LINE(831)
		_this;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,focusOn,(void))

Void FlxCamera_obj::followAdjust( hx::Null< Float >  __o_LeadX,hx::Null< Float >  __o_LeadY){
Float LeadX = __o_LeadX.Default(0);
Float LeadY = __o_LeadY.Default(0);
	HX_STACK_PUSH("FlxCamera::followAdjust","org/flixel/FlxCamera.hx",821);
	HX_STACK_THIS(this);
	HX_STACK_ARG(LeadX,"LeadX");
	HX_STACK_ARG(LeadY,"LeadY");
{
		HX_STACK_LINE(821)
		this->followLead = ::native::geom::Point_obj::__new(LeadX,LeadY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxCamera_obj,followAdjust,(void))

Void FlxCamera_obj::follow( ::org::flixel::FlxObject Target,hx::Null< int >  __o_Style,::org::flixel::FlxPoint Offset,hx::Null< Float >  __o_Lerp){
int Style = __o_Style.Default(0);
Float Lerp = __o_Lerp.Default(0);
	HX_STACK_PUSH("FlxCamera::follow","org/flixel/FlxCamera.hx",778);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Target,"Target");
	HX_STACK_ARG(Style,"Style");
	HX_STACK_ARG(Offset,"Offset");
	HX_STACK_ARG(Lerp,"Lerp");
{
		HX_STACK_LINE(779)
		this->style = Style;
		HX_STACK_LINE(780)
		this->target = Target;
		HX_STACK_LINE(781)
		this->followLerp = Lerp;
		HX_STACK_LINE(782)
		Float helper;		HX_STACK_VAR(helper,"helper");
		HX_STACK_LINE(783)
		Float w = (int)0;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(784)
		Float h = (int)0;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(785)
		this->_lastTargetPosition = null();
		HX_STACK_LINE(786)
		switch( (int)(Style)){
			case (int)1: {
				HX_STACK_LINE(789)
				Float w1 = ((Float(this->width) / Float((int)8)) + ((  (((Offset != null()))) ? Float(Offset->x) : Float((int)0) )));		HX_STACK_VAR(w1,"w1");
				HX_STACK_LINE(790)
				Float h1 = ((Float(this->height) / Float((int)3)) + ((  (((Offset != null()))) ? Float(Offset->y) : Float((int)0) )));		HX_STACK_VAR(h1,"h1");
				HX_STACK_LINE(791)
				this->deadzone = ::org::flixel::FlxRect_obj::__new((Float(((this->width - w1))) / Float((int)2)),((Float(((this->height - h1))) / Float((int)2)) - (h1 * 0.25)),w1,h1);
			}
			;break;
			case (int)2: {
				struct _Function_2_1{
					inline static Float Block( ::org::flixel::FlxCamera_obj *__this){
						HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",793);
						{
							HX_STACK_LINE(793)
							Float Number1 = __this->width;		HX_STACK_VAR(Number1,"Number1");
							Float Number2 = __this->height;		HX_STACK_VAR(Number2,"Number2");
							HX_STACK_LINE(793)
							return (  (((Number1 >= Number2))) ? Float(Number1) : Float(Number2) );
						}
						return null();
					}
				};
				HX_STACK_LINE(793)
				helper = (Float(_Function_2_1::Block(this)) / Float((int)4));
				HX_STACK_LINE(794)
				this->deadzone = ::org::flixel::FlxRect_obj::__new((Float(((this->width - helper))) / Float((int)2)),(Float(((this->height - helper))) / Float((int)2)),helper,helper);
			}
			;break;
			case (int)3: {
				struct _Function_2_1{
					inline static Float Block( ::org::flixel::FlxCamera_obj *__this){
						HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",796);
						{
							HX_STACK_LINE(796)
							Float Number1 = __this->width;		HX_STACK_VAR(Number1,"Number1");
							Float Number2 = __this->height;		HX_STACK_VAR(Number2,"Number2");
							HX_STACK_LINE(796)
							return (  (((Number1 >= Number2))) ? Float(Number1) : Float(Number2) );
						}
						return null();
					}
				};
				HX_STACK_LINE(796)
				helper = (Float(_Function_2_1::Block(this)) / Float((int)8));
				HX_STACK_LINE(797)
				this->deadzone = ::org::flixel::FlxRect_obj::__new((Float(((this->width - helper))) / Float((int)2)),(Float(((this->height - helper))) / Float((int)2)),helper,helper);
			}
			;break;
			case (int)0: {
				HX_STACK_LINE(799)
				if (((this->target != null()))){
					HX_STACK_LINE(801)
					w = (this->target->width + ((  (((Offset != null()))) ? Float(Offset->x) : Float((int)0) )));
					HX_STACK_LINE(802)
					h = (this->target->height + ((  (((Offset != null()))) ? Float(Offset->y) : Float((int)0) )));
				}
				HX_STACK_LINE(804)
				this->deadzone = ::org::flixel::FlxRect_obj::__new((Float(((this->width - w))) / Float((int)2)),((Float(((this->height - h))) / Float((int)2)) - (h * 0.25)),w,h);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(805)
				this->deadzone = ::org::flixel::FlxRect_obj::__new((int)0,(int)0,this->width,this->height);
			}
			;break;
			default: {
				HX_STACK_LINE(807)
				this->deadzone = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,follow,(void))

Void FlxCamera_obj::update( ){
{
		HX_STACK_PUSH("FlxCamera::update","org/flixel/FlxCamera.hx",582);
		HX_STACK_THIS(this);
		HX_STACK_LINE(583)
		if ((::org::flixel::FlxG_obj::paused)){
			HX_STACK_LINE(583)
			return null();
		}
		HX_STACK_LINE(587)
		if (((this->target != null()))){
			HX_STACK_LINE(588)
			if (((this->deadzone == null()))){
				struct _Function_3_1{
					inline static ::org::flixel::FlxPoint Block( ::org::flixel::FlxCamera_obj *__this){
						HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",591);
						{
							HX_STACK_LINE(591)
							::org::flixel::FlxObject _this = __this->target;		HX_STACK_VAR(_this,"_this");
							::org::flixel::FlxPoint point = __this->_point;		HX_STACK_VAR(point,"point");
							HX_STACK_LINE(591)
							if (((point == null()))){
								HX_STACK_LINE(591)
								point = ::org::flixel::FlxPoint_obj::__new(null(),null());
							}
							HX_STACK_LINE(591)
							point->x = (_this->x + (_this->width * 0.5));
							HX_STACK_LINE(591)
							point->y = (_this->y + (_this->height * 0.5));
							HX_STACK_LINE(591)
							return point;
						}
						return null();
					}
				};
				HX_STACK_LINE(590)
				this->focusOn(_Function_3_1::Block(this));
			}
			else{
				HX_STACK_LINE(595)
				Float edge;		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(596)
				Float targetX = this->target->x;		HX_STACK_VAR(targetX,"targetX");
				HX_STACK_LINE(597)
				Float targetY = this->target->y;		HX_STACK_VAR(targetY,"targetY");
				HX_STACK_LINE(599)
				if (((this->style == (int)4))){
					HX_STACK_LINE(601)
					if (((targetX > (this->scroll->x + this->width)))){
						HX_STACK_LINE(602)
						hx::AddEq(this->_scrollTarget->x,this->width);
					}
					else{
						HX_STACK_LINE(605)
						if (((targetX < this->scroll->x))){
							HX_STACK_LINE(606)
							hx::SubEq(this->_scrollTarget->x,this->width);
						}
					}
					HX_STACK_LINE(610)
					if (((targetY > (this->scroll->y + this->height)))){
						HX_STACK_LINE(611)
						hx::AddEq(this->_scrollTarget->y,this->height);
					}
					else{
						HX_STACK_LINE(614)
						if (((targetY < this->scroll->y))){
							HX_STACK_LINE(615)
							hx::SubEq(this->_scrollTarget->y,this->height);
						}
					}
				}
				else{
					HX_STACK_LINE(621)
					edge = (targetX - this->deadzone->x);
					HX_STACK_LINE(622)
					if (((this->_scrollTarget->x > edge))){
						HX_STACK_LINE(623)
						this->_scrollTarget->x = edge;
					}
					HX_STACK_LINE(626)
					edge = (((targetX + this->target->width) - this->deadzone->x) - this->deadzone->width);
					HX_STACK_LINE(627)
					if (((this->_scrollTarget->x < edge))){
						HX_STACK_LINE(628)
						this->_scrollTarget->x = edge;
					}
					HX_STACK_LINE(632)
					edge = (targetY - this->deadzone->y);
					HX_STACK_LINE(633)
					if (((this->_scrollTarget->y > edge))){
						HX_STACK_LINE(634)
						this->_scrollTarget->y = edge;
					}
					HX_STACK_LINE(637)
					edge = (((targetY + this->target->height) - this->deadzone->y) - this->deadzone->height);
					HX_STACK_LINE(638)
					if (((this->_scrollTarget->y < edge))){
						HX_STACK_LINE(639)
						this->_scrollTarget->y = edge;
					}
				}
				HX_STACK_LINE(644)
				if (((bool((this->followLead != null())) && bool(::Std_obj::is(this->target,hx::ClassOf< ::org::flixel::FlxSprite >()))))){
					HX_STACK_LINE(646)
					if (((this->_lastTargetPosition == null()))){
						HX_STACK_LINE(647)
						this->_lastTargetPosition = ::org::flixel::FlxPoint_obj::__new(this->target->x,this->target->y);
					}
					HX_STACK_LINE(650)
					hx::AddEq(this->_scrollTarget->x,(((this->target->x - this->_lastTargetPosition->x)) * this->followLead->x));
					HX_STACK_LINE(651)
					hx::AddEq(this->_scrollTarget->y,(((this->target->y - this->_lastTargetPosition->y)) * this->followLead->y));
					HX_STACK_LINE(653)
					this->_lastTargetPosition->x = this->target->x;
					HX_STACK_LINE(654)
					this->_lastTargetPosition->y = this->target->y;
				}
				HX_STACK_LINE(658)
				if (((this->followLerp == (int)0))){
					HX_STACK_LINE(660)
					this->scroll->x = this->_scrollTarget->x;
					HX_STACK_LINE(661)
					this->scroll->y = this->_scrollTarget->y;
				}
				else{
					HX_STACK_LINE(664)
					hx::AddEq(this->scroll->x,(Float((((this->_scrollTarget->x - this->scroll->x)) * ::org::flixel::FlxG_obj::elapsed)) / Float(((::org::flixel::FlxG_obj::elapsed + (this->followLerp * ::org::flixel::FlxG_obj::elapsed))))));
					HX_STACK_LINE(665)
					hx::AddEq(this->scroll->y,(Float((((this->_scrollTarget->y - this->scroll->y)) * ::org::flixel::FlxG_obj::elapsed)) / Float(((::org::flixel::FlxG_obj::elapsed + (this->followLerp * ::org::flixel::FlxG_obj::elapsed))))));
				}
			}
		}
		HX_STACK_LINE(672)
		if (((this->bounds != null()))){
			HX_STACK_LINE(674)
			if (((this->scroll->x < this->bounds->get_left()))){
				HX_STACK_LINE(675)
				this->scroll->x = this->bounds->get_left();
			}
			HX_STACK_LINE(678)
			if (((this->scroll->x > (this->bounds->get_right() - this->width)))){
				HX_STACK_LINE(679)
				this->scroll->x = (this->bounds->get_right() - this->width);
			}
			HX_STACK_LINE(682)
			if (((this->scroll->y < this->bounds->get_top()))){
				HX_STACK_LINE(683)
				this->scroll->y = this->bounds->get_top();
			}
			HX_STACK_LINE(686)
			if (((this->scroll->y > (this->bounds->get_bottom() - this->height)))){
				HX_STACK_LINE(687)
				this->scroll->y = (this->bounds->get_bottom() - this->height);
			}
		}
		HX_STACK_LINE(693)
		this->scroll->x = (Float(::Math_obj::floor((this->scroll->x * (int)100))) / Float((int)100));
		HX_STACK_LINE(694)
		this->scroll->y = (Float(::Math_obj::floor((this->scroll->y * (int)100))) / Float((int)100));
		HX_STACK_LINE(698)
		if (((this->_fxFlashAlpha > 0.0))){
			HX_STACK_LINE(700)
			hx::SubEq(this->_fxFlashAlpha,(Float(::org::flixel::FlxG_obj::elapsed) / Float(this->_fxFlashDuration)));
			HX_STACK_LINE(701)
			if (((bool((this->_fxFlashAlpha <= (int)0)) && bool((this->_fxFlashComplete_dyn() != null()))))){
				HX_STACK_LINE(702)
				this->_fxFlashComplete();
			}
		}
		HX_STACK_LINE(708)
		if (((bool((this->_fxFadeAlpha > 0.0)) && bool((this->_fxFadeAlpha < 1.0))))){
			HX_STACK_LINE(709)
			if ((this->_fxFadeIn)){
				HX_STACK_LINE(712)
				hx::SubEq(this->_fxFadeAlpha,(Float(::org::flixel::FlxG_obj::elapsed) / Float(this->_fxFadeDuration)));
				HX_STACK_LINE(713)
				if (((this->_fxFadeAlpha <= 0.0))){
					HX_STACK_LINE(715)
					this->_fxFadeAlpha = 0.0;
					HX_STACK_LINE(716)
					if (((this->_fxFadeComplete_dyn() != null()))){
						HX_STACK_LINE(717)
						this->_fxFadeComplete();
					}
				}
			}
			else{
				HX_STACK_LINE(724)
				hx::AddEq(this->_fxFadeAlpha,(Float(::org::flixel::FlxG_obj::elapsed) / Float(this->_fxFadeDuration)));
				HX_STACK_LINE(725)
				if (((this->_fxFadeAlpha >= 1.0))){
					HX_STACK_LINE(727)
					this->_fxFadeAlpha = 1.0;
					HX_STACK_LINE(728)
					if (((this->_fxFadeComplete_dyn() != null()))){
						HX_STACK_LINE(729)
						this->_fxFadeComplete();
					}
				}
			}
		}
		HX_STACK_LINE(737)
		if (((this->_fxShakeDuration > (int)0))){
			HX_STACK_LINE(739)
			hx::SubEq(this->_fxShakeDuration,::org::flixel::FlxG_obj::elapsed);
			HX_STACK_LINE(740)
			if (((this->_fxShakeDuration <= (int)0))){
				HX_STACK_LINE(742)
				{
					HX_STACK_LINE(742)
					::org::flixel::FlxPoint _this = this->_fxShakeOffset;		HX_STACK_VAR(_this,"_this");
					Float X = (int)0;		HX_STACK_VAR(X,"X");
					Float Y = (int)0;		HX_STACK_VAR(Y,"Y");
					HX_STACK_LINE(742)
					_this->x = X;
					HX_STACK_LINE(742)
					_this->y = Y;
					HX_STACK_LINE(742)
					_this;
				}
				HX_STACK_LINE(743)
				if (((this->_fxShakeComplete_dyn() != null()))){
					HX_STACK_LINE(744)
					this->_fxShakeComplete();
				}
			}
			else{
				HX_STACK_LINE(751)
				if (((bool((this->_fxShakeDirection == (int)0)) || bool((this->_fxShakeDirection == (int)1))))){
					struct _Function_4_1{
						inline static Float Block( ){
							HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",753);
							{
								HX_STACK_LINE(753)
								::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
								HX_STACK_LINE(753)
								if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
									HX_STACK_LINE(753)
									hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
								}
								HX_STACK_LINE(753)
								return ::org::flixel::FlxG_obj::globalSeed;
							}
							return null();
						}
					};
					HX_STACK_LINE(752)
					this->_fxShakeOffset->x = ((((((_Function_4_1::Block() * this->_fxShakeIntensity) * this->width) * (int)2) - (this->_fxShakeIntensity * this->width))) * this->zoom);
				}
				HX_STACK_LINE(755)
				if (((bool((this->_fxShakeDirection == (int)0)) || bool((this->_fxShakeDirection == (int)2))))){
					struct _Function_4_1{
						inline static Float Block( ){
							HX_STACK_PUSH("*::closure","org/flixel/FlxCamera.hx",757);
							{
								HX_STACK_LINE(757)
								::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
								HX_STACK_LINE(757)
								if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
									HX_STACK_LINE(757)
									hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
								}
								HX_STACK_LINE(757)
								return ::org::flixel::FlxG_obj::globalSeed;
							}
							return null();
						}
					};
					HX_STACK_LINE(756)
					this->_fxShakeOffset->y = ((((((_Function_4_1::Block() * this->_fxShakeIntensity) * this->height) * (int)2) - (this->_fxShakeIntensity * this->height))) * this->zoom);
				}
			}
			HX_STACK_LINE(762)
			if (((this->target != null()))){
				HX_STACK_LINE(764)
				this->_flashSprite->set_x((this->x + this->_flashOffsetX));
				HX_STACK_LINE(765)
				this->_flashSprite->set_y((this->y + this->_flashOffsetY));
			}
		}
	}
return null();
}


Void FlxCamera_obj::destroy( ){
{
		HX_STACK_PUSH("FlxCamera::destroy","org/flixel/FlxCamera.hx",528);
		HX_STACK_THIS(this);
		HX_STACK_LINE(536)
		this->target = null();
		HX_STACK_LINE(537)
		this->scroll = null();
		HX_STACK_LINE(538)
		this->deadzone = null();
		HX_STACK_LINE(539)
		this->bounds = null();
		HX_STACK_LINE(544)
		this->_flashRect = null();
		HX_STACK_LINE(545)
		this->_flashPoint = null();
		HX_STACK_LINE(546)
		this->_fxFlashComplete = null();
		HX_STACK_LINE(547)
		this->_fxFadeComplete = null();
		HX_STACK_LINE(548)
		this->_fxShakeComplete = null();
		HX_STACK_LINE(549)
		this->_fxShakeOffset = null();
		HX_STACK_LINE(557)
		this->_flashSprite->removeChild(this->_effectsLayer);
		HX_STACK_LINE(558)
		this->_flashSprite->removeChild(this->_canvas);
		HX_STACK_LINE(559)
		int canvasNumChildren = this->_canvas->get_numChildren();		HX_STACK_VAR(canvasNumChildren,"canvasNumChildren");
		HX_STACK_LINE(560)
		{
			HX_STACK_LINE(560)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = canvasNumChildren;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(560)
			while(((_g1 < _g))){
				HX_STACK_LINE(560)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(562)
				this->_canvas->removeChildAt((int)0);
			}
		}
		HX_STACK_LINE(564)
		this->_effectsLayer = null();
		HX_STACK_LINE(565)
		this->_canvas = null();
		HX_STACK_LINE(567)
		{
			HX_STACK_LINE(567)
			::org::flixel::system::layer::DrawStackItem currItem = this->_headOfDrawStack->next;		HX_STACK_VAR(currItem,"currItem");
			HX_STACK_LINE(567)
			while(((currItem != null()))){
				HX_STACK_LINE(567)
				{
					HX_STACK_LINE(567)
					currItem->atlas = null();
					HX_STACK_LINE(567)
					currItem->initialized = false;
					HX_STACK_LINE(567)
					currItem->position = (int)0;
				}
				HX_STACK_LINE(567)
				::org::flixel::system::layer::DrawStackItem newStorageHead = currItem;		HX_STACK_VAR(newStorageHead,"newStorageHead");
				HX_STACK_LINE(567)
				currItem = currItem->next;
				HX_STACK_LINE(567)
				if (((::org::flixel::FlxCamera_obj::_storageHead == null()))){
					HX_STACK_LINE(567)
					::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
					HX_STACK_LINE(567)
					newStorageHead->next = null();
				}
				else{
					HX_STACK_LINE(567)
					newStorageHead->next = ::org::flixel::FlxCamera_obj::_storageHead;
					HX_STACK_LINE(567)
					::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
				}
			}
			HX_STACK_LINE(567)
			{
				HX_STACK_LINE(567)
				::org::flixel::system::layer::DrawStackItem _this = this->_headOfDrawStack;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(567)
				_this->atlas = null();
				HX_STACK_LINE(567)
				_this->initialized = false;
				HX_STACK_LINE(567)
				_this->position = (int)0;
			}
			HX_STACK_LINE(567)
			this->_headOfDrawStack->next = null();
			HX_STACK_LINE(567)
			this->_currentStackItem = this->_headOfDrawStack;
		}
		HX_STACK_LINE(569)
		this->_headOfDrawStack->dispose();
		HX_STACK_LINE(570)
		this->_headOfDrawStack = null();
		HX_STACK_LINE(571)
		this->_currentStackItem = null();
		HX_STACK_LINE(573)
		this->_flashSprite = null();
		HX_STACK_LINE(575)
		this->super::destroy();
	}
return null();
}


Void FlxCamera_obj::render( ){
{
		HX_STACK_PUSH("FlxCamera::render","org/flixel/FlxCamera.hx",372);
		HX_STACK_THIS(this);
		HX_STACK_LINE(373)
		::org::flixel::system::layer::DrawStackItem currItem = this->_headOfDrawStack;		HX_STACK_VAR(currItem,"currItem");
		HX_STACK_LINE(375)
		bool useColor = (this->color < (int)16777215);		HX_STACK_VAR(useColor,"useColor");
		HX_STACK_LINE(377)
		while(((currItem != null()))){
			HX_STACK_LINE(379)
			Array< Float > data = currItem->drawData;		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(380)
			int dataLen = data->length;		HX_STACK_VAR(dataLen,"dataLen");
			HX_STACK_LINE(381)
			int position = currItem->position;		HX_STACK_VAR(position,"position");
			HX_STACK_LINE(382)
			if (((position > (int)0))){
				HX_STACK_LINE(384)
				if (((dataLen != position))){
					HX_STACK_LINE(385)
					data->splice(position,(dataLen - position));
				}
				HX_STACK_LINE(388)
				int tempFlags = (int)16;		HX_STACK_VAR(tempFlags,"tempFlags");
				HX_STACK_LINE(390)
				hx::OrEq(tempFlags,(int)8);
				HX_STACK_LINE(391)
				if (((bool(currItem->colored) || bool(useColor)))){
					HX_STACK_LINE(392)
					hx::OrEq(tempFlags,(int)4);
				}
				HX_STACK_LINE(395)
				hx::OrEq(tempFlags,currItem->blending);
				HX_STACK_LINE(403)
				currItem->atlas->_tileSheetData->tileSheet->drawTiles(this->_canvas->get_graphics(),data,this->antialiasing,tempFlags);
				HX_STACK_LINE(404)
				(::org::flixel::system::layer::TileSheetData_obj::_DRAWCALLS)++;
			}
			HX_STACK_LINE(406)
			currItem = currItem->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,render,(void))

Void FlxCamera_obj::clearDrawStack( ){
{
		HX_STACK_PUSH("FlxCamera::clearDrawStack","org/flixel/FlxCamera.hx",347);
		HX_STACK_THIS(this);
		HX_STACK_LINE(348)
		::org::flixel::system::layer::DrawStackItem currItem = this->_headOfDrawStack->next;		HX_STACK_VAR(currItem,"currItem");
		HX_STACK_LINE(349)
		while(((currItem != null()))){
			HX_STACK_LINE(351)
			{
				HX_STACK_LINE(351)
				currItem->atlas = null();
				HX_STACK_LINE(351)
				currItem->initialized = false;
				HX_STACK_LINE(351)
				currItem->position = (int)0;
			}
			HX_STACK_LINE(352)
			::org::flixel::system::layer::DrawStackItem newStorageHead = currItem;		HX_STACK_VAR(newStorageHead,"newStorageHead");
			HX_STACK_LINE(353)
			currItem = currItem->next;
			HX_STACK_LINE(354)
			if (((::org::flixel::FlxCamera_obj::_storageHead == null()))){
				HX_STACK_LINE(356)
				::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
				HX_STACK_LINE(357)
				newStorageHead->next = null();
			}
			else{
				HX_STACK_LINE(361)
				newStorageHead->next = ::org::flixel::FlxCamera_obj::_storageHead;
				HX_STACK_LINE(362)
				::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
			}
		}
		HX_STACK_LINE(366)
		{
			HX_STACK_LINE(366)
			::org::flixel::system::layer::DrawStackItem _this = this->_headOfDrawStack;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(366)
			_this->atlas = null();
			HX_STACK_LINE(366)
			_this->initialized = false;
			HX_STACK_LINE(366)
			_this->position = (int)0;
		}
		HX_STACK_LINE(367)
		this->_headOfDrawStack->next = null();
		HX_STACK_LINE(368)
		this->_currentStackItem = this->_headOfDrawStack;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,clearDrawStack,(void))

::org::flixel::system::layer::DrawStackItem FlxCamera_obj::getDrawStackItem( ::org::flixel::system::layer::Atlas ObjAtlas,bool ObjColored,int ObjBlending){
	HX_STACK_PUSH("FlxCamera::getDrawStackItem","org/flixel/FlxCamera.hx",292);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ObjAtlas,"ObjAtlas");
	HX_STACK_ARG(ObjColored,"ObjColored");
	HX_STACK_ARG(ObjBlending,"ObjBlending");
	HX_STACK_LINE(293)
	::org::flixel::system::layer::DrawStackItem itemToReturn = null();		HX_STACK_VAR(itemToReturn,"itemToReturn");
	HX_STACK_LINE(294)
	if (((this->_currentStackItem->initialized == false))){
		HX_STACK_LINE(296)
		this->_headOfDrawStack = this->_currentStackItem;
		HX_STACK_LINE(297)
		this->_currentStackItem->atlas = ObjAtlas;
		HX_STACK_LINE(299)
		this->_currentStackItem->colored = ObjColored;
		HX_STACK_LINE(300)
		this->_currentStackItem->blending = ObjBlending;
		HX_STACK_LINE(304)
		itemToReturn = this->_currentStackItem;
	}
	else{
		HX_STACK_LINE(307)
		if (((bool((bool((this->_currentStackItem->atlas == ObjAtlas)) && bool((this->_currentStackItem->colored == ObjColored)))) && bool((this->_currentStackItem->blending == ObjBlending))))){
			HX_STACK_LINE(311)
			itemToReturn = this->_currentStackItem;
		}
	}
	HX_STACK_LINE(315)
	if (((itemToReturn == null()))){
		HX_STACK_LINE(317)
		::org::flixel::system::layer::DrawStackItem newItem = null();		HX_STACK_VAR(newItem,"newItem");
		HX_STACK_LINE(318)
		if (((::org::flixel::FlxCamera_obj::_storageHead != null()))){
			HX_STACK_LINE(320)
			newItem = ::org::flixel::FlxCamera_obj::_storageHead;
			HX_STACK_LINE(321)
			::org::flixel::system::layer::DrawStackItem newHead = ::org::flixel::FlxCamera_obj::_storageHead->next;		HX_STACK_VAR(newHead,"newHead");
			HX_STACK_LINE(322)
			newItem->next = null();
			HX_STACK_LINE(323)
			::org::flixel::FlxCamera_obj::_storageHead = newHead;
		}
		else{
			HX_STACK_LINE(326)
			newItem = ::org::flixel::system::layer::DrawStackItem_obj::__new();
		}
		HX_STACK_LINE(330)
		newItem->atlas = ObjAtlas;
		HX_STACK_LINE(332)
		newItem->colored = ObjColored;
		HX_STACK_LINE(333)
		newItem->blending = ObjBlending;
		HX_STACK_LINE(337)
		this->_currentStackItem->next = newItem;
		HX_STACK_LINE(338)
		this->_currentStackItem = newItem;
		HX_STACK_LINE(339)
		itemToReturn = this->_currentStackItem;
	}
	HX_STACK_LINE(342)
	itemToReturn->initialized = true;
	HX_STACK_LINE(343)
	return itemToReturn;
}


HX_DEFINE_DYNAMIC_FUNC3(FlxCamera_obj,getDrawStackItem,return )

int FlxCamera_obj::STYLE_LOCKON;

int FlxCamera_obj::STYLE_PLATFORMER;

int FlxCamera_obj::STYLE_TOPDOWN;

int FlxCamera_obj::STYLE_TOPDOWN_TIGHT;

int FlxCamera_obj::STYLE_SCREEN_BY_SCREEN;

int FlxCamera_obj::STYLE_NO_DEAD_ZONE;

int FlxCamera_obj::SHAKE_BOTH_AXES;

int FlxCamera_obj::SHAKE_HORIZONTAL_ONLY;

int FlxCamera_obj::SHAKE_VERTICAL_ONLY;

Float FlxCamera_obj::defaultZoom;

::org::flixel::system::layer::DrawStackItem FlxCamera_obj::_storageHead;


FlxCamera_obj::FlxCamera_obj()
{
}

void FlxCamera_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxCamera);
	HX_MARK_MEMBER_NAME(fog,"fog");
	HX_MARK_MEMBER_NAME(antialiasing,"antialiasing");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(zoom,"zoom");
	HX_MARK_MEMBER_NAME(_fxFadeIn,"_fxFadeIn");
	HX_MARK_MEMBER_NAME(_headOfDrawStack,"_headOfDrawStack");
	HX_MARK_MEMBER_NAME(_currentStackItem,"_currentStackItem");
	HX_MARK_MEMBER_NAME(blue,"blue");
	HX_MARK_MEMBER_NAME(green,"green");
	HX_MARK_MEMBER_NAME(red,"red");
	HX_MARK_MEMBER_NAME(_effectsLayer,"_effectsLayer");
	HX_MARK_MEMBER_NAME(_canvas,"_canvas");
	HX_MARK_MEMBER_NAME(_fxShakeDirection,"_fxShakeDirection");
	HX_MARK_MEMBER_NAME(_fxShakeOffset,"_fxShakeOffset");
	HX_MARK_MEMBER_NAME(_fxShakeComplete,"_fxShakeComplete");
	HX_MARK_MEMBER_NAME(_fxShakeDuration,"_fxShakeDuration");
	HX_MARK_MEMBER_NAME(_fxShakeIntensity,"_fxShakeIntensity");
	HX_MARK_MEMBER_NAME(_fxFadeAlpha,"_fxFadeAlpha");
	HX_MARK_MEMBER_NAME(_fxFadeComplete,"_fxFadeComplete");
	HX_MARK_MEMBER_NAME(_fxFadeDuration,"_fxFadeDuration");
	HX_MARK_MEMBER_NAME(_scrollTarget,"_scrollTarget");
	HX_MARK_MEMBER_NAME(_lastTargetPosition,"_lastTargetPosition");
	HX_MARK_MEMBER_NAME(_fxFadeColor,"_fxFadeColor");
	HX_MARK_MEMBER_NAME(_fxFlashAlpha,"_fxFlashAlpha");
	HX_MARK_MEMBER_NAME(_fxFlashComplete,"_fxFlashComplete");
	HX_MARK_MEMBER_NAME(_fxFlashDuration,"_fxFlashDuration");
	HX_MARK_MEMBER_NAME(_fxFlashColor,"_fxFlashColor");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(_flashRect,"_flashRect");
	HX_MARK_MEMBER_NAME(_flashOffsetY,"_flashOffsetY");
	HX_MARK_MEMBER_NAME(_flashOffsetX,"_flashOffsetX");
	HX_MARK_MEMBER_NAME(_flashSprite,"_flashSprite");
	HX_MARK_MEMBER_NAME(_point,"_point");
	HX_MARK_MEMBER_NAME(bgColor,"bgColor");
	HX_MARK_MEMBER_NAME(scroll,"scroll");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(deadzone,"deadzone");
	HX_MARK_MEMBER_NAME(followLerp,"followLerp");
	HX_MARK_MEMBER_NAME(followLead,"followLead");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(style,"style");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxCamera_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fog,"fog");
	HX_VISIT_MEMBER_NAME(antialiasing,"antialiasing");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(zoom,"zoom");
	HX_VISIT_MEMBER_NAME(_fxFadeIn,"_fxFadeIn");
	HX_VISIT_MEMBER_NAME(_headOfDrawStack,"_headOfDrawStack");
	HX_VISIT_MEMBER_NAME(_currentStackItem,"_currentStackItem");
	HX_VISIT_MEMBER_NAME(blue,"blue");
	HX_VISIT_MEMBER_NAME(green,"green");
	HX_VISIT_MEMBER_NAME(red,"red");
	HX_VISIT_MEMBER_NAME(_effectsLayer,"_effectsLayer");
	HX_VISIT_MEMBER_NAME(_canvas,"_canvas");
	HX_VISIT_MEMBER_NAME(_fxShakeDirection,"_fxShakeDirection");
	HX_VISIT_MEMBER_NAME(_fxShakeOffset,"_fxShakeOffset");
	HX_VISIT_MEMBER_NAME(_fxShakeComplete,"_fxShakeComplete");
	HX_VISIT_MEMBER_NAME(_fxShakeDuration,"_fxShakeDuration");
	HX_VISIT_MEMBER_NAME(_fxShakeIntensity,"_fxShakeIntensity");
	HX_VISIT_MEMBER_NAME(_fxFadeAlpha,"_fxFadeAlpha");
	HX_VISIT_MEMBER_NAME(_fxFadeComplete,"_fxFadeComplete");
	HX_VISIT_MEMBER_NAME(_fxFadeDuration,"_fxFadeDuration");
	HX_VISIT_MEMBER_NAME(_scrollTarget,"_scrollTarget");
	HX_VISIT_MEMBER_NAME(_lastTargetPosition,"_lastTargetPosition");
	HX_VISIT_MEMBER_NAME(_fxFadeColor,"_fxFadeColor");
	HX_VISIT_MEMBER_NAME(_fxFlashAlpha,"_fxFlashAlpha");
	HX_VISIT_MEMBER_NAME(_fxFlashComplete,"_fxFlashComplete");
	HX_VISIT_MEMBER_NAME(_fxFlashDuration,"_fxFlashDuration");
	HX_VISIT_MEMBER_NAME(_fxFlashColor,"_fxFlashColor");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(_flashRect,"_flashRect");
	HX_VISIT_MEMBER_NAME(_flashOffsetY,"_flashOffsetY");
	HX_VISIT_MEMBER_NAME(_flashOffsetX,"_flashOffsetX");
	HX_VISIT_MEMBER_NAME(_flashSprite,"_flashSprite");
	HX_VISIT_MEMBER_NAME(_point,"_point");
	HX_VISIT_MEMBER_NAME(bgColor,"bgColor");
	HX_VISIT_MEMBER_NAME(scroll,"scroll");
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	HX_VISIT_MEMBER_NAME(deadzone,"deadzone");
	HX_VISIT_MEMBER_NAME(followLerp,"followLerp");
	HX_VISIT_MEMBER_NAME(followLead,"followLead");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(style,"style");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxCamera_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"fog") ) { return fog; }
		if (HX_FIELD_EQ(inName,"red") ) { return red; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"fill") ) { return fill_dyn(); }
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom; }
		if (HX_FIELD_EQ(inName,"fade") ) { return fade_dyn(); }
		if (HX_FIELD_EQ(inName,"blue") ) { return blue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"alpha") ) { return alpha; }
		if (HX_FIELD_EQ(inName,"shake") ) { return shake_dyn(); }
		if (HX_FIELD_EQ(inName,"flash") ) { return flash_dyn(); }
		if (HX_FIELD_EQ(inName,"green") ) { return green; }
		if (HX_FIELD_EQ(inName,"style") ) { return style; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"drawFX") ) { return drawFX_dyn(); }
		if (HX_FIELD_EQ(inName,"stopFX") ) { return stopFX_dyn(); }
		if (HX_FIELD_EQ(inName,"follow") ) { return follow_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll; }
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"focusOn") ) { return focusOn_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_canvas") ) { return _canvas; }
		if (HX_FIELD_EQ(inName,"bgColor") ) { return bgColor; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setScale") ) { return setScale_dyn(); }
		if (HX_FIELD_EQ(inName,"getScale") ) { return getScale_dyn(); }
		if (HX_FIELD_EQ(inName,"set_zoom") ) { return set_zoom_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"deadzone") ) { return deadzone; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"isColored") ) { return isColored_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angle") ) { return set_angle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"setBounds") ) { return setBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"_fxFadeIn") ) { return _fxFadeIn; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { return _flashRect; }
		if (HX_FIELD_EQ(inName,"followLerp") ) { return followLerp; }
		if (HX_FIELD_EQ(inName,"followLead") ) { return followLead; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultZoom") ) { return defaultZoom; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"STYLE_LOCKON") ) { return STYLE_LOCKON; }
		if (HX_FIELD_EQ(inName,"_storageHead") ) { return _storageHead; }
		if (HX_FIELD_EQ(inName,"antialiasing") ) { return antialiasing; }
		if (HX_FIELD_EQ(inName,"followAdjust") ) { return followAdjust_dyn(); }
		if (HX_FIELD_EQ(inName,"_fxFadeAlpha") ) { return _fxFadeAlpha; }
		if (HX_FIELD_EQ(inName,"_fxFadeColor") ) { return _fxFadeColor; }
		if (HX_FIELD_EQ(inName,"_flashSprite") ) { return _flashSprite; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"STYLE_TOPDOWN") ) { return STYLE_TOPDOWN; }
		if (HX_FIELD_EQ(inName,"_effectsLayer") ) { return _effectsLayer; }
		if (HX_FIELD_EQ(inName,"_scrollTarget") ) { return _scrollTarget; }
		if (HX_FIELD_EQ(inName,"_fxFlashAlpha") ) { return _fxFlashAlpha; }
		if (HX_FIELD_EQ(inName,"_fxFlashColor") ) { return _fxFlashColor; }
		if (HX_FIELD_EQ(inName,"_flashOffsetY") ) { return _flashOffsetY; }
		if (HX_FIELD_EQ(inName,"_flashOffsetX") ) { return _flashOffsetX; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"clearDrawStack") ) { return clearDrawStack_dyn(); }
		if (HX_FIELD_EQ(inName,"_fxShakeOffset") ) { return _fxShakeOffset; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"SHAKE_BOTH_AXES") ) { return SHAKE_BOTH_AXES; }
		if (HX_FIELD_EQ(inName,"_fxFadeComplete") ) { return _fxFadeComplete; }
		if (HX_FIELD_EQ(inName,"_fxFadeDuration") ) { return _fxFadeDuration; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"STYLE_PLATFORMER") ) { return STYLE_PLATFORMER; }
		if (HX_FIELD_EQ(inName,"set_antialiasing") ) { return set_antialiasing_dyn(); }
		if (HX_FIELD_EQ(inName,"getDrawStackItem") ) { return getDrawStackItem_dyn(); }
		if (HX_FIELD_EQ(inName,"_headOfDrawStack") ) { return _headOfDrawStack; }
		if (HX_FIELD_EQ(inName,"_fxShakeComplete") ) { return _fxShakeComplete; }
		if (HX_FIELD_EQ(inName,"_fxShakeDuration") ) { return _fxShakeDuration; }
		if (HX_FIELD_EQ(inName,"_fxFlashComplete") ) { return _fxFlashComplete; }
		if (HX_FIELD_EQ(inName,"_fxFlashDuration") ) { return _fxFlashDuration; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_currentStackItem") ) { return _currentStackItem; }
		if (HX_FIELD_EQ(inName,"_fxShakeDirection") ) { return _fxShakeDirection; }
		if (HX_FIELD_EQ(inName,"_fxShakeIntensity") ) { return _fxShakeIntensity; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"STYLE_NO_DEAD_ZONE") ) { return STYLE_NO_DEAD_ZONE; }
		if (HX_FIELD_EQ(inName,"getContainerSprite") ) { return getContainerSprite_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"STYLE_TOPDOWN_TIGHT") ) { return STYLE_TOPDOWN_TIGHT; }
		if (HX_FIELD_EQ(inName,"SHAKE_VERTICAL_ONLY") ) { return SHAKE_VERTICAL_ONLY; }
		if (HX_FIELD_EQ(inName,"_lastTargetPosition") ) { return _lastTargetPosition; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SHAKE_HORIZONTAL_ONLY") ) { return SHAKE_HORIZONTAL_ONLY; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"STYLE_SCREEN_BY_SCREEN") ) { return STYLE_SCREEN_BY_SCREEN; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxCamera_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"fog") ) { fog=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"red") ) { red=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { if (inCallProp) return set_zoom(inValue);zoom=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blue") ) { blue=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { if (inCallProp) return set_color(inValue);color=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { if (inCallProp) return set_angle(inValue);angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return set_alpha(inValue);alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"green") ) { green=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"style") ) { style=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return set_width(inValue);width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scroll") ) { scroll=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::org::flixel::FlxRect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::org::flixel::FlxObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return set_height(inValue);height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { _canvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bgColor") ) { bgColor=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"deadzone") ) { deadzone=inValue.Cast< ::org::flixel::FlxRect >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fxFadeIn") ) { _fxFadeIn=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_flashRect") ) { _flashRect=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"followLerp") ) { followLerp=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"followLead") ) { followLead=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultZoom") ) { defaultZoom=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"STYLE_LOCKON") ) { STYLE_LOCKON=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_storageHead") ) { _storageHead=inValue.Cast< ::org::flixel::system::layer::DrawStackItem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"antialiasing") ) { if (inCallProp) return set_antialiasing(inValue);antialiasing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeAlpha") ) { _fxFadeAlpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeColor") ) { _fxFadeColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashSprite") ) { _flashSprite=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"STYLE_TOPDOWN") ) { STYLE_TOPDOWN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_effectsLayer") ) { _effectsLayer=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_scrollTarget") ) { _scrollTarget=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFlashAlpha") ) { _fxFlashAlpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFlashColor") ) { _fxFlashColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashOffsetY") ) { _flashOffsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashOffsetX") ) { _flashOffsetX=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_fxShakeOffset") ) { _fxShakeOffset=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"SHAKE_BOTH_AXES") ) { SHAKE_BOTH_AXES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeComplete") ) { _fxFadeComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeDuration") ) { _fxFadeDuration=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"STYLE_PLATFORMER") ) { STYLE_PLATFORMER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_headOfDrawStack") ) { _headOfDrawStack=inValue.Cast< ::org::flixel::system::layer::DrawStackItem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeComplete") ) { _fxShakeComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeDuration") ) { _fxShakeDuration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFlashComplete") ) { _fxFlashComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFlashDuration") ) { _fxFlashDuration=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_currentStackItem") ) { _currentStackItem=inValue.Cast< ::org::flixel::system::layer::DrawStackItem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeDirection") ) { _fxShakeDirection=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeIntensity") ) { _fxShakeIntensity=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"STYLE_NO_DEAD_ZONE") ) { STYLE_NO_DEAD_ZONE=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"STYLE_TOPDOWN_TIGHT") ) { STYLE_TOPDOWN_TIGHT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SHAKE_VERTICAL_ONLY") ) { SHAKE_VERTICAL_ONLY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastTargetPosition") ) { _lastTargetPosition=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SHAKE_HORIZONTAL_ONLY") ) { SHAKE_HORIZONTAL_ONLY=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"STYLE_SCREEN_BY_SCREEN") ) { STYLE_SCREEN_BY_SCREEN=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxCamera_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fog"));
	outFields->push(HX_CSTRING("antialiasing"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("zoom"));
	outFields->push(HX_CSTRING("_fxFadeIn"));
	outFields->push(HX_CSTRING("_headOfDrawStack"));
	outFields->push(HX_CSTRING("_currentStackItem"));
	outFields->push(HX_CSTRING("blue"));
	outFields->push(HX_CSTRING("green"));
	outFields->push(HX_CSTRING("red"));
	outFields->push(HX_CSTRING("_effectsLayer"));
	outFields->push(HX_CSTRING("_canvas"));
	outFields->push(HX_CSTRING("_fxShakeDirection"));
	outFields->push(HX_CSTRING("_fxShakeOffset"));
	outFields->push(HX_CSTRING("_fxShakeDuration"));
	outFields->push(HX_CSTRING("_fxShakeIntensity"));
	outFields->push(HX_CSTRING("_fxFadeAlpha"));
	outFields->push(HX_CSTRING("_fxFadeDuration"));
	outFields->push(HX_CSTRING("_scrollTarget"));
	outFields->push(HX_CSTRING("_lastTargetPosition"));
	outFields->push(HX_CSTRING("_fxFadeColor"));
	outFields->push(HX_CSTRING("_fxFlashAlpha"));
	outFields->push(HX_CSTRING("_fxFlashDuration"));
	outFields->push(HX_CSTRING("_fxFlashColor"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("_flashRect"));
	outFields->push(HX_CSTRING("_flashOffsetY"));
	outFields->push(HX_CSTRING("_flashOffsetX"));
	outFields->push(HX_CSTRING("_flashSprite"));
	outFields->push(HX_CSTRING("_point"));
	outFields->push(HX_CSTRING("bgColor"));
	outFields->push(HX_CSTRING("scroll"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("deadzone"));
	outFields->push(HX_CSTRING("followLerp"));
	outFields->push(HX_CSTRING("followLead"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("style"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("STYLE_LOCKON"),
	HX_CSTRING("STYLE_PLATFORMER"),
	HX_CSTRING("STYLE_TOPDOWN"),
	HX_CSTRING("STYLE_TOPDOWN_TIGHT"),
	HX_CSTRING("STYLE_SCREEN_BY_SCREEN"),
	HX_CSTRING("STYLE_NO_DEAD_ZONE"),
	HX_CSTRING("SHAKE_BOTH_AXES"),
	HX_CSTRING("SHAKE_HORIZONTAL_ONLY"),
	HX_CSTRING("SHAKE_VERTICAL_ONLY"),
	HX_CSTRING("defaultZoom"),
	HX_CSTRING("_storageHead"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_height"),
	HX_CSTRING("set_width"),
	HX_CSTRING("isColored"),
	HX_CSTRING("fog"),
	HX_CSTRING("drawFX"),
	HX_CSTRING("fill"),
	HX_CSTRING("getContainerSprite"),
	HX_CSTRING("setScale"),
	HX_CSTRING("getScale"),
	HX_CSTRING("set_antialiasing"),
	HX_CSTRING("antialiasing"),
	HX_CSTRING("set_color"),
	HX_CSTRING("color"),
	HX_CSTRING("set_angle"),
	HX_CSTRING("angle"),
	HX_CSTRING("set_alpha"),
	HX_CSTRING("alpha"),
	HX_CSTRING("set_zoom"),
	HX_CSTRING("zoom"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("stopFX"),
	HX_CSTRING("shake"),
	HX_CSTRING("fade"),
	HX_CSTRING("flash"),
	HX_CSTRING("setBounds"),
	HX_CSTRING("focusOn"),
	HX_CSTRING("followAdjust"),
	HX_CSTRING("follow"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_fxFadeIn"),
	HX_CSTRING("render"),
	HX_CSTRING("clearDrawStack"),
	HX_CSTRING("getDrawStackItem"),
	HX_CSTRING("_headOfDrawStack"),
	HX_CSTRING("_currentStackItem"),
	HX_CSTRING("blue"),
	HX_CSTRING("green"),
	HX_CSTRING("red"),
	HX_CSTRING("_effectsLayer"),
	HX_CSTRING("_canvas"),
	HX_CSTRING("_fxShakeDirection"),
	HX_CSTRING("_fxShakeOffset"),
	HX_CSTRING("_fxShakeComplete"),
	HX_CSTRING("_fxShakeDuration"),
	HX_CSTRING("_fxShakeIntensity"),
	HX_CSTRING("_fxFadeAlpha"),
	HX_CSTRING("_fxFadeComplete"),
	HX_CSTRING("_fxFadeDuration"),
	HX_CSTRING("_scrollTarget"),
	HX_CSTRING("_lastTargetPosition"),
	HX_CSTRING("_fxFadeColor"),
	HX_CSTRING("_fxFlashAlpha"),
	HX_CSTRING("_fxFlashComplete"),
	HX_CSTRING("_fxFlashDuration"),
	HX_CSTRING("_fxFlashColor"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("_flashRect"),
	HX_CSTRING("_flashOffsetY"),
	HX_CSTRING("_flashOffsetX"),
	HX_CSTRING("_flashSprite"),
	HX_CSTRING("_point"),
	HX_CSTRING("bgColor"),
	HX_CSTRING("scroll"),
	HX_CSTRING("bounds"),
	HX_CSTRING("deadzone"),
	HX_CSTRING("followLerp"),
	HX_CSTRING("followLead"),
	HX_CSTRING("target"),
	HX_CSTRING("style"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxCamera_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_LOCKON,"STYLE_LOCKON");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_PLATFORMER,"STYLE_PLATFORMER");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN,"STYLE_TOPDOWN");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN_TIGHT,"STYLE_TOPDOWN_TIGHT");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_SCREEN_BY_SCREEN,"STYLE_SCREEN_BY_SCREEN");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_NO_DEAD_ZONE,"STYLE_NO_DEAD_ZONE");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::SHAKE_BOTH_AXES,"SHAKE_BOTH_AXES");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::SHAKE_HORIZONTAL_ONLY,"SHAKE_HORIZONTAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::SHAKE_VERTICAL_ONLY,"SHAKE_VERTICAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::defaultZoom,"defaultZoom");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::_storageHead,"_storageHead");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_LOCKON,"STYLE_LOCKON");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_PLATFORMER,"STYLE_PLATFORMER");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN,"STYLE_TOPDOWN");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN_TIGHT,"STYLE_TOPDOWN_TIGHT");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_SCREEN_BY_SCREEN,"STYLE_SCREEN_BY_SCREEN");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_NO_DEAD_ZONE,"STYLE_NO_DEAD_ZONE");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::SHAKE_BOTH_AXES,"SHAKE_BOTH_AXES");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::SHAKE_HORIZONTAL_ONLY,"SHAKE_HORIZONTAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::SHAKE_VERTICAL_ONLY,"SHAKE_VERTICAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::defaultZoom,"defaultZoom");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::_storageHead,"_storageHead");
};

Class FlxCamera_obj::__mClass;

void FlxCamera_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxCamera"), hx::TCanCast< FlxCamera_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxCamera_obj::__boot()
{
	STYLE_LOCKON= (int)0;
	STYLE_PLATFORMER= (int)1;
	STYLE_TOPDOWN= (int)2;
	STYLE_TOPDOWN_TIGHT= (int)3;
	STYLE_SCREEN_BY_SCREEN= (int)4;
	STYLE_NO_DEAD_ZONE= (int)5;
	SHAKE_BOTH_AXES= (int)0;
	SHAKE_HORIZONTAL_ONLY= (int)1;
	SHAKE_VERTICAL_ONLY= (int)2;
}

} // end namespace org
} // end namespace flixel
