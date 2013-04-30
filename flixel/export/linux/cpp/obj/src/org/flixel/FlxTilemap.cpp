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
#ifndef INCLUDED_ValueType
#include <ValueType.h>
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
#ifndef INCLUDED_org_flixel_FlxObject
#include <org/flixel/FlxObject.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPath
#include <org/flixel/FlxPath.h>
#endif
#ifndef INCLUDED_org_flixel_FlxPoint
#include <org/flixel/FlxPoint.h>
#endif
#ifndef INCLUDED_org_flixel_FlxRect
#include <org/flixel/FlxRect.h>
#endif
#ifndef INCLUDED_org_flixel_FlxSprite
#include <org/flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTilemap
#include <org/flixel/FlxTilemap.h>
#endif
#ifndef INCLUDED_org_flixel_FlxTypedGroup
#include <org/flixel/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_org_flixel_FlxU
#include <org/flixel/FlxU.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxTile
#include <org/flixel/system/FlxTile.h>
#endif
#ifndef INCLUDED_org_flixel_system_FlxTilemapBuffer
#include <org/flixel/system/FlxTilemapBuffer.h>
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

Void FlxTilemap_obj::__construct()
{
HX_STACK_PUSH("FlxTilemap::new","org/flixel/FlxTilemap.hx",142);
{
	HX_STACK_LINE(143)
	super::__construct(null(),null(),null(),null());
	HX_STACK_LINE(144)
	this->_auto = (int)0;
	HX_STACK_LINE(145)
	this->widthInTiles = (int)0;
	HX_STACK_LINE(146)
	this->heightInTiles = (int)0;
	HX_STACK_LINE(147)
	this->totalTiles = (int)0;
	HX_STACK_LINE(148)
	this->_buffers = Array_obj< ::org::flixel::system::FlxTilemapBuffer >::__new();
	HX_STACK_LINE(149)
	this->_flashPoint = ::native::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(150)
	this->_flashRect = null();
	HX_STACK_LINE(151)
	this->_data = null();
	HX_STACK_LINE(152)
	this->_tileWidth = (int)0;
	HX_STACK_LINE(153)
	this->_tileHeight = (int)0;
	HX_STACK_LINE(160)
	this->_rectIDs = null();
	HX_STACK_LINE(162)
	this->_tiles = null();
	HX_STACK_LINE(163)
	this->_tileObjects = null();
	HX_STACK_LINE(164)
	this->immovable = true;
	HX_STACK_LINE(165)
	this->moves = false;
	HX_STACK_LINE(166)
	this->cameras = null();
	HX_STACK_LINE(173)
	this->_lastVisualDebug = ::org::flixel::FlxG_obj::visualDebug;
	HX_STACK_LINE(175)
	this->_startingIndex = (int)0;
	HX_STACK_LINE(178)
	this->_helperPoint = ::native::geom::Point_obj::__new(null(),null());
}
;
	return null();
}

FlxTilemap_obj::~FlxTilemap_obj() { }

Dynamic FlxTilemap_obj::__CreateEmpty() { return  new FlxTilemap_obj; }
hx::ObjectPtr< FlxTilemap_obj > FlxTilemap_obj::__new()
{  hx::ObjectPtr< FlxTilemap_obj > result = new FlxTilemap_obj();
	result->__construct();
	return result;}

Dynamic FlxTilemap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTilemap_obj > result = new FlxTilemap_obj();
	result->__construct();
	return result;}

::org::flixel::FlxSprite FlxTilemap_obj::tileToFlxSprite( int X,int Y,hx::Null< int >  __o_NewTile){
int NewTile = __o_NewTile.Default(0);
	HX_STACK_PUSH("FlxTilemap::tileToFlxSprite","org/flixel/FlxTilemap.hx",1999);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_ARG(NewTile,"NewTile");
{
		HX_STACK_LINE(2000)
		int rowIndex = (X + (Y * this->widthInTiles));		HX_STACK_VAR(rowIndex,"rowIndex");
		HX_STACK_LINE(2002)
		::native::geom::Rectangle rect = null();		HX_STACK_VAR(rect,"rect");
		HX_STACK_LINE(2006)
		::org::flixel::system::FlxTile tile = this->_tileObjects->__get(this->_data->__get(rowIndex));		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(2007)
		if (((bool((tile == null())) || bool(!(tile->visible))))){
		}
		else{
			HX_STACK_LINE(2013)
			int rx = (((this->_data->__get(rowIndex) - this->_startingIndex)) * this->_tileWidth);		HX_STACK_VAR(rx,"rx");
			HX_STACK_LINE(2014)
			int ry = (int)0;		HX_STACK_VAR(ry,"ry");
			HX_STACK_LINE(2015)
			if (((::Std_obj::_int(rx) >= this->_tiles->get_width()))){
				HX_STACK_LINE(2017)
				ry = (::Std_obj::_int((Float(rx) / Float(this->_tiles->get_width()))) * this->_tileHeight);
				HX_STACK_LINE(2018)
				hx::ModEq(rx,this->_tiles->get_width());
			}
			HX_STACK_LINE(2020)
			rect = ::native::geom::Rectangle_obj::__new(rx,ry,this->_tileWidth,this->_tileHeight);
		}
		HX_STACK_LINE(2024)
		::native::geom::Point pt = ::native::geom::Point_obj::__new((int)0,(int)0);		HX_STACK_VAR(pt,"pt");
		HX_STACK_LINE(2025)
		::org::flixel::FlxSprite tileSprite = ::org::flixel::FlxSprite_obj::__new(null(),null(),null());		HX_STACK_VAR(tileSprite,"tileSprite");
		HX_STACK_LINE(2026)
		tileSprite->makeGraphic(this->_tileWidth,this->_tileHeight,(int)0,true,null());
		HX_STACK_LINE(2027)
		tileSprite->x = ((X * this->_tileWidth) + this->x);
		HX_STACK_LINE(2028)
		tileSprite->y = ((Y * this->_tileHeight) + this->y);
		HX_STACK_LINE(2029)
		if (((rect != null()))){
			HX_STACK_LINE(2029)
			tileSprite->get_pixels()->copyPixels(this->_tiles,rect,pt,null(),null(),null());
		}
		HX_STACK_LINE(2030)
		tileSprite->dirty = true;
		HX_STACK_LINE(2031)
		tileSprite->updateFrameData();
		HX_STACK_LINE(2033)
		if (((NewTile >= (int)0))){
			HX_STACK_LINE(2033)
			this->setTile(X,Y,NewTile,null());
		}
		HX_STACK_LINE(2035)
		return tileSprite;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,tileToFlxSprite,return )

Void FlxTilemap_obj::updateFrameData( ){
{
		HX_STACK_PUSH("FlxTilemap::updateFrameData","org/flixel/FlxTilemap.hx",1973);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1973)
		if (((bool((bool((this->_node != null())) && bool((this->_tileWidth >= (int)1)))) && bool((this->_tileHeight >= (int)1))))){
			HX_STACK_LINE(1977)
			this->_framesData = this->_node->addSpriteFramesData(this->_tileWidth,this->_tileHeight,::native::geom::Point_obj::__new((int)0,(int)0),(int)0,(int)0,(int)0,(int)0,(int)1,(int)1);
			HX_STACK_LINE(1979)
			this->_rectIDs = Array_obj< int >::__new();
			HX_STACK_LINE(1980)
			::org::flixel::FlxU_obj::SetArrayLength(this->_rectIDs,this->totalTiles);
			HX_STACK_LINE(1981)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1982)
			while(((i < this->totalTiles))){
				HX_STACK_LINE(1983)
				this->updateTile((i)++);
			}
		}
	}
return null();
}


Void FlxTilemap_obj::updateTile( int Index){
{
		HX_STACK_PUSH("FlxTilemap::updateTile","org/flixel/FlxTilemap.hx",1943);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Index,"Index");
		HX_STACK_LINE(1944)
		::org::flixel::system::FlxTile tile = this->_tileObjects->__get(this->_data->__get(Index));		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(1945)
		if (((bool((tile == null())) || bool(!(tile->visible))))){
			HX_STACK_LINE(1950)
			this->_rectIDs[Index] = (int)-1;
			HX_STACK_LINE(1952)
			return null();
		}
		HX_STACK_LINE(1964)
		this->_rectIDs[Index] = this->_framesData->frameIDs->__get((this->_data->__get(Index) - this->_startingIndex));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,updateTile,(void))

