#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_JoystickEvent
#include <native/events/JoystickEvent.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
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
#ifndef INCLUDED_org_flixel_system_input_FlxJoystickManager
#include <org/flixel/system/input/FlxJoystickManager.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_IFlxInput
#include <org/flixel/system/input/IFlxInput.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace input{

Void FlxJoystickManager_obj::__construct()
{
HX_STACK_PUSH("FlxJoystickManager::new","org/flixel/system/input/FlxJoystickManager.hx",36);
{
	HX_STACK_LINE(37)
	this->joysticks = ::IntHash_obj::__new();
	HX_STACK_LINE(38)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("axisMove"),this->handleAxisMove_dyn(),null(),null(),null());
	HX_STACK_LINE(39)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("ballMove"),this->handleBallMove_dyn(),null(),null(),null());
	HX_STACK_LINE(40)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("buttonDown"),this->handleButtonDown_dyn(),null(),null(),null());
	HX_STACK_LINE(41)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("buttonUp"),this->handleButtonUp_dyn(),null(),null(),null());
	HX_STACK_LINE(42)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("hatMove"),this->handleHatMove_dyn(),null(),null(),null());
}
;
	return null();
}

FlxJoystickManager_obj::~FlxJoystickManager_obj() { }

Dynamic FlxJoystickManager_obj::__CreateEmpty() { return  new FlxJoystickManager_obj; }
hx::ObjectPtr< FlxJoystickManager_obj > FlxJoystickManager_obj::__new()
{  hx::ObjectPtr< FlxJoystickManager_obj > result = new FlxJoystickManager_obj();
	result->__construct();
	return result;}

Dynamic FlxJoystickManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxJoystickManager_obj > result = new FlxJoystickManager_obj();
	result->__construct();
	return result;}

hx::Object *FlxJoystickManager_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::org::flixel::system::input::IFlxInput_obj)) return operator ::org::flixel::system::input::IFlxInput_obj *();
	return super::__ToInterface(inType);
}

