#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
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
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
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
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
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
#ifndef INCLUDED_org_flixel_FlxGroup
#include <org/flixel/FlxGroup.h>
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
#ifndef INCLUDED_org_flixel_FlxSound
#include <org/flixel/FlxSound.h>
#endif
#ifndef INCLUDED_org_flixel_FlxState
#include <org/flixel/FlxState.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSubState
#include <org/flixel/FlxSubState.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedGroup
#include <org/flixel/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_org_flixel_plugin_DebugPathDisplay
#include <org/flixel/plugin/DebugPathDisplay.h>
#endif
#ifndef INCLUDED_org_flixel_plugin_TimerManager
#include <org/flixel/plugin/TimerManager.h>
#endif
#ifndef INCLUDED_org_flixel_plugin_pxText_PxBitmapFont
#include <org/flixel/plugin/pxText/PxBitmapFont.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxDebugger
#include <org/flixel/system/FlxDebugger.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxQuadTree
#include <org/flixel/system/FlxQuadTree.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxReplay
#include <org/flixel/system/FlxReplay.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxWindow
#include <org/flixel/system/FlxWindow.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_Log
#include <org/flixel/system/debug/Log.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_VCR
#include <org/flixel/system/debug/VCR.h>
#endif
#ifndef INCLUDED_org_flixel_system_debug_Watch
#include <org/flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxInputStates
#include <org/flixel/system/input/FlxInputStates.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxInputs
#include <org/flixel/system/input/FlxInputs.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxJoystickManager
#include <org/flixel/system/input/FlxJoystickManager.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxKeyboard
#include <org/flixel/system/input/FlxKeyboard.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMouse
#include <org/flixel/system/input/FlxMouse.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxTouchManager
#include <org/flixel/system/input/FlxTouchManager.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_IFlxInput
#include <org/flixel/system/input/IFlxInput.h>
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
#ifndef INCLUDED_org_flixel_tweens_FlxTween
#include <org/flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_org_flixel_tweens_misc_MultiVarTween
#include <org/flixel/tweens/misc/MultiVarTween.h>
#endif
namespace org{
namespace flixel{

Void FlxG_obj::__construct()
{
HX_STACK_PUSH("FlxG::new","org/flixel/FlxG.hx",72);
{
}
;
	return null();
}

FlxG_obj::~FlxG_obj() { }

Dynamic FlxG_obj::__CreateEmpty() { return  new FlxG_obj; }
hx::ObjectPtr< FlxG_obj > FlxG_obj::__new()
{  hx::ObjectPtr< FlxG_obj > result = new FlxG_obj();
	result->__construct();
	return result;}

Dynamic FlxG_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxG_obj > result = new FlxG_obj();
	result->__construct();
	return result;}

bool FlxG_obj::supportsTouchEvents;

::org::flixel::FlxBasic FlxG_obj::tweener;

int FlxG_obj::bgColor;

int FlxG_obj::flashFramerate;

::String FlxG_obj::LIBRARY_NAME;

::String FlxG_obj::LIBRARY_MAJOR_VERSION;

::String FlxG_obj::LIBRARY_MINOR_VERSION;

int FlxG_obj::DEBUGGER_STANDARD;

int FlxG_obj::DEBUGGER_MICRO;

int FlxG_obj::DEBUGGER_BIG;

int FlxG_obj::DEBUGGER_TOP;

int FlxG_obj::DEBUGGER_LEFT;

int FlxG_obj::DEBUGGER_RIGHT;

int FlxG_obj::RED;

int FlxG_obj::GREEN;

int FlxG_obj::BLUE;

int FlxG_obj::PINK;

int FlxG_obj::WHITE;

int FlxG_obj::BLACK;

int FlxG_obj::TRANSPARENT;

Float FlxG_obj::DEG;

Float FlxG_obj::RAD;

::org::flixel::FlxGame FlxG_obj::_game;

bool FlxG_obj::paused;

bool FlxG_obj::debug;

Float FlxG_obj::elapsed;

Float FlxG_obj::timeScale;

int FlxG_obj::width;

int FlxG_obj::height;

::org::flixel::FlxRect FlxG_obj::worldBounds;

int FlxG_obj::worldDivisions;

bool FlxG_obj::visualDebug;

bool FlxG_obj::mobile;

Float FlxG_obj::globalSeed;

Dynamic FlxG_obj::levels;

int FlxG_obj::level;

Dynamic FlxG_obj::scores;

int FlxG_obj::score;

Dynamic FlxG_obj::saves;

int FlxG_obj::save;

::org::flixel::FlxSound FlxG_obj::music;

::org::flixel::FlxTypedGroup FlxG_obj::sounds;

bool FlxG_obj::mute;

Array< ::org::flixel::FlxCamera > FlxG_obj::cameras;

::org::flixel::FlxCamera FlxG_obj::camera;

bool FlxG_obj::useBufferLocking;

::native::geom::Rectangle FlxG_obj::_cameraRect;

Array< ::org::flixel::FlxBasic > FlxG_obj::plugins;

Dynamic FlxG_obj::volumeHandler;

::native::display::Sprite FlxG_obj::flashGfxSprite;

::native::display::Graphics FlxG_obj::flashGfx;

::Hash FlxG_obj::_cache;

::String FlxG_obj::_lastBitmapDataKey;

::org::flixel::system::input::FlxMouse FlxG_obj::mouse;

::org::flixel::system::input::FlxKeyboard FlxG_obj::keys;

::org::flixel::system::input::FlxTouchManager FlxG_obj::touchManager;

::org::flixel::system::input::FlxJoystickManager FlxG_obj::joystickManager;

::String FlxG_obj::getLibraryName( ){
	HX_STACK_PUSH("FlxG::getLibraryName","org/flixel/FlxG.hx",349);
	HX_STACK_LINE(349)
	return ((((HX_CSTRING("HaxeFlixel") + HX_CSTRING(" v")) + HX_CSTRING("1")) + HX_CSTRING(".")) + HX_CSTRING("09"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,getLibraryName,return )

Void FlxG_obj::log( Dynamic Data){
{
		HX_STACK_PUSH("FlxG::log","org/flixel/FlxG.hx",358);
		HX_STACK_ARG(Data,"Data");
		HX_STACK_LINE(358)
		if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
			struct _Function_2_1{
				inline static ::String Block( Dynamic &Data){
					HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",362);
					{
						HX_STACK_LINE(362)
						Dynamic AnyArray = hx::TCastToArray(Data);		HX_STACK_VAR(AnyArray,"AnyArray");
						HX_STACK_LINE(362)
						::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
						HX_STACK_LINE(362)
						if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
							HX_STACK_LINE(362)
							string = ::Std_obj::string(AnyArray->__GetItem((int)0));
							HX_STACK_LINE(362)
							int i = (int)1;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(362)
							int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
							HX_STACK_LINE(362)
							while(((i < l))){
								HX_STACK_LINE(362)
								hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
							}
						}
						HX_STACK_LINE(362)
						return string;
					}
					return null();
				}
			};
			HX_STACK_LINE(361)
			::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  (((Data == null()))) ? ::String(HX_CSTRING("ERROR: null object")) : ::String((  ((::Std_obj::is(Data,hx::ClassOf< Array<int> >()))) ? ::String(_Function_2_1::Block(Data)) : ::String(::Std_obj::string(Data)) )) ));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,log,(void))

Void FlxG_obj::clearLog( ){
{
		HX_STACK_PUSH("FlxG::clearLog","org/flixel/FlxG.hx",371);
		HX_STACK_LINE(371)
		if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
			HX_STACK_LINE(374)
			::org::flixel::FlxG_obj::_game->getDebugger()->log->clear();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,clearLog,(void))

Void FlxG_obj::watch( Dynamic AnyObject,::String VariableName,::String DisplayName){
{
		HX_STACK_PUSH("FlxG::watch","org/flixel/FlxG.hx",388);
		HX_STACK_ARG(AnyObject,"AnyObject");
		HX_STACK_ARG(VariableName,"VariableName");
		HX_STACK_ARG(DisplayName,"DisplayName");
		HX_STACK_LINE(388)
		if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->_debugger != null()))))){
			HX_STACK_LINE(391)
			::org::flixel::FlxG_obj::_game->_debugger->watch->add(AnyObject,VariableName,DisplayName);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxG_obj,watch,(void))

Void FlxG_obj::unwatch( Dynamic AnyObject,::String VariableName){
{
		HX_STACK_PUSH("FlxG::unwatch","org/flixel/FlxG.hx",404);
		HX_STACK_ARG(AnyObject,"AnyObject");
		HX_STACK_ARG(VariableName,"VariableName");
		HX_STACK_LINE(404)
		if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->_debugger != null()))))){
			HX_STACK_LINE(407)
			::org::flixel::FlxG_obj::_game->_debugger->watch->remove(AnyObject,VariableName);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxG_obj,unwatch,(void))

int FlxG_obj::framerate;

int FlxG_obj::get_framerate( ){
	HX_STACK_PUSH("FlxG::get_framerate","org/flixel/FlxG.hx",421);
	HX_STACK_LINE(421)
	return ::Std_obj::_int((Float((int)1000) / Float(::org::flixel::FlxG_obj::_game->_step)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,get_framerate,return )

int FlxG_obj::set_framerate( int Framerate){
	HX_STACK_PUSH("FlxG::set_framerate","org/flixel/FlxG.hx",429);
	HX_STACK_ARG(Framerate,"Framerate");
	HX_STACK_LINE(430)
	::org::flixel::FlxG_obj::_game->_step = ::Std_obj::_int(::Math_obj::abs((Float((int)1000) / Float(Framerate))));
	HX_STACK_LINE(431)
	::org::flixel::FlxG_obj::_game->_stepSeconds = (Float(::org::flixel::FlxG_obj::_game->_step) / Float((int)1000));
	HX_STACK_LINE(432)
	if (((::org::flixel::FlxG_obj::_game->_maxAccumulation < ::org::flixel::FlxG_obj::_game->_step))){
		HX_STACK_LINE(433)
		::org::flixel::FlxG_obj::_game->_maxAccumulation = ::org::flixel::FlxG_obj::_game->_step;
	}
	HX_STACK_LINE(436)
	return Framerate;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,set_framerate,return )

int FlxG_obj::get_flashFramerate( ){
	HX_STACK_PUSH("FlxG::get_flashFramerate","org/flixel/FlxG.hx",445);
	HX_STACK_LINE(446)
	if (((::org::flixel::FlxG_obj::_game->get_stage() != null()))){
		HX_STACK_LINE(447)
		return ::Std_obj::_int(::org::flixel::FlxG_obj::_game->get_stage()->frameRate);
	}
	HX_STACK_LINE(448)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,get_flashFramerate,return )

int FlxG_obj::set_flashFramerate( int Framerate){
	HX_STACK_PUSH("FlxG::set_flashFramerate","org/flixel/FlxG.hx",455);
	HX_STACK_ARG(Framerate,"Framerate");
	HX_STACK_LINE(456)
	::org::flixel::FlxG_obj::_game->_flashFramerate = ::Std_obj::_int(::Math_obj::abs(Framerate));
	HX_STACK_LINE(457)
	if (((::org::flixel::FlxG_obj::_game->get_stage() != null()))){
		HX_STACK_LINE(458)
		::org::flixel::FlxG_obj::_game->get_stage()->set_frameRate(::org::flixel::FlxG_obj::_game->_flashFramerate);
	}
	HX_STACK_LINE(461)
	::org::flixel::FlxG_obj::_game->_maxAccumulation = (::Std_obj::_int((Float((int)2000) / Float(::org::flixel::FlxG_obj::_game->_flashFramerate))) - (int)1);
	HX_STACK_LINE(462)
	if (((::org::flixel::FlxG_obj::_game->_maxAccumulation < ::org::flixel::FlxG_obj::_game->_step))){
		HX_STACK_LINE(463)
		::org::flixel::FlxG_obj::_game->_maxAccumulation = ::org::flixel::FlxG_obj::_game->_step;
	}
	HX_STACK_LINE(466)
	return Framerate;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,set_flashFramerate,return )

Float FlxG_obj::random( ){
	HX_STACK_PUSH("FlxG::random","org/flixel/FlxG.hx",489);
	HX_STACK_LINE(490)
	::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
	HX_STACK_LINE(491)
	if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
		HX_STACK_LINE(491)
		hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
	}
	HX_STACK_LINE(492)
	return ::org::flixel::FlxG_obj::globalSeed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,random,return )

Dynamic FlxG_obj::shuffle( Dynamic Objects,int HowManyTimes){
	HX_STACK_PUSH("FlxG::shuffle","org/flixel/FlxG.hx",504);
	HX_STACK_ARG(Objects,"Objects");
	HX_STACK_ARG(HowManyTimes,"HowManyTimes");
	HX_STACK_LINE(505)
	HowManyTimes = ::Std_obj::_int(::Math_obj::max(HowManyTimes,(int)0));
	HX_STACK_LINE(506)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(507)
	int index1;		HX_STACK_VAR(index1,"index1");
	HX_STACK_LINE(508)
	int index2;		HX_STACK_VAR(index2,"index2");
	HX_STACK_LINE(509)
	Dynamic object;		HX_STACK_VAR(object,"object");
	HX_STACK_LINE(510)
	while(((i < HowManyTimes))){
		struct _Function_2_1{
			inline static Float Block( ){
				HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",512);
				{
					HX_STACK_LINE(512)
					::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
					HX_STACK_LINE(512)
					if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
						HX_STACK_LINE(512)
						hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
					}
					HX_STACK_LINE(512)
					return ::org::flixel::FlxG_obj::globalSeed;
				}
				return null();
			}
		};
		HX_STACK_LINE(512)
		index1 = ::Std_obj::_int((_Function_2_1::Block() * Objects->__Field(HX_CSTRING("length"),true)));
		struct _Function_2_2{
			inline static Float Block( ){
				HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",513);
				{
					HX_STACK_LINE(513)
					::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
					HX_STACK_LINE(513)
					if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
						HX_STACK_LINE(513)
						hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
					}
					HX_STACK_LINE(513)
					return ::org::flixel::FlxG_obj::globalSeed;
				}
				return null();
			}
		};
		HX_STACK_LINE(513)
		index2 = ::Std_obj::_int((_Function_2_2::Block() * Objects->__Field(HX_CSTRING("length"),true)));
		HX_STACK_LINE(514)
		object = Objects->__GetItem(index2);
		HX_STACK_LINE(515)
		hx::IndexRef((Objects).mPtr,index2) = Objects->__GetItem(index1);
		HX_STACK_LINE(516)
		hx::IndexRef((Objects).mPtr,index1) = object;
		HX_STACK_LINE(517)
		(i)++;
	}
	HX_STACK_LINE(519)
	return Objects;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxG_obj,shuffle,return )

