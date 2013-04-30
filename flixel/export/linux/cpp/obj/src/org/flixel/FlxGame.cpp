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
#ifndef INCLUDED_native_Lib
#include <native/Lib.h>
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
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
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
#ifndef INCLUDED_native_display_StageAlign
#include <native/display/StageAlign.h>
#endif
#ifndef INCLUDED_native_display_StageScaleMode
#include <native/display/StageScaleMode.h>
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
#ifndef INCLUDED_native_text_Font
#include <native/text/Font.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
#ifndef INCLUDED_native_text_TextFormatAlign
#include <native/text/TextFormatAlign.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
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
#ifndef INCLUDED_org_flixel_FlxSave
#include <org/flixel/FlxSave.h>
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
#ifndef INCLUDED_org_flixel_FlxTimer
#include <org/flixel/FlxTimer.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedGroup
#include <org/flixel/FlxTypedGroup.h>
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
#ifndef INCLUDED_org_flixel_system_FlxReplay
#include <org/flixel/system/FlxReplay.h>
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
#ifndef INCLUDED_org_flixel_system_debug_Watch
#include <org/flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxInputs
#include <org/flixel/system/input/FlxInputs.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMouse
#include <org/flixel/system/input/FlxMouse.h>
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
namespace org{
namespace flixel{

Void FlxGame_obj::__construct(int GameSizeX,int GameSizeY,::Class InitialState,hx::Null< Float >  __o_Zoom,hx::Null< int >  __o_GameFramerate,hx::Null< int >  __o_FlashFramerate)
{
HX_STACK_PUSH("FlxGame::new","org/flixel/FlxGame.hx",185);
Float Zoom = __o_Zoom.Default(1);
int GameFramerate = __o_GameFramerate.Default(60);
int FlashFramerate = __o_FlashFramerate.Default(30);
{
	HX_STACK_LINE(186)
	super::__construct();
	HX_STACK_LINE(189)
	this->_lostFocus = false;
	HX_STACK_LINE(190)
	this->_focus = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(191)
	this->_focus->set_visible(false);
	HX_STACK_LINE(192)
	this->_soundTray = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(193)
	this->_inputContainer = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(196)
	::org::flixel::FlxG_obj::init(hx::ObjectPtr<OBJ_>(this),GameSizeX,GameSizeY,Zoom);
	HX_STACK_LINE(197)
	::org::flixel::FlxG_obj::set_framerate(GameFramerate);
	HX_STACK_LINE(198)
	::org::flixel::FlxG_obj::set_flashFramerate(FlashFramerate);
	HX_STACK_LINE(199)
	this->_accumulator = this->_step;
	HX_STACK_LINE(200)
	this->_total = (int)0;
	HX_STACK_LINE(201)
	::org::flixel::FlxGame_obj::_mark = (int)0;
	HX_STACK_LINE(202)
	this->_state = null();
	HX_STACK_LINE(203)
	this->useSoundHotKeys = true;
	HX_STACK_LINE(206)
	::org::flixel::FlxG_obj::debug = true;
	HX_STACK_LINE(207)
	this->_debuggerUp = false;
	HX_STACK_LINE(212)
	this->_replay = ::org::flixel::system::FlxReplay_obj::__new();
	HX_STACK_LINE(213)
	this->_replayRequested = false;
	HX_STACK_LINE(214)
	this->_recordingRequested = false;
	HX_STACK_LINE(215)
	this->_replaying = false;
	HX_STACK_LINE(216)
	this->_recording = false;
	HX_STACK_LINE(220)
	this->_iState = InitialState;
	HX_STACK_LINE(221)
	this->_requestedState = null();
	HX_STACK_LINE(222)
	this->_requestedReset = true;
	HX_STACK_LINE(224)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->create_dyn(),null(),null(),null());
}
;
	return null();
}

FlxGame_obj::~FlxGame_obj() { }

Dynamic FlxGame_obj::__CreateEmpty() { return  new FlxGame_obj; }
hx::ObjectPtr< FlxGame_obj > FlxGame_obj::__new(int GameSizeX,int GameSizeY,::Class InitialState,hx::Null< Float >  __o_Zoom,hx::Null< int >  __o_GameFramerate,hx::Null< int >  __o_FlashFramerate)
{  hx::ObjectPtr< FlxGame_obj > result = new FlxGame_obj();
	result->__construct(GameSizeX,GameSizeY,InitialState,__o_Zoom,__o_GameFramerate,__o_FlashFramerate);
	return result;}

Dynamic FlxGame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxGame_obj > result = new FlxGame_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::org::flixel::system::FlxDebugger FlxGame_obj::getDebugger( ){
	HX_STACK_PUSH("FlxGame::getDebugger","org/flixel/FlxGame.hx",799);
	HX_STACK_THIS(this);
	HX_STACK_LINE(799)
	return this->_debugger;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,getDebugger,return )

Void FlxGame_obj::createFocusScreen( ){
{
		HX_STACK_PUSH("FlxGame::createFocusScreen","org/flixel/FlxGame.hx",755);
		HX_STACK_THIS(this);
		HX_STACK_LINE(756)
		::native::display::Graphics gfx = this->_focus->get_graphics();		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(757)
		int screenWidth = ::Std_obj::_int((::org::flixel::FlxG_obj::width * ::org::flixel::FlxCamera_obj::defaultZoom));		HX_STACK_VAR(screenWidth,"screenWidth");
		HX_STACK_LINE(758)
		int screenHeight = ::Std_obj::_int((::org::flixel::FlxG_obj::height * ::org::flixel::FlxCamera_obj::defaultZoom));		HX_STACK_VAR(screenHeight,"screenHeight");
		HX_STACK_LINE(761)
		gfx->moveTo((int)0,(int)0);
		HX_STACK_LINE(762)
		gfx->beginFill((int)0,0.5);
		HX_STACK_LINE(763)
		gfx->lineTo(screenWidth,(int)0);
		HX_STACK_LINE(764)
		gfx->lineTo(screenWidth,screenHeight);
		HX_STACK_LINE(765)
		gfx->lineTo((int)0,screenHeight);
		HX_STACK_LINE(766)
		gfx->lineTo((int)0,(int)0);
		HX_STACK_LINE(767)
		gfx->endFill();
		HX_STACK_LINE(770)
		int halfWidth = ::Std_obj::_int((Float(screenWidth) / Float((int)2)));		HX_STACK_VAR(halfWidth,"halfWidth");
		HX_STACK_LINE(771)
		int halfHeight = ::Std_obj::_int((Float(screenHeight) / Float((int)2)));		HX_STACK_VAR(halfHeight,"halfHeight");
		HX_STACK_LINE(772)
		int helper = ::Std_obj::_int((Float(((  (((halfWidth <= halfHeight))) ? Float(halfWidth) : Float(halfHeight) ))) / Float((int)3)));		HX_STACK_VAR(helper,"helper");
		HX_STACK_LINE(773)
		gfx->moveTo((halfWidth - helper),(halfHeight - helper));
		HX_STACK_LINE(774)
		gfx->beginFill((int)16777215,0.65);
		HX_STACK_LINE(775)
		gfx->lineTo((halfWidth + helper),halfHeight);
		HX_STACK_LINE(776)
		gfx->lineTo((halfWidth - helper),(halfHeight + helper));
		HX_STACK_LINE(777)
		gfx->lineTo((halfWidth - helper),(halfHeight - helper));
		HX_STACK_LINE(778)
		gfx->endFill();
		HX_STACK_LINE(780)
		::native::display::Sprite logo = ::native::display::Sprite_obj::__new();		HX_STACK_VAR(logo,"logo");
		HX_STACK_LINE(781)
		::org::flixel::FlxAssets_obj::drawLogo(logo->get_graphics());
		HX_STACK_LINE(782)
		logo->set_scaleX((Float(helper) / Float((int)1000)));
		HX_STACK_LINE(783)
		if (((logo->get_scaleX() < 0.2))){
			HX_STACK_LINE(784)
			logo->set_scaleX(0.2);
		}
		HX_STACK_LINE(787)
		logo->set_scaleY(logo->get_scaleX());
		HX_STACK_LINE(788)
		logo->set_x(logo->set_y((int)5));
		HX_STACK_LINE(789)
		logo->set_alpha(0.35);
		HX_STACK_LINE(790)
		this->_focus->addChild(logo);
		HX_STACK_LINE(792)
		this->addChild(this->_focus);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,createFocusScreen,(void))

Void FlxGame_obj::createSoundTray( ){
{
		HX_STACK_PUSH("FlxGame::createSoundTray","org/flixel/FlxGame.hx",684);
		HX_STACK_THIS(this);
		HX_STACK_LINE(685)
		this->_soundTray->set_visible(false);
		HX_STACK_LINE(686)
		this->_soundTray->set_scaleX((int)2);
		HX_STACK_LINE(687)
		this->_soundTray->set_scaleY((int)2);
		HX_STACK_LINE(689)
		::native::display::Bitmap tmp = ::native::display::Bitmap_obj::__new(::native::display::BitmapData_obj::__new((int)80,(int)30,true,(int)2130706432,null()),null(),null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(693)
		this->_soundTray->set_x((((Float(::org::flixel::FlxG_obj::width) / Float((int)2)) * ::org::flixel::FlxCamera_obj::defaultZoom) - ((Float(tmp->get_width()) / Float((int)2)) * this->_soundTray->get_scaleX())));
		HX_STACK_LINE(694)
		this->_soundTray->addChild(tmp);
		HX_STACK_LINE(696)
		::native::text::TextField text = ::native::text::TextField_obj::__new();		HX_STACK_VAR(text,"text");
		HX_STACK_LINE(697)
		text->set_width(tmp->get_width());
		HX_STACK_LINE(698)
		text->set_height(tmp->get_height());
		HX_STACK_LINE(699)
		text->set_multiline(true);
		HX_STACK_LINE(700)
		text->set_wordWrap(true);
		HX_STACK_LINE(701)
		text->set_selectable(false);
		HX_STACK_LINE(709)
		::native::text::TextFormat dtf = ::native::text::TextFormat_obj::__new(::nme::installer::Assets_obj::getFont(::org::flixel::FlxAssets_obj::defaultFont)->fontName,(int)8,(int)16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(dtf,"dtf");
		HX_STACK_LINE(710)
		dtf->align = ::native::text::TextFormatAlign_obj::CENTER;
		HX_STACK_LINE(711)
		text->set_defaultTextFormat(dtf);
		HX_STACK_LINE(712)
		this->_soundTray->addChild(text);
		HX_STACK_LINE(713)
		text->set_text(HX_CSTRING("VOLUME"));
		HX_STACK_LINE(714)
		text->set_y((int)16);
		HX_STACK_LINE(716)
		int bx = (int)10;		HX_STACK_VAR(bx,"bx");
		HX_STACK_LINE(717)
		int by = (int)14;		HX_STACK_VAR(by,"by");
		HX_STACK_LINE(718)
		this->_soundTrayBars = Array_obj< ::native::display::Bitmap >::__new();
		HX_STACK_LINE(719)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(720)
		while(((i < (int)10))){
			HX_STACK_LINE(722)
			tmp = ::native::display::Bitmap_obj::__new(::native::display::BitmapData_obj::__new((int)4,++(i),false,(int)-1,null()),null(),null());
			HX_STACK_LINE(723)
			tmp->set_x(bx);
			HX_STACK_LINE(724)
			tmp->set_y(by);
			HX_STACK_LINE(725)
			this->_soundTray->addChild(tmp);
			HX_STACK_LINE(726)
			this->_soundTrayBars->push(tmp);
			HX_STACK_LINE(727)
			hx::AddEq(bx,(int)6);
			HX_STACK_LINE(728)
			(by)--;
		}
		HX_STACK_LINE(731)
		this->_soundTray->set_y(-(this->_soundTray->get_height()));
		HX_STACK_LINE(732)
		this->_soundTray->set_visible(false);
		HX_STACK_LINE(733)
		this->addChild(this->_soundTray);
		HX_STACK_LINE(736)
		::org::flixel::FlxSave soundPrefs = ::org::flixel::FlxSave_obj::__new();		HX_STACK_VAR(soundPrefs,"soundPrefs");
		HX_STACK_LINE(737)
		if (((bool(soundPrefs->bind(HX_CSTRING("flixel"))) && bool((soundPrefs->data->__Field(HX_CSTRING("sound"),true) != null()))))){
			HX_STACK_LINE(739)
			if (((soundPrefs->data->__Field(HX_CSTRING("sound"),true)->__Field(HX_CSTRING("volume"),true) != null()))){
				HX_STACK_LINE(740)
				::org::flixel::FlxG_obj::setVolume(soundPrefs->data->__Field(HX_CSTRING("sound"),true)->__Field(HX_CSTRING("volume"),true));
			}
			HX_STACK_LINE(743)
			if (((soundPrefs->data->__Field(HX_CSTRING("sound"),true)->__Field(HX_CSTRING("mute"),true) != null()))){
				HX_STACK_LINE(744)
				::org::flixel::FlxG_obj::mute = soundPrefs->data->__Field(HX_CSTRING("sound"),true)->__Field(HX_CSTRING("mute"),true);
			}
			HX_STACK_LINE(747)
			soundPrefs->destroy();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,createSoundTray,(void))

Void FlxGame_obj::create( ::native::events::Event FlashEvent){
{
		HX_STACK_PUSH("FlxGame::create","org/flixel/FlxGame.hx",625);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(626)
		if (((this->get_stage() == null()))){
			HX_STACK_LINE(627)
			return null();
		}
		HX_STACK_LINE(630)
		this->removeEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->create_dyn(),null());
		HX_STACK_LINE(632)
		this->_total = ::native::Lib_obj::getTimer();
		HX_STACK_LINE(634)
		this->get_stage()->set_scaleMode(::native::display::StageScaleMode_obj::NO_SCALE_dyn());
		HX_STACK_LINE(635)
		this->get_stage()->set_align(::native::display::StageAlign_obj::TOP_LEFT_dyn());
		HX_STACK_LINE(636)
		this->get_stage()->set_frameRate(this->_flashFramerate);
		HX_STACK_LINE(638)
		this->addChild(this->_inputContainer);
		HX_STACK_LINE(640)
		::org::flixel::system::input::FlxInputs_obj::init();
		HX_STACK_LINE(643)
		if ((!(::org::flixel::FlxG_obj::mobile))){
			HX_STACK_LINE(647)
			if ((::org::flixel::FlxG_obj::debug)){
				HX_STACK_LINE(649)
				this->_debugger = ::org::flixel::system::FlxDebugger_obj::__new((::org::flixel::FlxG_obj::width * ::org::flixel::FlxCamera_obj::defaultZoom),(::org::flixel::FlxG_obj::height * ::org::flixel::FlxCamera_obj::defaultZoom));
				HX_STACK_LINE(653)
				::nme::Lib_obj::get_current()->get_stage()->addChild(this->_debugger);
			}
			HX_STACK_LINE(659)
			this->createSoundTray();
			HX_STACK_LINE(662)
			this->get_stage()->addEventListener(::native::events::Event_obj::DEACTIVATE,this->onFocusLost_dyn(),null(),null(),null());
			HX_STACK_LINE(663)
			this->get_stage()->addEventListener(::native::events::Event_obj::ACTIVATE,this->onFocus_dyn(),null(),null(),null());
			HX_STACK_LINE(665)
			this->createFocusScreen();
		}
		HX_STACK_LINE(669)
		if ((this->_requestedReset)){
			HX_STACK_LINE(671)
			{
				HX_STACK_LINE(671)
				this->_requestedState = ::Type_obj::createInstance(this->_iState,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(671)
				if ((::Std_obj::is(this->_requestedState,hx::ClassOf< ::org::flixel::FlxSubState >()))){
					HX_STACK_LINE(671)
					hx::Throw (HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
				}
				HX_STACK_LINE(671)
				this->_replayTimer = (int)0;
				HX_STACK_LINE(671)
				this->_replayCancelKeys = null();
				HX_STACK_LINE(671)
				::org::flixel::FlxG_obj::reset();
			}
			HX_STACK_LINE(672)
			this->switchState();
			HX_STACK_LINE(673)
			this->_requestedReset = false;
		}
		HX_STACK_LINE(677)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,create,(void))

Void FlxGame_obj::draw( ){
{
		HX_STACK_PUSH("FlxGame::draw","org/flixel/FlxGame.hx",587);
		HX_STACK_THIS(this);
		HX_STACK_LINE(589)
		if ((this->_debuggerUp)){
			HX_STACK_LINE(590)
			::org::flixel::FlxGame_obj::_mark = ::native::Lib_obj::getTimer();
		}
		HX_STACK_LINE(594)
		::org::flixel::system::layer::TileSheetData_obj::_DRAWCALLS = (int)0;
		HX_STACK_LINE(597)
		{
			HX_STACK_LINE(597)
			::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
			HX_STACK_LINE(597)
			Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
			HX_STACK_LINE(597)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(597)
			int l = cams->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(597)
			while(((i < l))){
				HX_STACK_LINE(597)
				cam = cams->__get((i)++);
				HX_STACK_LINE(597)
				if (((bool((bool((cam == null())) || bool(!(cam->exists)))) || bool(!(cam->visible))))){
					HX_STACK_LINE(597)
					continue;
				}
				HX_STACK_LINE(597)
				{
					HX_STACK_LINE(597)
					::org::flixel::system::layer::DrawStackItem currItem = cam->_headOfDrawStack->next;		HX_STACK_VAR(currItem,"currItem");
					HX_STACK_LINE(597)
					while(((currItem != null()))){
						HX_STACK_LINE(597)
						{
							HX_STACK_LINE(597)
							currItem->atlas = null();
							HX_STACK_LINE(597)
							currItem->initialized = false;
							HX_STACK_LINE(597)
							currItem->position = (int)0;
						}
						HX_STACK_LINE(597)
						::org::flixel::system::layer::DrawStackItem newStorageHead = currItem;		HX_STACK_VAR(newStorageHead,"newStorageHead");
						HX_STACK_LINE(597)
						currItem = currItem->next;
						HX_STACK_LINE(597)
						if (((::org::flixel::FlxCamera_obj::_storageHead == null()))){
							HX_STACK_LINE(597)
							::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
							HX_STACK_LINE(597)
							newStorageHead->next = null();
						}
						else{
							HX_STACK_LINE(597)
							newStorageHead->next = ::org::flixel::FlxCamera_obj::_storageHead;
							HX_STACK_LINE(597)
							::org::flixel::FlxCamera_obj::_storageHead = newStorageHead;
						}
					}
					HX_STACK_LINE(597)
					{
						HX_STACK_LINE(597)
						::org::flixel::system::layer::DrawStackItem _this = cam->_headOfDrawStack;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(597)
						_this->atlas = null();
						HX_STACK_LINE(597)
						_this->initialized = false;
						HX_STACK_LINE(597)
						_this->position = (int)0;
					}
					HX_STACK_LINE(597)
					cam->_headOfDrawStack->next = null();
					HX_STACK_LINE(597)
					cam->_currentStackItem = cam->_headOfDrawStack;
				}
				HX_STACK_LINE(597)
				cam->_canvas->get_graphics()->clear();
				HX_STACK_LINE(597)
				cam->_effectsLayer->get_graphics()->clear();
				HX_STACK_LINE(597)
				cam->fill((int(cam->bgColor) & int((int)16777215)),true,(Float(((int((int(cam->bgColor) >> int((int)24))) & int((int)255)))) / Float((int)255)),null());
			}
		}
		HX_STACK_LINE(598)
		this->_state->draw();
		HX_STACK_LINE(601)
		{
			HX_STACK_LINE(601)
			::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
			HX_STACK_LINE(601)
			Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
			HX_STACK_LINE(601)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(601)
			int l = cams->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(601)
			while(((i < l))){
				HX_STACK_LINE(601)
				cam = cams->__get((i)++);
				HX_STACK_LINE(601)
				if (((bool((bool((cam == null())) || bool(!(cam->exists)))) || bool(!(cam->visible))))){
					HX_STACK_LINE(601)
					continue;
				}
				HX_STACK_LINE(601)
				cam->render();
			}
		}
		HX_STACK_LINE(604)
		if ((this->_debuggerUp)){
			HX_STACK_LINE(605)
			this->_debugger->perf->drawCalls(::org::flixel::system::layer::TileSheetData_obj::_DRAWCALLS);
		}
		HX_STACK_LINE(611)
		{
			HX_STACK_LINE(611)
			::org::flixel::FlxBasic plugin;		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(611)
			Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
			HX_STACK_LINE(611)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(611)
			int l = pluginList->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(611)
			while(((i < l))){
				HX_STACK_LINE(611)
				plugin = pluginList->__get((i)++);
				HX_STACK_LINE(611)
				if (((bool(plugin->exists) && bool(plugin->visible)))){
					HX_STACK_LINE(611)
					plugin->draw();
				}
			}
		}
		HX_STACK_LINE(612)
		{
			HX_STACK_LINE(612)
			::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
			HX_STACK_LINE(612)
			Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
			HX_STACK_LINE(612)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(612)
			int l = cams->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(612)
			while(((i < l))){
				HX_STACK_LINE(612)
				cam = cams->__get((i)++);
				HX_STACK_LINE(612)
				if (((bool((bool((cam == null())) || bool(!(cam->exists)))) || bool(!(cam->visible))))){
					HX_STACK_LINE(612)
					continue;
				}
				HX_STACK_LINE(612)
				cam->drawFX();
			}
		}
		HX_STACK_LINE(614)
		if ((this->_debuggerUp)){
			HX_STACK_LINE(615)
			this->_debugger->perf->flixelDraw((::native::Lib_obj::getTimer() - ::org::flixel::FlxGame_obj::_mark));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,draw,(void))

Void FlxGame_obj::update( ){
{
		HX_STACK_PUSH("FlxGame::update","org/flixel/FlxGame.hx",559);
		HX_STACK_THIS(this);
		HX_STACK_LINE(561)
		if ((this->_debuggerUp)){
			HX_STACK_LINE(562)
			::org::flixel::FlxGame_obj::_mark = ::native::Lib_obj::getTimer();
		}
		HX_STACK_LINE(565)
		::org::flixel::FlxG_obj::elapsed = (::org::flixel::FlxG_obj::timeScale * this->_stepSeconds);
		HX_STACK_LINE(566)
		::org::flixel::FlxG_obj::updateSounds();
		HX_STACK_LINE(567)
		{
			HX_STACK_LINE(567)
			::org::flixel::FlxBasic plugin;		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(567)
			Array< ::org::flixel::FlxBasic > pluginList = ::org::flixel::FlxG_obj::plugins;		HX_STACK_VAR(pluginList,"pluginList");
			HX_STACK_LINE(567)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(567)
			int l = pluginList->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(567)
			while(((i < l))){
				HX_STACK_LINE(567)
				plugin = pluginList->__get((i)++);
				HX_STACK_LINE(567)
				if (((bool(plugin->exists) && bool(plugin->active)))){
					HX_STACK_LINE(567)
					plugin->update();
				}
			}
		}
		HX_STACK_LINE(568)
		this->_state->tryUpdate();
		HX_STACK_LINE(570)
		if (((bool(::org::flixel::FlxG_obj::tweener->active) && bool(::org::flixel::FlxG_obj::tweener->get_hasTween())))){
			HX_STACK_LINE(572)
			::org::flixel::tweens::FlxTween t;		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(572)
			Dynamic ft = ::org::flixel::FlxG_obj::tweener->_tween;		HX_STACK_VAR(ft,"ft");
			HX_STACK_LINE(572)
			while(((ft != null()))){
				HX_STACK_LINE(572)
				t = hx::TCast< org::flixel::tweens::FlxTween >::cast(ft);
				HX_STACK_LINE(572)
				if ((t->active)){
					HX_STACK_LINE(572)
					t->update();
					HX_STACK_LINE(572)
					if ((ft->__Field(HX_CSTRING("_finish"),true))){
						HX_STACK_LINE(572)
						ft->__Field(HX_CSTRING("finish"),true)();
					}
				}
				HX_STACK_LINE(572)
				ft = ft->__Field(HX_CSTRING("_next"),true);
			}
		}
		HX_STACK_LINE(575)
		{
			HX_STACK_LINE(575)
			::org::flixel::FlxCamera cam;		HX_STACK_VAR(cam,"cam");
			HX_STACK_LINE(575)
			Array< ::org::flixel::FlxCamera > cams = ::org::flixel::FlxG_obj::cameras;		HX_STACK_VAR(cams,"cams");
			HX_STACK_LINE(575)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(575)
			int l = cams->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(575)
			while(((i < l))){
				HX_STACK_LINE(575)
				cam = cams->__get((i)++);
				HX_STACK_LINE(575)
				if (((bool((cam != null())) && bool(cam->exists)))){
					HX_STACK_LINE(575)
					if ((cam->active)){
						HX_STACK_LINE(575)
						cam->update();
					}
					HX_STACK_LINE(575)
					if (((cam->target == null()))){
						HX_STACK_LINE(575)
						cam->_flashSprite->set_x((cam->x + cam->_flashOffsetX));
						HX_STACK_LINE(575)
						cam->_flashSprite->set_y((cam->y + cam->_flashOffsetY));
					}
					HX_STACK_LINE(575)
					cam->_flashSprite->set_visible(cam->visible);
				}
			}
		}
		HX_STACK_LINE(578)
		if ((this->_debuggerUp)){
			HX_STACK_LINE(579)
			this->_debugger->perf->flixelUpdate((::native::Lib_obj::getTimer() - ::org::flixel::FlxGame_obj::_mark));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,update,(void))

Void FlxGame_obj::updateSoundTray( Float MS){
{
		HX_STACK_PUSH("FlxGame::updateSoundTray","org/flixel/FlxGame.hx",524);
		HX_STACK_THIS(this);
		HX_STACK_ARG(MS,"MS");
		HX_STACK_LINE(524)
		if (((this->_soundTrayTimer > (int)0))){
			HX_STACK_LINE(527)
			hx::SubEq(this->_soundTrayTimer,(Float(MS) / Float((int)1000)));
		}
		else{
			HX_STACK_LINE(530)
			if (((this->_soundTray->get_y() > -(this->_soundTray->get_height())))){
				HX_STACK_LINE(532)
				{
					HX_STACK_LINE(532)
					::native::display::Sprite _g = this->_soundTray;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(532)
					_g->set_y((_g->get_y() - (((Float(MS) / Float((int)1000)) * ::org::flixel::FlxG_obj::height) * (int)2)));
				}
				HX_STACK_LINE(533)
				if (((this->_soundTray->get_y() <= -(this->_soundTray->get_height())))){
					HX_STACK_LINE(535)
					this->_soundTray->set_visible(false);
					HX_STACK_LINE(536)
					this->_updateSoundTray = false;
					HX_STACK_LINE(539)
					::org::flixel::FlxSave soundPrefs = ::org::flixel::FlxSave_obj::__new();		HX_STACK_VAR(soundPrefs,"soundPrefs");
					HX_STACK_LINE(540)
					if ((soundPrefs->bind(HX_CSTRING("flixel")))){
						HX_STACK_LINE(542)
						if (((soundPrefs->data->__Field(HX_CSTRING("sound"),true) == null()))){
							struct _Function_6_1{
								inline static Dynamic Block( ){
									HX_STACK_PUSH("*::closure","org/flixel/FlxGame.hx",544);
									{
										hx::Anon __result = hx::Anon_obj::Create();
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(543)
							soundPrefs->data->__FieldRef(HX_CSTRING("sound")) = _Function_6_1::Block();
						}
						HX_STACK_LINE(546)
						soundPrefs->data->__Field(HX_CSTRING("sound"),true)->__FieldRef(HX_CSTRING("mute")) = ::org::flixel::FlxG_obj::mute;
						HX_STACK_LINE(547)
						soundPrefs->data->__Field(HX_CSTRING("sound"),true)->__FieldRef(HX_CSTRING("volume")) = ::org::flixel::FlxG_obj::volume;
						HX_STACK_LINE(548)
						soundPrefs->close(null(),null());
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,updateSoundTray,(void))

Void FlxGame_obj::step( ){
{
		HX_STACK_PUSH("FlxGame::step","org/flixel/FlxGame.hx",414);
		HX_STACK_THIS(this);
		HX_STACK_LINE(416)
		if ((this->_requestedReset)){
			HX_STACK_LINE(418)
			{
				HX_STACK_LINE(418)
				this->_requestedState = ::Type_obj::createInstance(this->_iState,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(418)
				if ((::Std_obj::is(this->_requestedState,hx::ClassOf< ::org::flixel::FlxSubState >()))){
					HX_STACK_LINE(418)
					hx::Throw (HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
				}
				HX_STACK_LINE(418)
				this->_replayTimer = (int)0;
				HX_STACK_LINE(418)
				this->_replayCancelKeys = null();
				HX_STACK_LINE(418)
				::org::flixel::FlxG_obj::reset();
			}
			HX_STACK_LINE(419)
			this->_requestedReset = false;
		}
		HX_STACK_LINE(424)
		if ((this->_recordingRequested)){
			HX_STACK_LINE(426)
			this->_recordingRequested = false;
			HX_STACK_LINE(427)
			this->_replay->create(::org::flixel::FlxG_obj::globalSeed);
			HX_STACK_LINE(428)
			this->_recording = true;
			HX_STACK_LINE(431)
			this->_debugger->vcr->recording();
			HX_STACK_LINE(432)
			if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
				struct _Function_3_1{
					inline static ::String Block( ){
						HX_STACK_PUSH("*::closure","org/flixel/FlxGame.hx",432);
						{
							HX_STACK_LINE(432)
							Dynamic AnyArray = hx::TCastToArray(HX_CSTRING("FLIXEL: starting new flixel gameplay record."));		HX_STACK_VAR(AnyArray,"AnyArray");
							HX_STACK_LINE(432)
							::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
							HX_STACK_LINE(432)
							if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
								HX_STACK_LINE(432)
								string = ::Std_obj::string(AnyArray->__GetItem((int)0));
								HX_STACK_LINE(432)
								int i = (int)1;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(432)
								int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
								HX_STACK_LINE(432)
								while(((i < l))){
									HX_STACK_LINE(432)
									hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
								}
							}
							HX_STACK_LINE(432)
							return string;
						}
						return null();
					}
				};
				HX_STACK_LINE(432)
				::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  ((::Std_obj::is(HX_CSTRING("FLIXEL: starting new flixel gameplay record."),hx::ClassOf< Array<int> >()))) ? ::String(_Function_3_1::Block()) : ::String(::Std_obj::string(HX_CSTRING("FLIXEL: starting new flixel gameplay record."))) ));
			}
		}
		else{
			HX_STACK_LINE(435)
			if ((this->_replayRequested)){
				HX_STACK_LINE(437)
				this->_replayRequested = false;
				HX_STACK_LINE(438)
				this->_replay->rewind();
				HX_STACK_LINE(439)
				::org::flixel::FlxG_obj::globalSeed = this->_replay->seed;
				HX_STACK_LINE(441)
				this->_debugger->vcr->playing();
				HX_STACK_LINE(443)
				this->_replaying = true;
			}
		}
		HX_STACK_LINE(448)
		if (((this->_state != this->_requestedState))){
			HX_STACK_LINE(449)
			this->switchState();
		}
		HX_STACK_LINE(454)
		::org::flixel::FlxBasic_obj::_ACTIVECOUNT = (int)0;
		HX_STACK_LINE(457)
		if ((this->_replaying)){
			HX_STACK_LINE(459)
			this->_replay->playNextFrame();
			HX_STACK_LINE(460)
			if (((this->_replayTimer > (int)0))){
				HX_STACK_LINE(462)
				hx::SubEq(this->_replayTimer,this->_step);
				HX_STACK_LINE(463)
				if (((this->_replayTimer <= (int)0))){
					HX_STACK_LINE(464)
					if (((this->_replayCallback_dyn() != null()))){
						HX_STACK_LINE(467)
						this->_replayCallback();
						HX_STACK_LINE(468)
						this->_replayCallback = null();
					}
					else{
						HX_STACK_LINE(471)
						::org::flixel::FlxG_obj::stopReplay();
					}
				}
			}
			HX_STACK_LINE(476)
			if (((bool(this->_replaying) && bool(this->_replay->finished)))){
				HX_STACK_LINE(478)
				::org::flixel::FlxG_obj::stopReplay();
				HX_STACK_LINE(479)
				if (((this->_replayCallback_dyn() != null()))){
					HX_STACK_LINE(481)
					this->_replayCallback();
					HX_STACK_LINE(482)
					this->_replayCallback = null();
				}
			}
			HX_STACK_LINE(486)
			this->_debugger->vcr->updateRuntime(this->_step);
		}
		else{
			HX_STACK_LINE(493)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(493)
			int l = ::org::flixel::system::input::FlxInputs_obj::inputs->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(493)
			while(((i < l))){
				HX_STACK_LINE(493)
				::org::flixel::system::input::IFlxInput input = ::org::flixel::system::input::FlxInputs_obj::inputs->__get((i)++);		HX_STACK_VAR(input,"input");
				HX_STACK_LINE(493)
				input->update();
			}
		}
		HX_STACK_LINE(497)
		if ((this->_recording)){
			HX_STACK_LINE(499)
			this->_replay->recordFrame();
			HX_STACK_LINE(501)
			this->_debugger->vcr->updateRuntime(this->_step);
		}
		HX_STACK_LINE(506)
		this->update();
		HX_STACK_LINE(510)
		::org::flixel::FlxG_obj::mouse->wheel = (int)0;
		HX_STACK_LINE(513)
		if ((this->_debuggerUp)){
			HX_STACK_LINE(514)
			this->_debugger->perf->activeObjects(::org::flixel::FlxBasic_obj::_ACTIVECOUNT);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,step,(void))

Void FlxGame_obj::switchState( ){
{
		HX_STACK_PUSH("FlxGame::switchState","org/flixel/FlxGame.hx",369);
		HX_STACK_THIS(this);
		HX_STACK_LINE(372)
		::org::flixel::plugin::pxText::PxBitmapFont_obj::clearStorage();
		HX_STACK_LINE(373)
		::org::flixel::system::layer::Atlas_obj::clearAtlasCache();
		HX_STACK_LINE(374)
		::org::flixel::system::layer::TileSheetData_obj::clear();
		HX_STACK_LINE(376)
		::org::flixel::FlxG_obj::clearBitmapCache();
		HX_STACK_LINE(377)
		::org::flixel::FlxG_obj::resetCameras(null());
		HX_STACK_LINE(378)
		::org::flixel::FlxG_obj::resetInput();
		HX_STACK_LINE(379)
		::org::flixel::FlxG_obj::destroySounds(null());
		HX_STACK_LINE(383)
		if (((this->_debugger != null()))){
			HX_STACK_LINE(384)
			this->_debugger->watch->removeAll();
		}
		HX_STACK_LINE(390)
		::org::flixel::plugin::TimerManager timerManager = ::org::flixel::FlxTimer_obj::get_manager();		HX_STACK_VAR(timerManager,"timerManager");
		HX_STACK_LINE(391)
		if (((timerManager != null()))){
			HX_STACK_LINE(392)
			timerManager->clear();
		}
		HX_STACK_LINE(397)
		if (((this->_state != null()))){
			HX_STACK_LINE(398)
			this->_state->destroy();
		}
		HX_STACK_LINE(403)
		this->_state = this->_requestedState;
		HX_STACK_LINE(404)
		this->_state->create();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,switchState,(void))

Void FlxGame_obj::resetGame( ){
{
		HX_STACK_PUSH("FlxGame::resetGame","org/flixel/FlxGame.hx",345);
		HX_STACK_THIS(this);
		HX_STACK_LINE(346)
		this->_requestedState = ::Type_obj::createInstance(this->_iState,Dynamic( Array_obj<Dynamic>::__new()));
		HX_STACK_LINE(349)
		if ((::Std_obj::is(this->_requestedState,hx::ClassOf< ::org::flixel::FlxSubState >()))){
			HX_STACK_LINE(350)
			hx::Throw (HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
		}
		HX_STACK_LINE(356)
		this->_replayTimer = (int)0;
		HX_STACK_LINE(357)
		this->_replayCancelKeys = null();
		HX_STACK_LINE(360)
		::org::flixel::FlxG_obj::reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,resetGame,(void))

Void FlxGame_obj::onEnterFrame( ::native::events::Event FlashEvent){
{
		HX_STACK_PUSH("FlxGame::onEnterFrame","org/flixel/FlxGame.hx",286);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(287)
		::org::flixel::FlxGame_obj::_mark = ::native::Lib_obj::getTimer();
		HX_STACK_LINE(288)
		this->_elapsedMS = (::org::flixel::FlxGame_obj::_mark - this->_total);
		HX_STACK_LINE(289)
		this->_total = ::org::flixel::FlxGame_obj::_mark;
		HX_STACK_LINE(291)
		if ((this->_updateSoundTray)){
			HX_STACK_LINE(292)
			this->updateSoundTray(this->_elapsedMS);
		}
		HX_STACK_LINE(294)
		if ((!(this->_lostFocus))){
			HX_STACK_LINE(297)
			if (((bool((this->_debugger != null())) && bool(this->_debugger->vcr->paused)))){
				HX_STACK_LINE(298)
				if ((this->_debugger->vcr->stepRequested)){
					HX_STACK_LINE(301)
					this->_debugger->vcr->stepRequested = false;
					HX_STACK_LINE(302)
					this->step();
				}
			}
			else{
				HX_STACK_LINE(308)
				hx::AddEq(this->_accumulator,this->_elapsedMS);
				HX_STACK_LINE(309)
				if (((this->_accumulator > this->_maxAccumulation))){
					HX_STACK_LINE(310)
					this->_accumulator = this->_maxAccumulation;
				}
				HX_STACK_LINE(315)
				while(((this->_accumulator >= this->_step))){
					HX_STACK_LINE(317)
					this->step();
					HX_STACK_LINE(318)
					this->_accumulator = (this->_accumulator - this->_step);
				}
			}
			HX_STACK_LINE(324)
			::org::flixel::FlxBasic_obj::_VISIBLECOUNT = (int)0;
			HX_STACK_LINE(325)
			this->draw();
			HX_STACK_LINE(328)
			if ((this->_debuggerUp)){
				HX_STACK_LINE(330)
				this->_debugger->perf->flash(this->_elapsedMS);
				HX_STACK_LINE(331)
				this->_debugger->perf->visibleObjects(::org::flixel::FlxBasic_obj::_VISIBLECOUNT);
				HX_STACK_LINE(332)
				this->_debugger->perf->update();
				HX_STACK_LINE(333)
				this->_debugger->watch->update();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onEnterFrame,(void))

Void FlxGame_obj::onFocusLost( ::native::events::Event FlashEvent){
{
		HX_STACK_PUSH("FlxGame::onFocusLost","org/flixel/FlxGame.hx",272);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(273)
		this->_lostFocus = this->_focus->set_visible(true);
		HX_STACK_LINE(274)
		this->get_stage()->set_frameRate((int)10);
		HX_STACK_LINE(275)
		::org::flixel::FlxG_obj::pauseSounds();
		HX_STACK_LINE(276)
		::org::flixel::system::input::FlxInputs_obj::onFocusLost();
		HX_STACK_LINE(278)
		this->_state->onFocusLost();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onFocusLost,(void))

Void FlxGame_obj::onFocus( ::native::events::Event FlashEvent){
{
		HX_STACK_PUSH("FlxGame::onFocus","org/flixel/FlxGame.hx",258);
		HX_STACK_THIS(this);
		HX_STACK_ARG(FlashEvent,"FlashEvent");
		HX_STACK_LINE(259)
		this->_lostFocus = this->_focus->set_visible(false);
		HX_STACK_LINE(260)
		this->get_stage()->set_frameRate(this->_flashFramerate);
		HX_STACK_LINE(261)
		::org::flixel::FlxG_obj::resumeSounds();
		HX_STACK_LINE(262)
		::org::flixel::system::input::FlxInputs_obj::onFocus();
		HX_STACK_LINE(264)
		this->_state->onFocus();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onFocus,(void))

Void FlxGame_obj::showSoundTray( hx::Null< bool >  __o_Silent){
bool Silent = __o_Silent.Default(false);
	HX_STACK_PUSH("FlxGame::showSoundTray","org/flixel/FlxGame.hx",232);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Silent,"Silent");
{
		HX_STACK_LINE(233)
		if ((!(Silent))){
			HX_STACK_LINE(234)
			::org::flixel::FlxG_obj::play(::org::flixel::FlxAssets_obj::sndBeep,null(),null(),null());
		}
		HX_STACK_LINE(237)
		this->_soundTrayTimer = (int)1;
		HX_STACK_LINE(238)
		this->_soundTray->set_y((int)0);
		HX_STACK_LINE(239)
		this->_soundTray->set_visible(true);
		HX_STACK_LINE(240)
		this->_updateSoundTray = true;
		HX_STACK_LINE(241)
		int globalVolume = ::Math_obj::round((::org::flixel::FlxG_obj::volume * (int)10));		HX_STACK_VAR(globalVolume,"globalVolume");
		HX_STACK_LINE(242)
		if ((::org::flixel::FlxG_obj::mute)){
			HX_STACK_LINE(243)
			globalVolume = (int)0;
		}
		HX_STACK_LINE(246)
		{
			HX_STACK_LINE(246)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->_soundTrayBars->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(246)
			while(((_g1 < _g))){
				HX_STACK_LINE(246)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(248)
				if (((i < globalVolume))){
					HX_STACK_LINE(248)
					this->_soundTrayBars->__get(i)->set_alpha((int)1);
				}
				else{
					HX_STACK_LINE(249)
					this->_soundTrayBars->__get(i)->set_alpha(0.5);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,showSoundTray,(void))

int FlxGame_obj::_mark;


FlxGame_obj::FlxGame_obj()
{
}

void FlxGame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxGame);
	HX_MARK_MEMBER_NAME(debugger,"debugger");
	HX_MARK_MEMBER_NAME(_replayCallback,"_replayCallback");
	HX_MARK_MEMBER_NAME(_replayTimer,"_replayTimer");
	HX_MARK_MEMBER_NAME(_replayCancelKeys,"_replayCancelKeys");
	HX_MARK_MEMBER_NAME(_recording,"_recording");
	HX_MARK_MEMBER_NAME(_replaying,"_replaying");
	HX_MARK_MEMBER_NAME(_recordingRequested,"_recordingRequested");
	HX_MARK_MEMBER_NAME(_replayRequested,"_replayRequested");
	HX_MARK_MEMBER_NAME(_replay,"_replay");
	HX_MARK_MEMBER_NAME(_debuggerUp,"_debuggerUp");
	HX_MARK_MEMBER_NAME(_debugger,"_debugger");
	HX_MARK_MEMBER_NAME(_soundTrayBars,"_soundTrayBars");
	HX_MARK_MEMBER_NAME(_updateSoundTray,"_updateSoundTray");
	HX_MARK_MEMBER_NAME(_soundTrayTimer,"_soundTrayTimer");
	HX_MARK_MEMBER_NAME(_soundTray,"_soundTray");
	HX_MARK_MEMBER_NAME(_focus,"_focus");
	HX_MARK_MEMBER_NAME(_requestedReset,"_requestedReset");
	HX_MARK_MEMBER_NAME(_requestedState,"_requestedState");
	HX_MARK_MEMBER_NAME(_maxAccumulation,"_maxAccumulation");
	HX_MARK_MEMBER_NAME(_flashFramerate,"_flashFramerate");
	HX_MARK_MEMBER_NAME(_stepSeconds,"_stepSeconds");
	HX_MARK_MEMBER_NAME(_step,"_step");
	HX_MARK_MEMBER_NAME(_elapsedMS,"_elapsedMS");
	HX_MARK_MEMBER_NAME(_lostFocus,"_lostFocus");
	HX_MARK_MEMBER_NAME(_accumulator,"_accumulator");
	HX_MARK_MEMBER_NAME(_total,"_total");
	HX_MARK_MEMBER_NAME(_iState,"_iState");
	HX_MARK_MEMBER_NAME(_inputContainer,"_inputContainer");
	HX_MARK_MEMBER_NAME(_state,"_state");
	HX_MARK_MEMBER_NAME(useSoundHotKeys,"useSoundHotKeys");
	HX_MARK_MEMBER_NAME(junk,"junk");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxGame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(debugger,"debugger");
	HX_VISIT_MEMBER_NAME(_replayCallback,"_replayCallback");
	HX_VISIT_MEMBER_NAME(_replayTimer,"_replayTimer");
	HX_VISIT_MEMBER_NAME(_replayCancelKeys,"_replayCancelKeys");
	HX_VISIT_MEMBER_NAME(_recording,"_recording");
	HX_VISIT_MEMBER_NAME(_replaying,"_replaying");
	HX_VISIT_MEMBER_NAME(_recordingRequested,"_recordingRequested");
	HX_VISIT_MEMBER_NAME(_replayRequested,"_replayRequested");
	HX_VISIT_MEMBER_NAME(_replay,"_replay");
	HX_VISIT_MEMBER_NAME(_debuggerUp,"_debuggerUp");
	HX_VISIT_MEMBER_NAME(_debugger,"_debugger");
	HX_VISIT_MEMBER_NAME(_soundTrayBars,"_soundTrayBars");
	HX_VISIT_MEMBER_NAME(_updateSoundTray,"_updateSoundTray");
	HX_VISIT_MEMBER_NAME(_soundTrayTimer,"_soundTrayTimer");
	HX_VISIT_MEMBER_NAME(_soundTray,"_soundTray");
	HX_VISIT_MEMBER_NAME(_focus,"_focus");
	HX_VISIT_MEMBER_NAME(_requestedReset,"_requestedReset");
	HX_VISIT_MEMBER_NAME(_requestedState,"_requestedState");
	HX_VISIT_MEMBER_NAME(_maxAccumulation,"_maxAccumulation");
	HX_VISIT_MEMBER_NAME(_flashFramerate,"_flashFramerate");
	HX_VISIT_MEMBER_NAME(_stepSeconds,"_stepSeconds");
	HX_VISIT_MEMBER_NAME(_step,"_step");
	HX_VISIT_MEMBER_NAME(_elapsedMS,"_elapsedMS");
	HX_VISIT_MEMBER_NAME(_lostFocus,"_lostFocus");
	HX_VISIT_MEMBER_NAME(_accumulator,"_accumulator");
	HX_VISIT_MEMBER_NAME(_total,"_total");
	HX_VISIT_MEMBER_NAME(_iState,"_iState");
	HX_VISIT_MEMBER_NAME(_inputContainer,"_inputContainer");
	HX_VISIT_MEMBER_NAME(_state,"_state");
	HX_VISIT_MEMBER_NAME(useSoundHotKeys,"useSoundHotKeys");
	HX_VISIT_MEMBER_NAME(junk,"junk");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxGame_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		if (HX_FIELD_EQ(inName,"junk") ) { return junk; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mark") ) { return _mark; }
		if (HX_FIELD_EQ(inName,"_step") ) { return _step; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_focus") ) { return _focus; }
		if (HX_FIELD_EQ(inName,"_total") ) { return _total; }
		if (HX_FIELD_EQ(inName,"_state") ) { return _state; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"_replay") ) { return _replay; }
		if (HX_FIELD_EQ(inName,"_iState") ) { return _iState; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"debugger") ) { return inCallProp ? getDebugger() : debugger; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resetGame") ) { return resetGame_dyn(); }
		if (HX_FIELD_EQ(inName,"_debugger") ) { return _debugger; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_recording") ) { return _recording; }
		if (HX_FIELD_EQ(inName,"_replaying") ) { return _replaying; }
		if (HX_FIELD_EQ(inName,"_soundTray") ) { return _soundTray; }
		if (HX_FIELD_EQ(inName,"_elapsedMS") ) { return _elapsedMS; }
		if (HX_FIELD_EQ(inName,"_lostFocus") ) { return _lostFocus; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getDebugger") ) { return getDebugger_dyn(); }
		if (HX_FIELD_EQ(inName,"switchState") ) { return switchState_dyn(); }
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		if (HX_FIELD_EQ(inName,"_debuggerUp") ) { return _debuggerUp; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"_replayTimer") ) { return _replayTimer; }
		if (HX_FIELD_EQ(inName,"_stepSeconds") ) { return _stepSeconds; }
		if (HX_FIELD_EQ(inName,"_accumulator") ) { return _accumulator; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"showSoundTray") ) { return showSoundTray_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_soundTrayBars") ) { return _soundTrayBars; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"createSoundTray") ) { return createSoundTray_dyn(); }
		if (HX_FIELD_EQ(inName,"updateSoundTray") ) { return updateSoundTray_dyn(); }
		if (HX_FIELD_EQ(inName,"_replayCallback") ) { return _replayCallback; }
		if (HX_FIELD_EQ(inName,"_soundTrayTimer") ) { return _soundTrayTimer; }
		if (HX_FIELD_EQ(inName,"_requestedReset") ) { return _requestedReset; }
		if (HX_FIELD_EQ(inName,"_requestedState") ) { return _requestedState; }
		if (HX_FIELD_EQ(inName,"_flashFramerate") ) { return _flashFramerate; }
		if (HX_FIELD_EQ(inName,"_inputContainer") ) { return _inputContainer; }
		if (HX_FIELD_EQ(inName,"useSoundHotKeys") ) { return useSoundHotKeys; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_replayRequested") ) { return _replayRequested; }
		if (HX_FIELD_EQ(inName,"_updateSoundTray") ) { return _updateSoundTray; }
		if (HX_FIELD_EQ(inName,"_maxAccumulation") ) { return _maxAccumulation; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"createFocusScreen") ) { return createFocusScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"_replayCancelKeys") ) { return _replayCancelKeys; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_recordingRequested") ) { return _recordingRequested; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxGame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"junk") ) { junk=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mark") ) { _mark=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_step") ) { _step=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_focus") ) { _focus=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_total") ) { _total=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_state") ) { _state=inValue.Cast< ::org::flixel::FlxState >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_replay") ) { _replay=inValue.Cast< ::org::flixel::system::FlxReplay >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_iState") ) { _iState=inValue.Cast< ::Class >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"debugger") ) { debugger=inValue.Cast< ::org::flixel::system::FlxDebugger >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_debugger") ) { _debugger=inValue.Cast< ::org::flixel::system::FlxDebugger >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_recording") ) { _recording=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_replaying") ) { _replaying=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_soundTray") ) { _soundTray=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_elapsedMS") ) { _elapsedMS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lostFocus") ) { _lostFocus=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_debuggerUp") ) { _debuggerUp=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_replayTimer") ) { _replayTimer=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stepSeconds") ) { _stepSeconds=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_accumulator") ) { _accumulator=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_soundTrayBars") ) { _soundTrayBars=inValue.Cast< Array< ::native::display::Bitmap > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_replayCallback") ) { _replayCallback=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_soundTrayTimer") ) { _soundTrayTimer=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_requestedReset") ) { _requestedReset=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_requestedState") ) { _requestedState=inValue.Cast< ::org::flixel::FlxState >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashFramerate") ) { _flashFramerate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_inputContainer") ) { _inputContainer=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"useSoundHotKeys") ) { useSoundHotKeys=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_replayRequested") ) { _replayRequested=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_updateSoundTray") ) { _updateSoundTray=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxAccumulation") ) { _maxAccumulation=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_replayCancelKeys") ) { _replayCancelKeys=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_recordingRequested") ) { _recordingRequested=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxGame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("debugger"));
	outFields->push(HX_CSTRING("_replayTimer"));
	outFields->push(HX_CSTRING("_replayCancelKeys"));
	outFields->push(HX_CSTRING("_recording"));
	outFields->push(HX_CSTRING("_replaying"));
	outFields->push(HX_CSTRING("_recordingRequested"));
	outFields->push(HX_CSTRING("_replayRequested"));
	outFields->push(HX_CSTRING("_replay"));
	outFields->push(HX_CSTRING("_debuggerUp"));
	outFields->push(HX_CSTRING("_debugger"));
	outFields->push(HX_CSTRING("_soundTrayBars"));
	outFields->push(HX_CSTRING("_updateSoundTray"));
	outFields->push(HX_CSTRING("_soundTrayTimer"));
	outFields->push(HX_CSTRING("_soundTray"));
	outFields->push(HX_CSTRING("_focus"));
	outFields->push(HX_CSTRING("_requestedReset"));
	outFields->push(HX_CSTRING("_requestedState"));
	outFields->push(HX_CSTRING("_maxAccumulation"));
	outFields->push(HX_CSTRING("_flashFramerate"));
	outFields->push(HX_CSTRING("_stepSeconds"));
	outFields->push(HX_CSTRING("_step"));
	outFields->push(HX_CSTRING("_elapsedMS"));
	outFields->push(HX_CSTRING("_lostFocus"));
	outFields->push(HX_CSTRING("_accumulator"));
	outFields->push(HX_CSTRING("_total"));
	outFields->push(HX_CSTRING("_iState"));
	outFields->push(HX_CSTRING("_inputContainer"));
	outFields->push(HX_CSTRING("_state"));
	outFields->push(HX_CSTRING("useSoundHotKeys"));
	outFields->push(HX_CSTRING("junk"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_mark"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getDebugger"),
	HX_CSTRING("debugger"),
	HX_CSTRING("createFocusScreen"),
	HX_CSTRING("createSoundTray"),
	HX_CSTRING("create"),
	HX_CSTRING("draw"),
	HX_CSTRING("update"),
	HX_CSTRING("updateSoundTray"),
	HX_CSTRING("step"),
	HX_CSTRING("switchState"),
	HX_CSTRING("resetGame"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("showSoundTray"),
	HX_CSTRING("_replayCallback"),
	HX_CSTRING("_replayTimer"),
	HX_CSTRING("_replayCancelKeys"),
	HX_CSTRING("_recording"),
	HX_CSTRING("_replaying"),
	HX_CSTRING("_recordingRequested"),
	HX_CSTRING("_replayRequested"),
	HX_CSTRING("_replay"),
	HX_CSTRING("_debuggerUp"),
	HX_CSTRING("_debugger"),
	HX_CSTRING("_soundTrayBars"),
	HX_CSTRING("_updateSoundTray"),
	HX_CSTRING("_soundTrayTimer"),
	HX_CSTRING("_soundTray"),
	HX_CSTRING("_focus"),
	HX_CSTRING("_requestedReset"),
	HX_CSTRING("_requestedState"),
	HX_CSTRING("_maxAccumulation"),
	HX_CSTRING("_flashFramerate"),
	HX_CSTRING("_stepSeconds"),
	HX_CSTRING("_step"),
	HX_CSTRING("_elapsedMS"),
	HX_CSTRING("_lostFocus"),
	HX_CSTRING("_accumulator"),
	HX_CSTRING("_total"),
	HX_CSTRING("_iState"),
	HX_CSTRING("_inputContainer"),
	HX_CSTRING("_state"),
	HX_CSTRING("useSoundHotKeys"),
	HX_CSTRING("junk"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxGame_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxGame_obj::_mark,"_mark");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxGame_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxGame_obj::_mark,"_mark");
};

Class FlxGame_obj::__mClass;

void FlxGame_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxGame"), hx::TCanCast< FlxGame_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxGame_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
