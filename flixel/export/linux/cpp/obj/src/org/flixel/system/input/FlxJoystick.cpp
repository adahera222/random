#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxJoyButton
#include <org/flixel/system/input/FlxJoyButton.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxJoystick
#include <org/flixel/system/input/FlxJoystick.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace input{

Void FlxJoystick_obj::__construct(int id,hx::Null< Float >  __o_globalDeadZone)
{
HX_STACK_PUSH("FlxJoystick::new","org/flixel/system/input/FlxJoystick.hx",6);
Float globalDeadZone = __o_globalDeadZone.Default(0);
{
	HX_STACK_LINE(20)
	this->deadZone = 0.15;
	HX_STACK_LINE(24)
	this->buttons = ::IntHash_obj::__new();
	HX_STACK_LINE(25)
	this->ball = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(26)
	this->axis = Array_obj< Float >::__new();
	HX_STACK_LINE(27)
	this->hat = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(28)
	this->id = id;
	HX_STACK_LINE(30)
	if (((globalDeadZone != (int)0))){
		HX_STACK_LINE(31)
		this->deadZone = globalDeadZone;
	}
}
;
	return null();
}

FlxJoystick_obj::~FlxJoystick_obj() { }

Dynamic FlxJoystick_obj::__CreateEmpty() { return  new FlxJoystick_obj; }
hx::ObjectPtr< FlxJoystick_obj > FlxJoystick_obj::__new(int id,hx::Null< Float >  __o_globalDeadZone)
{  hx::ObjectPtr< FlxJoystick_obj > result = new FlxJoystick_obj();
	result->__construct(id,__o_globalDeadZone);
	return result;}

Dynamic FlxJoystick_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxJoystick_obj > result = new FlxJoystick_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool FlxJoystick_obj::anyInput( ){
	HX_STACK_PUSH("FlxJoystick::anyInput","org/flixel/system/input/FlxJoystick.hx",168);
	HX_STACK_THIS(this);
	HX_STACK_LINE(169)
	for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoyButton > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoyButton >(this->buttons->iterator());  __it->hasNext(); ){
		::org::flixel::system::input::FlxJoyButton button = __it->next();
		if (((button->current > (int)0))){
			HX_STACK_LINE(172)
			return true;
		}
;
	}
	HX_STACK_LINE(177)
	int numAxis = this->axis->length;		HX_STACK_VAR(numAxis,"numAxis");
	HX_STACK_LINE(178)
	{
		HX_STACK_LINE(178)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(178)
		while(((_g < numAxis))){
			HX_STACK_LINE(178)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(180)
			if (((this->axis->__get((int)0) != (int)0))){
				HX_STACK_LINE(181)
				return true;
			}
		}
	}
	HX_STACK_LINE(186)
	if (((bool((this->ball->x != (int)0)) || bool((this->ball->y != (int)0))))){
		HX_STACK_LINE(187)
		return true;
	}
	HX_STACK_LINE(191)
	if (((bool((this->hat->x != (int)0)) || bool((this->hat->y != (int)0))))){
		HX_STACK_LINE(192)
		return true;
	}
	HX_STACK_LINE(196)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystick_obj,anyInput,return )

bool FlxJoystick_obj::anyButton( ){
	HX_STACK_PUSH("FlxJoystick::anyButton","org/flixel/system/input/FlxJoystick.hx",151);
	HX_STACK_THIS(this);
	HX_STACK_LINE(152)
	for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoyButton > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoyButton >(this->buttons->iterator());  __it->hasNext(); ){
		::org::flixel::system::input::FlxJoyButton button = __it->next();
		if (((button->current > (int)0))){
			HX_STACK_LINE(155)
			return true;
		}
;
	}
	HX_STACK_LINE(160)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystick_obj,anyButton,return )

