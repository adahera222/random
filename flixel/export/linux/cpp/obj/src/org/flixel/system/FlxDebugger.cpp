#include <hxcpp.h>

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
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_native_text_Font
#include <native/text/Font.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
#ifndef INCLUDED_native_ui_Mouse
#include <native/ui/Mouse.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
#ifndef INCLUDED_org_flixel_FlxAssets
#include <org/flixel/FlxAssets.h>
#endif
#ifndef INCLUDED_org_flixel_FlxG
#include <org/flixel/FlxG.h>
#endif
#ifndef INCLUDED_org_flixel_FlxGame
#include <org/flixel/FlxGame.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
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
#ifndef INCLUDED_org_flixel_system_debug_Perf
#include <org/flixel/system/debug/Perf.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_VCR
#include <org/flixel/system/debug/VCR.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_Vis
#include <org/flixel/system/debug/Vis.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_Watch
#include <org/flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMouse
#include <org/flixel/system/input/FlxMouse.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_IFlxInput
#include <org/flixel/system/input/IFlxInput.h>
#endif
namespace org{
namespace flixel{
namespace system{

Void FlxDebugger_obj::__construct(Float Width,Float Height)
{
HX_STACK_PUSH("FlxDebugger::new","org/flixel/system/FlxDebugger.hx",77);
{
	HX_STACK_LINE(78)
	super::__construct();
	HX_STACK_LINE(79)
	this->set_visible(false);
	HX_STACK_LINE(80)
	this->hasMouse = false;
	HX_STACK_LINE(81)
	this->_screen = ::native::geom::Point_obj::__new(Width,Height);
	HX_STACK_LINE(86)
	::native::display::Sprite bg = ::native::display::Sprite_obj::__new();		HX_STACK_VAR(bg,"bg");
	HX_STACK_LINE(87)
	bg->get_graphics()->beginFill((int)0,(Float((int)127) / Float((int)255)));
	HX_STACK_LINE(88)
	bg->get_graphics()->drawRect((int)0,(int)0,::Std_obj::_int(Width),(int)15);
	HX_STACK_LINE(89)
	bg->get_graphics()->endFill();
	HX_STACK_LINE(90)
	this->addChild(bg);
	HX_STACK_LINE(93)
	::native::text::TextField txt = ::native::text::TextField_obj::__new();		HX_STACK_VAR(txt,"txt");
	HX_STACK_LINE(94)
	txt->set_x((int)2);
	HX_STACK_LINE(95)
	txt->set_width((int)160);
	HX_STACK_LINE(96)
	txt->set_height((int)16);
	HX_STACK_LINE(97)
	txt->set_selectable(false);
	HX_STACK_LINE(98)
	txt->set_multiline(false);
	HX_STACK_LINE(99)
	txt->set_defaultTextFormat(::native::text::TextFormat_obj::__new(::nme::installer::Assets_obj::getFont(::org::flixel::FlxAssets_obj::debuggerFont)->fontName,(int)12,(int)16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
	HX_STACK_LINE(100)
	::String str = ::org::flixel::FlxG_obj::getLibraryName();		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(101)
	if ((::org::flixel::FlxG_obj::debug)){
		HX_STACK_LINE(102)
		hx::AddEq(str,HX_CSTRING(" [debug]"));
	}
	else{
		HX_STACK_LINE(106)
		hx::AddEq(str,HX_CSTRING(" [release]"));
	}
	HX_STACK_LINE(109)
	txt->set_text(str);
	HX_STACK_LINE(110)
	this->addChild(txt);
	HX_STACK_LINE(112)
	this->_gutter = (int)8;
	HX_STACK_LINE(113)
	::native::geom::Rectangle screenBounds = ::native::geom::Rectangle_obj::__new(this->_gutter,((int)15 + (Float(this->_gutter) / Float((int)2))),(this->_screen->x - (this->_gutter * (int)2)),((this->_screen->y - (this->_gutter * 1.5)) - (int)15));		HX_STACK_VAR(screenBounds,"screenBounds");
	HX_STACK_LINE(115)
	this->log = ::org::flixel::system::debug::Log_obj::__new(HX_CSTRING("log"),(int)0,(int)0,true,screenBounds,null(),null());
	HX_STACK_LINE(116)
	this->addChild(this->log);
	HX_STACK_LINE(118)
	this->watch = ::org::flixel::system::debug::Watch_obj::__new(HX_CSTRING("watch"),(int)0,(int)0,true,screenBounds,null(),null());
	HX_STACK_LINE(119)
	this->addChild(this->watch);
	HX_STACK_LINE(121)
	this->perf = ::org::flixel::system::debug::Perf_obj::__new(HX_CSTRING("stats"),(int)0,(int)0,false,screenBounds,null(),null());
	HX_STACK_LINE(122)
	this->addChild(this->perf);
	HX_STACK_LINE(124)
	this->vcr = ::org::flixel::system::debug::VCR_obj::__new();
	HX_STACK_LINE(125)
	this->vcr->set_x((Float(((Width - (Float(this->vcr->get_width()) / Float((int)2))))) / Float((int)2)));
	HX_STACK_LINE(126)
	this->vcr->set_y((int)2);
	HX_STACK_LINE(127)
	this->addChild(this->vcr);
	HX_STACK_LINE(129)
	this->vis = ::org::flixel::system::debug::Vis_obj::__new();
	HX_STACK_LINE(130)
	this->vis->set_x(((Width - this->vis->get_width()) - (int)4));
	HX_STACK_LINE(131)
	this->vis->set_y((int)2);
	HX_STACK_LINE(132)
	this->addChild(this->vis);
	HX_STACK_LINE(134)
	this->setLayout((int)0);
	HX_STACK_LINE(137)
	this->addEventListener(::native::events::MouseEvent_obj::MOUSE_OVER,this->onMouseOver_dyn(),null(),null(),null());
	HX_STACK_LINE(138)
	this->addEventListener(::native::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null(),null(),null());
}
;
	return null();
}

FlxDebugger_obj::~FlxDebugger_obj() { }

Dynamic FlxDebugger_obj::__CreateEmpty() { return  new FlxDebugger_obj; }
hx::ObjectPtr< FlxDebugger_obj > FlxDebugger_obj::__new(Float Width,Float Height)
{  hx::ObjectPtr< FlxDebugger_obj > result = new FlxDebugger_obj();
	result->__construct(Width,Height);
	return result;}

Dynamic FlxDebugger_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxDebugger_obj > result = new FlxDebugger_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void FlxDebugger_obj::resetLayout( ){
{
		HX_STACK_PUSH("FlxDebugger::resetLayout","org/flixel/system/FlxDebugger.hx",222);
		HX_STACK_THIS(this);
		HX_STACK_LINE(222)
		switch( (int)(this->_layout)){
			case (int)1: {
				HX_STACK_LINE(226)
				this->log->resize((Float(this->_screen->x) / Float((int)4)),(int)68);
				HX_STACK_LINE(227)
				this->log->reposition((int)0,this->_screen->y);
				HX_STACK_LINE(228)
				this->watch->resize((Float(this->_screen->x) / Float((int)4)),(int)68);
				HX_STACK_LINE(229)
				this->watch->reposition(this->_screen->x,this->_screen->y);
				HX_STACK_LINE(230)
				this->perf->reposition(this->_screen->x,(int)0);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(232)
				this->log->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)2)));
				HX_STACK_LINE(233)
				this->log->reposition((int)0,this->_screen->y);
				HX_STACK_LINE(234)
				this->watch->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)2)));
				HX_STACK_LINE(235)
				this->watch->reposition(this->_screen->x,this->_screen->y);
				HX_STACK_LINE(236)
				this->perf->reposition(this->_screen->x,(int)0);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(238)
				this->log->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(239)
				this->log->reposition((int)0,(int)0);
				HX_STACK_LINE(240)
				this->watch->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(241)
				this->watch->reposition(this->_screen->x,(int)0);
				HX_STACK_LINE(242)
				this->perf->reposition(this->_screen->x,this->_screen->y);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(244)
				this->log->resize((Float(this->_screen->x) / Float((int)3)),(Float((((this->_screen->y - (int)15) - (this->_gutter * 2.5)))) / Float((int)2)));
				HX_STACK_LINE(245)
				this->log->reposition((int)0,(int)0);
				HX_STACK_LINE(246)
				this->watch->resize((Float(this->_screen->x) / Float((int)3)),(Float((((this->_screen->y - (int)15) - (this->_gutter * 2.5)))) / Float((int)2)));
				HX_STACK_LINE(247)
				this->watch->reposition((int)0,this->_screen->y);
				HX_STACK_LINE(248)
				this->perf->reposition(this->_screen->x,(int)0);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(250)
				this->log->resize((Float(this->_screen->x) / Float((int)3)),(Float((((this->_screen->y - (int)15) - (this->_gutter * 2.5)))) / Float((int)2)));
				HX_STACK_LINE(251)
				this->log->reposition(this->_screen->x,(int)0);
				HX_STACK_LINE(252)
				this->watch->resize((Float(this->_screen->x) / Float((int)3)),(Float((((this->_screen->y - (int)15) - (this->_gutter * 2.5)))) / Float((int)2)));
				HX_STACK_LINE(253)
				this->watch->reposition(this->_screen->x,this->_screen->y);
				HX_STACK_LINE(254)
				this->perf->reposition((int)0,(int)0);
			}
			;break;
			case (int)0: {
				HX_STACK_LINE(256)
				this->log->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(257)
				this->log->reposition((int)0,this->_screen->y);
				HX_STACK_LINE(258)
				this->watch->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(259)
				this->watch->reposition(this->_screen->x,this->_screen->y);
				HX_STACK_LINE(260)
				this->perf->reposition(this->_screen->x,(int)0);
			}
			;break;
			default: {
				HX_STACK_LINE(262)
				this->log->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(263)
				this->log->reposition((int)0,this->_screen->y);
				HX_STACK_LINE(264)
				this->watch->resize((Float(((this->_screen->x - (this->_gutter * (int)3)))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(265)
				this->watch->reposition(this->_screen->x,this->_screen->y);
				HX_STACK_LINE(266)
				this->perf->reposition(this->_screen->x,(int)0);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,resetLayout,(void))

Void FlxDebugger_obj::setLayout( int Layout){
{
		HX_STACK_PUSH("FlxDebugger::setLayout","org/flixel/system/FlxDebugger.hx",212);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Layout,"Layout");
		HX_STACK_LINE(213)
		this->_layout = Layout;
		HX_STACK_LINE(214)
		this->resetLayout();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxDebugger_obj,setLayout,(void))

Void FlxDebugger_obj::onMouseOut( ::native::events::MouseEvent E){
{
		HX_STACK_PUSH("FlxDebugger::onMouseOut","org/flixel/system/FlxDebugger.hx",199);
		HX_STACK_THIS(this);
		HX_STACK_ARG(E,"E");
		HX_STACK_LINE(200)
		this->hasMouse = false;
		HX_STACK_LINE(202)
		if (((bool(!(::org::flixel::FlxG_obj::mouse->useSystemCursor)) && bool(!(::org::flixel::FlxG_obj::_game->_debugger->vcr->paused))))){
			HX_STACK_LINE(203)
			::native::ui::Mouse_obj::hide();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxDebugger_obj,onMouseOut,(void))

Void FlxDebugger_obj::onMouseOver( ::native::events::MouseEvent E){
{
		HX_STACK_PUSH("FlxDebugger::onMouseOver","org/flixel/system/FlxDebugger.hx",187);
		HX_STACK_THIS(this);
		HX_STACK_ARG(E,"E");
		HX_STACK_LINE(188)
		this->hasMouse = true;
		HX_STACK_LINE(190)
		::native::ui::Mouse_obj::show();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxDebugger_obj,onMouseOver,(void))

Void FlxDebugger_obj::destroy( ){
{
		HX_STACK_PUSH("FlxDebugger::destroy","org/flixel/system/FlxDebugger.hx",145);
		HX_STACK_THIS(this);
		HX_STACK_LINE(146)
		this->_screen = null();
		HX_STACK_LINE(147)
		if (((this->log != null()))){
			HX_STACK_LINE(149)
			this->removeChild(this->log);
			HX_STACK_LINE(150)
			this->log->destroy();
			HX_STACK_LINE(151)
			this->log = null();
		}
		HX_STACK_LINE(153)
		if (((this->watch != null()))){
			HX_STACK_LINE(155)
			this->removeChild(this->watch);
			HX_STACK_LINE(156)
			this->watch->destroy();
			HX_STACK_LINE(157)
			this->watch = null();
		}
		HX_STACK_LINE(159)
		if (((this->perf != null()))){
			HX_STACK_LINE(161)
			this->removeChild(this->perf);
			HX_STACK_LINE(162)
			this->perf->destroy();
			HX_STACK_LINE(163)
			this->perf = null();
		}
		HX_STACK_LINE(165)
		if (((this->vcr != null()))){
			HX_STACK_LINE(167)
			this->removeChild(this->vcr);
			HX_STACK_LINE(168)
			this->vcr->destroy();
			HX_STACK_LINE(169)
			this->vcr = null();
		}
		HX_STACK_LINE(171)
		if (((this->vis != null()))){
			HX_STACK_LINE(173)
			this->removeChild(this->vis);
			HX_STACK_LINE(174)
			this->vis->destroy();
			HX_STACK_LINE(175)
			this->vis = null();
		}
		HX_STACK_LINE(178)
		this->removeEventListener(::native::events::MouseEvent_obj::MOUSE_OVER,this->onMouseOver_dyn(),null());
		HX_STACK_LINE(179)
		this->removeEventListener(::native::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,destroy,(void))


FlxDebugger_obj::FlxDebugger_obj()
{
}

void FlxDebugger_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxDebugger);
	HX_MARK_MEMBER_NAME(_gutter,"_gutter");
	HX_MARK_MEMBER_NAME(_screen,"_screen");
	HX_MARK_MEMBER_NAME(_layout,"_layout");
	HX_MARK_MEMBER_NAME(hasMouse,"hasMouse");
	HX_MARK_MEMBER_NAME(vis,"vis");
	HX_MARK_MEMBER_NAME(vcr,"vcr");
	HX_MARK_MEMBER_NAME(watch,"watch");
	HX_MARK_MEMBER_NAME(log,"log");
	HX_MARK_MEMBER_NAME(perf,"perf");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxDebugger_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_gutter,"_gutter");
	HX_VISIT_MEMBER_NAME(_screen,"_screen");
	HX_VISIT_MEMBER_NAME(_layout,"_layout");
	HX_VISIT_MEMBER_NAME(hasMouse,"hasMouse");
	HX_VISIT_MEMBER_NAME(vis,"vis");
	HX_VISIT_MEMBER_NAME(vcr,"vcr");
	HX_VISIT_MEMBER_NAME(watch,"watch");
	HX_VISIT_MEMBER_NAME(log,"log");
	HX_VISIT_MEMBER_NAME(perf,"perf");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxDebugger_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"vis") ) { return vis; }
		if (HX_FIELD_EQ(inName,"vcr") ) { return vcr; }
		if (HX_FIELD_EQ(inName,"log") ) { return log; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"perf") ) { return perf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"watch") ) { return watch; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_gutter") ) { return _gutter; }
		if (HX_FIELD_EQ(inName,"_screen") ) { return _screen; }
		if (HX_FIELD_EQ(inName,"_layout") ) { return _layout; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasMouse") ) { return hasMouse; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setLayout") ) { return setLayout_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return onMouseOut_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"resetLayout") ) { return resetLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return onMouseOver_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxDebugger_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"vis") ) { vis=inValue.Cast< ::org::flixel::system::debug::Vis >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vcr") ) { vcr=inValue.Cast< ::org::flixel::system::debug::VCR >(); return inValue; }
		if (HX_FIELD_EQ(inName,"log") ) { log=inValue.Cast< ::org::flixel::system::debug::Log >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"perf") ) { perf=inValue.Cast< ::org::flixel::system::debug::Perf >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"watch") ) { watch=inValue.Cast< ::org::flixel::system::debug::Watch >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_gutter") ) { _gutter=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_screen") ) { _screen=inValue.Cast< ::native::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_layout") ) { _layout=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasMouse") ) { hasMouse=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxDebugger_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_gutter"));
	outFields->push(HX_CSTRING("_screen"));
	outFields->push(HX_CSTRING("_layout"));
	outFields->push(HX_CSTRING("hasMouse"));
	outFields->push(HX_CSTRING("vis"));
	outFields->push(HX_CSTRING("vcr"));
	outFields->push(HX_CSTRING("watch"));
	outFields->push(HX_CSTRING("log"));
	outFields->push(HX_CSTRING("perf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("resetLayout"),
	HX_CSTRING("setLayout"),
	HX_CSTRING("onMouseOut"),
	HX_CSTRING("onMouseOver"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_gutter"),
	HX_CSTRING("_screen"),
	HX_CSTRING("_layout"),
	HX_CSTRING("hasMouse"),
	HX_CSTRING("vis"),
	HX_CSTRING("vcr"),
	HX_CSTRING("watch"),
	HX_CSTRING("log"),
	HX_CSTRING("perf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxDebugger_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxDebugger_obj::__mClass,"__mClass");
};

Class FlxDebugger_obj::__mClass;

void FlxDebugger_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.FlxDebugger"), hx::TCanCast< FlxDebugger_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxDebugger_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
