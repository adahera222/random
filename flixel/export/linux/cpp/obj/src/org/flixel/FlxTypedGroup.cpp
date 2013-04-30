#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
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
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_org_flixel_FlxBasic
#include <org/flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_org_flixel_FlxG
#include <org/flixel/FlxG.h>
#endif
#ifndef INCLUDED_org_flixel_FlxGame
#include <org/flixel/FlxGame.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedGroup
#include <org/flixel/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_org_flixel_FlxU
#include <org/flixel/FlxU.h>
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
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_FlxSpriteFrames
#include <org/flixel/system/layer/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Node
#include <org/flixel/system/layer/Node.h>
#endif
#ifndef INCLUDED_org_flixel_tweens_FlxTween
#include <org/flixel/tweens/FlxTween.h>
#endif
namespace org{
namespace flixel{

Void FlxTypedGroup_obj::__construct(hx::Null< int >  __o_MaxSize)
{
HX_STACK_PUSH("FlxTypedGroup::new","org/flixel/FlxTypedGroup.hx",57);
int MaxSize = __o_MaxSize.Default(0);
{
	HX_STACK_LINE(58)
	super::__construct();
	HX_STACK_LINE(59)
	this->members = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(60)
	this->length = (int)0;
	HX_STACK_LINE(61)
	this->set_maxSize(::Std_obj::_int(::Math_obj::abs(MaxSize)));
	HX_STACK_LINE(62)
	this->_marker = (int)0;
	HX_STACK_LINE(63)
	this->_sortIndex = null();
	HX_STACK_LINE(64)
	this->autoReviveMembers = false;
}
;
	return null();
}

FlxTypedGroup_obj::~FlxTypedGroup_obj() { }

Dynamic FlxTypedGroup_obj::__CreateEmpty() { return  new FlxTypedGroup_obj; }
hx::ObjectPtr< FlxTypedGroup_obj > FlxTypedGroup_obj::__new(hx::Null< int >  __o_MaxSize)
{  hx::ObjectPtr< FlxTypedGroup_obj > result = new FlxTypedGroup_obj();
	result->__construct(__o_MaxSize);
	return result;}

Dynamic FlxTypedGroup_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTypedGroup_obj > result = new FlxTypedGroup_obj();
	result->__construct(inArgs[0]);
	return result;}

int FlxTypedGroup_obj::sortHandler( Dynamic Obj1,Dynamic Obj2){
	HX_STACK_PUSH("FlxTypedGroup::sortHandler","org/flixel/FlxTypedGroup.hx",697);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Obj1,"Obj1");
	HX_STACK_ARG(Obj2,"Obj2");
	HX_STACK_LINE(698)
	int prop1 = (  (((Obj1 == null()))) ? Dynamic(null()) : Dynamic(Obj1->__Field(this->_sortIndex,true)) );		HX_STACK_VAR(prop1,"prop1");
	HX_STACK_LINE(699)
	int prop2 = (  (((Obj2 == null()))) ? Dynamic(null()) : Dynamic(Obj2->__Field(this->_sortIndex,true)) );		HX_STACK_VAR(prop2,"prop2");
	HX_STACK_LINE(701)
	if (((prop1 < prop2))){
		HX_STACK_LINE(702)
		return this->_sortOrder;
	}
	else{
		HX_STACK_LINE(705)
		if (((prop1 > prop2))){
			HX_STACK_LINE(706)
			return -(this->_sortOrder);
		}
	}
	HX_STACK_LINE(709)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTypedGroup_obj,sortHandler,return )

Void FlxTypedGroup_obj::revive( ){
{
		HX_STACK_PUSH("FlxTypedGroup::revive","org/flixel/FlxTypedGroup.hx",673);
		HX_STACK_THIS(this);
		HX_STACK_LINE(674)
		this->super::revive();
		HX_STACK_LINE(675)
		if ((this->autoReviveMembers)){
			HX_STACK_LINE(677)
			Dynamic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(678)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(679)
			while(((i < this->length))){
				HX_STACK_LINE(681)
				basic = this->members->__GetItem((i)++);
				HX_STACK_LINE(682)
				if (((bool((basic != null())) && bool(!(basic->__Field(HX_CSTRING("exists"),true)))))){
					HX_STACK_LINE(683)
					basic->__Field(HX_CSTRING("revive"),true)();
				}
			}
		}
	}
return null();
}


Void FlxTypedGroup_obj::kill( ){
{
		HX_STACK_PUSH("FlxTypedGroup::kill","org/flixel/FlxTypedGroup.hx",655);
		HX_STACK_THIS(this);
		HX_STACK_LINE(656)
		Dynamic basic;		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(657)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(658)
		while(((i < this->length))){
			HX_STACK_LINE(660)
			basic = this->members->__GetItem((i)++);
			HX_STACK_LINE(661)
			if (((bool((basic != null())) && bool(basic->__Field(HX_CSTRING("exists"),true))))){
				HX_STACK_LINE(662)
				basic->__Field(HX_CSTRING("kill"),true)();
			}
		}
		HX_STACK_LINE(666)
		this->super::kill();
	}
return null();
}


