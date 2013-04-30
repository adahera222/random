#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_native_display_CapsStyle
#include <native/display/CapsStyle.h>
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
#ifndef INCLUDED_native_display_JointStyle
#include <native/display/JointStyle.h>
#endif
#ifndef INCLUDED_native_display_LineScaleMode
#include <native/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
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
#ifndef INCLUDED_org_flixel_FlxGame
#include <org/flixel/FlxGame.h>
#endif
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPath
#include <org/flixel/FlxPath.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxRect
#include <org/flixel/FlxRect.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTilemap
#include <org/flixel/FlxTilemap.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedGroup
#include <org/flixel/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxDebugger
#include <org/flixel/system/FlxDebugger.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxWindow
#include <org/flixel/system/FlxWindow.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_Log
#include <org/flixel/system/debug/Log.h>
#endif
namespace org{
namespace flixel{

Void FlxObject_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height)
{
HX_STACK_PUSH("FlxObject::new","org/flixel/FlxObject.hx",15);
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
{
	HX_STACK_LINE(266)
	this->_boundingBoxColorOverritten = false;
	HX_STACK_LINE(285)
	super::__construct();
	HX_STACK_LINE(287)
	this->x = X;
	HX_STACK_LINE(288)
	this->y = Y;
	HX_STACK_LINE(289)
	this->last = ::org::flixel::FlxPoint_obj::__new(this->x,this->y);
	HX_STACK_LINE(290)
	this->width = Width;
	HX_STACK_LINE(291)
	this->height = Height;
	HX_STACK_LINE(292)
	this->mass = 1.0;
	HX_STACK_LINE(293)
	this->elasticity = 0.0;
	HX_STACK_LINE(295)
	this->health = (int)1;
	HX_STACK_LINE(297)
	this->immovable = false;
	HX_STACK_LINE(298)
	this->moves = true;
	HX_STACK_LINE(300)
	this->touching = (int)0;
	HX_STACK_LINE(301)
	this->wasTouching = (int)0;
	HX_STACK_LINE(302)
	this->allowCollisions = (int)4369;
	HX_STACK_LINE(304)
	this->velocity = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(305)
	this->acceleration = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(306)
	this->drag = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(307)
	this->maxVelocity = ::org::flixel::FlxPoint_obj::__new((int)10000,(int)10000);
	HX_STACK_LINE(309)
	this->angle = (int)0;
	HX_STACK_LINE(310)
	this->angularVelocity = (int)0;
	HX_STACK_LINE(311)
	this->angularAcceleration = (int)0;
	HX_STACK_LINE(312)
	this->angularDrag = (int)0;
	HX_STACK_LINE(313)
	this->maxAngular = (int)10000;
	HX_STACK_LINE(315)
	this->scrollFactor = ::org::flixel::FlxPoint_obj::__new(1.0,1.0);
	HX_STACK_LINE(316)
	this->_flicker = false;
	HX_STACK_LINE(317)
	this->_flickerTimer = (int)0;
	HX_STACK_LINE(319)
	this->_point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(320)
	this->_rect = ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
	HX_STACK_LINE(322)
	this->path = null();
	HX_STACK_LINE(323)
	this->pathSpeed = (int)0;
	HX_STACK_LINE(324)
	this->pathAngle = (int)0;
}
;
	return null();
}

FlxObject_obj::~FlxObject_obj() { }

Dynamic FlxObject_obj::__CreateEmpty() { return  new FlxObject_obj; }
hx::ObjectPtr< FlxObject_obj > FlxObject_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height)
{  hx::ObjectPtr< FlxObject_obj > result = new FlxObject_obj();
	result->__construct(__o_X,__o_Y,__o_Width,__o_Height);
	return result;}