::String FlxJoystickManager_obj::toString( ){
	HX_STACK_PUSH("FlxJoystickManager::toString","org/flixel/system/input/FlxJoystickManager.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_LINE(193)
	return HX_CSTRING("FlxJoyStickManager");
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,toString,return )

Void FlxJoystickManager_obj::onFocusLost( ){
{
		HX_STACK_PUSH("FlxJoystickManager::onFocusLost","org/flixel/system/input/FlxJoystickManager.hx",188);
		HX_STACK_THIS(this);
		HX_STACK_LINE(188)
		this->reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,onFocusLost,(void))

Void FlxJoystickManager_obj::onFocus( ){
{
		HX_STACK_PUSH("FlxJoystickManager::onFocus","org/flixel/system/input/FlxJoystickManager.hx",183);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,onFocus,(void))

Float FlxJoystickManager_obj::set_deadZone( Float DeadZone){
	HX_STACK_PUSH("FlxJoystickManager::set_deadZone","org/flixel/system/input/FlxJoystickManager.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_ARG(DeadZone,"DeadZone");
	HX_STACK_LINE(174)
	this->globalDeadZone = DeadZone;
	HX_STACK_LINE(175)
	for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoystick > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoystick >(this->joysticks->iterator());  __it->hasNext(); ){
		::org::flixel::system::input::FlxJoystick joy = __it->next();
		joy->deadZone = DeadZone;
	}
	HX_STACK_LINE(179)
	return this->globalDeadZone;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,set_deadZone,return )

Void FlxJoystickManager_obj::handleHatMove( ::native::events::JoystickEvent FlashEvent){
{
		HX_STACK_PUSH("FlxJoystickManager::handleHatMove","org/flixel/system/input/FlxJoystickManager.hx",160);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(161)
		::org::flixel::system::input::FlxJoystick joy = this->joystick(FlashEvent->device);		HX_STACK_VAR(joy,"joy");
		HX_STACK_LINE(162)
		joy->hat->x = (  (((::Math_obj::abs(FlashEvent->x) < joy->deadZone))) ? Float((int)0) : Float(FlashEvent->x) );
		HX_STACK_LINE(163)
		joy->hat->y = (  (((::Math_obj::abs(FlashEvent->y) < joy->deadZone))) ? Float((int)0) : Float(FlashEvent->y) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,handleHatMove,(void))

Void FlxJoystickManager_obj::handleBallMove( ::native::events::JoystickEvent FlashEvent){
{
		HX_STACK_PUSH("FlxJoystickManager::handleBallMove","org/flixel/system/input/FlxJoystickManager.hx",149);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(150)
		::org::flixel::system::input::FlxJoystick joy = this->joystick(FlashEvent->device);		HX_STACK_VAR(joy,"joy");
		HX_STACK_LINE(151)
		joy->ball->x = (  (((::Math_obj::abs(FlashEvent->x) < joy->deadZone))) ? Float((int)0) : Float(FlashEvent->x) );
		HX_STACK_LINE(152)
		joy->ball->y = (  (((::Math_obj::abs(FlashEvent->y) < joy->deadZone))) ? Float((int)0) : Float(FlashEvent->y) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,handleBallMove,(void))

Void FlxJoystickManager_obj::handleAxisMove( ::native::events::JoystickEvent FlashEvent){
{
		HX_STACK_PUSH("FlxJoystickManager::handleAxisMove","org/flixel/system/input/FlxJoystickManager.hx",139);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(140)
		::org::flixel::system::input::FlxJoystick joy = this->joystick(FlashEvent->device);		HX_STACK_VAR(joy,"joy");
		HX_STACK_LINE(141)
		joy->axis = FlashEvent->axis;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,handleAxisMove,(void))

Void FlxJoystickManager_obj::handleButtonUp( ::native::events::JoystickEvent FlashEvent){
{
		HX_STACK_PUSH("FlxJoystickManager::handleButtonUp","org/flixel/system/input/FlxJoystickManager.hx",125);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(126)
		::org::flixel::system::input::FlxJoystick joy = this->joystick(FlashEvent->device);		HX_STACK_VAR(joy,"joy");
		HX_STACK_LINE(128)
		::org::flixel::system::input::FlxJoyButton object = joy->getButton(FlashEvent->id);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(129)
		if (((object == null()))){
			HX_STACK_LINE(129)
			return null();
		}
		HX_STACK_LINE(130)
		if (((object->current > (int)0))){
			HX_STACK_LINE(130)
			object->current = (int)-1;
		}
		else{
			HX_STACK_LINE(131)
			object->current = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,handleButtonUp,(void))

Void FlxJoystickManager_obj::handleButtonDown( ::native::events::JoystickEvent FlashEvent){
{
		HX_STACK_PUSH("FlxJoystickManager::handleButtonDown","org/flixel/system/input/FlxJoystickManager.hx",111);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(112)
		::org::flixel::system::input::FlxJoystick joy = this->joystick(FlashEvent->device);		HX_STACK_VAR(joy,"joy");
		HX_STACK_LINE(114)
		::org::flixel::system::input::FlxJoyButton o = joy->getButton(FlashEvent->id);		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(115)
		if (((o == null()))){
			HX_STACK_LINE(115)
			return null();
		}
		HX_STACK_LINE(116)
		if (((o->current > (int)0))){
			HX_STACK_LINE(116)
			o->current = (int)1;
		}
		else{
			HX_STACK_LINE(117)
			o->current = (int)2;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,handleButtonDown,(void))

Void FlxJoystickManager_obj::destroy( ){
{
		HX_STACK_PUSH("FlxJoystickManager::destroy","org/flixel/system/input/FlxJoystickManager.hx",96);
		HX_STACK_THIS(this);
		HX_STACK_LINE(97)
		for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoystick > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoystick >(this->joysticks->iterator());  __it->hasNext(); ){
			::org::flixel::system::input::FlxJoystick joy = __it->next();
			joy->destroy();
		}
		HX_STACK_LINE(102)
		this->joysticks = ::IntHash_obj::__new();
		HX_STACK_LINE(103)
		this->numActiveJoysticks = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,destroy,(void))

Void FlxJoystickManager_obj::reset( ){
{
		HX_STACK_PUSH("FlxJoystickManager::reset","org/flixel/system/input/FlxJoystickManager.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_LINE(85)
		for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoystick > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoystick >(this->joysticks->iterator());  __it->hasNext(); ){
			::org::flixel::system::input::FlxJoystick joy = __it->next();
			joy->reset();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,reset,(void))

Void FlxJoystickManager_obj::update( ){
{
		HX_STACK_PUSH("FlxJoystickManager::update","org/flixel/system/input/FlxJoystickManager.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_LINE(74)
		for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoystick > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoystick >(this->joysticks->iterator());  __it->hasNext(); ){
			::org::flixel::system::input::FlxJoystick joy = __it->next();
			joy->update();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,update,(void))

int FlxJoystickManager_obj::getNumActiveJoysticks( ){
	HX_STACK_PUSH("FlxJoystickManager::getNumActiveJoysticks","org/flixel/system/input/FlxJoystickManager.hx",63);
	HX_STACK_THIS(this);
	HX_STACK_LINE(64)
	int count = (int)0;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(65)
	for(::cpp::FastIterator_obj< ::org::flixel::system::input::FlxJoystick > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::input::FlxJoystick >(this->joysticks->iterator());  __it->hasNext(); ){
		::org::flixel::system::input::FlxJoystick joy = __it->next();
		(count)++;
	}
	HX_STACK_LINE(67)
	return count;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxJoystickManager_obj,getNumActiveJoysticks,return )

::org::flixel::system::input::FlxJoystick FlxJoystickManager_obj::joystick( int joystickID){
	HX_STACK_PUSH("FlxJoystickManager::joystick","org/flixel/system/input/FlxJoystickManager.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_ARG(joystickID,"joystickID");
	HX_STACK_LINE(50)
	::org::flixel::system::input::FlxJoystick joy = this->joysticks->get(joystickID);		HX_STACK_VAR(joy,"joy");
	HX_STACK_LINE(51)
	if (((joy == null()))){
		HX_STACK_LINE(53)
		joy = ::org::flixel::system::input::FlxJoystick_obj::__new(joystickID,this->globalDeadZone);
		HX_STACK_LINE(54)
		this->joysticks->set(joystickID,joy);
	}
	HX_STACK_LINE(56)
	return joy;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxJoystickManager_obj,joystick,return )


FlxJoystickManager_obj::FlxJoystickManager_obj()
{
}

void FlxJoystickManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxJoystickManager);
	HX_MARK_MEMBER_NAME(joysticks,"joysticks");
	HX_MARK_MEMBER_NAME(numActiveJoysticks,"numActiveJoysticks");
	HX_MARK_MEMBER_NAME(globalDeadZone,"globalDeadZone");
	HX_MARK_END_CLASS();
}

void FlxJoystickManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(joysticks,"joysticks");
	HX_VISIT_MEMBER_NAME(numActiveJoysticks,"numActiveJoysticks");
	HX_VISIT_MEMBER_NAME(globalDeadZone,"globalDeadZone");
}

Dynamic FlxJoystickManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"joystick") ) { return joystick_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"joysticks") ) { return joysticks; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_deadZone") ) { return set_deadZone_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"handleHatMove") ) { return handleHatMove_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"handleBallMove") ) { return handleBallMove_dyn(); }
		if (HX_FIELD_EQ(inName,"handleAxisMove") ) { return handleAxisMove_dyn(); }
		if (HX_FIELD_EQ(inName,"handleButtonUp") ) { return handleButtonUp_dyn(); }
		if (HX_FIELD_EQ(inName,"globalDeadZone") ) { return globalDeadZone; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"handleButtonDown") ) { return handleButtonDown_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"numActiveJoysticks") ) { return inCallProp ? getNumActiveJoysticks() : numActiveJoysticks; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getNumActiveJoysticks") ) { return getNumActiveJoysticks_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxJoystickManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"joysticks") ) { joysticks=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"globalDeadZone") ) { if (inCallProp) return set_deadZone(inValue);globalDeadZone=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"numActiveJoysticks") ) { numActiveJoysticks=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxJoystickManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("joysticks"));
	outFields->push(HX_CSTRING("numActiveJoysticks"));
	outFields->push(HX_CSTRING("globalDeadZone"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("set_deadZone"),
	HX_CSTRING("handleHatMove"),
	HX_CSTRING("handleBallMove"),
	HX_CSTRING("handleAxisMove"),
	HX_CSTRING("handleButtonUp"),
	HX_CSTRING("handleButtonDown"),
	HX_CSTRING("destroy"),
	HX_CSTRING("reset"),
	HX_CSTRING("update"),
	HX_CSTRING("getNumActiveJoysticks"),
	HX_CSTRING("joystick"),
	HX_CSTRING("joysticks"),
	HX_CSTRING("numActiveJoysticks"),
	HX_CSTRING("globalDeadZone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxJoystickManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxJoystickManager_obj::__mClass,"__mClass");
};

Class FlxJoystickManager_obj::__mClass;

void FlxJoystickManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.input.FlxJoystickManager"), hx::TCanCast< FlxJoystickManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxJoystickManager_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input