Void FlxTypedGroup_obj::clear( ){
{
		HX_STACK_PUSH("FlxTypedGroup::clear","org/flixel/FlxTypedGroup.hx",646);
		HX_STACK_THIS(this);
		HX_STACK_LINE(647)
		this->length = (int)0;
		HX_STACK_LINE(648)
		this->members->__Field(HX_CSTRING("splice"),true)((int)0,this->members->__Field(HX_CSTRING("length"),true));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,clear,(void))

Dynamic FlxTypedGroup_obj::getRandom( hx::Null< int >  __o_StartIndex,hx::Null< int >  __o_Length){
int StartIndex = __o_StartIndex.Default(0);
int Length = __o_Length.Default(0);
	HX_STACK_PUSH("FlxTypedGroup::getRandom","org/flixel/FlxTypedGroup.hx",629);
	HX_STACK_THIS(this);
	HX_STACK_ARG(StartIndex,"StartIndex");
	HX_STACK_ARG(Length,"Length");
{
		HX_STACK_LINE(630)
		if (((StartIndex < (int)0))){
			HX_STACK_LINE(631)
			StartIndex = (int)0;
		}
		HX_STACK_LINE(634)
		if (((Length <= (int)0))){
			HX_STACK_LINE(635)
			Length = this->length;
		}
		HX_STACK_LINE(638)
		return ::org::flixel::FlxG_obj::getRandom(this->members,StartIndex,Length);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTypedGroup_obj,getRandom,return )

int FlxTypedGroup_obj::countDead( ){
	HX_STACK_PUSH("FlxTypedGroup::countDead","org/flixel/FlxTypedGroup.hx",598);
	HX_STACK_THIS(this);
	HX_STACK_LINE(599)
	int count = (int)-1;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(600)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(601)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(602)
	while(((i < this->length))){
		HX_STACK_LINE(604)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(605)
		if (((basic != null()))){
			HX_STACK_LINE(607)
			if (((count < (int)0))){
				HX_STACK_LINE(608)
				count = (int)0;
			}
			HX_STACK_LINE(611)
			if ((!(basic->__Field(HX_CSTRING("alive"),true)))){
				HX_STACK_LINE(612)
				(count)++;
			}
		}
	}
	HX_STACK_LINE(617)
	return count;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,countDead,return )

int FlxTypedGroup_obj::countLiving( ){
	HX_STACK_PUSH("FlxTypedGroup::countLiving","org/flixel/FlxTypedGroup.hx",571);
	HX_STACK_THIS(this);
	HX_STACK_LINE(572)
	int count = (int)-1;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(573)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(574)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(575)
	while(((i < this->length))){
		HX_STACK_LINE(577)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(578)
		if (((basic != null()))){
			HX_STACK_LINE(580)
			if (((count < (int)0))){
				HX_STACK_LINE(581)
				count = (int)0;
			}
			HX_STACK_LINE(584)
			if (((bool(basic->__Field(HX_CSTRING("exists"),true)) && bool(basic->__Field(HX_CSTRING("alive"),true))))){
				HX_STACK_LINE(585)
				(count)++;
			}
		}
	}
	HX_STACK_LINE(590)
	return count;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,countLiving,return )

Dynamic FlxTypedGroup_obj::getFirstDead( ){
	HX_STACK_PUSH("FlxTypedGroup::getFirstDead","org/flixel/FlxTypedGroup.hx",552);
	HX_STACK_THIS(this);
	HX_STACK_LINE(553)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(554)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(555)
	while(((i < this->length))){
		HX_STACK_LINE(557)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(558)
		if (((bool((basic != null())) && bool(!(basic->__Field(HX_CSTRING("alive"),true)))))){
			HX_STACK_LINE(559)
			return basic;
		}
	}
	HX_STACK_LINE(563)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,getFirstDead,return )

Dynamic FlxTypedGroup_obj::getFirstAlive( ){
	HX_STACK_PUSH("FlxTypedGroup::getFirstAlive","org/flixel/FlxTypedGroup.hx",531);
	HX_STACK_THIS(this);
	HX_STACK_LINE(532)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(533)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(534)
	while(((i < this->length))){
		HX_STACK_LINE(536)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(537)
		if (((bool((bool((basic != null())) && bool(basic->__Field(HX_CSTRING("exists"),true)))) && bool(basic->__Field(HX_CSTRING("alive"),true))))){
			HX_STACK_LINE(538)
			return basic;
		}
	}
	HX_STACK_LINE(542)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,getFirstAlive,return )

Dynamic FlxTypedGroup_obj::getFirstExtant( ){
	HX_STACK_PUSH("FlxTypedGroup::getFirstExtant","org/flixel/FlxTypedGroup.hx",510);
	HX_STACK_THIS(this);
	HX_STACK_LINE(511)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(512)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(513)
	while(((i < this->length))){
		HX_STACK_LINE(515)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(516)
		if (((bool((basic != null())) && bool(basic->__Field(HX_CSTRING("exists"),true))))){
			HX_STACK_LINE(517)
			return basic;
		}
	}
	HX_STACK_LINE(521)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,getFirstExtant,return )

int FlxTypedGroup_obj::getFirstNull( ){
	HX_STACK_PUSH("FlxTypedGroup::getFirstNull","org/flixel/FlxTypedGroup.hx",486);
	HX_STACK_THIS(this);
	HX_STACK_LINE(487)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(488)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(489)
	int l = this->members->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(490)
	while(((i < l))){
		HX_STACK_LINE(491)
		if (((this->members->__GetItem(i) == null()))){
			HX_STACK_LINE(493)
			return i;
		}
		else{
			HX_STACK_LINE(497)
			(i)++;
		}
	}
	HX_STACK_LINE(501)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedGroup_obj,getFirstNull,return )

Dynamic FlxTypedGroup_obj::getFirstAvailable( ::Class ObjectClass){
	HX_STACK_PUSH("FlxTypedGroup::getFirstAvailable","org/flixel/FlxTypedGroup.hx",466);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ObjectClass,"ObjectClass");
	HX_STACK_LINE(467)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(468)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(469)
	while(((i < this->length))){
		HX_STACK_LINE(471)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(472)
		if (((bool((bool((basic != null())) && bool(!(basic->__Field(HX_CSTRING("exists"),true))))) && bool(((bool((ObjectClass == null())) || bool(::Std_obj::is(basic,ObjectClass)))))))){
			HX_STACK_LINE(473)
			return basic;
		}
	}
	HX_STACK_LINE(477)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedGroup_obj,getFirstAvailable,return )

Void FlxTypedGroup_obj::callAll( ::String FunctionName,hx::Null< bool >  __o_Recurse){
bool Recurse = __o_Recurse.Default(true);
	HX_STACK_PUSH("FlxTypedGroup::callAll","org/flixel/FlxTypedGroup.hx",439);
	HX_STACK_THIS(this);
	HX_STACK_ARG(FunctionName,"FunctionName");
	HX_STACK_ARG(Recurse,"Recurse");
{
		HX_STACK_LINE(440)
		Dynamic basic;		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(441)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(442)
		while(((i < this->length))){
			HX_STACK_LINE(444)
			basic = this->members->__GetItem((i)++);
			HX_STACK_LINE(445)
			if (((basic != null()))){
				HX_STACK_LINE(446)
				if (((bool(Recurse) && bool(::Std_obj::is(basic,hx::ClassOf< ::org::flixel::FlxTypedGroup >()))))){
					HX_STACK_LINE(448)
					basic->__Field(HX_CSTRING("callAll"),true)(FunctionName,Recurse);
				}
				else{
					HX_STACK_LINE(452)
					::Reflect_obj::callMethod(basic,(  (((basic == null()))) ? Dynamic(null()) : Dynamic(basic->__Field(FunctionName,true)) ),Dynamic( Array_obj<Dynamic>::__new()));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTypedGroup_obj,callAll,(void))

Void FlxTypedGroup_obj::setAll( ::String VariableName,Dynamic Value,hx::Null< bool >  __o_Recurse){
bool Recurse = __o_Recurse.Default(true);
	HX_STACK_PUSH("FlxTypedGroup::setAll","org/flixel/FlxTypedGroup.hx",412);
	HX_STACK_THIS(this);
	HX_STACK_ARG(VariableName,"VariableName");
	HX_STACK_ARG(Value,"Value");
	HX_STACK_ARG(Recurse,"Recurse");
{
		HX_STACK_LINE(413)
		Dynamic basic;		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(414)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(415)
		while(((i < this->length))){
			HX_STACK_LINE(417)
			basic = this->members->__GetItem((i)++);
			HX_STACK_LINE(418)
			if (((basic != null()))){
				HX_STACK_LINE(419)
				if (((bool(Recurse) && bool(::Std_obj::is(basic,hx::ClassOf< ::org::flixel::FlxTypedGroup >()))))){
					HX_STACK_LINE(421)
					basic->__Field(HX_CSTRING("setAll"),true)(VariableName,Value,Recurse);
				}
				else{
					HX_STACK_LINE(425)
					if (((basic != null()))){
						HX_STACK_LINE(426)
						basic->__SetField(VariableName,Value,true);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTypedGroup_obj,setAll,(void))

Void FlxTypedGroup_obj::sort( ::String __o_Index,hx::Null< int >  __o_Order){
::String Index = __o_Index.Default(HX_CSTRING("y"));
int Order = __o_Order.Default(-1);
	HX_STACK_PUSH("FlxTypedGroup::sort","org/flixel/FlxTypedGroup.hx",399);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Index,"Index");
	HX_STACK_ARG(Order,"Order");
{
		HX_STACK_LINE(400)
		this->_sortIndex = Index;
		HX_STACK_LINE(401)
		this->_sortOrder = Order;
		HX_STACK_LINE(402)
		this->members->__Field(HX_CSTRING("sort"),true)(this->sortHandler_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTypedGroup_obj,sort,(void))

Dynamic FlxTypedGroup_obj::replace( Dynamic OldObject,Dynamic NewObject){
	HX_STACK_PUSH("FlxTypedGroup::replace","org/flixel/FlxTypedGroup.hx",379);
	HX_STACK_THIS(this);
	HX_STACK_ARG(OldObject,"OldObject");
	HX_STACK_ARG(NewObject,"NewObject");
	struct _Function_1_1{
		inline static int Block( ::org::flixel::FlxTypedGroup_obj *__this,Dynamic &OldObject){
			HX_STACK_PUSH("*::closure","org/flixel/FlxTypedGroup.hx",380);
			{
				HX_STACK_LINE(380)
				Dynamic array = __this->members;		HX_STACK_VAR(array,"array");
				int fromIndex = (int)0;		HX_STACK_VAR(fromIndex,"fromIndex");
				HX_STACK_LINE(380)
				int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
				HX_STACK_LINE(380)
				int index = (int)-1;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(380)
				{
					HX_STACK_LINE(380)
					int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(380)
					while(((_g < len))){
						HX_STACK_LINE(380)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(380)
						if (((array->__GetItem(i) == OldObject))){
							HX_STACK_LINE(380)
							index = i;
							HX_STACK_LINE(380)
							break;
						}
					}
				}
				HX_STACK_LINE(380)
				return index;
			}
			return null();
		}
	};
	HX_STACK_LINE(380)
	int index = _Function_1_1::Block(this,OldObject);		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(381)
	if (((bool((index < (int)0)) || bool((index >= this->members->__Field(HX_CSTRING("length"),true)))))){
		HX_STACK_LINE(382)
		return null();
	}
	HX_STACK_LINE(385)
	hx::IndexRef((this->members).mPtr,index) = NewObject;
	HX_STACK_LINE(386)
	return NewObject;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTypedGroup_obj,replace,return )

Dynamic FlxTypedGroup_obj::remove( Dynamic Object,hx::Null< bool >  __o_Splice){
bool Splice = __o_Splice.Default(false);
	HX_STACK_PUSH("FlxTypedGroup::remove","org/flixel/FlxTypedGroup.hx",350);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Object,"Object");
	HX_STACK_ARG(Splice,"Splice");
{
		HX_STACK_LINE(351)
		if (((this->members == null()))){
			HX_STACK_LINE(352)
			return null();
		}
		struct _Function_1_1{
			inline static int Block( ::org::flixel::FlxTypedGroup_obj *__this,Dynamic &Object){
				HX_STACK_PUSH("*::closure","org/flixel/FlxTypedGroup.hx",356);
				{
					HX_STACK_LINE(356)
					Dynamic array = __this->members;		HX_STACK_VAR(array,"array");
					int fromIndex = (int)0;		HX_STACK_VAR(fromIndex,"fromIndex");
					HX_STACK_LINE(356)
					int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(356)
					int index = (int)-1;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(356)
					{
						HX_STACK_LINE(356)
						int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(356)
						while(((_g < len))){
							HX_STACK_LINE(356)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(356)
							if (((array->__GetItem(i) == Object))){
								HX_STACK_LINE(356)
								index = i;
								HX_STACK_LINE(356)
								break;
							}
						}
					}
					HX_STACK_LINE(356)
					return index;
				}
				return null();
			}
		};
		HX_STACK_LINE(356)
		int index = _Function_1_1::Block(this,Object);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(357)
		if (((bool((index < (int)0)) || bool((index >= this->members->__Field(HX_CSTRING("length"),true)))))){
			HX_STACK_LINE(358)
			return null();
		}
		HX_STACK_LINE(361)
		if ((Splice)){
			HX_STACK_LINE(362)
			this->members->__Field(HX_CSTRING("splice"),true)(index,(int)1);
		}
		else{
			HX_STACK_LINE(366)
			hx::IndexRef((this->members).mPtr,index) = null();
		}
		HX_STACK_LINE(369)
		return Object;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTypedGroup_obj,remove,return )

Dynamic FlxTypedGroup_obj::recycle( ::Class ObjectClass){
	HX_STACK_PUSH("FlxTypedGroup::recycle","org/flixel/FlxTypedGroup.hx",306);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ObjectClass,"ObjectClass");
	HX_STACK_LINE(307)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(308)
	if (((this->maxSize > (int)0))){
		HX_STACK_LINE(309)
		if (((this->length < this->maxSize))){
			HX_STACK_LINE(312)
			if (((ObjectClass == null()))){
				HX_STACK_LINE(313)
				return null();
			}
			HX_STACK_LINE(316)
			return this->add(::Type_obj::createInstance(ObjectClass,Dynamic( Array_obj<Dynamic>::__new())));
		}
		else{
			HX_STACK_LINE(320)
			basic = this->members->__GetItem((this->_marker)++);
			HX_STACK_LINE(321)
			if (((this->_marker >= this->maxSize))){
				HX_STACK_LINE(322)
				this->_marker = (int)0;
			}
			HX_STACK_LINE(325)
			return basic;
		}
	}
	else{
		HX_STACK_LINE(330)
		basic = this->getFirstAvailable(ObjectClass);
		HX_STACK_LINE(331)
		if (((basic != null()))){
			HX_STACK_LINE(332)
			return basic;
		}
		HX_STACK_LINE(335)
		if (((ObjectClass == null()))){
			HX_STACK_LINE(336)
			return null();
		}
		HX_STACK_LINE(339)
		return this->add(::Type_obj::createInstance(ObjectClass,Dynamic( Array_obj<Dynamic>::__new())));
	}
	HX_STACK_LINE(308)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedGroup_obj,recycle,return )

::org::flixel::system::layer::Atlas FlxTypedGroup_obj::set_atlas( ::org::flixel::system::layer::Atlas value){
	HX_STACK_PUSH("FlxTypedGroup::set_atlas","org/flixel/FlxTypedGroup.hx",260);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(261)
	if (((this->_atlas != value))){
		HX_STACK_LINE(263)
		if (((value == null()))){
			HX_STACK_LINE(265)
			this->_node = null();
			HX_STACK_LINE(266)
			this->_framesData = null();
		}
		HX_STACK_LINE(269)
		this->_atlas = value;
	}
	HX_STACK_LINE(272)
	if (((this->_atlas != null()))){
		HX_STACK_LINE(274)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Dynamic _g1 = this->members;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(274)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(274)
			Dynamic basic = _g1->__GetItem(_g);		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(274)
			++(_g);
			HX_STACK_LINE(276)
			if (((basic != null()))){
				HX_STACK_LINE(277)
				this->setGroupAtlas(basic);
			}
		}
	}
	HX_STACK_LINE(283)
	return value;
}


Void FlxTypedGroup_obj::setGroupAtlas( Dynamic Object){
{
		HX_STACK_PUSH("FlxTypedGroup::setGroupAtlas","org/flixel/FlxTypedGroup.hx",252);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Object,"Object");
		HX_STACK_LINE(252)
		if (((this->_atlas != null()))){
			HX_STACK_LINE(254)
			Object->__Field(HX_CSTRING("set_atlas"),true)(this->_atlas);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedGroup_obj,setGroupAtlas,(void))

Dynamic FlxTypedGroup_obj::add( Dynamic Object){
	HX_STACK_PUSH("FlxTypedGroup::add","org/flixel/FlxTypedGroup.hx",186);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Object,"Object");
	HX_STACK_LINE(187)
	if (((Object == null()))){
		HX_STACK_LINE(189)
		if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
			struct _Function_3_1{
				inline static ::String Block( ){
					HX_STACK_PUSH("*::closure","org/flixel/FlxTypedGroup.hx",189);
					{
						HX_STACK_LINE(189)
						Dynamic AnyArray = hx::TCastToArray(HX_CSTRING("WARNING: Cannot add a `null` object to a FlxGroup."));		HX_STACK_VAR(AnyArray,"AnyArray");
						HX_STACK_LINE(189)
						::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
						HX_STACK_LINE(189)
						if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
							HX_STACK_LINE(189)
							string = ::Std_obj::string(AnyArray->__GetItem((int)0));
							HX_STACK_LINE(189)
							int i = (int)1;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(189)
							int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
							HX_STACK_LINE(189)
							while(((i < l))){
								HX_STACK_LINE(189)
								hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
							}
						}
						HX_STACK_LINE(189)
						return string;
					}
					return null();
				}
			};
			HX_STACK_LINE(189)
			::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  ((::Std_obj::is(HX_CSTRING("WARNING: Cannot add a `null` object to a FlxGroup."),hx::ClassOf< Array<int> >()))) ? ::String(_Function_3_1::Block()) : ::String(::Std_obj::string(HX_CSTRING("WARNING: Cannot add a `null` object to a FlxGroup."))) ));
		}
		HX_STACK_LINE(190)
		return null();
	}
	struct _Function_1_1{
		inline static int Block( ::org::flixel::FlxTypedGroup_obj *__this,Dynamic &Object){
			HX_STACK_PUSH("*::closure","org/flixel/FlxTypedGroup.hx",194);
			{
				HX_STACK_LINE(194)
				Dynamic array = __this->members;		HX_STACK_VAR(array,"array");
				int fromIndex = (int)0;		HX_STACK_VAR(fromIndex,"fromIndex");
				HX_STACK_LINE(194)
				int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
				HX_STACK_LINE(194)
				int index = (int)-1;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(194)
				{
					HX_STACK_LINE(194)
					int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(194)
					while(((_g < len))){
						HX_STACK_LINE(194)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(194)
						if (((array->__GetItem(i) == Object))){
							HX_STACK_LINE(194)
							index = i;
							HX_STACK_LINE(194)
							break;
						}
					}
				}
				HX_STACK_LINE(194)
				return index;
			}
			return null();
		}
	};
	HX_STACK_LINE(194)
	if (((_Function_1_1::Block(this,Object) >= (int)0))){
		HX_STACK_LINE(195)
		return Object;
	}
	HX_STACK_LINE(200)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(201)
	int l = this->members->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(202)
	while(((i < l))){
		HX_STACK_LINE(204)
		if (((this->members->__GetItem(i) == null()))){
			HX_STACK_LINE(206)
			hx::IndexRef((this->members).mPtr,i) = Object;
			HX_STACK_LINE(207)
			if (((i >= this->length))){
				HX_STACK_LINE(208)
				this->length = (i + (int)1);
			}
			HX_STACK_LINE(212)
			this->setGroupAtlas(Object);
			HX_STACK_LINE(214)
			return Object;
		}
		HX_STACK_LINE(216)
		(i)++;
	}
	HX_STACK_LINE(220)
	if (((this->maxSize > (int)0))){
		HX_STACK_LINE(221)
		if (((this->members->__Field(HX_CSTRING("length"),true) >= this->maxSize))){
			HX_STACK_LINE(223)
			return Object;
		}
		else{
			HX_STACK_LINE(226)
			if ((((this->members->__Field(HX_CSTRING("length"),true) * (int)2) <= this->maxSize))){
				HX_STACK_LINE(227)
				::org::flixel::FlxU_obj::SetArrayLength(this->members,(this->members->__Field(HX_CSTRING("length"),true) * (int)2));
			}
			else{
				HX_STACK_LINE(231)
				::org::flixel::FlxU_obj::SetArrayLength(this->members,this->maxSize);
			}
		}
	}
	else{
		HX_STACK_LINE(236)
		::org::flixel::FlxU_obj::SetArrayLength(this->members,(this->members->__Field(HX_CSTRING("length"),true) * (int)2));
	}
	HX_STACK_LINE(243)
	this->setGroupAtlas(Object);
	HX_STACK_LINE(245)
	hx::IndexRef((this->members).mPtr,i) = Object;
	HX_STACK_LINE(246)
	this->length = (i + (int)1);
	HX_STACK_LINE(247)
	return Object;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedGroup_obj,add,return )

int FlxTypedGroup_obj::set_maxSize( int Size){
	HX_STACK_PUSH("FlxTypedGroup::set_maxSize","org/flixel/FlxTypedGroup.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Size,"Size");
	HX_STACK_LINE(148)
	this->maxSize = ::Std_obj::_int(::Math_obj::abs(Size));
	HX_STACK_LINE(149)
	if (((this->_marker >= this->maxSize))){
		HX_STACK_LINE(150)
		this->_marker = (int)0;
	}
	HX_STACK_LINE(153)
	if (((bool((bool((this->maxSize == (int)0)) || bool((this->members == null())))) || bool((this->maxSize >= this->members->__Field(HX_CSTRING("length"),true)))))){
		HX_STACK_LINE(154)
		return this->maxSize;
	}
	HX_STACK_LINE(159)
	Dynamic basic;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(160)
	int i = this->maxSize;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(161)
	int l = this->members->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(162)
	while(((i < l))){
		HX_STACK_LINE(164)
		basic = this->members->__GetItem((i)++);
		HX_STACK_LINE(165)
		if (((basic != null()))){
			HX_STACK_LINE(166)
			basic->__Field(HX_CSTRING("destroy"),true)();
		}
	}
	HX_STACK_LINE(170)
	this->length = this->maxSize;
	HX_STACK_LINE(171)
	::org::flixel::FlxU_obj::SetArrayLength(this->members,this->maxSize);
	HX_STACK_LINE(172)
	return this->maxSize;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedGroup_obj,set_maxSize,return )

Void FlxTypedGroup_obj::draw( ){
{
		HX_STACK_PUSH("FlxTypedGroup::draw","org/flixel/FlxTypedGroup.hx",130);
		HX_STACK_THIS(this);
		HX_STACK_LINE(131)
		Dynamic basic;		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(132)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(133)
		while(((i < this->length))){
			HX_STACK_LINE(135)
			basic = this->members->__GetItem((i)++);
			HX_STACK_LINE(136)
			if (((bool((bool((basic != null())) && bool(basic->__Field(HX_CSTRING("exists"),true)))) && bool(basic->__Field(HX_CSTRING("visible"),true))))){
				HX_STACK_LINE(137)
				basic->__Field(HX_CSTRING("draw"),true)();
			}
		}
	}
return null();
}


Void FlxTypedGroup_obj::update( ){
{
		HX_STACK_PUSH("FlxTypedGroup::update","org/flixel/FlxTypedGroup.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_LINE(101)
		Dynamic basic;		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(102)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(103)
		while(((i < this->length))){
			HX_STACK_LINE(105)
			basic = this->members->__GetItem((i)++);
			HX_STACK_LINE(106)
			if (((bool((bool((basic != null())) && bool(basic->__Field(HX_CSTRING("exists"),true)))) && bool(basic->__Field(HX_CSTRING("active"),true))))){
				HX_STACK_LINE(108)
				basic->__Field(HX_CSTRING("preUpdate"),true)();
				HX_STACK_LINE(109)
				basic->__Field(HX_CSTRING("update"),true)();
				HX_STACK_LINE(111)
				if ((basic->__Field(HX_CSTRING("get_hasTween"),true)())){
					HX_STACK_LINE(113)
					::org::flixel::tweens::FlxTween t;		HX_STACK_VAR(t,"t");
					HX_STACK_LINE(113)
					Dynamic ft = basic->__Field(HX_CSTRING("_tween"),true);		HX_STACK_VAR(ft,"ft");
					HX_STACK_LINE(113)
					while(((ft != null()))){
						HX_STACK_LINE(113)
						t = hx::TCast< org::flixel::tweens::FlxTween >::cast(ft);
						HX_STACK_LINE(113)
						if ((t->active)){
							HX_STACK_LINE(113)
							t->update();
							HX_STACK_LINE(113)
							if ((ft->__Field(HX_CSTRING("_finish"),true))){
								HX_STACK_LINE(113)
								ft->__Field(HX_CSTRING("finish"),true)();
							}
						}
						HX_STACK_LINE(113)
						ft = ft->__Field(HX_CSTRING("_next"),true);
					}
				}
				HX_STACK_LINE(116)
				basic->__Field(HX_CSTRING("postUpdate"),true)();
			}
		}
		HX_STACK_LINE(120)
		if ((this->get_hasTween())){
			HX_STACK_LINE(122)
			::org::flixel::tweens::FlxTween t;		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(122)
			Dynamic ft = this->_tween;		HX_STACK_VAR(ft,"ft");
			HX_STACK_LINE(122)
			while(((ft != null()))){
				HX_STACK_LINE(122)
				t = hx::TCast< org::flixel::tweens::FlxTween >::cast(ft);
				HX_STACK_LINE(122)
				if ((t->active)){
					HX_STACK_LINE(122)
					t->update();
					HX_STACK_LINE(122)
					if ((ft->__Field(HX_CSTRING("_finish"),true))){
						HX_STACK_LINE(122)
						ft->__Field(HX_CSTRING("finish"),true)();
					}
				}
				HX_STACK_LINE(122)
				ft = ft->__Field(HX_CSTRING("_next"),true);
			}
		}
	}
return null();
}


Void FlxTypedGroup_obj::preUpdate( ){
{
		HX_STACK_PUSH("FlxTypedGroup::preUpdate","org/flixel/FlxTypedGroup.hx",94);
		HX_STACK_THIS(this);
	}
return null();
}


Void FlxTypedGroup_obj::destroy( ){
{
		HX_STACK_PUSH("FlxTypedGroup::destroy","org/flixel/FlxTypedGroup.hx",72);
		HX_STACK_THIS(this);
		HX_STACK_LINE(73)
		if (((this->members != null()))){
			HX_STACK_LINE(75)
			Dynamic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(76)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(77)
			while(((i < this->length))){
				HX_STACK_LINE(79)
				basic = this->members->__GetItem((i)++);
				HX_STACK_LINE(80)
				if (((basic != null()))){
					HX_STACK_LINE(81)
					basic->__Field(HX_CSTRING("destroy"),true)();
				}
			}
			HX_STACK_LINE(85)
			this->members = null();
		}
		HX_STACK_LINE(87)
		this->_sortIndex = null();
		HX_STACK_LINE(88)
		this->super::destroy();
	}
return null();
}


int FlxTypedGroup_obj::ASCENDING;

int FlxTypedGroup_obj::DESCENDING;


FlxTypedGroup_obj::FlxTypedGroup_obj()
{
}

void FlxTypedGroup_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTypedGroup);
	HX_MARK_MEMBER_NAME(autoReviveMembers,"autoReviveMembers");
	HX_MARK_MEMBER_NAME(_sortOrder,"_sortOrder");
	HX_MARK_MEMBER_NAME(_sortIndex,"_sortIndex");
	HX_MARK_MEMBER_NAME(_marker,"_marker");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(members,"members");
	HX_MARK_MEMBER_NAME(maxSize,"maxSize");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxTypedGroup_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(autoReviveMembers,"autoReviveMembers");
	HX_VISIT_MEMBER_NAME(_sortOrder,"_sortOrder");
	HX_VISIT_MEMBER_NAME(_sortIndex,"_sortIndex");
	HX_VISIT_MEMBER_NAME(_marker,"_marker");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(members,"members");
	HX_VISIT_MEMBER_NAME(maxSize,"maxSize");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxTypedGroup_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		if (HX_FIELD_EQ(inName,"sort") ) { return sort_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"revive") ) { return revive_dyn(); }
		if (HX_FIELD_EQ(inName,"setAll") ) { return setAll_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"callAll") ) { return callAll_dyn(); }
		if (HX_FIELD_EQ(inName,"replace") ) { return replace_dyn(); }
		if (HX_FIELD_EQ(inName,"recycle") ) { return recycle_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_marker") ) { return _marker; }
		if (HX_FIELD_EQ(inName,"members") ) { return members; }
		if (HX_FIELD_EQ(inName,"maxSize") ) { return maxSize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ASCENDING") ) { return ASCENDING; }
		if (HX_FIELD_EQ(inName,"getRandom") ) { return getRandom_dyn(); }
		if (HX_FIELD_EQ(inName,"countDead") ) { return countDead_dyn(); }
		if (HX_FIELD_EQ(inName,"set_atlas") ) { return set_atlas_dyn(); }
		if (HX_FIELD_EQ(inName,"preUpdate") ) { return preUpdate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"DESCENDING") ) { return DESCENDING; }
		if (HX_FIELD_EQ(inName,"_sortOrder") ) { return _sortOrder; }
		if (HX_FIELD_EQ(inName,"_sortIndex") ) { return _sortIndex; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sortHandler") ) { return sortHandler_dyn(); }
		if (HX_FIELD_EQ(inName,"countLiving") ) { return countLiving_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxSize") ) { return set_maxSize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getFirstDead") ) { return getFirstDead_dyn(); }
		if (HX_FIELD_EQ(inName,"getFirstNull") ) { return getFirstNull_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getFirstAlive") ) { return getFirstAlive_dyn(); }
		if (HX_FIELD_EQ(inName,"setGroupAtlas") ) { return setGroupAtlas_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getFirstExtant") ) { return getFirstExtant_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getFirstAvailable") ) { return getFirstAvailable_dyn(); }
		if (HX_FIELD_EQ(inName,"autoReviveMembers") ) { return autoReviveMembers; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTypedGroup_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_marker") ) { _marker=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"members") ) { members=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxSize") ) { if (inCallProp) return set_maxSize(inValue);maxSize=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ASCENDING") ) { ASCENDING=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"DESCENDING") ) { DESCENDING=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sortOrder") ) { _sortOrder=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sortIndex") ) { _sortIndex=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"autoReviveMembers") ) { autoReviveMembers=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTypedGroup_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("autoReviveMembers"));
	outFields->push(HX_CSTRING("_sortOrder"));
	outFields->push(HX_CSTRING("_sortIndex"));
	outFields->push(HX_CSTRING("_marker"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("members"));
	outFields->push(HX_CSTRING("maxSize"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ASCENDING"),
	HX_CSTRING("DESCENDING"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sortHandler"),
	HX_CSTRING("revive"),
	HX_CSTRING("kill"),
	HX_CSTRING("clear"),
	HX_CSTRING("getRandom"),
	HX_CSTRING("countDead"),
	HX_CSTRING("countLiving"),
	HX_CSTRING("getFirstDead"),
	HX_CSTRING("getFirstAlive"),
	HX_CSTRING("getFirstExtant"),
	HX_CSTRING("getFirstNull"),
	HX_CSTRING("getFirstAvailable"),
	HX_CSTRING("callAll"),
	HX_CSTRING("setAll"),
	HX_CSTRING("sort"),
	HX_CSTRING("replace"),
	HX_CSTRING("remove"),
	HX_CSTRING("recycle"),
	HX_CSTRING("set_atlas"),
	HX_CSTRING("setGroupAtlas"),
	HX_CSTRING("add"),
	HX_CSTRING("set_maxSize"),
	HX_CSTRING("draw"),
	HX_CSTRING("update"),
	HX_CSTRING("preUpdate"),
	HX_CSTRING("destroy"),
	HX_CSTRING("autoReviveMembers"),
	HX_CSTRING("_sortOrder"),
	HX_CSTRING("_sortIndex"),
	HX_CSTRING("_marker"),
	HX_CSTRING("length"),
	HX_CSTRING("members"),
	HX_CSTRING("maxSize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTypedGroup_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxTypedGroup_obj::ASCENDING,"ASCENDING");
	HX_MARK_MEMBER_NAME(FlxTypedGroup_obj::DESCENDING,"DESCENDING");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTypedGroup_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxTypedGroup_obj::ASCENDING,"ASCENDING");
	HX_VISIT_MEMBER_NAME(FlxTypedGroup_obj::DESCENDING,"DESCENDING");
};

Class FlxTypedGroup_obj::__mClass;

void FlxTypedGroup_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxTypedGroup"), hx::TCanCast< FlxTypedGroup_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxTypedGroup_obj::__boot()
{
	ASCENDING= (int)-1;
	DESCENDING= (int)1;
}

} // end namespace org
} // end namespace flixel
