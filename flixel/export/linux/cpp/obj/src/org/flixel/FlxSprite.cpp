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
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_BlendMode
#include <native/display/BlendMode.h>
#endif
#ifndef INCLUDED_native_display_CapsStyle
#include <native/display/CapsStyle.h>
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
#ifndef INCLUDED_native_display_JointStyle
#include <native/display/JointStyle.h>
#endif
#ifndef INCLUDED_native_display_LineScaleMode
#include <native/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
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
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSprite
#include <org/flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxAnim
#include <org/flixel/system/FlxAnim.h>
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
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_DrawStackItem
#include <org/flixel/system/layer/DrawStackItem.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_FlxSpriteFrames
#include <org/flixel/system/layer/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Node
#include <org/flixel/system/layer/Node.h>
#endif
namespace org{
namespace flixel{

Void FlxSprite_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,Dynamic SimpleGraphic)
{
HX_STACK_PUSH("FlxSprite::new","org/flixel/FlxSprite.hx",29);
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(97)
	this->_calculatedPixelsFacing = (int)16;
	HX_STACK_LINE(96)
	this->_calculatedPixelsIndex = (int)-1;
	HX_STACK_LINE(92)
	this->_blendInt = (int)0;
	HX_STACK_LINE(228)
	super::__construct(X,Y,null(),null());
	HX_STACK_LINE(230)
	this->_flashPoint = ::native::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(231)
	this->_flashRect = ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());
	HX_STACK_LINE(232)
	this->_flashRect2 = ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());
	HX_STACK_LINE(233)
	this->_flashPointZero = ::native::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(234)
	this->offset = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(235)
	this->origin = ::org::flixel::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(236)
	this->scale = ::org::flixel::FlxPoint_obj::__new(1.0,1.0);
	HX_STACK_LINE(240)
	this->_color = (int)16777215;
	HX_STACK_LINE(242)
	this->set_alpha(1.0);
	HX_STACK_LINE(246)
	this->_blend = null();
	HX_STACK_LINE(248)
	this->set_antialiasing(false);
	HX_STACK_LINE(249)
	this->cameras = null();
	HX_STACK_LINE(251)
	this->finished = false;
	HX_STACK_LINE(252)
	this->paused = true;
	HX_STACK_LINE(253)
	this->set_facing((int)16);
	HX_STACK_LINE(254)
	this->_animations = ::Hash_obj::__new();
	HX_STACK_LINE(255)
	this->_flipped = (int)0;
	HX_STACK_LINE(256)
	this->_curAnim = null();
	HX_STACK_LINE(257)
	this->_curFrame = (int)0;
	HX_STACK_LINE(258)
	this->_curIndex = (int)0;
	HX_STACK_LINE(259)
	this->_frameTimer = (int)0;
	HX_STACK_LINE(261)
	this->_matrix = ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(262)
	this->_callback = null();
	HX_STACK_LINE(265)
	this->_red = 1.0;
	HX_STACK_LINE(266)
	this->_green = 1.0;
	HX_STACK_LINE(267)
	this->_blue = 1.0;
	HX_STACK_LINE(269)
	this->_frameID = (int)0;
	HX_STACK_LINE(270)
	this->_additionalAngle = 0.0;
	HX_STACK_LINE(273)
	if (((SimpleGraphic == null()))){
		HX_STACK_LINE(274)
		SimpleGraphic = ::org::flixel::FlxAssets_obj::imgDefault;
	}
	HX_STACK_LINE(277)
	this->loadGraphic(SimpleGraphic,null(),null(),null(),null(),null(),null());
}
;
	return null();
}

FlxSprite_obj::~FlxSprite_obj() { }

Dynamic FlxSprite_obj::__CreateEmpty() { return  new FlxSprite_obj; }
hx::ObjectPtr< FlxSprite_obj > FlxSprite_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,Dynamic SimpleGraphic)
{  hx::ObjectPtr< FlxSprite_obj > result = new FlxSprite_obj();
	result->__construct(__o_X,__o_Y,SimpleGraphic);
	return result;}

Dynamic FlxSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxSprite_obj > result = new FlxSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool FlxSprite_obj::overlapsPoint( ::org::flixel::FlxPoint point,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxSprite::overlapsPoint","org/flixel/FlxSprite.hx",1864);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(1865)
		if (((bool((this->scale->x == (int)1)) && bool((this->scale->y == (int)1))))){
			HX_STACK_LINE(1866)
			return this->super::overlapsPoint(point,InScreenSpace,Camera);
		}
		HX_STACK_LINE(1870)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(1871)
			return (bool((bool((bool((point->x > (this->x - ((0.5 * this->width) * ((this->scale->x - (int)1)))))) && bool((point->x < ((this->x + this->width) + ((0.5 * this->width) * ((this->scale->x - (int)1)))))))) && bool((point->y > (this->y - ((0.5 * this->height) * ((this->scale->y - (int)1)))))))) && bool((point->y < ((this->y + this->height) + ((0.5 * this->height) * ((this->scale->y - (int)1)))))));
		}
		HX_STACK_LINE(1875)
		if (((Camera == null()))){
			HX_STACK_LINE(1876)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1879)
		Float X = (point->x - Camera->scroll->x);		HX_STACK_VAR(X,"X");
		HX_STACK_LINE(1880)
		Float Y = (point->y - Camera->scroll->y);		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(1881)
		{
			HX_STACK_LINE(1881)
			::org::flixel::FlxPoint point1 = this->_point;		HX_STACK_VAR(point1,"point1");
			::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
			HX_STACK_LINE(1881)
			if (((point1 == null()))){
				HX_STACK_LINE(1881)
				point1 = ::org::flixel::FlxPoint_obj::__new(null(),null());
			}
			HX_STACK_LINE(1881)
			if (((Camera1 == null()))){
				HX_STACK_LINE(1881)
				Camera1 = ::org::flixel::FlxG_obj::camera;
			}
			HX_STACK_LINE(1881)
			point1->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
			HX_STACK_LINE(1881)
			point1->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
			HX_STACK_LINE(1881)
			point1;
		}
		HX_STACK_LINE(1882)
		return (bool((bool((bool((X > (this->_point->x - ((0.5 * this->width) * ((this->scale->x - (int)1)))))) && bool((X < ((this->_point->x + this->width) + ((0.5 * this->width) * ((this->scale->x - (int)1)))))))) && bool((Y > (this->_point->y - ((0.5 * this->height) * ((this->scale->y - (int)1)))))))) && bool((Y < ((this->_point->y + this->height) + ((0.5 * this->height) * ((this->scale->y - (int)1)))))));
	}
}


Void FlxSprite_obj::updateFrameData( ){
{
		HX_STACK_PUSH("FlxSprite::updateFrameData","org/flixel/FlxSprite.hx",1846);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1846)
		if (((bool((bool((this->_node != null())) && bool((this->frameWidth >= (int)1)))) && bool((this->frameHeight >= (int)1))))){
			HX_STACK_LINE(1850)
			if (((this->frames > (int)1))){
				HX_STACK_LINE(1851)
				this->_framesData = this->_node->addSpriteFramesData(::Std_obj::_int(this->frameWidth),::Std_obj::_int(this->frameHeight),null(),(int)0,(int)0,(int)0,(int)0,(int)1,(int)1);
			}
			else{
				HX_STACK_LINE(1855)
				this->_framesData = this->_node->addSpriteFramesData(::Std_obj::_int(this->frameWidth),::Std_obj::_int(this->frameHeight),null(),null(),null(),null(),null(),null(),null());
			}
			HX_STACK_LINE(1858)
			this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
		}
	}
return null();
}


::native::display::BlendMode FlxSprite_obj::set_blend( ::native::display::BlendMode value){
	HX_STACK_PUSH("FlxSprite::set_blend","org/flixel/FlxSprite.hx",1827);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1828)
	{
		::native::display::BlendMode _switch_1 = (value);
		switch((_switch_1)->GetIndex()){
			case 7: {
				HX_STACK_LINE(1830)
				this->_blendInt = (int)65536;
			}
			;break;
			default: {
				HX_STACK_LINE(1832)
				this->_blendInt = (int)0;
			}
		}
	}
	HX_STACK_LINE(1836)
	this->_blend = value;
	HX_STACK_LINE(1837)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_blend,return )

::native::display::BlendMode FlxSprite_obj::get_blend( ){
	HX_STACK_PUSH("FlxSprite::get_blend","org/flixel/FlxSprite.hx",1822);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1822)
	return this->_blend;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_blend,return )