Void FlxTilemap_obj::autoTile( int Index){
{
		HX_STACK_PUSH("FlxTilemap::autoTile","org/flixel/FlxTilemap.hx",1909);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Index,"Index");
		HX_STACK_LINE(1910)
		if (((this->_data->__get(Index) == (int)0))){
			HX_STACK_LINE(1911)
			return null();
		}
		HX_STACK_LINE(1915)
		this->_data[Index] = (int)0;
		HX_STACK_LINE(1916)
		if (((bool(((Index - this->widthInTiles) < (int)0)) || bool((this->_data->__get((Index - this->widthInTiles)) > (int)0))))){
			HX_STACK_LINE(1917)
			hx::AddEq(this->_data[Index],(int)1);
		}
		HX_STACK_LINE(1918)
		if (((bool((hx::Mod(Index,this->widthInTiles) >= (this->widthInTiles - (int)1))) || bool((this->_data->__get((Index + (int)1)) > (int)0))))){
			HX_STACK_LINE(1919)
			hx::AddEq(this->_data[Index],(int)2);
		}
		HX_STACK_LINE(1920)
		if (((bool((::Std_obj::_int((Index + this->widthInTiles)) >= this->totalTiles)) || bool((this->_data->__get((Index + this->widthInTiles)) > (int)0))))){
			HX_STACK_LINE(1921)
			hx::AddEq(this->_data[Index],(int)4);
		}
		HX_STACK_LINE(1922)
		if (((bool((hx::Mod(Index,this->widthInTiles) <= (int)0)) || bool((this->_data->__get((Index - (int)1)) > (int)0))))){
			HX_STACK_LINE(1923)
			hx::AddEq(this->_data[Index],(int)8);
		}
		HX_STACK_LINE(1924)
		if (((bool((this->_auto == (int)2)) && bool((this->_data->__get(Index) == (int)15))))){
			HX_STACK_LINE(1926)
			if (((bool((bool((hx::Mod(Index,this->widthInTiles) > (int)0)) && bool((::Std_obj::_int((Index + this->widthInTiles)) < this->totalTiles)))) && bool((this->_data->__get(((Index + this->widthInTiles) - (int)1)) <= (int)0))))){
				HX_STACK_LINE(1927)
				this->_data[Index] = (int)1;
			}
			HX_STACK_LINE(1928)
			if (((bool((bool((hx::Mod(Index,this->widthInTiles) > (int)0)) && bool(((Index - this->widthInTiles) >= (int)0)))) && bool((this->_data->__get(((Index - this->widthInTiles) - (int)1)) <= (int)0))))){
				HX_STACK_LINE(1929)
				this->_data[Index] = (int)2;
			}
			HX_STACK_LINE(1930)
			if (((bool((bool((hx::Mod(Index,this->widthInTiles) < (this->widthInTiles - (int)1))) && bool(((Index - this->widthInTiles) >= (int)0)))) && bool((this->_data->__get(((Index - this->widthInTiles) + (int)1)) <= (int)0))))){
				HX_STACK_LINE(1931)
				this->_data[Index] = (int)4;
			}
			HX_STACK_LINE(1932)
			if (((bool((bool((hx::Mod(Index,this->widthInTiles) < (this->widthInTiles - (int)1))) && bool((::Std_obj::_int((Index + this->widthInTiles)) < this->totalTiles)))) && bool((this->_data->__get(((Index + this->widthInTiles) + (int)1)) <= (int)0))))){
				HX_STACK_LINE(1933)
				this->_data[Index] = (int)8;
			}
		}
		HX_STACK_LINE(1935)
		hx::AddEq(this->_data[Index],(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,autoTile,(void))

::org::flixel::FlxPoint FlxTilemap_obj::rayHit( ::org::flixel::FlxPoint Start,::org::flixel::FlxPoint End,hx::Null< Float >  __o_Resolution){
Float Resolution = __o_Resolution.Default(1);
	HX_STACK_PUSH("FlxTilemap::rayHit","org/flixel/FlxTilemap.hx",1636);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Start,"Start");
	HX_STACK_ARG(End,"End");
	HX_STACK_ARG(Resolution,"Resolution");
{
		HX_STACK_LINE(1637)
		::org::flixel::FlxPoint Result = null();		HX_STACK_VAR(Result,"Result");
		HX_STACK_LINE(1638)
		Float step = this->_tileWidth;		HX_STACK_VAR(step,"step");
		HX_STACK_LINE(1639)
		if (((this->_tileHeight < this->_tileWidth))){
			HX_STACK_LINE(1640)
			step = this->_tileHeight;
		}
		HX_STACK_LINE(1643)
		hx::DivEq(step,Resolution);
		HX_STACK_LINE(1644)
		Float deltaX = (End->x - Start->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(1645)
		Float deltaY = (End->y - Start->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(1646)
		Float distance = ::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY)));		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(1647)
		int steps = ::Math_obj::ceil((Float(distance) / Float(step)));		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(1648)
		Float stepX = (Float(deltaX) / Float(steps));		HX_STACK_VAR(stepX,"stepX");
		HX_STACK_LINE(1649)
		Float stepY = (Float(deltaY) / Float(steps));		HX_STACK_VAR(stepY,"stepY");
		HX_STACK_LINE(1650)
		Float curX = ((Start->x - stepX) - this->x);		HX_STACK_VAR(curX,"curX");
		HX_STACK_LINE(1651)
		Float curY = ((Start->y - stepY) - this->y);		HX_STACK_VAR(curY,"curY");
		HX_STACK_LINE(1652)
		int tileX;		HX_STACK_VAR(tileX,"tileX");
		HX_STACK_LINE(1653)
		int tileY;		HX_STACK_VAR(tileY,"tileY");
		HX_STACK_LINE(1654)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1655)
		while(((i < steps))){
			HX_STACK_LINE(1657)
			hx::AddEq(curX,stepX);
			HX_STACK_LINE(1658)
			hx::AddEq(curY,stepY);
			HX_STACK_LINE(1660)
			if (((bool((bool((bool((curX < (int)0)) || bool((curX > this->width)))) || bool((curY < (int)0)))) || bool((curY > this->height))))){
				HX_STACK_LINE(1662)
				(i)++;
				HX_STACK_LINE(1663)
				continue;
			}
			HX_STACK_LINE(1666)
			tileX = ::Math_obj::floor((Float(curX) / Float(this->_tileWidth)));
			HX_STACK_LINE(1667)
			tileY = ::Math_obj::floor((Float(curY) / Float(this->_tileHeight)));
			HX_STACK_LINE(1668)
			if (((this->_tileObjects->__get(this->_data->__get(((tileY * this->widthInTiles) + tileX)))->allowCollisions != (int)0))){
				HX_STACK_LINE(1671)
				hx::MultEq(tileX,this->_tileWidth);
				HX_STACK_LINE(1672)
				hx::MultEq(tileY,this->_tileHeight);
				HX_STACK_LINE(1673)
				Float rx = (int)0;		HX_STACK_VAR(rx,"rx");
				HX_STACK_LINE(1674)
				Float ry = (int)0;		HX_STACK_VAR(ry,"ry");
				HX_STACK_LINE(1675)
				Float q;		HX_STACK_VAR(q,"q");
				HX_STACK_LINE(1676)
				Float lx = (curX - stepX);		HX_STACK_VAR(lx,"lx");
				HX_STACK_LINE(1677)
				Float ly = (curY - stepY);		HX_STACK_VAR(ly,"ly");
				HX_STACK_LINE(1680)
				q = tileX;
				HX_STACK_LINE(1681)
				if (((deltaX < (int)0))){
					HX_STACK_LINE(1682)
					hx::AddEq(q,this->_tileWidth);
				}
				HX_STACK_LINE(1685)
				rx = q;
				HX_STACK_LINE(1686)
				ry = (ly + (stepY * ((Float(((q - lx))) / Float(stepX)))));
				HX_STACK_LINE(1687)
				if (((bool((ry > tileY)) && bool((ry < (tileY + this->_tileHeight)))))){
					HX_STACK_LINE(1689)
					if (((Result == null()))){
						HX_STACK_LINE(1690)
						Result = ::org::flixel::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(1693)
					Result->x = rx;
					HX_STACK_LINE(1694)
					Result->y = ry;
					HX_STACK_LINE(1695)
					return Result;
				}
				HX_STACK_LINE(1699)
				q = tileY;
				HX_STACK_LINE(1700)
				if (((deltaY < (int)0))){
					HX_STACK_LINE(1701)
					hx::AddEq(q,this->_tileHeight);
				}
				HX_STACK_LINE(1704)
				rx = (lx + (stepX * ((Float(((q - ly))) / Float(stepY)))));
				HX_STACK_LINE(1705)
				ry = q;
				HX_STACK_LINE(1706)
				if (((bool((rx > tileX)) && bool((rx < (tileX + this->_tileWidth)))))){
					HX_STACK_LINE(1708)
					if (((Result == null()))){
						HX_STACK_LINE(1709)
						Result = ::org::flixel::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(1712)
					Result->x = rx;
					HX_STACK_LINE(1713)
					Result->y = ry;
					HX_STACK_LINE(1714)
					return Result;
				}
				HX_STACK_LINE(1716)
				return null();
			}
			HX_STACK_LINE(1718)
			(i)++;
		}
		HX_STACK_LINE(1720)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,rayHit,return )

bool FlxTilemap_obj::ray( ::org::flixel::FlxPoint Start,::org::flixel::FlxPoint End,::org::flixel::FlxPoint Result,hx::Null< Float >  __o_Resolution){
Float Resolution = __o_Resolution.Default(1);
	HX_STACK_PUSH("FlxTilemap::ray","org/flixel/FlxTilemap.hx",1537);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Start,"Start");
	HX_STACK_ARG(End,"End");
	HX_STACK_ARG(Result,"Result");
	HX_STACK_ARG(Resolution,"Resolution");
{
		HX_STACK_LINE(1538)
		Float step = this->_tileWidth;		HX_STACK_VAR(step,"step");
		HX_STACK_LINE(1539)
		if (((this->_tileHeight < this->_tileWidth))){
			HX_STACK_LINE(1540)
			step = this->_tileHeight;
		}
		HX_STACK_LINE(1543)
		hx::DivEq(step,Resolution);
		HX_STACK_LINE(1544)
		Float deltaX = (End->x - Start->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(1545)
		Float deltaY = (End->y - Start->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(1546)
		Float distance = ::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY)));		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(1547)
		int steps = ::Math_obj::ceil((Float(distance) / Float(step)));		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(1548)
		Float stepX = (Float(deltaX) / Float(steps));		HX_STACK_VAR(stepX,"stepX");
		HX_STACK_LINE(1549)
		Float stepY = (Float(deltaY) / Float(steps));		HX_STACK_VAR(stepY,"stepY");
		HX_STACK_LINE(1550)
		Float curX = ((Start->x - stepX) - this->x);		HX_STACK_VAR(curX,"curX");
		HX_STACK_LINE(1551)
		Float curY = ((Start->y - stepY) - this->y);		HX_STACK_VAR(curY,"curY");
		HX_STACK_LINE(1552)
		int tileX;		HX_STACK_VAR(tileX,"tileX");
		HX_STACK_LINE(1553)
		int tileY;		HX_STACK_VAR(tileY,"tileY");
		HX_STACK_LINE(1554)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1555)
		while(((i < steps))){
			HX_STACK_LINE(1557)
			hx::AddEq(curX,stepX);
			HX_STACK_LINE(1558)
			hx::AddEq(curY,stepY);
			HX_STACK_LINE(1560)
			if (((bool((bool((bool((curX < (int)0)) || bool((curX > this->width)))) || bool((curY < (int)0)))) || bool((curY > this->height))))){
				HX_STACK_LINE(1562)
				(i)++;
				HX_STACK_LINE(1563)
				continue;
			}
			HX_STACK_LINE(1566)
			tileX = ::Math_obj::floor((Float(curX) / Float(this->_tileWidth)));
			HX_STACK_LINE(1567)
			tileY = ::Math_obj::floor((Float(curY) / Float(this->_tileHeight)));
			HX_STACK_LINE(1568)
			if (((this->_tileObjects->__get(this->_data->__get(((tileY * this->widthInTiles) + tileX)))->allowCollisions != (int)0))){
				HX_STACK_LINE(1571)
				hx::MultEq(tileX,this->_tileWidth);
				HX_STACK_LINE(1572)
				hx::MultEq(tileY,this->_tileHeight);
				HX_STACK_LINE(1573)
				Float rx = (int)0;		HX_STACK_VAR(rx,"rx");
				HX_STACK_LINE(1574)
				Float ry = (int)0;		HX_STACK_VAR(ry,"ry");
				HX_STACK_LINE(1575)
				Float q;		HX_STACK_VAR(q,"q");
				HX_STACK_LINE(1576)
				Float lx = (curX - stepX);		HX_STACK_VAR(lx,"lx");
				HX_STACK_LINE(1577)
				Float ly = (curY - stepY);		HX_STACK_VAR(ly,"ly");
				HX_STACK_LINE(1580)
				q = tileX;
				HX_STACK_LINE(1581)
				if (((deltaX < (int)0))){
					HX_STACK_LINE(1582)
					hx::AddEq(q,this->_tileWidth);
				}
				HX_STACK_LINE(1585)
				rx = q;
				HX_STACK_LINE(1586)
				ry = (ly + (stepY * ((Float(((q - lx))) / Float(stepX)))));
				HX_STACK_LINE(1587)
				if (((bool((ry > tileY)) && bool((ry < (tileY + this->_tileHeight)))))){
					HX_STACK_LINE(1589)
					if (((Result != null()))){
						HX_STACK_LINE(1591)
						Result->x = rx;
						HX_STACK_LINE(1592)
						Result->y = ry;
					}
					HX_STACK_LINE(1594)
					return false;
				}
				HX_STACK_LINE(1598)
				q = tileY;
				HX_STACK_LINE(1599)
				if (((deltaY < (int)0))){
					HX_STACK_LINE(1600)
					hx::AddEq(q,this->_tileHeight);
				}
				HX_STACK_LINE(1603)
				rx = (lx + (stepX * ((Float(((q - ly))) / Float(stepY)))));
				HX_STACK_LINE(1604)
				ry = q;
				HX_STACK_LINE(1605)
				if (((bool((rx > tileX)) && bool((rx < (tileX + this->_tileWidth)))))){
					HX_STACK_LINE(1607)
					if (((Result != null()))){
						HX_STACK_LINE(1609)
						Result->x = rx;
						HX_STACK_LINE(1610)
						Result->y = ry;
					}
					HX_STACK_LINE(1612)
					return false;
				}
				HX_STACK_LINE(1614)
				return true;
			}
			HX_STACK_LINE(1616)
			(i)++;
		}
		HX_STACK_LINE(1618)
		return true;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,ray,return )

::org::flixel::FlxRect FlxTilemap_obj::getBounds( ::org::flixel::FlxRect Bounds){
	HX_STACK_PUSH("FlxTilemap::getBounds","org/flixel/FlxTilemap.hx",1519);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Bounds,"Bounds");
	HX_STACK_LINE(1520)
	if (((Bounds == null()))){
		HX_STACK_LINE(1521)
		Bounds = ::org::flixel::FlxRect_obj::__new(null(),null(),null(),null());
	}
	struct _Function_1_1{
		inline static ::org::flixel::FlxRect Block( ::org::flixel::FlxRect &Bounds,::org::flixel::FlxTilemap_obj *__this){
			HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1524);
			{
				HX_STACK_LINE(1524)
				Bounds->x = __this->x;
				HX_STACK_LINE(1524)
				Bounds->y = __this->y;
				HX_STACK_LINE(1524)
				Bounds->width = __this->width;
				HX_STACK_LINE(1524)
				Bounds->height = __this->height;
				HX_STACK_LINE(1524)
				return Bounds;
			}
			return null();
		}
	};
	HX_STACK_LINE(1524)
	return _Function_1_1::Block(Bounds,this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getBounds,return )

Void FlxTilemap_obj::follow( ::org::flixel::FlxCamera Camera,hx::Null< int >  __o_Border,hx::Null< bool >  __o_UpdateWorld){
int Border = __o_Border.Default(0);
bool UpdateWorld = __o_UpdateWorld.Default(true);
	HX_STACK_PUSH("FlxTilemap::follow","org/flixel/FlxTilemap.hx",1505);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Camera,"Camera");
	HX_STACK_ARG(Border,"Border");
	HX_STACK_ARG(UpdateWorld,"UpdateWorld");
{
		HX_STACK_LINE(1506)
		if (((Camera == null()))){
			HX_STACK_LINE(1507)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1510)
		Camera->setBounds((this->x + (Border * this->_tileWidth)),(this->y + (Border * this->_tileHeight)),(this->width - ((Border * this->_tileWidth) * (int)2)),(this->height - ((Border * this->_tileHeight) * (int)2)),UpdateWorld);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,follow,(void))

Void FlxTilemap_obj::setTileProperties( int Tile,hx::Null< int >  __o_AllowCollisions,Dynamic Callback,::Class CallbackFilter,hx::Null< int >  __o_Range){
int AllowCollisions = __o_AllowCollisions.Default(4369);
int Range = __o_Range.Default(1);
	HX_STACK_PUSH("FlxTilemap::setTileProperties","org/flixel/FlxTilemap.hx",1481);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Tile,"Tile");
	HX_STACK_ARG(AllowCollisions,"AllowCollisions");
	HX_STACK_ARG(Callback,"Callback");
	HX_STACK_ARG(CallbackFilter,"CallbackFilter");
	HX_STACK_ARG(Range,"Range");
{
		HX_STACK_LINE(1482)
		if (((Range <= (int)0))){
			HX_STACK_LINE(1483)
			Range = (int)1;
		}
		HX_STACK_LINE(1486)
		::org::flixel::system::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(1487)
		int i = Tile;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1488)
		int l = (Tile + Range);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1489)
		while(((i < l))){
			HX_STACK_LINE(1491)
			tile = this->_tileObjects->__get((i)++);
			HX_STACK_LINE(1492)
			tile->allowCollisions = AllowCollisions;
			HX_STACK_LINE(1493)
			tile->callbackFunction = Callback;
			HX_STACK_LINE(1494)
			tile->filter = CallbackFilter;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxTilemap_obj,setTileProperties,(void))

