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
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_media_ID3Info
#include <native/media/ID3Info.h>
#endif
#ifndef INCLUDED_native_media_Sound
#include <native/media/Sound.h>
#endif
#ifndef INCLUDED_native_media_SoundChannel
#include <native/media/SoundChannel.h>
#endif
#ifndef INCLUDED_native_media_SoundLoaderContext
#include <native/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_native_media_SoundTransform
#include <native/media/SoundTransform.h>
#endif
#ifndef INCLUDED_native_net_URLRequest
#include <native/net/URLRequest.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
#ifndef INCLUDED_org_flixel_FadeTween
#include <org/flixel/FadeTween.h>
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
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSound
#include <org/flixel/FlxSound.h>
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
namespace org{
namespace flixel{

Void FlxSound_obj::__construct()
{
HX_STACK_PUSH("FlxSound::new","org/flixel/FlxSound.hx",13);
{
	HX_STACK_LINE(81)
	this->_volumeAdjust = 1.0;
	HX_STACK_LINE(112)
	super::__construct();
	HX_STACK_LINE(113)
	this->reset();
}
;
	return null();
}

FlxSound_obj::~FlxSound_obj() { }

Dynamic FlxSound_obj::__CreateEmpty() { return  new FlxSound_obj; }
hx::ObjectPtr< FlxSound_obj > FlxSound_obj::__new()
{  hx::ObjectPtr< FlxSound_obj > result = new FlxSound_obj();
	result->__construct();
	return result;}

Dynamic FlxSound_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxSound_obj > result = new FlxSound_obj();
	result->__construct();
	return result;}

Void FlxSound_obj::gotID3( ::native::events::Event event){
{
		HX_STACK_PUSH("FlxSound::gotID3","org/flixel/FlxSound.hx",573);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(574)
		if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
			struct _Function_2_1{
				inline static ::String Block( ){
					HX_STACK_PUSH("*::closure","org/flixel/FlxSound.hx",574);
					{
						HX_STACK_LINE(574)
						Dynamic AnyArray = hx::TCastToArray(HX_CSTRING("got ID3 info!"));		HX_STACK_VAR(AnyArray,"AnyArray");
						HX_STACK_LINE(574)
						::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
						HX_STACK_LINE(574)
						if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
							HX_STACK_LINE(574)
							string = ::Std_obj::string(AnyArray->__GetItem((int)0));
							HX_STACK_LINE(574)
							int i = (int)1;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(574)
							int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
							HX_STACK_LINE(574)
							while(((i < l))){
								HX_STACK_LINE(574)
								hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
							}
						}
						HX_STACK_LINE(574)
						return string;
					}
					return null();
				}
			};
			HX_STACK_LINE(574)
			::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  ((::Std_obj::is(HX_CSTRING("got ID3 info!"),hx::ClassOf< Array<int> >()))) ? ::String(_Function_2_1::Block()) : ::String(::Std_obj::string(HX_CSTRING("got ID3 info!"))) ));
		}
		HX_STACK_LINE(575)
		this->name = this->_sound->get_id3()->songName;
		HX_STACK_LINE(576)
		this->artist = this->_sound->get_id3()->artist;
		HX_STACK_LINE(577)
		this->_sound->removeEventListener(::native::events::Event_obj::ID3,this->gotID3_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSound_obj,gotID3,(void))