bool FlxSprite_obj::simpleRenderSprite( ){
	HX_STACK_PUSH("FlxSprite::simpleRenderSprite","org/flixel/FlxSprite.hx",1810);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1810)
	return (bool((bool(((bool((bool((this->angle == (int)0)) && bool((this->_additionalAngle == (int)0)))) || bool((this->bakedRotation > (int)0))))) && bool((this->scale->x == (int)1)))) && bool((this->scale->y == (int)1)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,simpleRenderSprite,return )

bool FlxSprite_obj::get_simpleRender( ){
	HX_STACK_PUSH("FlxSprite::get_simpleRender","org/flixel/FlxSprite.hx",1805);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1805)
	return (bool((bool(((bool((bool((this->angle == (int)0)) && bool((this->_additionalAngle == (int)0)))) || bool((this->bakedRotation > (int)0))))) && bool((this->scale->x == (int)1)))) && bool((this->scale->y == (int)1)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_simpleRender,return )

bool FlxSprite_obj::set_antialiasing( bool val){
	HX_STACK_PUSH("FlxSprite::set_antialiasing","org/flixel/FlxSprite.hx",1789);
	HX_STACK_THIS(this);
	HX_STACK_ARG(val,"val");
	HX_STACK_LINE(1790)
	this->antialiasing = val;
	HX_STACK_LINE(1791)
	return val;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_antialiasing,return )

Void FlxSprite_obj::removeAllFilters( ){
{
		HX_STACK_PUSH("FlxSprite::removeAllFilters","org/flixel/FlxSprite.hx",1761);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1762)
		if (((this->filters == null()))){
			HX_STACK_LINE(1762)
			return null();
		}
		HX_STACK_LINE(1764)
		while(((this->filters->length != (int)0))){
			HX_STACK_LINE(1765)
			this->filters->pop();
		}
		HX_STACK_LINE(1769)
		this->drawFrame(true);
		HX_STACK_LINE(1772)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(1775)
		this->updateAtlasInfo(true);
		HX_STACK_LINE(1777)
		this->filters = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,removeAllFilters,(void))

Void FlxSprite_obj::removeFilter( ::native::filters::BitmapFilter filter){
{
		HX_STACK_PUSH("FlxSprite::removeFilter","org/flixel/FlxSprite.hx",1741);
		HX_STACK_THIS(this);
		HX_STACK_ARG(filter,"filter");
		HX_STACK_LINE(1742)
		if (((bool((this->filters == null())) || bool((filter == null()))))){
			HX_STACK_LINE(1743)
			return null();
		}
		HX_STACK_LINE(1747)
		this->filters->remove(filter);
		HX_STACK_LINE(1749)
		this->drawFrame(true);
		HX_STACK_LINE(1751)
		if (((this->filters->length == (int)0))){
			HX_STACK_LINE(1752)
			this->filters = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,removeFilter,(void))

Void FlxSprite_obj::setClipping( int width,int height){
{
		HX_STACK_PUSH("FlxSprite::setClipping","org/flixel/FlxSprite.hx",1718);
		HX_STACK_THIS(this);
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(1719)
		::org::flixel::FlxSprite tempSpr = ::org::flixel::FlxSprite_obj::__new((int)0,(int)0,this->_pixels);		HX_STACK_VAR(tempSpr,"tempSpr");
		HX_STACK_LINE(1720)
		::org::flixel::FlxPoint diffSize = ::org::flixel::FlxPoint_obj::__new((width - this->frameWidth),(height - this->frameHeight));		HX_STACK_VAR(diffSize,"diffSize");
		HX_STACK_LINE(1724)
		this->makeGraphic(width,height,(int)0,null(),null());
		HX_STACK_LINE(1727)
		this->stamp(tempSpr,::Std_obj::_int((Float(diffSize->x) / Float((int)2))),::Std_obj::_int((Float(diffSize->y) / Float((int)2))));
		HX_STACK_LINE(1729)
		hx::SubEq(this->x,(diffSize->x * 0.5));
		HX_STACK_LINE(1730)
		hx::SubEq(this->y,(diffSize->y * 0.5));
		HX_STACK_LINE(1732)
		tempSpr->destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxSprite_obj,setClipping,(void))

Void FlxSprite_obj::addFilter( ::native::filters::BitmapFilter filter,::org::flixel::FlxPoint updateSize,hx::Null< bool >  __o_permanent){
bool permanent = __o_permanent.Default(false);
	HX_STACK_PUSH("FlxSprite::addFilter","org/flixel/FlxSprite.hx",1680);
	HX_STACK_THIS(this);
	HX_STACK_ARG(filter,"filter");
	HX_STACK_ARG(updateSize,"updateSize");
	HX_STACK_ARG(permanent,"permanent");
{
		HX_STACK_LINE(1683)
		if (((bool((updateSize != null())) && bool((permanent == false))))){
			HX_STACK_LINE(1684)
			this->setClipping((this->frameWidth + ::Std_obj::_int(updateSize->x)),(this->frameHeight + ::Std_obj::_int(updateSize->y)));
		}
		HX_STACK_LINE(1688)
		if ((!(permanent))){
			HX_STACK_LINE(1690)
			if (((this->filters == null()))){
				HX_STACK_LINE(1691)
				this->filters = Array_obj< ::native::filters::BitmapFilter >::__new();
			}
			HX_STACK_LINE(1694)
			this->filters->push(filter);
		}
		else{
			HX_STACK_LINE(1697)
			this->_pixels->applyFilter(this->_pixels,this->_flashRect,this->_flashPointZero,filter);
		}
		HX_STACK_LINE(1702)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(1705)
		this->updateAtlasInfo(true);
		HX_STACK_LINE(1707)
		this->drawFrame(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,addFilter,(void))

Void FlxSprite_obj::calcFrame( hx::Null< bool >  __o_AreYouSure){
bool AreYouSure = __o_AreYouSure.Default(false);
	HX_STACK_PUSH("FlxSprite::calcFrame","org/flixel/FlxSprite.hx",1578);
	HX_STACK_THIS(this);
	HX_STACK_ARG(AreYouSure,"AreYouSure");
{
		HX_STACK_LINE(1580)
		if ((AreYouSure)){
			HX_STACK_LINE(1582)
			if (((bool((this->_calculatedPixelsIndex == this->_curIndex)) && bool((this->_calculatedPixelsFacing == this->facing))))){
				HX_STACK_LINE(1583)
				return null();
			}
			HX_STACK_LINE(1586)
			if (((bool((bool((this->framePixels == null())) || bool((this->framePixels->get_width() != this->width)))) || bool((this->framePixels->get_height() != this->height))))){
				HX_STACK_LINE(1587)
				this->framePixels = ::native::display::BitmapData_obj::__new(::Std_obj::_int(this->frameWidth),::Std_obj::_int(this->frameHeight),null(),null(),null());
			}
			HX_STACK_LINE(1595)
			int indexX = (this->_curIndex * ((this->frameWidth + (int)1)));		HX_STACK_VAR(indexX,"indexX");
			HX_STACK_LINE(1596)
			this->_calculatedPixelsIndex = this->_curIndex;
			HX_STACK_LINE(1597)
			this->_calculatedPixelsFacing = this->facing;
			HX_STACK_LINE(1599)
			int indexY = (int)0;		HX_STACK_VAR(indexY,"indexY");
			HX_STACK_LINE(1605)
			int widthHelper = this->_pixels->get_width();		HX_STACK_VAR(widthHelper,"widthHelper");
			HX_STACK_LINE(1607)
			if (((indexX >= widthHelper))){
				HX_STACK_LINE(1612)
				indexY = (::Std_obj::_int((Float(indexX) / Float(widthHelper))) * ((this->frameHeight + (int)1)));
				HX_STACK_LINE(1614)
				hx::ModEq(indexX,widthHelper);
			}
			HX_STACK_LINE(1626)
			this->_flashRect->x = indexX;
			HX_STACK_LINE(1627)
			this->_flashRect->y = indexY;
			HX_STACK_LINE(1628)
			this->framePixels->copyPixels(this->_pixels,this->_flashRect,this->_flashPointZero,null(),null(),null());
			HX_STACK_LINE(1630)
			if (((bool((this->_flipped != (int)0)) && bool((this->facing == (int)1))))){
				HX_STACK_LINE(1632)
				::native::display::BitmapData temp = this->framePixels->clone();		HX_STACK_VAR(temp,"temp");
				HX_STACK_LINE(1633)
				this->_matrix->identity();
				HX_STACK_LINE(1634)
				this->_matrix->scale((int)-1,(int)1);
				HX_STACK_LINE(1635)
				this->_matrix->translate(temp->get_width(),(int)0);
				HX_STACK_LINE(1636)
				this->framePixels->fillRect(this->framePixels->get_rect(),(int)0);
				HX_STACK_LINE(1637)
				this->framePixels->draw(temp,this->_matrix,null(),null(),null(),null());
			}
			HX_STACK_LINE(1640)
			this->_flashRect->x = this->_flashRect->y = (int)0;
			HX_STACK_LINE(1641)
			if ((this->_useColorTransform)){
				HX_STACK_LINE(1642)
				this->framePixels->colorTransform(this->_flashRect,this->_colorTransform);
			}
		}
		HX_STACK_LINE(1649)
		if (((this->_callback_dyn() != null()))){
			HX_STACK_LINE(1650)
			this->_callback((  (((this->_curAnim != null()))) ? ::String(this->_curAnim->name) : ::String(null()) ),this->_curFrame,this->_curIndex);
		}
		HX_STACK_LINE(1654)
		this->dirty = false;
		HX_STACK_LINE(1657)
		if (((this->filters != null()))){
			HX_STACK_LINE(1659)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::native::filters::BitmapFilter > _g1 = this->filters;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1659)
			while(((_g < _g1->length))){
				HX_STACK_LINE(1659)
				::native::filters::BitmapFilter filter = _g1->__get(_g);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(1659)
				++(_g);
				HX_STACK_LINE(1661)
				this->framePixels->applyFilter(this->framePixels,this->_flashRect,this->_flashPointZero,filter);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,calcFrame,(void))

bool FlxSprite_obj::pixelsOverlapPoint( ::org::flixel::FlxPoint point,hx::Null< int >  __o_Mask,::org::flixel::FlxCamera Camera){
int Mask = __o_Mask.Default(255);
	HX_STACK_PUSH("FlxSprite::pixelsOverlapPoint","org/flixel/FlxSprite.hx",1517);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(Mask,"Mask");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(1518)
		if (((Camera == null()))){
			HX_STACK_LINE(1519)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1522)
		{
			HX_STACK_LINE(1522)
			::org::flixel::FlxPoint point1 = this->_point;		HX_STACK_VAR(point1,"point1");
			::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
			HX_STACK_LINE(1522)
			if (((point1 == null()))){
				HX_STACK_LINE(1522)
				point1 = ::org::flixel::FlxPoint_obj::__new(null(),null());
			}
			HX_STACK_LINE(1522)
			if (((Camera1 == null()))){
				HX_STACK_LINE(1522)
				Camera1 = ::org::flixel::FlxG_obj::camera;
			}
			HX_STACK_LINE(1522)
			point1->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
			HX_STACK_LINE(1522)
			point1->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
			HX_STACK_LINE(1522)
			point1;
		}
		HX_STACK_LINE(1523)
		this->_point->x = (this->_point->x - this->offset->x);
		HX_STACK_LINE(1524)
		this->_point->y = (this->_point->y - this->offset->y);
		HX_STACK_LINE(1525)
		this->_flashPoint->x = ((point->x - Camera->scroll->x) - this->_point->x);
		HX_STACK_LINE(1526)
		this->_flashPoint->y = ((point->y - Camera->scroll->y) - this->_point->y);
		HX_STACK_LINE(1531)
		if (((bool((bool((bool((this->_flashPoint->x < (int)0)) || bool((this->_flashPoint->x > this->frameWidth)))) || bool((this->_flashPoint->y < (int)0)))) || bool((this->_flashPoint->y > this->frameHeight))))){
			HX_STACK_LINE(1532)
			return false;
		}
		else{
			HX_STACK_LINE(1538)
			int indexX = (this->_curIndex * ((this->frameWidth + (int)1)));		HX_STACK_VAR(indexX,"indexX");
			HX_STACK_LINE(1539)
			int indexY = (int)0;		HX_STACK_VAR(indexY,"indexY");
			HX_STACK_LINE(1542)
			int widthHelper = (  (((this->_flipped != (int)0))) ? int(this->_flipped) : int(this->_pixels->get_width()) );		HX_STACK_VAR(widthHelper,"widthHelper");
			HX_STACK_LINE(1543)
			if (((indexX >= widthHelper))){
				HX_STACK_LINE(1545)
				indexY = (::Std_obj::_int((Float(indexX) / Float(widthHelper))) * ((this->frameHeight + (int)1)));
				HX_STACK_LINE(1546)
				hx::ModEq(indexX,widthHelper);
			}
			HX_STACK_LINE(1549)
			int pixelColor = (int)0;		HX_STACK_VAR(pixelColor,"pixelColor");
			HX_STACK_LINE(1551)
			if (((bool((this->_flipped != (int)0)) && bool((this->facing == (int)1))))){
				HX_STACK_LINE(1552)
				pixelColor = this->_pixels->getPixel32(::Std_obj::_int(((indexX + this->frameWidth) - this->_flashPoint->x)),::Std_obj::_int((indexY + this->_flashPoint->y)));
			}
			else{
				HX_STACK_LINE(1556)
				pixelColor = this->_pixels->getPixel32(::Std_obj::_int((indexX + this->_flashPoint->x)),::Std_obj::_int((indexY + this->_flashPoint->y)));
			}
			HX_STACK_LINE(1561)
			int pixelAlpha = (int((int(pixelColor) >> int((int)24))) & int((int)255));		HX_STACK_VAR(pixelAlpha,"pixelAlpha");
			HX_STACK_LINE(1565)
			return (pixelAlpha >= Mask);
		}
		HX_STACK_LINE(1531)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,pixelsOverlapPoint,return )

bool FlxSprite_obj::onScreenSprite( ::org::flixel::FlxCamera Camera){
	HX_STACK_PUSH("FlxSprite::onScreenSprite","org/flixel/FlxSprite.hx",1467);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_LINE(1468)
	if (((Camera == null()))){
		HX_STACK_LINE(1469)
		Camera = ::org::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(1472)
	{
		HX_STACK_LINE(1472)
		::org::flixel::FlxPoint point = this->_point;		HX_STACK_VAR(point,"point");
		::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
		HX_STACK_LINE(1472)
		if (((point == null()))){
			HX_STACK_LINE(1472)
			point = ::org::flixel::FlxPoint_obj::__new(null(),null());
		}
		HX_STACK_LINE(1472)
		if (((Camera1 == null()))){
			HX_STACK_LINE(1472)
			Camera1 = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1472)
		point->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
		HX_STACK_LINE(1472)
		point->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
		HX_STACK_LINE(1472)
		point;
	}
	HX_STACK_LINE(1473)
	this->_point->x = (this->_point->x - this->offset->x);
	HX_STACK_LINE(1474)
	this->_point->y = (this->_point->y - this->offset->y);
	HX_STACK_LINE(1476)
	bool result = false;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(1477)
	bool notRotated = (this->angle == 0.0);		HX_STACK_VAR(notRotated,"notRotated");
	HX_STACK_LINE(1479)
	notRotated = (bool(notRotated) && bool((this->_additionalAngle != 0.0)));
	HX_STACK_LINE(1481)
	if (((bool((bool(((bool(notRotated) || bool((this->bakedRotation > (int)0))))) && bool((this->scale->x == (int)1)))) && bool((this->scale->y == (int)1))))){
		HX_STACK_LINE(1482)
		result = (bool((bool((bool(((this->_point->x + this->frameWidth) > (int)0)) && bool((this->_point->x < Camera->width)))) && bool(((this->_point->y + this->frameHeight) > (int)0)))) && bool((this->_point->y < Camera->height)));
	}
	else{
		HX_STACK_LINE(1487)
		Float halfWidth = (0.5 * this->frameWidth);		HX_STACK_VAR(halfWidth,"halfWidth");
		HX_STACK_LINE(1488)
		Float halfHeight = (0.5 * this->frameHeight);		HX_STACK_VAR(halfHeight,"halfHeight");
		HX_STACK_LINE(1489)
		Float absScaleX = (  (((this->scale->x > (int)0))) ? Float(this->scale->x) : Float(-(this->scale->x)) );		HX_STACK_VAR(absScaleX,"absScaleX");
		HX_STACK_LINE(1490)
		Float absScaleY = (  (((this->scale->y > (int)0))) ? Float(this->scale->y) : Float(-(this->scale->y)) );		HX_STACK_VAR(absScaleY,"absScaleY");
		HX_STACK_LINE(1494)
		Float radius = (((  (((this->frameWidth >= this->frameHeight))) ? int(this->frameWidth) : int(this->frameHeight) )) * ((  (((absScaleX >= absScaleY))) ? Float(absScaleX) : Float(absScaleY) )));		HX_STACK_VAR(radius,"radius");
		HX_STACK_LINE(1496)
		hx::AddEq(this->_point->x,halfWidth);
		HX_STACK_LINE(1497)
		hx::AddEq(this->_point->y,halfHeight);
		HX_STACK_LINE(1498)
		result = (bool((bool((bool(((this->_point->x + radius) > (int)0)) && bool(((this->_point->x - radius) < Camera->width)))) && bool(((this->_point->y + radius) > (int)0)))) && bool(((this->_point->y - radius) < Camera->height)));
	}
	HX_STACK_LINE(1501)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,onScreenSprite,return )

bool FlxSprite_obj::onScreen( ::org::flixel::FlxCamera Camera){
	HX_STACK_PUSH("FlxSprite::onScreen","org/flixel/FlxSprite.hx",1462);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	struct _Function_1_1{
		inline static bool Block( ::org::flixel::FlxCamera &Camera,::org::flixel::FlxSprite_obj *__this){
			HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",1463);
			{
				HX_STACK_LINE(1463)
				::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
				HX_STACK_LINE(1463)
				if (((Camera1 == null()))){
					HX_STACK_LINE(1463)
					Camera1 = ::org::flixel::FlxG_obj::camera;
				}
				HX_STACK_LINE(1463)
				{
					HX_STACK_LINE(1463)
					::org::flixel::FlxPoint point = __this->_point;		HX_STACK_VAR(point,"point");
					::org::flixel::FlxCamera Camera2 = Camera1;		HX_STACK_VAR(Camera2,"Camera2");
					HX_STACK_LINE(1463)
					if (((point == null()))){
						HX_STACK_LINE(1463)
						point = ::org::flixel::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(1463)
					if (((Camera2 == null()))){
						HX_STACK_LINE(1463)
						Camera2 = ::org::flixel::FlxG_obj::camera;
					}
					HX_STACK_LINE(1463)
					point->x = (__this->x - (Camera2->scroll->x * __this->scrollFactor->x));
					HX_STACK_LINE(1463)
					point->y = (__this->y - (Camera2->scroll->y * __this->scrollFactor->y));
					HX_STACK_LINE(1463)
					point;
				}
				HX_STACK_LINE(1463)
				__this->_point->x = (__this->_point->x - __this->offset->x);
				HX_STACK_LINE(1463)
				__this->_point->y = (__this->_point->y - __this->offset->y);
				HX_STACK_LINE(1463)
				bool result = false;		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(1463)
				bool notRotated = (__this->angle == 0.0);		HX_STACK_VAR(notRotated,"notRotated");
				HX_STACK_LINE(1463)
				notRotated = (bool(notRotated) && bool((__this->_additionalAngle != 0.0)));
				HX_STACK_LINE(1463)
				if (((bool((bool(((bool(notRotated) || bool((__this->bakedRotation > (int)0))))) && bool((__this->scale->x == (int)1)))) && bool((__this->scale->y == (int)1))))){
					HX_STACK_LINE(1463)
					result = (bool((bool((bool(((__this->_point->x + __this->frameWidth) > (int)0)) && bool((__this->_point->x < Camera1->width)))) && bool(((__this->_point->y + __this->frameHeight) > (int)0)))) && bool((__this->_point->y < Camera1->height)));
				}
				else{
					HX_STACK_LINE(1463)
					Float halfWidth = (0.5 * __this->frameWidth);		HX_STACK_VAR(halfWidth,"halfWidth");
					HX_STACK_LINE(1463)
					Float halfHeight = (0.5 * __this->frameHeight);		HX_STACK_VAR(halfHeight,"halfHeight");
					HX_STACK_LINE(1463)
					Float absScaleX = (  (((__this->scale->x > (int)0))) ? Float(__this->scale->x) : Float(-(__this->scale->x)) );		HX_STACK_VAR(absScaleX,"absScaleX");
					HX_STACK_LINE(1463)
					Float absScaleY = (  (((__this->scale->y > (int)0))) ? Float(__this->scale->y) : Float(-(__this->scale->y)) );		HX_STACK_VAR(absScaleY,"absScaleY");
					HX_STACK_LINE(1463)
					Float radius = (((  (((__this->frameWidth >= __this->frameHeight))) ? int(__this->frameWidth) : int(__this->frameHeight) )) * ((  (((absScaleX >= absScaleY))) ? Float(absScaleX) : Float(absScaleY) )));		HX_STACK_VAR(radius,"radius");
					HX_STACK_LINE(1463)
					hx::AddEq(__this->_point->x,halfWidth);
					HX_STACK_LINE(1463)
					hx::AddEq(__this->_point->y,halfHeight);
					HX_STACK_LINE(1463)
					result = (bool((bool((bool(((__this->_point->x + radius) > (int)0)) && bool(((__this->_point->x - radius) < Camera1->width)))) && bool(((__this->_point->y + radius) > (int)0)))) && bool(((__this->_point->y - radius) < Camera1->height)));
				}
				HX_STACK_LINE(1463)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1462)
	return _Function_1_1::Block(Camera,this);
}


::String FlxSprite_obj::set_curAnim( ::String AnimName){
	HX_STACK_PUSH("FlxSprite::set_curAnim","org/flixel/FlxSprite.hx",1448);
	HX_STACK_THIS(this);
	HX_STACK_ARG(AnimName,"AnimName");
	HX_STACK_LINE(1449)
	this->play(AnimName,null());
	HX_STACK_LINE(1450)
	return AnimName;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_curAnim,return )

::String FlxSprite_obj::get_curAnim( ){
	HX_STACK_PUSH("FlxSprite::get_curAnim","org/flixel/FlxSprite.hx",1436);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1437)
	if (((bool((this->_curAnim != null())) && bool(!(this->finished))))){
		HX_STACK_LINE(1438)
		return this->_curAnim->name;
	}
	HX_STACK_LINE(1439)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_curAnim,return )

int FlxSprite_obj::set_frame( int Frame){
	HX_STACK_PUSH("FlxSprite::set_frame","org/flixel/FlxSprite.hx",1419);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Frame,"Frame");
	HX_STACK_LINE(1420)
	this->_curAnim = null();
	HX_STACK_LINE(1421)
	this->_curIndex = hx::Mod(Frame,this->frames);
	HX_STACK_LINE(1423)
	if (((this->_framesData != null()))){
		HX_STACK_LINE(1424)
		this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
	}
	HX_STACK_LINE(1428)
	this->dirty = true;
	HX_STACK_LINE(1429)
	return Frame;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_frame,return )

int FlxSprite_obj::get_frame( ){
	HX_STACK_PUSH("FlxSprite::get_frame","org/flixel/FlxSprite.hx",1407);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1407)
	return this->_curIndex;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_frame,return )

int FlxSprite_obj::set_color( int Color){
	HX_STACK_PUSH("FlxSprite::set_color","org/flixel/FlxSprite.hx",1314);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_LINE(1348)
	hx::AndEq(Color,(int)16777215);
	HX_STACK_LINE(1349)
	if (((this->_color == Color))){
		HX_STACK_LINE(1350)
		return this->_color;
	}
	HX_STACK_LINE(1353)
	this->_color = Color;
	HX_STACK_LINE(1354)
	if (((bool((this->alpha != (int)1)) || bool((this->_color != (int)16777215))))){
		HX_STACK_LINE(1356)
		if (((this->_colorTransform == null()))){
			HX_STACK_LINE(1357)
			this->_colorTransform = ::native::geom::ColorTransform_obj::__new((Float(((int(this->_color) >> int((int)16)))) / Float((int)255)),(Float(((int((int(this->_color) >> int((int)8))) & int((int)255)))) / Float((int)255)),(Float(((int(this->_color) & int((int)255)))) / Float((int)255)),this->alpha,null(),null(),null(),null());
		}
		else{
			HX_STACK_LINE(1362)
			this->_colorTransform->redMultiplier = (Float(((int(this->_color) >> int((int)16)))) / Float((int)255));
			HX_STACK_LINE(1363)
			this->_colorTransform->greenMultiplier = (Float(((int((int(this->_color) >> int((int)8))) & int((int)255)))) / Float((int)255));
			HX_STACK_LINE(1364)
			this->_colorTransform->blueMultiplier = (Float(((int(this->_color) & int((int)255)))) / Float((int)255));
			HX_STACK_LINE(1365)
			this->_colorTransform->alphaMultiplier = this->alpha;
		}
		HX_STACK_LINE(1367)
		this->_useColorTransform = true;
	}
	else{
		HX_STACK_LINE(1371)
		if (((this->_colorTransform != null()))){
			HX_STACK_LINE(1373)
			this->_colorTransform->redMultiplier = (int)1;
			HX_STACK_LINE(1374)
			this->_colorTransform->greenMultiplier = (int)1;
			HX_STACK_LINE(1375)
			this->_colorTransform->blueMultiplier = (int)1;
			HX_STACK_LINE(1376)
			this->_colorTransform->alphaMultiplier = (int)1;
		}
		HX_STACK_LINE(1378)
		this->_useColorTransform = false;
	}
	HX_STACK_LINE(1382)
	this->dirty = true;
	HX_STACK_LINE(1385)
	this->_red = (Float(((int(this->_color) >> int((int)16)))) / Float((int)255));
	HX_STACK_LINE(1386)
	this->_green = (Float(((int((int(this->_color) >> int((int)8))) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1387)
	this->_blue = (Float(((int(this->_color) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1394)
	return this->_color;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_color,return )

int FlxSprite_obj::get_color( ){
	HX_STACK_PUSH("FlxSprite::get_color","org/flixel/FlxSprite.hx",1302);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1302)
	return this->_color;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_color,return )

Float FlxSprite_obj::set_alpha( Float Alpha){
	HX_STACK_PUSH("FlxSprite::set_alpha","org/flixel/FlxSprite.hx",1245);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Alpha,"Alpha");
	HX_STACK_LINE(1246)
	if (((Alpha > (int)1))){
		HX_STACK_LINE(1247)
		Alpha = (int)1;
	}
	HX_STACK_LINE(1250)
	if (((Alpha < (int)0))){
		HX_STACK_LINE(1251)
		Alpha = (int)0;
	}
	HX_STACK_LINE(1254)
	if (((Alpha == this->alpha))){
		HX_STACK_LINE(1255)
		return this->alpha;
	}
	HX_STACK_LINE(1258)
	this->alpha = Alpha;
	HX_STACK_LINE(1289)
	return this->alpha;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_alpha,return )

int FlxSprite_obj::set_facing( int Direction){
	HX_STACK_PUSH("FlxSprite::set_facing","org/flixel/FlxSprite.hx",1227);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Direction,"Direction");
	HX_STACK_LINE(1228)
	if (((this->facing != Direction))){
		HX_STACK_LINE(1229)
		this->dirty = true;
	}
	HX_STACK_LINE(1232)
	this->facing = Direction;
	HX_STACK_LINE(1233)
	return Direction;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_facing,return )

::native::display::BitmapData FlxSprite_obj::set_pixels( ::native::display::BitmapData Pixels){
	HX_STACK_PUSH("FlxSprite::set_pixels","org/flixel/FlxSprite.hx",1204);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Pixels,"Pixels");
	HX_STACK_LINE(1205)
	this->_pixels = Pixels;
	HX_STACK_LINE(1206)
	this->width = this->frameWidth = this->_pixels->get_width();
	HX_STACK_LINE(1207)
	this->height = this->frameHeight = this->_pixels->get_height();
	HX_STACK_LINE(1208)
	this->resetHelpers();
	HX_STACK_LINE(1210)
	this->_bitmapDataKey = ::org::flixel::FlxG_obj::getCacheKeyFor(this->_pixels);
	HX_STACK_LINE(1211)
	if (((this->_bitmapDataKey == null()))){
		HX_STACK_LINE(1213)
		this->_bitmapDataKey = ::org::flixel::FlxG_obj::getUniqueBitmapKey(null());
		HX_STACK_LINE(1214)
		::org::flixel::FlxG_obj::addBitmap(Pixels,false,false,this->_bitmapDataKey,null(),null());
	}
	HX_STACK_LINE(1217)
	this->_calculatedPixelsIndex = (int)-1;
	HX_STACK_LINE(1219)
	this->updateAtlasInfo(true);
	HX_STACK_LINE(1220)
	return this->_pixels;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_pixels,return )

::native::display::BitmapData FlxSprite_obj::get_pixels( ){
	HX_STACK_PUSH("FlxSprite::get_pixels","org/flixel/FlxSprite.hx",1196);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1196)
	return this->_pixels;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_pixels,return )

Array< ::org::flixel::FlxPoint > FlxSprite_obj::replaceColor( int Color,int NewColor,hx::Null< bool >  __o_FetchPositions){
bool FetchPositions = __o_FetchPositions.Default(false);
	HX_STACK_PUSH("FlxSprite::replaceColor","org/flixel/FlxSprite.hx",1155);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(NewColor,"NewColor");
	HX_STACK_ARG(FetchPositions,"FetchPositions");
{
		HX_STACK_LINE(1156)
		Array< ::org::flixel::FlxPoint > positions = null();		HX_STACK_VAR(positions,"positions");
		HX_STACK_LINE(1157)
		if ((FetchPositions)){
			HX_STACK_LINE(1158)
			positions = Array_obj< ::org::flixel::FlxPoint >::__new();
		}
		HX_STACK_LINE(1162)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1163)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1164)
		int rows = this->_pixels->get_height();		HX_STACK_VAR(rows,"rows");
		HX_STACK_LINE(1165)
		int columns = this->_pixels->get_width();		HX_STACK_VAR(columns,"columns");
		HX_STACK_LINE(1166)
		while(((row < rows))){
			HX_STACK_LINE(1168)
			column = (int)0;
			HX_STACK_LINE(1169)
			while(((column < columns))){
				HX_STACK_LINE(1171)
				if (((this->_pixels->getPixel32(column,row) == Color))){
					HX_STACK_LINE(1173)
					this->_pixels->setPixel32(column,row,NewColor);
					HX_STACK_LINE(1174)
					if ((FetchPositions)){
						HX_STACK_LINE(1175)
						positions->push(::org::flixel::FlxPoint_obj::__new(column,row));
					}
					HX_STACK_LINE(1178)
					this->dirty = true;
				}
				HX_STACK_LINE(1180)
				(column)++;
			}
			HX_STACK_LINE(1182)
			(row)++;
		}
		HX_STACK_LINE(1185)
		this->updateAtlasInfo(true);
		HX_STACK_LINE(1186)
		return positions;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,replaceColor,return )

Void FlxSprite_obj::centerOffsets( hx::Null< bool >  __o_AdjustPosition){
bool AdjustPosition = __o_AdjustPosition.Default(false);
	HX_STACK_PUSH("FlxSprite::centerOffsets","org/flixel/FlxSprite.hx",1140);
	HX_STACK_THIS(this);
	HX_STACK_ARG(AdjustPosition,"AdjustPosition");
{
		HX_STACK_LINE(1141)
		this->offset->x = (((this->frameWidth - this->width)) * 0.5);
		HX_STACK_LINE(1142)
		this->offset->y = (((this->frameHeight - this->height)) * 0.5);
		HX_STACK_LINE(1143)
		if ((AdjustPosition)){
			HX_STACK_LINE(1145)
			hx::AddEq(this->x,this->offset->x);
			HX_STACK_LINE(1146)
			hx::AddEq(this->y,this->offset->y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,centerOffsets,(void))

Void FlxSprite_obj::setOriginToCorner( ){
{
		HX_STACK_PUSH("FlxSprite::setOriginToCorner","org/flixel/FlxSprite.hx",1131);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1131)
		this->origin->x = this->origin->y = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,setOriginToCorner,(void))

Void FlxSprite_obj::randomFrame( ){
{
		HX_STACK_PUSH("FlxSprite::randomFrame","org/flixel/FlxSprite.hx",1115);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1116)
		this->_curAnim = null();
		struct _Function_1_1{
			inline static Float Block( ){
				HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",1117);
				{
					HX_STACK_LINE(1117)
					::org::flixel::FlxG_obj::globalSeed = (Float(hx::Mod(((int)69621 * ::Std_obj::_int((::org::flixel::FlxG_obj::globalSeed * (int)2147483647))),(int)2147483647)) / Float((int)2147483647));
					HX_STACK_LINE(1117)
					if (((::org::flixel::FlxG_obj::globalSeed <= (int)0))){
						HX_STACK_LINE(1117)
						hx::AddEq(::org::flixel::FlxG_obj::globalSeed,(int)1);
					}
					HX_STACK_LINE(1117)
					return ::org::flixel::FlxG_obj::globalSeed;
				}
				return null();
			}
		};
		HX_STACK_LINE(1117)
		this->_curIndex = ::Std_obj::_int((_Function_1_1::Block() * ((Float(this->_pixels->get_width()) / Float(this->frameWidth)))));
		HX_STACK_LINE(1119)
		if (((this->_framesData != null()))){
			HX_STACK_LINE(1120)
			this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
		}
		HX_STACK_LINE(1124)
		this->dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,randomFrame,(void))

::org::flixel::system::FlxAnim FlxSprite_obj::getAnimation( ::String name){
	HX_STACK_PUSH("FlxSprite::getAnimation","org/flixel/FlxSprite.hx",1106);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(1106)
	return this->_animations->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,getAnimation,return )

Void FlxSprite_obj::play( ::String AnimName,hx::Null< bool >  __o_Force){
bool Force = __o_Force.Default(false);
	HX_STACK_PUSH("FlxSprite::play","org/flixel/FlxSprite.hx",1061);
	HX_STACK_THIS(this);
	HX_STACK_ARG(AnimName,"AnimName");
	HX_STACK_ARG(Force,"Force");
{
		HX_STACK_LINE(1062)
		if (((bool((bool((bool(!(Force)) && bool((this->_curAnim != null())))) && bool((AnimName == this->_curAnim->name)))) && bool(((bool(this->_curAnim->looped) || bool(!(this->finished)))))))){
			HX_STACK_LINE(1064)
			this->paused = false;
			HX_STACK_LINE(1065)
			return null();
		}
		HX_STACK_LINE(1067)
		this->_curFrame = (int)0;
		HX_STACK_LINE(1068)
		this->_curIndex = (int)0;
		HX_STACK_LINE(1070)
		if (((this->_framesData != null()))){
			HX_STACK_LINE(1071)
			this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
		}
		HX_STACK_LINE(1075)
		this->_frameTimer = (int)0;
		HX_STACK_LINE(1076)
		if ((this->_animations->exists(AnimName))){
			HX_STACK_LINE(1078)
			this->_curAnim = this->_animations->get(AnimName);
			HX_STACK_LINE(1079)
			if (((this->_curAnim->delay <= (int)0))){
				HX_STACK_LINE(1080)
				this->finished = true;
			}
			else{
				HX_STACK_LINE(1084)
				this->finished = false;
			}
			HX_STACK_LINE(1087)
			this->_curIndex = this->_curAnim->frames->__get(this->_curFrame);
			HX_STACK_LINE(1089)
			if (((this->_framesData != null()))){
				HX_STACK_LINE(1090)
				this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
			}
			HX_STACK_LINE(1094)
			this->dirty = true;
			HX_STACK_LINE(1095)
			this->paused = false;
			HX_STACK_LINE(1096)
			return null();
		}
		HX_STACK_LINE(1099)
		{
			HX_STACK_LINE(1099)
			Dynamic Data = ((HX_CSTRING("WARNING: No animation called \"") + AnimName) + HX_CSTRING("\""));		HX_STACK_VAR(Data,"Data");
			HX_STACK_LINE(1099)
			if (((bool((::org::flixel::FlxG_obj::_game != null())) && bool((::org::flixel::FlxG_obj::_game->getDebugger() != null()))))){
				struct _Function_3_1{
					inline static ::String Block( Dynamic &Data){
						HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",1099);
						{
							HX_STACK_LINE(1099)
							Dynamic AnyArray = hx::TCastToArray(Data);		HX_STACK_VAR(AnyArray,"AnyArray");
							HX_STACK_LINE(1099)
							::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
							HX_STACK_LINE(1099)
							if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
								HX_STACK_LINE(1099)
								string = ::Std_obj::string(AnyArray->__GetItem((int)0));
								HX_STACK_LINE(1099)
								int i = (int)1;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(1099)
								int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
								HX_STACK_LINE(1099)
								while(((i < l))){
									HX_STACK_LINE(1099)
									hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
								}
							}
							HX_STACK_LINE(1099)
							return string;
						}
						return null();
					}
				};
				HX_STACK_LINE(1099)
				::org::flixel::FlxG_obj::_game->getDebugger()->log->add((  (((Data == null()))) ? ::String(HX_CSTRING("ERROR: null object")) : ::String((  ((::Std_obj::is(Data,hx::ClassOf< Array<int> >()))) ? ::String(_Function_3_1::Block(Data)) : ::String(::Std_obj::string(Data)) )) ));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxSprite_obj,play,(void))

Void FlxSprite_obj::addAnimationCallback( Dynamic AnimationCallback){
{
		HX_STACK_PUSH("FlxSprite::addAnimationCallback","org/flixel/FlxSprite.hx",1050);
		HX_STACK_THIS(this);
		HX_STACK_ARG(AnimationCallback,"AnimationCallback");
		HX_STACK_LINE(1050)
		this->_callback = AnimationCallback;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,addAnimationCallback,(void))

Void FlxSprite_obj::addAnimation( ::String Name,Array< int > Frames,hx::Null< int >  __o_FrameRate,hx::Null< bool >  __o_Looped){
int FrameRate = __o_FrameRate.Default(30);
bool Looped = __o_Looped.Default(true);
	HX_STACK_PUSH("FlxSprite::addAnimation","org/flixel/FlxSprite.hx",1037);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Name,"Name");
	HX_STACK_ARG(Frames,"Frames");
	HX_STACK_ARG(FrameRate,"FrameRate");
	HX_STACK_ARG(Looped,"Looped");
{
		HX_STACK_LINE(1037)
		this->_animations->set(Name,::org::flixel::system::FlxAnim_obj::__new(Name,Frames,FrameRate,Looped));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxSprite_obj,addAnimation,(void))

Void FlxSprite_obj::drawFrame( hx::Null< bool >  __o_Force){
bool Force = __o_Force.Default(false);
	HX_STACK_PUSH("FlxSprite::drawFrame","org/flixel/FlxSprite.hx",1018);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Force,"Force");
{
		HX_STACK_LINE(1018)
		this->calcFrame(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,drawFrame,(void))

Void FlxSprite_obj::updateAnimation( ){
{
		HX_STACK_PUSH("FlxSprite::updateAnimation","org/flixel/FlxSprite.hx",942);
		HX_STACK_THIS(this);
		HX_STACK_LINE(943)
		if (((this->bakedRotation > (int)0))){
			HX_STACK_LINE(945)
			int oldIndex = this->_curIndex;		HX_STACK_VAR(oldIndex,"oldIndex");
			HX_STACK_LINE(949)
			int angleHelper = ::Math_obj::floor(hx::Mod(((this->angle + this->_additionalAngle)),(int)360));		HX_STACK_VAR(angleHelper,"angleHelper");
			HX_STACK_LINE(958)
			while(((angleHelper < (int)0))){
				HX_STACK_LINE(959)
				hx::AddEq(angleHelper,(int)360);
			}
			HX_STACK_LINE(964)
			this->_curIndex = ::Math_obj::floor(((Float(angleHelper) / Float(this->bakedRotation)) + 0.5));
			HX_STACK_LINE(967)
			if (((this->_framesData != null()))){
				HX_STACK_LINE(968)
				this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
			}
			HX_STACK_LINE(972)
			if (((oldIndex != this->_curIndex))){
				HX_STACK_LINE(973)
				this->dirty = true;
			}
		}
		else{
			HX_STACK_LINE(977)
			if (((bool((bool((bool((this->_curAnim != null())) && bool((this->_curAnim->delay > (int)0)))) && bool(((bool(this->_curAnim->looped) || bool(!(this->finished))))))) && bool(!(this->paused))))){
				HX_STACK_LINE(979)
				hx::AddEq(this->_frameTimer,::org::flixel::FlxG_obj::elapsed);
				HX_STACK_LINE(980)
				while(((this->_frameTimer > this->_curAnim->delay))){
					HX_STACK_LINE(982)
					this->_frameTimer = (this->_frameTimer - this->_curAnim->delay);
					HX_STACK_LINE(983)
					if (((this->_curFrame == (this->_curAnim->frames->length - (int)1)))){
						HX_STACK_LINE(985)
						if ((this->_curAnim->looped)){
							HX_STACK_LINE(986)
							this->_curFrame = (int)0;
						}
						HX_STACK_LINE(989)
						this->finished = true;
					}
					else{
						HX_STACK_LINE(992)
						(this->_curFrame)++;
					}
					HX_STACK_LINE(995)
					this->_curIndex = this->_curAnim->frames->__get(this->_curFrame);
					HX_STACK_LINE(997)
					if (((this->_framesData != null()))){
						HX_STACK_LINE(998)
						this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
					}
					HX_STACK_LINE(1002)
					this->dirty = true;
				}
			}
		}
		HX_STACK_LINE(1006)
		if ((this->dirty)){
			HX_STACK_LINE(1007)
			this->calcFrame(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,updateAnimation,(void))

Void FlxSprite_obj::fill( int Color){
{
		HX_STACK_PUSH("FlxSprite::fill","org/flixel/FlxSprite.hx",924);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Color,"Color");
		HX_STACK_LINE(925)
		this->_pixels->fillRect(this->_flashRect2,Color);
		HX_STACK_LINE(926)
		if (((this->_pixels != this->framePixels))){
			HX_STACK_LINE(927)
			this->dirty = true;
		}
		HX_STACK_LINE(931)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(933)
		this->updateAtlasInfo(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,fill,(void))

Void FlxSprite_obj::drawLine( Float StartX,Float StartY,Float EndX,Float EndY,int Color,hx::Null< int >  __o_Thickness){
int Thickness = __o_Thickness.Default(1);
	HX_STACK_PUSH("FlxSprite::drawLine","org/flixel/FlxSprite.hx",883);
	HX_STACK_THIS(this);
	HX_STACK_ARG(StartX,"StartX");
	HX_STACK_ARG(StartY,"StartY");
	HX_STACK_ARG(EndX,"EndX");
	HX_STACK_ARG(EndY,"EndY");
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Thickness,"Thickness");
{
		HX_STACK_LINE(885)
		::native::display::Graphics gfx = ::org::flixel::FlxG_obj::flashGfx;		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(886)
		gfx->clear();
		HX_STACK_LINE(887)
		gfx->moveTo(StartX,StartY);
		HX_STACK_LINE(889)
		Float alphaComponent = (Float(((int((int(Color) >> int((int)24))) & int((int)255)))) / Float((int)255));		HX_STACK_VAR(alphaComponent,"alphaComponent");
		HX_STACK_LINE(893)
		if (((alphaComponent <= (int)0))){
			HX_STACK_LINE(894)
			alphaComponent = (int)1;
		}
		HX_STACK_LINE(900)
		gfx->lineStyle(Thickness,Color,alphaComponent,null(),null(),null(),null(),null());
		HX_STACK_LINE(902)
		gfx->lineTo(EndX,EndY);
		HX_STACK_LINE(905)
		this->_pixels->draw(::org::flixel::FlxG_obj::flashGfxSprite,null(),null(),null(),null(),null());
		HX_STACK_LINE(906)
		this->dirty = true;
		HX_STACK_LINE(909)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(912)
		this->updateAtlasInfo(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(FlxSprite_obj,drawLine,(void))

Void FlxSprite_obj::stamp( ::org::flixel::FlxSprite Brush,hx::Null< int >  __o_X,hx::Null< int >  __o_Y){
int X = __o_X.Default(0);
int Y = __o_Y.Default(0);
	HX_STACK_PUSH("FlxSprite::stamp","org/flixel/FlxSprite.hx",828);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Brush,"Brush");
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
{
		HX_STACK_LINE(829)
		Brush->drawFrame(null());
		HX_STACK_LINE(830)
		::native::display::BitmapData bitmapData = Brush->framePixels;		HX_STACK_VAR(bitmapData,"bitmapData");
		HX_STACK_LINE(833)
		if (((bool((bool((bool(((bool((Brush->angle == (int)0)) || bool((Brush->bakedRotation > (int)0))))) && bool((Brush->scale->x == (int)1)))) && bool((Brush->scale->y == (int)1)))) && bool((Brush->get_blend() == null()))))){
			HX_STACK_LINE(835)
			this->_flashPoint->x = X;
			HX_STACK_LINE(836)
			this->_flashPoint->y = Y;
			HX_STACK_LINE(837)
			this->_flashRect2->width = bitmapData->get_width();
			HX_STACK_LINE(838)
			this->_flashRect2->height = bitmapData->get_height();
			HX_STACK_LINE(839)
			this->_pixels->copyPixels(bitmapData,this->_flashRect2,this->_flashPoint,null(),null(),true);
			HX_STACK_LINE(840)
			this->_flashRect2->width = this->_pixels->get_width();
			HX_STACK_LINE(841)
			this->_flashRect2->height = this->_pixels->get_height();
			HX_STACK_LINE(845)
			return null();
		}
		HX_STACK_LINE(849)
		this->_matrix->identity();
		HX_STACK_LINE(850)
		this->_matrix->translate(-(Brush->origin->x),-(Brush->origin->y));
		HX_STACK_LINE(851)
		this->_matrix->scale(Brush->scale->x,Brush->scale->y);
		HX_STACK_LINE(852)
		if (((Brush->angle != (int)0))){
			HX_STACK_LINE(853)
			this->_matrix->rotate((Brush->angle * ((Float(::Math_obj::PI) / Float((int)180)))));
		}
		HX_STACK_LINE(856)
		this->_matrix->translate((X + Brush->origin->x),(Y + Brush->origin->y));
		HX_STACK_LINE(857)
		::native::display::BlendMode brushBlend = Brush->get_blend();		HX_STACK_VAR(brushBlend,"brushBlend");
		HX_STACK_LINE(859)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(861)
		this->_pixels->draw(bitmapData,this->_matrix,null(),brushBlend,null(),Brush->antialiasing);
		HX_STACK_LINE(865)
		this->updateAtlasInfo(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,stamp,(void))

Void FlxSprite_obj::draw( ){
{
		HX_STACK_PUSH("FlxSprite::draw","org/flixel/FlxSprite.hx",643);
		HX_STACK_THIS(this);
		HX_STACK_LINE(645)
		if (((this->_atlas == null()))){
			HX_STACK_LINE(646)
			return null();
		}
		HX_STACK_LINE(651)
		if (((this->_flickerTimer != (int)0))){
			HX_STACK_LINE(653)
			this->_flicker = !(this->_flicker);
			HX_STACK_LINE(654)
			if ((this->_flicker)){
				HX_STACK_LINE(655)
				return null();
			}
		}
		HX_STACK_LINE(660)
		if ((this->dirty)){
			HX_STACK_LINE(661)
			this->calcFrame(null());
		}
		HX_STACK_LINE(665)
		if (((this->cameras == null()))){
			HX_STACK_LINE(666)
			this->cameras = ::org::flixel::FlxG_obj::cameras;
		}
		HX_STACK_LINE(669)
		::org::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(670)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(671)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(674)
		::org::flixel::system::layer::DrawStackItem drawItem;		HX_STACK_VAR(drawItem,"drawItem");
		HX_STACK_LINE(675)
		Array< Float > currDrawData;		HX_STACK_VAR(currDrawData,"currDrawData");
		HX_STACK_LINE(676)
		int currIndex;		HX_STACK_VAR(currIndex,"currIndex");
		HX_STACK_LINE(678)
		bool isColored = (this->_color < (int)16777215);		HX_STACK_VAR(isColored,"isColored");
		HX_STACK_LINE(683)
		Float radians;		HX_STACK_VAR(radians,"radians");
		HX_STACK_LINE(684)
		Float cos;		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(685)
		Float sin;		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(688)
		while(((i < l))){
			HX_STACK_LINE(690)
			camera = this->cameras->__get((i)++);
			struct _Function_2_1{
				inline static bool Block( ::org::flixel::FlxCamera &camera,::org::flixel::FlxSprite_obj *__this){
					HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",692);
					{
						HX_STACK_LINE(692)
						::org::flixel::FlxCamera Camera = camera;		HX_STACK_VAR(Camera,"Camera");
						HX_STACK_LINE(692)
						if (((Camera == null()))){
							HX_STACK_LINE(692)
							Camera = ::org::flixel::FlxG_obj::camera;
						}
						HX_STACK_LINE(692)
						{
							HX_STACK_LINE(692)
							::org::flixel::FlxPoint point = __this->_point;		HX_STACK_VAR(point,"point");
							::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
							HX_STACK_LINE(692)
							if (((point == null()))){
								HX_STACK_LINE(692)
								point = ::org::flixel::FlxPoint_obj::__new(null(),null());
							}
							HX_STACK_LINE(692)
							if (((Camera1 == null()))){
								HX_STACK_LINE(692)
								Camera1 = ::org::flixel::FlxG_obj::camera;
							}
							HX_STACK_LINE(692)
							point->x = (__this->x - (Camera1->scroll->x * __this->scrollFactor->x));
							HX_STACK_LINE(692)
							point->y = (__this->y - (Camera1->scroll->y * __this->scrollFactor->y));
							HX_STACK_LINE(692)
							point;
						}
						HX_STACK_LINE(692)
						__this->_point->x = (__this->_point->x - __this->offset->x);
						HX_STACK_LINE(692)
						__this->_point->y = (__this->_point->y - __this->offset->y);
						HX_STACK_LINE(692)
						bool result = false;		HX_STACK_VAR(result,"result");
						HX_STACK_LINE(692)
						bool notRotated = (__this->angle == 0.0);		HX_STACK_VAR(notRotated,"notRotated");
						HX_STACK_LINE(692)
						notRotated = (bool(notRotated) && bool((__this->_additionalAngle != 0.0)));
						HX_STACK_LINE(692)
						if (((bool((bool(((bool(notRotated) || bool((__this->bakedRotation > (int)0))))) && bool((__this->scale->x == (int)1)))) && bool((__this->scale->y == (int)1))))){
							HX_STACK_LINE(692)
							result = (bool((bool((bool(((__this->_point->x + __this->frameWidth) > (int)0)) && bool((__this->_point->x < Camera->width)))) && bool(((__this->_point->y + __this->frameHeight) > (int)0)))) && bool((__this->_point->y < Camera->height)));
						}
						else{
							HX_STACK_LINE(692)
							Float halfWidth = (0.5 * __this->frameWidth);		HX_STACK_VAR(halfWidth,"halfWidth");
							HX_STACK_LINE(692)
							Float halfHeight = (0.5 * __this->frameHeight);		HX_STACK_VAR(halfHeight,"halfHeight");
							HX_STACK_LINE(692)
							Float absScaleX = (  (((__this->scale->x > (int)0))) ? Float(__this->scale->x) : Float(-(__this->scale->x)) );		HX_STACK_VAR(absScaleX,"absScaleX");
							HX_STACK_LINE(692)
							Float absScaleY = (  (((__this->scale->y > (int)0))) ? Float(__this->scale->y) : Float(-(__this->scale->y)) );		HX_STACK_VAR(absScaleY,"absScaleY");
							HX_STACK_LINE(692)
							Float radius = (((  (((__this->frameWidth >= __this->frameHeight))) ? int(__this->frameWidth) : int(__this->frameHeight) )) * ((  (((absScaleX >= absScaleY))) ? Float(absScaleX) : Float(absScaleY) )));		HX_STACK_VAR(radius,"radius");
							HX_STACK_LINE(692)
							hx::AddEq(__this->_point->x,halfWidth);
							HX_STACK_LINE(692)
							hx::AddEq(__this->_point->y,halfHeight);
							HX_STACK_LINE(692)
							result = (bool((bool((bool(((__this->_point->x + radius) > (int)0)) && bool(((__this->_point->x - radius) < Camera->width)))) && bool(((__this->_point->y + radius) > (int)0)))) && bool(((__this->_point->y - radius) < Camera->height)));
						}
						HX_STACK_LINE(692)
						return result;
					}
					return null();
				}
			};
			HX_STACK_LINE(692)
			if (((bool((bool(!(_Function_2_1::Block(camera,this))) || bool(!(camera->visible)))) || bool(!(camera->exists))))){
				HX_STACK_LINE(693)
				continue;
			}
			HX_STACK_LINE(699)
			bool isColoredCamera = (camera->color < (int)16777215);		HX_STACK_VAR(isColoredCamera,"isColoredCamera");
			struct _Function_2_2{
				inline static ::org::flixel::system::layer::DrawStackItem Block( ::org::flixel::FlxSprite_obj *__this,::org::flixel::FlxCamera &camera,bool &isColored,bool &isColoredCamera){
					HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",700);
					{
						HX_STACK_LINE(700)
						::org::flixel::system::layer::Atlas ObjAtlas = __this->_atlas;		HX_STACK_VAR(ObjAtlas,"ObjAtlas");
						bool ObjColored = (bool(isColored) || bool(isColoredCamera));		HX_STACK_VAR(ObjColored,"ObjColored");
						int ObjBlending = __this->_blendInt;		HX_STACK_VAR(ObjBlending,"ObjBlending");
						HX_STACK_LINE(700)
						::org::flixel::system::layer::DrawStackItem itemToReturn = null();		HX_STACK_VAR(itemToReturn,"itemToReturn");
						HX_STACK_LINE(700)
						if (((camera->_currentStackItem->initialized == false))){
							HX_STACK_LINE(700)
							camera->_headOfDrawStack = camera->_currentStackItem;
							HX_STACK_LINE(700)
							camera->_currentStackItem->atlas = ObjAtlas;
							HX_STACK_LINE(700)
							camera->_currentStackItem->colored = ObjColored;
							HX_STACK_LINE(700)
							camera->_currentStackItem->blending = ObjBlending;
							HX_STACK_LINE(700)
							itemToReturn = camera->_currentStackItem;
						}
						else{
							HX_STACK_LINE(700)
							if (((bool((bool((camera->_currentStackItem->atlas == ObjAtlas)) && bool((camera->_currentStackItem->colored == ObjColored)))) && bool((camera->_currentStackItem->blending == ObjBlending))))){
								HX_STACK_LINE(700)
								itemToReturn = camera->_currentStackItem;
							}
						}
						HX_STACK_LINE(700)
						if (((itemToReturn == null()))){
							HX_STACK_LINE(700)
							::org::flixel::system::layer::DrawStackItem newItem = null();		HX_STACK_VAR(newItem,"newItem");
							HX_STACK_LINE(700)
							if (((::org::flixel::FlxCamera_obj::_storageHead != null()))){
								HX_STACK_LINE(700)
								newItem = ::org::flixel::FlxCamera_obj::_storageHead;
								HX_STACK_LINE(700)
								::org::flixel::system::layer::DrawStackItem newHead = ::org::flixel::FlxCamera_obj::_storageHead->next;		HX_STACK_VAR(newHead,"newHead");
								HX_STACK_LINE(700)
								newItem->next = null();
								HX_STACK_LINE(700)
								::org::flixel::FlxCamera_obj::_storageHead = newHead;
							}
							else{
								HX_STACK_LINE(700)
								newItem = ::org::flixel::system::layer::DrawStackItem_obj::__new();
							}
							HX_STACK_LINE(700)
							newItem->atlas = ObjAtlas;
							HX_STACK_LINE(700)
							newItem->colored = ObjColored;
							HX_STACK_LINE(700)
							newItem->blending = ObjBlending;
							HX_STACK_LINE(700)
							camera->_currentStackItem->next = newItem;
							HX_STACK_LINE(700)
							camera->_currentStackItem = newItem;
							HX_STACK_LINE(700)
							itemToReturn = camera->_currentStackItem;
						}
						HX_STACK_LINE(700)
						itemToReturn->initialized = true;
						HX_STACK_LINE(700)
						return itemToReturn;
					}
					return null();
				}
			};
			HX_STACK_LINE(700)
			drawItem = _Function_2_2::Block(this,camera,isColored,isColoredCamera);
			HX_STACK_LINE(704)
			currDrawData = drawItem->drawData;
			HX_STACK_LINE(705)
			currIndex = drawItem->position;
			HX_STACK_LINE(707)
			this->_point->x = ((this->x - (camera->scroll->x * this->scrollFactor->x)) - this->offset->x);
			HX_STACK_LINE(708)
			this->_point->y = ((this->y - (camera->scroll->y * this->scrollFactor->y)) - this->offset->y);
			HX_STACK_LINE(710)
			this->_point->x = (this->_point->x + this->origin->x);
			HX_STACK_LINE(711)
			this->_point->y = (this->_point->y + this->origin->y);
			HX_STACK_LINE(742)
			Float csx = (int)1;		HX_STACK_VAR(csx,"csx");
			HX_STACK_LINE(743)
			Float ssy = (int)0;		HX_STACK_VAR(ssy,"ssy");
			HX_STACK_LINE(744)
			Float ssx = (int)0;		HX_STACK_VAR(ssx,"ssx");
			HX_STACK_LINE(745)
			Float csy = (int)1;		HX_STACK_VAR(csy,"csy");
			HX_STACK_LINE(746)
			Float x2 = 0.0;		HX_STACK_VAR(x2,"x2");
			HX_STACK_LINE(747)
			Float y2 = 0.0;		HX_STACK_VAR(y2,"y2");
			HX_STACK_LINE(749)
			if ((!(((bool((bool(((bool((bool((this->angle == (int)0)) && bool((this->_additionalAngle == (int)0)))) || bool((this->bakedRotation > (int)0))))) && bool((this->scale->x == (int)1)))) && bool((this->scale->y == (int)1))))))){
				HX_STACK_LINE(751)
				radians = (-(((this->angle + this->_additionalAngle))) * ((Float(::Math_obj::PI) / Float((int)180))));
				HX_STACK_LINE(752)
				cos = ::Math_obj::cos(radians);
				HX_STACK_LINE(753)
				sin = ::Math_obj::sin(radians);
				HX_STACK_LINE(755)
				csx = (cos * this->scale->x);
				HX_STACK_LINE(756)
				ssy = (sin * this->scale->y);
				HX_STACK_LINE(757)
				ssx = (sin * this->scale->x);
				HX_STACK_LINE(758)
				csy = (cos * this->scale->y);
				HX_STACK_LINE(760)
				Float x1 = (this->origin->x - this->_halfWidth);		HX_STACK_VAR(x1,"x1");
				HX_STACK_LINE(761)
				Float y1 = (this->origin->y - this->_halfHeight);		HX_STACK_VAR(y1,"y1");
				HX_STACK_LINE(762)
				x2 = ((x1 * csx) + (y1 * ssy));
				HX_STACK_LINE(763)
				y2 = ((-(x1) * ssx) + (y1 * csy));
			}
			HX_STACK_LINE(766)
			currDrawData[(currIndex)++] = (this->_point->x - x2);
			HX_STACK_LINE(767)
			currDrawData[(currIndex)++] = (this->_point->y - y2);
			HX_STACK_LINE(769)
			currDrawData[(currIndex)++] = this->_frameID;
			HX_STACK_LINE(771)
			if (((bool((this->_flipped != (int)0)) && bool((this->facing == (int)1))))){
				HX_STACK_LINE(773)
				currDrawData[(currIndex)++] = -(csx);
				HX_STACK_LINE(774)
				currDrawData[(currIndex)++] = ssy;
				HX_STACK_LINE(775)
				currDrawData[(currIndex)++] = ssx;
				HX_STACK_LINE(776)
				currDrawData[(currIndex)++] = csy;
			}
			else{
				HX_STACK_LINE(780)
				currDrawData[(currIndex)++] = csx;
				HX_STACK_LINE(781)
				currDrawData[(currIndex)++] = ssy;
				HX_STACK_LINE(782)
				currDrawData[(currIndex)++] = -(ssx);
				HX_STACK_LINE(783)
				currDrawData[(currIndex)++] = csy;
			}
			HX_STACK_LINE(786)
			if (((bool(isColored) || bool(isColoredCamera)))){
				HX_STACK_LINE(787)
				if ((isColoredCamera)){
					HX_STACK_LINE(790)
					currDrawData[(currIndex)++] = (this->_red * camera->red);
					HX_STACK_LINE(791)
					currDrawData[(currIndex)++] = (this->_green * camera->green);
					HX_STACK_LINE(792)
					currDrawData[(currIndex)++] = (this->_blue * camera->blue);
				}
				else{
					HX_STACK_LINE(796)
					currDrawData[(currIndex)++] = this->_red;
					HX_STACK_LINE(797)
					currDrawData[(currIndex)++] = this->_green;
					HX_STACK_LINE(798)
					currDrawData[(currIndex)++] = this->_blue;
				}
			}
			HX_STACK_LINE(801)
			currDrawData[(currIndex)++] = this->alpha;
			HX_STACK_LINE(808)
			drawItem->position = currIndex;
			HX_STACK_LINE(810)
			(::org::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
			HX_STACK_LINE(812)
			if (((bool(::org::flixel::FlxG_obj::visualDebug) && bool(!(this->ignoreDrawDebug))))){
				HX_STACK_LINE(813)
				this->drawDebug(camera);
			}
		}
	}
return null();
}


bool FlxSprite_obj::isColored( ){
	HX_STACK_PUSH("FlxSprite::isColored","org/flixel/FlxSprite.hx",631);
	HX_STACK_THIS(this);
	HX_STACK_LINE(631)
	return (this->_color < (int)16777215);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,isColored,return )

Void FlxSprite_obj::postUpdate( ){
{
		HX_STACK_PUSH("FlxSprite::postUpdate","org/flixel/FlxSprite.hx",625);
		HX_STACK_THIS(this);
		HX_STACK_LINE(626)
		this->super::postUpdate();
		HX_STACK_LINE(627)
		this->updateAnimation();
	}
return null();
}


Void FlxSprite_obj::resetHelpers( ){
{
		HX_STACK_PUSH("FlxSprite::resetHelpers","org/flixel/FlxSprite.hx",579);
		HX_STACK_THIS(this);
		HX_STACK_LINE(580)
		this->_flashRect->x = (int)0;
		HX_STACK_LINE(581)
		this->_flashRect->y = (int)0;
		HX_STACK_LINE(582)
		this->_flashRect->width = this->frameWidth;
		HX_STACK_LINE(583)
		this->_flashRect->height = this->frameHeight;
		HX_STACK_LINE(584)
		this->_flashRect2->x = (int)0;
		HX_STACK_LINE(585)
		this->_flashRect2->y = (int)0;
		HX_STACK_LINE(586)
		this->_flashRect2->width = this->_pixels->get_width();
		HX_STACK_LINE(587)
		this->_flashRect2->height = this->_pixels->get_height();
		HX_STACK_LINE(589)
		{
			HX_STACK_LINE(589)
			::org::flixel::FlxPoint _this = this->origin;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(589)
			_this->x = (this->frameWidth * 0.5);
			HX_STACK_LINE(589)
			_this->y = (this->frameHeight * 0.5);
			HX_STACK_LINE(589)
			_this;
		}
		HX_STACK_LINE(601)
		this->frames = ::Std_obj::_int((Float(((Float(this->_flashRect2->width) / Float(((this->_flashRect->width + (int)1)))) * this->_flashRect2->height)) / Float(((this->_flashRect->height + (int)1)))));
		HX_STACK_LINE(602)
		if (((this->frames == (int)0))){
			HX_STACK_LINE(602)
			this->frames = (int)1;
		}
		HX_STACK_LINE(603)
		if (((this->_flipped > (int)0))){
			HX_STACK_LINE(604)
			hx::MultEq(this->frames,(int)2);
		}
		HX_STACK_LINE(608)
		this->_curIndex = (int)0;
		HX_STACK_LINE(610)
		if (((this->_framesData != null()))){
			HX_STACK_LINE(611)
			this->_frameID = this->_framesData->frameIDs->__get(this->_curIndex);
		}
		HX_STACK_LINE(615)
		this->_halfWidth = (this->frameWidth * 0.5);
		HX_STACK_LINE(616)
		this->_halfHeight = (this->frameHeight * 0.5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,resetHelpers,(void))

::org::flixel::FlxSprite FlxSprite_obj::makeGraphic( int Width,int Height,Dynamic Color,hx::Null< bool >  __o_Unique,::String Key){
bool Unique = __o_Unique.Default(false);
	HX_STACK_PUSH("FlxSprite::makeGraphic","org/flixel/FlxSprite.hx",554);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Width,"Width");
	HX_STACK_ARG(Height,"Height");
	HX_STACK_ARG(Color,"Color");
	HX_STACK_ARG(Unique,"Unique");
	HX_STACK_ARG(Key,"Key");
{
		HX_STACK_LINE(556)
		if (((Color == null()))){
			HX_STACK_LINE(557)
			Color = (int)-1;
		}
		HX_STACK_LINE(562)
		this->bakedRotation = (int)0;
		HX_STACK_LINE(563)
		this->_pixels = ::org::flixel::FlxG_obj::createBitmap(Width,Height,Color,Unique,Key);
		HX_STACK_LINE(565)
		this->_bitmapDataKey = ::org::flixel::FlxG_obj::_lastBitmapDataKey;
		HX_STACK_LINE(566)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(568)
		this->width = this->frameWidth = this->_pixels->get_width();
		HX_STACK_LINE(569)
		this->height = this->frameHeight = this->_pixels->get_height();
		HX_STACK_LINE(570)
		this->resetHelpers();
		HX_STACK_LINE(571)
		this->updateAtlasInfo(null());
		HX_STACK_LINE(572)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxSprite_obj,makeGraphic,return )

::org::flixel::FlxSprite FlxSprite_obj::loadRotatedGraphic( Dynamic Graphic,hx::Null< int >  __o_Rotations,hx::Null< int >  __o_Frame,hx::Null< bool >  __o_AntiAliasing,hx::Null< bool >  __o_AutoBuffer,::String Key){
int Rotations = __o_Rotations.Default(16);
int Frame = __o_Frame.Default(-1);
bool AntiAliasing = __o_AntiAliasing.Default(false);
bool AutoBuffer = __o_AutoBuffer.Default(false);
	HX_STACK_PUSH("FlxSprite::loadRotatedGraphic","org/flixel/FlxSprite.hx",413);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Graphic,"Graphic");
	HX_STACK_ARG(Rotations,"Rotations");
	HX_STACK_ARG(Frame,"Frame");
	HX_STACK_ARG(AntiAliasing,"AntiAliasing");
	HX_STACK_ARG(AutoBuffer,"AutoBuffer");
	HX_STACK_ARG(Key,"Key");
{
		HX_STACK_LINE(415)
		int rows = ::Std_obj::_int(::Math_obj::sqrt(Rotations));		HX_STACK_VAR(rows,"rows");
		HX_STACK_LINE(416)
		::native::display::BitmapData brush = ::org::flixel::FlxG_obj::addBitmap(Graphic,false,false,Key,null(),null());		HX_STACK_VAR(brush,"brush");
		HX_STACK_LINE(417)
		if (((Frame >= (int)0))){
			HX_STACK_LINE(420)
			::native::display::BitmapData full = brush;		HX_STACK_VAR(full,"full");
			HX_STACK_LINE(421)
			brush = ::native::display::BitmapData_obj::__new(full->get_height(),full->get_height(),null(),null(),null());
			HX_STACK_LINE(422)
			int rx = (Frame * brush->get_width());		HX_STACK_VAR(rx,"rx");
			HX_STACK_LINE(423)
			int ry = (int)0;		HX_STACK_VAR(ry,"ry");
			HX_STACK_LINE(424)
			int fw = full->get_width();		HX_STACK_VAR(fw,"fw");
			HX_STACK_LINE(425)
			if (((rx >= fw))){
				HX_STACK_LINE(427)
				ry = (::Std_obj::_int((Float(rx) / Float(fw))) * brush->get_height());
				HX_STACK_LINE(428)
				hx::ModEq(rx,fw);
			}
			HX_STACK_LINE(430)
			this->_flashRect->x = rx;
			HX_STACK_LINE(431)
			this->_flashRect->y = ry;
			HX_STACK_LINE(432)
			this->_flashRect->width = brush->get_width();
			HX_STACK_LINE(433)
			this->_flashRect->height = brush->get_height();
			HX_STACK_LINE(434)
			brush->copyPixels(full,this->_flashRect,this->_flashPointZero,null(),null(),null());
		}
		HX_STACK_LINE(437)
		int max = brush->get_width();		HX_STACK_VAR(max,"max");
		HX_STACK_LINE(438)
		if (((brush->get_height() > max))){
			HX_STACK_LINE(439)
			max = brush->get_height();
		}
		HX_STACK_LINE(443)
		if ((AutoBuffer)){
			HX_STACK_LINE(444)
			max = ::Std_obj::_int((max * 1.5));
		}
		struct _Function_1_1{
			inline static int Block( int &Rotations,int &rows){
				HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",448);
				{
					HX_STACK_LINE(448)
					Float Value = (Float(Rotations) / Float(rows));		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(448)
					int number = ::Std_obj::_int(Value);		HX_STACK_VAR(number,"number");
					struct _Function_2_1{
						inline static int Block( int &number,Float &Value){
							HX_STACK_PUSH("*::closure","org/flixel/FlxSprite.hx",448);
							{
								HX_STACK_LINE(448)
								return (  (((number != Value))) ? int((number + (int)1)) : int(number) );
							}
							return null();
						}
					};
					HX_STACK_LINE(448)
					return (  (((Value > (int)0))) ? int(_Function_2_1::Block(number,Value)) : int(number) );
				}
				return null();
			}
		};
		HX_STACK_LINE(448)
		int columns = _Function_1_1::Block(Rotations,rows);		HX_STACK_VAR(columns,"columns");
		HX_STACK_LINE(449)
		this->width = (max * columns);
		HX_STACK_LINE(450)
		this->height = (max * rows);
		HX_STACK_LINE(451)
		::String key = HX_CSTRING("");		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(452)
		if ((::Std_obj::is(Graphic,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(453)
			key = Graphic;
		}
		else{
			HX_STACK_LINE(456)
			if ((::Std_obj::is(Graphic,hx::ClassOf< ::Class >()))){
				HX_STACK_LINE(457)
				key = ::Type_obj::getClassName(Graphic);
			}
			else{
				HX_STACK_LINE(460)
				if (((bool(::Std_obj::is(Graphic,hx::ClassOf< ::native::display::BitmapData >())) && bool((Key != null()))))){
					HX_STACK_LINE(461)
					key = Key;
				}
				else{
					HX_STACK_LINE(465)
					return null();
				}
			}
		}
		HX_STACK_LINE(471)
		hx::AddEq(key,(((((((HX_CSTRING(":") + Frame) + HX_CSTRING(":")) + this->width) + HX_CSTRING("x")) + this->height) + HX_CSTRING(":")) + Rotations));
		HX_STACK_LINE(473)
		bool skipGen = ::org::flixel::FlxG_obj::checkBitmapCache(key);		HX_STACK_VAR(skipGen,"skipGen");
		HX_STACK_LINE(478)
		this->_pixels = ::org::flixel::FlxG_obj::createBitmap((::Std_obj::_int(this->width) + columns),(::Std_obj::_int(this->height) + rows),(int)0,true,key);
		HX_STACK_LINE(482)
		this->_bitmapDataKey = ::org::flixel::FlxG_obj::_lastBitmapDataKey;
		HX_STACK_LINE(483)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(486)
		this->width = this->frameWidth = this->_pixels->get_width();
		HX_STACK_LINE(487)
		this->height = this->frameHeight = this->_pixels->get_height();
		HX_STACK_LINE(488)
		this->bakedRotation = (Float((int)360) / Float(Rotations));
		HX_STACK_LINE(491)
		if ((!(skipGen))){
			HX_STACK_LINE(493)
			int row = (int)0;		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(494)
			int column;		HX_STACK_VAR(column,"column");
			HX_STACK_LINE(495)
			Float bakedAngle = (int)0;		HX_STACK_VAR(bakedAngle,"bakedAngle");
			HX_STACK_LINE(496)
			int halfBrushWidth = ::Std_obj::_int((brush->get_width() * 0.5));		HX_STACK_VAR(halfBrushWidth,"halfBrushWidth");
			HX_STACK_LINE(497)
			int halfBrushHeight = ::Std_obj::_int((brush->get_height() * 0.5));		HX_STACK_VAR(halfBrushHeight,"halfBrushHeight");
			HX_STACK_LINE(498)
			int midpointX = ::Std_obj::_int((max * 0.5));		HX_STACK_VAR(midpointX,"midpointX");
			HX_STACK_LINE(499)
			int midpointY = ::Std_obj::_int((max * 0.5));		HX_STACK_VAR(midpointY,"midpointY");
			HX_STACK_LINE(500)
			while(((row < rows))){
				HX_STACK_LINE(502)
				column = (int)0;
				HX_STACK_LINE(503)
				while(((column < columns))){
					HX_STACK_LINE(505)
					this->_matrix->identity();
					HX_STACK_LINE(506)
					this->_matrix->translate(-(halfBrushWidth),-(halfBrushHeight));
					HX_STACK_LINE(507)
					this->_matrix->rotate((bakedAngle * ((Float(::Math_obj::PI) / Float((int)180)))));
					HX_STACK_LINE(511)
					this->_matrix->translate((((max * column) + midpointX) + column),(midpointY + row));
					HX_STACK_LINE(513)
					hx::AddEq(bakedAngle,this->bakedRotation);
					HX_STACK_LINE(514)
					this->_pixels->draw(brush,this->_matrix,null(),null(),null(),AntiAliasing);
					HX_STACK_LINE(515)
					(column)++;
				}
				HX_STACK_LINE(517)
				hx::AddEq(midpointY,max);
				HX_STACK_LINE(518)
				(row)++;
			}
		}
		HX_STACK_LINE(521)
		this->frameWidth = this->frameHeight = max;
		HX_STACK_LINE(522)
		this->width = this->height = max;
		HX_STACK_LINE(523)
		this->resetHelpers();
		HX_STACK_LINE(524)
		if ((AutoBuffer)){
			HX_STACK_LINE(526)
			this->width = brush->get_width();
			HX_STACK_LINE(527)
			this->height = brush->get_height();
			HX_STACK_LINE(528)
			this->centerOffsets(null());
		}
		HX_STACK_LINE(532)
		this->set_antialiasing(AntiAliasing);
		HX_STACK_LINE(535)
		this->updateAtlasInfo(null());
		HX_STACK_LINE(537)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC6(FlxSprite_obj,loadRotatedGraphic,return )

::org::flixel::FlxSprite FlxSprite_obj::loadGraphic( Dynamic Graphic,hx::Null< bool >  __o_Animated,hx::Null< bool >  __o_Reverse,hx::Null< int >  __o_Width,hx::Null< int >  __o_Height,hx::Null< bool >  __o_Unique,::String Key){
bool Animated = __o_Animated.Default(false);
bool Reverse = __o_Reverse.Default(false);
int Width = __o_Width.Default(0);
int Height = __o_Height.Default(0);
bool Unique = __o_Unique.Default(false);
	HX_STACK_PUSH("FlxSprite::loadGraphic","org/flixel/FlxSprite.hx",335);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Graphic,"Graphic");
	HX_STACK_ARG(Animated,"Animated");
	HX_STACK_ARG(Reverse,"Reverse");
	HX_STACK_ARG(Width,"Width");
	HX_STACK_ARG(Height,"Height");
	HX_STACK_ARG(Unique,"Unique");
	HX_STACK_ARG(Key,"Key");
{
		HX_STACK_LINE(336)
		this->bakedRotation = (int)0;
		HX_STACK_LINE(338)
		this->_pixels = ::org::flixel::FlxG_obj::addBitmap(Graphic,false,Unique,Key,null(),null());
		HX_STACK_LINE(339)
		this->_bitmapDataKey = ::org::flixel::FlxG_obj::_lastBitmapDataKey;
		HX_STACK_LINE(341)
		this->_calculatedPixelsIndex = (int)-1;
		HX_STACK_LINE(346)
		if ((Reverse)){
			HX_STACK_LINE(347)
			this->_flipped = (int(this->_pixels->get_width()) >> int((int)1));
		}
		else{
			HX_STACK_LINE(351)
			this->_flipped = (int)0;
		}
		HX_STACK_LINE(354)
		if (((Width == (int)0))){
			HX_STACK_LINE(355)
			if ((Animated)){
				HX_STACK_LINE(357)
				Width = this->_pixels->get_height();
			}
			else{
				HX_STACK_LINE(360)
				if (((this->_flipped > (int)0))){
					HX_STACK_LINE(361)
					Width = this->_pixels->get_width();
				}
				else{
					HX_STACK_LINE(369)
					Width = this->_pixels->get_width();
				}
			}
		}
		HX_STACK_LINE(373)
		this->width = this->frameWidth = Width;
		HX_STACK_LINE(374)
		if (((Height == (int)0))){
			HX_STACK_LINE(375)
			if ((Animated)){
				HX_STACK_LINE(377)
				Height = ::Std_obj::_int(this->width);
			}
			else{
				HX_STACK_LINE(381)
				Height = this->_pixels->get_height();
			}
		}
		HX_STACK_LINE(387)
		if (((bool((Key != null())) && bool(((bool((Width != (int)0)) || bool((Height != (int)0)))))))){
			HX_STACK_LINE(388)
			hx::AddEq(Key,(((HX_CSTRING("FrameSize:") + Width) + HX_CSTRING("_")) + Height));
		}
		HX_STACK_LINE(391)
		this->_pixels = ::org::flixel::FlxG_obj::addBitmap(Graphic,false,Unique,Key,Width,Height);
		HX_STACK_LINE(392)
		this->_bitmapDataKey = ::org::flixel::FlxG_obj::_lastBitmapDataKey;
		HX_STACK_LINE(395)
		this->height = this->frameHeight = Height;
		HX_STACK_LINE(396)
		this->resetHelpers();
		HX_STACK_LINE(397)
		this->updateAtlasInfo(null());
		HX_STACK_LINE(398)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC7(FlxSprite_obj,loadGraphic,return )

Void FlxSprite_obj::destroy( ){
{
		HX_STACK_PUSH("FlxSprite::destroy","org/flixel/FlxSprite.hx",285);
		HX_STACK_THIS(this);
		HX_STACK_LINE(286)
		if (((this->_animations != null()))){
			HX_STACK_LINE(288)
			for(::cpp::FastIterator_obj< ::org::flixel::system::FlxAnim > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::FlxAnim >(this->_animations->iterator());  __it->hasNext(); ){
				::org::flixel::system::FlxAnim anim = __it->next();
				if (((anim != null()))){
					HX_STACK_LINE(291)
					anim->destroy();
				}
;
			}
			HX_STACK_LINE(295)
			this->_animations = null();
		}
		HX_STACK_LINE(298)
		this->_flashPoint = null();
		HX_STACK_LINE(299)
		this->_flashRect = null();
		HX_STACK_LINE(300)
		this->_flashRect2 = null();
		HX_STACK_LINE(301)
		this->_flashPointZero = null();
		HX_STACK_LINE(302)
		this->offset = null();
		HX_STACK_LINE(303)
		this->origin = null();
		HX_STACK_LINE(304)
		this->scale = null();
		HX_STACK_LINE(305)
		this->_curAnim = null();
		HX_STACK_LINE(306)
		this->_matrix = null();
		HX_STACK_LINE(307)
		this->_callback = null();
		HX_STACK_LINE(308)
		this->_colorTransform = null();
		HX_STACK_LINE(309)
		if (((this->framePixels != null()))){
			HX_STACK_LINE(310)
			this->framePixels->dispose();
		}
		HX_STACK_LINE(313)
		this->framePixels = null();
		HX_STACK_LINE(317)
		this->_blend = null();
		HX_STACK_LINE(319)
		this->super::destroy();
	}
return null();
}


int FlxSprite_obj::get_flipped( ){
	HX_STACK_PUSH("FlxSprite::get_flipped","org/flixel/FlxSprite.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_LINE(55)
	return this->_flipped;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_flipped,return )


FlxSprite_obj::FlxSprite_obj()
{
}

void FlxSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxSprite);
	HX_MARK_MEMBER_NAME(blend,"blend");
	HX_MARK_MEMBER_NAME(simpleRender,"simpleRender");
	HX_MARK_MEMBER_NAME(bakedRotation,"bakedRotation");
	HX_MARK_MEMBER_NAME(antialiasing,"antialiasing");
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(pixels,"pixels");
	HX_MARK_MEMBER_NAME(_additionalAngle,"_additionalAngle");
	HX_MARK_MEMBER_NAME(_halfHeight,"_halfHeight");
	HX_MARK_MEMBER_NAME(_halfWidth,"_halfWidth");
	HX_MARK_MEMBER_NAME(_blue,"_blue");
	HX_MARK_MEMBER_NAME(_green,"_green");
	HX_MARK_MEMBER_NAME(_red,"_red");
	HX_MARK_MEMBER_NAME(_frameID,"_frameID");
	HX_MARK_MEMBER_NAME(filters,"filters");
	HX_MARK_MEMBER_NAME(_matrix,"_matrix");
	HX_MARK_MEMBER_NAME(_useColorTransform,"_useColorTransform");
	HX_MARK_MEMBER_NAME(_colorTransform,"_colorTransform");
	HX_MARK_MEMBER_NAME(_flashPointZero,"_flashPointZero");
	HX_MARK_MEMBER_NAME(_flashRect2,"_flashRect2");
	HX_MARK_MEMBER_NAME(_flashRect,"_flashRect");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(_pixels,"_pixels");
	HX_MARK_MEMBER_NAME(_color,"_color");
	HX_MARK_MEMBER_NAME(_callback,"_callback");
	HX_MARK_MEMBER_NAME(_frameTimer,"_frameTimer");
	HX_MARK_MEMBER_NAME(_curIndex,"_curIndex");
	HX_MARK_MEMBER_NAME(_curFrame,"_curFrame");
	HX_MARK_MEMBER_NAME(_curAnim,"_curAnim");
	HX_MARK_MEMBER_NAME(_animations,"_animations");
	HX_MARK_MEMBER_NAME(dirty,"dirty");
	HX_MARK_MEMBER_NAME(framePixels,"framePixels");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(frameHeight,"frameHeight");
	HX_MARK_MEMBER_NAME(frameWidth,"frameWidth");
	HX_MARK_MEMBER_NAME(paused,"paused");
	HX_MARK_MEMBER_NAME(finished,"finished");
	HX_MARK_MEMBER_NAME(_calculatedPixelsFacing,"_calculatedPixelsFacing");
	HX_MARK_MEMBER_NAME(_calculatedPixelsIndex,"_calculatedPixelsIndex");
	HX_MARK_MEMBER_NAME(_blendInt,"_blendInt");
	HX_MARK_MEMBER_NAME(_blend,"_blend");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(origin,"origin");
	HX_MARK_MEMBER_NAME(curAnim,"curAnim");
	HX_MARK_MEMBER_NAME(_flipped,"_flipped");
	HX_MARK_MEMBER_NAME(flipped,"flipped");
	HX_MARK_MEMBER_NAME(frame,"frame");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(facing,"facing");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(blend,"blend");
	HX_VISIT_MEMBER_NAME(simpleRender,"simpleRender");
	HX_VISIT_MEMBER_NAME(bakedRotation,"bakedRotation");
	HX_VISIT_MEMBER_NAME(antialiasing,"antialiasing");
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(pixels,"pixels");
	HX_VISIT_MEMBER_NAME(_additionalAngle,"_additionalAngle");
	HX_VISIT_MEMBER_NAME(_halfHeight,"_halfHeight");
	HX_VISIT_MEMBER_NAME(_halfWidth,"_halfWidth");
	HX_VISIT_MEMBER_NAME(_blue,"_blue");
	HX_VISIT_MEMBER_NAME(_green,"_green");
	HX_VISIT_MEMBER_NAME(_red,"_red");
	HX_VISIT_MEMBER_NAME(_frameID,"_frameID");
	HX_VISIT_MEMBER_NAME(filters,"filters");
	HX_VISIT_MEMBER_NAME(_matrix,"_matrix");
	HX_VISIT_MEMBER_NAME(_useColorTransform,"_useColorTransform");
	HX_VISIT_MEMBER_NAME(_colorTransform,"_colorTransform");
	HX_VISIT_MEMBER_NAME(_flashPointZero,"_flashPointZero");
	HX_VISIT_MEMBER_NAME(_flashRect2,"_flashRect2");
	HX_VISIT_MEMBER_NAME(_flashRect,"_flashRect");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(_pixels,"_pixels");
	HX_VISIT_MEMBER_NAME(_color,"_color");
	HX_VISIT_MEMBER_NAME(_callback,"_callback");
	HX_VISIT_MEMBER_NAME(_frameTimer,"_frameTimer");
	HX_VISIT_MEMBER_NAME(_curIndex,"_curIndex");
	HX_VISIT_MEMBER_NAME(_curFrame,"_curFrame");
	HX_VISIT_MEMBER_NAME(_curAnim,"_curAnim");
	HX_VISIT_MEMBER_NAME(_animations,"_animations");
	HX_VISIT_MEMBER_NAME(dirty,"dirty");
	HX_VISIT_MEMBER_NAME(framePixels,"framePixels");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(frameHeight,"frameHeight");
	HX_VISIT_MEMBER_NAME(frameWidth,"frameWidth");
	HX_VISIT_MEMBER_NAME(paused,"paused");
	HX_VISIT_MEMBER_NAME(finished,"finished");
	HX_VISIT_MEMBER_NAME(_calculatedPixelsFacing,"_calculatedPixelsFacing");
	HX_VISIT_MEMBER_NAME(_calculatedPixelsIndex,"_calculatedPixelsIndex");
	HX_VISIT_MEMBER_NAME(_blendInt,"_blendInt");
	HX_VISIT_MEMBER_NAME(_blend,"_blend");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(origin,"origin");
	HX_VISIT_MEMBER_NAME(curAnim,"curAnim");
	HX_VISIT_MEMBER_NAME(_flipped,"_flipped");
	HX_VISIT_MEMBER_NAME(flipped,"flipped");
	HX_VISIT_MEMBER_NAME(frame,"frame");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(facing,"facing");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"fill") ) { return fill_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"_red") ) { return _red; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"blend") ) { return inCallProp ? get_blend() : blend; }
		if (HX_FIELD_EQ(inName,"alpha") ) { return alpha; }
		if (HX_FIELD_EQ(inName,"stamp") ) { return stamp_dyn(); }
		if (HX_FIELD_EQ(inName,"_blue") ) { return _blue; }
		if (HX_FIELD_EQ(inName,"dirty") ) { return dirty; }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		if (HX_FIELD_EQ(inName,"frame") ) { return inCallProp ? get_frame() : frame; }
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { return inCallProp ? get_pixels() : pixels; }
		if (HX_FIELD_EQ(inName,"_green") ) { return _green; }
		if (HX_FIELD_EQ(inName,"_color") ) { return _color; }
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"paused") ) { return paused; }
		if (HX_FIELD_EQ(inName,"_blend") ) { return _blend; }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		if (HX_FIELD_EQ(inName,"origin") ) { return origin; }
		if (HX_FIELD_EQ(inName,"facing") ) { return facing; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"filters") ) { return filters; }
		if (HX_FIELD_EQ(inName,"_matrix") ) { return _matrix; }
		if (HX_FIELD_EQ(inName,"_pixels") ) { return _pixels; }
		if (HX_FIELD_EQ(inName,"curAnim") ) { return inCallProp ? get_curAnim() : curAnim; }
		if (HX_FIELD_EQ(inName,"flipped") ) { return inCallProp ? get_flipped() : flipped; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onScreen") ) { return onScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"drawLine") ) { return drawLine_dyn(); }
		if (HX_FIELD_EQ(inName,"_frameID") ) { return _frameID; }
		if (HX_FIELD_EQ(inName,"_curAnim") ) { return _curAnim; }
		if (HX_FIELD_EQ(inName,"finished") ) { return finished; }
		if (HX_FIELD_EQ(inName,"_flipped") ) { return _flipped; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_blend") ) { return set_blend_dyn(); }
		if (HX_FIELD_EQ(inName,"get_blend") ) { return get_blend_dyn(); }
		if (HX_FIELD_EQ(inName,"addFilter") ) { return addFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"calcFrame") ) { return calcFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"set_frame") ) { return set_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"get_frame") ) { return get_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"drawFrame") ) { return drawFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"isColored") ) { return isColored_dyn(); }
		if (HX_FIELD_EQ(inName,"_callback") ) { return _callback; }
		if (HX_FIELD_EQ(inName,"_curIndex") ) { return _curIndex; }
		if (HX_FIELD_EQ(inName,"_curFrame") ) { return _curFrame; }
		if (HX_FIELD_EQ(inName,"_blendInt") ) { return _blendInt; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_facing") ) { return set_facing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pixels") ) { return set_pixels_dyn(); }
		if (HX_FIELD_EQ(inName,"get_pixels") ) { return get_pixels_dyn(); }
		if (HX_FIELD_EQ(inName,"postUpdate") ) { return postUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"_halfWidth") ) { return _halfWidth; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { return _flashRect; }
		if (HX_FIELD_EQ(inName,"frameWidth") ) { return frameWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setClipping") ) { return setClipping_dyn(); }
		if (HX_FIELD_EQ(inName,"set_curAnim") ) { return set_curAnim_dyn(); }
		if (HX_FIELD_EQ(inName,"get_curAnim") ) { return get_curAnim_dyn(); }
		if (HX_FIELD_EQ(inName,"randomFrame") ) { return randomFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"makeGraphic") ) { return makeGraphic_dyn(); }
		if (HX_FIELD_EQ(inName,"loadGraphic") ) { return loadGraphic_dyn(); }
		if (HX_FIELD_EQ(inName,"_halfHeight") ) { return _halfHeight; }
		if (HX_FIELD_EQ(inName,"_flashRect2") ) { return _flashRect2; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		if (HX_FIELD_EQ(inName,"_frameTimer") ) { return _frameTimer; }
		if (HX_FIELD_EQ(inName,"_animations") ) { return _animations; }
		if (HX_FIELD_EQ(inName,"framePixels") ) { return framePixels; }
		if (HX_FIELD_EQ(inName,"frameHeight") ) { return frameHeight; }
		if (HX_FIELD_EQ(inName,"get_flipped") ) { return get_flipped_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"simpleRender") ) { return inCallProp ? get_simpleRender() : simpleRender; }
		if (HX_FIELD_EQ(inName,"antialiasing") ) { return antialiasing; }
		if (HX_FIELD_EQ(inName,"removeFilter") ) { return removeFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"replaceColor") ) { return replaceColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnimation") ) { return getAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"addAnimation") ) { return addAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"resetHelpers") ) { return resetHelpers_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"overlapsPoint") ) { return overlapsPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"bakedRotation") ) { return bakedRotation; }
		if (HX_FIELD_EQ(inName,"centerOffsets") ) { return centerOffsets_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onScreenSprite") ) { return onScreenSprite_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAnimation") ) { return updateAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"_colorTransform") ) { return _colorTransform; }
		if (HX_FIELD_EQ(inName,"_flashPointZero") ) { return _flashPointZero; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_simpleRender") ) { return get_simpleRender_dyn(); }
		if (HX_FIELD_EQ(inName,"set_antialiasing") ) { return set_antialiasing_dyn(); }
		if (HX_FIELD_EQ(inName,"removeAllFilters") ) { return removeAllFilters_dyn(); }
		if (HX_FIELD_EQ(inName,"_additionalAngle") ) { return _additionalAngle; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setOriginToCorner") ) { return setOriginToCorner_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"simpleRenderSprite") ) { return simpleRenderSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"pixelsOverlapPoint") ) { return pixelsOverlapPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"loadRotatedGraphic") ) { return loadRotatedGraphic_dyn(); }
		if (HX_FIELD_EQ(inName,"_useColorTransform") ) { return _useColorTransform; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"addAnimationCallback") ) { return addAnimationCallback_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_calculatedPixelsIndex") ) { return _calculatedPixelsIndex; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_calculatedPixelsFacing") ) { return _calculatedPixelsFacing; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_red") ) { _red=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"blend") ) { if (inCallProp) return set_blend(inValue);blend=inValue.Cast< ::native::display::BlendMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return set_alpha(inValue);alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_blue") ) { _blue=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dirty") ) { dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { if (inCallProp) return set_frame(inValue);frame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { if (inCallProp) return set_color(inValue);color=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { if (inCallProp) return set_pixels(inValue);pixels=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_green") ) { _green=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_color") ) { _color=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_blend") ) { _blend=inValue.Cast< ::native::display::BlendMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"origin") ) { origin=inValue.Cast< ::org::flixel::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"facing") ) { if (inCallProp) return set_facing(inValue);facing=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { filters=inValue.Cast< Array< ::native::filters::BitmapFilter > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_matrix") ) { _matrix=inValue.Cast< ::native::geom::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pixels") ) { _pixels=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curAnim") ) { if (inCallProp) return set_curAnim(inValue);curAnim=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flipped") ) { flipped=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_frameID") ) { _frameID=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curAnim") ) { _curAnim=inValue.Cast< ::org::flixel::system::FlxAnim >(); return inValue; }
		if (HX_FIELD_EQ(inName,"finished") ) { finished=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flipped") ) { _flipped=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_callback") ) { _callback=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curIndex") ) { _curIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curFrame") ) { _curFrame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_blendInt") ) { _blendInt=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_halfWidth") ) { _halfWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { _flashRect=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameWidth") ) { frameWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_halfHeight") ) { _halfHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect2") ) { _flashRect2=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_frameTimer") ) { _frameTimer=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_animations") ) { _animations=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"framePixels") ) { framePixels=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameHeight") ) { frameHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"simpleRender") ) { simpleRender=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"antialiasing") ) { if (inCallProp) return set_antialiasing(inValue);antialiasing=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bakedRotation") ) { bakedRotation=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_colorTransform") ) { _colorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashPointZero") ) { _flashPointZero=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_additionalAngle") ) { _additionalAngle=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_useColorTransform") ) { _useColorTransform=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_calculatedPixelsIndex") ) { _calculatedPixelsIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_calculatedPixelsFacing") ) { _calculatedPixelsFacing=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("blend"));
	outFields->push(HX_CSTRING("simpleRender"));
	outFields->push(HX_CSTRING("bakedRotation"));
	outFields->push(HX_CSTRING("antialiasing"));
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("pixels"));
	outFields->push(HX_CSTRING("_additionalAngle"));
	outFields->push(HX_CSTRING("_halfHeight"));
	outFields->push(HX_CSTRING("_halfWidth"));
	outFields->push(HX_CSTRING("_blue"));
	outFields->push(HX_CSTRING("_green"));
	outFields->push(HX_CSTRING("_red"));
	outFields->push(HX_CSTRING("_frameID"));
	outFields->push(HX_CSTRING("filters"));
	outFields->push(HX_CSTRING("_matrix"));
	outFields->push(HX_CSTRING("_useColorTransform"));
	outFields->push(HX_CSTRING("_colorTransform"));
	outFields->push(HX_CSTRING("_flashPointZero"));
	outFields->push(HX_CSTRING("_flashRect2"));
	outFields->push(HX_CSTRING("_flashRect"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("_pixels"));
	outFields->push(HX_CSTRING("_color"));
	outFields->push(HX_CSTRING("_frameTimer"));
	outFields->push(HX_CSTRING("_curIndex"));
	outFields->push(HX_CSTRING("_curFrame"));
	outFields->push(HX_CSTRING("_curAnim"));
	outFields->push(HX_CSTRING("_animations"));
	outFields->push(HX_CSTRING("dirty"));
	outFields->push(HX_CSTRING("framePixels"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("frameHeight"));
	outFields->push(HX_CSTRING("frameWidth"));
	outFields->push(HX_CSTRING("paused"));
	outFields->push(HX_CSTRING("finished"));
	outFields->push(HX_CSTRING("_calculatedPixelsFacing"));
	outFields->push(HX_CSTRING("_calculatedPixelsIndex"));
	outFields->push(HX_CSTRING("_blendInt"));
	outFields->push(HX_CSTRING("_blend"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("origin"));
	outFields->push(HX_CSTRING("curAnim"));
	outFields->push(HX_CSTRING("_flipped"));
	outFields->push(HX_CSTRING("flipped"));
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("facing"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("overlapsPoint"),
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("set_blend"),
	HX_CSTRING("get_blend"),
	HX_CSTRING("blend"),
	HX_CSTRING("simpleRenderSprite"),
	HX_CSTRING("get_simpleRender"),
	HX_CSTRING("simpleRender"),
	HX_CSTRING("bakedRotation"),
	HX_CSTRING("set_antialiasing"),
	HX_CSTRING("antialiasing"),
	HX_CSTRING("removeAllFilters"),
	HX_CSTRING("removeFilter"),
	HX_CSTRING("setClipping"),
	HX_CSTRING("addFilter"),
	HX_CSTRING("calcFrame"),
	HX_CSTRING("pixelsOverlapPoint"),
	HX_CSTRING("onScreenSprite"),
	HX_CSTRING("onScreen"),
	HX_CSTRING("set_curAnim"),
	HX_CSTRING("get_curAnim"),
	HX_CSTRING("set_frame"),
	HX_CSTRING("get_frame"),
	HX_CSTRING("set_color"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_alpha"),
	HX_CSTRING("alpha"),
	HX_CSTRING("set_facing"),
	HX_CSTRING("set_pixels"),
	HX_CSTRING("get_pixels"),
	HX_CSTRING("pixels"),
	HX_CSTRING("replaceColor"),
	HX_CSTRING("centerOffsets"),
	HX_CSTRING("setOriginToCorner"),
	HX_CSTRING("randomFrame"),
	HX_CSTRING("getAnimation"),
	HX_CSTRING("play"),
	HX_CSTRING("addAnimationCallback"),
	HX_CSTRING("addAnimation"),
	HX_CSTRING("drawFrame"),
	HX_CSTRING("updateAnimation"),
	HX_CSTRING("fill"),
	HX_CSTRING("drawLine"),
	HX_CSTRING("stamp"),
	HX_CSTRING("draw"),
	HX_CSTRING("isColored"),
	HX_CSTRING("postUpdate"),
	HX_CSTRING("resetHelpers"),
	HX_CSTRING("makeGraphic"),
	HX_CSTRING("loadRotatedGraphic"),
	HX_CSTRING("loadGraphic"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_additionalAngle"),
	HX_CSTRING("_halfHeight"),
	HX_CSTRING("_halfWidth"),
	HX_CSTRING("_blue"),
	HX_CSTRING("_green"),
	HX_CSTRING("_red"),
	HX_CSTRING("_frameID"),
	HX_CSTRING("filters"),
	HX_CSTRING("_matrix"),
	HX_CSTRING("_useColorTransform"),
	HX_CSTRING("_colorTransform"),
	HX_CSTRING("_flashPointZero"),
	HX_CSTRING("_flashRect2"),
	HX_CSTRING("_flashRect"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("_pixels"),
	HX_CSTRING("_color"),
	HX_CSTRING("_callback"),
	HX_CSTRING("_frameTimer"),
	HX_CSTRING("_curIndex"),
	HX_CSTRING("_curFrame"),
	HX_CSTRING("_curAnim"),
	HX_CSTRING("_animations"),
	HX_CSTRING("dirty"),
	HX_CSTRING("framePixels"),
	HX_CSTRING("frames"),
	HX_CSTRING("frameHeight"),
	HX_CSTRING("frameWidth"),
	HX_CSTRING("paused"),
	HX_CSTRING("finished"),
	HX_CSTRING("_calculatedPixelsFacing"),
	HX_CSTRING("_calculatedPixelsIndex"),
	HX_CSTRING("_blendInt"),
	HX_CSTRING("_blend"),
	HX_CSTRING("scale"),
	HX_CSTRING("offset"),
	HX_CSTRING("origin"),
	HX_CSTRING("curAnim"),
	HX_CSTRING("get_flipped"),
	HX_CSTRING("_flipped"),
	HX_CSTRING("flipped"),
	HX_CSTRING("frame"),
	HX_CSTRING("color"),
	HX_CSTRING("facing"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxSprite_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxSprite_obj::__mClass,"__mClass");
};

Class FlxSprite_obj::__mClass;

void FlxSprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxSprite"), hx::TCanCast< FlxSprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxSprite_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