bool FlxTilemap_obj::setTileByIndex( int Index,int Tile,hx::Null< bool >  __o_UpdateGraphics){
bool UpdateGraphics = __o_UpdateGraphics.Default(true);
	HX_STACK_PUSH("FlxTilemap::setTileByIndex","org/flixel/FlxTilemap.hx",1424);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Index,"Index");
	HX_STACK_ARG(Tile,"Tile");
	HX_STACK_ARG(UpdateGraphics,"UpdateGraphics");
{
		HX_STACK_LINE(1425)
		if (((Index >= this->_data->length))){
			HX_STACK_LINE(1426)
			return false;
		}
		HX_STACK_LINE(1430)
		bool ok = true;		HX_STACK_VAR(ok,"ok");
		HX_STACK_LINE(1431)
		this->_data[Index] = Tile;
		HX_STACK_LINE(1433)
		if ((!(UpdateGraphics))){
			HX_STACK_LINE(1434)
			return ok;
		}
		HX_STACK_LINE(1438)
		this->setDirty(null());
		HX_STACK_LINE(1440)
		if (((this->_auto == (int)0))){
			HX_STACK_LINE(1442)
			this->updateTile(Index);
			HX_STACK_LINE(1443)
			return ok;
		}
		HX_STACK_LINE(1447)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1448)
		int row = (::Std_obj::_int((Float(Index) / Float(this->widthInTiles))) - (int)1);		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1449)
		int rowLength = (row + (int)3);		HX_STACK_VAR(rowLength,"rowLength");
		HX_STACK_LINE(1450)
		int column = (hx::Mod(Index,this->widthInTiles) - (int)1);		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1451)
		int columnHeight = (column + (int)3);		HX_STACK_VAR(columnHeight,"columnHeight");
		HX_STACK_LINE(1452)
		while(((row < rowLength))){
			HX_STACK_LINE(1454)
			column = (columnHeight - (int)3);
			HX_STACK_LINE(1455)
			while(((column < columnHeight))){
				HX_STACK_LINE(1457)
				if (((bool((bool((bool((row >= (int)0)) && bool((row < this->heightInTiles)))) && bool((column >= (int)0)))) && bool((column < this->widthInTiles))))){
					HX_STACK_LINE(1459)
					i = ((row * this->widthInTiles) + column);
					HX_STACK_LINE(1460)
					this->autoTile(i);
					HX_STACK_LINE(1461)
					this->updateTile(i);
				}
				HX_STACK_LINE(1463)
				(column)++;
			}
			HX_STACK_LINE(1465)
			(row)++;
		}
		HX_STACK_LINE(1468)
		return ok;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,setTileByIndex,return )

bool FlxTilemap_obj::setTile( int X,int Y,int Tile,hx::Null< bool >  __o_UpdateGraphics){
bool UpdateGraphics = __o_UpdateGraphics.Default(true);
	HX_STACK_PUSH("FlxTilemap::setTile","org/flixel/FlxTilemap.hx",1408);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_ARG(Tile,"Tile");
	HX_STACK_ARG(UpdateGraphics,"UpdateGraphics");
{
		HX_STACK_LINE(1409)
		if (((bool((X >= this->widthInTiles)) || bool((Y >= this->heightInTiles))))){
			HX_STACK_LINE(1410)
			return false;
		}
		HX_STACK_LINE(1413)
		return this->setTileByIndex(((Y * this->widthInTiles) + X),Tile,UpdateGraphics);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,setTile,return )

Array< ::org::flixel::FlxPoint > FlxTilemap_obj::getTileCoords( int Index,hx::Null< bool >  __o_Midpoint){
bool Midpoint = __o_Midpoint.Default(true);
	HX_STACK_PUSH("FlxTilemap::getTileCoords","org/flixel/FlxTilemap.hx",1371);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Index,"Index");
	HX_STACK_ARG(Midpoint,"Midpoint");
{
		HX_STACK_LINE(1372)
		Array< ::org::flixel::FlxPoint > array = null();		HX_STACK_VAR(array,"array");
		HX_STACK_LINE(1374)
		::org::flixel::FlxPoint point;		HX_STACK_VAR(point,"point");
		HX_STACK_LINE(1375)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1376)
		int l = (this->widthInTiles * this->heightInTiles);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1377)
		while(((i < l))){
			HX_STACK_LINE(1379)
			if (((this->_data->__get(i) == Index))){
				HX_STACK_LINE(1381)
				point = ::org::flixel::FlxPoint_obj::__new((this->x + (::Std_obj::_int(hx::Mod(i,this->widthInTiles)) * this->_tileWidth)),(this->y + (::Std_obj::_int((Float(i) / Float(this->widthInTiles))) * this->_tileHeight)));
				HX_STACK_LINE(1382)
				if ((Midpoint)){
					HX_STACK_LINE(1384)
					hx::AddEq(point->x,(this->_tileWidth * 0.5));
					HX_STACK_LINE(1385)
					hx::AddEq(point->y,(this->_tileHeight * 0.5));
				}
				HX_STACK_LINE(1387)
				if (((array == null()))){
					HX_STACK_LINE(1388)
					array = Array_obj< ::org::flixel::FlxPoint >::__new();
				}
				HX_STACK_LINE(1391)
				array->push(point);
			}
			HX_STACK_LINE(1393)
			(i)++;
		}
		HX_STACK_LINE(1396)
		return array;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTilemap_obj,getTileCoords,return )

Array< int > FlxTilemap_obj::getTileInstances( int Index){
	HX_STACK_PUSH("FlxTilemap::getTileInstances","org/flixel/FlxTilemap.hx",1344);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Index,"Index");
	HX_STACK_LINE(1345)
	Array< int > array = null();		HX_STACK_VAR(array,"array");
	HX_STACK_LINE(1346)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1347)
	int l = (this->widthInTiles * this->heightInTiles);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1348)
	while(((i < l))){
		HX_STACK_LINE(1350)
		if (((this->_data->__get(i) == Index))){
			HX_STACK_LINE(1352)
			if (((array == null()))){
				HX_STACK_LINE(1353)
				array = Array_obj< int >::__new();
			}
			HX_STACK_LINE(1356)
			array->push(i);
		}
		HX_STACK_LINE(1358)
		(i)++;
	}
	HX_STACK_LINE(1361)
	return array;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getTileInstances,return )

int FlxTilemap_obj::getTileByIndex( int Index){
	HX_STACK_PUSH("FlxTilemap::getTileByIndex","org/flixel/FlxTilemap.hx",1334);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Index,"Index");
	HX_STACK_LINE(1334)
	return this->_data->__get(Index);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getTileByIndex,return )

int FlxTilemap_obj::getTile( int X,int Y){
	HX_STACK_PUSH("FlxTilemap::getTile","org/flixel/FlxTilemap.hx",1321);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_LINE(1321)
	return this->_data->__get(((Y * this->widthInTiles) + X));
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTilemap_obj,getTile,return )

bool FlxTilemap_obj::overlapsPoint( ::org::flixel::FlxPoint point,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxTilemap::overlapsPoint","org/flixel/FlxTilemap.hx",1298);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(1299)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(1300)
			return (this->_tileObjects->__get(this->_data->__get(::Math_obj::floor(((::Math_obj::floor((Float(((point->y - this->y))) / Float(this->_tileHeight))) * this->widthInTiles) + (Float(((point->x - this->x))) / Float(this->_tileWidth))))))->allowCollisions > (int)0);
		}
		HX_STACK_LINE(1304)
		if (((Camera == null()))){
			HX_STACK_LINE(1305)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1308)
		point->x = (point->x - Camera->scroll->x);
		HX_STACK_LINE(1309)
		point->y = (point->y - Camera->scroll->y);
		HX_STACK_LINE(1310)
		{
			HX_STACK_LINE(1310)
			::org::flixel::FlxPoint point1 = this->_point;		HX_STACK_VAR(point1,"point1");
			::org::flixel::FlxCamera Camera1 = Camera;		HX_STACK_VAR(Camera1,"Camera1");
			HX_STACK_LINE(1310)
			if (((point1 == null()))){
				HX_STACK_LINE(1310)
				point1 = ::org::flixel::FlxPoint_obj::__new(null(),null());
			}
			HX_STACK_LINE(1310)
			if (((Camera1 == null()))){
				HX_STACK_LINE(1310)
				Camera1 = ::org::flixel::FlxG_obj::camera;
			}
			HX_STACK_LINE(1310)
			point1->x = (this->x - (Camera1->scroll->x * this->scrollFactor->x));
			HX_STACK_LINE(1310)
			point1->y = (this->y - (Camera1->scroll->y * this->scrollFactor->y));
			HX_STACK_LINE(1310)
			point1;
		}
		HX_STACK_LINE(1311)
		return (this->_tileObjects->__get(this->_data->__get(::Std_obj::_int(((::Std_obj::_int((Float(((point->y - this->_point->y))) / Float(this->_tileHeight))) * this->widthInTiles) + (Float(((point->x - this->_point->x))) / Float(this->_tileWidth))))))->allowCollisions > (int)0);
	}
}


