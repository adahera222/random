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
#ifndef INCLUDED_native_events_KeyboardEvent
#include <native/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_org_flixel_FlxG
#include <org/flixel/FlxG.h>
#endif
#ifndef INCLUDED_org_flixel_FlxGame
#include <org/flixel/FlxGame.h>
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
#ifndef INCLUDED_org_flixel_system_input_FlxInputStates
#include <org/flixel/system/input/FlxInputStates.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxKeyboard
#include <org/flixel/system/input/FlxKeyboard.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMapObject
#include <org/flixel/system/input/FlxMapObject.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_IFlxInput
#include <org/flixel/system/input/IFlxInput.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace input{

Void FlxKeyboard_obj::__construct()
{
HX_STACK_PUSH("FlxKeyboard::new","org/flixel/system/input/FlxKeyboard.hx",106);
{
	HX_STACK_LINE(107)
	super::__construct();
	HX_STACK_LINE(109)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(112)
	i = (int)65;
	HX_STACK_LINE(113)
	while(((i <= (int)90))){
		HX_STACK_LINE(114)
		this->addKey(::String::fromCharCode(i),(i)++);
	}
	HX_STACK_LINE(119)
	i = (int)48;
	HX_STACK_LINE(120)
	this->addKey(HX_CSTRING("ZERO"),(i)++);
	HX_STACK_LINE(121)
	this->addKey(HX_CSTRING("ONE"),(i)++);
	HX_STACK_LINE(122)
	this->addKey(HX_CSTRING("TWO"),(i)++);
	HX_STACK_LINE(123)
	this->addKey(HX_CSTRING("THREE"),(i)++);
	HX_STACK_LINE(124)
	this->addKey(HX_CSTRING("FOUR"),(i)++);
	HX_STACK_LINE(125)
	this->addKey(HX_CSTRING("FIVE"),(i)++);
	HX_STACK_LINE(126)
	this->addKey(HX_CSTRING("SIX"),(i)++);
	HX_STACK_LINE(127)
	this->addKey(HX_CSTRING("SEVEN"),(i)++);
	HX_STACK_LINE(128)
	this->addKey(HX_CSTRING("EIGHT"),(i)++);
	HX_STACK_LINE(129)
	this->addKey(HX_CSTRING("NINE"),(i)++);
	HX_STACK_LINE(143)
	this->addKey(HX_CSTRING("PAGEUP"),(int)33);
	HX_STACK_LINE(144)
	this->addKey(HX_CSTRING("PAGEDOWN"),(int)34);
	HX_STACK_LINE(145)
	this->addKey(HX_CSTRING("HOME"),(int)36);
	HX_STACK_LINE(146)
	this->addKey(HX_CSTRING("END"),(int)35);
	HX_STACK_LINE(147)
	this->addKey(HX_CSTRING("INSERT"),(int)45);
	HX_STACK_LINE(159)
	this->addKey(HX_CSTRING("ESCAPE"),(int)27);
	HX_STACK_LINE(160)
	this->addKey(HX_CSTRING("MINUS"),(int)189);
	HX_STACK_LINE(161)
	this->addKey(HX_CSTRING("PLUS"),(int)187);
	HX_STACK_LINE(162)
	this->addKey(HX_CSTRING("DELETE"),(int)46);
	HX_STACK_LINE(163)
	this->addKey(HX_CSTRING("BACKSPACE"),(int)8);
	HX_STACK_LINE(164)
	this->addKey(HX_CSTRING("LBRACKET"),(int)219);
	HX_STACK_LINE(165)
	this->addKey(HX_CSTRING("RBRACKET"),(int)221);
	HX_STACK_LINE(166)
	this->addKey(HX_CSTRING("BACKSLASH"),(int)220);
	HX_STACK_LINE(167)
	this->addKey(HX_CSTRING("CAPSLOCK"),(int)20);
	HX_STACK_LINE(168)
	this->addKey(HX_CSTRING("SEMICOLON"),(int)186);
	HX_STACK_LINE(169)
	this->addKey(HX_CSTRING("QUOTE"),(int)222);
	HX_STACK_LINE(170)
	this->addKey(HX_CSTRING("ENTER"),(int)13);
	HX_STACK_LINE(171)
	this->addKey(HX_CSTRING("SHIFT"),(int)16);
	HX_STACK_LINE(172)
	this->addKey(HX_CSTRING("COMMA"),(int)188);
	HX_STACK_LINE(173)
	this->addKey(HX_CSTRING("PERIOD"),(int)190);
	HX_STACK_LINE(174)
	this->addKey(HX_CSTRING("SLASH"),(int)191);
	HX_STACK_LINE(175)
	this->addKey(HX_CSTRING("NUMPADSLASH"),(int)191);
	HX_STACK_LINE(176)
	this->addKey(HX_CSTRING("CONTROL"),(int)17);
	HX_STACK_LINE(177)
	this->addKey(HX_CSTRING("ALT"),(int)18);
	HX_STACK_LINE(178)
	this->addKey(HX_CSTRING("SPACE"),(int)32);
	HX_STACK_LINE(179)
	this->addKey(HX_CSTRING("UP"),(int)38);
	HX_STACK_LINE(180)
	this->addKey(HX_CSTRING("DOWN"),(int)40);
	HX_STACK_LINE(181)
	this->addKey(HX_CSTRING("LEFT"),(int)37);
	HX_STACK_LINE(182)
	this->addKey(HX_CSTRING("RIGHT"),(int)39);
	HX_STACK_LINE(183)
	this->addKey(HX_CSTRING("TAB"),(int)9);
	HX_STACK_LINE(191)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyDown_dyn(),null(),null(),null());
	HX_STACK_LINE(192)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::KeyboardEvent_obj::KEY_UP,this->onKeyUp_dyn(),null(),null(),null());
}
;
	return null();
}

FlxKeyboard_obj::~FlxKeyboard_obj() { }

