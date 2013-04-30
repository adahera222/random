#include <hxcpp.h>

#ifndef INCLUDED_MenuState
#include <MenuState.h>
#endif
#ifndef INCLUDED_org_flixel_FlxBasic
#include <org/flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_org_flixel_FlxG
#include <org/flixel/FlxG.h>
#endif
#ifndef INCLUDED_org_flixel_FlxGroup
#include <org/flixel/FlxGroup.h>
#endif
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSprite
#include <org/flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_org_flixel_FlxState
#include <org/flixel/FlxState.h>
#endif
#ifndef INCLUDED_org_flixel_FlxText
#include <org/flixel/FlxText.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedGroup
#include <org/flixel/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMouse
#include <org/flixel/system/input/FlxMouse.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_IFlxInput
#include <org/flixel/system/input/IFlxInput.h>
#endif

Void MenuState_obj::__construct()
{
HX_STACK_PUSH("MenuState::new","MenuState.hx",15);
{
	HX_STACK_LINE(15)
	super::__construct();
}
;
	return null();
}

MenuState_obj::~MenuState_obj() { }

Dynamic MenuState_obj::__CreateEmpty() { return  new MenuState_obj; }
hx::ObjectPtr< MenuState_obj > MenuState_obj::__new()
{  hx::ObjectPtr< MenuState_obj > result = new MenuState_obj();
	result->__construct();
	return result;}

Dynamic MenuState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuState_obj > result = new MenuState_obj();
	result->__construct();
	return result;}

Void MenuState_obj::update( ){
{
		HX_STACK_PUSH("MenuState::update","MenuState.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_LINE(37)
		this->super::update();
	}
return null();
}


Void MenuState_obj::destroy( ){
{
		HX_STACK_PUSH("MenuState::destroy","MenuState.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_LINE(32)
		this->super::destroy();
	}
return null();
}


Void MenuState_obj::create( ){
{
		HX_STACK_PUSH("MenuState::create","MenuState.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_LINE(20)
		::org::flixel::FlxG_obj::set_bgColor((int)-15524837);
		HX_STACK_LINE(25)
		::org::flixel::FlxG_obj::mouse->show(null(),null(),null(),null());
		HX_STACK_LINE(28)
		this->add(::org::flixel::FlxText_obj::__new((int)0,(int)0,(int)100,HX_CSTRING("Hello World!"),null(),null(),null()));
	}
return null();
}



MenuState_obj::MenuState_obj()
{
}

void MenuState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MenuState);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MenuState_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MenuState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuState_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("create"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuState_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuState_obj::__mClass,"__mClass");
};

Class MenuState_obj::__mClass;

void MenuState_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("MenuState"), hx::TCanCast< MenuState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MenuState_obj::__boot()
{
}

