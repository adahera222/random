#include <hxcpp.h>

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
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_events_TouchEvent
#include <native/events/TouchEvent.h>
#endif
#ifndef INCLUDED_native_media_Sound
#include <native/media/Sound.h>
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
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSound
#include <org/flixel/FlxSound.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSprite
#include <org/flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedButton
#include <org/flixel/FlxTypedButton.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMouse
#include <org/flixel/system/input/FlxMouse.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxTouch
#include <org/flixel/system/input/FlxTouch.h>
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
namespace org{
namespace flixel{

Void FlxTypedButton_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{
HX_STACK_PUSH("FlxTypedButton::new","org/flixel/FlxButton.hx",131);
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(132)
	super::__construct(X,Y,null());
	HX_STACK_LINE(134)
	this->loadGraphic(::org::flixel::FlxAssets_obj::imgDefaultButton,true,false,(int)80,(int)20,null(),null());
	HX_STACK_LINE(136)
	this->onUp = OnClick;
	HX_STACK_LINE(137)
	this->onDown = null();
	HX_STACK_LINE(138)
	this->onOut = null();
	HX_STACK_LINE(139)
	this->onOver = null();
	HX_STACK_LINE(141)
	this->soundOver = null();
	HX_STACK_LINE(142)
	this->soundOut = null();
	HX_STACK_LINE(143)
	this->soundDown = null();
	HX_STACK_LINE(144)
	this->soundUp = null();
	HX_STACK_LINE(146)
	this->status = (int)0;
	HX_STACK_LINE(147)
	this->on = false;
	HX_STACK_LINE(148)
	this->_pressed = false;
	HX_STACK_LINE(149)
	this->_initialized = false;
}
;
	return null();
}

FlxTypedButton_obj::~FlxTypedButton_obj() { }

Dynamic FlxTypedButton_obj::__CreateEmpty() { return  new FlxTypedButton_obj; }
hx::ObjectPtr< FlxTypedButton_obj > FlxTypedButton_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{  hx::ObjectPtr< FlxTypedButton_obj > result = new FlxTypedButton_obj();
	result->__construct(__o_X,__o_Y,Label,OnClick);
	return result;}

Dynamic FlxTypedButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTypedButton_obj > result = new FlxTypedButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::org::flixel::system::layer::Atlas FlxTypedButton_obj::set_atlas( ::org::flixel::system::layer::Atlas value){
	HX_STACK_PUSH("FlxTypedButton::set_atlas","org/flixel/FlxButton.hx",437);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(438)
	::org::flixel::system::layer::Atlas atl = this->super::set_atlas(value);		HX_STACK_VAR(atl,"atl");
	HX_STACK_LINE(439)
	if (((bool((atl == value)) && bool((this->label != null()))))){
		HX_STACK_LINE(440)
		this->label->__Field(HX_CSTRING("set_atlas"),true)(value);
	}
	HX_STACK_LINE(444)
	return value;
}


Void FlxTypedButton_obj::onMouseUp( ::native::events::Event event){
{
		HX_STACK_PUSH("FlxTypedButton::onMouseUp","org/flixel/FlxButton.hx",419);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(420)
		if (((bool((bool((bool(!(this->exists)) || bool(!(this->visible)))) || bool(!(this->active)))) || bool((this->status != (int)2))))){
			HX_STACK_LINE(421)
			return null();
		}
		HX_STACK_LINE(424)
		if (((this->onUp_dyn() != null()))){
			HX_STACK_LINE(425)
			this->onUp();
		}
		HX_STACK_LINE(428)
		if (((this->soundUp != null()))){
			HX_STACK_LINE(429)
			this->soundUp->play(true);
		}
		HX_STACK_LINE(432)
		this->status = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedButton_obj,onMouseUp,(void))

Void FlxTypedButton_obj::setSounds( ::native::media::Sound SoundOver,hx::Null< Float >  __o_SoundOverVolume,::native::media::Sound SoundOut,hx::Null< Float >  __o_SoundOutVolume,::native::media::Sound SoundDown,hx::Null< Float >  __o_SoundDownVolume,::native::media::Sound SoundUp,hx::Null< Float >  __o_SoundUpVolume){
Float SoundOverVolume = __o_SoundOverVolume.Default(1.0);
Float SoundOutVolume = __o_SoundOutVolume.Default(1.0);
Float SoundDownVolume = __o_SoundDownVolume.Default(1.0);
Float SoundUpVolume = __o_SoundUpVolume.Default(1.0);
	HX_STACK_PUSH("FlxTypedButton::setSounds","org/flixel/FlxButton.hx",396);
	HX_STACK_THIS(this);
	HX_STACK_ARG(SoundOver,"SoundOver");
	HX_STACK_ARG(SoundOverVolume,"SoundOverVolume");
	HX_STACK_ARG(SoundOut,"SoundOut");
	HX_STACK_ARG(SoundOutVolume,"SoundOutVolume");
	HX_STACK_ARG(SoundDown,"SoundDown");
	HX_STACK_ARG(SoundDownVolume,"SoundDownVolume");
	HX_STACK_ARG(SoundUp,"SoundUp");
	HX_STACK_ARG(SoundUpVolume,"SoundUpVolume");
{
		HX_STACK_LINE(397)
		if (((SoundOver != null()))){
			HX_STACK_LINE(398)
			this->soundOver = ::org::flixel::FlxG_obj::loadSound(SoundOver,SoundOverVolume,null(),null(),null(),null());
		}
		HX_STACK_LINE(401)
		if (((SoundOut != null()))){
			HX_STACK_LINE(402)
			this->soundOut = ::org::flixel::FlxG_obj::loadSound(SoundOut,SoundOutVolume,null(),null(),null(),null());
		}
		HX_STACK_LINE(405)
		if (((SoundDown != null()))){
			HX_STACK_LINE(406)
			this->soundDown = ::org::flixel::FlxG_obj::loadSound(SoundDown,SoundDownVolume,null(),null(),null(),null());
		}
		HX_STACK_LINE(409)
		if (((SoundUp != null()))){
			HX_STACK_LINE(410)
			this->soundUp = ::org::flixel::FlxG_obj::loadSound(SoundUp,SoundUpVolume,null(),null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(FlxTypedButton_obj,setSounds,(void))

Void FlxTypedButton_obj::draw( ){
{
		HX_STACK_PUSH("FlxTypedButton::draw","org/flixel/FlxButton.hx",371);
		HX_STACK_THIS(this);
		HX_STACK_LINE(372)
		this->super::draw();
		HX_STACK_LINE(373)
		if (((this->label != null()))){
			HX_STACK_LINE(375)
			this->label->__FieldRef(HX_CSTRING("cameras")) = this->cameras;
			HX_STACK_LINE(376)
			this->label->__Field(HX_CSTRING("draw"),true)();
		}
	}
return null();
}


bool FlxTypedButton_obj::updateButtonStatus( ::org::flixel::FlxPoint Point,::org::flixel::FlxCamera Camera,bool JustPressed){
	HX_STACK_PUSH("FlxTypedButton::updateButtonStatus","org/flixel/FlxButton.hx",333);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Point,"Point");
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_ARG(JustPressed,"JustPressed");
	HX_STACK_LINE(334)
	bool offAll = true;		HX_STACK_VAR(offAll,"offAll");
	HX_STACK_LINE(335)
	if ((this->overlapsPoint(Point,true,Camera))){
		HX_STACK_LINE(337)
		offAll = false;
		HX_STACK_LINE(338)
		if ((JustPressed)){
			HX_STACK_LINE(340)
			this->status = (int)2;
			HX_STACK_LINE(341)
			if (((this->onDown_dyn() != null()))){
				HX_STACK_LINE(342)
				this->onDown();
			}
			HX_STACK_LINE(345)
			if (((this->soundDown != null()))){
				HX_STACK_LINE(346)
				this->soundDown->play(true);
			}
		}
		HX_STACK_LINE(350)
		if (((this->status == (int)0))){
			HX_STACK_LINE(352)
			this->status = (int)1;
			HX_STACK_LINE(353)
			if (((this->onOver_dyn() != null()))){
				HX_STACK_LINE(354)
				this->onOver();
			}
			HX_STACK_LINE(357)
			if (((this->soundOver != null()))){
				HX_STACK_LINE(358)
				this->soundOver->play(true);
			}
		}
	}
	HX_STACK_LINE(364)
	return offAll;
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTypedButton_obj,updateButtonStatus,return )

Void FlxTypedButton_obj::updateButton( ){
{
		HX_STACK_PUSH("FlxTypedButton::updateButton","org/flixel/FlxButton.hx",249);
		HX_STACK_THIS(this);
		HX_STACK_LINE(252)
		bool continueUpdate = false;		HX_STACK_VAR(continueUpdate,"continueUpdate");
		HX_STACK_LINE(255)
		continueUpdate = ::org::flixel::FlxG_obj::mouse->_updateCursorContainer;
		HX_STACK_LINE(259)
		continueUpdate = true;
		HX_STACK_LINE(262)
		if ((continueUpdate)){
			HX_STACK_LINE(264)
			if (((this->cameras == null()))){
				HX_STACK_LINE(265)
				this->cameras = ::org::flixel::FlxG_obj::cameras;
			}
			HX_STACK_LINE(268)
			::org::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
			HX_STACK_LINE(269)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(270)
			int l = this->cameras->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(271)
			bool offAll = true;		HX_STACK_VAR(offAll,"offAll");
			HX_STACK_LINE(272)
			while(((i < l))){
				HX_STACK_LINE(274)
				camera = this->cameras->__get((i)++);
				HX_STACK_LINE(276)
				::org::flixel::FlxG_obj::mouse->getWorldPosition(camera,this->_point);
				HX_STACK_LINE(277)
				offAll = (  (((this->updateButtonStatus(this->_point,camera,::org::flixel::FlxG_obj::mouse->justPressed()) == false))) ? bool(false) : bool(offAll) );
				HX_STACK_LINE(280)
				{
					HX_STACK_LINE(280)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = ::org::flixel::FlxG_obj::touchManager->touches->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(280)
					while(((_g1 < _g))){
						HX_STACK_LINE(280)
						int j = (_g1)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(282)
						::org::flixel::system::input::FlxTouch touch = ::org::flixel::FlxG_obj::touchManager->touches->__get(j);		HX_STACK_VAR(touch,"touch");
						HX_STACK_LINE(283)
						touch->getWorldPosition(camera,this->_point);
						HX_STACK_LINE(284)
						offAll = (  (((this->updateButtonStatus(this->_point,camera,touch->justPressed()) == false))) ? bool(false) : bool(offAll) );
					}
				}
			}
			HX_STACK_LINE(288)
			if ((offAll)){
				HX_STACK_LINE(290)
				if (((this->status != (int)0))){
					HX_STACK_LINE(292)
					if (((this->onOut_dyn() != null()))){
						HX_STACK_LINE(293)
						this->onOut();
					}
					HX_STACK_LINE(296)
					if (((this->soundOut != null()))){
						HX_STACK_LINE(297)
						this->soundOut->play(true);
					}
				}
				HX_STACK_LINE(301)
				this->status = (int)0;
			}
		}
		HX_STACK_LINE(307)
		if (((this->label != null()))){
			HX_STACK_LINE(309)
			this->label->__FieldRef(HX_CSTRING("x")) = this->x;
			HX_STACK_LINE(310)
			this->label->__FieldRef(HX_CSTRING("y")) = this->y;
			HX_STACK_LINE(312)
			if (((this->labelOffset != null()))){
				HX_STACK_LINE(314)
				hx::AddEq(this->label->__FieldRef(HX_CSTRING("x")),this->labelOffset->x);
				HX_STACK_LINE(315)
				hx::AddEq(this->label->__FieldRef(HX_CSTRING("y")),this->labelOffset->y);
			}
			HX_STACK_LINE(318)
			this->label->__FieldRef(HX_CSTRING("scrollFactor")) = this->scrollFactor;
		}
		HX_STACK_LINE(322)
		if (((bool((this->status == (int)1)) && bool(this->on)))){
			HX_STACK_LINE(323)
			this->set_frame((int)0);
		}
		else{
			HX_STACK_LINE(327)
			this->set_frame(this->status);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedButton_obj,updateButton,(void))

Void FlxTypedButton_obj::update( ){
{
		HX_STACK_PUSH("FlxTypedButton::update","org/flixel/FlxButton.hx",223);
		HX_STACK_THIS(this);
		HX_STACK_LINE(224)
		this->updateButton();
		HX_STACK_LINE(228)
		if (((this->label == null()))){
			HX_STACK_LINE(229)
			return null();
		}
		HX_STACK_LINE(232)
		switch( (int)(this->get_frame())){
			case (int)1: {
				HX_STACK_LINE(234)
				this->label->__Field(HX_CSTRING("set_alpha"),true)(1.0);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(237)
				this->label->__Field(HX_CSTRING("set_alpha"),true)(0.5);
				HX_STACK_LINE(238)
				(this->label->__FieldRef(HX_CSTRING("y")))++;
			}
			;break;
			default: {
				HX_STACK_LINE(240)
				this->label->__Field(HX_CSTRING("set_alpha"),true)(0.8);
			}
		}
	}
return null();
}


Void FlxTypedButton_obj::preUpdate( ){
{
		HX_STACK_PUSH("FlxTypedButton::preUpdate","org/flixel/FlxButton.hx",201);
		HX_STACK_THIS(this);
		HX_STACK_LINE(202)
		this->super::preUpdate();
		HX_STACK_LINE(204)
		if ((!(this->_initialized))){
			HX_STACK_LINE(205)
			if (((::org::flixel::FlxG_obj::get_stage() != null()))){
				HX_STACK_LINE(209)
				::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
				HX_STACK_LINE(212)
				::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->onMouseUp_dyn(),null(),null(),null());
				HX_STACK_LINE(214)
				this->_initialized = true;
			}
		}
	}
return null();
}


Void FlxTypedButton_obj::destroy( ){
{
		HX_STACK_PUSH("FlxTypedButton::destroy","org/flixel/FlxButton.hx",156);
		HX_STACK_THIS(this);
		HX_STACK_LINE(157)
		if (((::org::flixel::FlxG_obj::get_stage() != null()))){
			HX_STACK_LINE(160)
			::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null());
			HX_STACK_LINE(164)
			::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->onMouseUp_dyn(),null());
		}
		HX_STACK_LINE(167)
		if (((this->label != null()))){
			HX_STACK_LINE(169)
			this->label->__Field(HX_CSTRING("destroy"),true)();
			HX_STACK_LINE(170)
			this->label = null();
		}
		HX_STACK_LINE(172)
		this->onUp = null();
		HX_STACK_LINE(173)
		this->onDown = null();
		HX_STACK_LINE(174)
		this->onOut = null();
		HX_STACK_LINE(175)
		this->onOver = null();
		HX_STACK_LINE(176)
		if (((this->soundOver != null()))){
			HX_STACK_LINE(177)
			this->soundOver->destroy();
		}
		HX_STACK_LINE(180)
		if (((this->soundOut != null()))){
			HX_STACK_LINE(181)
			this->soundOut->destroy();
		}
		HX_STACK_LINE(184)
		if (((this->soundDown != null()))){
			HX_STACK_LINE(185)
			this->soundDown->destroy();
		}
		HX_STACK_LINE(188)
		if (((this->soundUp != null()))){
			HX_STACK_LINE(189)
			this->soundUp->destroy();
		}
		HX_STACK_LINE(192)
		this->super::destroy();
	}
return null();
}



FlxTypedButton_obj::FlxTypedButton_obj()
{
}

void FlxTypedButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTypedButton);
	HX_MARK_MEMBER_NAME(_initialized,"_initialized");
	HX_MARK_MEMBER_NAME(_pressed,"_pressed");
	HX_MARK_MEMBER_NAME(soundUp,"soundUp");
	HX_MARK_MEMBER_NAME(soundDown,"soundDown");
	HX_MARK_MEMBER_NAME(soundOut,"soundOut");
	HX_MARK_MEMBER_NAME(soundOver,"soundOver");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(onOut,"onOut");
	HX_MARK_MEMBER_NAME(onOver,"onOver");
	HX_MARK_MEMBER_NAME(onDown,"onDown");
	HX_MARK_MEMBER_NAME(onUp,"onUp");
	HX_MARK_MEMBER_NAME(labelOffset,"labelOffset");
	HX_MARK_MEMBER_NAME(label,"label");
	HX_MARK_MEMBER_NAME(on,"on");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxTypedButton_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_initialized,"_initialized");
	HX_VISIT_MEMBER_NAME(_pressed,"_pressed");
	HX_VISIT_MEMBER_NAME(soundUp,"soundUp");
	HX_VISIT_MEMBER_NAME(soundDown,"soundDown");
	HX_VISIT_MEMBER_NAME(soundOut,"soundOut");
	HX_VISIT_MEMBER_NAME(soundOver,"soundOver");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(onOut,"onOut");
	HX_VISIT_MEMBER_NAME(onOver,"onOver");
	HX_VISIT_MEMBER_NAME(onDown,"onDown");
	HX_VISIT_MEMBER_NAME(onUp,"onUp");
	HX_VISIT_MEMBER_NAME(labelOffset,"labelOffset");
	HX_VISIT_MEMBER_NAME(label,"label");
	HX_VISIT_MEMBER_NAME(on,"on");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxTypedButton_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"on") ) { return on; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"onUp") ) { return onUp; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"onOut") ) { return onOut; }
		if (HX_FIELD_EQ(inName,"label") ) { return label; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		if (HX_FIELD_EQ(inName,"onOver") ) { return onOver; }
		if (HX_FIELD_EQ(inName,"onDown") ) { return onDown; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"soundUp") ) { return soundUp; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_pressed") ) { return _pressed; }
		if (HX_FIELD_EQ(inName,"soundOut") ) { return soundOut; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_atlas") ) { return set_atlas_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"setSounds") ) { return setSounds_dyn(); }
		if (HX_FIELD_EQ(inName,"preUpdate") ) { return preUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"soundDown") ) { return soundDown; }
		if (HX_FIELD_EQ(inName,"soundOver") ) { return soundOver; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"labelOffset") ) { return labelOffset; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateButton") ) { return updateButton_dyn(); }
		if (HX_FIELD_EQ(inName,"_initialized") ) { return _initialized; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"updateButtonStatus") ) { return updateButtonStatus_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTypedButton_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"on") ) { on=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"onUp") ) { onUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"onOut") ) { onOut=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"label") ) { label=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onOver") ) { onOver=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onDown") ) { onDown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"soundUp") ) { soundUp=inValue.Cast< ::org::flixel::FlxSound >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_pressed") ) { _pressed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"soundOut") ) { soundOut=inValue.Cast< ::org::flixel::FlxSound >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"soundDown") ) { soundDown=inValue.Cast< ::org::flixel::FlxSound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"soundOver") ) { soundOver=inValue.Cast< ::org::flixel::FlxSound >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"labelOffset") ) { labelOffset=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_initialized") ) { _initialized=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTypedButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_initialized"));
	outFields->push(HX_CSTRING("_pressed"));
	outFields->push(HX_CSTRING("soundUp"));
	outFields->push(HX_CSTRING("soundDown"));
	outFields->push(HX_CSTRING("soundOut"));
	outFields->push(HX_CSTRING("soundOver"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("labelOffset"));
	outFields->push(HX_CSTRING("label"));
	outFields->push(HX_CSTRING("on"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_atlas"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("setSounds"),
	HX_CSTRING("draw"),
	HX_CSTRING("updateButtonStatus"),
	HX_CSTRING("updateButton"),
	HX_CSTRING("update"),
	HX_CSTRING("preUpdate"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_initialized"),
	HX_CSTRING("_pressed"),
	HX_CSTRING("soundUp"),
	HX_CSTRING("soundDown"),
	HX_CSTRING("soundOut"),
	HX_CSTRING("soundOver"),
	HX_CSTRING("status"),
	HX_CSTRING("onOut"),
	HX_CSTRING("onOver"),
	HX_CSTRING("onDown"),
	HX_CSTRING("onUp"),
	HX_CSTRING("labelOffset"),
	HX_CSTRING("label"),
	HX_CSTRING("on"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTypedButton_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTypedButton_obj::__mClass,"__mClass");
};

Class FlxTypedButton_obj::__mClass;

void FlxTypedButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxTypedButton"), hx::TCanCast< FlxTypedButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxTypedButton_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