Dynamic FlxKeyboard_obj::__CreateEmpty() { return  new FlxKeyboard_obj; }
hx::ObjectPtr< FlxKeyboard_obj > FlxKeyboard_obj::__new()
{  hx::ObjectPtr< FlxKeyboard_obj > result = new FlxKeyboard_obj();
	result->__construct();
	return result;}

Dynamic FlxKeyboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxKeyboard_obj > result = new FlxKeyboard_obj();
	result->__construct();
	return result;}

hx::Object *FlxKeyboard_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::org::flixel::system::input::IFlxInput_obj)) return operator ::org::flixel::system::input::IFlxInput_obj *();
	return super::__ToInterface(inType);
}

::String FlxKeyboard_obj::toString( ){
	HX_STACK_PUSH("FlxKeyboard::toString","org/flixel/system/input/FlxKeyboard.hx",338);
	HX_STACK_THIS(this);
	HX_STACK_LINE(338)
	return HX_CSTRING("Keyboard");
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,toString,return )

Void FlxKeyboard_obj::onFocusLost( ){
{
		HX_STACK_PUSH("FlxKeyboard::onFocusLost","org/flixel/system/input/FlxKeyboard.hx",333);
		HX_STACK_THIS(this);
		HX_STACK_LINE(333)
		this->reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,onFocusLost,(void))

Void FlxKeyboard_obj::onFocus( ){
{
		HX_STACK_PUSH("FlxKeyboard::onFocus","org/flixel/system/input/FlxKeyboard.hx",328);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,onFocus,(void))

Void FlxKeyboard_obj::handleKeyDown( ::native::events::KeyboardEvent FlashEvent){
{
		HX_STACK_PUSH("FlxKeyboard::handleKeyDown","org/flixel/system/input/FlxKeyboard.hx",319);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(320)
		::org::flixel::system::input::FlxMapObject o = this->_map->__get(FlashEvent->keyCode);		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(321)
		if (((o == null()))){
			HX_STACK_LINE(321)
			return null();
		}
		HX_STACK_LINE(322)
		if (((o->current > (int)0))){
			HX_STACK_LINE(322)
			o->current = (int)1;
		}
		else{
			HX_STACK_LINE(323)
			o->current = (int)2;
		}
		HX_STACK_LINE(324)
		this->__SetField(o->name,true,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,handleKeyDown,(void))

Void FlxKeyboard_obj::onKeyDown( ::native::events::KeyboardEvent FlashEvent){
{
		HX_STACK_PUSH("FlxKeyboard::onKeyDown","org/flixel/system/input/FlxKeyboard.hx",271);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(274)
		if (((bool(::org::flixel::FlxG_obj::_game->_debuggerUp) && bool(::org::flixel::FlxG_obj::_game->_debugger->watch->editing)))){
			HX_STACK_LINE(275)
			return null();
		}
		HX_STACK_LINE(278)
		if (((bool((bool((bool((bool(::org::flixel::FlxG_obj::_game->_replaying) && bool((::org::flixel::FlxG_obj::_game->_replayCancelKeys != null())))) && bool((::org::flixel::FlxG_obj::_game->_debugger == null())))) && bool((FlashEvent->keyCode != (int)192)))) && bool((FlashEvent->keyCode != (int)220))))){
			HX_STACK_LINE(283)
			bool cancel = false;		HX_STACK_VAR(cancel,"cancel");
			HX_STACK_LINE(284)
			::String replayCancelKey;		HX_STACK_VAR(replayCancelKey,"replayCancelKey");
			HX_STACK_LINE(285)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(286)
			int l = ::org::flixel::FlxG_obj::_game->_replayCancelKeys->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(287)
			while(((i < l))){
				HX_STACK_LINE(289)
				replayCancelKey = ::org::flixel::FlxG_obj::_game->_replayCancelKeys->__get((i)++);
				HX_STACK_LINE(290)
				if (((bool((replayCancelKey == HX_CSTRING("ANY"))) || bool((this->getKeyCode(replayCancelKey) == ::Std_obj::_int(FlashEvent->keyCode)))))){
					HX_STACK_LINE(292)
					if (((::org::flixel::FlxG_obj::_game->_replayCallback_dyn() != null()))){
						HX_STACK_LINE(294)
						::org::flixel::FlxG_obj::_game->_replayCallback();
						HX_STACK_LINE(295)
						::org::flixel::FlxG_obj::_game->_replayCallback = null();
					}
					else{
						HX_STACK_LINE(298)
						::org::flixel::FlxG_obj::stopReplay();
					}
					HX_STACK_LINE(301)
					break;
				}
			}
			HX_STACK_LINE(304)
			return null();
		}
		HX_STACK_LINE(308)
		this->handleKeyDown(FlashEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,onKeyDown,(void))

Void FlxKeyboard_obj::onKeyUp( ::native::events::KeyboardEvent FlashEvent){
{
		HX_STACK_PUSH("FlxKeyboard::onKeyUp","org/flixel/system/input/FlxKeyboard.hx",200);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(202)
		if (((bool(::org::flixel::FlxG_obj::_game->_debuggerUp) && bool(::org::flixel::FlxG_obj::_game->_debugger->watch->editing)))){
			HX_STACK_LINE(203)
			return null();
		}
		HX_STACK_LINE(207)
		if ((!(::org::flixel::FlxG_obj::mobile))){
			HX_STACK_LINE(210)
			if (((bool((::org::flixel::FlxG_obj::_game->_debugger != null())) && bool(((bool((FlashEvent->keyCode == (int)192)) || bool((FlashEvent->keyCode == (int)220)))))))){
				HX_STACK_LINE(212)
				::org::flixel::FlxG_obj::_game->_debugger->set_visible(!(::org::flixel::FlxG_obj::_game->_debugger->get_visible()));
				HX_STACK_LINE(213)
				::org::flixel::FlxG_obj::_game->_debuggerUp = ::org::flixel::FlxG_obj::_game->_debugger->get_visible();
				HX_STACK_LINE(215)
				return null();
			}
			HX_STACK_LINE(218)
			if ((::org::flixel::FlxG_obj::_game->useSoundHotKeys)){
				HX_STACK_LINE(220)
				int c = FlashEvent->keyCode;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(221)
				::String code = ::String::fromCharCode(FlashEvent->charCode);		HX_STACK_VAR(code,"code");
				HX_STACK_LINE(222)
				if (((bool((c == (int)48)) || bool((c == (int)96))))){
					HX_STACK_LINE(224)
					::org::flixel::FlxG_obj::mute = !(::org::flixel::FlxG_obj::mute);
					HX_STACK_LINE(225)
					if (((::org::flixel::FlxG_obj::volumeHandler_dyn() != null()))){
						HX_STACK_LINE(226)
						::org::flixel::FlxG_obj::volumeHandler((  ((::org::flixel::FlxG_obj::mute)) ? Float((int)0) : Float(::org::flixel::FlxG_obj::volume) ));
					}
					HX_STACK_LINE(229)
					::org::flixel::FlxG_obj::_game->showSoundTray(null());
					HX_STACK_LINE(230)
					return null();
				}
				else{
					HX_STACK_LINE(232)
					if (((bool((c == (int)109)) || bool((c == (int)189))))){
						HX_STACK_LINE(234)
						::org::flixel::FlxG_obj::mute = false;
						HX_STACK_LINE(235)
						::org::flixel::FlxG_obj::setVolume((::org::flixel::FlxG_obj::volume - 0.1));
						HX_STACK_LINE(236)
						::org::flixel::FlxG_obj::_game->showSoundTray(null());
						HX_STACK_LINE(237)
						return null();
					}
					else{
						HX_STACK_LINE(239)
						if (((bool((c == (int)107)) || bool((c == (int)187))))){
							HX_STACK_LINE(241)
							::org::flixel::FlxG_obj::mute = false;
							HX_STACK_LINE(242)
							::org::flixel::FlxG_obj::setVolume((::org::flixel::FlxG_obj::volume + 0.1));
							HX_STACK_LINE(243)
							::org::flixel::FlxG_obj::_game->showSoundTray(null());
							HX_STACK_LINE(244)
							return null();
						}
						else{
						}
					}
				}
			}
		}
		HX_STACK_LINE(253)
		if ((::org::flixel::FlxG_obj::_game->_replaying)){
			HX_STACK_LINE(254)
			return null();
		}
		HX_STACK_LINE(259)
		::org::flixel::system::input::FlxMapObject object = this->_map->__get(FlashEvent->keyCode);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(260)
		if (((object == null()))){
			HX_STACK_LINE(260)
			return null();
		}
		HX_STACK_LINE(261)
		if (((object->current > (int)0))){
			HX_STACK_LINE(261)
			object->current = (int)-1;
		}
		else{
			HX_STACK_LINE(262)
			object->current = (int)0;
		}
		HX_STACK_LINE(263)
		this->__SetField(object->name,false,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,onKeyUp,(void))


FlxKeyboard_obj::FlxKeyboard_obj()
{
}

void FlxKeyboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxKeyboard);
	HX_MARK_MEMBER_NAME(RIGHT,"RIGHT");
	HX_MARK_MEMBER_NAME(LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(DOWN,"DOWN");
	HX_MARK_MEMBER_NAME(UP,"UP");
	HX_MARK_MEMBER_NAME(SPACE,"SPACE");
	HX_MARK_MEMBER_NAME(ALT,"ALT");
	HX_MARK_MEMBER_NAME(CONTROL,"CONTROL");
	HX_MARK_MEMBER_NAME(NUMPADSLASH,"NUMPADSLASH");
	HX_MARK_MEMBER_NAME(SLASH,"SLASH");
	HX_MARK_MEMBER_NAME(NUMPADPERIOD,"NUMPADPERIOD");
	HX_MARK_MEMBER_NAME(PERIOD,"PERIOD");
	HX_MARK_MEMBER_NAME(COMMA,"COMMA");
	HX_MARK_MEMBER_NAME(M,"M");
	HX_MARK_MEMBER_NAME(N,"N");
	HX_MARK_MEMBER_NAME(B,"B");
	HX_MARK_MEMBER_NAME(V,"V");
	HX_MARK_MEMBER_NAME(C,"C");
	HX_MARK_MEMBER_NAME(X,"X");
	HX_MARK_MEMBER_NAME(Z,"Z");
	HX_MARK_MEMBER_NAME(SHIFT,"SHIFT");
	HX_MARK_MEMBER_NAME(ENTER,"ENTER");
	HX_MARK_MEMBER_NAME(QUOTE,"QUOTE");
	HX_MARK_MEMBER_NAME(SEMICOLON,"SEMICOLON");
	HX_MARK_MEMBER_NAME(L,"L");
	HX_MARK_MEMBER_NAME(K,"K");
	HX_MARK_MEMBER_NAME(J,"J");
	HX_MARK_MEMBER_NAME(H,"H");
	HX_MARK_MEMBER_NAME(G,"G");
	HX_MARK_MEMBER_NAME(F,"F");
	HX_MARK_MEMBER_NAME(D,"D");
	HX_MARK_MEMBER_NAME(S,"S");
	HX_MARK_MEMBER_NAME(A,"A");
	HX_MARK_MEMBER_NAME(CAPSLOCK,"CAPSLOCK");
	HX_MARK_MEMBER_NAME(BACKSLASH,"BACKSLASH");
	HX_MARK_MEMBER_NAME(RBRACKET,"RBRACKET");
	HX_MARK_MEMBER_NAME(LBRACKET,"LBRACKET");
	HX_MARK_MEMBER_NAME(P,"P");
	HX_MARK_MEMBER_NAME(O,"O");
	HX_MARK_MEMBER_NAME(I,"I");
	HX_MARK_MEMBER_NAME(U,"U");
	HX_MARK_MEMBER_NAME(Y,"Y");
	HX_MARK_MEMBER_NAME(T,"T");
	HX_MARK_MEMBER_NAME(R,"R");
	HX_MARK_MEMBER_NAME(E,"E");
	HX_MARK_MEMBER_NAME(W,"W");
	HX_MARK_MEMBER_NAME(Q,"Q");
	HX_MARK_MEMBER_NAME(TAB,"TAB");
	HX_MARK_MEMBER_NAME(BACKSPACE,"BACKSPACE");
	HX_MARK_MEMBER_NAME(DELETE,"DELETE");
	HX_MARK_MEMBER_NAME(NUMPADPLUS,"NUMPADPLUS");
	HX_MARK_MEMBER_NAME(PLUS,"PLUS");
	HX_MARK_MEMBER_NAME(NUMPADMINUS,"NUMPADMINUS");
	HX_MARK_MEMBER_NAME(MINUS,"MINUS");
	HX_MARK_MEMBER_NAME(INSERT,"INSERT");
	HX_MARK_MEMBER_NAME(END,"END");
	HX_MARK_MEMBER_NAME(HOME,"HOME");
	HX_MARK_MEMBER_NAME(PAGEDOWN,"PAGEDOWN");
	HX_MARK_MEMBER_NAME(PAGEUP,"PAGEUP");
	HX_MARK_MEMBER_NAME(NUMPADZERO,"NUMPADZERO");
	HX_MARK_MEMBER_NAME(NUMPADNINE,"NUMPADNINE");
	HX_MARK_MEMBER_NAME(NUMPADEIGHT,"NUMPADEIGHT");
	HX_MARK_MEMBER_NAME(NUMPADSEVEN,"NUMPADSEVEN");
	HX_MARK_MEMBER_NAME(NUMPADSIX,"NUMPADSIX");
	HX_MARK_MEMBER_NAME(NUMPADFIVE,"NUMPADFIVE");
	HX_MARK_MEMBER_NAME(NUMPADFOUR,"NUMPADFOUR");
	HX_MARK_MEMBER_NAME(NUMPADTHREE,"NUMPADTHREE");
	HX_MARK_MEMBER_NAME(NUMPADTWO,"NUMPADTWO");
	HX_MARK_MEMBER_NAME(NUMPADONE,"NUMPADONE");
	HX_MARK_MEMBER_NAME(ZERO,"ZERO");
	HX_MARK_MEMBER_NAME(NINE,"NINE");
	HX_MARK_MEMBER_NAME(EIGHT,"EIGHT");
	HX_MARK_MEMBER_NAME(SEVEN,"SEVEN");
	HX_MARK_MEMBER_NAME(SIX,"SIX");
	HX_MARK_MEMBER_NAME(FIVE,"FIVE");
	HX_MARK_MEMBER_NAME(FOUR,"FOUR");
	HX_MARK_MEMBER_NAME(THREE,"THREE");
	HX_MARK_MEMBER_NAME(TWO,"TWO");
	HX_MARK_MEMBER_NAME(ONE,"ONE");
	HX_MARK_MEMBER_NAME(F12,"F12");
	HX_MARK_MEMBER_NAME(F11,"F11");
	HX_MARK_MEMBER_NAME(F10,"F10");
	HX_MARK_MEMBER_NAME(F9,"F9");
	HX_MARK_MEMBER_NAME(F8,"F8");
	HX_MARK_MEMBER_NAME(F7,"F7");
	HX_MARK_MEMBER_NAME(F6,"F6");
	HX_MARK_MEMBER_NAME(F5,"F5");
	HX_MARK_MEMBER_NAME(F4,"F4");
	HX_MARK_MEMBER_NAME(F3,"F3");
	HX_MARK_MEMBER_NAME(F2,"F2");
	HX_MARK_MEMBER_NAME(F1,"F1");
	HX_MARK_MEMBER_NAME(ESCAPE,"ESCAPE");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxKeyboard_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(RIGHT,"RIGHT");
	HX_VISIT_MEMBER_NAME(LEFT,"LEFT");
	HX_VISIT_MEMBER_NAME(DOWN,"DOWN");
	HX_VISIT_MEMBER_NAME(UP,"UP");
	HX_VISIT_MEMBER_NAME(SPACE,"SPACE");
	HX_VISIT_MEMBER_NAME(ALT,"ALT");
	HX_VISIT_MEMBER_NAME(CONTROL,"CONTROL");
	HX_VISIT_MEMBER_NAME(NUMPADSLASH,"NUMPADSLASH");
	HX_VISIT_MEMBER_NAME(SLASH,"SLASH");
	HX_VISIT_MEMBER_NAME(NUMPADPERIOD,"NUMPADPERIOD");
	HX_VISIT_MEMBER_NAME(PERIOD,"PERIOD");
	HX_VISIT_MEMBER_NAME(COMMA,"COMMA");
	HX_VISIT_MEMBER_NAME(M,"M");
	HX_VISIT_MEMBER_NAME(N,"N");
	HX_VISIT_MEMBER_NAME(B,"B");
	HX_VISIT_MEMBER_NAME(V,"V");
	HX_VISIT_MEMBER_NAME(C,"C");
	HX_VISIT_MEMBER_NAME(X,"X");
	HX_VISIT_MEMBER_NAME(Z,"Z");
	HX_VISIT_MEMBER_NAME(SHIFT,"SHIFT");
	HX_VISIT_MEMBER_NAME(ENTER,"ENTER");
	HX_VISIT_MEMBER_NAME(QUOTE,"QUOTE");
	HX_VISIT_MEMBER_NAME(SEMICOLON,"SEMICOLON");
	HX_VISIT_MEMBER_NAME(L,"L");
	HX_VISIT_MEMBER_NAME(K,"K");
	HX_VISIT_MEMBER_NAME(J,"J");
	HX_VISIT_MEMBER_NAME(H,"H");
	HX_VISIT_MEMBER_NAME(G,"G");
	HX_VISIT_MEMBER_NAME(F,"F");
	HX_VISIT_MEMBER_NAME(D,"D");
	HX_VISIT_MEMBER_NAME(S,"S");
	HX_VISIT_MEMBER_NAME(A,"A");
	HX_VISIT_MEMBER_NAME(CAPSLOCK,"CAPSLOCK");
	HX_VISIT_MEMBER_NAME(BACKSLASH,"BACKSLASH");
	HX_VISIT_MEMBER_NAME(RBRACKET,"RBRACKET");
	HX_VISIT_MEMBER_NAME(LBRACKET,"LBRACKET");
	HX_VISIT_MEMBER_NAME(P,"P");
	HX_VISIT_MEMBER_NAME(O,"O");
	HX_VISIT_MEMBER_NAME(I,"I");
	HX_VISIT_MEMBER_NAME(U,"U");
	HX_VISIT_MEMBER_NAME(Y,"Y");
	HX_VISIT_MEMBER_NAME(T,"T");
	HX_VISIT_MEMBER_NAME(R,"R");
	HX_VISIT_MEMBER_NAME(E,"E");
	HX_VISIT_MEMBER_NAME(W,"W");
	HX_VISIT_MEMBER_NAME(Q,"Q");
	HX_VISIT_MEMBER_NAME(TAB,"TAB");
	HX_VISIT_MEMBER_NAME(BACKSPACE,"BACKSPACE");
	HX_VISIT_MEMBER_NAME(DELETE,"DELETE");
	HX_VISIT_MEMBER_NAME(NUMPADPLUS,"NUMPADPLUS");
	HX_VISIT_MEMBER_NAME(PLUS,"PLUS");
	HX_VISIT_MEMBER_NAME(NUMPADMINUS,"NUMPADMINUS");
	HX_VISIT_MEMBER_NAME(MINUS,"MINUS");
	HX_VISIT_MEMBER_NAME(INSERT,"INSERT");
	HX_VISIT_MEMBER_NAME(END,"END");
	HX_VISIT_MEMBER_NAME(HOME,"HOME");
	HX_VISIT_MEMBER_NAME(PAGEDOWN,"PAGEDOWN");
	HX_VISIT_MEMBER_NAME(PAGEUP,"PAGEUP");
	HX_VISIT_MEMBER_NAME(NUMPADZERO,"NUMPADZERO");
	HX_VISIT_MEMBER_NAME(NUMPADNINE,"NUMPADNINE");
	HX_VISIT_MEMBER_NAME(NUMPADEIGHT,"NUMPADEIGHT");
	HX_VISIT_MEMBER_NAME(NUMPADSEVEN,"NUMPADSEVEN");
	HX_VISIT_MEMBER_NAME(NUMPADSIX,"NUMPADSIX");
	HX_VISIT_MEMBER_NAME(NUMPADFIVE,"NUMPADFIVE");
	HX_VISIT_MEMBER_NAME(NUMPADFOUR,"NUMPADFOUR");
	HX_VISIT_MEMBER_NAME(NUMPADTHREE,"NUMPADTHREE");
	HX_VISIT_MEMBER_NAME(NUMPADTWO,"NUMPADTWO");
	HX_VISIT_MEMBER_NAME(NUMPADONE,"NUMPADONE");
	HX_VISIT_MEMBER_NAME(ZERO,"ZERO");
	HX_VISIT_MEMBER_NAME(NINE,"NINE");
	HX_VISIT_MEMBER_NAME(EIGHT,"EIGHT");
	HX_VISIT_MEMBER_NAME(SEVEN,"SEVEN");
	HX_VISIT_MEMBER_NAME(SIX,"SIX");
	HX_VISIT_MEMBER_NAME(FIVE,"FIVE");
	HX_VISIT_MEMBER_NAME(FOUR,"FOUR");
	HX_VISIT_MEMBER_NAME(THREE,"THREE");
	HX_VISIT_MEMBER_NAME(TWO,"TWO");
	HX_VISIT_MEMBER_NAME(ONE,"ONE");
	HX_VISIT_MEMBER_NAME(F12,"F12");
	HX_VISIT_MEMBER_NAME(F11,"F11");
	HX_VISIT_MEMBER_NAME(F10,"F10");
	HX_VISIT_MEMBER_NAME(F9,"F9");
	HX_VISIT_MEMBER_NAME(F8,"F8");
	HX_VISIT_MEMBER_NAME(F7,"F7");
	HX_VISIT_MEMBER_NAME(F6,"F6");
	HX_VISIT_MEMBER_NAME(F5,"F5");
	HX_VISIT_MEMBER_NAME(F4,"F4");
	HX_VISIT_MEMBER_NAME(F3,"F3");
	HX_VISIT_MEMBER_NAME(F2,"F2");
	HX_VISIT_MEMBER_NAME(F1,"F1");
	HX_VISIT_MEMBER_NAME(ESCAPE,"ESCAPE");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxKeyboard_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"M") ) { return M; }
		if (HX_FIELD_EQ(inName,"N") ) { return N; }
		if (HX_FIELD_EQ(inName,"B") ) { return B; }
		if (HX_FIELD_EQ(inName,"V") ) { return V; }
		if (HX_FIELD_EQ(inName,"C") ) { return C; }
		if (HX_FIELD_EQ(inName,"X") ) { return X; }
		if (HX_FIELD_EQ(inName,"Z") ) { return Z; }
		if (HX_FIELD_EQ(inName,"L") ) { return L; }
		if (HX_FIELD_EQ(inName,"K") ) { return K; }
		if (HX_FIELD_EQ(inName,"J") ) { return J; }
		if (HX_FIELD_EQ(inName,"H") ) { return H; }
		if (HX_FIELD_EQ(inName,"G") ) { return G; }
		if (HX_FIELD_EQ(inName,"F") ) { return F; }
		if (HX_FIELD_EQ(inName,"D") ) { return D; }
		if (HX_FIELD_EQ(inName,"S") ) { return S; }
		if (HX_FIELD_EQ(inName,"A") ) { return A; }
		if (HX_FIELD_EQ(inName,"P") ) { return P; }
		if (HX_FIELD_EQ(inName,"O") ) { return O; }
		if (HX_FIELD_EQ(inName,"I") ) { return I; }
		if (HX_FIELD_EQ(inName,"U") ) { return U; }
		if (HX_FIELD_EQ(inName,"Y") ) { return Y; }
		if (HX_FIELD_EQ(inName,"T") ) { return T; }
		if (HX_FIELD_EQ(inName,"R") ) { return R; }
		if (HX_FIELD_EQ(inName,"E") ) { return E; }
		if (HX_FIELD_EQ(inName,"W") ) { return W; }
		if (HX_FIELD_EQ(inName,"Q") ) { return Q; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"UP") ) { return UP; }
		if (HX_FIELD_EQ(inName,"F9") ) { return F9; }
		if (HX_FIELD_EQ(inName,"F8") ) { return F8; }
		if (HX_FIELD_EQ(inName,"F7") ) { return F7; }
		if (HX_FIELD_EQ(inName,"F6") ) { return F6; }
		if (HX_FIELD_EQ(inName,"F5") ) { return F5; }
		if (HX_FIELD_EQ(inName,"F4") ) { return F4; }
		if (HX_FIELD_EQ(inName,"F3") ) { return F3; }
		if (HX_FIELD_EQ(inName,"F2") ) { return F2; }
		if (HX_FIELD_EQ(inName,"F1") ) { return F1; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"ALT") ) { return ALT; }
		if (HX_FIELD_EQ(inName,"TAB") ) { return TAB; }
		if (HX_FIELD_EQ(inName,"END") ) { return END; }
		if (HX_FIELD_EQ(inName,"SIX") ) { return SIX; }
		if (HX_FIELD_EQ(inName,"TWO") ) { return TWO; }
		if (HX_FIELD_EQ(inName,"ONE") ) { return ONE; }
		if (HX_FIELD_EQ(inName,"F12") ) { return F12; }
		if (HX_FIELD_EQ(inName,"F11") ) { return F11; }
		if (HX_FIELD_EQ(inName,"F10") ) { return F10; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { return LEFT; }
		if (HX_FIELD_EQ(inName,"DOWN") ) { return DOWN; }
		if (HX_FIELD_EQ(inName,"PLUS") ) { return PLUS; }
		if (HX_FIELD_EQ(inName,"HOME") ) { return HOME; }
		if (HX_FIELD_EQ(inName,"ZERO") ) { return ZERO; }
		if (HX_FIELD_EQ(inName,"NINE") ) { return NINE; }
		if (HX_FIELD_EQ(inName,"FIVE") ) { return FIVE; }
		if (HX_FIELD_EQ(inName,"FOUR") ) { return FOUR; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { return RIGHT; }
		if (HX_FIELD_EQ(inName,"SPACE") ) { return SPACE; }
		if (HX_FIELD_EQ(inName,"SLASH") ) { return SLASH; }
		if (HX_FIELD_EQ(inName,"COMMA") ) { return COMMA; }
		if (HX_FIELD_EQ(inName,"SHIFT") ) { return SHIFT; }
		if (HX_FIELD_EQ(inName,"ENTER") ) { return ENTER; }
		if (HX_FIELD_EQ(inName,"QUOTE") ) { return QUOTE; }
		if (HX_FIELD_EQ(inName,"MINUS") ) { return MINUS; }
		if (HX_FIELD_EQ(inName,"EIGHT") ) { return EIGHT; }
		if (HX_FIELD_EQ(inName,"SEVEN") ) { return SEVEN; }
		if (HX_FIELD_EQ(inName,"THREE") ) { return THREE; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PERIOD") ) { return PERIOD; }
		if (HX_FIELD_EQ(inName,"DELETE") ) { return DELETE; }
		if (HX_FIELD_EQ(inName,"INSERT") ) { return INSERT; }
		if (HX_FIELD_EQ(inName,"PAGEUP") ) { return PAGEUP; }
		if (HX_FIELD_EQ(inName,"ESCAPE") ) { return ESCAPE; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"CONTROL") ) { return CONTROL; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"CAPSLOCK") ) { return CAPSLOCK; }
		if (HX_FIELD_EQ(inName,"RBRACKET") ) { return RBRACKET; }
		if (HX_FIELD_EQ(inName,"LBRACKET") ) { return LBRACKET; }
		if (HX_FIELD_EQ(inName,"PAGEDOWN") ) { return PAGEDOWN; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"SEMICOLON") ) { return SEMICOLON; }
		if (HX_FIELD_EQ(inName,"BACKSLASH") ) { return BACKSLASH; }
		if (HX_FIELD_EQ(inName,"BACKSPACE") ) { return BACKSPACE; }
		if (HX_FIELD_EQ(inName,"NUMPADSIX") ) { return NUMPADSIX; }
		if (HX_FIELD_EQ(inName,"NUMPADTWO") ) { return NUMPADTWO; }
		if (HX_FIELD_EQ(inName,"NUMPADONE") ) { return NUMPADONE; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NUMPADPLUS") ) { return NUMPADPLUS; }
		if (HX_FIELD_EQ(inName,"NUMPADZERO") ) { return NUMPADZERO; }
		if (HX_FIELD_EQ(inName,"NUMPADNINE") ) { return NUMPADNINE; }
		if (HX_FIELD_EQ(inName,"NUMPADFIVE") ) { return NUMPADFIVE; }
		if (HX_FIELD_EQ(inName,"NUMPADFOUR") ) { return NUMPADFOUR; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		if (HX_FIELD_EQ(inName,"NUMPADSLASH") ) { return NUMPADSLASH; }
		if (HX_FIELD_EQ(inName,"NUMPADMINUS") ) { return NUMPADMINUS; }
		if (HX_FIELD_EQ(inName,"NUMPADEIGHT") ) { return NUMPADEIGHT; }
		if (HX_FIELD_EQ(inName,"NUMPADSEVEN") ) { return NUMPADSEVEN; }
		if (HX_FIELD_EQ(inName,"NUMPADTHREE") ) { return NUMPADTHREE; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"NUMPADPERIOD") ) { return NUMPADPERIOD; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"handleKeyDown") ) { return handleKeyDown_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxKeyboard_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"M") ) { M=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"N") ) { N=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"B") ) { B=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V") ) { V=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"C") ) { C=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"X") ) { X=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Z") ) { Z=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"L") ) { L=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"K") ) { K=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"J") ) { J=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"H") ) { H=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"G") ) { G=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F") ) { F=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D") ) { D=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"S") ) { S=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A") ) { A=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"P") ) { P=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"O") ) { O=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"I") ) { I=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"U") ) { U=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Y") ) { Y=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"T") ) { T=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"R") ) { R=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"E") ) { E=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"W") ) { W=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Q") ) { Q=inValue.Cast< bool >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"UP") ) { UP=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F9") ) { F9=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F8") ) { F8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F7") ) { F7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F6") ) { F6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F5") ) { F5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F4") ) { F4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F3") ) { F3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F2") ) { F2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F1") ) { F1=inValue.Cast< bool >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"ALT") ) { ALT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TAB") ) { TAB=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"END") ) { END=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SIX") ) { SIX=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TWO") ) { TWO=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ONE") ) { ONE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F12") ) { F12=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F11") ) { F11=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F10") ) { F10=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { LEFT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOWN") ) { DOWN=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PLUS") ) { PLUS=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HOME") ) { HOME=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ZERO") ) { ZERO=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NINE") ) { NINE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FIVE") ) { FIVE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FOUR") ) { FOUR=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { RIGHT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SPACE") ) { SPACE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SLASH") ) { SLASH=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"COMMA") ) { COMMA=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SHIFT") ) { SHIFT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ENTER") ) { ENTER=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"QUOTE") ) { QUOTE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MINUS") ) { MINUS=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"EIGHT") ) { EIGHT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SEVEN") ) { SEVEN=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"THREE") ) { THREE=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PERIOD") ) { PERIOD=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DELETE") ) { DELETE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"INSERT") ) { INSERT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PAGEUP") ) { PAGEUP=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ESCAPE") ) { ESCAPE=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"CONTROL") ) { CONTROL=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"CAPSLOCK") ) { CAPSLOCK=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RBRACKET") ) { RBRACKET=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LBRACKET") ) { LBRACKET=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PAGEDOWN") ) { PAGEDOWN=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SEMICOLON") ) { SEMICOLON=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BACKSLASH") ) { BACKSLASH=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BACKSPACE") ) { BACKSPACE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADSIX") ) { NUMPADSIX=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADTWO") ) { NUMPADTWO=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADONE") ) { NUMPADONE=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NUMPADPLUS") ) { NUMPADPLUS=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADZERO") ) { NUMPADZERO=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADNINE") ) { NUMPADNINE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADFIVE") ) { NUMPADFIVE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADFOUR") ) { NUMPADFOUR=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NUMPADSLASH") ) { NUMPADSLASH=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADMINUS") ) { NUMPADMINUS=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADEIGHT") ) { NUMPADEIGHT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADSEVEN") ) { NUMPADSEVEN=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NUMPADTHREE") ) { NUMPADTHREE=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"NUMPADPERIOD") ) { NUMPADPERIOD=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxKeyboard_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("RIGHT"));
	outFields->push(HX_CSTRING("LEFT"));
	outFields->push(HX_CSTRING("DOWN"));
	outFields->push(HX_CSTRING("UP"));
	outFields->push(HX_CSTRING("SPACE"));
	outFields->push(HX_CSTRING("ALT"));
	outFields->push(HX_CSTRING("CONTROL"));
	outFields->push(HX_CSTRING("NUMPADSLASH"));
	outFields->push(HX_CSTRING("SLASH"));
	outFields->push(HX_CSTRING("NUMPADPERIOD"));
	outFields->push(HX_CSTRING("PERIOD"));
	outFields->push(HX_CSTRING("COMMA"));
	outFields->push(HX_CSTRING("M"));
	outFields->push(HX_CSTRING("N"));
	outFields->push(HX_CSTRING("B"));
	outFields->push(HX_CSTRING("V"));
	outFields->push(HX_CSTRING("C"));
	outFields->push(HX_CSTRING("X"));
	outFields->push(HX_CSTRING("Z"));
	outFields->push(HX_CSTRING("SHIFT"));
	outFields->push(HX_CSTRING("ENTER"));
	outFields->push(HX_CSTRING("QUOTE"));
	outFields->push(HX_CSTRING("SEMICOLON"));
	outFields->push(HX_CSTRING("L"));
	outFields->push(HX_CSTRING("K"));
	outFields->push(HX_CSTRING("J"));
	outFields->push(HX_CSTRING("H"));
	outFields->push(HX_CSTRING("G"));
	outFields->push(HX_CSTRING("F"));
	outFields->push(HX_CSTRING("D"));
	outFields->push(HX_CSTRING("S"));
	outFields->push(HX_CSTRING("A"));
	outFields->push(HX_CSTRING("CAPSLOCK"));
	outFields->push(HX_CSTRING("BACKSLASH"));
	outFields->push(HX_CSTRING("RBRACKET"));
	outFields->push(HX_CSTRING("LBRACKET"));
	outFields->push(HX_CSTRING("P"));
	outFields->push(HX_CSTRING("O"));
	outFields->push(HX_CSTRING("I"));
	outFields->push(HX_CSTRING("U"));
	outFields->push(HX_CSTRING("Y"));
	outFields->push(HX_CSTRING("T"));
	outFields->push(HX_CSTRING("R"));
	outFields->push(HX_CSTRING("E"));
	outFields->push(HX_CSTRING("W"));
	outFields->push(HX_CSTRING("Q"));
	outFields->push(HX_CSTRING("TAB"));
	outFields->push(HX_CSTRING("BACKSPACE"));
	outFields->push(HX_CSTRING("DELETE"));
	outFields->push(HX_CSTRING("NUMPADPLUS"));
	outFields->push(HX_CSTRING("PLUS"));
	outFields->push(HX_CSTRING("NUMPADMINUS"));
	outFields->push(HX_CSTRING("MINUS"));
	outFields->push(HX_CSTRING("INSERT"));
	outFields->push(HX_CSTRING("END"));
	outFields->push(HX_CSTRING("HOME"));
	outFields->push(HX_CSTRING("PAGEDOWN"));
	outFields->push(HX_CSTRING("PAGEUP"));
	outFields->push(HX_CSTRING("NUMPADZERO"));
	outFields->push(HX_CSTRING("NUMPADNINE"));
	outFields->push(HX_CSTRING("NUMPADEIGHT"));
	outFields->push(HX_CSTRING("NUMPADSEVEN"));
	outFields->push(HX_CSTRING("NUMPADSIX"));
	outFields->push(HX_CSTRING("NUMPADFIVE"));
	outFields->push(HX_CSTRING("NUMPADFOUR"));
	outFields->push(HX_CSTRING("NUMPADTHREE"));
	outFields->push(HX_CSTRING("NUMPADTWO"));
	outFields->push(HX_CSTRING("NUMPADONE"));
	outFields->push(HX_CSTRING("ZERO"));
	outFields->push(HX_CSTRING("NINE"));
	outFields->push(HX_CSTRING("EIGHT"));
	outFields->push(HX_CSTRING("SEVEN"));
	outFields->push(HX_CSTRING("SIX"));
	outFields->push(HX_CSTRING("FIVE"));
	outFields->push(HX_CSTRING("FOUR"));
	outFields->push(HX_CSTRING("THREE"));
	outFields->push(HX_CSTRING("TWO"));
	outFields->push(HX_CSTRING("ONE"));
	outFields->push(HX_CSTRING("F12"));
	outFields->push(HX_CSTRING("F11"));
	outFields->push(HX_CSTRING("F10"));
	outFields->push(HX_CSTRING("F9"));
	outFields->push(HX_CSTRING("F8"));
	outFields->push(HX_CSTRING("F7"));
	outFields->push(HX_CSTRING("F6"));
	outFields->push(HX_CSTRING("F5"));
	outFields->push(HX_CSTRING("F4"));
	outFields->push(HX_CSTRING("F3"));
	outFields->push(HX_CSTRING("F2"));
	outFields->push(HX_CSTRING("F1"));
	outFields->push(HX_CSTRING("ESCAPE"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("handleKeyDown"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("RIGHT"),
	HX_CSTRING("LEFT"),
	HX_CSTRING("DOWN"),
	HX_CSTRING("UP"),
	HX_CSTRING("SPACE"),
	HX_CSTRING("ALT"),
	HX_CSTRING("CONTROL"),
	HX_CSTRING("NUMPADSLASH"),
	HX_CSTRING("SLASH"),
	HX_CSTRING("NUMPADPERIOD"),
	HX_CSTRING("PERIOD"),
	HX_CSTRING("COMMA"),
	HX_CSTRING("M"),
	HX_CSTRING("N"),
	HX_CSTRING("B"),
	HX_CSTRING("V"),
	HX_CSTRING("C"),
	HX_CSTRING("X"),
	HX_CSTRING("Z"),
	HX_CSTRING("SHIFT"),
	HX_CSTRING("ENTER"),
	HX_CSTRING("QUOTE"),
	HX_CSTRING("SEMICOLON"),
	HX_CSTRING("L"),
	HX_CSTRING("K"),
	HX_CSTRING("J"),
	HX_CSTRING("H"),
	HX_CSTRING("G"),
	HX_CSTRING("F"),
	HX_CSTRING("D"),
	HX_CSTRING("S"),
	HX_CSTRING("A"),
	HX_CSTRING("CAPSLOCK"),
	HX_CSTRING("BACKSLASH"),
	HX_CSTRING("RBRACKET"),
	HX_CSTRING("LBRACKET"),
	HX_CSTRING("P"),
	HX_CSTRING("O"),
	HX_CSTRING("I"),
	HX_CSTRING("U"),
	HX_CSTRING("Y"),
	HX_CSTRING("T"),
	HX_CSTRING("R"),
	HX_CSTRING("E"),
	HX_CSTRING("W"),
	HX_CSTRING("Q"),
	HX_CSTRING("TAB"),
	HX_CSTRING("BACKSPACE"),
	HX_CSTRING("DELETE"),
	HX_CSTRING("NUMPADPLUS"),
	HX_CSTRING("PLUS"),
	HX_CSTRING("NUMPADMINUS"),
	HX_CSTRING("MINUS"),
	HX_CSTRING("INSERT"),
	HX_CSTRING("END"),
	HX_CSTRING("HOME"),
	HX_CSTRING("PAGEDOWN"),
	HX_CSTRING("PAGEUP"),
	HX_CSTRING("NUMPADZERO"),
	HX_CSTRING("NUMPADNINE"),
	HX_CSTRING("NUMPADEIGHT"),
	HX_CSTRING("NUMPADSEVEN"),
	HX_CSTRING("NUMPADSIX"),
	HX_CSTRING("NUMPADFIVE"),
	HX_CSTRING("NUMPADFOUR"),
	HX_CSTRING("NUMPADTHREE"),
	HX_CSTRING("NUMPADTWO"),
	HX_CSTRING("NUMPADONE"),
	HX_CSTRING("ZERO"),
	HX_CSTRING("NINE"),
	HX_CSTRING("EIGHT"),
	HX_CSTRING("SEVEN"),
	HX_CSTRING("SIX"),
	HX_CSTRING("FIVE"),
	HX_CSTRING("FOUR"),
	HX_CSTRING("THREE"),
	HX_CSTRING("TWO"),
	HX_CSTRING("ONE"),
	HX_CSTRING("F12"),
	HX_CSTRING("F11"),
	HX_CSTRING("F10"),
	HX_CSTRING("F9"),
	HX_CSTRING("F8"),
	HX_CSTRING("F7"),
	HX_CSTRING("F6"),
	HX_CSTRING("F5"),
	HX_CSTRING("F4"),
	HX_CSTRING("F3"),
	HX_CSTRING("F2"),
	HX_CSTRING("F1"),
	HX_CSTRING("ESCAPE"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxKeyboard_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxKeyboard_obj::__mClass,"__mClass");
};

Class FlxKeyboard_obj::__mClass;

void FlxKeyboard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.input.FlxKeyboard"), hx::TCanCast< FlxKeyboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxKeyboard_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input
