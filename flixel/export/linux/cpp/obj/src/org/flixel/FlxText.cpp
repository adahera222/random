#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_BlendMode
#include <native/display/BlendMode.h>
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
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_filters_BitmapFilter
#include <native/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
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
#ifndef INCLUDED_native_text_TextFormatAlign
#include <native/text/TextFormatAlign.h>
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
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_FlxSpriteFrames
#include <org/flixel/system/layer/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Node
#include <org/flixel/system/layer/Node.h>
#endif
namespace org{
namespace flixel{

Void FlxText_obj::__construct(Float X,Float Y,int Width,::String Text,hx::Null< int >  __o_size,hx::Null< bool >  __o_EmbeddedFont,hx::Null< bool >  __o_IsStatic)
{
HX_STACK_PUSH("FlxText::new","org/flixel/FlxText.hx",76);
int size = __o_size.Default(8);
bool EmbeddedFont = __o_EmbeddedFont.Default(true);
bool IsStatic = __o_IsStatic.Default(false);
{
	HX_STACK_LINE(77)
	super::__construct(X,Y,null());
	HX_STACK_LINE(79)
	this->_isStatic = false;
	HX_STACK_LINE(81)
	::String key = ::org::flixel::FlxG_obj::getUniqueBitmapKey(HX_CSTRING("text"));		HX_STACK_VAR(key,"key");
	HX_STACK_LINE(82)
	this->makeGraphic(Width,(int)1,(int)0,false,key);
	HX_STACK_LINE(84)
	if (((Text == null()))){
		HX_STACK_LINE(85)
		Text = HX_CSTRING("");
	}
	HX_STACK_LINE(88)
	this->_textField = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(89)
	this->_textField->set_width(Width);
	HX_STACK_LINE(90)
	this->_textField->set_selectable(false);
	HX_STACK_LINE(91)
	this->_textField->set_multiline(true);
	HX_STACK_LINE(92)
	this->_textField->set_wordWrap(true);
	HX_STACK_LINE(93)
	this->_format = ::native::text::TextFormat_obj::__new(::nme::installer::Assets_obj::getFont(::org::flixel::FlxAssets_obj::defaultFont)->fontName,size,(int)16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(94)
	this->_formatAdjusted = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(95)
	this->_textField->set_defaultTextFormat(this->_format);
	HX_STACK_LINE(96)
	this->_textField->set_text(Text);
	HX_STACK_LINE(97)
	this->_textField->set_embedFonts(EmbeddedFont);
	HX_STACK_LINE(101)
	if (((Text.length <= (int)0))){
		HX_STACK_LINE(102)
		this->_textField->set_height((int)1);
	}
	else{
		HX_STACK_LINE(106)
		this->_textField->set_height((int)10);
	}
	HX_STACK_LINE(110)
	this->_regen = true;
	HX_STACK_LINE(111)
	this->_shadow = (int)0;
	HX_STACK_LINE(112)
	this->_useShadow = false;
	HX_STACK_LINE(113)
	this->allowCollisions = (int)0;
	HX_STACK_LINE(114)
	this->moves = false;
	HX_STACK_LINE(118)
	if (((Text != HX_CSTRING("")))){
		HX_STACK_LINE(119)
		this->calcFrame(true);
	}
	HX_STACK_LINE(124)
	this->_isStatic = IsStatic;
}
;
	return null();
}

FlxText_obj::~FlxText_obj() { }

Dynamic FlxText_obj::__CreateEmpty() { return  new FlxText_obj; }
hx::ObjectPtr< FlxText_obj > FlxText_obj::__new(Float X,Float Y,int Width,::String Text,hx::Null< int >  __o_size,hx::Null< bool >  __o_EmbeddedFont,hx::Null< bool >  __o_IsStatic)
{  hx::ObjectPtr< FlxText_obj > result = new FlxText_obj();
	result->__construct(X,Y,Width,Text,__o_size,__o_EmbeddedFont,__o_IsStatic);
	return result;}

Dynamic FlxText_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxText_obj > result = new FlxText_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void FlxText_obj::updateFrameData( ){
{
		HX_STACK_PUSH("FlxText::updateFrameData","org/flixel/FlxText.hx",639);
		HX_STACK_THIS(this);
		HX_STACK_LINE(639)
		if (((bool((bool((this->_node != null())) && bool((this->frameWidth >= (int)1)))) && bool((this->frameHeight >= (int)1))))){
			HX_STACK_LINE(643)
			this->_framesData = this->_node->addSpriteFramesData(::Std_obj::_int(this->width),::Std_obj::_int(this->height),null(),null(),null(),null(),null(),null(),null());
			HX_STACK_LINE(644)
			this->_frameID = this->_framesData->frameIDs->__get((int)0);
		}
	}
return null();
}


Void FlxText_obj::updateAtlasInfo( hx::Null< bool >  __o_updateAtlas){
bool updateAtlas = __o_updateAtlas.Default(false);
	HX_STACK_PUSH("FlxText::updateAtlasInfo","org/flixel/FlxText.hx",623);
	HX_STACK_THIS(this);
	HX_STACK_ARG(updateAtlas,"updateAtlas");
{
		HX_STACK_LINE(625)
		this->_atlas = ::org::flixel::FlxG_obj::get_state()->getAtlasFor(this->_bitmapDataKey);
		HX_STACK_LINE(626)
		::native::display::BitmapData cachedBmd = ::org::flixel::FlxG_obj::_cache->get(this->_bitmapDataKey);		HX_STACK_VAR(cachedBmd,"cachedBmd");
		HX_STACK_LINE(627)
		if (((cachedBmd != this->_pixels))){
			HX_STACK_LINE(629)
			cachedBmd->dispose();
			HX_STACK_LINE(630)
			::org::flixel::FlxG_obj::_cache->set(this->_bitmapDataKey,this->_pixels);
			HX_STACK_LINE(631)
			this->_atlas->clearAndFillWith(this->_pixels);
		}
		HX_STACK_LINE(633)
		this->_node = this->_atlas->getNodeByKey(this->_bitmapDataKey);
		HX_STACK_LINE(634)
		this->updateFrameData();
	}
return null();
}


::org::flixel::system::layer::Atlas FlxText_obj::set_atlas( ::org::flixel::system::layer::Atlas value){
	HX_STACK_PUSH("FlxText::set_atlas","org/flixel/FlxText.hx",612);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(613)
	if ((!(this->_isStatic))){
		HX_STACK_LINE(614)
		return value;
	}
	HX_STACK_LINE(618)
	return this->super::set_atlas(value);
}


::String FlxText_obj::convertTextAlignmentFromString( ::String strAlign){
	HX_STACK_PUSH("FlxText::convertTextAlignmentFromString","org/flixel/FlxText.hx",602);
	HX_STACK_THIS(this);
	HX_STACK_ARG(strAlign,"strAlign");
	HX_STACK_LINE(602)
	return strAlign;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,convertTextAlignmentFromString,return )

::native::text::TextFormat FlxText_obj::dtfCopy( ){
	HX_STACK_PUSH("FlxText::dtfCopy","org/flixel/FlxText.hx",572);
	HX_STACK_THIS(this);
	HX_STACK_LINE(573)
	::native::text::TextFormat defaultTextFormat = this->_textField->get_defaultTextFormat();		HX_STACK_VAR(defaultTextFormat,"defaultTextFormat");
	HX_STACK_LINE(574)
	return ::native::text::TextFormat_obj::__new(defaultTextFormat->font,defaultTextFormat->size,defaultTextFormat->color,defaultTextFormat->bold,defaultTextFormat->italic,defaultTextFormat->underline,defaultTextFormat->url,defaultTextFormat->target,defaultTextFormat->align,null(),null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,dtfCopy,return )

Void FlxText_obj::setClipping( int width,int height){
{
		HX_STACK_PUSH("FlxText::setClipping","org/flixel/FlxText.hx",564);
		HX_STACK_THIS(this);
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


Void FlxText_obj::addFilter( ::native::filters::BitmapFilter filter,::org::flixel::FlxPoint updateSize,hx::Null< bool >  __o_permanent){
bool permanent = __o_permanent.Default(false);
	HX_STACK_PUSH("FlxText::addFilter","org/flixel/FlxText.hx",553);
	HX_STACK_THIS(this);
	HX_STACK_ARG(filter,"filter");
	HX_STACK_ARG(updateSize,"updateSize");
	HX_STACK_ARG(permanent,"permanent");
{
		HX_STACK_LINE(553)
		this->super::addFilter(filter,null(),false);
	}
return null();
}


Void FlxText_obj::calcFrame( hx::Null< bool >  __o_AreYouSure){
bool AreYouSure = __o_AreYouSure.Default(false);
	HX_STACK_PUSH("FlxText::calcFrame","org/flixel/FlxText.hx",454);
	HX_STACK_THIS(this);
	HX_STACK_ARG(AreYouSure,"AreYouSure");
{
		HX_STACK_LINE(456)
		if ((AreYouSure)){
			HX_STACK_LINE(458)
			this->_regen = true;
			HX_STACK_LINE(460)
			if ((this->_regen)){
				HX_STACK_LINE(463)
				this->height = this->_textField->get_textHeight();
				HX_STACK_LINE(464)
				hx::AddEq(this->height,(int)4);
				HX_STACK_LINE(465)
				this->_pixels = ::native::display::BitmapData_obj::__new(::Std_obj::_int(this->width),::Std_obj::_int(this->height),true,(int)0,null());
				HX_STACK_LINE(466)
				this->frameHeight = ::Std_obj::_int(this->height);
				HX_STACK_LINE(467)
				this->_textField->set_height((this->height * 1.2));
				HX_STACK_LINE(468)
				this->_flashRect->x = (int)0;
				HX_STACK_LINE(469)
				this->_flashRect->y = (int)0;
				HX_STACK_LINE(470)
				this->_flashRect->width = this->width;
				HX_STACK_LINE(471)
				this->_flashRect->height = this->height;
				HX_STACK_LINE(472)
				this->_regen = false;
			}
			else{
				HX_STACK_LINE(475)
				this->_pixels->fillRect(this->_flashRect,(int)0);
			}
			HX_STACK_LINE(479)
			if (((bool((bool((this->_textField != null())) && bool((this->_textField->get_text() != null())))) && bool((this->_textField->get_text().length > (int)0))))){
				HX_STACK_LINE(482)
				this->_formatAdjusted->font = this->_format->font;
				HX_STACK_LINE(483)
				this->_formatAdjusted->size = this->_format->size;
				HX_STACK_LINE(484)
				this->_formatAdjusted->color = this->_format->color;
				HX_STACK_LINE(485)
				this->_formatAdjusted->align = this->_format->align;
				HX_STACK_LINE(486)
				this->_matrix->identity();
				HX_STACK_LINE(491)
				if (((bool((this->_format->align == ::native::text::TextFormatAlign_obj::CENTER)) && bool((this->_textField->get_numLines() == (int)1))))){
					HX_STACK_LINE(494)
					this->_formatAdjusted->align = ::native::text::TextFormatAlign_obj::LEFT;
					HX_STACK_LINE(495)
					this->_textField->setTextFormat(this->_formatAdjusted,null(),null());
					HX_STACK_LINE(499)
					this->_matrix->translate(::Math_obj::floor((Float(((this->width - this->_textField->get_textWidth()))) / Float((int)2))),(int)0);
				}
				HX_STACK_LINE(503)
				if ((this->_useShadow)){
					HX_STACK_LINE(505)
					this->_formatAdjusted->color = this->_shadow;
					HX_STACK_LINE(506)
					this->_textField->setTextFormat(this->_formatAdjusted,null(),null());
					HX_STACK_LINE(507)
					this->_matrix->translate((int)1,(int)1);
					HX_STACK_LINE(508)
					this->_pixels->draw(this->_textField,this->_matrix,this->_colorTransform,null(),null(),null());
					HX_STACK_LINE(509)
					this->_matrix->translate((int)-1,(int)-1);
					HX_STACK_LINE(510)
					this->_formatAdjusted->color = this->_format->color;
					HX_STACK_LINE(511)
					this->_textField->setTextFormat(this->_formatAdjusted,null(),null());
				}
				HX_STACK_LINE(514)
				this->_pixels->draw(this->_textField,this->_matrix,this->_colorTransform,null(),null(),null());
				HX_STACK_LINE(515)
				this->_textField->setTextFormat(this->_format,null(),null());
			}
			HX_STACK_LINE(518)
			this->updateAtlasInfo(null());
			HX_STACK_LINE(529)
			{
				HX_STACK_LINE(529)
				::org::flixel::FlxPoint _this = this->origin;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(529)
				_this->x = (this->frameWidth * 0.5);
				HX_STACK_LINE(529)
				_this->y = (this->frameHeight * 0.5);
				HX_STACK_LINE(529)
				_this;
			}
			HX_STACK_LINE(530)
			this->_halfWidth = this->origin->x;
			HX_STACK_LINE(531)
			this->_halfHeight = this->origin->y;
		}
		HX_STACK_LINE(535)
		this->dirty = false;
		HX_STACK_LINE(538)
		if (((this->filters != null()))){
			HX_STACK_LINE(540)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::native::filters::BitmapFilter > _g1 = this->filters;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(540)
			while(((_g < _g1->length))){
				HX_STACK_LINE(540)
				::native::filters::BitmapFilter filter = _g1->__get(_g);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(540)
				++(_g);
				HX_STACK_LINE(542)
				this->framePixels->applyFilter(this->framePixels,this->_flashRect,this->_flashPointZero,filter);
			}
		}
	}
return null();
}


bool FlxText_obj::set_isStatic( bool value){
	HX_STACK_PUSH("FlxText::set_isStatic","org/flixel/FlxText.hx",437);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(438)
	if ((this->_isStatic)){
		HX_STACK_LINE(439)
		return value;
	}
	HX_STACK_LINE(443)
	return this->_isStatic = value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_isStatic,return )

bool FlxText_obj::get_isStatic( ){
	HX_STACK_PUSH("FlxText::get_isStatic","org/flixel/FlxText.hx",432);
	HX_STACK_THIS(this);
	HX_STACK_LINE(432)
	return this->_isStatic;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_isStatic,return )

bool FlxText_obj::set_useShadow( bool value){
	HX_STACK_PUSH("FlxText::set_useShadow","org/flixel/FlxText.hx",405);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(406)
	if ((this->_isStatic)){
		HX_STACK_LINE(407)
		return value;
	}
	HX_STACK_LINE(411)
	if (((value != this->_useShadow))){
		HX_STACK_LINE(413)
		this->_useShadow = value;
		HX_STACK_LINE(417)
		this->calcFrame(true);
	}
	HX_STACK_LINE(420)
	return this->_useShadow;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_useShadow,return )

bool FlxText_obj::get_useShadow( ){
	HX_STACK_PUSH("FlxText::get_useShadow","org/flixel/FlxText.hx",400);
	HX_STACK_THIS(this);
	HX_STACK_LINE(400)
	return this->_useShadow;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_useShadow,return )

int FlxText_obj::set_shadow( int Color){
	HX_STACK_PUSH("FlxText::set_shadow","org/flixel/FlxText.hx",384);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_LINE(385)
	if ((this->_isStatic)){
		HX_STACK_LINE(386)
		return Color;
	}
	HX_STACK_LINE(390)
	this->_shadow = Color;
	HX_STACK_LINE(394)
	this->calcFrame(true);
	HX_STACK_LINE(396)
	return Color;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_shadow,return )

int FlxText_obj::get_shadow( ){
	HX_STACK_PUSH("FlxText::get_shadow","org/flixel/FlxText.hx",372);
	HX_STACK_THIS(this);
	HX_STACK_LINE(372)
	return this->_shadow;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_shadow,return )

::String FlxText_obj::set_alignment( ::String Alignment){
	HX_STACK_PUSH("FlxText::set_alignment","org/flixel/FlxText.hx",347);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Alignment,"Alignment");
	HX_STACK_LINE(348)
	if ((this->_isStatic)){
		HX_STACK_LINE(349)
		return Alignment;
	}
	HX_STACK_LINE(353)
	this->_format->align = this->convertTextAlignmentFromString(Alignment);
	HX_STACK_LINE(354)
	this->_textField->set_defaultTextFormat(this->_format);
	HX_STACK_LINE(355)
	this->_textField->setTextFormat(this->_format,null(),null());
	HX_STACK_LINE(359)
	this->calcFrame(true);
	HX_STACK_LINE(361)
	return Alignment;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_alignment,return )

::String FlxText_obj::get_alignment( ){
	HX_STACK_PUSH("FlxText::get_alignment","org/flixel/FlxText.hx",339);
	HX_STACK_THIS(this);
	HX_STACK_LINE(339)
	return hx::TCast< String >::cast(this->_format->align);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_alignment,return )

::String FlxText_obj::set_font( ::String Font){
	HX_STACK_PUSH("FlxText::set_font","org/flixel/FlxText.hx",315);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Font,"Font");
	HX_STACK_LINE(316)
	if ((this->_isStatic)){
		HX_STACK_LINE(317)
		return Font;
	}
	HX_STACK_LINE(321)
	this->_format->font = ::nme::installer::Assets_obj::getFont(Font)->fontName;
	HX_STACK_LINE(322)
	this->_textField->set_defaultTextFormat(this->_format);
	HX_STACK_LINE(323)
	this->_textField->setTextFormat(this->_format,null(),null());
	HX_STACK_LINE(324)
	this->_regen = true;
	HX_STACK_LINE(328)
	this->calcFrame(true);
	HX_STACK_LINE(330)
	return Font;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_font,return )

::String FlxText_obj::get_font( ){
	HX_STACK_PUSH("FlxText::get_font","org/flixel/FlxText.hx",307);
	HX_STACK_THIS(this);
	HX_STACK_LINE(307)
	return this->_format->font;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_font,return )

int FlxText_obj::set_color( int Color){
	HX_STACK_PUSH("FlxText::set_color","org/flixel/FlxText.hx",279);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_LINE(280)
	if ((this->_isStatic)){
		HX_STACK_LINE(281)
		return Color;
	}
	HX_STACK_LINE(288)
	this->_format->color = Color;
	HX_STACK_LINE(290)
	this->_textField->set_defaultTextFormat(this->_format);
	HX_STACK_LINE(291)
	this->_textField->setTextFormat(this->_format,null(),null());
	HX_STACK_LINE(292)
	this->_regen = true;
	HX_STACK_LINE(296)
	this->calcFrame(true);
	HX_STACK_LINE(298)
	return Color;
}


int FlxText_obj::get_color( ){
	HX_STACK_PUSH("FlxText::get_color","org/flixel/FlxText.hx",262);
	HX_STACK_THIS(this);
	HX_STACK_LINE(262)
	return this->_format->color;
}


Float FlxText_obj::set_size( Float Size){
	HX_STACK_PUSH("FlxText::set_size","org/flixel/FlxText.hx",234);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Size,"Size");
	HX_STACK_LINE(235)
	if ((this->_isStatic)){
		HX_STACK_LINE(236)
		return Size;
	}
	HX_STACK_LINE(240)
	this->_format->size = Size;
	HX_STACK_LINE(241)
	this->_textField->set_defaultTextFormat(this->_format);
	HX_STACK_LINE(242)
	this->_textField->setTextFormat(this->_format,null(),null());
	HX_STACK_LINE(243)
	this->_regen = true;
	HX_STACK_LINE(247)
	this->calcFrame(true);
	HX_STACK_LINE(249)
	return Size;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_size,return )

Float FlxText_obj::get_size( ){
	HX_STACK_PUSH("FlxText::get_size","org/flixel/FlxText.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_LINE(226)
	return this->_format->size;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_size,return )

::String FlxText_obj::set_text( ::String Text){
	HX_STACK_PUSH("FlxText::set_text","org/flixel/FlxText.hx",200);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Text,"Text");
	HX_STACK_LINE(201)
	if ((this->_isStatic)){
		HX_STACK_LINE(202)
		return Text;
	}
	HX_STACK_LINE(206)
	::String ot = this->_textField->get_text();		HX_STACK_VAR(ot,"ot");
	HX_STACK_LINE(207)
	this->_textField->set_text(Text);
	HX_STACK_LINE(208)
	if (((this->_textField->get_text() != ot))){
		HX_STACK_LINE(210)
		this->_regen = true;
		HX_STACK_LINE(214)
		this->calcFrame(true);
	}
	HX_STACK_LINE(217)
	return this->_textField->get_text();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_text,return )

::String FlxText_obj::get_text( ){
	HX_STACK_PUSH("FlxText::get_text","org/flixel/FlxText.hx",192);
	HX_STACK_THIS(this);
	HX_STACK_LINE(192)
	return this->_textField->get_text();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_text,return )

::org::flixel::FlxText FlxText_obj::setFormat( ::String Font,hx::Null< Float >  __o_Size,hx::Null< int >  __o_Color,::String Alignment,hx::Null< int >  __o_ShadowColor,hx::Null< bool >  __o_UseShadow){
Float Size = __o_Size.Default(8);
int Color = __o_Color.Default(16777215);
int ShadowColor = __o_ShadowColor.Default(0);
bool UseShadow = __o_UseShadow.Default(false);
	HX_STACK_PUSH("FlxText::setFormat","org/flixel/FlxText.hx",159);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Font,"Font");
	HX_STACK_ARG(Size,"Size");
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Alignment,"Alignment");
	HX_STACK_ARG(ShadowColor,"ShadowColor");
	HX_STACK_ARG(UseShadow,"UseShadow");
{
		HX_STACK_LINE(160)
		if ((this->_isStatic)){
			HX_STACK_LINE(161)
			return hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(165)
		if (((Font == null()))){
			HX_STACK_LINE(166)
			Font = ::org::flixel::FlxAssets_obj::defaultFont;
		}
		HX_STACK_LINE(169)
		this->_format->font = ::nme::installer::Assets_obj::getFont(Font)->fontName;
		HX_STACK_LINE(170)
		this->_format->size = Size;
		HX_STACK_LINE(171)
		this->_format->color = Color;
		HX_STACK_LINE(172)
		this->_format->align = this->convertTextAlignmentFromString(Alignment);
		HX_STACK_LINE(173)
		this->_textField->set_defaultTextFormat(this->_format);
		HX_STACK_LINE(174)
		this->_textField->setTextFormat(this->_format,null(),null());
		HX_STACK_LINE(175)
		this->_shadow = ShadowColor;
		HX_STACK_LINE(176)
		this->_useShadow = UseShadow;
		HX_STACK_LINE(177)
		this->_regen = true;
		HX_STACK_LINE(181)
		this->calcFrame(true);
		HX_STACK_LINE(183)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC6(FlxText_obj,setFormat,return )

Void FlxText_obj::destroy( ){
{
		HX_STACK_PUSH("FlxText::destroy","org/flixel/FlxText.hx",131);
		HX_STACK_THIS(this);
		HX_STACK_LINE(133)
		if (((this->_pixels != null()))){
			HX_STACK_LINE(134)
			this->_pixels->dispose();
		}
		HX_STACK_LINE(138)
		this->_textField = null();
		HX_STACK_LINE(139)
		this->_format = null();
		HX_STACK_LINE(140)
		this->_formatAdjusted = null();
		HX_STACK_LINE(141)
		this->super::destroy();
	}
return null();
}



FlxText_obj::FlxText_obj()
{
}

void FlxText_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxText);
	HX_MARK_MEMBER_NAME(isStatic,"isStatic");
	HX_MARK_MEMBER_NAME(alignment,"alignment");
	HX_MARK_MEMBER_NAME(font,"font");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(_isStatic,"_isStatic");
	HX_MARK_MEMBER_NAME(_useShadow,"_useShadow");
	HX_MARK_MEMBER_NAME(_shadow,"_shadow");
	HX_MARK_MEMBER_NAME(_regen,"_regen");
	HX_MARK_MEMBER_NAME(_formatAdjusted,"_formatAdjusted");
	HX_MARK_MEMBER_NAME(_format,"_format");
	HX_MARK_MEMBER_NAME(_textField,"_textField");
	HX_MARK_MEMBER_NAME(useShadow,"useShadow");
	HX_MARK_MEMBER_NAME(shadow,"shadow");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxText_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(isStatic,"isStatic");
	HX_VISIT_MEMBER_NAME(alignment,"alignment");
	HX_VISIT_MEMBER_NAME(font,"font");
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(text,"text");
	HX_VISIT_MEMBER_NAME(_isStatic,"_isStatic");
	HX_VISIT_MEMBER_NAME(_useShadow,"_useShadow");
	HX_VISIT_MEMBER_NAME(_shadow,"_shadow");
	HX_VISIT_MEMBER_NAME(_regen,"_regen");
	HX_VISIT_MEMBER_NAME(_formatAdjusted,"_formatAdjusted");
	HX_VISIT_MEMBER_NAME(_format,"_format");
	HX_VISIT_MEMBER_NAME(_textField,"_textField");
	HX_VISIT_MEMBER_NAME(useShadow,"useShadow");
	HX_VISIT_MEMBER_NAME(shadow,"shadow");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxText_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { return inCallProp ? get_font() : font; }
		if (HX_FIELD_EQ(inName,"size") ) { return inCallProp ? get_size() : size; }
		if (HX_FIELD_EQ(inName,"text") ) { return inCallProp ? get_text() : text; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_regen") ) { return _regen; }
		if (HX_FIELD_EQ(inName,"shadow") ) { return inCallProp ? get_shadow() : shadow; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dtfCopy") ) { return dtfCopy_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_shadow") ) { return _shadow; }
		if (HX_FIELD_EQ(inName,"_format") ) { return _format; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isStatic") ) { return inCallProp ? get_isStatic() : isStatic; }
		if (HX_FIELD_EQ(inName,"set_font") ) { return set_font_dyn(); }
		if (HX_FIELD_EQ(inName,"get_font") ) { return get_font_dyn(); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_text") ) { return set_text_dyn(); }
		if (HX_FIELD_EQ(inName,"get_text") ) { return get_text_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_atlas") ) { return set_atlas_dyn(); }
		if (HX_FIELD_EQ(inName,"addFilter") ) { return addFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"calcFrame") ) { return calcFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"alignment") ) { return inCallProp ? get_alignment() : alignment; }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"setFormat") ) { return setFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"_isStatic") ) { return _isStatic; }
		if (HX_FIELD_EQ(inName,"useShadow") ) { return inCallProp ? get_useShadow() : useShadow; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_shadow") ) { return set_shadow_dyn(); }
		if (HX_FIELD_EQ(inName,"get_shadow") ) { return get_shadow_dyn(); }
		if (HX_FIELD_EQ(inName,"_useShadow") ) { return _useShadow; }
		if (HX_FIELD_EQ(inName,"_textField") ) { return _textField; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setClipping") ) { return setClipping_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_isStatic") ) { return set_isStatic_dyn(); }
		if (HX_FIELD_EQ(inName,"get_isStatic") ) { return get_isStatic_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_useShadow") ) { return set_useShadow_dyn(); }
		if (HX_FIELD_EQ(inName,"get_useShadow") ) { return get_useShadow_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alignment") ) { return set_alignment_dyn(); }
		if (HX_FIELD_EQ(inName,"get_alignment") ) { return get_alignment_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAtlasInfo") ) { return updateAtlasInfo_dyn(); }
		if (HX_FIELD_EQ(inName,"_formatAdjusted") ) { return _formatAdjusted; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"convertTextAlignmentFromString") ) { return convertTextAlignmentFromString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxText_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { if (inCallProp) return set_font(inValue);font=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp) return set_size(inValue);size=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"text") ) { if (inCallProp) return set_text(inValue);text=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_regen") ) { _regen=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shadow") ) { if (inCallProp) return set_shadow(inValue);shadow=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_shadow") ) { _shadow=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_format") ) { _format=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isStatic") ) { if (inCallProp) return set_isStatic(inValue);isStatic=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alignment") ) { if (inCallProp) return set_alignment(inValue);alignment=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isStatic") ) { _isStatic=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"useShadow") ) { if (inCallProp) return set_useShadow(inValue);useShadow=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_useShadow") ) { _useShadow=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_textField") ) { _textField=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_formatAdjusted") ) { _formatAdjusted=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isStatic"));
	outFields->push(HX_CSTRING("alignment"));
	outFields->push(HX_CSTRING("font"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("text"));
	outFields->push(HX_CSTRING("_isStatic"));
	outFields->push(HX_CSTRING("_useShadow"));
	outFields->push(HX_CSTRING("_shadow"));
	outFields->push(HX_CSTRING("_regen"));
	outFields->push(HX_CSTRING("_formatAdjusted"));
	outFields->push(HX_CSTRING("_format"));
	outFields->push(HX_CSTRING("_textField"));
	outFields->push(HX_CSTRING("useShadow"));
	outFields->push(HX_CSTRING("shadow"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("updateAtlasInfo"),
	HX_CSTRING("set_atlas"),
	HX_CSTRING("convertTextAlignmentFromString"),
	HX_CSTRING("dtfCopy"),
	HX_CSTRING("setClipping"),
	HX_CSTRING("addFilter"),
	HX_CSTRING("calcFrame"),
	HX_CSTRING("set_isStatic"),
	HX_CSTRING("get_isStatic"),
	HX_CSTRING("isStatic"),
	HX_CSTRING("set_useShadow"),
	HX_CSTRING("get_useShadow"),
	HX_CSTRING("set_shadow"),
	HX_CSTRING("get_shadow"),
	HX_CSTRING("set_alignment"),
	HX_CSTRING("get_alignment"),
	HX_CSTRING("alignment"),
	HX_CSTRING("set_font"),
	HX_CSTRING("get_font"),
	HX_CSTRING("font"),
	HX_CSTRING("set_color"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_size"),
	HX_CSTRING("get_size"),
	HX_CSTRING("size"),
	HX_CSTRING("set_text"),
	HX_CSTRING("get_text"),
	HX_CSTRING("text"),
	HX_CSTRING("setFormat"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_isStatic"),
	HX_CSTRING("_useShadow"),
	HX_CSTRING("_shadow"),
	HX_CSTRING("_regen"),
	HX_CSTRING("_formatAdjusted"),
	HX_CSTRING("_format"),
	HX_CSTRING("_textField"),
	HX_CSTRING("useShadow"),
	HX_CSTRING("shadow"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxText_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxText_obj::__mClass,"__mClass");
};

Class FlxText_obj::__mClass;

void FlxText_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxText"), hx::TCanCast< FlxText_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxText_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