Dynamic FlxObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxObject_obj > result = new FlxObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void FlxObject_obj::hurt( Float Damage){
{
		HX_STACK_PUSH("FlxObject::hurt","org/flixel/FlxObject.hx",1062);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Damage,"Damage");
		HX_STACK_LINE(1063)
		this->health = (this->health - Damage);
		HX_STACK_LINE(1064)
		if (((this->health <= (int)0))){
			HX_STACK_LINE(1065)
			this->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,hurt,(void))

bool FlxObject_obj::justTouched( int Direction){
	HX_STACK_PUSH("FlxObject::justTouched","org/flixel/FlxObject.hx",1052);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Direction,"Direction");
	HX_STACK_LINE(1052)
	return (bool((((int(this->touching) & int(Direction))) > (int)0)) && bool((((int(this->wasTouching) & int(Direction))) <= (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,justTouched,return )

bool FlxObject_obj::isTouching( int Direction){
	HX_STACK_PUSH("FlxObject::isTouching","org/flixel/FlxObject.hx",1042);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Direction,"Direction");
	HX_STACK_LINE(1042)
	return (((int(this->touching) & int(Direction))) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,isTouching,return )

Void FlxObject_obj::reset( Float X,Float Y){
{
		HX_STACK_PUSH("FlxObject::reset","org/flixel/FlxObject.hx",1024);
		HX_STACK_THIS(this);
		HX_STACK_ARG(X,"X");
		HX_STACK_ARG(Y,"Y");
		HX_STACK_LINE(1025)
		this->revive();
		HX_STACK_LINE(1026)
		this->touching = (int)0;
		HX_STACK_LINE(1027)
		this->wasTouching = (int)0;
		HX_STACK_LINE(1028)
		this->x = X;
		HX_STACK_LINE(1029)
		this->y = Y;
		HX_STACK_LINE(1030)
		this->last->x = this->x;
		HX_STACK_LINE(1031)
		this->last->y = this->y;
		HX_STACK_LINE(1032)
		this->velocity->x = (int)0;
		HX_STACK_LINE(1033)
		this->velocity->y = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,reset,(void))

::org::flixel::FlxPoint FlxObject_obj::getMidpoint( ::org::flixel::FlxPoint point){
	HX_STACK_PUSH("FlxObject::getMidpoint","org/flixel/FlxObject.hx",1007);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(1008)
	if (((point == null()))){
		HX_STACK_LINE(1009)
		point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(1012)
	point->x = (this->x + (this->width * 0.5));
	HX_STACK_LINE(1013)
	point->y = (this->y + (this->height * 0.5));
	HX_STACK_LINE(1014)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,getMidpoint,return )

bool FlxObject_obj::set_solid( bool Solid){
	HX_STACK_PUSH("FlxObject::set_solid","org/flixel/FlxObject.hx",989);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Solid,"Solid");
	HX_STACK_LINE(990)
	if ((Solid)){
		HX_STACK_LINE(991)
		this->allowCollisions = (int)4369;
	}
	else{
		HX_STACK_LINE(995)
		this->allowCollisions = (int)0;
	}
	HX_STACK_LINE(998)
	return Solid;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_solid,return )

bool FlxObject_obj::get_solid( ){
	HX_STACK_PUSH("FlxObject::get_solid","org/flixel/FlxObject.hx",981);
	HX_STACK_THIS(this);
	HX_STACK_LINE(981)
	return (((int(this->allowCollisions) & int((int)4369))) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,get_solid,return )

bool FlxObject_obj::get_flickering( ){
	HX_STACK_PUSH("FlxObject::get_flickering","org/flixel/FlxObject.hx",969);
	HX_STACK_THIS(this);
	HX_STACK_LINE(969)
	return (this->_flickerTimer != (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,get_flickering,return )

Void FlxObject_obj::flicker( hx::Null< Float >  __o_Duration){
Float Duration = __o_Duration.Default(1);
	HX_STACK_PUSH("FlxObject::flicker","org/flixel/FlxObject.hx",954);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Duration,"Duration");
{
		HX_STACK_LINE(955)
		this->_flickerTimer = Duration;
		HX_STACK_LINE(956)
		if (((this->_flickerTimer == (int)0))){
			HX_STACK_LINE(957)
			this->_flicker = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,flicker,(void))

::org::flixel::FlxPoint FlxObject_obj::getScreenXY( ::org::flixel::FlxPoint point,::org::flixel::FlxCamera Camera){
	HX_STACK_PUSH("FlxObject::getScreenXY","org/flixel/FlxObject.hx",934);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_LINE(935)
	if (((point == null()))){
		HX_STACK_LINE(936)
		point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(939)
	if (((Camera == null()))){
		HX_STACK_LINE(940)
		Camera = ::org::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(943)
	point->x = (this->x - (Camera->scroll->x * this->scrollFactor->x));
	HX_STACK_LINE(944)
	point->y = (this->y - (Camera->scroll->y * this->scrollFactor->y));
	HX_STACK_LINE(945)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,getScreenXY,return )

bool FlxObject_obj::onScreenObject( ::org::flixel::FlxCamera Camera){
	HX_STACK_PUSH("FlxObject::onScreenObject","org/flixel/FlxObject.hx",918);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_LINE(919)
	if (((Camera == null()))){
		HX_STACK_LINE(920)
		Camera = ::org::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(923)
	{
		HX_STACK_LINE(923)
		::org::flixel::FlxPoint point = this->_point;		HX_STACK_VAR(point,"point");
		::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
		HX_STACK_LINE(923)
		if (((point == null()))){
			HX_STACK_LINE(923)
			point = ::org::flixel::FlxPoint_obj::__new(null(),null());
		}
		HX_STACK_LINE(923)
		if (((Camera1 == null()))){
			HX_STACK_LINE(923)
			Camera1 = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(923)
		point->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
		HX_STACK_LINE(923)
		point->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
		HX_STACK_LINE(923)
		point;
	}
	HX_STACK_LINE(924)
	return (bool((bool((bool(((this->_point->x + this->width) > (int)0)) && bool((this->_point->x < Camera->width)))) && bool(((this->_point->y + this->height) > (int)0)))) && bool((this->_point->y < Camera->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,onScreenObject,return )

bool FlxObject_obj::onScreen( ::org::flixel::FlxCamera Camera){
	HX_STACK_PUSH("FlxObject::onScreen","org/flixel/FlxObject.hx",913);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	struct _Function_1_1{
		inline static bool Block( ::org::flixel::FlxCamera &Camera,::org::flixel::FlxObject_obj *__this){
			HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",914);
			{
				HX_STACK_LINE(914)
				::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
				HX_STACK_LINE(914)
				if (((Camera1 == null()))){
					HX_STACK_LINE(914)
					Camera1 = ::org::flixel::FlxG_obj::camera;
				}
				HX_STACK_LINE(914)
				{
					HX_STACK_LINE(914)
					::org::flixel::FlxPoint point = __this->_point;		HX_STACK_VAR(point,"point");
					::org::flixel::FlxCamera Camera2 = Camera1;		HX_STACK_VAR(Camera2,"Camera2");
					HX_STACK_LINE(914)
					if (((point == null()))){
						HX_STACK_LINE(914)
						point = ::org::flixel::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(914)
					if (((Camera2 == null()))){
						HX_STACK_LINE(914)
						Camera2 = ::org::flixel::FlxG_obj::camera;
					}
					HX_STACK_LINE(914)
					point->x = (__this->x - (Camera2->scroll->x * __this->scrollFactor->x));
					HX_STACK_LINE(914)
					point->y = (__this->y - (Camera2->scroll->y * __this->scrollFactor->y));
					HX_STACK_LINE(914)
					point;
				}
				HX_STACK_LINE(914)
				return (bool((bool((bool(((__this->_point->x + __this->width) > (int)0)) && bool((__this->_point->x < Camera1->width)))) && bool(((__this->_point->y + __this->height) > (int)0)))) && bool((__this->_point->y < Camera1->height)));
			}
			return null();
		}
	};
	HX_STACK_LINE(913)
	return _Function_1_1::Block(Camera,this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,onScreen,return )

bool FlxObject_obj::overlapsPoint( ::org::flixel::FlxPoint point,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxObject::overlapsPoint","org/flixel/FlxObject.hx",891);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(892)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(893)
			return (bool((bool((bool((point->x > this->x)) && bool((point->x < (this->x + this->width))))) && bool((point->y > this->y)))) && bool((point->y < (this->y + this->height))));
		}
		HX_STACK_LINE(897)
		if (((Camera == null()))){
			HX_STACK_LINE(898)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(901)
		Float X = (point->x - Camera->scroll->x);		HX_STACK_VAR(X,"X");
		HX_STACK_LINE(902)
		Float Y = (point->y - Camera->scroll->y);		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(903)
		{
			HX_STACK_LINE(903)
			::org::flixel::FlxPoint point1 = this->_point;		HX_STACK_VAR(point1,"point1");
			::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
			HX_STACK_LINE(903)
			if (((point1 == null()))){
				HX_STACK_LINE(903)
				point1 = ::org::flixel::FlxPoint_obj::__new(null(),null());
			}
			HX_STACK_LINE(903)
			if (((Camera1 == null()))){
				HX_STACK_LINE(903)
				Camera1 = ::org::flixel::FlxG_obj::camera;
			}
			HX_STACK_LINE(903)
			point1->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
			HX_STACK_LINE(903)
			point1->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
			HX_STACK_LINE(903)
			point1;
		}
		HX_STACK_LINE(904)
		return (bool((bool((bool((X > this->_point->x)) && bool((X < (this->_point->x + this->width))))) && bool((Y > this->_point->y)))) && bool((Y < (this->_point->y + this->height))));
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxObject_obj,overlapsPoint,return )

bool FlxObject_obj::overlapsAt( Float X,Float Y,::org::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxObject::overlapsAt","org/flixel/FlxObject.hx",836);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(837)
		if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxTypedGroup >()))){
			HX_STACK_LINE(839)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(840)
			::org::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(841)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(842)
			::org::flixel::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(843)
			Array< ::org::flixel::FlxBasic > members = grp->members;		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(844)
			while(((i < ::Std_obj::_int(grp->length)))){
				HX_STACK_LINE(846)
				basic = members->__get((i)++);
				HX_STACK_LINE(847)
				if (((bool((bool((basic != null())) && bool(basic->exists))) && bool(this->overlapsAt(X,Y,basic,InScreenSpace,Camera))))){
					HX_STACK_LINE(848)
					results = true;
				}
			}
			HX_STACK_LINE(852)
			return results;
		}
		HX_STACK_LINE(855)
		if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxTilemap >()))){
			HX_STACK_LINE(861)
			::org::flixel::FlxTilemap tilemap = hx::TCast< org::flixel::FlxTilemap >::cast(ObjectOrGroup);		HX_STACK_VAR(tilemap,"tilemap");
			HX_STACK_LINE(862)
			return tilemap->overlapsAt((tilemap->x - ((X - this->x))),(tilemap->y - ((Y - this->y))),hx::ObjectPtr<OBJ_>(this),InScreenSpace,Camera);
		}
		HX_STACK_LINE(865)
		::org::flixel::FlxObject object = hx::TCast< org::flixel::FlxObject >::cast(ObjectOrGroup);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(866)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(867)
			return (bool((bool((bool(((object->x + object->width) > X)) && bool((object->x < (X + this->width))))) && bool(((object->y + object->height) > Y)))) && bool((object->y < (Y + this->height))));
		}
		HX_STACK_LINE(872)
		if (((Camera == null()))){
			HX_STACK_LINE(873)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		struct _Function_1_1{
			inline static ::org::flixel::FlxPoint Block( ::org::flixel::FlxCamera &Camera,::org::flixel::FlxObject &object){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",876);
				{
					HX_STACK_LINE(876)
					::org::flixel::FlxPoint point = null();		HX_STACK_VAR(point,"point");
					::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
					HX_STACK_LINE(876)
					if (((point == null()))){
						HX_STACK_LINE(876)
						point = ::org::flixel::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(876)
					if (((Camera1 == null()))){
						HX_STACK_LINE(876)
						Camera1 = ::org::flixel::FlxG_obj::camera;
					}
					HX_STACK_LINE(876)
					point->x = (object->x - (Camera1->scroll->x * object->scrollFactor->x));
					HX_STACK_LINE(876)
					point->y = (object->y - (Camera1->scroll->y * object->scrollFactor->y));
					HX_STACK_LINE(876)
					return point;
				}
				return null();
			}
		};
		HX_STACK_LINE(876)
		::org::flixel::FlxPoint objectScreenPos = _Function_1_1::Block(Camera,object);		HX_STACK_VAR(objectScreenPos,"objectScreenPos");
		HX_STACK_LINE(877)
		this->_point->x = (X - (Camera->scroll->x * this->scrollFactor->x));
		HX_STACK_LINE(878)
		this->_point->y = (Y - (Camera->scroll->y * this->scrollFactor->y));
		HX_STACK_LINE(879)
		return (bool((bool((bool(((objectScreenPos->x + object->width) > this->_point->x)) && bool((objectScreenPos->x < (this->_point->x + this->width))))) && bool(((objectScreenPos->y + object->height) > this->_point->y)))) && bool((objectScreenPos->y < (this->_point->y + this->height))));
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxObject_obj,overlapsAt,return )

bool FlxObject_obj::overlaps( ::org::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxObject::overlaps","org/flixel/FlxObject.hx",781);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(782)
		if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxTypedGroup >()))){
			HX_STACK_LINE(784)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(785)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(786)
			::org::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(787)
			::org::flixel::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(788)
			Array< ::org::flixel::FlxBasic > members = grp->members;		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(789)
			while(((i < grp->length))){
				HX_STACK_LINE(791)
				basic = members->__get((i)++);
				HX_STACK_LINE(792)
				if (((bool((bool((basic != null())) && bool(basic->exists))) && bool(this->overlaps(basic,InScreenSpace,Camera))))){
					HX_STACK_LINE(793)
					results = true;
				}
			}
			HX_STACK_LINE(797)
			return results;
		}
		HX_STACK_LINE(800)
		if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxTilemap >()))){
			HX_STACK_LINE(801)
			return (hx::TCast< org::flixel::FlxTilemap >::cast(ObjectOrGroup))->overlaps(hx::ObjectPtr<OBJ_>(this),InScreenSpace,Camera);
		}
		HX_STACK_LINE(807)
		::org::flixel::FlxObject object = hx::TCast< org::flixel::FlxObject >::cast(ObjectOrGroup);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(808)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(809)
			return (bool((bool((bool(((object->x + object->width) > this->x)) && bool((object->x < (this->x + this->width))))) && bool(((object->y + object->height) > this->y)))) && bool((object->y < (this->y + this->height))));
		}
		HX_STACK_LINE(814)
		if (((Camera == null()))){
			HX_STACK_LINE(815)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		struct _Function_1_1{
			inline static ::org::flixel::FlxPoint Block( ::org::flixel::FlxCamera &Camera,::org::flixel::FlxObject &object){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",818);
				{
					HX_STACK_LINE(818)
					::org::flixel::FlxPoint point = null();		HX_STACK_VAR(point,"point");
					::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
					HX_STACK_LINE(818)
					if (((point == null()))){
						HX_STACK_LINE(818)
						point = ::org::flixel::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(818)
					if (((Camera1 == null()))){
						HX_STACK_LINE(818)
						Camera1 = ::org::flixel::FlxG_obj::camera;
					}
					HX_STACK_LINE(818)
					point->x = (object->x - (Camera1->scroll->x * object->scrollFactor->x));
					HX_STACK_LINE(818)
					point->y = (object->y - (Camera1->scroll->y * object->scrollFactor->y));
					HX_STACK_LINE(818)
					return point;
				}
				return null();
			}
		};
		HX_STACK_LINE(818)
		::org::flixel::FlxPoint objectScreenPos = _Function_1_1::Block(Camera,object);		HX_STACK_VAR(objectScreenPos,"objectScreenPos");
		HX_STACK_LINE(819)
		{
			HX_STACK_LINE(819)
			::org::flixel::FlxPoint point = this->_point;		HX_STACK_VAR(point,"point");
			::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
			HX_STACK_LINE(819)
			if (((point == null()))){
				HX_STACK_LINE(819)
				point = ::org::flixel::FlxPoint_obj::__new(null(),null());
			}
			HX_STACK_LINE(819)
			if (((Camera1 == null()))){
				HX_STACK_LINE(819)
				Camera1 = ::org::flixel::FlxG_obj::camera;
			}
			HX_STACK_LINE(819)
			point->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
			HX_STACK_LINE(819)
			point->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
			HX_STACK_LINE(819)
			point;
		}
		HX_STACK_LINE(820)
		return (bool((bool((bool(((objectScreenPos->x + object->width) > this->_point->x)) && bool((objectScreenPos->x < (this->_point->x + this->width))))) && bool(((objectScreenPos->y + object->height) > this->_point->y)))) && bool((objectScreenPos->y < (this->_point->y + this->height))));
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxObject_obj,overlaps,return )

Void FlxObject_obj::updatePathMotion( ){
{
		HX_STACK_PUSH("FlxObject::updatePathMotion","org/flixel/FlxObject.hx",684);
		HX_STACK_THIS(this);
		HX_STACK_LINE(686)
		this->_point->x = (this->x + (this->width * 0.5));
		HX_STACK_LINE(687)
		this->_point->y = (this->y + (this->height * 0.5));
		HX_STACK_LINE(688)
		::org::flixel::FlxPoint node = this->path->nodes->__get(this->_pathNodeIndex);		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(689)
		Float deltaX = (node->x - this->_point->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(690)
		Float deltaY = (node->y - this->_point->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(692)
		bool horizontalOnly = (((int(this->_pathMode) & int((int)65536))) > (int)0);		HX_STACK_VAR(horizontalOnly,"horizontalOnly");
		HX_STACK_LINE(693)
		bool verticalOnly = (((int(this->_pathMode) & int((int)1048576))) > (int)0);		HX_STACK_VAR(verticalOnly,"verticalOnly");
		HX_STACK_LINE(695)
		if ((horizontalOnly)){
			HX_STACK_LINE(696)
			if (((((  (((deltaX > (int)0))) ? Float(deltaX) : Float(-(deltaX)) )) < (this->pathSpeed * ::org::flixel::FlxG_obj::elapsed)))){
				HX_STACK_LINE(698)
				node = this->advancePath(null());
			}
		}
		else{
			HX_STACK_LINE(702)
			if ((verticalOnly)){
				HX_STACK_LINE(703)
				if (((((  (((deltaY > (int)0))) ? Float(deltaY) : Float(-(deltaY)) )) < (this->pathSpeed * ::org::flixel::FlxG_obj::elapsed)))){
					HX_STACK_LINE(705)
					node = this->advancePath(null());
				}
			}
			else{
				HX_STACK_LINE(710)
				if (((::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY))) < (this->pathSpeed * ::org::flixel::FlxG_obj::elapsed)))){
					HX_STACK_LINE(712)
					node = this->advancePath(null());
				}
			}
		}
		HX_STACK_LINE(718)
		if (((this->pathSpeed != (int)0))){
			HX_STACK_LINE(721)
			this->_point->x = (this->x + (this->width * 0.5));
			HX_STACK_LINE(722)
			this->_point->y = (this->y + (this->height * 0.5));
			HX_STACK_LINE(723)
			if (((bool(horizontalOnly) || bool((this->_point->y == node->y))))){
				HX_STACK_LINE(725)
				this->velocity->x = (  (((this->_point->x < node->x))) ? Float(this->pathSpeed) : Float(-(this->pathSpeed)) );
				HX_STACK_LINE(726)
				if (((this->velocity->x < (int)0))){
					HX_STACK_LINE(727)
					this->pathAngle = (int)-90;
				}
				else{
					HX_STACK_LINE(731)
					this->pathAngle = (int)90;
				}
				HX_STACK_LINE(734)
				if ((!(horizontalOnly))){
					HX_STACK_LINE(735)
					this->velocity->y = (int)0;
				}
			}
			else{
				HX_STACK_LINE(739)
				if (((bool(verticalOnly) || bool((this->_point->x == node->x))))){
					HX_STACK_LINE(741)
					this->velocity->y = (  (((this->_point->y < node->y))) ? Float(this->pathSpeed) : Float(-(this->pathSpeed)) );
					HX_STACK_LINE(742)
					if (((this->velocity->y < (int)0))){
						HX_STACK_LINE(743)
						this->pathAngle = (int)0;
					}
					else{
						HX_STACK_LINE(747)
						this->pathAngle = (int)180;
					}
					HX_STACK_LINE(750)
					if ((!(verticalOnly))){
						HX_STACK_LINE(751)
						this->velocity->x = (int)0;
					}
				}
				else{
					struct _Function_4_1{
						inline static Float Block( ::org::flixel::FlxObject_obj *__this,::org::flixel::FlxPoint &node){
							HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",757);
							{
								HX_STACK_LINE(757)
								::org::flixel::FlxPoint Point1 = __this->_point;		HX_STACK_VAR(Point1,"Point1");
								HX_STACK_LINE(757)
								Float x = (node->x - Point1->x);		HX_STACK_VAR(x,"x");
								HX_STACK_LINE(757)
								Float y = (node->y - Point1->y);		HX_STACK_VAR(y,"y");
								HX_STACK_LINE(757)
								Float angle = (int)0;		HX_STACK_VAR(angle,"angle");
								HX_STACK_LINE(757)
								if (((bool((x != (int)0)) || bool((y != (int)0))))){
									HX_STACK_LINE(757)
									Float c1 = 0.7853981625;		HX_STACK_VAR(c1,"c1");
									HX_STACK_LINE(757)
									Float c2 = ((int)3 * c1);		HX_STACK_VAR(c2,"c2");
									HX_STACK_LINE(757)
									Float ay = (  (((y < (int)0))) ? Float(-(y)) : Float(y) );		HX_STACK_VAR(ay,"ay");
									HX_STACK_LINE(757)
									if (((x >= (int)0))){
										HX_STACK_LINE(757)
										angle = (c1 - (c1 * ((Float(((x - ay))) / Float(((x + ay)))))));
									}
									else{
										HX_STACK_LINE(757)
										angle = (c2 - (c1 * ((Float(((x + ay))) / Float(((ay - x)))))));
									}
									HX_STACK_LINE(757)
									angle = (((  (((y < (int)0))) ? Float(-(angle)) : Float(angle) )) * 57.2957796);
									HX_STACK_LINE(757)
									if (((angle > (int)90))){
										HX_STACK_LINE(757)
										angle = (angle - (int)270);
									}
									else{
										HX_STACK_LINE(757)
										hx::AddEq(angle,(int)90);
									}
								}
								HX_STACK_LINE(757)
								return angle;
							}
							return null();
						}
					};
					HX_STACK_LINE(757)
					this->pathAngle = _Function_4_1::Block(this,node);
					HX_STACK_LINE(758)
					{
						HX_STACK_LINE(758)
						::org::flixel::FlxPoint point = this->velocity;		HX_STACK_VAR(point,"point");
						HX_STACK_LINE(758)
						Float sin = (int)0;		HX_STACK_VAR(sin,"sin");
						HX_STACK_LINE(758)
						Float cos = (int)0;		HX_STACK_VAR(cos,"cos");
						HX_STACK_LINE(758)
						Float radians = (this->pathAngle * -0.017453293);		HX_STACK_VAR(radians,"radians");
						HX_STACK_LINE(758)
						while(((radians < -3.14159265))){
							HX_STACK_LINE(758)
							hx::AddEq(radians,6.28318531);
						}
						HX_STACK_LINE(758)
						while(((radians > 3.14159265))){
							HX_STACK_LINE(758)
							radians = (radians - 6.28318531);
						}
						HX_STACK_LINE(758)
						if (((radians < (int)0))){
							HX_STACK_LINE(758)
							sin = ((1.27323954 * radians) + ((.405284735 * radians) * radians));
							HX_STACK_LINE(758)
							if (((sin < (int)0))){
								HX_STACK_LINE(758)
								sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
							}
							else{
								HX_STACK_LINE(758)
								sin = ((.225 * (((sin * sin) - sin))) + sin);
							}
						}
						else{
							HX_STACK_LINE(758)
							sin = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
							HX_STACK_LINE(758)
							if (((sin < (int)0))){
								HX_STACK_LINE(758)
								sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
							}
							else{
								HX_STACK_LINE(758)
								sin = ((.225 * (((sin * sin) - sin))) + sin);
							}
						}
						HX_STACK_LINE(758)
						hx::AddEq(radians,1.57079632);
						HX_STACK_LINE(758)
						if (((radians > 3.14159265))){
							HX_STACK_LINE(758)
							radians = (radians - 6.28318531);
						}
						HX_STACK_LINE(758)
						if (((radians < (int)0))){
							HX_STACK_LINE(758)
							cos = ((1.27323954 * radians) + ((0.405284735 * radians) * radians));
							HX_STACK_LINE(758)
							if (((cos < (int)0))){
								HX_STACK_LINE(758)
								cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
							}
							else{
								HX_STACK_LINE(758)
								cos = ((.225 * (((cos * cos) - cos))) + cos);
							}
						}
						else{
							HX_STACK_LINE(758)
							cos = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
							HX_STACK_LINE(758)
							if (((cos < (int)0))){
								HX_STACK_LINE(758)
								cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
							}
							else{
								HX_STACK_LINE(758)
								cos = ((.225 * (((cos * cos) - cos))) + cos);
							}
						}
						HX_STACK_LINE(758)
						Float dx = (int)0;		HX_STACK_VAR(dx,"dx");
						HX_STACK_LINE(758)
						Float dy = this->pathSpeed;		HX_STACK_VAR(dy,"dy");
						HX_STACK_LINE(758)
						if (((point == null()))){
							HX_STACK_LINE(758)
							point = ::org::flixel::FlxPoint_obj::__new(null(),null());
						}
						HX_STACK_LINE(758)
						point->x = ((cos * dx) - (sin * dy));
						HX_STACK_LINE(758)
						point->y = (((int)0 - (sin * dx)) - (cos * dy));
						HX_STACK_LINE(758)
						point;
					}
				}
			}
			HX_STACK_LINE(762)
			if ((this->_pathRotate)){
				HX_STACK_LINE(764)
				this->angularVelocity = (int)0;
				HX_STACK_LINE(765)
				this->angularAcceleration = (int)0;
				HX_STACK_LINE(766)
				this->angle = this->pathAngle;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,updatePathMotion,(void))

::org::flixel::FlxPoint FlxObject_obj::advancePath( hx::Null< bool >  __o_Snap){
bool Snap = __o_Snap.Default(true);
	HX_STACK_PUSH("FlxObject::advancePath","org/flixel/FlxObject.hx",592);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Snap,"Snap");
{
		HX_STACK_LINE(593)
		if ((Snap)){
			HX_STACK_LINE(595)
			::org::flixel::FlxPoint oldNode = this->path->nodes->__get(this->_pathNodeIndex);		HX_STACK_VAR(oldNode,"oldNode");
			HX_STACK_LINE(596)
			if (((oldNode != null()))){
				HX_STACK_LINE(598)
				if (((((int(this->_pathMode) & int((int)1048576))) == (int)0))){
					HX_STACK_LINE(599)
					this->x = (oldNode->x - (this->width * 0.5));
				}
				HX_STACK_LINE(602)
				if (((((int(this->_pathMode) & int((int)65536))) == (int)0))){
					HX_STACK_LINE(603)
					this->y = (oldNode->y - (this->height * 0.5));
				}
			}
		}
		HX_STACK_LINE(609)
		hx::AddEq(this->_pathNodeIndex,this->_pathInc);
		HX_STACK_LINE(611)
		if (((((int(this->_pathMode) & int((int)1))) > (int)0))){
			HX_STACK_LINE(612)
			if (((this->_pathNodeIndex < (int)0))){
				HX_STACK_LINE(615)
				this->_pathNodeIndex = (int)0;
				HX_STACK_LINE(616)
				this->stopFollowingPath(false);
			}
		}
		else{
			HX_STACK_LINE(619)
			if (((((int(this->_pathMode) & int((int)16))) > (int)0))){
				HX_STACK_LINE(620)
				if (((this->_pathNodeIndex >= this->path->nodes->length))){
					HX_STACK_LINE(622)
					this->_pathNodeIndex = (int)0;
				}
			}
			else{
				HX_STACK_LINE(626)
				if (((((int(this->_pathMode) & int((int)256))) > (int)0))){
					HX_STACK_LINE(627)
					if (((this->_pathNodeIndex < (int)0))){
						HX_STACK_LINE(630)
						this->_pathNodeIndex = (this->path->nodes->length - (int)1);
						HX_STACK_LINE(631)
						if (((this->_pathNodeIndex < (int)0))){
							HX_STACK_LINE(632)
							this->_pathNodeIndex = (int)0;
						}
					}
				}
				else{
					HX_STACK_LINE(637)
					if (((((int(this->_pathMode) & int((int)4096))) > (int)0))){
						HX_STACK_LINE(638)
						if (((this->_pathInc > (int)0))){
							HX_STACK_LINE(640)
							if (((this->_pathNodeIndex >= this->path->nodes->length))){
								HX_STACK_LINE(643)
								this->_pathNodeIndex = (this->path->nodes->length - (int)2);
								HX_STACK_LINE(644)
								if (((this->_pathNodeIndex < (int)0))){
									HX_STACK_LINE(645)
									this->_pathNodeIndex = (int)0;
								}
								HX_STACK_LINE(648)
								this->_pathInc = -(this->_pathInc);
							}
						}
						else{
							HX_STACK_LINE(651)
							if (((this->_pathNodeIndex < (int)0))){
								HX_STACK_LINE(653)
								this->_pathNodeIndex = (int)1;
								HX_STACK_LINE(654)
								if (((this->_pathNodeIndex >= this->path->nodes->length))){
									HX_STACK_LINE(655)
									this->_pathNodeIndex = (this->path->nodes->length - (int)1);
								}
								HX_STACK_LINE(658)
								if (((this->_pathNodeIndex < (int)0))){
									HX_STACK_LINE(659)
									this->_pathNodeIndex = (int)0;
								}
								HX_STACK_LINE(662)
								this->_pathInc = -(this->_pathInc);
							}
						}
					}
					else{
						HX_STACK_LINE(666)
						if (((this->_pathNodeIndex >= this->path->nodes->length))){
							HX_STACK_LINE(669)
							this->_pathNodeIndex = (this->path->nodes->length - (int)1);
							HX_STACK_LINE(670)
							this->stopFollowingPath(false);
						}
					}
				}
			}
		}
		HX_STACK_LINE(674)
		return this->path->nodes->__get(this->_pathNodeIndex);
	}
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,advancePath,return )

Void FlxObject_obj::stopFollowingPath( hx::Null< bool >  __o_DestroyPath){
bool DestroyPath = __o_DestroyPath.Default(false);
	HX_STACK_PUSH("FlxObject::stopFollowingPath","org/flixel/FlxObject.hx",575);
	HX_STACK_THIS(this);
	HX_STACK_ARG(DestroyPath,"DestroyPath");
{
		HX_STACK_LINE(576)
		this->pathSpeed = (int)0;
		HX_STACK_LINE(577)
		this->velocity->x = (int)0;
		HX_STACK_LINE(578)
		this->velocity->y = (int)0;
		HX_STACK_LINE(580)
		if (((bool(DestroyPath) && bool((this->path != null()))))){
			HX_STACK_LINE(582)
			this->path->destroy();
			HX_STACK_LINE(583)
			this->path = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,stopFollowingPath,(void))

Void FlxObject_obj::followPath( ::org::flixel::FlxPath Path,hx::Null< Float >  __o_Speed,hx::Null< int >  __o_Mode,hx::Null< bool >  __o_AutoRotate){
Float Speed = __o_Speed.Default(100);
int Mode = __o_Mode.Default(0);
bool AutoRotate = __o_AutoRotate.Default(false);
	HX_STACK_PUSH("FlxObject::followPath","org/flixel/FlxObject.hx",545);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Path,"Path");
	HX_STACK_ARG(Speed,"Speed");
	HX_STACK_ARG(Mode,"Mode");
	HX_STACK_ARG(AutoRotate,"AutoRotate");
{
		HX_STACK_LINE(546)
		if (((Path->nodes->length <= (int)0))){
			HX_STACK_LINE(548)
			if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
				struct _Function_3_1{
					inline static ::String Block( ){
						HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",548);
						{
							HX_STACK_LINE(548)
							Dynamic AnyArray = hx::TCastToArray(HX_CSTRING("WARNING: Paths need at least one node in them to be followed."));		HX_STACK_VAR(AnyArray,"AnyArray");
							HX_STACK_LINE(548)
							::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
							HX_STACK_LINE(548)
							if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
								HX_STACK_LINE(548)
								string = ::Std_obj::string(AnyArray->__GetItem((int)0));
								HX_STACK_LINE(548)
								int i = (int)1;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(548)
								int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
								HX_STACK_LINE(548)
								while(((i < l))){
									HX_STACK_LINE(548)
									hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
								}
							}
							HX_STACK_LINE(548)
							return string;
						}
						return null();
					}
				};
				HX_STACK_LINE(548)
				::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  ((::Std_obj::is(HX_CSTRING("WARNING: Paths need at least one node in them to be followed."),hx::ClassOf< Array<int> >()))) ? ::String(_Function_3_1::Block()) : ::String(::Std_obj::string(HX_CSTRING("WARNING: Paths need at least one node in them to be followed."))) ));
			}
			HX_STACK_LINE(549)
			return null();
		}
		HX_STACK_LINE(552)
		this->path = Path;
		HX_STACK_LINE(553)
		this->pathSpeed = (  (((Speed > (int)0))) ? Float(Speed) : Float(-(Speed)) );
		HX_STACK_LINE(554)
		this->_pathMode = Mode;
		HX_STACK_LINE(555)
		this->_pathRotate = AutoRotate;
		HX_STACK_LINE(558)
		if (((bool((this->_pathMode == (int)1)) || bool((this->_pathMode == (int)256))))){
			HX_STACK_LINE(560)
			this->_pathNodeIndex = (this->path->nodes->length - (int)1);
			HX_STACK_LINE(561)
			this->_pathInc = (int)-1;
		}
		else{
			HX_STACK_LINE(565)
			this->_pathNodeIndex = (int)0;
			HX_STACK_LINE(566)
			this->_pathInc = (int)1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxObject_obj,followPath,(void))

Void FlxObject_obj::drawDebug( ::org::flixel::FlxCamera Camera){
{
		HX_STACK_PUSH("FlxObject::drawDebug","org/flixel/FlxObject.hx",465);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Camera,"Camera");
		HX_STACK_LINE(466)
		if (((Camera == null()))){
			HX_STACK_LINE(467)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(472)
		Float boundingBoxX = (this->x - (Camera->scroll->x * this->scrollFactor->x));		HX_STACK_VAR(boundingBoxX,"boundingBoxX");
		HX_STACK_LINE(473)
		Float boundingBoxY = (this->y - (Camera->scroll->y * this->scrollFactor->y));		HX_STACK_VAR(boundingBoxY,"boundingBoxY");
		HX_STACK_LINE(479)
		if (((bool((this->allowCollisions != (int)0)) && bool(!(this->_boundingBoxColorOverritten))))){
			HX_STACK_LINE(481)
			if (((this->allowCollisions != (int)4369))){
				HX_STACK_LINE(482)
				this->onBoundingBoxColorSet((int)-1040641);
			}
			HX_STACK_LINE(489)
			if ((this->immovable)){
				HX_STACK_LINE(490)
				this->onBoundingBoxColorSet((int)-16715227);
			}
			else{
				HX_STACK_LINE(498)
				this->onBoundingBoxColorSet((int)-65518);
			}
		}
		else{
			HX_STACK_LINE(506)
			if ((!(this->_boundingBoxColorOverritten))){
				HX_STACK_LINE(507)
				this->onBoundingBoxColorSet((int)-16740119);
			}
		}
		HX_STACK_LINE(528)
		::native::display::Graphics gfx = Camera->_effectsLayer->get_graphics();		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(529)
		gfx->lineStyle((int)1,this->debugBoundingBoxColor,0.5,null(),null(),null(),null(),null());
		HX_STACK_LINE(530)
		gfx->drawRect(boundingBoxX,boundingBoxY,this->width,this->height);
	}
return null();
}


Void FlxObject_obj::draw( ){
{
		HX_STACK_PUSH("FlxObject::draw","org/flixel/FlxObject.hx",430);
		HX_STACK_THIS(this);
		HX_STACK_LINE(431)
		if (((this->cameras == null()))){
			HX_STACK_LINE(432)
			this->cameras = ::org::flixel::FlxG_obj::cameras;
		}
		HX_STACK_LINE(435)
		::org::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(436)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(437)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(438)
		while(((i < l))){
			HX_STACK_LINE(440)
			camera = this->cameras->__get((i)++);
			struct _Function_2_1{
				inline static bool Block( ::org::flixel::FlxCamera &camera,::org::flixel::FlxObject_obj *__this){
					HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",441);
					{
						HX_STACK_LINE(441)
						::org::flixel::FlxCamera Camera = camera;		HX_STACK_VAR(Camera,"Camera");
						HX_STACK_LINE(441)
						if (((Camera == null()))){
							HX_STACK_LINE(441)
							Camera = ::org::flixel::FlxG_obj::camera;
						}
						HX_STACK_LINE(441)
						{
							HX_STACK_LINE(441)
							::org::flixel::FlxPoint point = __this->_point;		HX_STACK_VAR(point,"point");
							::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
							HX_STACK_LINE(441)
							if (((point == null()))){
								HX_STACK_LINE(441)
								point = ::org::flixel::FlxPoint_obj::__new(null(),null());
							}
							HX_STACK_LINE(441)
							if (((Camera1 == null()))){
								HX_STACK_LINE(441)
								Camera1 = ::org::flixel::FlxG_obj::camera;
							}
							HX_STACK_LINE(441)
							point->x = (__this->x - (Camera1->scroll->x * __this->scrollFactor->x));
							HX_STACK_LINE(441)
							point->y = (__this->y - (Camera1->scroll->y * __this->scrollFactor->y));
							HX_STACK_LINE(441)
							point;
						}
						HX_STACK_LINE(441)
						return (bool((bool((bool(((__this->_point->x + __this->width) > (int)0)) && bool((__this->_point->x < Camera->width)))) && bool(((__this->_point->y + __this->height) > (int)0)))) && bool((__this->_point->y < Camera->height)));
					}
					return null();
				}
			};
			HX_STACK_LINE(441)
			if (((bool((bool(!(_Function_2_1::Block(camera,this))) || bool(!(camera->visible)))) || bool(!(camera->exists))))){
				HX_STACK_LINE(442)
				continue;
			}
			HX_STACK_LINE(445)
			(::org::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
			HX_STACK_LINE(448)
			if (((bool(::org::flixel::FlxG_obj::visualDebug) && bool(!(this->ignoreDrawDebug))))){
				HX_STACK_LINE(449)
				this->drawDebug(camera);
			}
		}
	}
return null();
}


Void FlxObject_obj::updateMotion( ){
{
		HX_STACK_PUSH("FlxObject::updateMotion","org/flixel/FlxObject.hx",402);
		HX_STACK_THIS(this);
		HX_STACK_LINE(403)
		Float delta;		HX_STACK_VAR(delta,"delta");
		HX_STACK_LINE(404)
		Float velocityDelta;		HX_STACK_VAR(velocityDelta,"velocityDelta");
		HX_STACK_LINE(406)
		Float dt = ::org::flixel::FlxG_obj::elapsed;		HX_STACK_VAR(dt,"dt");
		struct _Function_1_1{
			inline static Float Block( ::org::flixel::FlxObject_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",408);
				{
					HX_STACK_LINE(408)
					Float Velocity = __this->angularVelocity;		HX_STACK_VAR(Velocity,"Velocity");
					Float Acceleration = __this->angularAcceleration;		HX_STACK_VAR(Acceleration,"Acceleration");
					Float Drag = __this->angularDrag;		HX_STACK_VAR(Drag,"Drag");
					Float Max = __this->maxAngular;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(408)
					if (((Acceleration != (int)0))){
						HX_STACK_LINE(408)
						hx::AddEq(Velocity,(Acceleration * ::org::flixel::FlxG_obj::elapsed));
					}
					else{
						HX_STACK_LINE(408)
						if (((Drag != (int)0))){
							HX_STACK_LINE(408)
							Float drag = (Drag * ::org::flixel::FlxG_obj::elapsed);		HX_STACK_VAR(drag,"drag");
							HX_STACK_LINE(408)
							if ((((Velocity - drag) > (int)0))){
								HX_STACK_LINE(408)
								Velocity = (Velocity - drag);
							}
							else{
								HX_STACK_LINE(408)
								if ((((Velocity + drag) < (int)0))){
									HX_STACK_LINE(408)
									hx::AddEq(Velocity,drag);
								}
								else{
									HX_STACK_LINE(408)
									Velocity = (int)0;
								}
							}
						}
					}
					HX_STACK_LINE(408)
					if (((bool((Velocity != (int)0)) && bool((Max != (int)0))))){
						HX_STACK_LINE(408)
						if (((Velocity > Max))){
							HX_STACK_LINE(408)
							Velocity = Max;
						}
						else{
							HX_STACK_LINE(408)
							if (((Velocity < -(Max)))){
								HX_STACK_LINE(408)
								Velocity = -(Max);
							}
						}
					}
					HX_STACK_LINE(408)
					return Velocity;
				}
				return null();
			}
		};
		HX_STACK_LINE(408)
		velocityDelta = (0.5 * ((_Function_1_1::Block(this) - this->angularVelocity)));
		HX_STACK_LINE(409)
		hx::AddEq(this->angularVelocity,velocityDelta);
		HX_STACK_LINE(410)
		hx::AddEq(this->angle,(this->angularVelocity * dt));
		HX_STACK_LINE(411)
		hx::AddEq(this->angularVelocity,velocityDelta);
		struct _Function_1_2{
			inline static Float Block( ::org::flixel::FlxObject_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",413);
				{
					HX_STACK_LINE(413)
					Float Velocity = __this->velocity->x;		HX_STACK_VAR(Velocity,"Velocity");
					Float Acceleration = __this->acceleration->x;		HX_STACK_VAR(Acceleration,"Acceleration");
					Float Drag = __this->drag->x;		HX_STACK_VAR(Drag,"Drag");
					Float Max = __this->maxVelocity->x;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(413)
					if (((Acceleration != (int)0))){
						HX_STACK_LINE(413)
						hx::AddEq(Velocity,(Acceleration * ::org::flixel::FlxG_obj::elapsed));
					}
					else{
						HX_STACK_LINE(413)
						if (((Drag != (int)0))){
							HX_STACK_LINE(413)
							Float drag = (Drag * ::org::flixel::FlxG_obj::elapsed);		HX_STACK_VAR(drag,"drag");
							HX_STACK_LINE(413)
							if ((((Velocity - drag) > (int)0))){
								HX_STACK_LINE(413)
								Velocity = (Velocity - drag);
							}
							else{
								HX_STACK_LINE(413)
								if ((((Velocity + drag) < (int)0))){
									HX_STACK_LINE(413)
									hx::AddEq(Velocity,drag);
								}
								else{
									HX_STACK_LINE(413)
									Velocity = (int)0;
								}
							}
						}
					}
					HX_STACK_LINE(413)
					if (((bool((Velocity != (int)0)) && bool((Max != (int)0))))){
						HX_STACK_LINE(413)
						if (((Velocity > Max))){
							HX_STACK_LINE(413)
							Velocity = Max;
						}
						else{
							HX_STACK_LINE(413)
							if (((Velocity < -(Max)))){
								HX_STACK_LINE(413)
								Velocity = -(Max);
							}
						}
					}
					HX_STACK_LINE(413)
					return Velocity;
				}
				return null();
			}
		};
		HX_STACK_LINE(413)
		velocityDelta = (0.5 * ((_Function_1_2::Block(this) - this->velocity->x)));
		HX_STACK_LINE(414)
		hx::AddEq(this->velocity->x,velocityDelta);
		HX_STACK_LINE(415)
		delta = (this->velocity->x * dt);
		HX_STACK_LINE(416)
		hx::AddEq(this->velocity->x,velocityDelta);
		HX_STACK_LINE(417)
		hx::AddEq(this->x,delta);
		struct _Function_1_3{
			inline static Float Block( ::org::flixel::FlxObject_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",419);
				{
					HX_STACK_LINE(419)
					Float Velocity = __this->velocity->y;		HX_STACK_VAR(Velocity,"Velocity");
					Float Acceleration = __this->acceleration->y;		HX_STACK_VAR(Acceleration,"Acceleration");
					Float Drag = __this->drag->y;		HX_STACK_VAR(Drag,"Drag");
					Float Max = __this->maxVelocity->y;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(419)
					if (((Acceleration != (int)0))){
						HX_STACK_LINE(419)
						hx::AddEq(Velocity,(Acceleration * ::org::flixel::FlxG_obj::elapsed));
					}
					else{
						HX_STACK_LINE(419)
						if (((Drag != (int)0))){
							HX_STACK_LINE(419)
							Float drag = (Drag * ::org::flixel::FlxG_obj::elapsed);		HX_STACK_VAR(drag,"drag");
							HX_STACK_LINE(419)
							if ((((Velocity - drag) > (int)0))){
								HX_STACK_LINE(419)
								Velocity = (Velocity - drag);
							}
							else{
								HX_STACK_LINE(419)
								if ((((Velocity + drag) < (int)0))){
									HX_STACK_LINE(419)
									hx::AddEq(Velocity,drag);
								}
								else{
									HX_STACK_LINE(419)
									Velocity = (int)0;
								}
							}
						}
					}
					HX_STACK_LINE(419)
					if (((bool((Velocity != (int)0)) && bool((Max != (int)0))))){
						HX_STACK_LINE(419)
						if (((Velocity > Max))){
							HX_STACK_LINE(419)
							Velocity = Max;
						}
						else{
							HX_STACK_LINE(419)
							if (((Velocity < -(Max)))){
								HX_STACK_LINE(419)
								Velocity = -(Max);
							}
						}
					}
					HX_STACK_LINE(419)
					return Velocity;
				}
				return null();
			}
		};
		HX_STACK_LINE(419)
		velocityDelta = (0.5 * ((_Function_1_3::Block(this) - this->velocity->y)));
		HX_STACK_LINE(420)
		hx::AddEq(this->velocity->y,velocityDelta);
		HX_STACK_LINE(421)
		delta = (this->velocity->y * dt);
		HX_STACK_LINE(422)
		hx::AddEq(this->velocity->y,velocityDelta);
		HX_STACK_LINE(423)
		hx::AddEq(this->y,delta);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,updateMotion,(void))

Void FlxObject_obj::postUpdate( ){
{
		HX_STACK_PUSH("FlxObject::postUpdate","org/flixel/FlxObject.hx",386);
		HX_STACK_THIS(this);
		HX_STACK_LINE(387)
		if ((this->moves)){
			HX_STACK_LINE(389)
			Float delta;		HX_STACK_VAR(delta,"delta");
			HX_STACK_LINE(389)
			Float velocityDelta;		HX_STACK_VAR(velocityDelta,"velocityDelta");
			HX_STACK_LINE(389)
			Float dt = ::org::flixel::FlxG_obj::elapsed;		HX_STACK_VAR(dt,"dt");
			struct _Function_2_1{
				inline static Float Block( ::org::flixel::FlxObject_obj *__this){
					HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",389);
					{
						HX_STACK_LINE(389)
						Float Velocity = __this->angularVelocity;		HX_STACK_VAR(Velocity,"Velocity");
						Float Acceleration = __this->angularAcceleration;		HX_STACK_VAR(Acceleration,"Acceleration");
						Float Drag = __this->angularDrag;		HX_STACK_VAR(Drag,"Drag");
						Float Max = __this->maxAngular;		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(389)
						if (((Acceleration != (int)0))){
							HX_STACK_LINE(389)
							hx::AddEq(Velocity,(Acceleration * ::org::flixel::FlxG_obj::elapsed));
						}
						else{
							HX_STACK_LINE(389)
							if (((Drag != (int)0))){
								HX_STACK_LINE(389)
								Float drag = (Drag * ::org::flixel::FlxG_obj::elapsed);		HX_STACK_VAR(drag,"drag");
								HX_STACK_LINE(389)
								if ((((Velocity - drag) > (int)0))){
									HX_STACK_LINE(389)
									Velocity = (Velocity - drag);
								}
								else{
									HX_STACK_LINE(389)
									if ((((Velocity + drag) < (int)0))){
										HX_STACK_LINE(389)
										hx::AddEq(Velocity,drag);
									}
									else{
										HX_STACK_LINE(389)
										Velocity = (int)0;
									}
								}
							}
						}
						HX_STACK_LINE(389)
						if (((bool((Velocity != (int)0)) && bool((Max != (int)0))))){
							HX_STACK_LINE(389)
							if (((Velocity > Max))){
								HX_STACK_LINE(389)
								Velocity = Max;
							}
							else{
								HX_STACK_LINE(389)
								if (((Velocity < -(Max)))){
									HX_STACK_LINE(389)
									Velocity = -(Max);
								}
							}
						}
						HX_STACK_LINE(389)
						return Velocity;
					}
					return null();
				}
			};
			HX_STACK_LINE(389)
			velocityDelta = (0.5 * ((_Function_2_1::Block(this) - this->angularVelocity)));
			HX_STACK_LINE(389)
			hx::AddEq(this->angularVelocity,velocityDelta);
			HX_STACK_LINE(389)
			hx::AddEq(this->angle,(this->angularVelocity * dt));
			HX_STACK_LINE(389)
			hx::AddEq(this->angularVelocity,velocityDelta);
			struct _Function_2_2{
				inline static Float Block( ::org::flixel::FlxObject_obj *__this){
					HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",389);
					{
						HX_STACK_LINE(389)
						Float Velocity = __this->velocity->x;		HX_STACK_VAR(Velocity,"Velocity");
						Float Acceleration = __this->acceleration->x;		HX_STACK_VAR(Acceleration,"Acceleration");
						Float Drag = __this->drag->x;		HX_STACK_VAR(Drag,"Drag");
						Float Max = __this->maxVelocity->x;		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(389)
						if (((Acceleration != (int)0))){
							HX_STACK_LINE(389)
							hx::AddEq(Velocity,(Acceleration * ::org::flixel::FlxG_obj::elapsed));
						}
						else{
							HX_STACK_LINE(389)
							if (((Drag != (int)0))){
								HX_STACK_LINE(389)
								Float drag = (Drag * ::org::flixel::FlxG_obj::elapsed);		HX_STACK_VAR(drag,"drag");
								HX_STACK_LINE(389)
								if ((((Velocity - drag) > (int)0))){
									HX_STACK_LINE(389)
									Velocity = (Velocity - drag);
								}
								else{
									HX_STACK_LINE(389)
									if ((((Velocity + drag) < (int)0))){
										HX_STACK_LINE(389)
										hx::AddEq(Velocity,drag);
									}
									else{
										HX_STACK_LINE(389)
										Velocity = (int)0;
									}
								}
							}
						}
						HX_STACK_LINE(389)
						if (((bool((Velocity != (int)0)) && bool((Max != (int)0))))){
							HX_STACK_LINE(389)
							if (((Velocity > Max))){
								HX_STACK_LINE(389)
								Velocity = Max;
							}
							else{
								HX_STACK_LINE(389)
								if (((Velocity < -(Max)))){
									HX_STACK_LINE(389)
									Velocity = -(Max);
								}
							}
						}
						HX_STACK_LINE(389)
						return Velocity;
					}
					return null();
				}
			};
			HX_STACK_LINE(389)
			velocityDelta = (0.5 * ((_Function_2_2::Block(this) - this->velocity->x)));
			HX_STACK_LINE(389)
			hx::AddEq(this->velocity->x,velocityDelta);
			HX_STACK_LINE(389)
			delta = (this->velocity->x * dt);
			HX_STACK_LINE(389)
			hx::AddEq(this->velocity->x,velocityDelta);
			HX_STACK_LINE(389)
			hx::AddEq(this->x,delta);
			struct _Function_2_3{
				inline static Float Block( ::org::flixel::FlxObject_obj *__this){
					HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",389);
					{
						HX_STACK_LINE(389)
						Float Velocity = __this->velocity->y;		HX_STACK_VAR(Velocity,"Velocity");
						Float Acceleration = __this->acceleration->y;		HX_STACK_VAR(Acceleration,"Acceleration");
						Float Drag = __this->drag->y;		HX_STACK_VAR(Drag,"Drag");
						Float Max = __this->maxVelocity->y;		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(389)
						if (((Acceleration != (int)0))){
							HX_STACK_LINE(389)
							hx::AddEq(Velocity,(Acceleration * ::org::flixel::FlxG_obj::elapsed));
						}
						else{
							HX_STACK_LINE(389)
							if (((Drag != (int)0))){
								HX_STACK_LINE(389)
								Float drag = (Drag * ::org::flixel::FlxG_obj::elapsed);		HX_STACK_VAR(drag,"drag");
								HX_STACK_LINE(389)
								if ((((Velocity - drag) > (int)0))){
									HX_STACK_LINE(389)
									Velocity = (Velocity - drag);
								}
								else{
									HX_STACK_LINE(389)
									if ((((Velocity + drag) < (int)0))){
										HX_STACK_LINE(389)
										hx::AddEq(Velocity,drag);
									}
									else{
										HX_STACK_LINE(389)
										Velocity = (int)0;
									}
								}
							}
						}
						HX_STACK_LINE(389)
						if (((bool((Velocity != (int)0)) && bool((Max != (int)0))))){
							HX_STACK_LINE(389)
							if (((Velocity > Max))){
								HX_STACK_LINE(389)
								Velocity = Max;
							}
							else{
								HX_STACK_LINE(389)
								if (((Velocity < -(Max)))){
									HX_STACK_LINE(389)
									Velocity = -(Max);
								}
							}
						}
						HX_STACK_LINE(389)
						return Velocity;
					}
					return null();
				}
			};
			HX_STACK_LINE(389)
			velocityDelta = (0.5 * ((_Function_2_3::Block(this) - this->velocity->y)));
			HX_STACK_LINE(389)
			hx::AddEq(this->velocity->y,velocityDelta);
			HX_STACK_LINE(389)
			delta = (this->velocity->y * dt);
			HX_STACK_LINE(389)
			hx::AddEq(this->velocity->y,velocityDelta);
			HX_STACK_LINE(389)
			hx::AddEq(this->y,delta);
		}
		HX_STACK_LINE(392)
		this->wasTouching = this->touching;
		HX_STACK_LINE(393)
		this->touching = (int)0;
	}
return null();
}


Void FlxObject_obj::preUpdate( ){
{
		HX_STACK_PUSH("FlxObject::preUpdate","org/flixel/FlxObject.hx",358);
		HX_STACK_THIS(this);
		HX_STACK_LINE(359)
		(::org::flixel::FlxBasic_obj::_ACTIVECOUNT)++;
		HX_STACK_LINE(361)
		if (((this->_flickerTimer > (int)0))){
			HX_STACK_LINE(363)
			hx::SubEq(this->_flickerTimer,::org::flixel::FlxG_obj::elapsed);
			HX_STACK_LINE(364)
			if (((this->_flickerTimer <= (int)0))){
				HX_STACK_LINE(366)
				this->_flickerTimer = (int)0;
				HX_STACK_LINE(367)
				this->_flicker = false;
			}
		}
		HX_STACK_LINE(371)
		this->last->x = this->x;
		HX_STACK_LINE(372)
		this->last->y = this->y;
		HX_STACK_LINE(374)
		if (((bool((bool((this->path != null())) && bool((this->pathSpeed != (int)0)))) && bool((this->path->nodes->__get(this->_pathNodeIndex) != null()))))){
			HX_STACK_LINE(376)
			this->_point->x = (this->x + (this->width * 0.5));
			HX_STACK_LINE(376)
			this->_point->y = (this->y + (this->height * 0.5));
			HX_STACK_LINE(376)
			::org::flixel::FlxPoint node = this->path->nodes->__get(this->_pathNodeIndex);		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(376)
			Float deltaX = (node->x - this->_point->x);		HX_STACK_VAR(deltaX,"deltaX");
			HX_STACK_LINE(376)
			Float deltaY = (node->y - this->_point->y);		HX_STACK_VAR(deltaY,"deltaY");
			HX_STACK_LINE(376)
			bool horizontalOnly = (((int(this->_pathMode) & int((int)65536))) > (int)0);		HX_STACK_VAR(horizontalOnly,"horizontalOnly");
			HX_STACK_LINE(376)
			bool verticalOnly = (((int(this->_pathMode) & int((int)1048576))) > (int)0);		HX_STACK_VAR(verticalOnly,"verticalOnly");
			HX_STACK_LINE(376)
			if ((horizontalOnly)){
				HX_STACK_LINE(376)
				if (((((  (((deltaX > (int)0))) ? Float(deltaX) : Float(-(deltaX)) )) < (this->pathSpeed * ::org::flixel::FlxG_obj::elapsed)))){
					HX_STACK_LINE(376)
					node = this->advancePath(null());
				}
			}
			else{
				HX_STACK_LINE(376)
				if ((verticalOnly)){
					HX_STACK_LINE(376)
					if (((((  (((deltaY > (int)0))) ? Float(deltaY) : Float(-(deltaY)) )) < (this->pathSpeed * ::org::flixel::FlxG_obj::elapsed)))){
						HX_STACK_LINE(376)
						node = this->advancePath(null());
					}
				}
				else{
					HX_STACK_LINE(376)
					if (((::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY))) < (this->pathSpeed * ::org::flixel::FlxG_obj::elapsed)))){
						HX_STACK_LINE(376)
						node = this->advancePath(null());
					}
				}
			}
			HX_STACK_LINE(376)
			if (((this->pathSpeed != (int)0))){
				HX_STACK_LINE(376)
				this->_point->x = (this->x + (this->width * 0.5));
				HX_STACK_LINE(376)
				this->_point->y = (this->y + (this->height * 0.5));
				HX_STACK_LINE(376)
				if (((bool(horizontalOnly) || bool((this->_point->y == node->y))))){
					HX_STACK_LINE(376)
					this->velocity->x = (  (((this->_point->x < node->x))) ? Float(this->pathSpeed) : Float(-(this->pathSpeed)) );
					HX_STACK_LINE(376)
					if (((this->velocity->x < (int)0))){
						HX_STACK_LINE(376)
						this->pathAngle = (int)-90;
					}
					else{
						HX_STACK_LINE(376)
						this->pathAngle = (int)90;
					}
					HX_STACK_LINE(376)
					if ((!(horizontalOnly))){
						HX_STACK_LINE(376)
						this->velocity->y = (int)0;
					}
				}
				else{
					HX_STACK_LINE(376)
					if (((bool(verticalOnly) || bool((this->_point->x == node->x))))){
						HX_STACK_LINE(376)
						this->velocity->y = (  (((this->_point->y < node->y))) ? Float(this->pathSpeed) : Float(-(this->pathSpeed)) );
						HX_STACK_LINE(376)
						if (((this->velocity->y < (int)0))){
							HX_STACK_LINE(376)
							this->pathAngle = (int)0;
						}
						else{
							HX_STACK_LINE(376)
							this->pathAngle = (int)180;
						}
						HX_STACK_LINE(376)
						if ((!(verticalOnly))){
							HX_STACK_LINE(376)
							this->velocity->x = (int)0;
						}
					}
					else{
						struct _Function_5_1{
							inline static Float Block( ::org::flixel::FlxObject_obj *__this,::org::flixel::FlxPoint &node){
								HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",376);
								{
									HX_STACK_LINE(376)
									::org::flixel::FlxPoint Point1 = __this->_point;		HX_STACK_VAR(Point1,"Point1");
									HX_STACK_LINE(376)
									Float x = (node->x - Point1->x);		HX_STACK_VAR(x,"x");
									HX_STACK_LINE(376)
									Float y = (node->y - Point1->y);		HX_STACK_VAR(y,"y");
									HX_STACK_LINE(376)
									Float angle = (int)0;		HX_STACK_VAR(angle,"angle");
									HX_STACK_LINE(376)
									if (((bool((x != (int)0)) || bool((y != (int)0))))){
										HX_STACK_LINE(376)
										Float c1 = 0.7853981625;		HX_STACK_VAR(c1,"c1");
										HX_STACK_LINE(376)
										Float c2 = ((int)3 * c1);		HX_STACK_VAR(c2,"c2");
										HX_STACK_LINE(376)
										Float ay = (  (((y < (int)0))) ? Float(-(y)) : Float(y) );		HX_STACK_VAR(ay,"ay");
										HX_STACK_LINE(376)
										if (((x >= (int)0))){
											HX_STACK_LINE(376)
											angle = (c1 - (c1 * ((Float(((x - ay))) / Float(((x + ay)))))));
										}
										else{
											HX_STACK_LINE(376)
											angle = (c2 - (c1 * ((Float(((x + ay))) / Float(((ay - x)))))));
										}
										HX_STACK_LINE(376)
										angle = (((  (((y < (int)0))) ? Float(-(angle)) : Float(angle) )) * 57.2957796);
										HX_STACK_LINE(376)
										if (((angle > (int)90))){
											HX_STACK_LINE(376)
											angle = (angle - (int)270);
										}
										else{
											HX_STACK_LINE(376)
											hx::AddEq(angle,(int)90);
										}
									}
									HX_STACK_LINE(376)
									return angle;
								}
								return null();
							}
						};
						HX_STACK_LINE(376)
						this->pathAngle = _Function_5_1::Block(this,node);
						HX_STACK_LINE(376)
						{
							HX_STACK_LINE(376)
							::org::flixel::FlxPoint point = this->velocity;		HX_STACK_VAR(point,"point");
							HX_STACK_LINE(376)
							Float sin = (int)0;		HX_STACK_VAR(sin,"sin");
							HX_STACK_LINE(376)
							Float cos = (int)0;		HX_STACK_VAR(cos,"cos");
							HX_STACK_LINE(376)
							Float radians = (this->pathAngle * -0.017453293);		HX_STACK_VAR(radians,"radians");
							HX_STACK_LINE(376)
							while(((radians < -3.14159265))){
								HX_STACK_LINE(376)
								hx::AddEq(radians,6.28318531);
							}
							HX_STACK_LINE(376)
							while(((radians > 3.14159265))){
								HX_STACK_LINE(376)
								radians = (radians - 6.28318531);
							}
							HX_STACK_LINE(376)
							if (((radians < (int)0))){
								HX_STACK_LINE(376)
								sin = ((1.27323954 * radians) + ((.405284735 * radians) * radians));
								HX_STACK_LINE(376)
								if (((sin < (int)0))){
									HX_STACK_LINE(376)
									sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
								}
								else{
									HX_STACK_LINE(376)
									sin = ((.225 * (((sin * sin) - sin))) + sin);
								}
							}
							else{
								HX_STACK_LINE(376)
								sin = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
								HX_STACK_LINE(376)
								if (((sin < (int)0))){
									HX_STACK_LINE(376)
									sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
								}
								else{
									HX_STACK_LINE(376)
									sin = ((.225 * (((sin * sin) - sin))) + sin);
								}
							}
							HX_STACK_LINE(376)
							hx::AddEq(radians,1.57079632);
							HX_STACK_LINE(376)
							if (((radians > 3.14159265))){
								HX_STACK_LINE(376)
								radians = (radians - 6.28318531);
							}
							HX_STACK_LINE(376)
							if (((radians < (int)0))){
								HX_STACK_LINE(376)
								cos = ((1.27323954 * radians) + ((0.405284735 * radians) * radians));
								HX_STACK_LINE(376)
								if (((cos < (int)0))){
									HX_STACK_LINE(376)
									cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
								}
								else{
									HX_STACK_LINE(376)
									cos = ((.225 * (((cos * cos) - cos))) + cos);
								}
							}
							else{
								HX_STACK_LINE(376)
								cos = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
								HX_STACK_LINE(376)
								if (((cos < (int)0))){
									HX_STACK_LINE(376)
									cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
								}
								else{
									HX_STACK_LINE(376)
									cos = ((.225 * (((cos * cos) - cos))) + cos);
								}
							}
							HX_STACK_LINE(376)
							Float dx = (int)0;		HX_STACK_VAR(dx,"dx");
							HX_STACK_LINE(376)
							Float dy = this->pathSpeed;		HX_STACK_VAR(dy,"dy");
							HX_STACK_LINE(376)
							if (((point == null()))){
								HX_STACK_LINE(376)
								point = ::org::flixel::FlxPoint_obj::__new(null(),null());
							}
							HX_STACK_LINE(376)
							point->x = ((cos * dx) - (sin * dy));
							HX_STACK_LINE(376)
							point->y = (((int)0 - (sin * dx)) - (cos * dy));
							HX_STACK_LINE(376)
							point;
						}
					}
				}
				HX_STACK_LINE(376)
				if ((this->_pathRotate)){
					HX_STACK_LINE(376)
					this->angularVelocity = (int)0;
					HX_STACK_LINE(376)
					this->angularAcceleration = (int)0;
					HX_STACK_LINE(376)
					this->angle = this->pathAngle;
				}
			}
		}
	}
return null();
}


Void FlxObject_obj::destroy( ){
{
		HX_STACK_PUSH("FlxObject::destroy","org/flixel/FlxObject.hx",333);
		HX_STACK_THIS(this);
		HX_STACK_LINE(334)
		this->velocity = null();
		HX_STACK_LINE(335)
		this->acceleration = null();
		HX_STACK_LINE(336)
		this->drag = null();
		HX_STACK_LINE(337)
		this->maxVelocity = null();
		HX_STACK_LINE(338)
		this->scrollFactor = null();
		HX_STACK_LINE(339)
		this->_point = null();
		HX_STACK_LINE(340)
		this->_rect = null();
		HX_STACK_LINE(341)
		this->last = null();
		HX_STACK_LINE(342)
		this->cameras = null();
		HX_STACK_LINE(343)
		if (((this->path != null()))){
			HX_STACK_LINE(344)
			this->path->destroy();
		}
		HX_STACK_LINE(347)
		this->path = null();
		HX_STACK_LINE(348)
		this->super::destroy();
	}
return null();
}


int FlxObject_obj::onBoundingBoxColorSet( int val){
	HX_STACK_PUSH("FlxObject::onBoundingBoxColorSet","org/flixel/FlxObject.hx",268);
	HX_STACK_THIS(this);
	HX_STACK_ARG(val,"val");
	HX_STACK_LINE(269)
	this->_boundingBoxColorOverritten = true;
	HX_STACK_LINE(270)
	this->debugBoundingBoxColor = val;
	HX_STACK_LINE(271)
	return val;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,onBoundingBoxColorSet,return )

Float FlxObject_obj::SEPARATE_BIAS;

int FlxObject_obj::LEFT;

int FlxObject_obj::RIGHT;

int FlxObject_obj::UP;

int FlxObject_obj::DOWN;

int FlxObject_obj::NONE;

int FlxObject_obj::CEILING;

int FlxObject_obj::FLOOR;

int FlxObject_obj::WALL;

int FlxObject_obj::ANY;

int FlxObject_obj::PATH_FORWARD;

int FlxObject_obj::PATH_BACKWARD;

int FlxObject_obj::PATH_LOOP_FORWARD;

int FlxObject_obj::PATH_LOOP_BACKWARD;

int FlxObject_obj::PATH_YOYO;

int FlxObject_obj::PATH_HORIZONTAL_ONLY;

int FlxObject_obj::PATH_VERTICAL_ONLY;

::org::flixel::FlxRect FlxObject_obj::_firstSeparateFlxRect;

::org::flixel::FlxRect FlxObject_obj::_secondSeparateFlxRect;

::org::flixel::FlxPoint FlxObject_obj::_pZero;

bool FlxObject_obj::separate( ::org::flixel::FlxObject Object1,::org::flixel::FlxObject Object2){
	HX_STACK_PUSH("FlxObject::separate","org/flixel/FlxObject.hx",1077);
	HX_STACK_ARG(Object1,"Object1");
	HX_STACK_ARG(Object2,"Object2");
	HX_STACK_LINE(1078)
	bool separatedX = ::org::flixel::FlxObject_obj::separateX(Object1,Object2);		HX_STACK_VAR(separatedX,"separatedX");
	HX_STACK_LINE(1079)
	bool separatedY = ::org::flixel::FlxObject_obj::separateY(Object1,Object2);		HX_STACK_VAR(separatedY,"separatedY");
	HX_STACK_LINE(1080)
	return (bool(separatedX) || bool(separatedY));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,separate,return )

bool FlxObject_obj::separateX( ::org::flixel::FlxObject Object1,::org::flixel::FlxObject Object2){
	HX_STACK_PUSH("FlxObject::separateX","org/flixel/FlxObject.hx",1090);
	HX_STACK_ARG(Object1,"Object1");
	HX_STACK_ARG(Object2,"Object2");
	HX_STACK_LINE(1092)
	bool obj1immovable = Object1->immovable;		HX_STACK_VAR(obj1immovable,"obj1immovable");
	HX_STACK_LINE(1093)
	bool obj2immovable = Object2->immovable;		HX_STACK_VAR(obj2immovable,"obj2immovable");
	HX_STACK_LINE(1094)
	if (((bool(obj1immovable) && bool(obj2immovable)))){
		HX_STACK_LINE(1095)
		return false;
	}
	HX_STACK_LINE(1100)
	if ((::Std_obj::is(Object1,hx::ClassOf< ::org::flixel::FlxTilemap >()))){
		HX_STACK_LINE(1101)
		return (hx::TCast< org::flixel::FlxTilemap >::cast(Object1))->overlapsWithCallback(Object2,::org::flixel::FlxObject_obj::separateX_dyn(),null(),null());
	}
	HX_STACK_LINE(1104)
	if ((::Std_obj::is(Object2,hx::ClassOf< ::org::flixel::FlxTilemap >()))){
		HX_STACK_LINE(1105)
		return (hx::TCast< org::flixel::FlxTilemap >::cast(Object2))->overlapsWithCallback(Object1,::org::flixel::FlxObject_obj::separateX_dyn(),true,null());
	}
	HX_STACK_LINE(1110)
	Float overlap = (int)0;		HX_STACK_VAR(overlap,"overlap");
	HX_STACK_LINE(1111)
	Float obj1delta = (Object1->x - Object1->last->x);		HX_STACK_VAR(obj1delta,"obj1delta");
	HX_STACK_LINE(1112)
	Float obj2delta = (Object2->x - Object2->last->x);		HX_STACK_VAR(obj2delta,"obj2delta");
	HX_STACK_LINE(1113)
	if (((obj1delta != obj2delta))){
		HX_STACK_LINE(1116)
		Float obj1deltaAbs = (  (((obj1delta > (int)0))) ? Float(obj1delta) : Float(-(obj1delta)) );		HX_STACK_VAR(obj1deltaAbs,"obj1deltaAbs");
		HX_STACK_LINE(1117)
		Float obj2deltaAbs = (  (((obj2delta > (int)0))) ? Float(obj2delta) : Float(-(obj2delta)) );		HX_STACK_VAR(obj2deltaAbs,"obj2deltaAbs");
		struct _Function_2_1{
			inline static ::org::flixel::FlxRect Block( ::org::flixel::FlxObject &Object1,Float &obj1delta){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",1119);
				{
					HX_STACK_LINE(1119)
					::org::flixel::FlxRect _this = ::org::flixel::FlxObject_obj::_firstSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1119)
					_this->x = (Object1->x - ((  (((obj1delta > (int)0))) ? Float(obj1delta) : Float((int)0) )));
					HX_STACK_LINE(1119)
					_this->y = Object1->last->y;
					HX_STACK_LINE(1119)
					_this->width = (Object1->width + ((  (((obj1delta > (int)0))) ? Float(obj1delta) : Float(-(obj1delta)) )));
					HX_STACK_LINE(1119)
					_this->height = Object1->height;
					HX_STACK_LINE(1119)
					return _this;
				}
				return null();
			}
		};
		HX_STACK_LINE(1119)
		::org::flixel::FlxRect obj1rect = _Function_2_1::Block(Object1,obj1delta);		HX_STACK_VAR(obj1rect,"obj1rect");
		struct _Function_2_2{
			inline static ::org::flixel::FlxRect Block( ::org::flixel::FlxObject &Object2,Float &obj2delta){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",1120);
				{
					HX_STACK_LINE(1120)
					::org::flixel::FlxRect _this = ::org::flixel::FlxObject_obj::_secondSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1120)
					_this->x = (Object2->x - ((  (((obj2delta > (int)0))) ? Float(obj2delta) : Float((int)0) )));
					HX_STACK_LINE(1120)
					_this->y = Object2->last->y;
					HX_STACK_LINE(1120)
					_this->width = (Object2->width + ((  (((obj2delta > (int)0))) ? Float(obj2delta) : Float(-(obj2delta)) )));
					HX_STACK_LINE(1120)
					_this->height = Object2->height;
					HX_STACK_LINE(1120)
					return _this;
				}
				return null();
			}
		};
		HX_STACK_LINE(1120)
		::org::flixel::FlxRect obj2rect = _Function_2_2::Block(Object2,obj2delta);		HX_STACK_VAR(obj2rect,"obj2rect");
		HX_STACK_LINE(1122)
		if (((bool((bool((bool(((obj1rect->x + obj1rect->width) > obj2rect->x)) && bool((obj1rect->x < (obj2rect->x + obj2rect->width))))) && bool(((obj1rect->y + obj1rect->height) > obj2rect->y)))) && bool((obj1rect->y < (obj2rect->y + obj2rect->height)))))){
			HX_STACK_LINE(1124)
			Float maxOverlap = ((obj1deltaAbs + obj2deltaAbs) + ::org::flixel::FlxObject_obj::SEPARATE_BIAS);		HX_STACK_VAR(maxOverlap,"maxOverlap");
			HX_STACK_LINE(1127)
			if (((obj1delta > obj2delta))){
				HX_STACK_LINE(1129)
				overlap = ((Object1->x + Object1->width) - Object2->x);
				HX_STACK_LINE(1130)
				if (((bool((bool((overlap > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)16))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)1))) == (int)0))))){
					HX_STACK_LINE(1131)
					overlap = (int)0;
				}
				else{
					HX_STACK_LINE(1136)
					hx::OrEq(Object1->touching,(int)16);
					HX_STACK_LINE(1137)
					hx::OrEq(Object2->touching,(int)1);
				}
			}
			else{
				HX_STACK_LINE(1140)
				if (((obj1delta < obj2delta))){
					HX_STACK_LINE(1142)
					overlap = ((Object1->x - Object2->width) - Object2->x);
					HX_STACK_LINE(1143)
					if (((bool((bool((-(overlap) > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)1))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)16))) == (int)0))))){
						HX_STACK_LINE(1144)
						overlap = (int)0;
					}
					else{
						HX_STACK_LINE(1149)
						hx::OrEq(Object1->touching,(int)1);
						HX_STACK_LINE(1150)
						hx::OrEq(Object2->touching,(int)16);
					}
				}
			}
		}
	}
	HX_STACK_LINE(1157)
	if (((overlap != (int)0))){
		HX_STACK_LINE(1159)
		Float obj1v = Object1->velocity->x;		HX_STACK_VAR(obj1v,"obj1v");
		HX_STACK_LINE(1160)
		Float obj2v = Object2->velocity->x;		HX_STACK_VAR(obj2v,"obj2v");
		HX_STACK_LINE(1162)
		if (((bool(!(obj1immovable)) && bool(!(obj2immovable))))){
			HX_STACK_LINE(1164)
			hx::MultEq(overlap,0.5);
			HX_STACK_LINE(1165)
			Object1->x = (Object1->x - overlap);
			HX_STACK_LINE(1166)
			hx::AddEq(Object2->x,overlap);
			HX_STACK_LINE(1168)
			Float obj1velocity = (::Math_obj::sqrt((Float(((obj2v * obj2v) * Object2->mass)) / Float(Object1->mass))) * ((  (((obj2v > (int)0))) ? int((int)1) : int((int)-1) )));		HX_STACK_VAR(obj1velocity,"obj1velocity");
			HX_STACK_LINE(1169)
			Float obj2velocity = (::Math_obj::sqrt((Float(((obj1v * obj1v) * Object1->mass)) / Float(Object2->mass))) * ((  (((obj1v > (int)0))) ? int((int)1) : int((int)-1) )));		HX_STACK_VAR(obj2velocity,"obj2velocity");
			HX_STACK_LINE(1170)
			Float average = (((obj1velocity + obj2velocity)) * 0.5);		HX_STACK_VAR(average,"average");
			HX_STACK_LINE(1171)
			hx::SubEq(obj1velocity,average);
			HX_STACK_LINE(1172)
			hx::SubEq(obj2velocity,average);
			HX_STACK_LINE(1173)
			Object1->velocity->x = (average + (obj1velocity * Object1->elasticity));
			HX_STACK_LINE(1174)
			Object2->velocity->x = (average + (obj2velocity * Object2->elasticity));
		}
		else{
			HX_STACK_LINE(1176)
			if ((!(obj1immovable))){
				HX_STACK_LINE(1178)
				Object1->x = (Object1->x - overlap);
				HX_STACK_LINE(1179)
				Object1->velocity->x = (obj2v - (obj1v * Object1->elasticity));
			}
			else{
				HX_STACK_LINE(1181)
				if ((!(obj2immovable))){
					HX_STACK_LINE(1183)
					hx::AddEq(Object2->x,overlap);
					HX_STACK_LINE(1184)
					Object2->velocity->x = (obj1v - (obj2v * Object2->elasticity));
				}
			}
		}
		HX_STACK_LINE(1186)
		return true;
	}
	else{
		HX_STACK_LINE(1189)
		return false;
	}
	HX_STACK_LINE(1157)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,separateX,return )

