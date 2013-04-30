#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
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
#ifndef INCLUDED_native_display_PixelSnapping
#include <native/display/PixelSnapping.h>
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
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_ui_Mouse
#include <native/ui/Mouse.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_org_flixel_FlxAssets
#include <org/flixel/FlxAssets.h>
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
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxDebugger
#include <org/flixel/system/FlxDebugger.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxWindow
#include <org/flixel/system/FlxWindow.h>
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
#ifndef INCLUDED_org_flixel_system_replay_MouseRecord
#include <org/flixel/system/replay/MouseRecord.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace input{

Void FlxMouse_obj::__construct(::native::display::Sprite CursorContainer)
{
HX_STACK_PUSH("FlxMouse::new","org/flixel/system/input/FlxMouse.hx",88);
{
	HX_STACK_LINE(89)
	super::__construct(null(),null());
	HX_STACK_LINE(90)
	this->_cursorContainer = CursorContainer;
	HX_STACK_LINE(91)
	this->_cursorContainer->set_mouseChildren(false);
	HX_STACK_LINE(92)
	this->_cursorContainer->set_mouseEnabled(false);
	HX_STACK_LINE(93)
	this->_lastX = this->screenX = (int)0;
	HX_STACK_LINE(94)
	this->_lastY = this->screenY = (int)0;
	HX_STACK_LINE(95)
	this->_lastWheel = this->wheel = (int)0;
	HX_STACK_LINE(96)
	this->_current = (int)0;
	HX_STACK_LINE(97)
	this->_last = (int)0;
	HX_STACK_LINE(98)
	this->_cursor = null();
	HX_STACK_LINE(99)
	this->_point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(100)
	this->_globalScreenPosition = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(101)
	this->set_systemCursor(false);
	HX_STACK_LINE(103)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(104)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(105)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_WHEEL,this->onMouseWheel_dyn(),null(),null(),null());
}
;
	return null();
}

FlxMouse_obj::~FlxMouse_obj() { }

Dynamic FlxMouse_obj::__CreateEmpty() { return  new FlxMouse_obj; }
hx::ObjectPtr< FlxMouse_obj > FlxMouse_obj::__new(::native::display::Sprite CursorContainer)
{  hx::ObjectPtr< FlxMouse_obj > result = new FlxMouse_obj();
	result->__construct(CursorContainer);
	return result;}

Dynamic FlxMouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxMouse_obj > result = new FlxMouse_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *FlxMouse_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::org::flixel::system::input::IFlxInput_obj)) return operator ::org::flixel::system::input::IFlxInput_obj *();
	return super::__ToInterface(inType);
}

bool FlxMouse_obj::set_systemCursor( bool value){
	HX_STACK_PUSH("FlxMouse::set_systemCursor","org/flixel/system/input/FlxMouse.hx",496);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(497)
	this->useSystemCursor = value;
	HX_STACK_LINE(498)
	if ((!(this->useSystemCursor))){
		HX_STACK_LINE(499)
		::native::ui::Mouse_obj::hide();
	}
	else{
		HX_STACK_LINE(501)
		::native::ui::Mouse_obj::show();
	}
	HX_STACK_LINE(504)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxMouse_obj,set_systemCursor,return )