bool FlxTilemap_obj::overlapsWithCallback( ::org::flixel::FlxObject Object,Dynamic Callback,hx::Null< bool >  __o_FlipCallbackParams,::org::flixel::FlxPoint Position){
bool FlipCallbackParams = __o_FlipCallbackParams.Default(false);
	HX_STACK_PUSH("FlxTilemap::overlapsWithCallback","org/flixel/FlxTilemap.hx",1189);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Object,"Object");
	HX_STACK_ARG(Callback,"Callback");
	HX_STACK_ARG(FlipCallbackParams,"FlipCallbackParams");
	HX_STACK_ARG(Position,"Position");
{
		HX_STACK_LINE(1190)
		bool results = false;		HX_STACK_VAR(results,"results");
		HX_STACK_LINE(1192)
		Float X = this->x;		HX_STACK_VAR(X,"X");
		HX_STACK_LINE(1193)
		Float Y = this->y;		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(1194)
		if (((Position != null()))){
			HX_STACK_LINE(1196)
			X = Position->x;
			HX_STACK_LINE(1197)
			Y = Position->y;
		}
		struct _Function_1_1{
			inline static int Block( ::org::flixel::FlxObject &Object,::org::flixel::FlxTilemap_obj *__this,Float &X){
				HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1201);
				{
					HX_STACK_LINE(1201)
					Float Value = (Float(((Object->x - X))) / Float(__this->_tileWidth));		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(1201)
					int number = ::Std_obj::_int(Value);		HX_STACK_VAR(number,"number");
					HX_STACK_LINE(1201)
					return (  (((Value > (int)0))) ? int(number) : int((  (((number != Value))) ? int((number - (int)1)) : int(number) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1201)
		int selectionX = _Function_1_1::Block(Object,this,X);		HX_STACK_VAR(selectionX,"selectionX");
		struct _Function_1_2{
			inline static int Block( ::org::flixel::FlxObject &Object,Float &Y,::org::flixel::FlxTilemap_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1202);
				{
					HX_STACK_LINE(1202)
					Float Value = (Float(((Object->y - Y))) / Float(__this->_tileHeight));		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(1202)
					int number = ::Std_obj::_int(Value);		HX_STACK_VAR(number,"number");
					HX_STACK_LINE(1202)
					return (  (((Value > (int)0))) ? int(number) : int((  (((number != Value))) ? int((number - (int)1)) : int(number) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1202)
		int selectionY = _Function_1_2::Block(Object,Y,this);		HX_STACK_VAR(selectionY,"selectionY");
		struct _Function_1_3{
			inline static int Block( ::org::flixel::FlxObject &Object,::org::flixel::FlxTilemap_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1203);
				{
					HX_STACK_LINE(1203)
					Float Value = (Float(Object->width) / Float(__this->_tileWidth));		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(1203)
					int number = ::Std_obj::_int(Value);		HX_STACK_VAR(number,"number");
					struct _Function_2_1{
						inline static int Block( int &number,Float &Value){
							HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1203);
							{
								HX_STACK_LINE(1203)
								return (  (((number != Value))) ? int((number + (int)1)) : int(number) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1203)
					return (  (((Value > (int)0))) ? int(_Function_2_1::Block(number,Value)) : int(number) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1203)
		int selectionWidth = ((selectionX + _Function_1_3::Block(Object,this)) + (int)1);		HX_STACK_VAR(selectionWidth,"selectionWidth");
		struct _Function_1_4{
			inline static int Block( ::org::flixel::FlxObject &Object,::org::flixel::FlxTilemap_obj *__this){
				HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1204);
				{
					HX_STACK_LINE(1204)
					Float Value = (Float(Object->height) / Float(__this->_tileHeight));		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(1204)
					int number = ::Std_obj::_int(Value);		HX_STACK_VAR(number,"number");
					struct _Function_2_1{
						inline static int Block( int &number,Float &Value){
							HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1204);
							{
								HX_STACK_LINE(1204)
								return (  (((number != Value))) ? int((number + (int)1)) : int(number) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1204)
					return (  (((Value > (int)0))) ? int(_Function_2_1::Block(number,Value)) : int(number) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1204)
		int selectionHeight = ((selectionY + _Function_1_4::Block(Object,this)) + (int)1);		HX_STACK_VAR(selectionHeight,"selectionHeight");
		HX_STACK_LINE(1207)
		if (((selectionX < (int)0))){
			HX_STACK_LINE(1208)
			selectionX = (int)0;
		}
		HX_STACK_LINE(1211)
		if (((selectionY < (int)0))){
			HX_STACK_LINE(1212)
			selectionY = (int)0;
		}
		HX_STACK_LINE(1215)
		if (((selectionWidth > this->widthInTiles))){
			HX_STACK_LINE(1216)
			selectionWidth = this->widthInTiles;
		}
		HX_STACK_LINE(1219)
		if (((selectionHeight > this->heightInTiles))){
			HX_STACK_LINE(1220)
			selectionHeight = this->heightInTiles;
		}
		HX_STACK_LINE(1225)
		int rowStart = (selectionY * this->widthInTiles);		HX_STACK_VAR(rowStart,"rowStart");
		HX_STACK_LINE(1226)
		int row = selectionY;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1227)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1228)
		::org::flixel::system::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(1229)
		bool overlapFound;		HX_STACK_VAR(overlapFound,"overlapFound");
		HX_STACK_LINE(1230)
		Float deltaX = (X - this->last->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(1231)
		Float deltaY = (Y - this->last->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(1232)
		while(((row < selectionHeight))){
			HX_STACK_LINE(1234)
			column = selectionX;
			HX_STACK_LINE(1235)
			while(((column < selectionWidth))){
				HX_STACK_LINE(1237)
				overlapFound = false;
				HX_STACK_LINE(1238)
				int dataIndex = this->_data->__get((rowStart + column));		HX_STACK_VAR(dataIndex,"dataIndex");
				HX_STACK_LINE(1239)
				if (((dataIndex < (int)0))){
					HX_STACK_LINE(1241)
					(column)++;
					HX_STACK_LINE(1242)
					continue;
				}
				HX_STACK_LINE(1245)
				tile = this->_tileObjects->__get(dataIndex);
				HX_STACK_LINE(1246)
				if (((tile->allowCollisions != (int)0))){
					HX_STACK_LINE(1248)
					tile->x = (X + (column * this->_tileWidth));
					HX_STACK_LINE(1249)
					tile->y = (Y + (row * this->_tileHeight));
					HX_STACK_LINE(1250)
					tile->last->x = (tile->x - deltaX);
					HX_STACK_LINE(1251)
					tile->last->y = (tile->y - deltaY);
					HX_STACK_LINE(1252)
					if (((Callback != null()))){
						HX_STACK_LINE(1253)
						if ((FlipCallbackParams)){
							HX_STACK_LINE(1255)
							overlapFound = Callback(Object,tile).Cast< bool >();
						}
						else{
							HX_STACK_LINE(1259)
							overlapFound = Callback(tile,Object).Cast< bool >();
						}
					}
					else{
						HX_STACK_LINE(1264)
						overlapFound = (bool((bool((bool(((Object->x + Object->width) > tile->x)) && bool((Object->x < (tile->x + tile->width))))) && bool(((Object->y + Object->height) > tile->y)))) && bool((Object->y < (tile->y + tile->height))));
					}
					HX_STACK_LINE(1267)
					if ((overlapFound)){
						HX_STACK_LINE(1269)
						if (((bool((tile->callbackFunction_dyn() != null())) && bool(((bool((tile->filter == null())) || bool(::Std_obj::is(Object,tile->filter)))))))){
							HX_STACK_LINE(1271)
							tile->mapIndex = (rowStart + column);
							HX_STACK_LINE(1272)
							tile->callbackFunction(tile,Object);
						}
						HX_STACK_LINE(1274)
						results = true;
					}
				}
				else{
					HX_STACK_LINE(1277)
					if (((bool((tile->callbackFunction_dyn() != null())) && bool(((bool((tile->filter == null())) || bool(::Std_obj::is(Object,tile->filter)))))))){
						HX_STACK_LINE(1279)
						tile->mapIndex = (rowStart + column);
						HX_STACK_LINE(1280)
						tile->callbackFunction(tile,Object);
					}
				}
				HX_STACK_LINE(1282)
				(column)++;
			}
			HX_STACK_LINE(1284)
			hx::AddEq(rowStart,this->widthInTiles);
			HX_STACK_LINE(1285)
			(row)++;
		}
		HX_STACK_LINE(1287)
		return results;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,overlapsWithCallback,return )

bool FlxTilemap_obj::overlapsAt( Float X,Float Y,::org::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxTilemap::overlapsAt","org/flixel/FlxTilemap.hx",1136);
	HX_STACK_THIS(this);
	HX_STACK_ARG(X,"X");
	HX_STACK_ARG(Y,"Y");
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(1137)
		if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxTypedGroup >()))){
			HX_STACK_LINE(1139)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(1140)
			::org::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(1141)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1142)
			::org::flixel::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(1143)
			Array< ::org::flixel::FlxBasic > members = grp->members;		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(1144)
			while(((i < grp->length))){
				HX_STACK_LINE(1146)
				basic = members->__get((i)++);
				HX_STACK_LINE(1147)
				if (((bool((basic != null())) && bool(basic->exists)))){
					HX_STACK_LINE(1148)
					if ((::Std_obj::is(basic,hx::ClassOf< ::org::flixel::FlxObject >()))){
						HX_STACK_LINE(1151)
						this->_point->x = X;
						HX_STACK_LINE(1152)
						this->_point->y = Y;
						HX_STACK_LINE(1153)
						if ((this->overlapsWithCallback(hx::TCast< org::flixel::FlxObject >::cast(basic),null(),false,this->_point))){
							HX_STACK_LINE(1154)
							results = true;
						}
					}
					else{
						HX_STACK_LINE(1159)
						if ((this->overlapsAt(X,Y,basic,InScreenSpace,Camera))){
							HX_STACK_LINE(1161)
							results = true;
						}
					}
				}
			}
			HX_STACK_LINE(1167)
			return results;
		}
		else{
			HX_STACK_LINE(1169)
			if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxObject >()))){
				HX_STACK_LINE(1171)
				this->_point->x = X;
				HX_STACK_LINE(1172)
				this->_point->y = Y;
				HX_STACK_LINE(1173)
				return this->overlapsWithCallback(hx::TCast< org::flixel::FlxObject >::cast(ObjectOrGroup),null(),false,this->_point);
			}
		}
		HX_STACK_LINE(1175)
		return false;
	}
}


bool FlxTilemap_obj::overlaps( ::org::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::org::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_PUSH("FlxTilemap::overlaps","org/flixel/FlxTilemap.hx",1085);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup");
	HX_STACK_ARG(InScreenSpace,"InScreenSpace");
	HX_STACK_ARG(Camera,"Camera");
{
		HX_STACK_LINE(1086)
		if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxTypedGroup >()))){
			HX_STACK_LINE(1088)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(1089)
			::org::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(1090)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1091)
			::org::flixel::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(1092)
			Array< ::org::flixel::FlxBasic > members = grp->members;		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(1094)
			while(((i < grp->length))){
				HX_STACK_LINE(1096)
				basic = members->__get((i)++);
				HX_STACK_LINE(1097)
				if (((bool((basic != null())) && bool(basic->exists)))){
					HX_STACK_LINE(1098)
					if ((::Std_obj::is(basic,hx::ClassOf< ::org::flixel::FlxObject >()))){
						HX_STACK_LINE(1100)
						if ((this->overlapsWithCallback(hx::TCast< org::flixel::FlxObject >::cast(basic),null(),null(),null()))){
							HX_STACK_LINE(1102)
							results = true;
						}
					}
					else{
						HX_STACK_LINE(1107)
						if ((this->overlaps(basic,InScreenSpace,Camera))){
							HX_STACK_LINE(1109)
							results = true;
						}
					}
				}
			}
			HX_STACK_LINE(1115)
			return results;
		}
		else{
			HX_STACK_LINE(1117)
			if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::org::flixel::FlxObject >()))){
				HX_STACK_LINE(1118)
				return this->overlapsWithCallback(hx::TCast< org::flixel::FlxObject >::cast(ObjectOrGroup),null(),null(),null());
			}
		}
		HX_STACK_LINE(1121)
		return false;
	}
}


Void FlxTilemap_obj::walkPath( Array< int > Data,int Start,Array< ::org::flixel::FlxPoint > Points){
{
		HX_STACK_PUSH("FlxTilemap::walkPath","org/flixel/FlxTilemap.hx",994);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Data,"Data");
		HX_STACK_ARG(Start,"Start");
		HX_STACK_ARG(Points,"Points");
		HX_STACK_LINE(995)
		Points->push(::org::flixel::FlxPoint_obj::__new(((this->x + (::Math_obj::floor(hx::Mod(Start,this->widthInTiles)) * this->_tileWidth)) + (this->_tileWidth * 0.5)),((this->y + (::Math_obj::floor((Float(Start) / Float(this->widthInTiles))) * this->_tileHeight)) + (this->_tileHeight * 0.5))));
		HX_STACK_LINE(996)
		if (((Data->__get(Start) == (int)0))){
			HX_STACK_LINE(997)
			return null();
		}
		HX_STACK_LINE(1001)
		bool left = (hx::Mod(Start,this->widthInTiles) > (int)0);		HX_STACK_VAR(left,"left");
		HX_STACK_LINE(1002)
		bool right = (hx::Mod(Start,this->widthInTiles) < (this->widthInTiles - (int)1));		HX_STACK_VAR(right,"right");
		HX_STACK_LINE(1003)
		bool up = ((Float(Start) / Float(this->widthInTiles)) > (int)0);		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(1004)
		bool down = ((Float(Start) / Float(this->widthInTiles)) < (this->heightInTiles - (int)1));		HX_STACK_VAR(down,"down");
		HX_STACK_LINE(1006)
		int current = Data->__get(Start);		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(1007)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1008)
		if ((up)){
			HX_STACK_LINE(1010)
			i = (Start - this->widthInTiles);
			HX_STACK_LINE(1011)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1012)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1016)
		if ((right)){
			HX_STACK_LINE(1018)
			i = (Start + (int)1);
			HX_STACK_LINE(1019)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1020)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1024)
		if ((down)){
			HX_STACK_LINE(1026)
			i = (Start + this->widthInTiles);
			HX_STACK_LINE(1027)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1028)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1032)
		if ((left)){
			HX_STACK_LINE(1034)
			i = (Start - (int)1);
			HX_STACK_LINE(1035)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1036)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1040)
		if (((bool(up) && bool(right)))){
			HX_STACK_LINE(1042)
			i = ((Start - this->widthInTiles) + (int)1);
			HX_STACK_LINE(1043)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1044)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1048)
		if (((bool(right) && bool(down)))){
			HX_STACK_LINE(1050)
			i = ((Start + this->widthInTiles) + (int)1);
			HX_STACK_LINE(1051)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1052)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1056)
		if (((bool(left) && bool(down)))){
			HX_STACK_LINE(1058)
			i = ((Start + this->widthInTiles) - (int)1);
			HX_STACK_LINE(1059)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1060)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1064)
		if (((bool(up) && bool(left)))){
			HX_STACK_LINE(1066)
			i = ((Start - this->widthInTiles) - (int)1);
			HX_STACK_LINE(1067)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(1068)
				return this->walkPath(Data,i,Points);
			}
		}
		HX_STACK_LINE(1072)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,walkPath,(void))