bool FlxObject_obj::separateY( ::org::flixel::FlxObject Object1,::org::flixel::FlxObject Object2){
	HX_STACK_PUSH("FlxObject::separateY","org/flixel/FlxObject.hx",1201);
	HX_STACK_ARG(Object1,"Object1");
	HX_STACK_ARG(Object2,"Object2");
	HX_STACK_LINE(1203)
	bool obj1immovable = Object1->immovable;		HX_STACK_VAR(obj1immovable,"obj1immovable");
	HX_STACK_LINE(1204)
	bool obj2immovable = Object2->immovable;		HX_STACK_VAR(obj2immovable,"obj2immovable");
	HX_STACK_LINE(1205)
	if (((bool(obj1immovable) && bool(obj2immovable)))){
		HX_STACK_LINE(1206)
		return false;
	}
	HX_STACK_LINE(1211)
	if ((::Std_obj::is(Object1,hx::ClassOf< ::org::flixel::FlxTilemap >()))){
		HX_STACK_LINE(1212)
		return (hx::TCast< org::flixel::FlxTilemap >::cast(Object1))->overlapsWithCallback(Object2,::org::flixel::FlxObject_obj::separateY_dyn(),null(),null());
	}
	HX_STACK_LINE(1215)
	if ((::Std_obj::is(Object2,hx::ClassOf< ::org::flixel::FlxTilemap >()))){
		HX_STACK_LINE(1216)
		return (hx::TCast< org::flixel::FlxTilemap >::cast(Object2))->overlapsWithCallback(Object1,::org::flixel::FlxObject_obj::separateY_dyn(),true,null());
	}
	HX_STACK_LINE(1221)
	Float overlap = (int)0;		HX_STACK_VAR(overlap,"overlap");
	HX_STACK_LINE(1222)
	Float obj1delta = (Object1->y - Object1->last->y);		HX_STACK_VAR(obj1delta,"obj1delta");
	HX_STACK_LINE(1223)
	Float obj2delta = (Object2->y - Object2->last->y);		HX_STACK_VAR(obj2delta,"obj2delta");
	HX_STACK_LINE(1224)
	if (((obj1delta != obj2delta))){
		HX_STACK_LINE(1227)
		Float obj1deltaAbs = (  (((obj1delta > (int)0))) ? Float(obj1delta) : Float(-(obj1delta)) );		HX_STACK_VAR(obj1deltaAbs,"obj1deltaAbs");
		HX_STACK_LINE(1228)
		Float obj2deltaAbs = (  (((obj2delta > (int)0))) ? Float(obj2delta) : Float(-(obj2delta)) );		HX_STACK_VAR(obj2deltaAbs,"obj2deltaAbs");
		struct _Function_2_1{
			inline static ::org::flixel::FlxRect Block( Float &obj1delta,::org::flixel::FlxObject &Object1,Float &obj1deltaAbs){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",1230);
				{
					HX_STACK_LINE(1230)
					::org::flixel::FlxRect _this = ::org::flixel::FlxObject_obj::_firstSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1230)
					_this->x = Object1->x;
					HX_STACK_LINE(1230)
					_this->y = (Object1->y - ((  (((obj1delta > (int)0))) ? Float(obj1delta) : Float((int)0) )));
					HX_STACK_LINE(1230)
					_this->width = Object1->width;
					HX_STACK_LINE(1230)
					_this->height = (Object1->height + obj1deltaAbs);
					HX_STACK_LINE(1230)
					return _this;
				}
				return null();
			}
		};
		HX_STACK_LINE(1230)
		::org::flixel::FlxRect obj1rect = _Function_2_1::Block(obj1delta,Object1,obj1deltaAbs);		HX_STACK_VAR(obj1rect,"obj1rect");
		struct _Function_2_2{
			inline static ::org::flixel::FlxRect Block( Float &obj2delta,::org::flixel::FlxObject &Object2,Float &obj2deltaAbs){
				HX_STACK_PUSH("*::closure","org/flixel/FlxObject.hx",1231);
				{
					HX_STACK_LINE(1231)
					::org::flixel::FlxRect _this = ::org::flixel::FlxObject_obj::_secondSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1231)
					_this->x = Object2->x;
					HX_STACK_LINE(1231)
					_this->y = (Object2->y - ((  (((obj2delta > (int)0))) ? Float(obj2delta) : Float((int)0) )));
					HX_STACK_LINE(1231)
					_this->width = Object2->width;
					HX_STACK_LINE(1231)
					_this->height = (Object2->height + obj2deltaAbs);
					HX_STACK_LINE(1231)
					return _this;
				}
				return null();
			}
		};
		HX_STACK_LINE(1231)
		::org::flixel::FlxRect obj2rect = _Function_2_2::Block(obj2delta,Object2,obj2deltaAbs);		HX_STACK_VAR(obj2rect,"obj2rect");
		HX_STACK_LINE(1233)
		if (((bool((bool((bool(((obj1rect->x + obj1rect->width) > obj2rect->x)) && bool((obj1rect->x < (obj2rect->x + obj2rect->width))))) && bool(((obj1rect->y + obj1rect->height) > obj2rect->y)))) && bool((obj1rect->y < (obj2rect->y + obj2rect->height)))))){
			HX_STACK_LINE(1235)
			Float maxOverlap = ((obj1deltaAbs + obj2deltaAbs) + ::org::flixel::FlxObject_obj::SEPARATE_BIAS);		HX_STACK_VAR(maxOverlap,"maxOverlap");
			HX_STACK_LINE(1238)
			if (((obj1delta > obj2delta))){
				HX_STACK_LINE(1240)
				overlap = ((Object1->y + Object1->height) - Object2->y);
				HX_STACK_LINE(1241)
				if (((bool((bool((overlap > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)4096))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)256))) == (int)0))))){
					HX_STACK_LINE(1242)
					overlap = (int)0;
				}
				else{
					HX_STACK_LINE(1247)
					hx::OrEq(Object1->touching,(int)4096);
					HX_STACK_LINE(1248)
					hx::OrEq(Object2->touching,(int)256);
				}
			}
			else{
				HX_STACK_LINE(1251)
				if (((obj1delta < obj2delta))){
					HX_STACK_LINE(1253)
					overlap = ((Object1->y - Object2->height) - Object2->y);
					HX_STACK_LINE(1254)
					if (((bool((bool((-(overlap) > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)256))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)4096))) == (int)0))))){
						HX_STACK_LINE(1255)
						overlap = (int)0;
					}
					else{
						HX_STACK_LINE(1260)
						hx::OrEq(Object1->touching,(int)256);
						HX_STACK_LINE(1261)
						hx::OrEq(Object2->touching,(int)4096);
					}
				}
			}
		}
	}
	HX_STACK_LINE(1268)
	if (((overlap != (int)0))){
		HX_STACK_LINE(1270)
		Float obj1v = Object1->velocity->y;		HX_STACK_VAR(obj1v,"obj1v");
		HX_STACK_LINE(1271)
		Float obj2v = Object2->velocity->y;		HX_STACK_VAR(obj2v,"obj2v");
		HX_STACK_LINE(1273)
		if (((bool(!(obj1immovable)) && bool(!(obj2immovable))))){
			HX_STACK_LINE(1275)
			hx::MultEq(overlap,0.5);
			HX_STACK_LINE(1276)
			Object1->y = (Object1->y - overlap);
			HX_STACK_LINE(1277)
			hx::AddEq(Object2->y,overlap);
			HX_STACK_LINE(1279)
			Float obj1velocity = (::Math_obj::sqrt((Float(((obj2v * obj2v) * Object2->mass)) / Float(Object1->mass))) * ((  (((obj2v > (int)0))) ? int((int)1) : int((int)-1) )));		HX_STACK_VAR(obj1velocity,"obj1velocity");
			HX_STACK_LINE(1280)
			Float obj2velocity = (::Math_obj::sqrt((Float(((obj1v * obj1v) * Object1->mass)) / Float(Object2->mass))) * ((  (((obj1v > (int)0))) ? int((int)1) : int((int)-1) )));		HX_STACK_VAR(obj2velocity,"obj2velocity");
			HX_STACK_LINE(1281)
			Float average = (((obj1velocity + obj2velocity)) * 0.5);		HX_STACK_VAR(average,"average");
			HX_STACK_LINE(1282)
			hx::SubEq(obj1velocity,average);
			HX_STACK_LINE(1283)
			hx::SubEq(obj2velocity,average);
			HX_STACK_LINE(1284)
			Object1->velocity->y = (average + (obj1velocity * Object1->elasticity));
			HX_STACK_LINE(1285)
			Object2->velocity->y = (average + (obj2velocity * Object2->elasticity));
		}
		else{
			HX_STACK_LINE(1287)
			if ((!(obj1immovable))){
				HX_STACK_LINE(1289)
				Object1->y = (Object1->y - overlap);
				HX_STACK_LINE(1290)
				Object1->velocity->y = (obj2v - (obj1v * Object1->elasticity));
				HX_STACK_LINE(1292)
				if (((bool((bool(Object2->active) && bool(Object2->moves))) && bool((obj1delta > obj2delta))))){
					HX_STACK_LINE(1293)
					hx::AddEq(Object1->x,(Object2->x - Object2->last->x));
				}
			}
			else{
				HX_STACK_LINE(1297)
				if ((!(obj2immovable))){
					HX_STACK_LINE(1299)
					hx::AddEq(Object2->y,overlap);
					HX_STACK_LINE(1300)
					Object2->velocity->y = (obj1v - (obj2v * Object2->elasticity));
					HX_STACK_LINE(1302)
					if (((bool((bool(Object1->active) && bool(Object1->moves))) && bool((obj1delta < obj2delta))))){
						HX_STACK_LINE(1303)
						hx::AddEq(Object2->x,(Object1->x - Object1->last->x));
					}
				}
			}
		}
		HX_STACK_LINE(1307)
		return true;
	}
	else{
		HX_STACK_LINE(1310)
		return false;
	}
	HX_STACK_LINE(1268)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,separateY,return )