Dynamic FlxG_obj::getRandom( Dynamic Objects,hx::Null< int >  __o_StartIndex,hx::Null< int >  __o_Length){
int StartIndex = __o_StartIndex.Default(0);
int Length = __o_Length.Default(0);
	HX_STACK_PUSH("FlxG::getRandom","org/flixel/FlxG.hx",533);
	HX_STACK_ARG(Objects,"Objects");
	HX_STACK_ARG(StartIndex,"StartIndex");
	HX_STACK_ARG(Length,"Length");
{
		HX_STACK_LINE(534)
		if (((Objects != null()))){
			HX_STACK_LINE(536)
			if (((StartIndex < (int)0))){
				HX_STACK_LINE(536)
				StartIndex = (int)0;
			}
			HX_STACK_LINE(537)
			if (((Length < (int)0))){
				HX_STACK_LINE(537)
				Length = (int)0;
			}
			HX_STACK_LINE(539)
			int l = Length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(540)
			if (((bool((l == (int)0)) || bool((l > (Objects->__Field(HX_CSTRING("length"),true) - StartIndex)))))){
				HX_STACK_LINE(541)
				l = (Objects->__Field(HX_CSTRING("length"),true) - StartIndex);
			}
			HX_STACK_LINE(544)
			if (((l > (int)0))){
				struct _Function_3_1{
					inline static Float Block( ){
						HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",546);
						{
							HX_STACK_LINE(546)
							::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
							HX_STACK_LINE(546)
							if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
								HX_STACK_LINE(546)
								hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
							}
							HX_STACK_LINE(546)
							return ::org::flixel::FlxG_obj::globalSeed;
						}
						return null();
					}
				};
				HX_STACK_LINE(545)
				return Objects->__GetItem((StartIndex + ::Std_obj::_int((_Function_3_1::Block() * l))));
			}
		}
		HX_STACK_LINE(549)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxG_obj,getRandom,return )