Void FlxMouse_obj::onFocusLost( ){
{
		HX_STACK_PUSH("FlxMouse::onFocusLost","org/flixel/system/input/FlxMouse.hx",491);
		HX_STACK_THIS(this);
		HX_STACK_LINE(491)
		::native::ui::Mouse_obj::show();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,onFocusLost,(void))

Void FlxMouse_obj::onFocus( ){
{
		HX_STACK_PUSH("FlxMouse::onFocus","org/flixel/system/input/FlxMouse.hx",477);
		HX_STACK_THIS(this);
		HX_STACK_LINE(479)
		if (((bool(!(::org::flixel::FlxG_obj::_game->_debuggerUp)) && bool(!(this->useSystemCursor))))){
			HX_STACK_LINE(483)
			::native::ui::Mouse_obj::hide();
		}
		HX_STACK_LINE(486)
		this->reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,onFocus,(void))

Void FlxMouse_obj::playback( ::org::flixel::system::replay::MouseRecord Record){
{
		HX_STACK_PUSH("FlxMouse::playback","org/flixel/system/input/FlxMouse.hx",468);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Record,"Record");
		HX_STACK_LINE(469)
		this->_current = Record->button;
		HX_STACK_LINE(470)
		this->wheel = Record->wheel;
		HX_STACK_LINE(471)
		this->_globalScreenPosition->x = Record->x;
		HX_STACK_LINE(472)
		this->_globalScreenPosition->y = Record->y;
		HX_STACK_LINE(473)
		this->updateCursor();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxMouse_obj,playback,(void))

::org::flixel::system::replay::MouseRecord FlxMouse_obj::record( ){
	HX_STACK_PUSH("FlxMouse::record","org/flixel/system/input/FlxMouse.hx",451);
	HX_STACK_THIS(this);
	HX_STACK_LINE(452)
	if (((bool((bool((bool((this->_lastX == this->_globalScreenPosition->x)) && bool((this->_lastY == this->_globalScreenPosition->y)))) && bool((this->_current == (int)0)))) && bool((this->_lastWheel == this->wheel))))){
		HX_STACK_LINE(453)
		return null();
	}
	HX_STACK_LINE(456)
	this->_lastX = ::Math_obj::floor(this->_globalScreenPosition->x);
	HX_STACK_LINE(457)
	this->_lastY = ::Math_obj::floor(this->_globalScreenPosition->y);
	HX_STACK_LINE(458)
	this->_lastWheel = this->wheel;
	HX_STACK_LINE(459)
	return ::org::flixel::system::replay::MouseRecord_obj::__new(this->_lastX,this->_lastY,this->_current,this->_lastWheel);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,record,return )

bool FlxMouse_obj::justReleased( ){
	HX_STACK_PUSH("FlxMouse::justReleased","org/flixel/system/input/FlxMouse.hx",444);
	HX_STACK_THIS(this);
	HX_STACK_LINE(444)
	return (bool((this->_current == (int)-1)) || bool((this->_current == (int)-2)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,justReleased,return )

bool FlxMouse_obj::justPressed( ){
	HX_STACK_PUSH("FlxMouse::justPressed","org/flixel/system/input/FlxMouse.hx",438);
	HX_STACK_THIS(this);
	HX_STACK_LINE(438)
	return (bool((this->_current == (int)2)) || bool((this->_current == (int)-2)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,justPressed,return )

bool FlxMouse_obj::pressed( ){
	HX_STACK_PUSH("FlxMouse::pressed","org/flixel/system/input/FlxMouse.hx",432);
	HX_STACK_THIS(this);
	HX_STACK_LINE(432)
	return (this->_current > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,pressed,return )

Void FlxMouse_obj::reset( ){
{
		HX_STACK_PUSH("FlxMouse::reset","org/flixel/system/input/FlxMouse.hx",423);
		HX_STACK_THIS(this);
		HX_STACK_LINE(424)
		this->_current = (int)0;
		HX_STACK_LINE(425)
		this->_last = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,reset,(void))

::org::flixel::FlxPoint FlxMouse_obj::getScreenPosition( ::org::flixel::FlxCamera Camera,::org::flixel::FlxPoint point){
	HX_STACK_PUSH("FlxMouse::getScreenPosition","org/flixel/system/input/FlxMouse.hx",405);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(406)
	if (((Camera == null()))){
		HX_STACK_LINE(407)
		Camera = ::org::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(410)
	if (((point == null()))){
		HX_STACK_LINE(411)
		point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(414)
	point->x = (Float(((this->_globalScreenPosition->x - Camera->x))) / Float(Camera->zoom));
	HX_STACK_LINE(415)
	point->y = (Float(((this->_globalScreenPosition->y - Camera->y))) / Float(Camera->zoom));
	HX_STACK_LINE(416)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxMouse_obj,getScreenPosition,return )

::org::flixel::FlxPoint FlxMouse_obj::getWorldPosition( ::org::flixel::FlxCamera Camera,::org::flixel::FlxPoint point){
	HX_STACK_PUSH("FlxMouse::getWorldPosition","org/flixel/system/input/FlxMouse.hx",382);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(383)
	if (((Camera == null()))){
		HX_STACK_LINE(384)
		Camera = ::org::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(387)
	if (((point == null()))){
		HX_STACK_LINE(388)
		point = ::org::flixel::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(391)
	this->getScreenPosition(Camera,this->_point);
	HX_STACK_LINE(392)
	point->x = (this->_point->x + Camera->scroll->x);
	HX_STACK_LINE(393)
	point->y = (this->_point->y + Camera->scroll->y);
	HX_STACK_LINE(394)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxMouse_obj,getWorldPosition,return )

Void FlxMouse_obj::updateCursor( ){
{
		HX_STACK_PUSH("FlxMouse::updateCursor","org/flixel/system/input/FlxMouse.hx",357);
		HX_STACK_THIS(this);
		HX_STACK_LINE(359)
		if ((this->_updateCursorContainer)){
			HX_STACK_LINE(361)
			this->_cursorContainer->set_x(this->_globalScreenPosition->x);
			HX_STACK_LINE(362)
			this->_cursorContainer->set_y(this->_globalScreenPosition->y);
		}
		HX_STACK_LINE(367)
		::org::flixel::FlxCamera camera = ::org::flixel::FlxG_obj::camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(368)
		this->screenX = ::Math_obj::floor((Float(((this->_globalScreenPosition->x - camera->x))) / Float(camera->zoom)));
		HX_STACK_LINE(369)
		this->screenY = ::Math_obj::floor((Float(((this->_globalScreenPosition->y - camera->y))) / Float(camera->zoom)));
		HX_STACK_LINE(370)
		this->x = (this->screenX + camera->scroll->x);
		HX_STACK_LINE(371)
		this->y = (this->screenY + camera->scroll->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,updateCursor,(void))

Void FlxMouse_obj::update( ){
{
		HX_STACK_PUSH("FlxMouse::update","org/flixel/system/input/FlxMouse.hx",328);
		HX_STACK_THIS(this);
		HX_STACK_LINE(328)
		if ((this->_updateCursorContainer)){
			HX_STACK_LINE(331)
			int X = ::Math_obj::floor(::org::flixel::FlxG_obj::_game->get_mouseX());		HX_STACK_VAR(X,"X");
			HX_STACK_LINE(332)
			int Y = ::Math_obj::floor(::org::flixel::FlxG_obj::_game->get_mouseY());		HX_STACK_VAR(Y,"Y");
			HX_STACK_LINE(334)
			this->_globalScreenPosition->x = X;
			HX_STACK_LINE(335)
			this->_globalScreenPosition->y = Y;
			HX_STACK_LINE(336)
			this->updateCursor();
			HX_STACK_LINE(337)
			if (((bool((this->_last == (int)-1)) && bool((this->_current == (int)-1))))){
				HX_STACK_LINE(338)
				this->_current = (int)0;
			}
			else{
				HX_STACK_LINE(341)
				if (((bool((this->_last == (int)2)) && bool((this->_current == (int)2))))){
					HX_STACK_LINE(342)
					this->_current = (int)1;
				}
				else{
					HX_STACK_LINE(345)
					if (((bool((this->_last == (int)-2)) && bool((this->_current == (int)-2))))){
						HX_STACK_LINE(346)
						this->_current = (int)0;
					}
				}
			}
			HX_STACK_LINE(349)
			this->_last = this->_current;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,update,(void))

Void FlxMouse_obj::unload( ){
{
		HX_STACK_PUSH("FlxMouse::unload","org/flixel/system/input/FlxMouse.hx",306);
		HX_STACK_THIS(this);
		HX_STACK_LINE(306)
		if (((this->_cursor != null()))){
			HX_STACK_LINE(308)
			if ((this->_cursorContainer->get_visible())){
				HX_STACK_LINE(310)
				this->load(null(),null(),null(),null());
			}
			else{
				HX_STACK_LINE(315)
				this->_cursorContainer->removeChild(this->_cursor);
				HX_STACK_LINE(316)
				this->_cursor = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,unload,(void))

Void FlxMouse_obj::load( Dynamic Graphic,hx::Null< Float >  __o_Scale,hx::Null< int >  __o_XOffset,hx::Null< int >  __o_YOffset){
Float Scale = __o_Scale.Default(1);
int XOffset = __o_XOffset.Default(0);
int YOffset = __o_YOffset.Default(0);
	HX_STACK_PUSH("FlxMouse::load","org/flixel/system/input/FlxMouse.hx",265);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Graphic,"Graphic");
	HX_STACK_ARG(Scale,"Scale");
	HX_STACK_ARG(XOffset,"XOffset");
	HX_STACK_ARG(YOffset,"YOffset");
{
		HX_STACK_LINE(266)
		if (((this->_cursor != null()))){
			HX_STACK_LINE(267)
			this->_cursorContainer->removeChild(this->_cursor);
		}
		HX_STACK_LINE(271)
		if (((Graphic == null()))){
			HX_STACK_LINE(272)
			Graphic = ::org::flixel::FlxAssets_obj::imgDefaultCursor;
		}
		HX_STACK_LINE(276)
		if ((::Std_obj::is(Graphic,hx::ClassOf< ::Class >()))){
			HX_STACK_LINE(277)
			this->_cursor = ::Type_obj::createInstance(Graphic,Dynamic( Array_obj<Dynamic>::__new()));
		}
		else{
			HX_STACK_LINE(280)
			if ((::Std_obj::is(Graphic,hx::ClassOf< ::native::display::BitmapData >()))){
				HX_STACK_LINE(281)
				this->_cursor = ::native::display::Bitmap_obj::__new(hx::TCast< native::display::BitmapData >::cast(Graphic),null(),null());
			}
			else{
				HX_STACK_LINE(284)
				if ((::Std_obj::is(Graphic,hx::ClassOf< ::String >()))){
					HX_STACK_LINE(285)
					this->_cursor = ::native::display::Bitmap_obj::__new(::org::flixel::FlxAssets_obj::getBitmapData(Graphic),null(),null());
				}
				else{
					HX_STACK_LINE(289)
					this->_cursor = ::native::display::Bitmap_obj::__new(::org::flixel::FlxAssets_obj::getBitmapData(::org::flixel::FlxAssets_obj::imgDefaultCursor),null(),null());
				}
			}
		}
		HX_STACK_LINE(293)
		this->_cursor->set_x(XOffset);
		HX_STACK_LINE(294)
		this->_cursor->set_y(YOffset);
		HX_STACK_LINE(295)
		this->_cursor->set_scaleX(Scale);
		HX_STACK_LINE(296)
		this->_cursor->set_scaleY(Scale);
		HX_STACK_LINE(298)
		this->_cursorContainer->addChild(this->_cursor);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxMouse_obj,load,(void))

bool FlxMouse_obj::get_visible( ){
	HX_STACK_PUSH("FlxMouse::get_visible","org/flixel/system/input/FlxMouse.hx",253);
	HX_STACK_THIS(this);
	HX_STACK_LINE(253)
	return this->_updateCursorContainer;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,get_visible,return )

Void FlxMouse_obj::hide( ){
{
		HX_STACK_PUSH("FlxMouse::hide","org/flixel/system/input/FlxMouse.hx",243);
		HX_STACK_THIS(this);
		HX_STACK_LINE(244)
		this->_updateCursorContainer = false;
		HX_STACK_LINE(245)
		this->_cursorContainer->set_visible(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,hide,(void))

Void FlxMouse_obj::show( Dynamic Graphic,hx::Null< Float >  __o_Scale,hx::Null< int >  __o_XOffset,hx::Null< int >  __o_YOffset){
Float Scale = __o_Scale.Default(1);
int XOffset = __o_XOffset.Default(0);
int YOffset = __o_YOffset.Default(0);
	HX_STACK_PUSH("FlxMouse::show","org/flixel/system/input/FlxMouse.hx",221);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Graphic,"Graphic");
	HX_STACK_ARG(Scale,"Scale");
	HX_STACK_ARG(XOffset,"XOffset");
	HX_STACK_ARG(YOffset,"YOffset");
{
		HX_STACK_LINE(222)
		this->_updateCursorContainer = true;
		HX_STACK_LINE(223)
		this->_cursorContainer->set_visible(true);
		HX_STACK_LINE(224)
		if (((Graphic != null()))){
			HX_STACK_LINE(225)
			this->load(Graphic,Scale,XOffset,YOffset);
		}
		else{
			HX_STACK_LINE(228)
			if (((this->_cursor == null()))){
				HX_STACK_LINE(229)
				this->load(null(),null(),null(),null());
			}
		}
		HX_STACK_LINE(232)
		if ((this->useSystemCursor)){
			HX_STACK_LINE(233)
			::native::ui::Mouse_obj::show();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxMouse_obj,show,(void))

Void FlxMouse_obj::destroy( ){
{
		HX_STACK_PUSH("FlxMouse::destroy","org/flixel/system/input/FlxMouse.hx",206);
		HX_STACK_THIS(this);
		HX_STACK_LINE(207)
		this->_cursorContainer = null();
		HX_STACK_LINE(208)
		this->_cursor = null();
		HX_STACK_LINE(209)
		this->_point = null();
		HX_STACK_LINE(210)
		this->_globalScreenPosition = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxMouse_obj,destroy,(void))

Void FlxMouse_obj::onMouseWheel( ::native::events::MouseEvent FlashEvent){
{
		HX_STACK_PUSH("FlxMouse::onMouseWheel","org/flixel/system/input/FlxMouse.hx",191);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(193)
		if (((bool((bool(::org::flixel::FlxG_obj::_game->_debuggerUp) && bool(::org::flixel::FlxG_obj::_game->_debugger->hasMouse))) || bool(::org::flixel::FlxG_obj::_game->_replaying)))){
			HX_STACK_LINE(194)
			return null();
		}
		HX_STACK_LINE(199)
		this->wheel = FlashEvent->delta;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxMouse_obj,onMouseWheel,(void))

Void FlxMouse_obj::onMouseUp( ::native::events::MouseEvent FlashEvent){
{
		HX_STACK_PUSH("FlxMouse::onMouseUp","org/flixel/system/input/FlxMouse.hx",164);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(166)
		if (((bool((bool(::org::flixel::FlxG_obj::_game->_debuggerUp) && bool(::org::flixel::FlxG_obj::_game->_debugger->hasMouse))) || bool(::org::flixel::FlxG_obj::_game->_replaying)))){
			HX_STACK_LINE(167)
			return null();
		}
		HX_STACK_LINE(172)
		if (((this->_current > (int)0))){
			HX_STACK_LINE(173)
			this->_current = (int)-1;
		}
		else{
			HX_STACK_LINE(176)
			if (((this->_current == (int)-2))){
				HX_STACK_LINE(177)
				(this->_current == (int)-2);
			}
			else{
				HX_STACK_LINE(181)
				this->_current = (int)0;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxMouse_obj,onMouseUp,(void))

Void FlxMouse_obj::onMouseDown( ::native::events::MouseEvent FlashEvent){
{
		HX_STACK_PUSH("FlxMouse::onMouseDown","org/flixel/system/input/FlxMouse.hx",113);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(115)
		if ((::org::flixel::FlxG_obj::_game->_debuggerUp)){
			HX_STACK_LINE(117)
			if ((::org::flixel::FlxG_obj::_game->_debugger->hasMouse)){
				HX_STACK_LINE(118)
				return null();
			}
			HX_STACK_LINE(121)
			if ((::org::flixel::FlxG_obj::_game->_debugger->watch->editing)){
				HX_STACK_LINE(122)
				::org::flixel::FlxG_obj::_game->_debugger->watch->submit();
			}
		}
		HX_STACK_LINE(129)
		if (((bool(::org::flixel::FlxG_obj::_game->_replaying) && bool((::org::flixel::FlxG_obj::_game->_replayCancelKeys != null()))))){
			HX_STACK_LINE(131)
			::String replayCancelKey;		HX_STACK_VAR(replayCancelKey,"replayCancelKey");
			HX_STACK_LINE(132)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(133)
			int l = ::org::flixel::FlxG_obj::_game->_replayCancelKeys->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(134)
			while(((i < l))){
				HX_STACK_LINE(136)
				replayCancelKey = ::org::flixel::FlxG_obj::_game->_replayCancelKeys->__get((i)++);
				HX_STACK_LINE(137)
				if (((bool((replayCancelKey == HX_CSTRING("MOUSE"))) || bool((replayCancelKey == HX_CSTRING("ANY")))))){
					HX_STACK_LINE(139)
					if (((::org::flixel::FlxG_obj::_game->_replayCallback_dyn() != null()))){
						HX_STACK_LINE(141)
						::org::flixel::FlxG_obj::_game->_replayCallback();
						HX_STACK_LINE(142)
						::org::flixel::FlxG_obj::_game->_replayCallback = null();
					}
					else{
						HX_STACK_LINE(145)
						::org::flixel::FlxG_obj::stopReplay();
					}
					HX_STACK_LINE(148)
					break;
				}
			}
			HX_STACK_LINE(151)
			return null();
		}
		HX_STACK_LINE(155)
		if (((this->_current > (int)0))){
			HX_STACK_LINE(155)
			this->_current = (int)1;
		}
		else{
			HX_STACK_LINE(156)
			this->_current = (int)2;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxMouse_obj,onMouseDown,(void))


FlxMouse_obj::FlxMouse_obj()
{
}

void FlxMouse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxMouse);
	HX_MARK_MEMBER_NAME(useSystemCursor,"useSystemCursor");
	HX_MARK_MEMBER_NAME(_globalScreenPosition,"_globalScreenPosition");
	HX_MARK_MEMBER_NAME(_point,"_point");
	HX_MARK_MEMBER_NAME(_lastWheel,"_lastWheel");
	HX_MARK_MEMBER_NAME(_lastY,"_lastY");
	HX_MARK_MEMBER_NAME(_lastX,"_lastX");
	HX_MARK_MEMBER_NAME(_cursor,"_cursor");
	HX_MARK_MEMBER_NAME(_updateCursorContainer,"_updateCursorContainer");
	HX_MARK_MEMBER_NAME(_cursorContainer,"_cursorContainer");
	HX_MARK_MEMBER_NAME(_last,"_last");
	HX_MARK_MEMBER_NAME(_current,"_current");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(screenY,"screenY");
	HX_MARK_MEMBER_NAME(screenX,"screenX");
	HX_MARK_MEMBER_NAME(wheel,"wheel");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxMouse_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(useSystemCursor,"useSystemCursor");
	HX_VISIT_MEMBER_NAME(_globalScreenPosition,"_globalScreenPosition");
	HX_VISIT_MEMBER_NAME(_point,"_point");
	HX_VISIT_MEMBER_NAME(_lastWheel,"_lastWheel");
	HX_VISIT_MEMBER_NAME(_lastY,"_lastY");
	HX_VISIT_MEMBER_NAME(_lastX,"_lastX");
	HX_VISIT_MEMBER_NAME(_cursor,"_cursor");
	HX_VISIT_MEMBER_NAME(_updateCursorContainer,"_updateCursorContainer");
	HX_VISIT_MEMBER_NAME(_cursorContainer,"_cursorContainer");
	HX_VISIT_MEMBER_NAME(_last,"_last");
	HX_VISIT_MEMBER_NAME(_current,"_current");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(screenY,"screenY");
	HX_VISIT_MEMBER_NAME(screenX,"screenX");
	HX_VISIT_MEMBER_NAME(wheel,"wheel");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxMouse_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"hide") ) { return hide_dyn(); }
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"_last") ) { return _last; }
		if (HX_FIELD_EQ(inName,"wheel") ) { return wheel; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"record") ) { return record_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"unload") ) { return unload_dyn(); }
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"_lastY") ) { return _lastY; }
		if (HX_FIELD_EQ(inName,"_lastX") ) { return _lastX; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"pressed") ) { return pressed_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_cursor") ) { return _cursor; }
		if (HX_FIELD_EQ(inName,"visible") ) { return inCallProp ? get_visible() : visible; }
		if (HX_FIELD_EQ(inName,"screenY") ) { return screenY; }
		if (HX_FIELD_EQ(inName,"screenX") ) { return screenX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"playback") ) { return playback_dyn(); }
		if (HX_FIELD_EQ(inName,"_current") ) { return _current; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_lastWheel") ) { return _lastWheel; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		if (HX_FIELD_EQ(inName,"justPressed") ) { return justPressed_dyn(); }
		if (HX_FIELD_EQ(inName,"get_visible") ) { return get_visible_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"justReleased") ) { return justReleased_dyn(); }
		if (HX_FIELD_EQ(inName,"updateCursor") ) { return updateCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseWheel") ) { return onMouseWheel_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"useSystemCursor") ) { return useSystemCursor; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"set_systemCursor") ) { return set_systemCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldPosition") ) { return getWorldPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"_cursorContainer") ) { return _cursorContainer; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getScreenPosition") ) { return getScreenPosition_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_globalScreenPosition") ) { return _globalScreenPosition; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_updateCursorContainer") ) { return _updateCursorContainer; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxMouse_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { _last=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wheel") ) { wheel=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastY") ) { _lastY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastX") ) { _lastX=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_cursor") ) { _cursor=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visible") ) { visible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screenY") ) { screenY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screenX") ) { screenX=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_current") ) { _current=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_lastWheel") ) { _lastWheel=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"useSystemCursor") ) { if (inCallProp) return set_systemCursor(inValue);useSystemCursor=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_cursorContainer") ) { _cursorContainer=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_globalScreenPosition") ) { _globalScreenPosition=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_updateCursorContainer") ) { _updateCursorContainer=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxMouse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("useSystemCursor"));
	outFields->push(HX_CSTRING("_globalScreenPosition"));
	outFields->push(HX_CSTRING("_point"));
	outFields->push(HX_CSTRING("_lastWheel"));
	outFields->push(HX_CSTRING("_lastY"));
	outFields->push(HX_CSTRING("_lastX"));
	outFields->push(HX_CSTRING("_cursor"));
	outFields->push(HX_CSTRING("_updateCursorContainer"));
	outFields->push(HX_CSTRING("_cursorContainer"));
	outFields->push(HX_CSTRING("_last"));
	outFields->push(HX_CSTRING("_current"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("screenY"));
	outFields->push(HX_CSTRING("screenX"));
	outFields->push(HX_CSTRING("wheel"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_systemCursor"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("playback"),
	HX_CSTRING("record"),
	HX_CSTRING("justReleased"),
	HX_CSTRING("justPressed"),
	HX_CSTRING("pressed"),
	HX_CSTRING("reset"),
	HX_CSTRING("getScreenPosition"),
	HX_CSTRING("getWorldPosition"),
	HX_CSTRING("updateCursor"),
	HX_CSTRING("update"),
	HX_CSTRING("unload"),
	HX_CSTRING("load"),
	HX_CSTRING("get_visible"),
	HX_CSTRING("hide"),
	HX_CSTRING("show"),
	HX_CSTRING("destroy"),
	HX_CSTRING("onMouseWheel"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("useSystemCursor"),
	HX_CSTRING("_globalScreenPosition"),
	HX_CSTRING("_point"),
	HX_CSTRING("_lastWheel"),
	HX_CSTRING("_lastY"),
	HX_CSTRING("_lastX"),
	HX_CSTRING("_cursor"),
	HX_CSTRING("_updateCursorContainer"),
	HX_CSTRING("_cursorContainer"),
	HX_CSTRING("_last"),
	HX_CSTRING("_current"),
	HX_CSTRING("visible"),
	HX_CSTRING("screenY"),
	HX_CSTRING("screenX"),
	HX_CSTRING("wheel"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxMouse_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxMouse_obj::__mClass,"__mClass");
};

Class FlxMouse_obj::__mClass;

void FlxMouse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.input.FlxMouse"), hx::TCanCast< FlxMouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxMouse_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input