FlxObject_obj::FlxObject_obj()
{
}

void FlxObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxObject);
	HX_MARK_MEMBER_NAME(solid,"solid");
	HX_MARK_MEMBER_NAME(flickering,"flickering");
	HX_MARK_MEMBER_NAME(_boundingBoxColorOverritten,"_boundingBoxColorOverritten");
	HX_MARK_MEMBER_NAME(debugBoundingBoxColor,"debugBoundingBoxColor");
	HX_MARK_MEMBER_NAME(_pathRotate,"_pathRotate");
	HX_MARK_MEMBER_NAME(_pathInc,"_pathInc");
	HX_MARK_MEMBER_NAME(_pathMode,"_pathMode");
	HX_MARK_MEMBER_NAME(_pathNodeIndex,"_pathNodeIndex");
	HX_MARK_MEMBER_NAME(pathAngle,"pathAngle");
	HX_MARK_MEMBER_NAME(pathSpeed,"pathSpeed");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_MEMBER_NAME(last,"last");
	HX_MARK_MEMBER_NAME(allowCollisions,"allowCollisions");
	HX_MARK_MEMBER_NAME(wasTouching,"wasTouching");
	HX_MARK_MEMBER_NAME(touching,"touching");
	HX_MARK_MEMBER_NAME(moves,"moves");
	HX_MARK_MEMBER_NAME(_rect,"_rect");
	HX_MARK_MEMBER_NAME(_point,"_point");
	HX_MARK_MEMBER_NAME(health,"health");
	HX_MARK_MEMBER_NAME(_flickerTimer,"_flickerTimer");
	HX_MARK_MEMBER_NAME(_flicker,"_flicker");
	HX_MARK_MEMBER_NAME(scrollFactor,"scrollFactor");
	HX_MARK_MEMBER_NAME(maxAngular,"maxAngular");
	HX_MARK_MEMBER_NAME(angularDrag,"angularDrag");
	HX_MARK_MEMBER_NAME(angularAcceleration,"angularAcceleration");
	HX_MARK_MEMBER_NAME(angularVelocity,"angularVelocity");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(maxVelocity,"maxVelocity");
	HX_MARK_MEMBER_NAME(drag,"drag");
	HX_MARK_MEMBER_NAME(acceleration,"acceleration");
	HX_MARK_MEMBER_NAME(elasticity,"elasticity");
	HX_MARK_MEMBER_NAME(mass,"mass");
	HX_MARK_MEMBER_NAME(velocity,"velocity");
	HX_MARK_MEMBER_NAME(immovable,"immovable");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(solid,"solid");
	HX_VISIT_MEMBER_NAME(flickering,"flickering");
	HX_VISIT_MEMBER_NAME(_boundingBoxColorOverritten,"_boundingBoxColorOverritten");
	HX_VISIT_MEMBER_NAME(debugBoundingBoxColor,"debugBoundingBoxColor");
	HX_VISIT_MEMBER_NAME(_pathRotate,"_pathRotate");
	HX_VISIT_MEMBER_NAME(_pathInc,"_pathInc");
	HX_VISIT_MEMBER_NAME(_pathMode,"_pathMode");
	HX_VISIT_MEMBER_NAME(_pathNodeIndex,"_pathNodeIndex");
	HX_VISIT_MEMBER_NAME(pathAngle,"pathAngle");
	HX_VISIT_MEMBER_NAME(pathSpeed,"pathSpeed");
	HX_VISIT_MEMBER_NAME(path,"path");
	HX_VISIT_MEMBER_NAME(last,"last");
	HX_VISIT_MEMBER_NAME(allowCollisions,"allowCollisions");
	HX_VISIT_MEMBER_NAME(wasTouching,"wasTouching");
	HX_VISIT_MEMBER_NAME(touching,"touching");
	HX_VISIT_MEMBER_NAME(moves,"moves");
	HX_VISIT_MEMBER_NAME(_rect,"_rect");
	HX_VISIT_MEMBER_NAME(_point,"_point");
	HX_VISIT_MEMBER_NAME(health,"health");
	HX_VISIT_MEMBER_NAME(_flickerTimer,"_flickerTimer");
	HX_VISIT_MEMBER_NAME(_flicker,"_flicker");
	HX_VISIT_MEMBER_NAME(scrollFactor,"scrollFactor");
	HX_VISIT_MEMBER_NAME(maxAngular,"maxAngular");
	HX_VISIT_MEMBER_NAME(angularDrag,"angularDrag");
	HX_VISIT_MEMBER_NAME(angularAcceleration,"angularAcceleration");
	HX_VISIT_MEMBER_NAME(angularVelocity,"angularVelocity");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(maxVelocity,"maxVelocity");
	HX_VISIT_MEMBER_NAME(drag,"drag");
	HX_VISIT_MEMBER_NAME(acceleration,"acceleration");
	HX_VISIT_MEMBER_NAME(elasticity,"elasticity");
	HX_VISIT_MEMBER_NAME(mass,"mass");
	HX_VISIT_MEMBER_NAME(velocity,"velocity");
	HX_VISIT_MEMBER_NAME(immovable,"immovable");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"UP") ) { return UP; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"ANY") ) { return ANY; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { return LEFT; }
		if (HX_FIELD_EQ(inName,"DOWN") ) { return DOWN; }
		if (HX_FIELD_EQ(inName,"NONE") ) { return NONE; }
		if (HX_FIELD_EQ(inName,"WALL") ) { return WALL; }
		if (HX_FIELD_EQ(inName,"hurt") ) { return hurt_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"path") ) { return path; }
		if (HX_FIELD_EQ(inName,"last") ) { return last; }
		if (HX_FIELD_EQ(inName,"drag") ) { return drag; }
		if (HX_FIELD_EQ(inName,"mass") ) { return mass; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { return RIGHT; }
		if (HX_FIELD_EQ(inName,"FLOOR") ) { return FLOOR; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"solid") ) { return inCallProp ? get_solid() : solid; }
		if (HX_FIELD_EQ(inName,"moves") ) { return moves; }
		if (HX_FIELD_EQ(inName,"_rect") ) { return _rect; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_pZero") ) { return _pZero; }
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"health") ) { return health; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"CEILING") ) { return CEILING; }
		if (HX_FIELD_EQ(inName,"flicker") ) { return flicker_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"separate") ) { return separate_dyn(); }
		if (HX_FIELD_EQ(inName,"onScreen") ) { return onScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"overlaps") ) { return overlaps_dyn(); }
		if (HX_FIELD_EQ(inName,"_pathInc") ) { return _pathInc; }
		if (HX_FIELD_EQ(inName,"touching") ) { return touching; }
		if (HX_FIELD_EQ(inName,"_flicker") ) { return _flicker; }
		if (HX_FIELD_EQ(inName,"velocity") ) { return velocity; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"PATH_YOYO") ) { return PATH_YOYO; }
		if (HX_FIELD_EQ(inName,"separateX") ) { return separateX_dyn(); }
		if (HX_FIELD_EQ(inName,"separateY") ) { return separateY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_solid") ) { return set_solid_dyn(); }
		if (HX_FIELD_EQ(inName,"get_solid") ) { return get_solid_dyn(); }
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		if (HX_FIELD_EQ(inName,"preUpdate") ) { return preUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"_pathMode") ) { return _pathMode; }
		if (HX_FIELD_EQ(inName,"pathAngle") ) { return pathAngle; }
		if (HX_FIELD_EQ(inName,"pathSpeed") ) { return pathSpeed; }
		if (HX_FIELD_EQ(inName,"immovable") ) { return immovable; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isTouching") ) { return isTouching_dyn(); }
		if (HX_FIELD_EQ(inName,"flickering") ) { return inCallProp ? get_flickering() : flickering; }
		if (HX_FIELD_EQ(inName,"overlapsAt") ) { return overlapsAt_dyn(); }
		if (HX_FIELD_EQ(inName,"followPath") ) { return followPath_dyn(); }
		if (HX_FIELD_EQ(inName,"postUpdate") ) { return postUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"maxAngular") ) { return maxAngular; }
		if (HX_FIELD_EQ(inName,"elasticity") ) { return elasticity; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"justTouched") ) { return justTouched_dyn(); }
		if (HX_FIELD_EQ(inName,"getMidpoint") ) { return getMidpoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getScreenXY") ) { return getScreenXY_dyn(); }
		if (HX_FIELD_EQ(inName,"advancePath") ) { return advancePath_dyn(); }
		if (HX_FIELD_EQ(inName,"_pathRotate") ) { return _pathRotate; }
		if (HX_FIELD_EQ(inName,"wasTouching") ) { return wasTouching; }
		if (HX_FIELD_EQ(inName,"angularDrag") ) { return angularDrag; }
		if (HX_FIELD_EQ(inName,"maxVelocity") ) { return maxVelocity; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"PATH_FORWARD") ) { return PATH_FORWARD; }
		if (HX_FIELD_EQ(inName,"updateMotion") ) { return updateMotion_dyn(); }
		if (HX_FIELD_EQ(inName,"scrollFactor") ) { return scrollFactor; }
		if (HX_FIELD_EQ(inName,"acceleration") ) { return acceleration; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SEPARATE_BIAS") ) { return SEPARATE_BIAS; }
		if (HX_FIELD_EQ(inName,"PATH_BACKWARD") ) { return PATH_BACKWARD; }
		if (HX_FIELD_EQ(inName,"overlapsPoint") ) { return overlapsPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"_flickerTimer") ) { return _flickerTimer; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_flickering") ) { return get_flickering_dyn(); }
		if (HX_FIELD_EQ(inName,"onScreenObject") ) { return onScreenObject_dyn(); }
		if (HX_FIELD_EQ(inName,"_pathNodeIndex") ) { return _pathNodeIndex; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"allowCollisions") ) { return allowCollisions; }
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { return angularVelocity; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"updatePathMotion") ) { return updatePathMotion_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"PATH_LOOP_FORWARD") ) { return PATH_LOOP_FORWARD; }
		if (HX_FIELD_EQ(inName,"stopFollowingPath") ) { return stopFollowingPath_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PATH_LOOP_BACKWARD") ) { return PATH_LOOP_BACKWARD; }
		if (HX_FIELD_EQ(inName,"PATH_VERTICAL_ONLY") ) { return PATH_VERTICAL_ONLY; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"angularAcceleration") ) { return angularAcceleration; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"PATH_HORIZONTAL_ONLY") ) { return PATH_HORIZONTAL_ONLY; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_firstSeparateFlxRect") ) { return _firstSeparateFlxRect; }
		if (HX_FIELD_EQ(inName,"onBoundingBoxColorSet") ) { return onBoundingBoxColorSet_dyn(); }
		if (HX_FIELD_EQ(inName,"debugBoundingBoxColor") ) { return debugBoundingBoxColor; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_secondSeparateFlxRect") ) { return _secondSeparateFlxRect; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_boundingBoxColorOverritten") ) { return _boundingBoxColorOverritten; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"UP") ) { UP=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"ANY") ) { ANY=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { LEFT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOWN") ) { DOWN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NONE") ) { NONE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WALL") ) { WALL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast< ::org::flixel::FlxPath >(); return inValue; }
		if (HX_FIELD_EQ(inName,"last") ) { last=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"drag") ) { drag=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mass") ) { mass=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { RIGHT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FLOOR") ) { FLOOR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"solid") ) { if (inCallProp) return set_solid(inValue);solid=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moves") ) { moves=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rect") ) { _rect=inValue.Cast< ::org::flixel::FlxRect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_pZero") ) { _pZero=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"health") ) { health=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"CEILING") ) { CEILING=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_pathInc") ) { _pathInc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touching") ) { touching=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flicker") ) { _flicker=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"velocity") ) { velocity=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"PATH_YOYO") ) { PATH_YOYO=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pathMode") ) { _pathMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathAngle") ) { pathAngle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathSpeed") ) { pathSpeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"immovable") ) { immovable=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"flickering") ) { flickering=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxAngular") ) { maxAngular=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elasticity") ) { elasticity=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_pathRotate") ) { _pathRotate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wasTouching") ) { wasTouching=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularDrag") ) { angularDrag=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxVelocity") ) { maxVelocity=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"PATH_FORWARD") ) { PATH_FORWARD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollFactor") ) { scrollFactor=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"acceleration") ) { acceleration=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SEPARATE_BIAS") ) { SEPARATE_BIAS=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PATH_BACKWARD") ) { PATH_BACKWARD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flickerTimer") ) { _flickerTimer=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_pathNodeIndex") ) { _pathNodeIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"allowCollisions") ) { allowCollisions=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { angularVelocity=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"PATH_LOOP_FORWARD") ) { PATH_LOOP_FORWARD=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PATH_LOOP_BACKWARD") ) { PATH_LOOP_BACKWARD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PATH_VERTICAL_ONLY") ) { PATH_VERTICAL_ONLY=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"angularAcceleration") ) { angularAcceleration=inValue.Cast< Float >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"PATH_HORIZONTAL_ONLY") ) { PATH_HORIZONTAL_ONLY=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_firstSeparateFlxRect") ) { _firstSeparateFlxRect=inValue.Cast< ::org::flixel::FlxRect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debugBoundingBoxColor") ) { if (inCallProp) return onBoundingBoxColorSet(inValue);debugBoundingBoxColor=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_secondSeparateFlxRect") ) { _secondSeparateFlxRect=inValue.Cast< ::org::flixel::FlxRect >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_boundingBoxColorOverritten") ) { _boundingBoxColorOverritten=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("solid"));
	outFields->push(HX_CSTRING("flickering"));
	outFields->push(HX_CSTRING("_boundingBoxColorOverritten"));
	outFields->push(HX_CSTRING("debugBoundingBoxColor"));
	outFields->push(HX_CSTRING("_pathRotate"));
	outFields->push(HX_CSTRING("_pathInc"));
	outFields->push(HX_CSTRING("_pathMode"));
	outFields->push(HX_CSTRING("_pathNodeIndex"));
	outFields->push(HX_CSTRING("pathAngle"));
	outFields->push(HX_CSTRING("pathSpeed"));
	outFields->push(HX_CSTRING("path"));
	outFields->push(HX_CSTRING("last"));
	outFields->push(HX_CSTRING("allowCollisions"));
	outFields->push(HX_CSTRING("wasTouching"));
	outFields->push(HX_CSTRING("touching"));
	outFields->push(HX_CSTRING("moves"));
	outFields->push(HX_CSTRING("_rect"));
	outFields->push(HX_CSTRING("_point"));
	outFields->push(HX_CSTRING("health"));
	outFields->push(HX_CSTRING("_flickerTimer"));
	outFields->push(HX_CSTRING("_flicker"));
	outFields->push(HX_CSTRING("scrollFactor"));
	outFields->push(HX_CSTRING("maxAngular"));
	outFields->push(HX_CSTRING("angularDrag"));
	outFields->push(HX_CSTRING("angularAcceleration"));
	outFields->push(HX_CSTRING("angularVelocity"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("maxVelocity"));
	outFields->push(HX_CSTRING("drag"));
	outFields->push(HX_CSTRING("acceleration"));
	outFields->push(HX_CSTRING("elasticity"));
	outFields->push(HX_CSTRING("mass"));
	outFields->push(HX_CSTRING("velocity"));
	outFields->push(HX_CSTRING("immovable"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SEPARATE_BIAS"),
	HX_CSTRING("LEFT"),
	HX_CSTRING("RIGHT"),
	HX_CSTRING("UP"),
	HX_CSTRING("DOWN"),
	HX_CSTRING("NONE"),
	HX_CSTRING("CEILING"),
	HX_CSTRING("FLOOR"),
	HX_CSTRING("WALL"),
	HX_CSTRING("ANY"),
	HX_CSTRING("PATH_FORWARD"),
	HX_CSTRING("PATH_BACKWARD"),
	HX_CSTRING("PATH_LOOP_FORWARD"),
	HX_CSTRING("PATH_LOOP_BACKWARD"),
	HX_CSTRING("PATH_YOYO"),
	HX_CSTRING("PATH_HORIZONTAL_ONLY"),
	HX_CSTRING("PATH_VERTICAL_ONLY"),
	HX_CSTRING("_firstSeparateFlxRect"),
	HX_CSTRING("_secondSeparateFlxRect"),
	HX_CSTRING("_pZero"),
	HX_CSTRING("separate"),
	HX_CSTRING("separateX"),
	HX_CSTRING("separateY"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("hurt"),
	HX_CSTRING("justTouched"),
	HX_CSTRING("isTouching"),
	HX_CSTRING("reset"),
	HX_CSTRING("getMidpoint"),
	HX_CSTRING("set_solid"),
	HX_CSTRING("get_solid"),
	HX_CSTRING("solid"),
	HX_CSTRING("get_flickering"),
	HX_CSTRING("flickering"),
	HX_CSTRING("flicker"),
	HX_CSTRING("getScreenXY"),
	HX_CSTRING("onScreenObject"),
	HX_CSTRING("onScreen"),
	HX_CSTRING("overlapsPoint"),
	HX_CSTRING("overlapsAt"),
	HX_CSTRING("overlaps"),
	HX_CSTRING("updatePathMotion"),
	HX_CSTRING("advancePath"),
	HX_CSTRING("stopFollowingPath"),
	HX_CSTRING("followPath"),
	HX_CSTRING("drawDebug"),
	HX_CSTRING("draw"),
	HX_CSTRING("updateMotion"),
	HX_CSTRING("postUpdate"),
	HX_CSTRING("preUpdate"),
	HX_CSTRING("destroy"),
	HX_CSTRING("onBoundingBoxColorSet"),
	HX_CSTRING("_boundingBoxColorOverritten"),
	HX_CSTRING("debugBoundingBoxColor"),
	HX_CSTRING("_pathRotate"),
	HX_CSTRING("_pathInc"),
	HX_CSTRING("_pathMode"),
	HX_CSTRING("_pathNodeIndex"),
	HX_CSTRING("pathAngle"),
	HX_CSTRING("pathSpeed"),
	HX_CSTRING("path"),
	HX_CSTRING("last"),
	HX_CSTRING("allowCollisions"),
	HX_CSTRING("wasTouching"),
	HX_CSTRING("touching"),
	HX_CSTRING("moves"),
	HX_CSTRING("_rect"),
	HX_CSTRING("_point"),
	HX_CSTRING("health"),
	HX_CSTRING("_flickerTimer"),
	HX_CSTRING("_flicker"),
	HX_CSTRING("scrollFactor"),
	HX_CSTRING("maxAngular"),
	HX_CSTRING("angularDrag"),
	HX_CSTRING("angularAcceleration"),
	HX_CSTRING("angularVelocity"),
	HX_CSTRING("angle"),
	HX_CSTRING("maxVelocity"),
	HX_CSTRING("drag"),
	HX_CSTRING("acceleration"),
	HX_CSTRING("elasticity"),
	HX_CSTRING("mass"),
	HX_CSTRING("velocity"),
	HX_CSTRING("immovable"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxObject_obj::SEPARATE_BIAS,"SEPARATE_BIAS");
	HX_MARK_MEMBER_NAME(FlxObject_obj::LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(FlxObject_obj::RIGHT,"RIGHT");
	HX_MARK_MEMBER_NAME(FlxObject_obj::UP,"UP");
	HX_MARK_MEMBER_NAME(FlxObject_obj::DOWN,"DOWN");
	HX_MARK_MEMBER_NAME(FlxObject_obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(FlxObject_obj::CEILING,"CEILING");
	HX_MARK_MEMBER_NAME(FlxObject_obj::FLOOR,"FLOOR");
	HX_MARK_MEMBER_NAME(FlxObject_obj::WALL,"WALL");
	HX_MARK_MEMBER_NAME(FlxObject_obj::ANY,"ANY");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_FORWARD,"PATH_FORWARD");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_BACKWARD,"PATH_BACKWARD");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_LOOP_FORWARD,"PATH_LOOP_FORWARD");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_LOOP_BACKWARD,"PATH_LOOP_BACKWARD");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_YOYO,"PATH_YOYO");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_HORIZONTAL_ONLY,"PATH_HORIZONTAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxObject_obj::PATH_VERTICAL_ONLY,"PATH_VERTICAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxObject_obj::_firstSeparateFlxRect,"_firstSeparateFlxRect");
	HX_MARK_MEMBER_NAME(FlxObject_obj::_secondSeparateFlxRect,"_secondSeparateFlxRect");
	HX_MARK_MEMBER_NAME(FlxObject_obj::_pZero,"_pZero");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::SEPARATE_BIAS,"SEPARATE_BIAS");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::LEFT,"LEFT");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::RIGHT,"RIGHT");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::UP,"UP");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::DOWN,"DOWN");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::CEILING,"CEILING");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::FLOOR,"FLOOR");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::WALL,"WALL");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::ANY,"ANY");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_FORWARD,"PATH_FORWARD");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_BACKWARD,"PATH_BACKWARD");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_LOOP_FORWARD,"PATH_LOOP_FORWARD");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_LOOP_BACKWARD,"PATH_LOOP_BACKWARD");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_YOYO,"PATH_YOYO");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_HORIZONTAL_ONLY,"PATH_HORIZONTAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::PATH_VERTICAL_ONLY,"PATH_VERTICAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::_firstSeparateFlxRect,"_firstSeparateFlxRect");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::_secondSeparateFlxRect,"_secondSeparateFlxRect");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::_pZero,"_pZero");
};

Class FlxObject_obj::__mClass;

void FlxObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxObject"), hx::TCanCast< FlxObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxObject_obj::__boot()
{
	SEPARATE_BIAS= (int)4;
	LEFT= (int)1;
	RIGHT= (int)16;
	UP= (int)256;
	DOWN= (int)4096;
	NONE= (int)0;
	CEILING= (int)256;
	FLOOR= (int)4096;
	WALL= (int)17;
	ANY= (int)4369;
	PATH_FORWARD= (int)0;
	PATH_BACKWARD= (int)1;
	PATH_LOOP_FORWARD= (int)16;
	PATH_LOOP_BACKWARD= (int)256;
	PATH_YOYO= (int)4096;
	PATH_HORIZONTAL_ONLY= (int)65536;
	PATH_VERTICAL_ONLY= (int)1048576;
	_firstSeparateFlxRect= ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
	_secondSeparateFlxRect= ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
	_pZero= ::org::flixel::FlxPoint_obj::__new(null(),null());
}

} // end namespace org
} // end namespace flixel