Float FlxJoystick_obj::getAxis( int axeID){
	HX_STACK_PUSH("FlxJoystick::getAxis","org/flixel/system/input/FlxJoystick.hx",136);
	HX_STACK_THIS(this);
	HX_STACK_ARG(axeID,"axeID");
	HX_STACK_LINE(137)
	if (((bool((axeID < (int)0)) || bool((axeID >= this->axis->length))))){
		HX_STACK_LINE(138)
		return (int)0;
	}
	struct _Function_1_1{
		inline static Float Block( ::org::flixel::system::input::FlxJoystick_obj *__this,int &axeID){
			HX_STACK_PUSH("*::closure","org/flixel/system/input/FlxJoystick.hx",140);
			{
				HX_STACK_LINE(140)
				Float Value = __this->axis->__get(axeID);		HX_STACK_VAR(Value,"Value");
				HX_STACK_LINE(140)
				return (  (((Value > (int)0))) ? Float(Value) : Float(-(Value)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(140)
	if (((_Function_1_1::Block(this,axeID) > this->deadZone))){
		HX_STACK_LINE(141)
		return this->axis->__get(axeID);
	}
	HX_STACK_LINE(143)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystick_obj,getAxis,return )

bool FlxJoystick_obj::justReleased( int buttonID){
	HX_STACK_PUSH("FlxJoystick::justReleased","org/flixel/system/input/FlxJoystick.hx",126);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buttonID,"buttonID");
	HX_STACK_LINE(127)
	if ((this->buttons->exists(buttonID))){
		HX_STACK_LINE(128)
		return (this->buttons->get(buttonID)->__Field(HX_CSTRING("current"),true) == (int)-1);
	}
	HX_STACK_LINE(132)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystick_obj,justReleased,return )

bool FlxJoystick_obj::justPressed( int buttonID){
	HX_STACK_PUSH("FlxJoystick::justPressed","org/flixel/system/input/FlxJoystick.hx",111);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buttonID,"buttonID");
	HX_STACK_LINE(112)
	if ((this->buttons->exists(buttonID))){
		HX_STACK_LINE(113)
		return (this->buttons->get(buttonID)->__Field(HX_CSTRING("current"),true) == (int)2);
	}
	HX_STACK_LINE(117)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystick_obj,justPressed,return )

bool FlxJoystick_obj::pressed( int buttonID){
	HX_STACK_PUSH("FlxJoystick::pressed","org/flixel/system/input/FlxJoystick.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buttonID,"buttonID");
	HX_STACK_LINE(97)
	if ((this->buttons->exists(buttonID))){
		HX_STACK_LINE(98)
		return (this->buttons->get(buttonID)->__Field(HX_CSTRING("current"),true) > (int)0);
	}
	HX_STACK_LINE(102)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystick_obj,pressed,return )

Void FlxJoystick_obj::destroy( ){
{
		HX_STACK_PUSH("FlxJoystick::destroy","org/flixel/system/input/FlxJoystick.hx",83);
		HX_STACK_THIS(this);
		HX_STACK_LINE(84)
		this->buttons = null();
		HX_STACK_LINE(85)
		this->axis = null();
		HX_STACK_LINE(86)
		this->hat = null();
		HX_STACK_LINE(87)
		this->ball = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystick_obj,destroy,(void))

Void FlxJoystick_obj::reset( ){
{
		HX_STACK_PUSH("FlxJoystick::reset","org/flixel/system/input/FlxJoystick.hx",65);
		HX_STACK_THIS(this);
		HX_STACK_LINE(66)
		for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoyButton > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoyButton >(this->buttons->iterator());  __it->hasNext(); ){
			::org::flixel::system::input::FlxJoyButton button = __it->next();
			{
				HX_STACK_LINE(68)
				button->current = (int)0;
				HX_STACK_LINE(69)
				button->last = (int)0;
			}
;
		}
		HX_STACK_LINE(72)
		int numAxis = this->axis->length;		HX_STACK_VAR(numAxis,"numAxis");
		HX_STACK_LINE(73)
		{
			HX_STACK_LINE(73)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(73)
			while(((_g < numAxis))){
				HX_STACK_LINE(73)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(75)
				this->axis[i] = (int)0;
			}
		}
		HX_STACK_LINE(78)
		this->hat->x = this->hat->y = (int)0;
		HX_STACK_LINE(79)
		this->ball->x = this->ball->y = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystick_obj,reset,(void))

Void FlxJoystick_obj::update( ){
{
		HX_STACK_PUSH("FlxJoystick::update","org/flixel/system/input/FlxJoystick.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(49)
		for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoyButton > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoyButton >(this->buttons->iterator());  __it->hasNext(); ){
			::org::flixel::system::input::FlxJoyButton button = __it->next();
			{
				HX_STACK_LINE(52)
				if (((bool((button->last == (int)-1)) && bool((button->current == (int)-1))))){
					HX_STACK_LINE(53)
					button->current = (int)0;
				}
				else{
					HX_STACK_LINE(56)
					if (((bool((button->last == (int)2)) && bool((button->current == (int)2))))){
						HX_STACK_LINE(57)
						button->current = (int)1;
					}
				}
				HX_STACK_LINE(60)
				button->last = button->current;
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystick_obj,update,(void))

::org::flixel::system::input::FlxJoyButton FlxJoystick_obj::getButton( int buttonID){
	HX_STACK_PUSH("FlxJoystick::getButton","org/flixel/system/input/FlxJoystick.hx",35);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buttonID,"buttonID");
	HX_STACK_LINE(36)
	::org::flixel::system::input::FlxJoyButton joyButton = this->buttons->get(buttonID);		HX_STACK_VAR(joyButton,"joyButton");
	HX_STACK_LINE(37)
	if (((joyButton == null()))){
		HX_STACK_LINE(39)
		joyButton = ::org::flixel::system::input::FlxJoyButton_obj::__new(buttonID,null(),null());
		HX_STACK_LINE(40)
		this->buttons->set(buttonID,joyButton);
	}
	HX_STACK_LINE(42)
	return joyButton;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystick_obj,getButton,return )


FlxJoystick_obj::FlxJoystick_obj()
{
}

void FlxJoystick_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxJoystick);
	HX_MARK_MEMBER_NAME(deadZone,"deadZone");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(ball,"ball");
	HX_MARK_MEMBER_NAME(hat,"hat");
	HX_MARK_MEMBER_NAME(axis,"axis");
	HX_MARK_MEMBER_NAME(buttons,"buttons");
	HX_MARK_END_CLASS();
}

void FlxJoystick_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(deadZone,"deadZone");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(ball,"ball");
	HX_VISIT_MEMBER_NAME(hat,"hat");
	HX_VISIT_MEMBER_NAME(axis,"axis");
	HX_VISIT_MEMBER_NAME(buttons,"buttons");
}

Dynamic FlxJoystick_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"hat") ) { return hat; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ball") ) { return ball; }
		if (HX_FIELD_EQ(inName,"axis") ) { return axis; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getAxis") ) { return getAxis_dyn(); }
		if (HX_FIELD_EQ(inName,"pressed") ) { return pressed_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"buttons") ) { return buttons; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"anyInput") ) { return anyInput_dyn(); }
		if (HX_FIELD_EQ(inName,"deadZone") ) { return deadZone; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"anyButton") ) { return anyButton_dyn(); }
		if (HX_FIELD_EQ(inName,"getButton") ) { return getButton_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"justPressed") ) { return justPressed_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"justReleased") ) { return justReleased_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxJoystick_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"hat") ) { hat=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ball") ) { ball=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"axis") ) { axis=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"buttons") ) { buttons=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"deadZone") ) { deadZone=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxJoystick_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("deadZone"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("ball"));
	outFields->push(HX_CSTRING("hat"));
	outFields->push(HX_CSTRING("axis"));
	outFields->push(HX_CSTRING("buttons"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("anyInput"),
	HX_CSTRING("anyButton"),
	HX_CSTRING("getAxis"),
	HX_CSTRING("justReleased"),
	HX_CSTRING("justPressed"),
	HX_CSTRING("pressed"),
	HX_CSTRING("destroy"),
	HX_CSTRING("reset"),
	HX_CSTRING("update"),
	HX_CSTRING("getButton"),
	HX_CSTRING("deadZone"),
	HX_CSTRING("id"),
	HX_CSTRING("ball"),
	HX_CSTRING("hat"),
	HX_CSTRING("axis"),
	HX_CSTRING("buttons"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxJoystick_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxJoystick_obj::__mClass,"__mClass");
};

Class FlxJoystick_obj::__mClass;

void FlxJoystick_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.input.FlxJoystick"), hx::TCanCast< FlxJoystick_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxJoystick_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input