Void FlxSound_obj::cleanup( bool destroySound,hx::Null< bool >  __o_resetPosition,hx::Null< bool >  __o_resetFading){
bool resetPosition = __o_resetPosition.Default(true);
bool resetFading = __o_resetFading.Default(true);
	HX_STACK_PUSH("FlxSound::cleanup","org/flixel/FlxSound.hx",538);
	HX_STACK_THIS(this);
	HX_STACK_ARG(destroySound,"destroySound");
	HX_STACK_ARG(resetPosition,"resetPosition");
	HX_STACK_ARG(resetFading,"resetFading");
{
		HX_STACK_LINE(539)
		if ((destroySound)){
			HX_STACK_LINE(541)
			this->reset();
			HX_STACK_LINE(542)
			return null();
		}
		HX_STACK_LINE(545)
		if (((this->_channel != null()))){
			HX_STACK_LINE(547)
			this->_channel->removeEventListener(::native::events::Event_obj::SOUND_COMPLETE,this->stopped_dyn(),null());
			HX_STACK_LINE(548)
			this->_channel->stop();
			HX_STACK_LINE(549)
			this->_channel = null();
		}
		HX_STACK_LINE(552)
		this->active = false;
		HX_STACK_LINE(554)
		if ((resetPosition)){
			HX_STACK_LINE(556)
			this->_position = (int)0;
			HX_STACK_LINE(557)
			this->_paused = false;
		}
		HX_STACK_LINE(560)
		if ((resetFading)){
			HX_STACK_LINE(562)
			if (((this->_fade != null()))){
				HX_STACK_LINE(562)
				this->_fade->destroy();
			}
			HX_STACK_LINE(563)
			this->_fade = null();
			HX_STACK_LINE(564)
			this->_onFadeComplete = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSound_obj,cleanup,(void))

Void FlxSound_obj::stopped( ::native::events::Event event){
{
		HX_STACK_PUSH("FlxSound::stopped","org/flixel/FlxSound.hx",518);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(518)
		if ((this->_looped)){
			HX_STACK_LINE(521)
			this->cleanup(false,null(),null());
			HX_STACK_LINE(522)
			this->play(null());
		}
		else{
			HX_STACK_LINE(525)
			this->cleanup(this->autoDestroy,null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSound_obj,stopped,(void))

Void FlxSound_obj::startSound( Float Position){
{
		HX_STACK_PUSH("FlxSound::startSound","org/flixel/FlxSound.hx",496);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Position,"Position");
		HX_STACK_LINE(497)
		int numLoops = (  (((bool(this->_looped) && bool((Position == (int)0))))) ? int((int)9999) : int((int)0) );		HX_STACK_VAR(numLoops,"numLoops");
		HX_STACK_LINE(498)
		this->_position = Position;
		HX_STACK_LINE(499)
		this->_paused = false;
		HX_STACK_LINE(500)
		this->_channel = this->_sound->play(this->_position,numLoops,this->_transform);
		HX_STACK_LINE(501)
		if (((this->_channel != null()))){
			HX_STACK_LINE(503)
			this->_channel->addEventListener(::native::events::Event_obj::SOUND_COMPLETE,this->stopped_dyn(),null(),null(),null());
			HX_STACK_LINE(504)
			this->active = true;
		}
		else{
			HX_STACK_LINE(508)
			this->exists = false;
			HX_STACK_LINE(509)
			this->active = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSound_obj,startSound,(void))

Void FlxSound_obj::updateTransform( ){
{
		HX_STACK_PUSH("FlxSound::updateTransform","org/flixel/FlxSound.hx",484);
		HX_STACK_THIS(this);
		HX_STACK_LINE(485)
		this->_transform->volume = (((((  ((::org::flixel::FlxG_obj::mute)) ? int((int)0) : int((int)1) )) * ::org::flixel::FlxG_obj::volume) * this->_volume) * this->_volumeAdjust);
		HX_STACK_LINE(486)
		if (((this->_channel != null()))){
			HX_STACK_LINE(487)
			this->_channel->set_soundTransform(this->_transform);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,updateTransform,(void))

Float FlxSound_obj::getActualVolume( ){
	HX_STACK_PUSH("FlxSound::getActualVolume","org/flixel/FlxSound.hx",476);
	HX_STACK_THIS(this);
	HX_STACK_LINE(476)
	return (this->_volume * this->_volumeAdjust);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,getActualVolume,return )

Float FlxSound_obj::set_volume( Float Volume){
	HX_STACK_PUSH("FlxSound::set_volume","org/flixel/FlxSound.hx",457);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Volume,"Volume");
	HX_STACK_LINE(458)
	this->_volume = Volume;
	HX_STACK_LINE(459)
	if (((this->_volume < (int)0))){
		HX_STACK_LINE(460)
		this->_volume = (int)0;
	}
	else{
		HX_STACK_LINE(463)
		if (((this->_volume > (int)1))){
			HX_STACK_LINE(464)
			this->_volume = (int)1;
		}
	}
	HX_STACK_LINE(467)
	this->updateTransform();
	HX_STACK_LINE(468)
	return Volume;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSound_obj,set_volume,return )

Float FlxSound_obj::get_volume( ){
	HX_STACK_PUSH("FlxSound::get_volume","org/flixel/FlxSound.hx",450);
	HX_STACK_THIS(this);
	HX_STACK_LINE(450)
	return this->_volume;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,get_volume,return )

bool FlxSound_obj::get_playing( ){
	HX_STACK_PUSH("FlxSound::get_playing","org/flixel/FlxSound.hx",440);
	HX_STACK_THIS(this);
	HX_STACK_LINE(440)
	return (this->_channel != null());
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,get_playing,return )

Void FlxSound_obj::fadeIn( Float Seconds){
{
		HX_STACK_PUSH("FlxSound::fadeIn","org/flixel/FlxSound.hx",421);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Seconds,"Seconds");
		HX_STACK_LINE(422)
		if (((bool(this->get_playing()) && bool((this->_fade == null()))))){
			HX_STACK_LINE(423)
			return null();
		}
		HX_STACK_LINE(427)
		Float fadeStartVolume = (  (((this->_fade != null()))) ? Float(this->_fade->get_value()) : Float((int)0) );		HX_STACK_VAR(fadeStartVolume,"fadeStartVolume");
		HX_STACK_LINE(428)
		this->_fade = ::org::flixel::FadeTween_obj::__new(fadeStartVolume,(int)1,Seconds,null());
		HX_STACK_LINE(429)
		this->_onFadeComplete = null();
		HX_STACK_LINE(431)
		this->play(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSound_obj,fadeIn,(void))

Void FlxSound_obj::fadeOut( Float Seconds,hx::Null< bool >  __o_PauseInstead){
bool PauseInstead = __o_PauseInstead.Default(false);
	HX_STACK_PUSH("FlxSound::fadeOut","org/flixel/FlxSound.hx",404);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Seconds,"Seconds");
	HX_STACK_ARG(PauseInstead,"PauseInstead");
{
		HX_STACK_LINE(405)
		if ((!(this->get_playing()))){
			HX_STACK_LINE(406)
			return null();
		}
		HX_STACK_LINE(410)
		Float fadeStartVolume = (  (((this->_fade != null()))) ? Float(this->_fade->get_value()) : Float((int)1) );		HX_STACK_VAR(fadeStartVolume,"fadeStartVolume");
		HX_STACK_LINE(411)
		this->_fade = ::org::flixel::FadeTween_obj::__new(fadeStartVolume,(int)0,Seconds,null());
		HX_STACK_LINE(412)
		this->_onFadeComplete = (  ((PauseInstead)) ? Dynamic(this->pause_dyn()) : Dynamic(this->stop_dyn()) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxSound_obj,fadeOut,(void))

Void FlxSound_obj::stop( ){
{
		HX_STACK_PUSH("FlxSound::stop","org/flixel/FlxSound.hx",394);
		HX_STACK_THIS(this);
		HX_STACK_LINE(394)
		this->cleanup(this->autoDestroy,true,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,stop,(void))

Void FlxSound_obj::pause( ){
{
		HX_STACK_PUSH("FlxSound::pause","org/flixel/FlxSound.hx",380);
		HX_STACK_THIS(this);
		HX_STACK_LINE(381)
		if ((!(this->get_playing()))){
			HX_STACK_LINE(382)
			return null();
		}
		HX_STACK_LINE(385)
		this->_position = this->_channel->get_position();
		HX_STACK_LINE(386)
		this->_paused = true;
		HX_STACK_LINE(387)
		this->cleanup(false,false,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,pause,(void))

Void FlxSound_obj::resume( ){
{
		HX_STACK_PUSH("FlxSound::resume","org/flixel/FlxSound.hx",369);
		HX_STACK_THIS(this);
		HX_STACK_LINE(369)
		if ((this->_paused)){
			HX_STACK_LINE(371)
			this->startSound(this->_position);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,resume,(void))

Void FlxSound_obj::play( hx::Null< bool >  __o_ForceRestart){
bool ForceRestart = __o_ForceRestart.Default(false);
	HX_STACK_PUSH("FlxSound::play","org/flixel/FlxSound.hx",340);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ForceRestart,"ForceRestart");
{
		HX_STACK_LINE(341)
		if ((!(this->exists))){
			HX_STACK_LINE(342)
			return null();
		}
		HX_STACK_LINE(345)
		if ((ForceRestart)){
			HX_STACK_LINE(346)
			this->cleanup(false,true,true);
		}
		else{
			HX_STACK_LINE(349)
			if ((this->get_playing())){
				HX_STACK_LINE(350)
				return null();
			}
		}
		HX_STACK_LINE(355)
		if ((this->_paused)){
			HX_STACK_LINE(356)
			this->resume();
		}
		else{
			HX_STACK_LINE(360)
			this->startSound((int)0);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSound_obj,play,(void))

::org::flixel::FlxSound FlxSound_obj::proximity( Float X,Float Y,::org::flixel::FlxObject TargetObject,Float Radius,hx::Null< bool >  __o_Pan){
bool Pan = __o_Pan.Default(true);
	HX_STACK_PUSH("FlxSound::proximity","org/flixel/FlxSound.hx",326);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_ARG(TargetObject,"TargetObject");
	HX_STACK_ARG(Radius,"Radius");
	HX_STACK_ARG(Pan,"Pan");
{
		HX_STACK_LINE(327)
		this->x = X;
		HX_STACK_LINE(328)
		this->y = Y;
		HX_STACK_LINE(329)
		this->_target = TargetObject;
		HX_STACK_LINE(330)
		this->_radius = Radius;
		HX_STACK_LINE(331)
		this->_pan = Pan;
		HX_STACK_LINE(332)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxSound_obj,proximity,return )

::org::flixel::FlxSound FlxSound_obj::loadStream( ::String SoundURL,hx::Null< bool >  __o_Looped,hx::Null< bool >  __o_AutoDestroy){
bool Looped = __o_Looped.Default(false);
bool AutoDestroy = __o_AutoDestroy.Default(false);
	HX_STACK_PUSH("FlxSound::loadStream","org/flixel/FlxSound.hx",300);
	HX_STACK_THIS(this);
	HX_STACK_ARG(SoundURL,"SoundURL");
	HX_STACK_ARG(Looped,"Looped");
	HX_STACK_ARG(AutoDestroy,"AutoDestroy");
{
		HX_STACK_LINE(301)
		this->cleanup(true,null(),null());
		HX_STACK_LINE(303)
		this->_sound = ::native::media::Sound_obj::__new(null(),null(),null());
		HX_STACK_LINE(304)
		this->_sound->addEventListener(::native::events::Event_obj::ID3,this->gotID3_dyn(),null(),null(),null());
		HX_STACK_LINE(305)
		this->_sound->load(::native::net::URLRequest_obj::__new(SoundURL),null(),null());
		HX_STACK_LINE(306)
		this->_looped = Looped;
		HX_STACK_LINE(307)
		this->autoDestroy = AutoDestroy;
		HX_STACK_LINE(308)
		this->updateTransform();
		HX_STACK_LINE(309)
		this->exists = true;
		HX_STACK_LINE(310)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSound_obj,loadStream,return )

::org::flixel::FlxSound FlxSound_obj::loadEmbedded( Dynamic EmbeddedSound,hx::Null< bool >  __o_Looped,hx::Null< bool >  __o_AutoDestroy){
bool Looped = __o_Looped.Default(false);
bool AutoDestroy = __o_AutoDestroy.Default(false);
	HX_STACK_PUSH("FlxSound::loadEmbedded","org/flixel/FlxSound.hx",266);
	HX_STACK_THIS(this);
	HX_STACK_ARG(EmbeddedSound,"EmbeddedSound");
	HX_STACK_ARG(Looped,"Looped");
	HX_STACK_ARG(AutoDestroy,"AutoDestroy");
{
		HX_STACK_LINE(267)
		this->cleanup(true,null(),null());
		HX_STACK_LINE(269)
		if ((::Std_obj::is(EmbeddedSound,hx::ClassOf< ::native::media::Sound >()))){
			HX_STACK_LINE(270)
			this->_sound = EmbeddedSound;
		}
		else{
			HX_STACK_LINE(273)
			if ((::Std_obj::is(EmbeddedSound,hx::ClassOf< ::Class >()))){
				HX_STACK_LINE(274)
				this->_sound = ::Type_obj::createInstance(EmbeddedSound,Dynamic( Array_obj<Dynamic>::__new()));
			}
			else{
				HX_STACK_LINE(277)
				if ((::Std_obj::is(EmbeddedSound,hx::ClassOf< ::String >()))){
					HX_STACK_LINE(278)
					this->_sound = ::nme::installer::Assets_obj::getSound(EmbeddedSound);
				}
			}
		}
		HX_STACK_LINE(283)
		this->_looped = Looped;
		HX_STACK_LINE(284)
		this->autoDestroy = AutoDestroy;
		HX_STACK_LINE(285)
		this->updateTransform();
		HX_STACK_LINE(286)
		this->exists = true;
		HX_STACK_LINE(287)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSound_obj,loadEmbedded,return )

Void FlxSound_obj::kill( ){
{
		HX_STACK_PUSH("FlxSound::kill","org/flixel/FlxSound.hx",251);
		HX_STACK_THIS(this);
		HX_STACK_LINE(252)
		this->super::kill();
		HX_STACK_LINE(253)
		this->cleanup(false,null(),null());
	}
return null();
}


Void FlxSound_obj::update( ){
{
		HX_STACK_PUSH("FlxSound::update","org/flixel/FlxSound.hx",182);
		HX_STACK_THIS(this);
		HX_STACK_LINE(183)
		if ((!(this->get_playing()))){
			HX_STACK_LINE(184)
			return null();
		}
		HX_STACK_LINE(188)
		this->_position = this->_channel->get_position();
		HX_STACK_LINE(190)
		Float radialMultiplier = 1.0;		HX_STACK_VAR(radialMultiplier,"radialMultiplier");
		HX_STACK_LINE(191)
		Float fadeMultiplier = 1.0;		HX_STACK_VAR(fadeMultiplier,"fadeMultiplier");
		HX_STACK_LINE(194)
		if (((this->_target != null()))){
			struct _Function_2_1{
				inline static Float Block( ::org::flixel::FlxSound_obj *__this){
					HX_STACK_PUSH("*::closure","org/flixel/FlxSound.hx",196);
					{
						HX_STACK_LINE(196)
						::org::flixel::FlxPoint Point1 = ::org::flixel::FlxPoint_obj::__new(__this->_target->x,__this->_target->y);		HX_STACK_VAR(Point1,"Point1");
						::org::flixel::FlxPoint Point2 = ::org::flixel::FlxPoint_obj::__new(__this->x,__this->y);		HX_STACK_VAR(Point2,"Point2");
						HX_STACK_LINE(196)
						Float dx = (Point1->x - Point2->x);		HX_STACK_VAR(dx,"dx");
						HX_STACK_LINE(196)
						Float dy = (Point1->y - Point2->y);		HX_STACK_VAR(dy,"dy");
						HX_STACK_LINE(196)
						return ::Math_obj::sqrt(((dx * dx) + (dy * dy)));
					}
					return null();
				}
			};
			HX_STACK_LINE(196)
			radialMultiplier = (Float(_Function_2_1::Block(this)) / Float(this->_radius));
			HX_STACK_LINE(197)
			if (((radialMultiplier < (int)0))){
				HX_STACK_LINE(197)
				radialMultiplier = (int)0;
			}
			HX_STACK_LINE(198)
			if (((radialMultiplier > (int)1))){
				HX_STACK_LINE(198)
				radialMultiplier = (int)1;
			}
			HX_STACK_LINE(200)
			radialMultiplier = ((int)1 - radialMultiplier);
			HX_STACK_LINE(202)
			if ((this->_pan)){
				HX_STACK_LINE(204)
				Float d = (Float(((this->x - this->_target->x))) / Float(this->_radius));		HX_STACK_VAR(d,"d");
				HX_STACK_LINE(205)
				if (((d < (int)-1))){
					HX_STACK_LINE(206)
					d = (int)-1;
				}
				else{
					HX_STACK_LINE(209)
					if (((d > (int)1))){
						HX_STACK_LINE(210)
						d = (int)1;
					}
				}
				HX_STACK_LINE(213)
				this->_transform->pan = d;
			}
		}
		HX_STACK_LINE(218)
		if (((this->_fade != null()))){
			HX_STACK_LINE(220)
			{
				HX_STACK_LINE(220)
				::org::flixel::FadeTween _g = this->_fade;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(220)
				_g->set_progress((_g->get_progress() + ::org::flixel::FlxG_obj::elapsed));
			}
			HX_STACK_LINE(221)
			fadeMultiplier = this->_fade->get_value();
			HX_STACK_LINE(223)
			if ((this->_fade->get_finished())){
				HX_STACK_LINE(225)
				this->_fade = null();
				HX_STACK_LINE(226)
				if (((this->_onFadeComplete_dyn() != null()))){
					HX_STACK_LINE(227)
					this->_onFadeComplete();
				}
			}
		}
		HX_STACK_LINE(233)
		this->_volumeAdjust = (radialMultiplier * fadeMultiplier);
		HX_STACK_LINE(234)
		this->updateTransform();
		HX_STACK_LINE(236)
		if (((this->_transform->volume > (int)0))){
			HX_STACK_LINE(238)
			this->amplitudeLeft = (Float(this->_channel->get_leftPeak()) / Float(this->_transform->volume));
			HX_STACK_LINE(239)
			this->amplitudeRight = (Float(this->_channel->get_rightPeak()) / Float(this->_transform->volume));
			HX_STACK_LINE(240)
			this->amplitude = (((this->amplitudeLeft + this->amplitudeRight)) * 0.5);
		}
		else{
			HX_STACK_LINE(244)
			this->amplitudeLeft = (int)0;
			HX_STACK_LINE(245)
			this->amplitudeRight = (int)0;
			HX_STACK_LINE(246)
			this->amplitude = (int)0;
		}
	}
return null();
}


Void FlxSound_obj::destroy( ){
{
		HX_STACK_PUSH("FlxSound::destroy","org/flixel/FlxSound.hx",154);
		HX_STACK_THIS(this);
		HX_STACK_LINE(155)
		this->_transform = null();
		HX_STACK_LINE(156)
		this->exists = false;
		HX_STACK_LINE(157)
		this->active = false;
		HX_STACK_LINE(158)
		this->_target = null();
		HX_STACK_LINE(159)
		this->name = null();
		HX_STACK_LINE(160)
		this->artist = null();
		HX_STACK_LINE(162)
		if (((this->_channel != null()))){
			HX_STACK_LINE(164)
			this->_channel->removeEventListener(::native::events::Event_obj::SOUND_COMPLETE,this->stopped_dyn(),null());
			HX_STACK_LINE(165)
			this->_channel->stop();
			HX_STACK_LINE(166)
			this->_channel = null();
		}
		HX_STACK_LINE(169)
		if (((this->_sound != null()))){
			HX_STACK_LINE(171)
			this->_sound->removeEventListener(::native::events::Event_obj::ID3,this->gotID3_dyn(),null());
			HX_STACK_LINE(172)
			this->_sound = null();
		}
		HX_STACK_LINE(175)
		this->super::destroy();
	}
return null();
}


Void FlxSound_obj::reset( ){
{
		HX_STACK_PUSH("FlxSound::reset","org/flixel/FlxSound.hx",120);
		HX_STACK_THIS(this);
		HX_STACK_LINE(121)
		this->destroy();
		HX_STACK_LINE(123)
		this->x = (int)0;
		HX_STACK_LINE(124)
		this->y = (int)0;
		HX_STACK_LINE(126)
		this->_position = (int)0;
		HX_STACK_LINE(127)
		this->_paused = false;
		HX_STACK_LINE(128)
		this->_volume = 1.0;
		HX_STACK_LINE(129)
		this->_volumeAdjust = 1.0;
		HX_STACK_LINE(130)
		this->_looped = false;
		HX_STACK_LINE(131)
		this->_target = null();
		HX_STACK_LINE(132)
		this->_radius = (int)0;
		HX_STACK_LINE(133)
		this->_pan = false;
		HX_STACK_LINE(134)
		if (((this->_fade != null()))){
			HX_STACK_LINE(134)
			this->_fade->destroy();
		}
		HX_STACK_LINE(135)
		this->_fade = null();
		HX_STACK_LINE(136)
		this->_onFadeComplete = null();
		HX_STACK_LINE(137)
		this->visible = false;
		HX_STACK_LINE(138)
		this->amplitude = (int)0;
		HX_STACK_LINE(139)
		this->amplitudeLeft = (int)0;
		HX_STACK_LINE(140)
		this->amplitudeRight = (int)0;
		HX_STACK_LINE(141)
		this->autoDestroy = false;
		HX_STACK_LINE(143)
		if (((this->_transform == null()))){
			HX_STACK_LINE(144)
			this->_transform = ::native::media::SoundTransform_obj::__new(null(),null());
		}
		HX_STACK_LINE(147)
		this->_transform->pan = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSound_obj,reset,(void))


FlxSound_obj::FlxSound_obj()
{
}

void FlxSound_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxSound);
	HX_MARK_MEMBER_NAME(volume,"volume");
	HX_MARK_MEMBER_NAME(playing,"playing");
	HX_MARK_MEMBER_NAME(_onFadeComplete,"_onFadeComplete");
	HX_MARK_MEMBER_NAME(_fade,"_fade");
	HX_MARK_MEMBER_NAME(_pan,"_pan");
	HX_MARK_MEMBER_NAME(_radius,"_radius");
	HX_MARK_MEMBER_NAME(_target,"_target");
	HX_MARK_MEMBER_NAME(_looped,"_looped");
	HX_MARK_MEMBER_NAME(_volumeAdjust,"_volumeAdjust");
	HX_MARK_MEMBER_NAME(_volume,"_volume");
	HX_MARK_MEMBER_NAME(_position,"_position");
	HX_MARK_MEMBER_NAME(_paused,"_paused");
	HX_MARK_MEMBER_NAME(_transform,"_transform");
	HX_MARK_MEMBER_NAME(_channel,"_channel");
	HX_MARK_MEMBER_NAME(_sound,"_sound");
	HX_MARK_MEMBER_NAME(autoDestroy,"autoDestroy");
	HX_MARK_MEMBER_NAME(amplitudeRight,"amplitudeRight");
	HX_MARK_MEMBER_NAME(amplitudeLeft,"amplitudeLeft");
	HX_MARK_MEMBER_NAME(amplitude,"amplitude");
	HX_MARK_MEMBER_NAME(artist,"artist");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(survive,"survive");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxSound_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(volume,"volume");
	HX_VISIT_MEMBER_NAME(playing,"playing");
	HX_VISIT_MEMBER_NAME(_onFadeComplete,"_onFadeComplete");
	HX_VISIT_MEMBER_NAME(_fade,"_fade");
	HX_VISIT_MEMBER_NAME(_pan,"_pan");
	HX_VISIT_MEMBER_NAME(_radius,"_radius");
	HX_VISIT_MEMBER_NAME(_target,"_target");
	HX_VISIT_MEMBER_NAME(_looped,"_looped");
	HX_VISIT_MEMBER_NAME(_volumeAdjust,"_volumeAdjust");
	HX_VISIT_MEMBER_NAME(_volume,"_volume");
	HX_VISIT_MEMBER_NAME(_position,"_position");
	HX_VISIT_MEMBER_NAME(_paused,"_paused");
	HX_VISIT_MEMBER_NAME(_transform,"_transform");
	HX_VISIT_MEMBER_NAME(_channel,"_channel");
	HX_VISIT_MEMBER_NAME(_sound,"_sound");
	HX_VISIT_MEMBER_NAME(autoDestroy,"autoDestroy");
	HX_VISIT_MEMBER_NAME(amplitudeRight,"amplitudeRight");
	HX_VISIT_MEMBER_NAME(amplitudeLeft,"amplitudeLeft");
	HX_VISIT_MEMBER_NAME(amplitude,"amplitude");
	HX_VISIT_MEMBER_NAME(artist,"artist");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(survive,"survive");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxSound_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		if (HX_FIELD_EQ(inName,"_pan") ) { return _pan; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"_fade") ) { return _fade; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"gotID3") ) { return gotID3_dyn(); }
		if (HX_FIELD_EQ(inName,"volume") ) { return inCallProp ? get_volume() : volume; }
		if (HX_FIELD_EQ(inName,"fadeIn") ) { return fadeIn_dyn(); }
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_sound") ) { return _sound; }
		if (HX_FIELD_EQ(inName,"artist") ) { return artist; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cleanup") ) { return cleanup_dyn(); }
		if (HX_FIELD_EQ(inName,"stopped") ) { return stopped_dyn(); }
		if (HX_FIELD_EQ(inName,"playing") ) { return inCallProp ? get_playing() : playing; }
		if (HX_FIELD_EQ(inName,"fadeOut") ) { return fadeOut_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_radius") ) { return _radius; }
		if (HX_FIELD_EQ(inName,"_target") ) { return _target; }
		if (HX_FIELD_EQ(inName,"_looped") ) { return _looped; }
		if (HX_FIELD_EQ(inName,"_volume") ) { return _volume; }
		if (HX_FIELD_EQ(inName,"_paused") ) { return _paused; }
		if (HX_FIELD_EQ(inName,"survive") ) { return survive; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_channel") ) { return _channel; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"proximity") ) { return proximity_dyn(); }
		if (HX_FIELD_EQ(inName,"_position") ) { return _position; }
		if (HX_FIELD_EQ(inName,"amplitude") ) { return amplitude; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"startSound") ) { return startSound_dyn(); }
		if (HX_FIELD_EQ(inName,"set_volume") ) { return set_volume_dyn(); }
		if (HX_FIELD_EQ(inName,"get_volume") ) { return get_volume_dyn(); }
		if (HX_FIELD_EQ(inName,"loadStream") ) { return loadStream_dyn(); }
		if (HX_FIELD_EQ(inName,"_transform") ) { return _transform; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_playing") ) { return get_playing_dyn(); }
		if (HX_FIELD_EQ(inName,"autoDestroy") ) { return autoDestroy; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadEmbedded") ) { return loadEmbedded_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_volumeAdjust") ) { return _volumeAdjust; }
		if (HX_FIELD_EQ(inName,"amplitudeLeft") ) { return amplitudeLeft; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"amplitudeRight") ) { return amplitudeRight; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateTransform") ) { return updateTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getActualVolume") ) { return getActualVolume_dyn(); }
		if (HX_FIELD_EQ(inName,"_onFadeComplete") ) { return _onFadeComplete; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxSound_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_pan") ) { _pan=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_fade") ) { _fade=inValue.Cast< ::org::flixel::FadeTween >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"volume") ) { if (inCallProp) return set_volume(inValue);volume=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sound") ) { _sound=inValue.Cast< ::native::media::Sound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"artist") ) { artist=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"playing") ) { playing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_radius") ) { _radius=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_target") ) { _target=inValue.Cast< ::org::flixel::FlxObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_looped") ) { _looped=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_volume") ) { _volume=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_paused") ) { _paused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"survive") ) { survive=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_channel") ) { _channel=inValue.Cast< ::native::media::SoundChannel >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { _position=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"amplitude") ) { amplitude=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_transform") ) { _transform=inValue.Cast< ::native::media::SoundTransform >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"autoDestroy") ) { autoDestroy=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_volumeAdjust") ) { _volumeAdjust=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"amplitudeLeft") ) { amplitudeLeft=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"amplitudeRight") ) { amplitudeRight=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_onFadeComplete") ) { _onFadeComplete=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxSound_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("volume"));
	outFields->push(HX_CSTRING("playing"));
	outFields->push(HX_CSTRING("_fade"));
	outFields->push(HX_CSTRING("_pan"));
	outFields->push(HX_CSTRING("_radius"));
	outFields->push(HX_CSTRING("_target"));
	outFields->push(HX_CSTRING("_looped"));
	outFields->push(HX_CSTRING("_volumeAdjust"));
	outFields->push(HX_CSTRING("_volume"));
	outFields->push(HX_CSTRING("_position"));
	outFields->push(HX_CSTRING("_paused"));
	outFields->push(HX_CSTRING("_transform"));
	outFields->push(HX_CSTRING("_channel"));
	outFields->push(HX_CSTRING("_sound"));
	outFields->push(HX_CSTRING("autoDestroy"));
	outFields->push(HX_CSTRING("amplitudeRight"));
	outFields->push(HX_CSTRING("amplitudeLeft"));
	outFields->push(HX_CSTRING("amplitude"));
	outFields->push(HX_CSTRING("artist"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("survive"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("gotID3"),
	HX_CSTRING("cleanup"),
	HX_CSTRING("stopped"),
	HX_CSTRING("startSound"),
	HX_CSTRING("updateTransform"),
	HX_CSTRING("getActualVolume"),
	HX_CSTRING("set_volume"),
	HX_CSTRING("get_volume"),
	HX_CSTRING("volume"),
	HX_CSTRING("get_playing"),
	HX_CSTRING("playing"),
	HX_CSTRING("fadeIn"),
	HX_CSTRING("fadeOut"),
	HX_CSTRING("stop"),
	HX_CSTRING("pause"),
	HX_CSTRING("resume"),
	HX_CSTRING("play"),
	HX_CSTRING("proximity"),
	HX_CSTRING("loadStream"),
	HX_CSTRING("loadEmbedded"),
	HX_CSTRING("kill"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("reset"),
	HX_CSTRING("_onFadeComplete"),
	HX_CSTRING("_fade"),
	HX_CSTRING("_pan"),
	HX_CSTRING("_radius"),
	HX_CSTRING("_target"),
	HX_CSTRING("_looped"),
	HX_CSTRING("_volumeAdjust"),
	HX_CSTRING("_volume"),
	HX_CSTRING("_position"),
	HX_CSTRING("_paused"),
	HX_CSTRING("_transform"),
	HX_CSTRING("_channel"),
	HX_CSTRING("_sound"),
	HX_CSTRING("autoDestroy"),
	HX_CSTRING("amplitudeRight"),
	HX_CSTRING("amplitudeLeft"),
	HX_CSTRING("amplitude"),
	HX_CSTRING("artist"),
	HX_CSTRING("name"),
	HX_CSTRING("survive"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxSound_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxSound_obj::__mClass,"__mClass");
};

Class FlxSound_obj::__mClass;

void FlxSound_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxSound"), hx::TCanCast< FlxSound_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxSound_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