Array< int > FlxTilemap_obj::computePathDistance( int StartIndex,int EndIndex,bool WideDiagonal){
	HX_STACK_PUSH("FlxTilemap::computePathDistance","org/flixel/FlxTilemap.hx",830);
	HX_STACK_THIS(this);
	HX_STACK_ARG(StartIndex,"StartIndex");
	HX_STACK_ARG(EndIndex,"EndIndex");
	HX_STACK_ARG(WideDiagonal,"WideDiagonal");
	HX_STACK_LINE(833)
	int mapSize = (this->widthInTiles * this->heightInTiles);		HX_STACK_VAR(mapSize,"mapSize");
	HX_STACK_LINE(834)
	Array< int > distances = Array_obj< int >::__new();		HX_STACK_VAR(distances,"distances");
	HX_STACK_LINE(835)
	::org::flixel::FlxU_obj::SetArrayLength(distances,mapSize);
	HX_STACK_LINE(836)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(837)
	while(((i < mapSize))){
		HX_STACK_LINE(839)
		if (((this->_tileObjects->__get(this->_data->__get(i))->allowCollisions != (int)0))){
			HX_STACK_LINE(840)
			distances[i] = (int)-2;
		}
		else{
			HX_STACK_LINE(844)
			distances[i] = (int)-1;
		}
		HX_STACK_LINE(847)
		(i)++;
	}
	HX_STACK_LINE(849)
	distances[StartIndex] = (int)0;
	HX_STACK_LINE(850)
	int distance = (int)1;		HX_STACK_VAR(distance,"distance");
	HX_STACK_LINE(851)
	Array< int > neighbors = Array_obj< int >::__new().Add(StartIndex);		HX_STACK_VAR(neighbors,"neighbors");
	HX_STACK_LINE(852)
	Array< int > current;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(853)
	int currentIndex;		HX_STACK_VAR(currentIndex,"currentIndex");
	HX_STACK_LINE(854)
	bool left;		HX_STACK_VAR(left,"left");
	HX_STACK_LINE(855)
	bool right;		HX_STACK_VAR(right,"right");
	HX_STACK_LINE(856)
	bool up;		HX_STACK_VAR(up,"up");
	HX_STACK_LINE(857)
	bool down;		HX_STACK_VAR(down,"down");
	HX_STACK_LINE(858)
	int currentLength;		HX_STACK_VAR(currentLength,"currentLength");
	HX_STACK_LINE(859)
	bool foundEnd = false;		HX_STACK_VAR(foundEnd,"foundEnd");
	HX_STACK_LINE(860)
	while(((neighbors->length > (int)0))){
		HX_STACK_LINE(862)
		current = neighbors;
		HX_STACK_LINE(863)
		neighbors = Array_obj< int >::__new();
		HX_STACK_LINE(865)
		i = (int)0;
		HX_STACK_LINE(866)
		currentLength = current->length;
		HX_STACK_LINE(867)
		while(((i < currentLength))){
			HX_STACK_LINE(869)
			currentIndex = current->__get((i)++);
			HX_STACK_LINE(870)
			if (((currentIndex == ::Std_obj::_int(EndIndex)))){
				HX_STACK_LINE(872)
				foundEnd = true;
				HX_STACK_LINE(874)
				neighbors = Array_obj< int >::__new();
				HX_STACK_LINE(875)
				break;
			}
			HX_STACK_LINE(879)
			left = (hx::Mod(currentIndex,this->widthInTiles) > (int)0);
			HX_STACK_LINE(880)
			right = (hx::Mod(currentIndex,this->widthInTiles) < (this->widthInTiles - (int)1));
			HX_STACK_LINE(881)
			up = ((Float(currentIndex) / Float(this->widthInTiles)) > (int)0);
			HX_STACK_LINE(882)
			down = ((Float(currentIndex) / Float(this->widthInTiles)) < (this->heightInTiles - (int)1));
			HX_STACK_LINE(884)
			int index;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(885)
			if ((up)){
				HX_STACK_LINE(887)
				index = (currentIndex - this->widthInTiles);
				HX_STACK_LINE(888)
				if (((distances->__get(index) == (int)-1))){
					HX_STACK_LINE(890)
					distances[index] = distance;
					HX_STACK_LINE(891)
					neighbors->push(index);
				}
			}
			HX_STACK_LINE(894)
			if ((right)){
				HX_STACK_LINE(896)
				index = (currentIndex + (int)1);
				HX_STACK_LINE(897)
				if (((distances->__get(index) == (int)-1))){
					HX_STACK_LINE(899)
					distances[index] = distance;
					HX_STACK_LINE(900)
					neighbors->push(index);
				}
			}
			HX_STACK_LINE(903)
			if ((down)){
				HX_STACK_LINE(905)
				index = (currentIndex + this->widthInTiles);
				HX_STACK_LINE(906)
				if (((distances->__get(index) == (int)-1))){
					HX_STACK_LINE(908)
					distances[index] = distance;
					HX_STACK_LINE(909)
					neighbors->push(index);
				}
			}
			HX_STACK_LINE(912)
			if ((left)){
				HX_STACK_LINE(914)
				index = (currentIndex - (int)1);
				HX_STACK_LINE(915)
				if (((distances->__get(index) == (int)-1))){
					HX_STACK_LINE(917)
					distances[index] = distance;
					HX_STACK_LINE(918)
					neighbors->push(index);
				}
			}
			HX_STACK_LINE(921)
			if (((bool(up) && bool(right)))){
				HX_STACK_LINE(923)
				index = ((currentIndex - this->widthInTiles) + (int)1);
				HX_STACK_LINE(924)
				if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex - this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex + (int)1)) >= (int)-1))))){
					HX_STACK_LINE(926)
					distances[index] = distance;
					HX_STACK_LINE(927)
					neighbors->push(index);
				}
				else{
					HX_STACK_LINE(929)
					if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
						HX_STACK_LINE(931)
						distances[index] = distance;
						HX_STACK_LINE(932)
						neighbors->push(index);
					}
				}
			}
			HX_STACK_LINE(935)
			if (((bool(right) && bool(down)))){
				HX_STACK_LINE(937)
				index = ((currentIndex + this->widthInTiles) + (int)1);
				HX_STACK_LINE(938)
				if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex + this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex + (int)1)) >= (int)-1))))){
					HX_STACK_LINE(940)
					distances[index] = distance;
					HX_STACK_LINE(941)
					neighbors->push(index);
				}
				else{
					HX_STACK_LINE(943)
					if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
						HX_STACK_LINE(945)
						distances[index] = distance;
						HX_STACK_LINE(946)
						neighbors->push(index);
					}
				}
			}
			HX_STACK_LINE(949)
			if (((bool(left) && bool(down)))){
				HX_STACK_LINE(951)
				index = ((currentIndex + this->widthInTiles) - (int)1);
				HX_STACK_LINE(952)
				if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex + this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex - (int)1)) >= (int)-1))))){
					HX_STACK_LINE(954)
					distances[index] = distance;
					HX_STACK_LINE(955)
					neighbors->push(index);
				}
				else{
					HX_STACK_LINE(957)
					if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
						HX_STACK_LINE(959)
						distances[index] = distance;
						HX_STACK_LINE(960)
						neighbors->push(index);
					}
				}
			}
			HX_STACK_LINE(963)
			if (((bool(up) && bool(left)))){
				HX_STACK_LINE(965)
				index = ((currentIndex - this->widthInTiles) - (int)1);
				HX_STACK_LINE(966)
				if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex - this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex - (int)1)) >= (int)-1))))){
					HX_STACK_LINE(968)
					distances[index] = distance;
					HX_STACK_LINE(969)
					neighbors->push(index);
				}
				else{
					HX_STACK_LINE(971)
					if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
						HX_STACK_LINE(973)
						distances[index] = distance;
						HX_STACK_LINE(974)
						neighbors->push(index);
					}
				}
			}
		}
		HX_STACK_LINE(978)
		(distance)++;
	}
	HX_STACK_LINE(980)
	if ((!(foundEnd))){
		HX_STACK_LINE(981)
		distances = null();
	}
	HX_STACK_LINE(984)
	return distances;
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,computePathDistance,return )

