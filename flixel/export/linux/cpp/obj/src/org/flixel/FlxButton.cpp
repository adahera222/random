#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_flixel_FlxBasic
#include <org/flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_org_flixel_FlxButton
#include <org/flixel/FlxButton.h>
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
#ifndef INCLUDED_org_flixel_FlxText
#include <org/flixel/FlxText.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedButton
#include <org/flixel/FlxTypedButton.h>
#endif
namespace org{
namespace flixel{

Void FlxButton_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{
HX_STACK_PUSH("FlxButton::new","org/flixel/FlxButton.hx",28);
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(29)
	super::__construct(X,Y,Label,OnClick);
	HX_STACK_LINE(30)
	if (((Label != null()))){
		HX_STACK_LINE(32)
		this->label = ::org::flixel::FlxText_obj::__new((int)0,(int)0,(int)80,Label,null(),null(),null());
		HX_STACK_LINE(33)
		this->label->__Field(HX_CSTRING("setFormat"),true)(null(),(int)8,(int)3355443,HX_CSTRING("center"),null(),null());
		HX_STACK_LINE(34)
		this->labelOffset = ::org::flixel::FlxPoint_obj::__new((int)-1,(int)3);
	}
}
;
	return null();
}

FlxButton_obj::~FlxButton_obj() { }

Dynamic FlxButton_obj::__CreateEmpty() { return  new FlxButton_obj; }
hx::ObjectPtr< FlxButton_obj > FlxButton_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{  hx::ObjectPtr< FlxButton_obj > result = new FlxButton_obj();
	result->__construct(__o_X,__o_Y,Label,OnClick);
	return result;}

Dynamic FlxButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxButton_obj > result = new FlxButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void FlxButton_obj::resetHelpers( ){
{
		HX_STACK_PUSH("FlxButton::resetHelpers","org/flixel/FlxButton.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_LINE(43)
		this->super::resetHelpers();
		HX_STACK_LINE(44)
		if (((this->label != null()))){
			HX_STACK_LINE(46)
			this->label->__FieldRef(HX_CSTRING("width")) = this->label->__FieldRef(HX_CSTRING("frameWidth")) = ::Std_obj::_int(this->width);
			HX_STACK_LINE(47)
			this->label->__Field(HX_CSTRING("set_size"),true)(this->label->__Field(HX_CSTRING("get_size"),true)());
		}
	}
return null();
}


int FlxButton_obj::NORMAL;

int FlxButton_obj::HIGHLIGHT;

int FlxButton_obj::PRESSED;


FlxButton_obj::FlxButton_obj()
{
}

void FlxButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxButton);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxButton_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxButton_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"NORMAL") ) { return NORMAL; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"PRESSED") ) { return PRESSED; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"HIGHLIGHT") ) { return HIGHLIGHT; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resetHelpers") ) { return resetHelpers_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxButton_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"NORMAL") ) { NORMAL=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"PRESSED") ) { PRESSED=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"HIGHLIGHT") ) { HIGHLIGHT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxButton_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NORMAL"),
	HX_CSTRING("HIGHLIGHT"),
	HX_CSTRING("PRESSED"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("resetHelpers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxButton_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxButton_obj::NORMAL,"NORMAL");
	HX_MARK_MEMBER_NAME(FlxButton_obj::HIGHLIGHT,"HIGHLIGHT");
	HX_MARK_MEMBER_NAME(FlxButton_obj::PRESSED,"PRESSED");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxButton_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxButton_obj::NORMAL,"NORMAL");
	HX_VISIT_MEMBER_NAME(FlxButton_obj::HIGHLIGHT,"HIGHLIGHT");
	HX_VISIT_MEMBER_NAME(FlxButton_obj::PRESSED,"PRESSED");
};

Class FlxButton_obj::__mClass;

void FlxButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxButton"), hx::TCanCast< FlxButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxButton_obj::__boot()
{
	NORMAL= (int)0;
	HIGHLIGHT= (int)1;
	PRESSED= (int)2;
}

} // end namespace org
} // end namespace flixel