Void FlxG_obj::loadReplay( ::String Data,::org::flixel::FlxState State,Array< ::String > CancelKeys,hx::Null< Float >  __o_Timeout,Dynamic Callback){
Float Timeout = __o_Timeout.Default(0);
	HX_STACK_PUSH("FlxG::loadReplay","org/flixel/FlxG.hx",562);
	HX_STACK_ARG(Data,"Data");
	HX_STACK_ARG(State,"State");
	HX_STACK_ARG(CancelKeys,"CancelKeys");
	HX_STACK_ARG(Timeout,"Timeout");
	HX_STACK_ARG(Callback,"Callback");
{
		HX_STACK_LINE(563)
		::org::flixel::FlxG_obj::_game->_replay->load(Data);
		HX_STACK_LINE(564)
		if (((State == null()))){
			HX_STACK_LINE(565)
			::org::flixel::FlxG_obj::resetGame();
		}
		else{
			HX_STACK_LINE(569)
			::org::flixel::FlxG_obj::switchState(State);
		}
		HX_STACK_LINE(572)
		::org::flixel::FlxG_obj::_game->_replayCancelKeys = CancelKeys;
		HX_STACK_LINE(573)
		::org::flixel::FlxG_obj::_game->_replayTimer = ::Std_obj::_int((Timeout * (int)1000));
		HX_STACK_LINE(574)
		::org::flixel::FlxG_obj::_game->_replayCallback = Callback;
		HX_STACK_LINE(575)
		::org::flixel::FlxG_obj::_game->_replayRequested = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxG_obj,loadReplay,(void))

Void FlxG_obj::reloadReplay( hx::Null< bool >  __o_StandardMode){
bool StandardMode = __o_StandardMode.Default(true);
	HX_STACK_PUSH("FlxG::reloadReplay","org/flixel/FlxG.hx",584);
	HX_STACK_ARG(StandardMode,"StandardMode");
{
		HX_STACK_LINE(585)
		if ((StandardMode)){
			HX_STACK_LINE(586)
			::org::flixel::FlxG_obj::resetGame();
		}
		else{
			HX_STACK_LINE(590)
			::org::flixel::FlxG_obj::resetState();
		}
		HX_STACK_LINE(595)
		if (((::org::flixel::FlxG_obj::_game->_replay->frameCount > (int)0))){
			HX_STACK_LINE(596)
			::org::flixel::FlxG_obj::_game->_replayRequested = true;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,reloadReplay,(void))

Void FlxG_obj::stopReplay( ){
{
		HX_STACK_PUSH("FlxG::stopReplay","org/flixel/FlxG.hx",607);
		HX_STACK_LINE(608)
		::org::flixel::FlxG_obj::_game->_replaying = false;
		HX_STACK_LINE(610)
		if (((::org::flixel::FlxG_obj::_game->_debugger != null()))){
			HX_STACK_LINE(611)
			::org::flixel::FlxG_obj::_game->_debugger->vcr->stopped();
		}
		HX_STACK_LINE(615)
		::org::flixel::FlxG_obj::resetInput();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,stopReplay,(void))

Void FlxG_obj::recordReplay( hx::Null< bool >  __o_StandardMode){
bool StandardMode = __o_StandardMode.Default(true);
	HX_STACK_PUSH("FlxG::recordReplay","org/flixel/FlxG.hx",623);
	HX_STACK_ARG(StandardMode,"StandardMode");
{
		HX_STACK_LINE(624)
		if ((StandardMode)){
			HX_STACK_LINE(625)
			::org::flixel::FlxG_obj::resetGame();
		}
		else{
			HX_STACK_LINE(629)
			::org::flixel::FlxG_obj::resetState();
		}
		HX_STACK_LINE(632)
		::org::flixel::FlxG_obj::_game->_recordingRequested = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,recordReplay,(void))

::String FlxG_obj::stopRecording( ){
	HX_STACK_PUSH("FlxG::stopRecording","org/flixel/FlxG.hx",640);
	HX_STACK_LINE(641)
	::org::flixel::FlxG_obj::_game->_recording = false;
	HX_STACK_LINE(643)
	if (((::org::flixel::FlxG_obj::_game->_debugger != null()))){
		HX_STACK_LINE(644)
		::org::flixel::FlxG_obj::_game->_debugger->vcr->stopped();
	}
	HX_STACK_LINE(648)
	return ::org::flixel::FlxG_obj::_game->_replay->save();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,stopRecording,return )

Void FlxG_obj::resetState( ){
{
		HX_STACK_PUSH("FlxG::resetState","org/flixel/FlxG.hx",656);
		struct _Function_1_1{
			inline static ::String Block( ){
				HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",657);
				{
					HX_STACK_LINE(657)
					::String s = ::Type_obj::getClassName(::Type_obj::getClass(::org::flixel::FlxG_obj::_game->_state));		HX_STACK_VAR(s,"s");
					HX_STACK_LINE(657)
					if (((s != null()))){
						HX_STACK_LINE(657)
						s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
						HX_STACK_LINE(657)
						{
						}
					}
					HX_STACK_LINE(657)
					return s;
				}
				return null();
			}
		};
		HX_STACK_LINE(657)
		::org::flixel::FlxG_obj::_game->_requestedState = ::Type_obj::createInstance(::Type_obj::resolveClass(_Function_1_1::Block()),Dynamic( Array_obj<Dynamic>::__new()));
		HX_STACK_LINE(659)
		if ((::Std_obj::is(::org::flixel::FlxG_obj::_game->_requestedState,hx::ClassOf< ::org::flixel::FlxSubState >()))){
			HX_STACK_LINE(660)
			hx::Throw (HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,resetState,(void))

Void FlxG_obj::resetGame( ){
{
		HX_STACK_PUSH("FlxG::resetGame","org/flixel/FlxG.hx",670);
		HX_STACK_LINE(670)
		::org::flixel::FlxG_obj::_game->_requestedReset = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,resetGame,(void))

Void FlxG_obj::resetInput( ){
{
		HX_STACK_PUSH("FlxG::resetInput","org/flixel/FlxG.hx",678);
		HX_STACK_LINE(678)
		::org::flixel::system::input::FlxInputs_obj::resetInputs();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,resetInput,(void))

Void FlxG_obj::playMusic( Dynamic Music,hx::Null< Float >  __o_Volume){
Float Volume = __o_Volume.Default(1.0);
	HX_STACK_PUSH("FlxG::playMusic","org/flixel/FlxG.hx",689);
	HX_STACK_ARG(Music,"Music");
	HX_STACK_ARG(Volume,"Volume");
{
		HX_STACK_LINE(690)
		if (((::org::flixel::FlxG_obj::music == null()))){
			HX_STACK_LINE(691)
			::org::flixel::FlxG_obj::music = ::org::flixel::FlxSound_obj::__new();
		}
		else{
			HX_STACK_LINE(694)
			if ((::org::flixel::FlxG_obj::music->active)){
				HX_STACK_LINE(695)
				::org::flixel::FlxG_obj::music->stop();
			}
		}
		HX_STACK_LINE(698)
		::org::flixel::FlxG_obj::music->loadEmbedded(Music,true,null());
		HX_STACK_LINE(699)
		::org::flixel::FlxG_obj::music->set_volume(Volume);
		HX_STACK_LINE(700)
		::org::flixel::FlxG_obj::music->survive = true;
		HX_STACK_LINE(701)
		::org::flixel::FlxG_obj::music->play(null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxG_obj,playMusic,(void))

::org::flixel::FlxSound FlxG_obj::loadSound( Dynamic EmbeddedSound,hx::Null< Float >  __o_Volume,hx::Null< bool >  __o_Looped,hx::Null< bool >  __o_AutoDestroy,hx::Null< bool >  __o_AutoPlay,::String URL){
Float Volume = __o_Volume.Default(1.0);
bool Looped = __o_Looped.Default(false);
bool AutoDestroy = __o_AutoDestroy.Default(false);
bool AutoPlay = __o_AutoPlay.Default(false);
	HX_STACK_PUSH("FlxG::loadSound","org/flixel/FlxG.hx",715);
	HX_STACK_ARG(EmbeddedSound,"EmbeddedSound");
	HX_STACK_ARG(Volume,"Volume");
	HX_STACK_ARG(Looped,"Looped");
	HX_STACK_ARG(AutoDestroy,"AutoDestroy");
	HX_STACK_ARG(AutoPlay,"AutoPlay");
	HX_STACK_ARG(URL,"URL");
{
		HX_STACK_LINE(716)
		if (((bool((EmbeddedSound == null())) && bool((URL == null()))))){
			HX_STACK_LINE(718)
			if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
				struct _Function_3_1{
					inline static ::String Block( ){
						HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",718);
						{
							HX_STACK_LINE(718)
							Dynamic AnyArray = hx::TCastToArray(HX_CSTRING("WARNING: FlxG.loadSound() requires either\nan embedded sound or a URL to work."));		HX_STACK_VAR(AnyArray,"AnyArray");
							HX_STACK_LINE(718)
							::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
							HX_STACK_LINE(718)
							if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
								HX_STACK_LINE(718)
								string = ::Std_obj::string(AnyArray->__GetItem((int)0));
								HX_STACK_LINE(718)
								int i = (int)1;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(718)
								int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
								HX_STACK_LINE(718)
								while(((i < l))){
									HX_STACK_LINE(718)
									hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
								}
							}
							HX_STACK_LINE(718)
							return string;
						}
						return null();
					}
				};
				HX_STACK_LINE(718)
				::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  ((::Std_obj::is(HX_CSTRING("WARNING: FlxG.loadSound() requires either\nan embedded sound or a URL to work."),hx::ClassOf< Array<int> >()))) ? ::String(_Function_3_1::Block()) : ::String(::Std_obj::string(HX_CSTRING("WARNING: FlxG.loadSound() requires either\nan embedded sound or a URL to work."))) ));
			}
			HX_STACK_LINE(719)
			return null();
		}
		HX_STACK_LINE(721)
		::org::flixel::FlxSound sound = ::org::flixel::FlxG_obj::sounds->recycle(hx::ClassOf< ::org::flixel::FlxSound >());		HX_STACK_VAR(sound,"sound");
		HX_STACK_LINE(722)
		if (((EmbeddedSound != null()))){
			HX_STACK_LINE(723)
			sound->loadEmbedded(EmbeddedSound,Looped,AutoDestroy);
		}
		else{
			HX_STACK_LINE(727)
			sound->loadStream(URL,Looped,AutoDestroy);
		}
		HX_STACK_LINE(730)
		sound->set_volume(Volume);
		HX_STACK_LINE(731)
		if ((AutoPlay)){
			HX_STACK_LINE(732)
			sound->play(null());
		}
		HX_STACK_LINE(735)
		return sound;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(FlxG_obj,loadSound,return )

::org::flixel::FlxSound FlxG_obj::play( Dynamic EmbeddedSound,hx::Null< Float >  __o_Volume,hx::Null< bool >  __o_Looped,hx::Null< bool >  __o_AutoDestroy){
Float Volume = __o_Volume.Default(1.0);
bool Looped = __o_Looped.Default(false);
bool AutoDestroy = __o_AutoDestroy.Default(true);
	HX_STACK_PUSH("FlxG::play","org/flixel/FlxG.hx",788);
	HX_STACK_ARG(EmbeddedSound,"EmbeddedSound");
	HX_STACK_ARG(Volume,"Volume");
	HX_STACK_ARG(Looped,"Looped");
	HX_STACK_ARG(AutoDestroy,"AutoDestroy");
{
		HX_STACK_LINE(788)
		return ::org::flixel::FlxG_obj::loadSound(EmbeddedSound,Volume,Looped,AutoDestroy,true,null());
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxG_obj,play,return )

::org::flixel::FlxSound FlxG_obj::stream( ::String URL,hx::Null< Float >  __o_Volume,hx::Null< bool >  __o_Looped,hx::Null< bool >  __o_AutoDestroy){
Float Volume = __o_Volume.Default(1.0);
bool Looped = __o_Looped.Default(false);
bool AutoDestroy = __o_AutoDestroy.Default(true);
	HX_STACK_PUSH("FlxG::stream","org/flixel/FlxG.hx",803);
	HX_STACK_ARG(URL,"URL");
	HX_STACK_ARG(Volume,"Volume");
	HX_STACK_ARG(Looped,"Looped");
	HX_STACK_ARG(AutoDestroy,"AutoDestroy");
{
		HX_STACK_LINE(803)
		return ::org::flixel::FlxG_obj::loadSound(null(),Volume,Looped,AutoDestroy,true,URL);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxG_obj,stream,return )

Float FlxG_obj::volume;

Float FlxG_obj::setVolume( Float Volume){
	HX_STACK_PUSH("FlxG::setVolume","org/flixel/FlxG.hx",819);
	HX_STACK_ARG(Volume,"Volume");
	HX_STACK_LINE(820)
	::org::flixel::FlxG_obj::volume = Volume;
	HX_STACK_LINE(821)
	if (((::org::flixel::FlxG_obj::volume < (int)0))){
		HX_STACK_LINE(822)
		::org::flixel::FlxG_obj::volume = (int)0;
	}
	else{
		HX_STACK_LINE(825)
		if (((::org::flixel::FlxG_obj::volume > (int)1))){
			HX_STACK_LINE(826)
			::org::flixel::FlxG_obj::volume = (int)1;
		}
	}
	HX_STACK_LINE(829)
	if (((::org::flixel::FlxG_obj::volumeHandler_dyn() != null()))){
		HX_STACK_LINE(831)
		Float param = (  ((::org::flixel::FlxG_obj::mute)) ? Float((int)0) : Float(::org::flixel::FlxG_obj::volume) );		HX_STACK_VAR(param,"param");
		HX_STACK_LINE(832)
		::org::flixel::FlxG_obj::volumeHandler(param);
	}
	HX_STACK_LINE(834)
	return Volume;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,setVolume,return )

Void FlxG_obj::destroySounds( hx::Null< bool >  __o_ForceDestroy){
bool ForceDestroy = __o_ForceDestroy.Default(false);
	HX_STACK_PUSH("FlxG::destroySounds","org/flixel/FlxG.hx",843);
	HX_STACK_ARG(ForceDestroy,"ForceDestroy");
{
		HX_STACK_LINE(844)
		if (((bool((::org::flixel::FlxG_obj::music != null())) && bool(((bool(ForceDestroy) || bool(!(::org::flixel::FlxG_obj::music->survive)))))))){
			HX_STACK_LINE(846)
			::org::flixel::FlxG_obj::music->destroy();
			HX_STACK_LINE(847)
			::org::flixel::FlxG_obj::music = null();
		}
		HX_STACK_LINE(849)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(850)
		::org::flixel::FlxSound sound;		HX_STACK_VAR(sound,"sound");
		HX_STACK_LINE(851)
		int l = ::org::flixel::FlxG_obj::sounds->members->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(852)
		while(((i < l))){
			HX_STACK_LINE(854)
			sound = ::org::flixel::FlxG_obj::sounds->members->__GetItem((i)++);
			HX_STACK_LINE(855)
			if (((bool((sound != null())) && bool(((bool(ForceDestroy) || bool(!(sound->survive)))))))){
				HX_STACK_LINE(856)
				sound->destroy();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,destroySounds,(void))

Void FlxG_obj::updateSounds( ){
{
		HX_STACK_PUSH("FlxG::updateSounds","org/flixel/FlxG.hx",866);
		HX_STACK_LINE(867)
		if (((bool((::org::flixel::FlxG_obj::music != null())) && bool(::org::flixel::FlxG_obj::music->active)))){
			HX_STACK_LINE(868)
			::org::flixel::FlxG_obj::music->update();
		}
		HX_STACK_LINE(871)
		if (((bool((::org::flixel::FlxG_obj::sounds != null())) && bool(::org::flixel::FlxG_obj::sounds->active)))){
			HX_STACK_LINE(872)
			::org::flixel::FlxG_obj::sounds->update();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,updateSounds,(void))

Void FlxG_obj::pauseSounds( ){
{
		HX_STACK_PUSH("FlxG::pauseSounds","org/flixel/FlxG.hx",881);
		HX_STACK_LINE(882)
		if (((bool((bool((::org::flixel::FlxG_obj::music != null())) && bool(::org::flixel::FlxG_obj::music->exists))) && bool(::org::flixel::FlxG_obj::music->active)))){
			HX_STACK_LINE(883)
			::org::flixel::FlxG_obj::music->pause();
		}
		HX_STACK_LINE(886)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(887)
		::org::flixel::FlxSound sound;		HX_STACK_VAR(sound,"sound");
		HX_STACK_LINE(888)
		int l = ::org::flixel::FlxG_obj::sounds->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(889)
		while(((i < l))){
			HX_STACK_LINE(891)
			sound = ::org::flixel::FlxG_obj::sounds->members->__GetItem((i)++);
			HX_STACK_LINE(892)
			if (((bool((bool((sound != null())) && bool(sound->exists))) && bool(sound->active)))){
				HX_STACK_LINE(893)
				sound->pause();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,pauseSounds,(void))

Void FlxG_obj::resumeSounds( ){
{
		HX_STACK_PUSH("FlxG::resumeSounds","org/flixel/FlxG.hx",903);
		HX_STACK_LINE(904)
		if (((bool((::org::flixel::FlxG_obj::music != null())) && bool(::org::flixel::FlxG_obj::music->exists)))){
			HX_STACK_LINE(905)
			::org::flixel::FlxG_obj::music->play(null());
		}
		HX_STACK_LINE(908)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(909)
		::org::flixel::FlxSound sound;		HX_STACK_VAR(sound,"sound");
		HX_STACK_LINE(910)
		int l = ::org::flixel::FlxG_obj::sounds->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(911)
		while(((i < l))){
			HX_STACK_LINE(913)
			sound = ::org::flixel::FlxG_obj::sounds->members->__GetItem((i)++);
			HX_STACK_LINE(914)
			if (((bool((sound != null())) && bool(sound->exists)))){
				HX_STACK_LINE(915)
				sound->resume();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,resumeSounds,(void))

bool FlxG_obj::checkBitmapCache( ::String Key){
	HX_STACK_PUSH("FlxG::checkBitmapCache","org/flixel/FlxG.hx",927);
	HX_STACK_ARG(Key,"Key");
	HX_STACK_LINE(927)
	return (bool(::org::flixel::FlxG_obj::_cache->exists(Key)) && bool((::org::flixel::FlxG_obj::_cache->get(Key) != null())));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,checkBitmapCache,return )

::native::display::BitmapData FlxG_obj::createBitmap( int Width,int Height,int Color,hx::Null< bool >  __o_Unique,::String Key){
bool Unique = __o_Unique.Default(false);
	HX_STACK_PUSH("FlxG::createBitmap","org/flixel/FlxG.hx",945);
	HX_STACK_ARG(Width,"Width");
	HX_STACK_ARG(Height,"Height");
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Unique,"Unique");
	HX_STACK_ARG(Key,"Key");
{
		HX_STACK_LINE(946)
		::String key = Key;		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(947)
		if (((key == null()))){
			HX_STACK_LINE(950)
			key = ((((Width + HX_CSTRING("x")) + Height) + HX_CSTRING(":")) + Color);
			HX_STACK_LINE(954)
			if (((bool(Unique) && bool(::org::flixel::FlxG_obj::checkBitmapCache(key))))){
				HX_STACK_LINE(955)
				key = ::org::flixel::FlxG_obj::getUniqueBitmapKey(key);
			}
		}
		HX_STACK_LINE(959)
		if ((!(::org::flixel::FlxG_obj::checkBitmapCache(key)))){
			HX_STACK_LINE(960)
			::org::flixel::FlxG_obj::_cache->set(key,::native::display::BitmapData_obj::__new(Width,Height,true,Color,null()));
		}
		HX_STACK_LINE(963)
		::org::flixel::FlxG_obj::_lastBitmapDataKey = key;
		HX_STACK_LINE(964)
		return ::org::flixel::FlxG_obj::_cache->get(key);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxG_obj,createBitmap,return )

::native::display::BitmapData FlxG_obj::addBitmap( Dynamic Graphic,hx::Null< bool >  __o_Reverse,hx::Null< bool >  __o_Unique,::String Key,hx::Null< int >  __o_FrameWidth,hx::Null< int >  __o_FrameHeight){
bool Reverse = __o_Reverse.Default(false);
bool Unique = __o_Unique.Default(false);
int FrameWidth = __o_FrameWidth.Default(0);
int FrameHeight = __o_FrameHeight.Default(0);
	HX_STACK_PUSH("FlxG::addBitmap","org/flixel/FlxG.hx",976);
	HX_STACK_ARG(Graphic,"Graphic");
	HX_STACK_ARG(Reverse,"Reverse");
	HX_STACK_ARG(Unique,"Unique");
	HX_STACK_ARG(Key,"Key");
	HX_STACK_ARG(FrameWidth,"FrameWidth");
	HX_STACK_ARG(FrameHeight,"FrameHeight");
{
		HX_STACK_LINE(977)
		if (((Graphic == null()))){
			HX_STACK_LINE(978)
			return null();
		}
		HX_STACK_LINE(982)
		bool isClass = true;		HX_STACK_VAR(isClass,"isClass");
		HX_STACK_LINE(983)
		bool isBitmap = true;		HX_STACK_VAR(isBitmap,"isBitmap");
		HX_STACK_LINE(984)
		if ((::Std_obj::is(Graphic,hx::ClassOf< ::Class >()))){
			HX_STACK_LINE(986)
			isClass = true;
			HX_STACK_LINE(987)
			isBitmap = false;
		}
		else{
			HX_STACK_LINE(989)
			if ((::Std_obj::is(Graphic,hx::ClassOf< ::native::display::BitmapData >()))){
				HX_STACK_LINE(991)
				isClass = false;
				HX_STACK_LINE(992)
				isBitmap = true;
			}
			else{
				HX_STACK_LINE(994)
				if ((::Std_obj::is(Graphic,hx::ClassOf< ::String >()))){
					HX_STACK_LINE(996)
					isClass = false;
					HX_STACK_LINE(997)
					isBitmap = false;
				}
				else{
					HX_STACK_LINE(1000)
					return null();
				}
			}
		}
		HX_STACK_LINE(1004)
		::String additionalKey = HX_CSTRING("");		HX_STACK_VAR(additionalKey,"additionalKey");
		HX_STACK_LINE(1006)
		if (((bool((FrameWidth != (int)0)) || bool((FrameHeight != (int)0))))){
			HX_STACK_LINE(1007)
			additionalKey = (((HX_CSTRING("FrameSize:") + FrameWidth) + HX_CSTRING("_")) + FrameHeight);
		}
		HX_STACK_LINE(1012)
		::String key = Key;		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(1013)
		if (((key == null()))){
			HX_STACK_LINE(1015)
			if ((isClass)){
				HX_STACK_LINE(1016)
				key = ::Type_obj::getClassName(hx::TCast< Class >::cast(Graphic));
			}
			else{
				HX_STACK_LINE(1019)
				if ((isBitmap)){
					HX_STACK_LINE(1020)
					if ((!(Unique))){
						HX_STACK_LINE(1023)
						key = ::org::flixel::FlxG_obj::getCacheKeyFor(Graphic);
						HX_STACK_LINE(1024)
						if (((key == null()))){
							HX_STACK_LINE(1025)
							key = ::org::flixel::FlxG_obj::getUniqueBitmapKey(null());
						}
					}
				}
				else{
					HX_STACK_LINE(1031)
					key = Graphic;
				}
			}
			HX_STACK_LINE(1034)
			hx::AddEq(key,(  ((Reverse)) ? ::String(HX_CSTRING("_REVERSE_")) : ::String(HX_CSTRING("")) ));
			HX_STACK_LINE(1035)
			hx::AddEq(key,additionalKey);
			HX_STACK_LINE(1037)
			if ((Unique)){
				HX_STACK_LINE(1038)
				key = ::org::flixel::FlxG_obj::getUniqueBitmapKey((  (((key == null()))) ? ::String(HX_CSTRING("pixels")) : ::String(key) ));
			}
		}
		HX_STACK_LINE(1043)
		::native::display::BitmapData tempBitmap;		HX_STACK_VAR(tempBitmap,"tempBitmap");
		HX_STACK_LINE(1046)
		if ((!(::org::flixel::FlxG_obj::checkBitmapCache(key)))){
			HX_STACK_LINE(1048)
			::native::display::BitmapData bd = null();		HX_STACK_VAR(bd,"bd");
			HX_STACK_LINE(1049)
			if ((isClass)){
				HX_STACK_LINE(1050)
				bd = ::Type_obj::createInstance(hx::TCast< Class >::cast(Graphic),Dynamic( Array_obj<Dynamic>::__new()))->__Field(HX_CSTRING("bitmapData"),true);
			}
			else{
				HX_STACK_LINE(1053)
				if ((isBitmap)){
					HX_STACK_LINE(1054)
					bd = Graphic;
				}
				else{
					HX_STACK_LINE(1058)
					bd = ::org::flixel::FlxAssets_obj::getBitmapData(Graphic);
				}
			}
			HX_STACK_LINE(1063)
			if (((additionalKey != HX_CSTRING("")))){
				HX_STACK_LINE(1065)
				int numHorizontalFrames = (  (((FrameWidth == (int)0))) ? int((int)1) : int(::Std_obj::_int((Float(bd->get_width()) / Float(FrameWidth)))) );		HX_STACK_VAR(numHorizontalFrames,"numHorizontalFrames");
				HX_STACK_LINE(1066)
				int numVerticalFrames = (  (((FrameHeight == (int)0))) ? int((int)1) : int(::Std_obj::_int((Float(bd->get_height()) / Float(FrameHeight)))) );		HX_STACK_VAR(numVerticalFrames,"numVerticalFrames");
				HX_STACK_LINE(1068)
				FrameWidth = (  (((FrameWidth == (int)0))) ? int(bd->get_width()) : int(FrameWidth) );
				HX_STACK_LINE(1069)
				FrameHeight = (  (((FrameHeight == (int)0))) ? int(bd->get_height()) : int(FrameHeight) );
				HX_STACK_LINE(1071)
				::native::display::BitmapData tempBitmap1 = ::native::display::BitmapData_obj::__new((bd->get_width() + numHorizontalFrames),(bd->get_height() + numVerticalFrames),true,(int)0,null());		HX_STACK_VAR(tempBitmap1,"tempBitmap1");
				HX_STACK_LINE(1073)
				::native::geom::Rectangle tempRect = ::native::geom::Rectangle_obj::__new((int)0,(int)0,FrameWidth,FrameHeight);		HX_STACK_VAR(tempRect,"tempRect");
				HX_STACK_LINE(1074)
				::native::geom::Point tempPoint = ::native::geom::Point_obj::__new(null(),null());		HX_STACK_VAR(tempPoint,"tempPoint");
				HX_STACK_LINE(1076)
				{
					HX_STACK_LINE(1076)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = numHorizontalFrames;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(1076)
					while(((_g1 < _g))){
						HX_STACK_LINE(1076)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(1078)
						tempPoint->x = (i * ((FrameWidth + (int)1)));
						HX_STACK_LINE(1079)
						tempRect->x = (i * FrameWidth);
						HX_STACK_LINE(1081)
						{
							HX_STACK_LINE(1081)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							int _g2 = numVerticalFrames;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(1081)
							while(((_g3 < _g2))){
								HX_STACK_LINE(1081)
								int j = (_g3)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(1083)
								tempPoint->y = (j * ((FrameHeight + (int)1)));
								HX_STACK_LINE(1084)
								tempRect->y = (j * FrameHeight);
								HX_STACK_LINE(1085)
								tempBitmap1->copyPixels(bd,tempRect,tempPoint,null(),null(),null());
							}
						}
					}
				}
				HX_STACK_LINE(1089)
				bd = tempBitmap1;
			}
			else{
				HX_STACK_LINE(1104)
				if ((Unique)){
					HX_STACK_LINE(1105)
					bd = bd->clone();
				}
			}
			HX_STACK_LINE(1109)
			::org::flixel::FlxG_obj::_cache->set(key,bd);
		}
		HX_STACK_LINE(1112)
		::org::flixel::FlxG_obj::_lastBitmapDataKey = key;
		HX_STACK_LINE(1113)
		return ::org::flixel::FlxG_obj::_cache->get(key);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(FlxG_obj,addBitmap,return )

::String FlxG_obj::getCacheKeyFor( ::native::display::BitmapData bmd){
	HX_STACK_PUSH("FlxG::getCacheKeyFor","org/flixel/FlxG.hx",1122);
	HX_STACK_ARG(bmd,"bmd");
	HX_STACK_LINE(1123)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(::org::flixel::FlxG_obj::_cache->keys());  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(1125)
			::native::display::BitmapData data = ::org::flixel::FlxG_obj::_cache->get(key);		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(1126)
			if (((data == bmd))){
				HX_STACK_LINE(1127)
				return key;
			}
		}
;
	}
	HX_STACK_LINE(1131)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,getCacheKeyFor,return )

::String FlxG_obj::getUniqueBitmapKey( ::String __o_baseKey){
::String baseKey = __o_baseKey.Default(HX_CSTRING("pixels"));
	HX_STACK_PUSH("FlxG::getUniqueBitmapKey","org/flixel/FlxG.hx",1140);
	HX_STACK_ARG(baseKey,"baseKey");
{
		HX_STACK_LINE(1141)
		if ((::org::flixel::FlxG_obj::checkBitmapCache(baseKey))){
			HX_STACK_LINE(1143)
			int inc = (int)0;		HX_STACK_VAR(inc,"inc");
			HX_STACK_LINE(1144)
			::String ukey;		HX_STACK_VAR(ukey,"ukey");
			HX_STACK_LINE(1145)
			do{
				HX_STACK_LINE(1146)
				ukey = (baseKey + (inc)++);
			}
while((::org::flixel::FlxG_obj::checkBitmapCache(ukey)));
			HX_STACK_LINE(1149)
			baseKey = ukey;
		}
		HX_STACK_LINE(1151)
		return baseKey;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,getUniqueBitmapKey,return )

bool FlxG_obj::fromAssetsCache( ::native::display::BitmapData bmd){
	HX_STACK_PUSH("FlxG::fromAssetsCache","org/flixel/FlxG.hx",1155);
	HX_STACK_ARG(bmd,"bmd");
	HX_STACK_LINE(1156)
	::Hash cachedBitmapData = ::nme::installer::Assets_obj::cachedBitmapData;		HX_STACK_VAR(cachedBitmapData,"cachedBitmapData");
	HX_STACK_LINE(1157)
	if (((cachedBitmapData != null()))){
		HX_STACK_LINE(1158)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(cachedBitmapData->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(1161)
				::native::display::BitmapData cacheBmd = cachedBitmapData->get(key);		HX_STACK_VAR(cacheBmd,"cacheBmd");
				HX_STACK_LINE(1162)
				if (((cacheBmd == bmd))){
					HX_STACK_LINE(1163)
					return true;
				}
			}
;
		}
	}
	HX_STACK_LINE(1168)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,fromAssetsCache,return )

Void FlxG_obj::removeBitmap( ::String Graphic){
{
		HX_STACK_PUSH("FlxG::removeBitmap","org/flixel/FlxG.hx",1176);
		HX_STACK_ARG(Graphic,"Graphic");
		HX_STACK_LINE(1176)
		if ((::org::flixel::FlxG_obj::_cache->exists(Graphic))){
			HX_STACK_LINE(1179)
			::native::display::BitmapData bmd = ::org::flixel::FlxG_obj::_cache->get(Graphic);		HX_STACK_VAR(bmd,"bmd");
			HX_STACK_LINE(1180)
			::org::flixel::FlxG_obj::_cache->remove(Graphic);
			HX_STACK_LINE(1181)
			if (((::org::flixel::FlxG_obj::fromAssetsCache(bmd) == false))){
				HX_STACK_LINE(1183)
				bmd->dispose();
				HX_STACK_LINE(1184)
				bmd = null();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,removeBitmap,(void))

Void FlxG_obj::clearBitmapCache( ){
{
		HX_STACK_PUSH("FlxG::clearBitmapCache","org/flixel/FlxG.hx",1193);
		HX_STACK_LINE(1194)
		::native::display::BitmapData bmd;		HX_STACK_VAR(bmd,"bmd");
		HX_STACK_LINE(1195)
		if (((::org::flixel::FlxG_obj::_cache != null()))){
			HX_STACK_LINE(1196)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(::org::flixel::FlxG_obj::_cache->keys());  __it->hasNext(); ){
				::String key = __it->next();
				{
					HX_STACK_LINE(1199)
					bmd = ::org::flixel::FlxG_obj::_cache->get(key);
					HX_STACK_LINE(1200)
					::org::flixel::FlxG_obj::_cache->remove(key);
					HX_STACK_LINE(1201)
					if (((bool((bmd != null())) && bool((::org::flixel::FlxG_obj::fromAssetsCache(bmd) == false))))){
						HX_STACK_LINE(1203)
						bmd->dispose();
						HX_STACK_LINE(1204)
						bmd = null();
					}
				}
;
			}
		}
		HX_STACK_LINE(1208)
		::org::flixel::FlxG_obj::_cache = ::Hash_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,clearBitmapCache,(void))

Void FlxG_obj::clearAssetsCache( ){
{
		HX_STACK_PUSH("FlxG::clearAssetsCache","org/flixel/FlxG.hx",1215);
		HX_STACK_LINE(1215)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(::nme::installer::Assets_obj::cachedBitmapData->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(1218)
				::native::display::BitmapData bmd = ::nme::installer::Assets_obj::cachedBitmapData->get(key);		HX_STACK_VAR(bmd,"bmd");
				HX_STACK_LINE(1219)
				bmd->dispose();
				HX_STACK_LINE(1220)
				::nme::installer::Assets_obj::cachedBitmapData->remove(key);
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,clearAssetsCache,(void))

::native::display::Stage FlxG_obj::stage;

::native::display::Stage FlxG_obj::get_stage( ){
	HX_STACK_PUSH("FlxG::get_stage","org/flixel/FlxG.hx",1231);
	HX_STACK_LINE(1232)
	if (((::org::flixel::FlxG_obj::_game->get_stage() != null()))){
		HX_STACK_LINE(1233)
		return ::org::flixel::FlxG_obj::_game->get_stage();
	}
	HX_STACK_LINE(1236)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,get_stage,return )

::org::flixel::FlxState FlxG_obj::state;

::org::flixel::FlxState FlxG_obj::get_state( ){
	HX_STACK_PUSH("FlxG::get_state","org/flixel/FlxG.hx",1245);
	HX_STACK_LINE(1245)
	return ::org::flixel::FlxG_obj::_game->_state;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,get_state,return )

Void FlxG_obj::switchState( ::org::flixel::FlxState State){
{
		HX_STACK_PUSH("FlxG::switchState","org/flixel/FlxG.hx",1253);
		HX_STACK_ARG(State,"State");
		HX_STACK_LINE(1253)
		::org::flixel::FlxG_obj::_game->_requestedState = State;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,switchState,(void))

Void FlxG_obj::setDebuggerLayout( int Layout){
{
		HX_STACK_PUSH("FlxG::setDebuggerLayout","org/flixel/FlxG.hx",1263);
		HX_STACK_ARG(Layout,"Layout");
		HX_STACK_LINE(1263)
		::org::flixel::FlxG_obj::_game->_debugger->setLayout(Layout);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,setDebuggerLayout,(void))

Void FlxG_obj::resetDebuggerLayout( ){
{
		HX_STACK_PUSH("FlxG::resetDebuggerLayout","org/flixel/FlxG.hx",1271);
		HX_STACK_LINE(1271)
		::org::flixel::FlxG_obj::_game->_debugger->resetLayout();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,resetDebuggerLayout,(void))

::org::flixel::FlxCamera FlxG_obj::addCamera( ::org::flixel::FlxCamera NewCamera){
	HX_STACK_PUSH("FlxG::addCamera","org/flixel/FlxG.hx",1283);
	HX_STACK_ARG(NewCamera,"NewCamera");
	HX_STACK_LINE(1284)
	::org::flixel::FlxG_obj::_game->addChildAt(NewCamera->_flashSprite,::org::flixel::FlxG_obj::_game->getChildIndex(::org::flixel::FlxG_obj::_game->_inputContainer));
	HX_STACK_LINE(1285)
	::org::flixel::FlxG_obj::cameras->push(NewCamera);
	HX_STACK_LINE(1286)
	NewCamera->ID = (::org::flixel::FlxG_obj::cameras->length - (int)1);
	HX_STACK_LINE(1287)
	return NewCamera;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,addCamera,return )

Void FlxG_obj::removeCamera( ::org::flixel::FlxCamera Camera,hx::Null< bool >  __o_Destroy){
bool Destroy = __o_Destroy.Default(true);
	HX_STACK_PUSH("FlxG::removeCamera","org/flixel/FlxG.hx",1296);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_ARG(Destroy,"Destroy");
{
		HX_STACK_LINE(1297)
		if (((bool((Camera != null())) && bool(::org::flixel::FlxG_obj::_game->contains(Camera->_flashSprite))))){
			HX_STACK_LINE(1299)
			::org::flixel::FlxG_obj::_game->removeChild(Camera->_flashSprite);
			struct _Function_2_1{
				inline static int Block( ::org::flixel::FlxCamera &Camera){
					HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",1300);
					{
						HX_STACK_LINE(1300)
						Dynamic array = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(array,"array");
						int fromIndex = (int)0;		HX_STACK_VAR(fromIndex,"fromIndex");
						HX_STACK_LINE(1300)
						int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
						HX_STACK_LINE(1300)
						int index = (int)-1;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(1300)
						{
							HX_STACK_LINE(1300)
							int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(1300)
							while(((_g < len))){
								HX_STACK_LINE(1300)
								int i = (_g)++;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(1300)
								if (((array->__GetItem(i) == Camera))){
									HX_STACK_LINE(1300)
									index = i;
									HX_STACK_LINE(1300)
									break;
								}
							}
						}
						HX_STACK_LINE(1300)
						return index;
					}
					return null();
				}
			};
			HX_STACK_LINE(1300)
			int index = _Function_2_1::Block(Camera);		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(1301)
			if (((index >= (int)0))){
				HX_STACK_LINE(1302)
				::org::flixel::FlxG_obj::cameras->splice(index,(int)1);
			}
		}
		else{
			HX_STACK_LINE(1305)
			if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
				struct _Function_3_1{
					inline static ::String Block( ){
						HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",1306);
						{
							HX_STACK_LINE(1306)
							Dynamic AnyArray = hx::TCastToArray(HX_CSTRING("Error removing camera, not part of game."));		HX_STACK_VAR(AnyArray,"AnyArray");
							HX_STACK_LINE(1306)
							::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
							HX_STACK_LINE(1306)
							if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
								HX_STACK_LINE(1306)
								string = ::Std_obj::string(AnyArray->__GetItem((int)0));
								HX_STACK_LINE(1306)
								int i = (int)1;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(1306)
								int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
								HX_STACK_LINE(1306)
								while(((i < l))){
									HX_STACK_LINE(1306)
									hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
								}
							}
							HX_STACK_LINE(1306)
							return string;
						}
						return null();
					}
				};
				HX_STACK_LINE(1306)
				::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  ((::Std_obj::is(HX_CSTRING("Error removing camera, not part of game."),hx::ClassOf< Array<int> >()))) ? ::String(_Function_3_1::Block()) : ::String(::Std_obj::string(HX_CSTRING("Error removing camera, not part of game."))) ));
			}
		}
		HX_STACK_LINE(1310)
		{
			HX_STACK_LINE(1310)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::org::flixel::FlxG_obj::cameras->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1310)
			while(((_g1 < _g))){
				HX_STACK_LINE(1310)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1312)
				::org::flixel::FlxG_obj::cameras->__get(i)->ID = i;
			}
		}
		HX_STACK_LINE(1316)
		if ((Destroy)){
			HX_STACK_LINE(1317)
			Camera->destroy();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxG_obj,removeCamera,(void))

Void FlxG_obj::resetCameras( ::org::flixel::FlxCamera NewCamera){
{
		HX_STACK_PUSH("FlxG::resetCameras","org/flixel/FlxG.hx",1329);
		HX_STACK_ARG(NewCamera,"NewCamera");
		HX_STACK_LINE(1330)
		::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
		HX_STACK_LINE(1331)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1332)
		int l = ::org::flixel::FlxG_obj::cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1333)
		while(((i < l))){
			HX_STACK_LINE(1335)
			cam = ::org::flixel::FlxG_obj::cameras->__get((i)++);
			HX_STACK_LINE(1336)
			::org::flixel::FlxG_obj::_game->removeChild(cam->_flashSprite);
			HX_STACK_LINE(1337)
			cam->destroy();
		}
		HX_STACK_LINE(1339)
		::org::flixel::FlxG_obj::cameras->splice((int)0,::org::flixel::FlxG_obj::cameras->length);
		HX_STACK_LINE(1341)
		if (((NewCamera == null()))){
			HX_STACK_LINE(1342)
			NewCamera = ::org::flixel::FlxCamera_obj::__new((int)0,(int)0,::org::flixel::FlxG_obj::width,::org::flixel::FlxG_obj::height,null());
		}
		HX_STACK_LINE(1344)
		::org::flixel::FlxG_obj::camera = ::org::flixel::FlxG_obj::addCamera(NewCamera);
		HX_STACK_LINE(1345)
		NewCamera->ID = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,resetCameras,(void))

Void FlxG_obj::flash( Dynamic Color,hx::Null< Float >  __o_Duration,Dynamic OnComplete,hx::Null< bool >  __o_Force){
Float Duration = __o_Duration.Default(1);
bool Force = __o_Force.Default(false);
	HX_STACK_PUSH("FlxG::flash","org/flixel/FlxG.hx",1360);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Duration,"Duration");
	HX_STACK_ARG(OnComplete,"OnComplete");
	HX_STACK_ARG(Force,"Force");
{
		HX_STACK_LINE(1362)
		if (((Color == null()))){
			HX_STACK_LINE(1363)
			Color = (int)-1;
		}
		HX_STACK_LINE(1368)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1369)
		int l = ::org::flixel::FlxG_obj::cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1370)
		while(((i < l))){
			HX_STACK_LINE(1371)
			::org::flixel::FlxG_obj::cameras->__get((i)++)->flash(Color,Duration,OnComplete,Force);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxG_obj,flash,(void))

Void FlxG_obj::fade( Dynamic Color,hx::Null< Float >  __o_Duration,hx::Null< bool >  __o_FadeIn,Dynamic OnComplete,hx::Null< bool >  __o_Force){
Float Duration = __o_Duration.Default(1);
bool FadeIn = __o_FadeIn.Default(false);
bool Force = __o_Force.Default(false);
	HX_STACK_PUSH("FlxG::fade","org/flixel/FlxG.hx",1389);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Duration,"Duration");
	HX_STACK_ARG(FadeIn,"FadeIn");
	HX_STACK_ARG(OnComplete,"OnComplete");
	HX_STACK_ARG(Force,"Force");
{
		HX_STACK_LINE(1391)
		if (((Color == null()))){
			HX_STACK_LINE(1392)
			Color = (int)-16777216;
		}
		HX_STACK_LINE(1397)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1398)
		int l = ::org::flixel::FlxG_obj::cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1399)
		while(((i < l))){
			HX_STACK_LINE(1400)
			::org::flixel::FlxG_obj::cameras->__get((i)++)->fade(Color,Duration,FadeIn,OnComplete,Force);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxG_obj,fade,(void))

Void FlxG_obj::shake( hx::Null< Float >  __o_Intensity,hx::Null< Float >  __o_Duration,Dynamic OnComplete,hx::Null< bool >  __o_Force,hx::Null< int >  __o_Direction){
Float Intensity = __o_Intensity.Default(0.05);
Float Duration = __o_Duration.Default(0.5);
bool Force = __o_Force.Default(true);
int Direction = __o_Direction.Default(0);
	HX_STACK_PUSH("FlxG::shake","org/flixel/FlxG.hx",1414);
	HX_STACK_ARG(Intensity,"Intensity");
	HX_STACK_ARG(Duration,"Duration");
	HX_STACK_ARG(OnComplete,"OnComplete");
	HX_STACK_ARG(Force,"Force");
	HX_STACK_ARG(Direction,"Direction");
{
		HX_STACK_LINE(1415)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1416)
		int l = ::org::flixel::FlxG_obj::cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1417)
		while(((i < l))){
			HX_STACK_LINE(1418)
			::org::flixel::FlxG_obj::cameras->__get((i)++)->shake(Intensity,Duration,OnComplete,Force,Direction);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxG_obj,shake,(void))

int FlxG_obj::get_bgColor( ){
	HX_STACK_PUSH("FlxG::get_bgColor","org/flixel/FlxG.hx",1433);
	HX_STACK_LINE(1433)
	if (((::org::flixel::FlxG_obj::camera == null()))){
		HX_STACK_LINE(1435)
		return (int)-16777216;
	}
	else{
		HX_STACK_LINE(1439)
		return ::org::flixel::FlxG_obj::camera->bgColor;
	}
	HX_STACK_LINE(1433)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,get_bgColor,return )

int FlxG_obj::set_bgColor( int Color){
	HX_STACK_PUSH("FlxG::set_bgColor","org/flixel/FlxG.hx",1449);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_LINE(1450)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1451)
	int l = ::org::flixel::FlxG_obj::cameras->length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1452)
	while(((i < l))){
		HX_STACK_LINE(1453)
		::org::flixel::FlxG_obj::cameras->__get((i)++)->bgColor = Color;
	}
	HX_STACK_LINE(1456)
	return Color;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,set_bgColor,return )

bool FlxG_obj::overlap( ::org::flixel::FlxBasic ObjectOrGroup1,::org::flixel::FlxBasic ObjectOrGroup2,Dynamic NotifyCallback,Dynamic ProcessCallback){
	HX_STACK_PUSH("FlxG::overlap","org/flixel/FlxG.hx",1472);
	HX_STACK_ARG(ObjectOrGroup1,"ObjectOrGroup1");
	HX_STACK_ARG(ObjectOrGroup2,"ObjectOrGroup2");
	HX_STACK_ARG(NotifyCallback,"NotifyCallback");
	HX_STACK_ARG(ProcessCallback,"ProcessCallback");
	HX_STACK_LINE(1473)
	if (((ObjectOrGroup1 == null()))){
		HX_STACK_LINE(1474)
		ObjectOrGroup1 = ::org::flixel::FlxG_obj::get_state();
	}
	HX_STACK_LINE(1477)
	if (((ObjectOrGroup2 == ObjectOrGroup1))){
		HX_STACK_LINE(1478)
		ObjectOrGroup2 = null();
	}
	HX_STACK_LINE(1481)
	::org::flixel::system::FlxQuadTree_obj::divisions = ::org::flixel::FlxG_obj::worldDivisions;
	HX_STACK_LINE(1482)
	::org::flixel::system::FlxQuadTree quadTree = ::org::flixel::system::FlxQuadTree_obj::recycle(::org::flixel::FlxG_obj::worldBounds->x,::org::flixel::FlxG_obj::worldBounds->y,::org::flixel::FlxG_obj::worldBounds->width,::org::flixel::FlxG_obj::worldBounds->height,null());		HX_STACK_VAR(quadTree,"quadTree");
	HX_STACK_LINE(1483)
	quadTree->load(ObjectOrGroup1,ObjectOrGroup2,NotifyCallback,ProcessCallback);
	HX_STACK_LINE(1484)
	bool result = quadTree->execute();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(1485)
	quadTree->destroy();
	HX_STACK_LINE(1486)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxG_obj,overlap,return )

bool FlxG_obj::collide( ::org::flixel::FlxBasic ObjectOrGroup1,::org::flixel::FlxBasic ObjectOrGroup2,Dynamic NotifyCallback){
	HX_STACK_PUSH("FlxG::collide","org/flixel/FlxG.hx",1503);
	HX_STACK_ARG(ObjectOrGroup1,"ObjectOrGroup1");
	HX_STACK_ARG(ObjectOrGroup2,"ObjectOrGroup2");
	HX_STACK_ARG(NotifyCallback,"NotifyCallback");
	struct _Function_1_1{
		inline static bool Block( ::org::flixel::FlxBasic &ObjectOrGroup2,Dynamic &NotifyCallback,::org::flixel::FlxBasic &ObjectOrGroup1){
			HX_STACK_PUSH("*::closure","org/flixel/FlxG.hx",1504);
			{
				HX_STACK_LINE(1504)
				::org::flixel::FlxBasic ObjectOrGroup11 = ObjectOrGroup1;		HX_STACK_VAR(ObjectOrGroup11,"ObjectOrGroup11");
				::org::flixel::FlxBasic ObjectOrGroup21 = ObjectOrGroup2;		HX_STACK_VAR(ObjectOrGroup21,"ObjectOrGroup21");
				HX_STACK_LINE(1504)
				if (((ObjectOrGroup11 == null()))){
					HX_STACK_LINE(1504)
					ObjectOrGroup11 = ::org::flixel::FlxG_obj::get_state();
				}
				HX_STACK_LINE(1504)
				if (((ObjectOrGroup21 == ObjectOrGroup11))){
					HX_STACK_LINE(1504)
					ObjectOrGroup21 = null();
				}
				HX_STACK_LINE(1504)
				::org::flixel::system::FlxQuadTree_obj::divisions = ::org::flixel::FlxG_obj::worldDivisions;
				HX_STACK_LINE(1504)
				::org::flixel::system::FlxQuadTree quadTree = ::org::flixel::system::FlxQuadTree_obj::recycle(::org::flixel::FlxG_obj::worldBounds->x,::org::flixel::FlxG_obj::worldBounds->y,::org::flixel::FlxG_obj::worldBounds->width,::org::flixel::FlxG_obj::worldBounds->height,null());		HX_STACK_VAR(quadTree,"quadTree");
				HX_STACK_LINE(1504)
				quadTree->load(ObjectOrGroup11,ObjectOrGroup21,NotifyCallback,::org::flixel::FlxObject_obj::separate_dyn());
				HX_STACK_LINE(1504)
				bool result = quadTree->execute();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(1504)
				quadTree->destroy();
				HX_STACK_LINE(1504)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1503)
	return _Function_1_1::Block(ObjectOrGroup2,NotifyCallback,ObjectOrGroup1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxG_obj,collide,return )

::org::flixel::FlxBasic FlxG_obj::addPlugin( ::org::flixel::FlxBasic Plugin){
	HX_STACK_PUSH("FlxG::addPlugin","org/flixel/FlxG.hx",1513);
	HX_STACK_ARG(Plugin,"Plugin");
	HX_STACK_LINE(1515)
	Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
	HX_STACK_LINE(1516)
	int l = pluginList->length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1517)
	{
		HX_STACK_LINE(1517)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1517)
		while(((_g < l))){
			HX_STACK_LINE(1517)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1519)
			if (((pluginList->__get(i)->toString() == Plugin->toString()))){
				HX_STACK_LINE(1520)
				return Plugin;
			}
		}
	}
	HX_STACK_LINE(1526)
	pluginList->push(Plugin);
	HX_STACK_LINE(1527)
	return Plugin;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,addPlugin,return )

::org::flixel::FlxBasic FlxG_obj::getPlugin( ::Class ClassType){
	HX_STACK_PUSH("FlxG::getPlugin","org/flixel/FlxG.hx",1536);
	HX_STACK_ARG(ClassType,"ClassType");
	HX_STACK_LINE(1537)
	Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
	HX_STACK_LINE(1538)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1539)
	int l = pluginList->length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1540)
	while(((i < l))){
		HX_STACK_LINE(1542)
		if ((::Std_obj::is(pluginList->__get(i),ClassType))){
			HX_STACK_LINE(1543)
			return ::org::flixel::FlxG_obj::plugins->__get(i);
		}
		HX_STACK_LINE(1546)
		(i)++;
	}
	HX_STACK_LINE(1548)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,getPlugin,return )

::org::flixel::FlxBasic FlxG_obj::removePlugin( ::org::flixel::FlxBasic Plugin){
	HX_STACK_PUSH("FlxG::removePlugin","org/flixel/FlxG.hx",1557);
	HX_STACK_ARG(Plugin,"Plugin");
	HX_STACK_LINE(1559)
	Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
	HX_STACK_LINE(1560)
	int i = (pluginList->length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1561)
	while(((i >= (int)0))){
		HX_STACK_LINE(1563)
		if (((pluginList->__get(i) == Plugin))){
			HX_STACK_LINE(1565)
			pluginList->splice(i,(int)1);
			HX_STACK_LINE(1566)
			return Plugin;
		}
		HX_STACK_LINE(1568)
		(i)--;
	}
	HX_STACK_LINE(1570)
	return Plugin;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,removePlugin,return )

bool FlxG_obj::removePluginType( ::Class ClassType){
	HX_STACK_PUSH("FlxG::removePluginType","org/flixel/FlxG.hx",1579);
	HX_STACK_ARG(ClassType,"ClassType");
	HX_STACK_LINE(1581)
	bool results = false;		HX_STACK_VAR(results,"results");
	HX_STACK_LINE(1582)
	Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
	HX_STACK_LINE(1583)
	int i = (pluginList->length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1584)
	while(((i >= (int)0))){
		HX_STACK_LINE(1586)
		if ((::Std_obj::is(pluginList->__get(i),ClassType))){
			HX_STACK_LINE(1588)
			pluginList->splice(i,(int)1);
			HX_STACK_LINE(1589)
			results = true;
		}
		HX_STACK_LINE(1591)
		(i)--;
	}
	HX_STACK_LINE(1593)
	return results;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxG_obj,removePluginType,return )

Void FlxG_obj::init( ::org::flixel::FlxGame Game,int Width,int Height,Float Zoom){
{
		HX_STACK_PUSH("FlxG::init","org/flixel/FlxG.hx",1600);
		HX_STACK_ARG(Game,"Game");
		HX_STACK_ARG(Width,"Width");
		HX_STACK_ARG(Height,"Height");
		HX_STACK_ARG(Zoom,"Zoom");
		HX_STACK_LINE(1603)
		::org::flixel::FlxG_obj::clearBitmapCache();
		HX_STACK_LINE(1605)
		::org::flixel::FlxG_obj::_game = Game;
		HX_STACK_LINE(1606)
		::org::flixel::FlxG_obj::width = ::Std_obj::_int(::Math_obj::abs(Width));
		HX_STACK_LINE(1607)
		::org::flixel::FlxG_obj::height = ::Std_obj::_int(::Math_obj::abs(Height));
		HX_STACK_LINE(1609)
		::org::flixel::FlxG_obj::mute = false;
		HX_STACK_LINE(1610)
		::org::flixel::FlxG_obj::setVolume(0.5);
		HX_STACK_LINE(1611)
		::org::flixel::FlxG_obj::sounds = ::org::flixel::FlxTypedGroup_obj::__new(null());
		HX_STACK_LINE(1612)
		::org::flixel::FlxG_obj::volumeHandler = null();
		HX_STACK_LINE(1614)
		if (((::org::flixel::FlxG_obj::flashGfxSprite == null()))){
			HX_STACK_LINE(1616)
			::org::flixel::FlxG_obj::flashGfxSprite = ::native::display::Sprite_obj::__new();
			HX_STACK_LINE(1617)
			::org::flixel::FlxG_obj::flashGfx = ::org::flixel::FlxG_obj::flashGfxSprite->get_graphics();
		}
		HX_STACK_LINE(1620)
		::org::flixel::FlxCamera_obj::defaultZoom = Zoom;
		HX_STACK_LINE(1621)
		::org::flixel::FlxG_obj::_cameraRect = ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());
		HX_STACK_LINE(1622)
		::org::flixel::FlxG_obj::cameras = Array_obj< ::org::flixel::FlxCamera >::__new();
		HX_STACK_LINE(1623)
		::org::flixel::FlxG_obj::useBufferLocking = false;
		HX_STACK_LINE(1625)
		::org::flixel::FlxG_obj::plugins = Array_obj< ::org::flixel::FlxBasic >::__new();
		HX_STACK_LINE(1628)
		::org::flixel::FlxG_obj::addPlugin(::org::flixel::plugin::DebugPathDisplay_obj::__new());
		HX_STACK_LINE(1631)
		::org::flixel::FlxG_obj::addPlugin(::org::flixel::plugin::TimerManager_obj::__new());
		HX_STACK_LINE(1636)
		::org::flixel::FlxG_obj::mobile = false;
		HX_STACK_LINE(1639)
		::org::flixel::FlxG_obj::levels = Dynamic( Array_obj<Dynamic>::__new() );
		HX_STACK_LINE(1640)
		::org::flixel::FlxG_obj::scores = Dynamic( Array_obj<Dynamic>::__new() );
		HX_STACK_LINE(1643)
		::org::flixel::FlxG_obj::visualDebug = false;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxG_obj,init,(void))

Void FlxG_obj::reset( ){
{
		HX_STACK_PUSH("FlxG::reset","org/flixel/FlxG.hx",1651);
		HX_STACK_LINE(1653)
		::org::flixel::plugin::pxText::PxBitmapFont_obj::clearStorage();
		HX_STACK_LINE(1654)
		::org::flixel::system::layer::Atlas_obj::clearAtlasCache();
		HX_STACK_LINE(1655)
		::org::flixel::system::layer::TileSheetData_obj::clear();
		HX_STACK_LINE(1657)
		::org::flixel::FlxG_obj::clearBitmapCache();
		HX_STACK_LINE(1658)
		::org::flixel::FlxG_obj::resetInput();
		HX_STACK_LINE(1659)
		::org::flixel::FlxG_obj::destroySounds(true);
		HX_STACK_LINE(1660)
		::org::flixel::FlxG_obj::levels = Dynamic( Array_obj<Dynamic>::__new());
		HX_STACK_LINE(1661)
		::org::flixel::FlxG_obj::scores = Dynamic( Array_obj<Dynamic>::__new());
		HX_STACK_LINE(1662)
		::org::flixel::FlxG_obj::level = (int)0;
		HX_STACK_LINE(1663)
		::org::flixel::FlxG_obj::score = (int)0;
		HX_STACK_LINE(1664)
		::org::flixel::FlxG_obj::paused = false;
		HX_STACK_LINE(1665)
		::org::flixel::FlxG_obj::timeScale = 1.0;
		HX_STACK_LINE(1666)
		::org::flixel::FlxG_obj::elapsed = (int)0;
		HX_STACK_LINE(1667)
		::org::flixel::FlxG_obj::globalSeed = ::Math_obj::random();
		HX_STACK_LINE(1668)
		::org::flixel::FlxG_obj::worldBounds = ::org::flixel::FlxRect_obj::__new((int)-10,(int)-10,(::org::flixel::FlxG_obj::width + (int)20),(::org::flixel::FlxG_obj::height + (int)20));
		HX_STACK_LINE(1669)
		::org::flixel::FlxG_obj::worldDivisions = (int)6;
		HX_STACK_LINE(1671)
		::org::flixel::plugin::DebugPathDisplay debugPathDisplay = hx::TCast< org::flixel::plugin::DebugPathDisplay >::cast(::org::flixel::FlxG_obj::getPlugin(hx::ClassOf< ::org::flixel::plugin::DebugPathDisplay >()));		HX_STACK_VAR(debugPathDisplay,"debugPathDisplay");
		HX_STACK_LINE(1672)
		if (((debugPathDisplay != null()))){
			HX_STACK_LINE(1673)
			debugPathDisplay->clear();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,reset,(void))

Void FlxG_obj::updateInputs( ){
{
		HX_STACK_PUSH("FlxG::updateInputs","org/flixel/FlxG.hx",1683);
		HX_STACK_LINE(1684)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1684)
		int l = ::org::flixel::system::input::FlxInputs_obj::inputs->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1684)
		while(((i < l))){
			HX_STACK_LINE(1684)
			::org::flixel::system::input::IFlxInput input = ::org::flixel::system::input::FlxInputs_obj::inputs->__get((i)++);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(1684)
			input->update();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,updateInputs,(void))

Void FlxG_obj::lockCameras( ){
{
		HX_STACK_PUSH("FlxG::lockCameras","org/flixel/FlxG.hx",1691);
		HX_STACK_LINE(1692)
		::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
		HX_STACK_LINE(1693)
		Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
		HX_STACK_LINE(1694)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1695)
		int l = cams->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1696)
		while(((i < l))){
			HX_STACK_LINE(1698)
			cam = cams->__get((i)++);
			HX_STACK_LINE(1699)
			if (((bool((bool((cam == null())) || bool(!(cam->exists)))) || bool(!(cam->visible))))){
				HX_STACK_LINE(1700)
				continue;
			}
			HX_STACK_LINE(1712)
			{
				HX_STACK_LINE(1712)
				::org::flixel::system::layer::DrawStackItem currItem = cam->_headOfDrawStack->next;		HX_STACK_VAR(currItem,"currItem");
				HX_STACK_LINE(1712)
				while(((currItem != null()))){
					HX_STACK_LINE(1712)
					{
						HX_STACK_LINE(1712)
						currItem->atlas = null();
						HX_STACK_LINE(1712)
						currItem->initialized = false;
						HX_STACK_LINE(1712)
						currItem->position = (int)0;
					}
					HX_STACK_LINE(1712)
					::org::flixel::system::layer::DrawStackItem newStorageHead = currItem;		HX_STACK_VAR(newStorageHead,"newStorageHead");
					HX_STACK_LINE(1712)
					currItem = currItem->next;
					HX_STACK_LINE(1712)
					if (((::org::flixel::FlxCamera_obj::_storageHead == null()))){
						HX_STACK_LINE(1712)
						::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
						HX_STACK_LINE(1712)
						newStorageHead->next = null();
					}
					else{
						HX_STACK_LINE(1712)
						newStorageHead->next = ::org::flixel::FlxCamera_obj::_storageHead;
						HX_STACK_LINE(1712)
						::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
					}
				}
				HX_STACK_LINE(1712)
				{
					HX_STACK_LINE(1712)
					::org::flixel::system::layer::DrawStackItem _this = cam->_headOfDrawStack;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1712)
					_this->atlas = null();
					HX_STACK_LINE(1712)
					_this->initialized = false;
					HX_STACK_LINE(1712)
					_this->position = (int)0;
				}
				HX_STACK_LINE(1712)
				cam->_headOfDrawStack->next = null();
				HX_STACK_LINE(1712)
				cam->_currentStackItem = cam->_headOfDrawStack;
			}
			HX_STACK_LINE(1713)
			cam->_canvas->get_graphics()->clear();
			HX_STACK_LINE(1715)
			cam->_effectsLayer->get_graphics()->clear();
			HX_STACK_LINE(1724)
			cam->fill((int(cam->bgColor) & int((int)16777215)),true,(Float(((int((int(cam->bgColor) >> int((int)24))) & int((int)255)))) / Float((int)255)),null());
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,lockCameras,(void))

Void FlxG_obj::renderCameras( ){
{
		HX_STACK_PUSH("FlxG::renderCameras","org/flixel/FlxG.hx",1731);
		HX_STACK_LINE(1732)
		::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
		HX_STACK_LINE(1733)
		Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
		HX_STACK_LINE(1734)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1735)
		int l = cams->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1736)
		while(((i < l))){
			HX_STACK_LINE(1738)
			cam = cams->__get((i)++);
			HX_STACK_LINE(1739)
			if (((bool((bool((cam == null())) || bool(!(cam->exists)))) || bool(!(cam->visible))))){
				HX_STACK_LINE(1740)
				continue;
			}
			HX_STACK_LINE(1744)
			cam->render();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,renderCameras,(void))

Void FlxG_obj::unlockCameras( ){
{
		HX_STACK_PUSH("FlxG::unlockCameras","org/flixel/FlxG.hx",1753);
		HX_STACK_LINE(1754)
		::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
		HX_STACK_LINE(1755)
		Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
		HX_STACK_LINE(1756)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1757)
		int l = cams->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1758)
		while(((i < l))){
			HX_STACK_LINE(1760)
			cam = cams->__get((i)++);
			HX_STACK_LINE(1761)
			if (((bool((bool((cam == null())) || bool(!(cam->exists)))) || bool(!(cam->visible))))){
				HX_STACK_LINE(1762)
				continue;
			}
			HX_STACK_LINE(1765)
			cam->drawFX();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,unlockCameras,(void))

Void FlxG_obj::updateCameras( ){
{
		HX_STACK_PUSH("FlxG::updateCameras","org/flixel/FlxG.hx",1780);
		HX_STACK_LINE(1781)
		::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
		HX_STACK_LINE(1782)
		Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
		HX_STACK_LINE(1783)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1784)
		int l = cams->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1785)
		while(((i < l))){
			HX_STACK_LINE(1787)
			cam = cams->__get((i)++);
			HX_STACK_LINE(1788)
			if (((bool((cam != null())) && bool(cam->exists)))){
				HX_STACK_LINE(1790)
				if ((cam->active)){
					HX_STACK_LINE(1791)
					cam->update();
				}
				HX_STACK_LINE(1795)
				if (((cam->target == null()))){
					HX_STACK_LINE(1797)
					cam->_flashSprite->set_x((cam->x + cam->_flashOffsetX));
					HX_STACK_LINE(1798)
					cam->_flashSprite->set_y((cam->y + cam->_flashOffsetY));
				}
				HX_STACK_LINE(1801)
				cam->_flashSprite->set_visible(cam->visible);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,updateCameras,(void))

Void FlxG_obj::updatePlugins( ){
{
		HX_STACK_PUSH("FlxG::updatePlugins","org/flixel/FlxG.hx",1810);
		HX_STACK_LINE(1811)
		::org::flixel::FlxBasic plugin;		HX_STACK_VAR(plugin,"plugin");
		HX_STACK_LINE(1812)
		Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
		HX_STACK_LINE(1813)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1814)
		int l = pluginList->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1815)
		while(((i < l))){
			HX_STACK_LINE(1817)
			plugin = pluginList->__get((i)++);
			HX_STACK_LINE(1818)
			if (((bool(plugin->exists) && bool(plugin->active)))){
				HX_STACK_LINE(1819)
				plugin->update();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,updatePlugins,(void))

Void FlxG_obj::drawPlugins( ){
{
		HX_STACK_PUSH("FlxG::drawPlugins","org/flixel/FlxG.hx",1829);
		HX_STACK_LINE(1830)
		::org::flixel::FlxBasic plugin;		HX_STACK_VAR(plugin,"plugin");
		HX_STACK_LINE(1831)
		Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
		HX_STACK_LINE(1832)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1833)
		int l = pluginList->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1834)
		while(((i < l))){
			HX_STACK_LINE(1836)
			plugin = pluginList->__get((i)++);
			HX_STACK_LINE(1837)
			if (((bool(plugin->exists) && bool(plugin->visible)))){
				HX_STACK_LINE(1838)
				plugin->draw();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxG_obj,drawPlugins,(void))

::org::flixel::tweens::misc::MultiVarTween FlxG_obj::tween( Dynamic object,Dynamic values,Float duration,Dynamic options){
	HX_STACK_PUSH("FlxG::tween","org/flixel/FlxG.hx",1858);
	HX_STACK_ARG(object,"object");
	HX_STACK_ARG(values,"values");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(options,"options");
	HX_STACK_LINE(1859)
	int type = (int)8;		HX_STACK_VAR(type,"type");
	Dynamic complete = null();		HX_STACK_VAR(complete,"complete");
	Dynamic ease = null();		HX_STACK_VAR(ease,"ease");
	::org::flixel::FlxBasic tweener = ::org::flixel::FlxG_obj::tweener;		HX_STACK_VAR(tweener,"tweener");
	HX_STACK_LINE(1863)
	if ((::Std_obj::is(object,hx::ClassOf< ::org::flixel::FlxBasic >()))){
		HX_STACK_LINE(1864)
		tweener = hx::TCast< org::flixel::FlxBasic >::cast(object);
	}
	HX_STACK_LINE(1867)
	if (((options != null()))){
		HX_STACK_LINE(1869)
		if ((::Reflect_obj::hasField(options,HX_CSTRING("type")))){
			HX_STACK_LINE(1869)
			type = options->__Field(HX_CSTRING("type"),true);
		}
		HX_STACK_LINE(1870)
		if ((::Reflect_obj::hasField(options,HX_CSTRING("complete")))){
			HX_STACK_LINE(1870)
			complete = options->__Field(HX_CSTRING("complete"),true);
		}
		HX_STACK_LINE(1871)
		if ((::Reflect_obj::hasField(options,HX_CSTRING("ease")))){
			HX_STACK_LINE(1871)
			ease = options->__Field(HX_CSTRING("ease"),true);
		}
		HX_STACK_LINE(1872)
		if ((::Reflect_obj::hasField(options,HX_CSTRING("tweener")))){
			HX_STACK_LINE(1872)
			tweener = options->__Field(HX_CSTRING("tweener"),true);
		}
	}
	HX_STACK_LINE(1874)
	::org::flixel::tweens::misc::MultiVarTween tween = ::org::flixel::tweens::misc::MultiVarTween_obj::__new(complete,type);		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(1875)
	tween->tween(object,values,duration,ease);
	HX_STACK_LINE(1876)
	tweener->addTween(tween,null());
	HX_STACK_LINE(1877)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxG_obj,tween,return )


FlxG_obj::FlxG_obj()
{
}

void FlxG_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxG);
	HX_MARK_END_CLASS();
}

void FlxG_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic FlxG_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { return RED; }
		if (HX_FIELD_EQ(inName,"DEG") ) { return DEG; }
		if (HX_FIELD_EQ(inName,"RAD") ) { return RAD; }
		if (HX_FIELD_EQ(inName,"log") ) { return log_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { return BLUE; }
		if (HX_FIELD_EQ(inName,"PINK") ) { return PINK; }
		if (HX_FIELD_EQ(inName,"save") ) { return save; }
		if (HX_FIELD_EQ(inName,"mute") ) { return mute; }
		if (HX_FIELD_EQ(inName,"keys") ) { return keys; }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"fade") ) { return fade_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"GREEN") ) { return GREEN; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { return WHITE; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { return BLACK; }
		if (HX_FIELD_EQ(inName,"_game") ) { return _game; }
		if (HX_FIELD_EQ(inName,"debug") ) { return debug; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		if (HX_FIELD_EQ(inName,"score") ) { return score; }
		if (HX_FIELD_EQ(inName,"saves") ) { return saves; }
		if (HX_FIELD_EQ(inName,"music") ) { return music; }
		if (HX_FIELD_EQ(inName,"mouse") ) { return mouse; }
		if (HX_FIELD_EQ(inName,"watch") ) { return watch_dyn(); }
		if (HX_FIELD_EQ(inName,"stage") ) { return inCallProp ? get_stage() : stage; }
		if (HX_FIELD_EQ(inName,"state") ) { return inCallProp ? get_state() : state; }
		if (HX_FIELD_EQ(inName,"flash") ) { return flash_dyn(); }
		if (HX_FIELD_EQ(inName,"shake") ) { return shake_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"tween") ) { return tween_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { return paused; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"mobile") ) { return mobile; }
		if (HX_FIELD_EQ(inName,"levels") ) { return levels; }
		if (HX_FIELD_EQ(inName,"scores") ) { return scores; }
		if (HX_FIELD_EQ(inName,"sounds") ) { return sounds; }
		if (HX_FIELD_EQ(inName,"camera") ) { return camera; }
		if (HX_FIELD_EQ(inName,"_cache") ) { return _cache; }
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		if (HX_FIELD_EQ(inName,"stream") ) { return stream_dyn(); }
		if (HX_FIELD_EQ(inName,"volume") ) { return volume; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tweener") ) { return tweener; }
		if (HX_FIELD_EQ(inName,"bgColor") ) { return inCallProp ? get_bgColor() : bgColor; }
		if (HX_FIELD_EQ(inName,"elapsed") ) { return elapsed; }
		if (HX_FIELD_EQ(inName,"cameras") ) { return cameras; }
		if (HX_FIELD_EQ(inName,"plugins") ) { return plugins; }
		if (HX_FIELD_EQ(inName,"unwatch") ) { return unwatch_dyn(); }
		if (HX_FIELD_EQ(inName,"shuffle") ) { return shuffle_dyn(); }
		if (HX_FIELD_EQ(inName,"overlap") ) { return overlap_dyn(); }
		if (HX_FIELD_EQ(inName,"collide") ) { return collide_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flashGfx") ) { return flashGfx; }
		if (HX_FIELD_EQ(inName,"clearLog") ) { return clearLog_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timeScale") ) { return timeScale; }
		if (HX_FIELD_EQ(inName,"framerate") ) { return inCallProp ? get_framerate() : framerate; }
		if (HX_FIELD_EQ(inName,"getRandom") ) { return getRandom_dyn(); }
		if (HX_FIELD_EQ(inName,"resetGame") ) { return resetGame_dyn(); }
		if (HX_FIELD_EQ(inName,"playMusic") ) { return playMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"loadSound") ) { return loadSound_dyn(); }
		if (HX_FIELD_EQ(inName,"setVolume") ) { return setVolume_dyn(); }
		if (HX_FIELD_EQ(inName,"addBitmap") ) { return addBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"get_stage") ) { return get_stage_dyn(); }
		if (HX_FIELD_EQ(inName,"get_state") ) { return get_state_dyn(); }
		if (HX_FIELD_EQ(inName,"addCamera") ) { return addCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"addPlugin") ) { return addPlugin_dyn(); }
		if (HX_FIELD_EQ(inName,"getPlugin") ) { return getPlugin_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"globalSeed") ) { return globalSeed; }
		if (HX_FIELD_EQ(inName,"loadReplay") ) { return loadReplay_dyn(); }
		if (HX_FIELD_EQ(inName,"stopReplay") ) { return stopReplay_dyn(); }
		if (HX_FIELD_EQ(inName,"resetState") ) { return resetState_dyn(); }
		if (HX_FIELD_EQ(inName,"resetInput") ) { return resetInput_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TRANSPARENT") ) { return TRANSPARENT; }
		if (HX_FIELD_EQ(inName,"worldBounds") ) { return worldBounds; }
		if (HX_FIELD_EQ(inName,"visualDebug") ) { return visualDebug; }
		if (HX_FIELD_EQ(inName,"_cameraRect") ) { return _cameraRect; }
		if (HX_FIELD_EQ(inName,"pauseSounds") ) { return pauseSounds_dyn(); }
		if (HX_FIELD_EQ(inName,"switchState") ) { return switchState_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bgColor") ) { return get_bgColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bgColor") ) { return set_bgColor_dyn(); }
		if (HX_FIELD_EQ(inName,"lockCameras") ) { return lockCameras_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPlugins") ) { return drawPlugins_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"LIBRARY_NAME") ) { return LIBRARY_NAME; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_BIG") ) { return DEBUGGER_BIG; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_TOP") ) { return DEBUGGER_TOP; }
		if (HX_FIELD_EQ(inName,"touchManager") ) { return touchManager; }
		if (HX_FIELD_EQ(inName,"reloadReplay") ) { return reloadReplay_dyn(); }
		if (HX_FIELD_EQ(inName,"recordReplay") ) { return recordReplay_dyn(); }
		if (HX_FIELD_EQ(inName,"updateSounds") ) { return updateSounds_dyn(); }
		if (HX_FIELD_EQ(inName,"resumeSounds") ) { return resumeSounds_dyn(); }
		if (HX_FIELD_EQ(inName,"createBitmap") ) { return createBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"removeBitmap") ) { return removeBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"removeCamera") ) { return removeCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"resetCameras") ) { return resetCameras_dyn(); }
		if (HX_FIELD_EQ(inName,"removePlugin") ) { return removePlugin_dyn(); }
		if (HX_FIELD_EQ(inName,"updateInputs") ) { return updateInputs_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DEBUGGER_LEFT") ) { return DEBUGGER_LEFT; }
		if (HX_FIELD_EQ(inName,"volumeHandler") ) { return volumeHandler; }
		if (HX_FIELD_EQ(inName,"get_framerate") ) { return get_framerate_dyn(); }
		if (HX_FIELD_EQ(inName,"set_framerate") ) { return set_framerate_dyn(); }
		if (HX_FIELD_EQ(inName,"stopRecording") ) { return stopRecording_dyn(); }
		if (HX_FIELD_EQ(inName,"destroySounds") ) { return destroySounds_dyn(); }
		if (HX_FIELD_EQ(inName,"renderCameras") ) { return renderCameras_dyn(); }
		if (HX_FIELD_EQ(inName,"unlockCameras") ) { return unlockCameras_dyn(); }
		if (HX_FIELD_EQ(inName,"updateCameras") ) { return updateCameras_dyn(); }
		if (HX_FIELD_EQ(inName,"updatePlugins") ) { return updatePlugins_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"flashFramerate") ) { return inCallProp ? get_flashFramerate() : flashFramerate; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_MICRO") ) { return DEBUGGER_MICRO; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_RIGHT") ) { return DEBUGGER_RIGHT; }
		if (HX_FIELD_EQ(inName,"worldDivisions") ) { return worldDivisions; }
		if (HX_FIELD_EQ(inName,"flashGfxSprite") ) { return flashGfxSprite; }
		if (HX_FIELD_EQ(inName,"getLibraryName") ) { return getLibraryName_dyn(); }
		if (HX_FIELD_EQ(inName,"getCacheKeyFor") ) { return getCacheKeyFor_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"joystickManager") ) { return joystickManager; }
		if (HX_FIELD_EQ(inName,"fromAssetsCache") ) { return fromAssetsCache_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"useBufferLocking") ) { return useBufferLocking; }
		if (HX_FIELD_EQ(inName,"checkBitmapCache") ) { return checkBitmapCache_dyn(); }
		if (HX_FIELD_EQ(inName,"clearBitmapCache") ) { return clearBitmapCache_dyn(); }
		if (HX_FIELD_EQ(inName,"clearAssetsCache") ) { return clearAssetsCache_dyn(); }
		if (HX_FIELD_EQ(inName,"removePluginType") ) { return removePluginType_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"DEBUGGER_STANDARD") ) { return DEBUGGER_STANDARD; }
		if (HX_FIELD_EQ(inName,"setDebuggerLayout") ) { return setDebuggerLayout_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_lastBitmapDataKey") ) { return _lastBitmapDataKey; }
		if (HX_FIELD_EQ(inName,"get_flashFramerate") ) { return get_flashFramerate_dyn(); }
		if (HX_FIELD_EQ(inName,"set_flashFramerate") ) { return set_flashFramerate_dyn(); }
		if (HX_FIELD_EQ(inName,"getUniqueBitmapKey") ) { return getUniqueBitmapKey_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { return supportsTouchEvents; }
		if (HX_FIELD_EQ(inName,"resetDebuggerLayout") ) { return resetDebuggerLayout_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"LIBRARY_MAJOR_VERSION") ) { return LIBRARY_MAJOR_VERSION; }
		if (HX_FIELD_EQ(inName,"LIBRARY_MINOR_VERSION") ) { return LIBRARY_MINOR_VERSION; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxG_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { RED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DEG") ) { DEG=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RAD") ) { RAD=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { BLUE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PINK") ) { PINK=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"save") ) { save=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mute") ) { mute=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keys") ) { keys=inValue.Cast< ::org::flixel::system::input::FlxKeyboard >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"GREEN") ) { GREEN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { WHITE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { BLACK=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_game") ) { _game=inValue.Cast< ::org::flixel::FlxGame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debug") ) { debug=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"score") ) { score=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"saves") ) { saves=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"music") ) { music=inValue.Cast< ::org::flixel::FlxSound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouse") ) { mouse=inValue.Cast< ::org::flixel::system::input::FlxMouse >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< ::org::flixel::FlxState >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mobile") ) { mobile=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"levels") ) { levels=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scores") ) { scores=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sounds") ) { sounds=inValue.Cast< ::org::flixel::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"camera") ) { camera=inValue.Cast< ::org::flixel::FlxCamera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cache") ) { _cache=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"volume") ) { if (inCallProp) return setVolume(inValue);volume=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tweener") ) { tweener=inValue.Cast< ::org::flixel::FlxBasic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bgColor") ) { if (inCallProp) return set_bgColor(inValue);bgColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elapsed") ) { elapsed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cameras") ) { cameras=inValue.Cast< Array< ::org::flixel::FlxCamera > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"plugins") ) { plugins=inValue.Cast< Array< ::org::flixel::FlxBasic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flashGfx") ) { flashGfx=inValue.Cast< ::native::display::Graphics >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timeScale") ) { timeScale=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"framerate") ) { if (inCallProp) return set_framerate(inValue);framerate=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"globalSeed") ) { globalSeed=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TRANSPARENT") ) { TRANSPARENT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"worldBounds") ) { worldBounds=inValue.Cast< ::org::flixel::FlxRect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visualDebug") ) { visualDebug=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cameraRect") ) { _cameraRect=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"LIBRARY_NAME") ) { LIBRARY_NAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_BIG") ) { DEBUGGER_BIG=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_TOP") ) { DEBUGGER_TOP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchManager") ) { touchManager=inValue.Cast< ::org::flixel::system::input::FlxTouchManager >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DEBUGGER_LEFT") ) { DEBUGGER_LEFT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"volumeHandler") ) { volumeHandler=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"flashFramerate") ) { if (inCallProp) return set_flashFramerate(inValue);flashFramerate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_MICRO") ) { DEBUGGER_MICRO=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DEBUGGER_RIGHT") ) { DEBUGGER_RIGHT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"worldDivisions") ) { worldDivisions=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flashGfxSprite") ) { flashGfxSprite=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"joystickManager") ) { joystickManager=inValue.Cast< ::org::flixel::system::input::FlxJoystickManager >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"useBufferLocking") ) { useBufferLocking=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"DEBUGGER_STANDARD") ) { DEBUGGER_STANDARD=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_lastBitmapDataKey") ) { _lastBitmapDataKey=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { supportsTouchEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"LIBRARY_MAJOR_VERSION") ) { LIBRARY_MAJOR_VERSION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LIBRARY_MINOR_VERSION") ) { LIBRARY_MINOR_VERSION=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxG_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("supportsTouchEvents"),
	HX_CSTRING("tweener"),
	HX_CSTRING("bgColor"),
	HX_CSTRING("flashFramerate"),
	HX_CSTRING("LIBRARY_NAME"),
	HX_CSTRING("LIBRARY_MAJOR_VERSION"),
	HX_CSTRING("LIBRARY_MINOR_VERSION"),
	HX_CSTRING("DEBUGGER_STANDARD"),
	HX_CSTRING("DEBUGGER_MICRO"),
	HX_CSTRING("DEBUGGER_BIG"),
	HX_CSTRING("DEBUGGER_TOP"),
	HX_CSTRING("DEBUGGER_LEFT"),
	HX_CSTRING("DEBUGGER_RIGHT"),
	HX_CSTRING("RED"),
	HX_CSTRING("GREEN"),
	HX_CSTRING("BLUE"),
	HX_CSTRING("PINK"),
	HX_CSTRING("WHITE"),
	HX_CSTRING("BLACK"),
	HX_CSTRING("TRANSPARENT"),
	HX_CSTRING("DEG"),
	HX_CSTRING("RAD"),
	HX_CSTRING("_game"),
	HX_CSTRING("paused"),
	HX_CSTRING("debug"),
	HX_CSTRING("elapsed"),
	HX_CSTRING("timeScale"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("worldBounds"),
	HX_CSTRING("worldDivisions"),
	HX_CSTRING("visualDebug"),
	HX_CSTRING("mobile"),
	HX_CSTRING("globalSeed"),
	HX_CSTRING("levels"),
	HX_CSTRING("level"),
	HX_CSTRING("scores"),
	HX_CSTRING("score"),
	HX_CSTRING("saves"),
	HX_CSTRING("save"),
	HX_CSTRING("music"),
	HX_CSTRING("sounds"),
	HX_CSTRING("mute"),
	HX_CSTRING("cameras"),
	HX_CSTRING("camera"),
	HX_CSTRING("useBufferLocking"),
	HX_CSTRING("_cameraRect"),
	HX_CSTRING("plugins"),
	HX_CSTRING("volumeHandler"),
	HX_CSTRING("flashGfxSprite"),
	HX_CSTRING("flashGfx"),
	HX_CSTRING("_cache"),
	HX_CSTRING("_lastBitmapDataKey"),
	HX_CSTRING("mouse"),
	HX_CSTRING("keys"),
	HX_CSTRING("touchManager"),
	HX_CSTRING("joystickManager"),
	HX_CSTRING("getLibraryName"),
	HX_CSTRING("log"),
	HX_CSTRING("clearLog"),
	HX_CSTRING("watch"),
	HX_CSTRING("unwatch"),
	HX_CSTRING("framerate"),
	HX_CSTRING("get_framerate"),
	HX_CSTRING("set_framerate"),
	HX_CSTRING("get_flashFramerate"),
	HX_CSTRING("set_flashFramerate"),
	HX_CSTRING("random"),
	HX_CSTRING("shuffle"),
	HX_CSTRING("getRandom"),
	HX_CSTRING("loadReplay"),
	HX_CSTRING("reloadReplay"),
	HX_CSTRING("stopReplay"),
	HX_CSTRING("recordReplay"),
	HX_CSTRING("stopRecording"),
	HX_CSTRING("resetState"),
	HX_CSTRING("resetGame"),
	HX_CSTRING("resetInput"),
	HX_CSTRING("playMusic"),
	HX_CSTRING("loadSound"),
	HX_CSTRING("play"),
	HX_CSTRING("stream"),
	HX_CSTRING("volume"),
	HX_CSTRING("setVolume"),
	HX_CSTRING("destroySounds"),
	HX_CSTRING("updateSounds"),
	HX_CSTRING("pauseSounds"),
	HX_CSTRING("resumeSounds"),
	HX_CSTRING("checkBitmapCache"),
	HX_CSTRING("createBitmap"),
	HX_CSTRING("addBitmap"),
	HX_CSTRING("getCacheKeyFor"),
	HX_CSTRING("getUniqueBitmapKey"),
	HX_CSTRING("fromAssetsCache"),
	HX_CSTRING("removeBitmap"),
	HX_CSTRING("clearBitmapCache"),
	HX_CSTRING("clearAssetsCache"),
	HX_CSTRING("stage"),
	HX_CSTRING("get_stage"),
	HX_CSTRING("state"),
	HX_CSTRING("get_state"),
	HX_CSTRING("switchState"),
	HX_CSTRING("setDebuggerLayout"),
	HX_CSTRING("resetDebuggerLayout"),
	HX_CSTRING("addCamera"),
	HX_CSTRING("removeCamera"),
	HX_CSTRING("resetCameras"),
	HX_CSTRING("flash"),
	HX_CSTRING("fade"),
	HX_CSTRING("shake"),
	HX_CSTRING("get_bgColor"),
	HX_CSTRING("set_bgColor"),
	HX_CSTRING("overlap"),
	HX_CSTRING("collide"),
	HX_CSTRING("addPlugin"),
	HX_CSTRING("getPlugin"),
	HX_CSTRING("removePlugin"),
	HX_CSTRING("removePluginType"),
	HX_CSTRING("init"),
	HX_CSTRING("reset"),
	HX_CSTRING("updateInputs"),
	HX_CSTRING("lockCameras"),
	HX_CSTRING("renderCameras"),
	HX_CSTRING("unlockCameras"),
	HX_CSTRING("updateCameras"),
	HX_CSTRING("updatePlugins"),
	HX_CSTRING("drawPlugins"),
	HX_CSTRING("tween"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxG_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxG_obj::supportsTouchEvents,"supportsTouchEvents");
	HX_MARK_MEMBER_NAME(FlxG_obj::tweener,"tweener");
	HX_MARK_MEMBER_NAME(FlxG_obj::bgColor,"bgColor");
	HX_MARK_MEMBER_NAME(FlxG_obj::flashFramerate,"flashFramerate");
	HX_MARK_MEMBER_NAME(FlxG_obj::LIBRARY_NAME,"LIBRARY_NAME");
	HX_MARK_MEMBER_NAME(FlxG_obj::LIBRARY_MAJOR_VERSION,"LIBRARY_MAJOR_VERSION");
	HX_MARK_MEMBER_NAME(FlxG_obj::LIBRARY_MINOR_VERSION,"LIBRARY_MINOR_VERSION");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEBUGGER_STANDARD,"DEBUGGER_STANDARD");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEBUGGER_MICRO,"DEBUGGER_MICRO");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEBUGGER_BIG,"DEBUGGER_BIG");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEBUGGER_TOP,"DEBUGGER_TOP");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEBUGGER_LEFT,"DEBUGGER_LEFT");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEBUGGER_RIGHT,"DEBUGGER_RIGHT");
	HX_MARK_MEMBER_NAME(FlxG_obj::RED,"RED");
	HX_MARK_MEMBER_NAME(FlxG_obj::GREEN,"GREEN");
	HX_MARK_MEMBER_NAME(FlxG_obj::BLUE,"BLUE");
	HX_MARK_MEMBER_NAME(FlxG_obj::PINK,"PINK");
	HX_MARK_MEMBER_NAME(FlxG_obj::WHITE,"WHITE");
	HX_MARK_MEMBER_NAME(FlxG_obj::BLACK,"BLACK");
	HX_MARK_MEMBER_NAME(FlxG_obj::TRANSPARENT,"TRANSPARENT");
	HX_MARK_MEMBER_NAME(FlxG_obj::DEG,"DEG");
	HX_MARK_MEMBER_NAME(FlxG_obj::RAD,"RAD");
	HX_MARK_MEMBER_NAME(FlxG_obj::_game,"_game");
	HX_MARK_MEMBER_NAME(FlxG_obj::paused,"paused");
	HX_MARK_MEMBER_NAME(FlxG_obj::debug,"debug");
	HX_MARK_MEMBER_NAME(FlxG_obj::elapsed,"elapsed");
	HX_MARK_MEMBER_NAME(FlxG_obj::timeScale,"timeScale");
	HX_MARK_MEMBER_NAME(FlxG_obj::width,"width");
	HX_MARK_MEMBER_NAME(FlxG_obj::height,"height");
	HX_MARK_MEMBER_NAME(FlxG_obj::worldBounds,"worldBounds");
	HX_MARK_MEMBER_NAME(FlxG_obj::worldDivisions,"worldDivisions");
	HX_MARK_MEMBER_NAME(FlxG_obj::visualDebug,"visualDebug");
	HX_MARK_MEMBER_NAME(FlxG_obj::mobile,"mobile");
	HX_MARK_MEMBER_NAME(FlxG_obj::globalSeed,"globalSeed");
	HX_MARK_MEMBER_NAME(FlxG_obj::levels,"levels");
	HX_MARK_MEMBER_NAME(FlxG_obj::level,"level");
	HX_MARK_MEMBER_NAME(FlxG_obj::scores,"scores");
	HX_MARK_MEMBER_NAME(FlxG_obj::score,"score");
	HX_MARK_MEMBER_NAME(FlxG_obj::saves,"saves");
	HX_MARK_MEMBER_NAME(FlxG_obj::save,"save");
	HX_MARK_MEMBER_NAME(FlxG_obj::music,"music");
	HX_MARK_MEMBER_NAME(FlxG_obj::sounds,"sounds");
	HX_MARK_MEMBER_NAME(FlxG_obj::mute,"mute");
	HX_MARK_MEMBER_NAME(FlxG_obj::cameras,"cameras");
	HX_MARK_MEMBER_NAME(FlxG_obj::camera,"camera");
	HX_MARK_MEMBER_NAME(FlxG_obj::useBufferLocking,"useBufferLocking");
	HX_MARK_MEMBER_NAME(FlxG_obj::_cameraRect,"_cameraRect");
	HX_MARK_MEMBER_NAME(FlxG_obj::plugins,"plugins");
	HX_MARK_MEMBER_NAME(FlxG_obj::volumeHandler,"volumeHandler");
	HX_MARK_MEMBER_NAME(FlxG_obj::flashGfxSprite,"flashGfxSprite");
	HX_MARK_MEMBER_NAME(FlxG_obj::flashGfx,"flashGfx");
	HX_MARK_MEMBER_NAME(FlxG_obj::_cache,"_cache");
	HX_MARK_MEMBER_NAME(FlxG_obj::_lastBitmapDataKey,"_lastBitmapDataKey");
	HX_MARK_MEMBER_NAME(FlxG_obj::mouse,"mouse");
	HX_MARK_MEMBER_NAME(FlxG_obj::keys,"keys");
	HX_MARK_MEMBER_NAME(FlxG_obj::touchManager,"touchManager");
	HX_MARK_MEMBER_NAME(FlxG_obj::joystickManager,"joystickManager");
	HX_MARK_MEMBER_NAME(FlxG_obj::framerate,"framerate");
	HX_MARK_MEMBER_NAME(FlxG_obj::volume,"volume");
	HX_MARK_MEMBER_NAME(FlxG_obj::stage,"stage");
	HX_MARK_MEMBER_NAME(FlxG_obj::state,"state");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxG_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxG_obj::supportsTouchEvents,"supportsTouchEvents");
	HX_VISIT_MEMBER_NAME(FlxG_obj::tweener,"tweener");
	HX_VISIT_MEMBER_NAME(FlxG_obj::bgColor,"bgColor");
	HX_VISIT_MEMBER_NAME(FlxG_obj::flashFramerate,"flashFramerate");
	HX_VISIT_MEMBER_NAME(FlxG_obj::LIBRARY_NAME,"LIBRARY_NAME");
	HX_VISIT_MEMBER_NAME(FlxG_obj::LIBRARY_MAJOR_VERSION,"LIBRARY_MAJOR_VERSION");
	HX_VISIT_MEMBER_NAME(FlxG_obj::LIBRARY_MINOR_VERSION,"LIBRARY_MINOR_VERSION");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEBUGGER_STANDARD,"DEBUGGER_STANDARD");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEBUGGER_MICRO,"DEBUGGER_MICRO");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEBUGGER_BIG,"DEBUGGER_BIG");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEBUGGER_TOP,"DEBUGGER_TOP");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEBUGGER_LEFT,"DEBUGGER_LEFT");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEBUGGER_RIGHT,"DEBUGGER_RIGHT");
	HX_VISIT_MEMBER_NAME(FlxG_obj::RED,"RED");
	HX_VISIT_MEMBER_NAME(FlxG_obj::GREEN,"GREEN");
	HX_VISIT_MEMBER_NAME(FlxG_obj::BLUE,"BLUE");
	HX_VISIT_MEMBER_NAME(FlxG_obj::PINK,"PINK");
	HX_VISIT_MEMBER_NAME(FlxG_obj::WHITE,"WHITE");
	HX_VISIT_MEMBER_NAME(FlxG_obj::BLACK,"BLACK");
	HX_VISIT_MEMBER_NAME(FlxG_obj::TRANSPARENT,"TRANSPARENT");
	HX_VISIT_MEMBER_NAME(FlxG_obj::DEG,"DEG");
	HX_VISIT_MEMBER_NAME(FlxG_obj::RAD,"RAD");
	HX_VISIT_MEMBER_NAME(FlxG_obj::_game,"_game");
	HX_VISIT_MEMBER_NAME(FlxG_obj::paused,"paused");
	HX_VISIT_MEMBER_NAME(FlxG_obj::debug,"debug");
	HX_VISIT_MEMBER_NAME(FlxG_obj::elapsed,"elapsed");
	HX_VISIT_MEMBER_NAME(FlxG_obj::timeScale,"timeScale");
	HX_VISIT_MEMBER_NAME(FlxG_obj::width,"width");
	HX_VISIT_MEMBER_NAME(FlxG_obj::height,"height");
	HX_VISIT_MEMBER_NAME(FlxG_obj::worldBounds,"worldBounds");
	HX_VISIT_MEMBER_NAME(FlxG_obj::worldDivisions,"worldDivisions");
	HX_VISIT_MEMBER_NAME(FlxG_obj::visualDebug,"visualDebug");
	HX_VISIT_MEMBER_NAME(FlxG_obj::mobile,"mobile");
	HX_VISIT_MEMBER_NAME(FlxG_obj::globalSeed,"globalSeed");
	HX_VISIT_MEMBER_NAME(FlxG_obj::levels,"levels");
	HX_VISIT_MEMBER_NAME(FlxG_obj::level,"level");
	HX_VISIT_MEMBER_NAME(FlxG_obj::scores,"scores");
	HX_VISIT_MEMBER_NAME(FlxG_obj::score,"score");
	HX_VISIT_MEMBER_NAME(FlxG_obj::saves,"saves");
	HX_VISIT_MEMBER_NAME(FlxG_obj::save,"save");
	HX_VISIT_MEMBER_NAME(FlxG_obj::music,"music");
	HX_VISIT_MEMBER_NAME(FlxG_obj::sounds,"sounds");
	HX_VISIT_MEMBER_NAME(FlxG_obj::mute,"mute");
	HX_VISIT_MEMBER_NAME(FlxG_obj::cameras,"cameras");
	HX_VISIT_MEMBER_NAME(FlxG_obj::camera,"camera");
	HX_VISIT_MEMBER_NAME(FlxG_obj::useBufferLocking,"useBufferLocking");
	HX_VISIT_MEMBER_NAME(FlxG_obj::_cameraRect,"_cameraRect");
	HX_VISIT_MEMBER_NAME(FlxG_obj::plugins,"plugins");
	HX_VISIT_MEMBER_NAME(FlxG_obj::volumeHandler,"volumeHandler");
	HX_VISIT_MEMBER_NAME(FlxG_obj::flashGfxSprite,"flashGfxSprite");
	HX_VISIT_MEMBER_NAME(FlxG_obj::flashGfx,"flashGfx");
	HX_VISIT_MEMBER_NAME(FlxG_obj::_cache,"_cache");
	HX_VISIT_MEMBER_NAME(FlxG_obj::_lastBitmapDataKey,"_lastBitmapDataKey");
	HX_VISIT_MEMBER_NAME(FlxG_obj::mouse,"mouse");
	HX_VISIT_MEMBER_NAME(FlxG_obj::keys,"keys");
	HX_VISIT_MEMBER_NAME(FlxG_obj::touchManager,"touchManager");
	HX_VISIT_MEMBER_NAME(FlxG_obj::joystickManager,"joystickManager");
	HX_VISIT_MEMBER_NAME(FlxG_obj::framerate,"framerate");
	HX_VISIT_MEMBER_NAME(FlxG_obj::volume,"volume");
	HX_VISIT_MEMBER_NAME(FlxG_obj::stage,"stage");
	HX_VISIT_MEMBER_NAME(FlxG_obj::state,"state");
};

Class FlxG_obj::__mClass;

void FlxG_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxG"), hx::TCanCast< FlxG_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxG_obj::__boot()
{
	supportsTouchEvents= false;
	tweener= ::org::flixel::FlxBasic_obj::__new();
	LIBRARY_NAME= HX_CSTRING("HaxeFlixel");
	LIBRARY_MAJOR_VERSION= HX_CSTRING("1");
	LIBRARY_MINOR_VERSION= HX_CSTRING("09");
	DEBUGGER_STANDARD= (int)0;
	DEBUGGER_MICRO= (int)1;
	DEBUGGER_BIG= (int)2;
	DEBUGGER_TOP= (int)3;
	DEBUGGER_LEFT= (int)4;
	DEBUGGER_RIGHT= (int)5;
	RED= (int)-65518;
	GREEN= (int)-16715227;
	BLUE= (int)-16740119;
	PINK= (int)-1040641;
	WHITE= (int)-1;
	BLACK= (int)-16777216;
	TRANSPARENT= (int)0;
	DEG= (Float((int)180) / Float(::Math_obj::PI));
	RAD= (Float(::Math_obj::PI) / Float((int)180));
}

} // end namespace org
} // end namespace flixel
