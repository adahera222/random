#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
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
#ifndef INCLUDED_native_events_KeyboardEvent
#include <native/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_text_Font
#include <native/text/Font.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFieldType
#include <native/text/TextFieldType.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
#ifndef INCLUDED_org_flixel_FlxAssets
#include <org/flixel/FlxAssets.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_WatchEntry
#include <org/flixel/system/debug/WatchEntry.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace debug{

Void WatchEntry_obj::__construct(Float Y,Float NameWidth,Float ValueWidth,Dynamic Obj,::String Field,::String Custom)
{
HX_STACK_PUSH("WatchEntry::new","org/flixel/system/debug/WatchEntry.hx",61);
{
	HX_STACK_LINE(62)
	this->editing = false;
	HX_STACK_LINE(64)
	this->object = Obj;
	HX_STACK_LINE(65)
	this->field = Field;
	HX_STACK_LINE(66)
	this->custom = Custom;
	HX_STACK_LINE(68)
	::String fontName = ::nme::installer::Assets_obj::getFont(::org::flixel::FlxAssets_obj::debuggerFont)->fontName;		HX_STACK_VAR(fontName,"fontName");
	HX_STACK_LINE(69)
	this->_whiteText = ::native::text::TextFormat_obj::__new(fontName,(int)12,(int)16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(70)
	this->_blackText = ::native::text::TextFormat_obj::__new(fontName,(int)12,(int)0,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(72)
	this->nameDisplay = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(73)
	this->nameDisplay->set_y(Y);
	HX_STACK_LINE(74)
	this->nameDisplay->set_multiline(false);
	HX_STACK_LINE(75)
	this->nameDisplay->set_selectable(true);
	HX_STACK_LINE(76)
	this->nameDisplay->set_defaultTextFormat(this->_whiteText);
	HX_STACK_LINE(78)
	this->valueDisplay = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(79)
	this->valueDisplay->set_y(Y);
	HX_STACK_LINE(80)
	this->valueDisplay->set_height((int)15);
	HX_STACK_LINE(81)
	this->valueDisplay->set_multiline(false);
	HX_STACK_LINE(82)
	this->valueDisplay->set_selectable(true);
	HX_STACK_LINE(83)
	this->valueDisplay->doubleClickEnabled = true;
	HX_STACK_LINE(84)
	this->valueDisplay->addEventListener(::native::events::KeyboardEvent_obj::KEY_UP,this->onKeyUp_dyn(),null(),null(),null());
	HX_STACK_LINE(85)
	this->valueDisplay->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(86)
	this->valueDisplay->set_background(false);
	HX_STACK_LINE(87)
	this->valueDisplay->set_backgroundColor((int)16777215);
	HX_STACK_LINE(88)
	this->valueDisplay->set_defaultTextFormat(this->_whiteText);
	HX_STACK_LINE(90)
	this->updateWidth(NameWidth,ValueWidth);
}
;
	return null();
}

WatchEntry_obj::~WatchEntry_obj() { }

Dynamic WatchEntry_obj::__CreateEmpty() { return  new WatchEntry_obj; }
hx::ObjectPtr< WatchEntry_obj > WatchEntry_obj::__new(Float Y,Float NameWidth,Float ValueWidth,Dynamic Obj,::String Field,::String Custom)
{  hx::ObjectPtr< WatchEntry_obj > result = new WatchEntry_obj();
	result->__construct(Y,NameWidth,ValueWidth,Obj,Field,Custom);
	return result;}

Dynamic WatchEntry_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WatchEntry_obj > result = new WatchEntry_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void WatchEntry_obj::doneEditing( ){
{
		HX_STACK_PUSH("WatchEntry::doneEditing","org/flixel/system/debug/WatchEntry.hx",211);
		HX_STACK_THIS(this);
		HX_STACK_LINE(212)
		this->valueDisplay->set_type(::native::text::TextFieldType_obj::DYNAMIC_dyn());
		HX_STACK_LINE(213)
		this->valueDisplay->setTextFormat(this->_whiteText,null(),null());
		HX_STACK_LINE(214)
		this->valueDisplay->set_defaultTextFormat(this->_whiteText);
		HX_STACK_LINE(215)
		this->valueDisplay->set_background(false);
		HX_STACK_LINE(216)
		this->editing = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WatchEntry_obj,doneEditing,(void))

Void WatchEntry_obj::submit( ){
{
		HX_STACK_PUSH("WatchEntry::submit","org/flixel/system/debug/WatchEntry.hx",202);
		HX_STACK_THIS(this);
		HX_STACK_LINE(203)
		{
			HX_STACK_LINE(203)
			Dynamic o = this->object;		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(203)
			if (((o != null()))){
				HX_STACK_LINE(203)
				o->__SetField(this->field,this->valueDisplay->get_text(),true);
			}
		}
		HX_STACK_LINE(204)
		this->doneEditing();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WatchEntry_obj,submit,(void))

Void WatchEntry_obj::cancel( ){
{
		HX_STACK_PUSH("WatchEntry::cancel","org/flixel/system/debug/WatchEntry.hx",193);
		HX_STACK_THIS(this);
		HX_STACK_LINE(194)
		this->valueDisplay->set_text(this->oldValue->toString());
		HX_STACK_LINE(195)
		this->doneEditing();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WatchEntry_obj,cancel,(void))

Void WatchEntry_obj::onKeyUp( ::native::events::KeyboardEvent FlashEvent){
{
		HX_STACK_PUSH("WatchEntry::onKeyUp","org/flixel/system/debug/WatchEntry.hx",175);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(175)
		if (((bool((bool((FlashEvent->keyCode == (int)13)) || bool((FlashEvent->keyCode == (int)9)))) || bool((FlashEvent->keyCode == (int)27))))){
			HX_STACK_LINE(177)
			if (((FlashEvent->keyCode == (int)27))){
				HX_STACK_LINE(179)
				this->cancel();
			}
			else{
				HX_STACK_LINE(183)
				this->submit();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WatchEntry_obj,onKeyUp,(void))

Void WatchEntry_obj::onMouseUp( ::native::events::MouseEvent FlashEvent){
{
		HX_STACK_PUSH("WatchEntry::onMouseUp","org/flixel/system/debug/WatchEntry.hx",160);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(161)
		this->editing = true;
		struct _Function_1_1{
			inline static Dynamic Block( ::org::flixel::system::debug::WatchEntry_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/system/debug/WatchEntry.hx",162);
				{
					HX_STACK_LINE(162)
					Dynamic o = __this->object;		HX_STACK_VAR(o,"o");
					HX_STACK_LINE(162)
					return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(__this->field,true)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(162)
		this->oldValue = _Function_1_1::Block(this);
		HX_STACK_LINE(163)
		this->valueDisplay->set_type(::native::text::TextFieldType_obj::INPUT_dyn());
		HX_STACK_LINE(164)
		this->valueDisplay->setTextFormat(this->_blackText,null(),null());
		HX_STACK_LINE(165)
		this->valueDisplay->set_background(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WatchEntry_obj,onMouseUp,(void))

bool WatchEntry_obj::updateValue( ){
	HX_STACK_PUSH("WatchEntry::updateValue","org/flixel/system/debug/WatchEntry.hx",146);
	HX_STACK_THIS(this);
	HX_STACK_LINE(147)
	if ((this->editing)){
		HX_STACK_LINE(148)
		return false;
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::org::flixel::system::debug::WatchEntry_obj *__this){
			HX_STACK_PUSH("*::closure","org/flixel/system/debug/WatchEntry.hx",151);
			{
				HX_STACK_LINE(151)
				Dynamic o = __this->object;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(151)
				return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(__this->field,true)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(151)
	this->valueDisplay->set_text(::Std_obj::string(_Function_1_1::Block(this)));
	HX_STACK_LINE(152)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(WatchEntry_obj,updateValue,return )

Void WatchEntry_obj::updateWidth( Float NameWidth,Float ValueWidth){
{
		HX_STACK_PUSH("WatchEntry::updateWidth","org/flixel/system/debug/WatchEntry.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(NameWidth,"NameWidth");
		HX_STACK_ARG(ValueWidth,"ValueWidth");
		HX_STACK_LINE(125)
		this->nameDisplay->set_width(NameWidth);
		HX_STACK_LINE(126)
		this->valueDisplay->set_width(ValueWidth);
		HX_STACK_LINE(127)
		if (((this->custom != null()))){
			HX_STACK_LINE(128)
			this->nameDisplay->set_text(this->custom);
		}
		else{
			HX_STACK_LINE(133)
			this->nameDisplay->set_text(HX_CSTRING(""));
			HX_STACK_LINE(134)
			if (((NameWidth > (int)120))){
				struct _Function_3_1{
					inline static ::String Block( ::org::flixel::system::debug::WatchEntry_obj *__this,Float &NameWidth){
						HX_STACK_PUSH("*::closure","org/flixel/system/debug/WatchEntry.hx",136);
						{
							HX_STACK_LINE(136)
							::String s = ::Type_obj::getClassName(::Type_obj::getClass(__this->object));		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(136)
							if (((s != null()))){
								HX_STACK_LINE(136)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(136)
								if (((NameWidth < (int)240))){
									HX_STACK_LINE(136)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(136)
							return s;
						}
						return null();
					}
				};
				HX_STACK_LINE(135)
				this->nameDisplay->appendText((_Function_3_1::Block(this,NameWidth) + HX_CSTRING(".")));
			}
			HX_STACK_LINE(138)
			this->nameDisplay->appendText(this->field);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(WatchEntry_obj,updateWidth,(void))

Void WatchEntry_obj::setY( Float Y){
{
		HX_STACK_PUSH("WatchEntry::setY","org/flixel/system/debug/WatchEntry.hx",115);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Y,"Y");
		HX_STACK_LINE(116)
		this->nameDisplay->set_y(Y);
		HX_STACK_LINE(117)
		this->valueDisplay->set_y(Y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WatchEntry_obj,setY,(void))

Void WatchEntry_obj::destroy( ){
{
		HX_STACK_PUSH("WatchEntry::destroy","org/flixel/system/debug/WatchEntry.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_LINE(98)
		this->object = null();
		HX_STACK_LINE(99)
		this->oldValue = null();
		HX_STACK_LINE(100)
		this->nameDisplay = null();
		HX_STACK_LINE(101)
		this->field = null();
		HX_STACK_LINE(102)
		this->custom = null();
		HX_STACK_LINE(103)
		if (((this->valueDisplay != null()))){
			HX_STACK_LINE(105)
			this->valueDisplay->removeEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null());
			HX_STACK_LINE(106)
			this->valueDisplay->removeEventListener(::native::events::KeyboardEvent_obj::KEY_UP,this->onKeyUp_dyn(),null());
			HX_STACK_LINE(107)
			this->valueDisplay = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WatchEntry_obj,destroy,(void))


WatchEntry_obj::WatchEntry_obj()
{
}

void WatchEntry_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WatchEntry);
	HX_MARK_MEMBER_NAME(_blackText,"_blackText");
	HX_MARK_MEMBER_NAME(_whiteText,"_whiteText");
	HX_MARK_MEMBER_NAME(oldValue,"oldValue");
	HX_MARK_MEMBER_NAME(editing,"editing");
	HX_MARK_MEMBER_NAME(valueDisplay,"valueDisplay");
	HX_MARK_MEMBER_NAME(nameDisplay,"nameDisplay");
	HX_MARK_MEMBER_NAME(custom,"custom");
	HX_MARK_MEMBER_NAME(field,"field");
	HX_MARK_MEMBER_NAME(object,"object");
	HX_MARK_END_CLASS();
}

void WatchEntry_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_blackText,"_blackText");
	HX_VISIT_MEMBER_NAME(_whiteText,"_whiteText");
	HX_VISIT_MEMBER_NAME(oldValue,"oldValue");
	HX_VISIT_MEMBER_NAME(editing,"editing");
	HX_VISIT_MEMBER_NAME(valueDisplay,"valueDisplay");
	HX_VISIT_MEMBER_NAME(nameDisplay,"nameDisplay");
	HX_VISIT_MEMBER_NAME(custom,"custom");
	HX_VISIT_MEMBER_NAME(field,"field");
	HX_VISIT_MEMBER_NAME(object,"object");
}

Dynamic WatchEntry_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"setY") ) { return setY_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"field") ) { return field; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"submit") ) { return submit_dyn(); }
		if (HX_FIELD_EQ(inName,"cancel") ) { return cancel_dyn(); }
		if (HX_FIELD_EQ(inName,"custom") ) { return custom; }
		if (HX_FIELD_EQ(inName,"object") ) { return object; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"editing") ) { return editing; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"oldValue") ) { return oldValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_blackText") ) { return _blackText; }
		if (HX_FIELD_EQ(inName,"_whiteText") ) { return _whiteText; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"doneEditing") ) { return doneEditing_dyn(); }
		if (HX_FIELD_EQ(inName,"updateValue") ) { return updateValue_dyn(); }
		if (HX_FIELD_EQ(inName,"updateWidth") ) { return updateWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nameDisplay") ) { return nameDisplay; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"valueDisplay") ) { return valueDisplay; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WatchEntry_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"field") ) { field=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"custom") ) { custom=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"object") ) { object=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"editing") ) { editing=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"oldValue") ) { oldValue=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_blackText") ) { _blackText=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_whiteText") ) { _whiteText=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nameDisplay") ) { nameDisplay=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"valueDisplay") ) { valueDisplay=inValue.Cast< ::native::text::TextField >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WatchEntry_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_blackText"));
	outFields->push(HX_CSTRING("_whiteText"));
	outFields->push(HX_CSTRING("oldValue"));
	outFields->push(HX_CSTRING("editing"));
	outFields->push(HX_CSTRING("valueDisplay"));
	outFields->push(HX_CSTRING("nameDisplay"));
	outFields->push(HX_CSTRING("custom"));
	outFields->push(HX_CSTRING("field"));
	outFields->push(HX_CSTRING("object"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doneEditing"),
	HX_CSTRING("submit"),
	HX_CSTRING("cancel"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("updateValue"),
	HX_CSTRING("updateWidth"),
	HX_CSTRING("setY"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_blackText"),
	HX_CSTRING("_whiteText"),
	HX_CSTRING("oldValue"),
	HX_CSTRING("editing"),
	HX_CSTRING("valueDisplay"),
	HX_CSTRING("nameDisplay"),
	HX_CSTRING("custom"),
	HX_CSTRING("field"),
	HX_CSTRING("object"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WatchEntry_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WatchEntry_obj::__mClass,"__mClass");
};

Class WatchEntry_obj::__mClass;

void WatchEntry_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.debug.WatchEntry"), hx::TCanCast< WatchEntry_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void WatchEntry_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace debug