Void FlxTilemap_obj::raySimplifyPath( Array< ::org::flixel::FlxPoint > Points){
{
		HX_STACK_PUSH("FlxTilemap::raySimplifyPath","org/flixel/FlxTilemap.hx",793);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Points,"Points");
		HX_STACK_LINE(794)
		::org::flixel::FlxPoint source = Points->__get((int)0);		HX_STACK_VAR(source,"source");
		HX_STACK_LINE(795)
		int lastIndex = (int)-1;		HX_STACK_VAR(lastIndex,"lastIndex");
		HX_STACK_LINE(796)
		::org::flixel::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(797)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(798)
		int l = Points->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(799)
		while(((i < l))){
			HX_STACK_LINE(801)
			node = Points->__get((i)++);
			HX_STACK_LINE(802)
			if (((node == null()))){
				HX_STACK_LINE(803)
				continue;
			}
			HX_STACK_LINE(806)
			if ((this->ray(source,node,this->_point,null()))){
				HX_STACK_LINE(807)
				if (((lastIndex >= (int)0))){
					HX_STACK_LINE(809)
					Points[lastIndex] = null();
				}
			}
			else{
				HX_STACK_LINE(814)
				source = Points->__get(lastIndex);
			}
			HX_STACK_LINE(817)
			lastIndex = (i - (int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,raySimplifyPath,(void))

Void FlxTilemap_obj::simplifyPath( Array< ::org::flixel::FlxPoint > Points){
{
		HX_STACK_PUSH("FlxTilemap::simplifyPath","org/flixel/FlxTilemap.hx",764);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Points,"Points");
		HX_STACK_LINE(765)
		Float deltaPrevious;		HX_STACK_VAR(deltaPrevious,"deltaPrevious");
		HX_STACK_LINE(766)
		Float deltaNext;		HX_STACK_VAR(deltaNext,"deltaNext");
		HX_STACK_LINE(767)
		::org::flixel::FlxPoint last = Points->__get((int)0);		HX_STACK_VAR(last,"last");
		HX_STACK_LINE(768)
		::org::flixel::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(769)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(770)
		int l = (Points->length - (int)1);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(771)
		while(((i < l))){
			HX_STACK_LINE(773)
			node = Points->__get(i);
			HX_STACK_LINE(774)
			deltaPrevious = (Float(((node->x - last->x))) / Float(((node->y - last->y))));
			HX_STACK_LINE(775)
			deltaNext = (Float(((node->x - Points->__get((i + (int)1))->x))) / Float(((node->y - Points->__get((i + (int)1))->y))));
			HX_STACK_LINE(776)
			if (((bool((bool((last->x == Points->__get((i + (int)1))->x)) || bool((last->y == Points->__get((i + (int)1))->y)))) || bool((deltaPrevious == deltaNext))))){
				HX_STACK_LINE(777)
				Points[i] = null();
			}
			else{
				HX_STACK_LINE(781)
				last = node;
			}
			HX_STACK_LINE(784)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,simplifyPath,(void))

::org::flixel::FlxPath FlxTilemap_obj::findPath( ::org::flixel::FlxPoint Start,::org::flixel::FlxPoint End,hx::Null< bool >  __o_Simplify,hx::Null< bool >  __o_RaySimplify,hx::Null< bool >  __o_WideDiagonal){
bool Simplify = __o_Simplify.Default(true);
bool RaySimplify = __o_RaySimplify.Default(false);
bool WideDiagonal = __o_WideDiagonal.Default(true);
	HX_STACK_PUSH("FlxTilemap::findPath","org/flixel/FlxTilemap.hx",703);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Start,"Start");
	HX_STACK_ARG(End,"End");
	HX_STACK_ARG(Simplify,"Simplify");
	HX_STACK_ARG(RaySimplify,"RaySimplify");
	HX_STACK_ARG(WideDiagonal,"WideDiagonal");
{
		HX_STACK_LINE(705)
		int startIndex = ((::Std_obj::_int((Float(((Start->y - this->y))) / Float(this->_tileHeight))) * this->widthInTiles) + ::Std_obj::_int((Float(((Start->x - this->x))) / Float(this->_tileWidth))));		HX_STACK_VAR(startIndex,"startIndex");
		HX_STACK_LINE(706)
		int endIndex = ((::Std_obj::_int((Float(((End->y - this->y))) / Float(this->_tileHeight))) * this->widthInTiles) + ::Std_obj::_int((Float(((End->x - this->x))) / Float(this->_tileWidth))));		HX_STACK_VAR(endIndex,"endIndex");
		HX_STACK_LINE(709)
		if (((bool((this->_tileObjects->__get(this->_data->__get(startIndex))->allowCollisions > (int)0)) || bool((this->_tileObjects->__get(this->_data->__get(endIndex))->allowCollisions > (int)0))))){
			HX_STACK_LINE(711)
			return null();
		}
		HX_STACK_LINE(716)
		Array< int > distances = this->computePathDistance(startIndex,endIndex,WideDiagonal);		HX_STACK_VAR(distances,"distances");
		HX_STACK_LINE(717)
		if (((distances == null()))){
			HX_STACK_LINE(718)
			return null();
		}
		HX_STACK_LINE(723)
		Array< ::org::flixel::FlxPoint > points = Array_obj< ::org::flixel::FlxPoint >::__new();		HX_STACK_VAR(points,"points");
		HX_STACK_LINE(724)
		this->walkPath(distances,endIndex,points);
		HX_STACK_LINE(727)
		::org::flixel::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(728)
		node = points->__get((points->length - (int)1));
		HX_STACK_LINE(729)
		node->x = Start->x;
		HX_STACK_LINE(730)
		node->y = Start->y;
		HX_STACK_LINE(731)
		node = points->__get((int)0);
		HX_STACK_LINE(732)
		node->x = End->x;
		HX_STACK_LINE(733)
		node->y = End->y;
		HX_STACK_LINE(736)
		if ((Simplify)){
			HX_STACK_LINE(737)
			this->simplifyPath(points);
		}
		HX_STACK_LINE(740)
		if ((RaySimplify)){
			HX_STACK_LINE(741)
			this->raySimplifyPath(points);
		}
		HX_STACK_LINE(746)
		::org::flixel::FlxPath path = ::org::flixel::FlxPath_obj::__new(null());		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(747)
		int i = (points->length - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(748)
		while(((i >= (int)0))){
			HX_STACK_LINE(750)
			node = points->__get((i)--);
			HX_STACK_LINE(751)
			if (((node != null()))){
				HX_STACK_LINE(752)
				path->addPoint(node,true);
			}
		}
		HX_STACK_LINE(756)
		return path;
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxTilemap_obj,findPath,return )

Void FlxTilemap_obj::setDirty( hx::Null< bool >  __o_Dirty){
bool Dirty = __o_Dirty.Default(true);
	HX_STACK_PUSH("FlxTilemap::setDirty","org/flixel/FlxTilemap.hx",683);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Dirty,"Dirty");
{
		HX_STACK_LINE(684)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(685)
		int l = this->_buffers->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(686)
		while(((i < l))){
			HX_STACK_LINE(687)
			this->_buffers->__get((i)++)->dirty = Dirty;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,setDirty,(void))

Array< int > FlxTilemap_obj::getData( hx::Null< bool >  __o_Simple){
bool Simple = __o_Simple.Default(false);
	HX_STACK_PUSH("FlxTilemap::getData","org/flixel/FlxTilemap.hx",659);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Simple,"Simple");
{
		HX_STACK_LINE(660)
		if ((!(Simple))){
			HX_STACK_LINE(661)
			return this->_data;
		}
		HX_STACK_LINE(665)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(666)
		int l = this->_data->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(667)
		Array< int > data = Array_obj< int >::__new();		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(668)
		::org::flixel::FlxU_obj::SetArrayLength(data,l);
		HX_STACK_LINE(669)
		while(((i < l))){
			HX_STACK_LINE(671)
			data[i] = (  (((this->_tileObjects->__get(this->_data->__get(i))->allowCollisions > (int)0))) ? int((int)1) : int((int)0) );
			HX_STACK_LINE(672)
			(i)++;
		}
		HX_STACK_LINE(674)
		return data;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getData,return )

Void FlxTilemap_obj::draw( ){
{
		HX_STACK_PUSH("FlxTilemap::draw","org/flixel/FlxTilemap.hx",600);
		HX_STACK_THIS(this);
		HX_STACK_LINE(601)
		if (((this->_flickerTimer != (int)0))){
			HX_STACK_LINE(603)
			this->_flicker = !(this->_flicker);
			HX_STACK_LINE(604)
			if ((this->_flicker)){
				HX_STACK_LINE(605)
				return null();
			}
		}
		HX_STACK_LINE(610)
		if (((this->cameras == null()))){
			HX_STACK_LINE(611)
			this->cameras = ::org::flixel::FlxG_obj::cameras;
		}
		HX_STACK_LINE(614)
		::org::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(615)
		::org::flixel::system::FlxTilemapBuffer buffer;		HX_STACK_VAR(buffer,"buffer");
		HX_STACK_LINE(616)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(617)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(618)
		while(((i < l))){
			HX_STACK_LINE(620)
			camera = this->cameras->__get(i);
			HX_STACK_LINE(621)
			if (((bool(!(camera->visible)) || bool(!(camera->exists))))){
				HX_STACK_LINE(622)
				continue;
			}
			HX_STACK_LINE(625)
			if (((this->_buffers->__get(i) == null()))){
				HX_STACK_LINE(626)
				this->_buffers[i] = ::org::flixel::system::FlxTilemapBuffer_obj::__new(this->_tileWidth,this->_tileHeight,this->widthInTiles,this->heightInTiles,camera);
			}
			HX_STACK_LINE(629)
			buffer = this->_buffers->__get((i)++);
			HX_STACK_LINE(646)
			this->drawTilemap(buffer,camera);
			HX_STACK_LINE(649)
			(::org::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
		}
	}
return null();
}


Void FlxTilemap_obj::drawTilemap( ::org::flixel::system::FlxTilemapBuffer Buffer,::org::flixel::FlxCamera Camera){
{
		HX_STACK_PUSH("FlxTilemap::drawTilemap","org/flixel/FlxTilemap.hx",411);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Buffer,"Buffer");
		HX_STACK_ARG(Camera,"Camera");
		HX_STACK_LINE(416)
		this->_helperPoint->x = (Float(::Math_obj::floor((((this->x - (Camera->scroll->x * this->scrollFactor->x))) * (int)5))) / Float((int)5));
		HX_STACK_LINE(417)
		this->_helperPoint->y = (Float(::Math_obj::floor((((this->y - (Camera->scroll->y * this->scrollFactor->y))) * (int)5))) / Float((int)5));
		HX_STACK_LINE(422)
		int tileID;		HX_STACK_VAR(tileID,"tileID");
		HX_STACK_LINE(424)
		int debugColor;		HX_STACK_VAR(debugColor,"debugColor");
		HX_STACK_LINE(426)
		Float drawX;		HX_STACK_VAR(drawX,"drawX");
		HX_STACK_LINE(427)
		Float drawY;		HX_STACK_VAR(drawY,"drawY");
		HX_STACK_LINE(431)
		bool isColoredCamera = (Camera->color < (int)16777215);		HX_STACK_VAR(isColoredCamera,"isColoredCamera");
		struct _Function_1_1{
			inline static ::org::flixel::system::layer::DrawStackItem Block( ::org::flixel::FlxTilemap_obj *__this,bool &isColoredCamera,::org::flixel::FlxCamera &Camera){
				HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",432);
				{
					HX_STACK_LINE(432)
					::org::flixel::system::layer::Atlas ObjAtlas = __this->_atlas;		HX_STACK_VAR(ObjAtlas,"ObjAtlas");
					HX_STACK_LINE(432)
					::org::flixel::system::layer::DrawStackItem itemToReturn = null();		HX_STACK_VAR(itemToReturn,"itemToReturn");
					HX_STACK_LINE(432)
					if (((Camera->_currentStackItem->initialized == false))){
						HX_STACK_LINE(432)
						Camera->_headOfDrawStack = Camera->_currentStackItem;
						HX_STACK_LINE(432)
						Camera->_currentStackItem->atlas = ObjAtlas;
						HX_STACK_LINE(432)
						Camera->_currentStackItem->colored = isColoredCamera;
						HX_STACK_LINE(432)
						Camera->_currentStackItem->blending = (int)0;
						HX_STACK_LINE(432)
						itemToReturn = Camera->_currentStackItem;
					}
					else{
						HX_STACK_LINE(432)
						if (((bool((bool((Camera->_currentStackItem->atlas == ObjAtlas)) && bool((Camera->_currentStackItem->colored == isColoredCamera)))) && bool((Camera->_currentStackItem->blending == (int)0))))){
							HX_STACK_LINE(432)
							itemToReturn = Camera->_currentStackItem;
						}
					}
					HX_STACK_LINE(432)
					if (((itemToReturn == null()))){
						HX_STACK_LINE(432)
						::org::flixel::system::layer::DrawStackItem newItem = null();		HX_STACK_VAR(newItem,"newItem");
						HX_STACK_LINE(432)
						if (((::org::flixel::FlxCamera_obj::_storageHead != null()))){
							HX_STACK_LINE(432)
							newItem = ::org::flixel::FlxCamera_obj::_storageHead;
							HX_STACK_LINE(432)
							::org::flixel::system::layer::DrawStackItem newHead = ::org::flixel::FlxCamera_obj::_storageHead->next;		HX_STACK_VAR(newHead,"newHead");
							HX_STACK_LINE(432)
							newItem->next = null();
							HX_STACK_LINE(432)
							::org::flixel::FlxCamera_obj::_storageHead = newHead;
						}
						else{
							HX_STACK_LINE(432)
							newItem = ::org::flixel::system::layer::DrawStackItem_obj::__new();
						}
						HX_STACK_LINE(432)
						newItem->atlas = ObjAtlas;
						HX_STACK_LINE(432)
						newItem->colored = isColoredCamera;
						HX_STACK_LINE(432)
						newItem->blending = (int)0;
						HX_STACK_LINE(432)
						Camera->_currentStackItem->next = newItem;
						HX_STACK_LINE(432)
						Camera->_currentStackItem = newItem;
						HX_STACK_LINE(432)
						itemToReturn = Camera->_currentStackItem;
					}
					HX_STACK_LINE(432)
					itemToReturn->initialized = true;
					HX_STACK_LINE(432)
					return itemToReturn;
				}
				return null();
			}
		};
		HX_STACK_LINE(432)
		::org::flixel::system::layer::DrawStackItem drawItem = _Function_1_1::Block(this,isColoredCamera,Camera);		HX_STACK_VAR(drawItem,"drawItem");
		HX_STACK_LINE(436)
		Array< Float > currDrawData = drawItem->drawData;		HX_STACK_VAR(currDrawData,"currDrawData");
		HX_STACK_LINE(437)
		int currIndex = drawItem->position;		HX_STACK_VAR(currIndex,"currIndex");
		HX_STACK_LINE(441)
		this->_point->x = ((Camera->scroll->x * this->scrollFactor->x) - this->x);
		HX_STACK_LINE(442)
		this->_point->y = ((Camera->scroll->y * this->scrollFactor->y) - this->y);
		HX_STACK_LINE(443)
		int screenXInTiles = ::Math_obj::floor((Float(this->_point->x) / Float(this->_tileWidth)));		HX_STACK_VAR(screenXInTiles,"screenXInTiles");
		HX_STACK_LINE(444)
		int screenYInTiles = ::Math_obj::floor((Float(this->_point->y) / Float(this->_tileHeight)));		HX_STACK_VAR(screenYInTiles,"screenYInTiles");
		HX_STACK_LINE(445)
		int screenRows = Buffer->rows;		HX_STACK_VAR(screenRows,"screenRows");
		HX_STACK_LINE(446)
		int screenColumns = Buffer->columns;		HX_STACK_VAR(screenColumns,"screenColumns");
		HX_STACK_LINE(449)
		if (((screenXInTiles < (int)0))){
			HX_STACK_LINE(450)
			screenXInTiles = (int)0;
		}
		HX_STACK_LINE(453)
		if (((screenXInTiles > (this->widthInTiles - screenColumns)))){
			HX_STACK_LINE(454)
			screenXInTiles = (this->widthInTiles - screenColumns);
		}
		HX_STACK_LINE(457)
		if (((screenYInTiles < (int)0))){
			HX_STACK_LINE(458)
			screenYInTiles = (int)0;
		}
		HX_STACK_LINE(461)
		if (((screenYInTiles > (this->heightInTiles - screenRows)))){
			HX_STACK_LINE(462)
			screenYInTiles = (this->heightInTiles - screenRows);
		}
		HX_STACK_LINE(466)
		int rowIndex = ((screenYInTiles * this->widthInTiles) + screenXInTiles);		HX_STACK_VAR(rowIndex,"rowIndex");
		HX_STACK_LINE(467)
		this->_flashPoint->y = (int)0;
		HX_STACK_LINE(468)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(469)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(470)
		int columnIndex;		HX_STACK_VAR(columnIndex,"columnIndex");
		HX_STACK_LINE(471)
		::org::flixel::system::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(473)
		::native::display::BitmapData debugTile;		HX_STACK_VAR(debugTile,"debugTile");
		HX_STACK_LINE(475)
		while(((row < screenRows))){
			HX_STACK_LINE(477)
			columnIndex = rowIndex;
			HX_STACK_LINE(478)
			column = (int)0;
			HX_STACK_LINE(479)
			this->_flashPoint->x = (int)0;
			HX_STACK_LINE(480)
			while(((column < screenColumns))){
				HX_STACK_LINE(511)
				tileID = this->_rectIDs->__get(columnIndex);
				HX_STACK_LINE(512)
				if (((tileID != (int)-1))){
					HX_STACK_LINE(514)
					drawX = (this->_helperPoint->x + (hx::Mod(columnIndex,this->widthInTiles) * this->_tileWidth));
					HX_STACK_LINE(515)
					drawY = (this->_helperPoint->y + (::Math_obj::floor((Float(columnIndex) / Float(this->widthInTiles))) * this->_tileHeight));
					HX_STACK_LINE(517)
					currDrawData[(currIndex)++] = drawX;
					HX_STACK_LINE(518)
					currDrawData[(currIndex)++] = drawY;
					HX_STACK_LINE(523)
					currDrawData[(currIndex)++] = tileID;
					HX_STACK_LINE(525)
					currDrawData[(currIndex)++] = (int)1;
					HX_STACK_LINE(526)
					currDrawData[(currIndex)++] = (int)0;
					HX_STACK_LINE(527)
					currDrawData[(currIndex)++] = (int)0;
					HX_STACK_LINE(528)
					currDrawData[(currIndex)++] = (int)1;
					HX_STACK_LINE(530)
					if ((isColoredCamera)){
						HX_STACK_LINE(532)
						currDrawData[(currIndex)++] = Camera->red;
						HX_STACK_LINE(533)
						currDrawData[(currIndex)++] = Camera->green;
						HX_STACK_LINE(534)
						currDrawData[(currIndex)++] = Camera->blue;
					}
					HX_STACK_LINE(536)
					currDrawData[(currIndex)++] = 1.0;
					HX_STACK_LINE(540)
					if (((bool(::org::flixel::FlxG_obj::visualDebug) && bool(!(this->ignoreDrawDebug))))){
						HX_STACK_LINE(542)
						tile = this->_tileObjects->__get(this->_data->__get(columnIndex));
						HX_STACK_LINE(543)
						if (((tile != null()))){
							HX_STACK_LINE(545)
							if (((tile->allowCollisions <= (int)0))){
								HX_STACK_LINE(546)
								debugColor = (int)-16740119;
							}
							else{
								HX_STACK_LINE(553)
								if (((tile->allowCollisions != (int)4369))){
									HX_STACK_LINE(554)
									debugColor = (int)-1040641;
								}
								else{
									HX_STACK_LINE(562)
									debugColor = (int)-16715227;
								}
							}
							HX_STACK_LINE(571)
							::native::display::Graphics gfx = Camera->_effectsLayer->get_graphics();		HX_STACK_VAR(gfx,"gfx");
							HX_STACK_LINE(572)
							gfx->lineStyle((int)1,debugColor,0.5,null(),null(),null(),null(),null());
							HX_STACK_LINE(573)
							gfx->drawRect(drawX,drawY,this->_tileWidth,this->_tileHeight);
						}
					}
				}
				HX_STACK_LINE(579)
				hx::AddEq(this->_flashPoint->x,this->_tileWidth);
				HX_STACK_LINE(580)
				(column)++;
				HX_STACK_LINE(581)
				(columnIndex)++;
			}
			HX_STACK_LINE(583)
			hx::AddEq(rowIndex,this->widthInTiles);
			HX_STACK_LINE(584)
			hx::AddEq(this->_flashPoint->y,this->_tileHeight);
			HX_STACK_LINE(585)
			(row)++;
		}
		HX_STACK_LINE(589)
		drawItem->position = currIndex;
		HX_STACK_LINE(592)
		Buffer->x = (screenXInTiles * this->_tileWidth);
		HX_STACK_LINE(593)
		Buffer->y = (screenYInTiles * this->_tileHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTilemap_obj,drawTilemap,(void))

Void FlxTilemap_obj::update( ){
{
		HX_STACK_PUSH("FlxTilemap::update","org/flixel/FlxTilemap.hx",396);
		HX_STACK_THIS(this);
		HX_STACK_LINE(396)
		if (((this->_lastVisualDebug != ::org::flixel::FlxG_obj::visualDebug))){
			HX_STACK_LINE(399)
			this->_lastVisualDebug = ::org::flixel::FlxG_obj::visualDebug;
			HX_STACK_LINE(400)
			this->setDirty(null());
		}
	}
return null();
}


::org::flixel::FlxTilemap FlxTilemap_obj::loadMap( Dynamic MapData,Dynamic TileGraphic,hx::Null< int >  __o_TileWidth,hx::Null< int >  __o_TileHeight,hx::Null< int >  __o_AutoTile,hx::Null< int >  __o_StartingIndex,hx::Null< int >  __o_DrawIndex,hx::Null< int >  __o_CollideIndex){
int TileWidth = __o_TileWidth.Default(0);
int TileHeight = __o_TileHeight.Default(0);
int AutoTile = __o_AutoTile.Default(0);
int StartingIndex = __o_StartingIndex.Default(0);
int DrawIndex = __o_DrawIndex.Default(1);
int CollideIndex = __o_CollideIndex.Default(1);
	HX_STACK_PUSH("FlxTilemap::loadMap","org/flixel/FlxTilemap.hx",244);
	HX_STACK_THIS(this);
	HX_STACK_ARG(MapData,"MapData");
	HX_STACK_ARG(TileGraphic,"TileGraphic");
	HX_STACK_ARG(TileWidth,"TileWidth");
	HX_STACK_ARG(TileHeight,"TileHeight");
	HX_STACK_ARG(AutoTile,"AutoTile");
	HX_STACK_ARG(StartingIndex,"StartingIndex");
	HX_STACK_ARG(DrawIndex,"DrawIndex");
	HX_STACK_ARG(CollideIndex,"CollideIndex");
{
		HX_STACK_LINE(245)
		this->_auto = AutoTile;
		HX_STACK_LINE(246)
		this->_startingIndex = (  (((StartingIndex <= (int)0))) ? int((int)0) : int(StartingIndex) );
		HX_STACK_LINE(249)
		if ((::Std_obj::is(MapData,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(252)
			this->_data = Array_obj< int >::__new();
			HX_STACK_LINE(253)
			Array< ::String > columns;		HX_STACK_VAR(columns,"columns");
			HX_STACK_LINE(254)
			Array< ::String > rows = MapData->__Field(HX_CSTRING("split"),true)(HX_CSTRING("\n"));		HX_STACK_VAR(rows,"rows");
			HX_STACK_LINE(255)
			this->heightInTiles = rows->length;
			HX_STACK_LINE(256)
			int row = (int)0;		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(257)
			int column;		HX_STACK_VAR(column,"column");
			HX_STACK_LINE(258)
			while(((row < this->heightInTiles))){
				HX_STACK_LINE(260)
				columns = rows->__get((row)++).split(HX_CSTRING(","));
				HX_STACK_LINE(261)
				if (((columns->length <= (int)1))){
					HX_STACK_LINE(263)
					this->heightInTiles = (this->heightInTiles - (int)1);
					HX_STACK_LINE(264)
					continue;
				}
				HX_STACK_LINE(266)
				if (((this->widthInTiles == (int)0))){
					HX_STACK_LINE(267)
					this->widthInTiles = columns->length;
				}
				HX_STACK_LINE(270)
				column = (int)0;
				HX_STACK_LINE(271)
				while(((column < this->widthInTiles))){
					HX_STACK_LINE(272)
					this->_data->push(::Std_obj::parseInt(columns->__get((column)++)));
				}
			}
		}
		else{
			HX_STACK_LINE(279)
			if ((::Std_obj::is(MapData,hx::ClassOf< Array<int> >()))){
				HX_STACK_LINE(280)
				this->_data = MapData;
			}
			else{
				HX_STACK_LINE(284)
				hx::Throw (((HX_CSTRING("Unexpected MapData format '") + ::Std_obj::string(::Type_obj::_typeof(MapData))) + HX_CSTRING("' passed into loadMap. Map data must be CSV string or Array<Int>.")));
			}
		}
		HX_STACK_LINE(289)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(290)
		this->totalTiles = this->_data->length;
		HX_STACK_LINE(291)
		if (((this->_auto > (int)0))){
			HX_STACK_LINE(293)
			this->_startingIndex = (int)1;
			HX_STACK_LINE(294)
			DrawIndex = (int)1;
			HX_STACK_LINE(295)
			CollideIndex = (int)1;
			HX_STACK_LINE(296)
			i = (int)0;
			HX_STACK_LINE(297)
			while(((i < this->totalTiles))){
				HX_STACK_LINE(298)
				this->autoTile((i)++);
			}
		}
		HX_STACK_LINE(304)
		this->_tiles = ::org::flixel::FlxG_obj::addBitmap(TileGraphic,null(),null(),null(),null(),null());
		HX_STACK_LINE(305)
		this->_tileWidth = TileWidth;
		HX_STACK_LINE(306)
		if (((this->_tileWidth <= (int)0))){
			HX_STACK_LINE(307)
			this->_tileWidth = this->_tiles->get_height();
		}
		HX_STACK_LINE(310)
		this->_tileHeight = TileHeight;
		HX_STACK_LINE(311)
		if (((this->_tileHeight <= (int)0))){
			HX_STACK_LINE(312)
			this->_tileHeight = this->_tileWidth;
		}
		HX_STACK_LINE(317)
		this->_tiles = ::org::flixel::FlxG_obj::addBitmap(TileGraphic,false,false,null(),this->_tileWidth,this->_tileHeight);
		HX_STACK_LINE(318)
		this->_bitmapDataKey = ::org::flixel::FlxG_obj::_lastBitmapDataKey;
		HX_STACK_LINE(322)
		this->_tileObjects = Array_obj< ::org::flixel::system::FlxTile >::__new();
		HX_STACK_LINE(324)
		int length = ::Std_obj::_int((Float(((Float(this->_tiles->get_width()) / Float(this->_tileWidth)) * this->_tiles->get_height())) / Float(this->_tileHeight)));		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(325)
		hx::AddEq(length,this->_startingIndex);
		HX_STACK_LINE(327)
		{
			HX_STACK_LINE(327)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(327)
			while(((_g < length))){
				HX_STACK_LINE(327)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(329)
				this->_tileObjects[i1] = ::org::flixel::system::FlxTile_obj::__new(hx::ObjectPtr<OBJ_>(this),i1,this->_tileWidth,this->_tileHeight,(i1 >= DrawIndex),(  (((i1 >= CollideIndex))) ? int(this->allowCollisions) : int((int)0) ));
			}
		}
		HX_STACK_LINE(332)
		this->updateAtlasInfo(null());
		HX_STACK_LINE(344)
		this->width = (this->widthInTiles * this->_tileWidth);
		HX_STACK_LINE(345)
		this->height = (this->heightInTiles * this->_tileHeight);
		HX_STACK_LINE(359)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC8(FlxTilemap_obj,loadMap,return )

Void FlxTilemap_obj::destroy( ){
{
		HX_STACK_PUSH("FlxTilemap::destroy","org/flixel/FlxTilemap.hx",186);
		HX_STACK_THIS(this);
		HX_STACK_LINE(187)
		this->_flashPoint = null();
		HX_STACK_LINE(188)
		this->_flashRect = null();
		HX_STACK_LINE(189)
		this->_tiles = null();
		HX_STACK_LINE(190)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(191)
		int l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(193)
		if (((this->_tileObjects != null()))){
			HX_STACK_LINE(195)
			l = this->_tileObjects->length;
			HX_STACK_LINE(196)
			{
				HX_STACK_LINE(196)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(196)
				while(((_g < l))){
					HX_STACK_LINE(196)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(198)
					this->_tileObjects->__get(i1)->destroy();
				}
			}
			HX_STACK_LINE(200)
			this->_tileObjects = null();
		}
		HX_STACK_LINE(203)
		if (((this->_buffers != null()))){
			HX_STACK_LINE(205)
			i = (int)0;
			HX_STACK_LINE(206)
			l = this->_buffers->length;
			HX_STACK_LINE(207)
			{
				HX_STACK_LINE(207)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(207)
				while(((_g < l))){
					HX_STACK_LINE(207)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(209)
					this->_buffers->__get(i1)->destroy();
				}
			}
			HX_STACK_LINE(211)
			this->_buffers = null();
		}
		HX_STACK_LINE(214)
		this->_data = null();
		HX_STACK_LINE(224)
		this->_helperPoint = null();
		HX_STACK_LINE(225)
		this->_rectIDs = null();
		HX_STACK_LINE(228)
		this->super::destroy();
	}
return null();
}


::String FlxTilemap_obj::imgAuto;

::String FlxTilemap_obj::imgAutoAlt;

int FlxTilemap_obj::OFF;

int FlxTilemap_obj::AUTO;

int FlxTilemap_obj::ALT;

::String FlxTilemap_obj::arrayToCSV( Array< int > Data,int Width,hx::Null< bool >  __o_Invert){
bool Invert = __o_Invert.Default(false);
	HX_STACK_PUSH("FlxTilemap::arrayToCSV","org/flixel/FlxTilemap.hx",1731);
	HX_STACK_ARG(Data,"Data");
	HX_STACK_ARG(Width,"Width");
	HX_STACK_ARG(Invert,"Invert");
{
		HX_STACK_LINE(1732)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1733)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1734)
		::String csv = HX_CSTRING("");		HX_STACK_VAR(csv,"csv");
		HX_STACK_LINE(1735)
		int Height = ::Std_obj::_int((Float(Data->length) / Float(Width)));		HX_STACK_VAR(Height,"Height");
		HX_STACK_LINE(1736)
		int index;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(1737)
		while(((row < Height))){
			HX_STACK_LINE(1739)
			column = (int)0;
			HX_STACK_LINE(1740)
			while(((column < Width))){
				HX_STACK_LINE(1742)
				index = Data->__get(((row * Width) + column));
				HX_STACK_LINE(1743)
				if ((Invert)){
					HX_STACK_LINE(1744)
					if (((index == (int)0))){
						HX_STACK_LINE(1746)
						index = (int)1;
					}
					else{
						HX_STACK_LINE(1749)
						if (((index == (int)1))){
							HX_STACK_LINE(1750)
							index = (int)0;
						}
					}
				}
				HX_STACK_LINE(1755)
				if (((column == (int)0))){
					HX_STACK_LINE(1756)
					if (((row == (int)0))){
						HX_STACK_LINE(1758)
						hx::AddEq(csv,index);
					}
					else{
						HX_STACK_LINE(1762)
						hx::AddEq(csv,(HX_CSTRING("\n") + index));
					}
				}
				else{
					HX_STACK_LINE(1767)
					hx::AddEq(csv,(HX_CSTRING(", ") + index));
				}
				HX_STACK_LINE(1770)
				(column)++;
			}
			HX_STACK_LINE(1772)
			(row)++;
		}
		HX_STACK_LINE(1774)
		return csv;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,arrayToCSV,return )

::String FlxTilemap_obj::bitmapToCSV( ::native::display::BitmapData bitmapData,hx::Null< bool >  __o_Invert,hx::Null< int >  __o_Scale,Array< int > ColorMap){
bool Invert = __o_Invert.Default(false);
int Scale = __o_Scale.Default(1);
	HX_STACK_PUSH("FlxTilemap::bitmapToCSV","org/flixel/FlxTilemap.hx",1793);
	HX_STACK_ARG(bitmapData,"bitmapData");
	HX_STACK_ARG(Invert,"Invert");
	HX_STACK_ARG(Scale,"Scale");
	HX_STACK_ARG(ColorMap,"ColorMap");
{
		HX_STACK_LINE(1794)
		if (((Scale < (int)1))){
			HX_STACK_LINE(1794)
			Scale = (int)1;
		}
		HX_STACK_LINE(1797)
		if (((Scale > (int)1))){
			HX_STACK_LINE(1799)
			::native::display::BitmapData bd = bitmapData;		HX_STACK_VAR(bd,"bd");
			HX_STACK_LINE(1800)
			bitmapData = ::native::display::BitmapData_obj::__new((bitmapData->get_width() * Scale),(bitmapData->get_height() * Scale),null(),null(),null());
			HX_STACK_LINE(1820)
			::native::geom::Matrix mtx = ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(mtx,"mtx");
			HX_STACK_LINE(1821)
			mtx->scale(Scale,Scale);
			HX_STACK_LINE(1822)
			bitmapData->draw(bd,mtx,null(),null(),null(),null());
		}
		HX_STACK_LINE(1827)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1828)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1832)
		int pixel;		HX_STACK_VAR(pixel,"pixel");
		HX_STACK_LINE(1834)
		::String csv = HX_CSTRING("");		HX_STACK_VAR(csv,"csv");
		HX_STACK_LINE(1835)
		int bitmapWidth = bitmapData->get_width();		HX_STACK_VAR(bitmapWidth,"bitmapWidth");
		HX_STACK_LINE(1836)
		int bitmapHeight = bitmapData->get_height();		HX_STACK_VAR(bitmapHeight,"bitmapHeight");
		HX_STACK_LINE(1837)
		while(((row < bitmapHeight))){
			HX_STACK_LINE(1839)
			column = (int)0;
			HX_STACK_LINE(1840)
			while(((column < bitmapWidth))){
				HX_STACK_LINE(1843)
				pixel = bitmapData->getPixel(column,row);
				HX_STACK_LINE(1844)
				if (((ColorMap != null()))){
					struct _Function_4_1{
						inline static int Block( Array< int > &ColorMap,int &pixel){
							HX_STACK_PUSH("*::closure","org/flixel/FlxTilemap.hx",1846);
							{
								HX_STACK_LINE(1846)
								int fromIndex = (int)0;		HX_STACK_VAR(fromIndex,"fromIndex");
								HX_STACK_LINE(1846)
								int len = ColorMap->length;		HX_STACK_VAR(len,"len");
								HX_STACK_LINE(1846)
								int index = (int)-1;		HX_STACK_VAR(index,"index");
								HX_STACK_LINE(1846)
								{
									HX_STACK_LINE(1846)
									int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
									HX_STACK_LINE(1846)
									while(((_g < len))){
										HX_STACK_LINE(1846)
										int i = (_g)++;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(1846)
										if (((ColorMap->__get(i) == pixel))){
											HX_STACK_LINE(1846)
											index = i;
											HX_STACK_LINE(1846)
											break;
										}
									}
								}
								HX_STACK_LINE(1846)
								return index;
							}
							return null();
						}
					};
					HX_STACK_LINE(1845)
					pixel = _Function_4_1::Block(ColorMap,pixel);
				}
				else{
					HX_STACK_LINE(1848)
					if (((bool((bool(Invert) && bool((pixel > (int)0)))) || bool((bool(!(Invert)) && bool((pixel == (int)0))))))){
						HX_STACK_LINE(1849)
						pixel = (int)1;
					}
					else{
						HX_STACK_LINE(1853)
						pixel = (int)0;
					}
				}
				HX_STACK_LINE(1858)
				if (((column == (int)0))){
					HX_STACK_LINE(1859)
					if (((row == (int)0))){
						HX_STACK_LINE(1861)
						hx::AddEq(csv,pixel);
					}
					else{
						HX_STACK_LINE(1865)
						hx::AddEq(csv,(HX_CSTRING("\n") + pixel));
					}
				}
				else{
					HX_STACK_LINE(1870)
					hx::AddEq(csv,(HX_CSTRING(", ") + pixel));
				}
				HX_STACK_LINE(1873)
				(column)++;
			}
			HX_STACK_LINE(1875)
			(row)++;
		}
		HX_STACK_LINE(1877)
		return csv;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,bitmapToCSV,return )

::String FlxTilemap_obj::imageToCSV( Dynamic ImageFile,hx::Null< bool >  __o_Invert,hx::Null< int >  __o_Scale){
bool Invert = __o_Invert.Default(false);
int Scale = __o_Scale.Default(1);
	HX_STACK_PUSH("FlxTilemap::imageToCSV","org/flixel/FlxTilemap.hx",1891);
	HX_STACK_ARG(ImageFile,"ImageFile");
	HX_STACK_ARG(Invert,"Invert");
	HX_STACK_ARG(Scale,"Scale");
{
		HX_STACK_LINE(1892)
		::native::display::BitmapData tempBitmapData;		HX_STACK_VAR(tempBitmapData,"tempBitmapData");
		HX_STACK_LINE(1893)
		if ((::Std_obj::is(ImageFile,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(1894)
			tempBitmapData = ::org::flixel::FlxAssets_obj::getBitmapData(ImageFile);
		}
		else{
			HX_STACK_LINE(1898)
			tempBitmapData = ::Type_obj::createInstance(ImageFile,Dynamic( Array_obj<Dynamic>::__new()))->__Field(HX_CSTRING("bitmapData"),true);
		}
		HX_STACK_LINE(1901)
		return ::org::flixel::FlxTilemap_obj::bitmapToCSV(tempBitmapData,Invert,Scale,null());
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,imageToCSV,return )


FlxTilemap_obj::FlxTilemap_obj()
{
}

void FlxTilemap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTilemap);
	HX_MARK_MEMBER_NAME(_rectIDs,"_rectIDs");
	HX_MARK_MEMBER_NAME(_helperPoint,"_helperPoint");
	HX_MARK_MEMBER_NAME(_startingIndex,"_startingIndex");
	HX_MARK_MEMBER_NAME(_lastVisualDebug,"_lastVisualDebug");
	HX_MARK_MEMBER_NAME(_tileObjects,"_tileObjects");
	HX_MARK_MEMBER_NAME(_tileHeight,"_tileHeight");
	HX_MARK_MEMBER_NAME(_tileWidth,"_tileWidth");
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(_buffers,"_buffers");
	HX_MARK_MEMBER_NAME(_tiles,"_tiles");
	HX_MARK_MEMBER_NAME(_flashRect,"_flashRect");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(totalTiles,"totalTiles");
	HX_MARK_MEMBER_NAME(heightInTiles,"heightInTiles");
	HX_MARK_MEMBER_NAME(widthInTiles,"widthInTiles");
	HX_MARK_MEMBER_NAME(_auto,"auto");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxTilemap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_rectIDs,"_rectIDs");
	HX_VISIT_MEMBER_NAME(_helperPoint,"_helperPoint");
	HX_VISIT_MEMBER_NAME(_startingIndex,"_startingIndex");
	HX_VISIT_MEMBER_NAME(_lastVisualDebug,"_lastVisualDebug");
	HX_VISIT_MEMBER_NAME(_tileObjects,"_tileObjects");
	HX_VISIT_MEMBER_NAME(_tileHeight,"_tileHeight");
	HX_VISIT_MEMBER_NAME(_tileWidth,"_tileWidth");
	HX_VISIT_MEMBER_NAME(_data,"_data");
	HX_VISIT_MEMBER_NAME(_buffers,"_buffers");
	HX_VISIT_MEMBER_NAME(_tiles,"_tiles");
	HX_VISIT_MEMBER_NAME(_flashRect,"_flashRect");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(totalTiles,"totalTiles");
	HX_VISIT_MEMBER_NAME(heightInTiles,"heightInTiles");
	HX_VISIT_MEMBER_NAME(widthInTiles,"widthInTiles");
	HX_VISIT_MEMBER_NAME(_auto,"auto");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxTilemap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"OFF") ) { return OFF; }
		if (HX_FIELD_EQ(inName,"ALT") ) { return ALT; }
		if (HX_FIELD_EQ(inName,"ray") ) { return ray_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"AUTO") ) { return AUTO; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"auto") ) { return _auto; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rayHit") ) { return rayHit_dyn(); }
		if (HX_FIELD_EQ(inName,"follow") ) { return follow_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_tiles") ) { return _tiles; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"imgAuto") ) { return imgAuto; }
		if (HX_FIELD_EQ(inName,"setTile") ) { return setTile_dyn(); }
		if (HX_FIELD_EQ(inName,"getTile") ) { return getTile_dyn(); }
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMap") ) { return loadMap_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"autoTile") ) { return autoTile_dyn(); }
		if (HX_FIELD_EQ(inName,"overlaps") ) { return overlaps_dyn(); }
		if (HX_FIELD_EQ(inName,"walkPath") ) { return walkPath_dyn(); }
		if (HX_FIELD_EQ(inName,"findPath") ) { return findPath_dyn(); }
		if (HX_FIELD_EQ(inName,"setDirty") ) { return setDirty_dyn(); }
		if (HX_FIELD_EQ(inName,"_rectIDs") ) { return _rectIDs; }
		if (HX_FIELD_EQ(inName,"_buffers") ) { return _buffers; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"imgAutoAlt") ) { return imgAutoAlt; }
		if (HX_FIELD_EQ(inName,"arrayToCSV") ) { return arrayToCSV_dyn(); }
		if (HX_FIELD_EQ(inName,"imageToCSV") ) { return imageToCSV_dyn(); }
		if (HX_FIELD_EQ(inName,"updateTile") ) { return updateTile_dyn(); }
		if (HX_FIELD_EQ(inName,"overlapsAt") ) { return overlapsAt_dyn(); }
		if (HX_FIELD_EQ(inName,"_tileWidth") ) { return _tileWidth; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { return _flashRect; }
		if (HX_FIELD_EQ(inName,"totalTiles") ) { return totalTiles; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bitmapToCSV") ) { return bitmapToCSV_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTilemap") ) { return drawTilemap_dyn(); }
		if (HX_FIELD_EQ(inName,"_tileHeight") ) { return _tileHeight; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"simplifyPath") ) { return simplifyPath_dyn(); }
		if (HX_FIELD_EQ(inName,"_helperPoint") ) { return _helperPoint; }
		if (HX_FIELD_EQ(inName,"_tileObjects") ) { return _tileObjects; }
		if (HX_FIELD_EQ(inName,"widthInTiles") ) { return widthInTiles; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getTileCoords") ) { return getTileCoords_dyn(); }
		if (HX_FIELD_EQ(inName,"overlapsPoint") ) { return overlapsPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"heightInTiles") ) { return heightInTiles; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setTileByIndex") ) { return setTileByIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"getTileByIndex") ) { return getTileByIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"_startingIndex") ) { return _startingIndex; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"tileToFlxSprite") ) { return tileToFlxSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"raySimplifyPath") ) { return raySimplifyPath_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getTileInstances") ) { return getTileInstances_dyn(); }
		if (HX_FIELD_EQ(inName,"_lastVisualDebug") ) { return _lastVisualDebug; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setTileProperties") ) { return setTileProperties_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"computePathDistance") ) { return computePathDistance_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"overlapsWithCallback") ) { return overlapsWithCallback_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTilemap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"OFF") ) { OFF=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ALT") ) { ALT=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"AUTO") ) { AUTO=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"auto") ) { _auto=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_tiles") ) { _tiles=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"imgAuto") ) { imgAuto=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_rectIDs") ) { _rectIDs=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_buffers") ) { _buffers=inValue.Cast< Array< ::org::flixel::system::FlxTilemapBuffer > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"imgAutoAlt") ) { imgAutoAlt=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tileWidth") ) { _tileWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { _flashRect=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"totalTiles") ) { totalTiles=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_tileHeight") ) { _tileHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_helperPoint") ) { _helperPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tileObjects") ) { _tileObjects=inValue.Cast< Array< ::org::flixel::system::FlxTile > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"widthInTiles") ) { widthInTiles=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"heightInTiles") ) { heightInTiles=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_startingIndex") ) { _startingIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_lastVisualDebug") ) { _lastVisualDebug=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTilemap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_rectIDs"));
	outFields->push(HX_CSTRING("_helperPoint"));
	outFields->push(HX_CSTRING("_startingIndex"));
	outFields->push(HX_CSTRING("_lastVisualDebug"));
	outFields->push(HX_CSTRING("_tileObjects"));
	outFields->push(HX_CSTRING("_tileHeight"));
	outFields->push(HX_CSTRING("_tileWidth"));
	outFields->push(HX_CSTRING("_data"));
	outFields->push(HX_CSTRING("_buffers"));
	outFields->push(HX_CSTRING("_tiles"));
	outFields->push(HX_CSTRING("_flashRect"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("totalTiles"));
	outFields->push(HX_CSTRING("heightInTiles"));
	outFields->push(HX_CSTRING("widthInTiles"));
	outFields->push(HX_CSTRING("auto"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("imgAuto"),
	HX_CSTRING("imgAutoAlt"),
	HX_CSTRING("OFF"),
	HX_CSTRING("AUTO"),
	HX_CSTRING("ALT"),
	HX_CSTRING("arrayToCSV"),
	HX_CSTRING("bitmapToCSV"),
	HX_CSTRING("imageToCSV"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("tileToFlxSprite"),
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("updateTile"),
	HX_CSTRING("autoTile"),
	HX_CSTRING("rayHit"),
	HX_CSTRING("ray"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("follow"),
	HX_CSTRING("setTileProperties"),
	HX_CSTRING("setTileByIndex"),
	HX_CSTRING("setTile"),
	HX_CSTRING("getTileCoords"),
	HX_CSTRING("getTileInstances"),
	HX_CSTRING("getTileByIndex"),
	HX_CSTRING("getTile"),
	HX_CSTRING("overlapsPoint"),
	HX_CSTRING("overlapsWithCallback"),
	HX_CSTRING("overlapsAt"),
	HX_CSTRING("overlaps"),
	HX_CSTRING("walkPath"),
	HX_CSTRING("computePathDistance"),
	HX_CSTRING("raySimplifyPath"),
	HX_CSTRING("simplifyPath"),
	HX_CSTRING("findPath"),
	HX_CSTRING("setDirty"),
	HX_CSTRING("getData"),
	HX_CSTRING("draw"),
	HX_CSTRING("drawTilemap"),
	HX_CSTRING("update"),
	HX_CSTRING("loadMap"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_rectIDs"),
	HX_CSTRING("_helperPoint"),
	HX_CSTRING("_startingIndex"),
	HX_CSTRING("_lastVisualDebug"),
	HX_CSTRING("_tileObjects"),
	HX_CSTRING("_tileHeight"),
	HX_CSTRING("_tileWidth"),
	HX_CSTRING("_data"),
	HX_CSTRING("_buffers"),
	HX_CSTRING("_tiles"),
	HX_CSTRING("_flashRect"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("totalTiles"),
	HX_CSTRING("heightInTiles"),
	HX_CSTRING("widthInTiles"),
	HX_CSTRING("auto"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::imgAuto,"imgAuto");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::imgAutoAlt,"imgAutoAlt");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::OFF,"OFF");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::AUTO,"AUTO");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::ALT,"ALT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::imgAuto,"imgAuto");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::imgAutoAlt,"imgAutoAlt");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::OFF,"OFF");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::AUTO,"AUTO");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::ALT,"ALT");
};

Class FlxTilemap_obj::__mClass;

void FlxTilemap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxTilemap"), hx::TCanCast< FlxTilemap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxTilemap_obj::__boot()
{
	imgAuto= ::org::flixel::FlxAssets_obj::imgAuto;
	imgAutoAlt= ::org::flixel::FlxAssets_obj::imgAutoAlt;
	OFF= (int)0;
	AUTO= (int)1;
	ALT= (int)2;
}

} // end namespace org
} // end namespace flixel
