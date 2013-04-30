#include <hxcpp.h>

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
#ifndef INCLUDED_org_flixel_FlxSprite
#include <org/flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_org_flixel_system_BGSprite
#include <org/flixel/system/BGSprite.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_DrawStackItem
#include <org/flixel/system/layer/DrawStackItem.h>
#endif
namespace org{
namespace flixel{
namespace system{

Void BGSprite_obj::__construct()
{
HX_STACK_PUSH("BGSprite::new","org/flixel/system/BGSprite.hx",19);
{
	HX_STACK_LINE(20)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(21)
	this->makeGraphic((int)1,(int)1,(int)0,true,::org::flixel::FlxG_obj::getUniqueBitmapKey(HX_CSTRING("bg_graphic_")));
	HX_STACK_LINE(22)
	{
		HX_STACK_LINE(22)
		::org::flixel::FlxPoint _this = this->scrollFactor;		HX_STACK_VAR(_this,"_this");
		Float X = (int)0;		HX_STACK_VAR(X,"X");
		Float Y = (int)0;		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(22)
		_this->x = X;
		HX_STACK_LINE(22)
		_this->y = Y;
		HX_STACK_LINE(22)
		_this;
	}
}
;
	return null();
}

BGSprite_obj::~BGSprite_obj() { }

Dynamic BGSprite_obj::__CreateEmpty() { return  new BGSprite_obj; }
hx::ObjectPtr< BGSprite_obj > BGSprite_obj::__new()
{  hx::ObjectPtr< BGSprite_obj > result = new BGSprite_obj();
	result->__construct();
	return result;}

Dynamic BGSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BGSprite_obj > result = new BGSprite_obj();
	result->__construct();
	return result;}

Void BGSprite_obj::draw( ){
{
		HX_STACK_PUSH("BGSprite::draw","org/flixel/system/BGSprite.hx",29);
		HX_STACK_THIS(this);
		HX_STACK_LINE(31)
		if (((this->_atlas == null()))){
			HX_STACK_LINE(32)
			return null();
		}
		HX_STACK_LINE(37)
		if (((this->cameras == null()))){
			HX_STACK_LINE(38)
			this->cameras = ::org::flixel::FlxG_obj::cameras;
		}
		HX_STACK_LINE(41)
		::org::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(42)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(43)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(45)
		::org::flixel::system::layer::DrawStackItem drawItem;		HX_STACK_VAR(drawItem,"drawItem");
		HX_STACK_LINE(46)
		Array< Float > currDrawData;		HX_STACK_VAR(currDrawData,"currDrawData");
		HX_STACK_LINE(47)
		int currIndex;		HX_STACK_VAR(currIndex,"currIndex");
		HX_STACK_LINE(49)
		bool isColored = (this->_color < (int)16777215);		HX_STACK_VAR(isColored,"isColored");
		HX_STACK_LINE(54)
		while(((i < l))){
			HX_STACK_LINE(56)
			camera = this->cameras->__get((i)++);
			HX_STACK_LINE(58)
			if (((bool(!(camera->visible)) || bool(!(camera->exists))))){
				HX_STACK_LINE(59)
				continue;
			}
			HX_STACK_LINE(64)
			bool isColoredCamera = (camera->color < (int)16777215);		HX_STACK_VAR(isColoredCamera,"isColoredCamera");
			struct _Function_2_1{
				inline static ::org::flixel::system::layer::DrawStackItem Block( ::org::flixel::system::BGSprite_obj *__this,::org::flixel::FlxCamera &camera,bool &isColored,bool &isColoredCamera){
					HX_STACK_PUSH("*::closure","org/flixel/system/BGSprite.hx",65);
					{
						HX_STACK_LINE(65)
						::org::flixel::system::layer::Atlas ObjAtlas = __this->_atlas;		HX_STACK_VAR(ObjAtlas,"ObjAtlas");
						bool ObjColored = (bool(isColored) || bool(isColoredCamera));		HX_STACK_VAR(ObjColored,"ObjColored");
						int ObjBlending = __this->_blendInt;		HX_STACK_VAR(ObjBlending,"ObjBlending");
						HX_STACK_LINE(65)
						::org::flixel::system::layer::DrawStackItem itemToReturn = null();		HX_STACK_VAR(itemToReturn,"itemToReturn");
						HX_STACK_LINE(65)
						if (((camera->_currentStackItem->initialized == false))){
							HX_STACK_LINE(65)
							camera->_headOfDrawStack = camera->_currentStackItem;
							HX_STACK_LINE(65)
							camera->_currentStackItem->atlas = ObjAtlas;
							HX_STACK_LINE(65)
							camera->_currentStackItem->colored = ObjColored;
							HX_STACK_LINE(65)
							camera->_currentStackItem->blending = ObjBlending;
							HX_STACK_LINE(65)
							itemToReturn = camera->_currentStackItem;
						}
						else{
							HX_STACK_LINE(65)
							if (((bool((bool((camera->_currentStackItem->atlas == ObjAtlas)) && bool((camera->_currentStackItem->colored == ObjColored)))) && bool((camera->_currentStackItem->blending == ObjBlending))))){
								HX_STACK_LINE(65)
								itemToReturn = camera->_currentStackItem;
							}
						}
						HX_STACK_LINE(65)
						if (((itemToReturn == null()))){
							HX_STACK_LINE(65)
							::org::flixel::system::layer::DrawStackItem newItem = null();		HX_STACK_VAR(newItem,"newItem");
							HX_STACK_LINE(65)
							if (((::org::flixel::FlxCamera_obj::_storageHead != null()))){
								HX_STACK_LINE(65)
								newItem = ::org::flixel::FlxCamera_obj::_storageHead;
								HX_STACK_LINE(65)
								::org::flixel::system::layer::DrawStackItem newHead = ::org::flixel::FlxCamera_obj::_storageHead->next;		HX_STACK_VAR(newHead,"newHead");
								HX_STACK_LINE(65)
								newItem->next = null();
								HX_STACK_LINE(65)
								::org::flixel::FlxCamera_obj::_storageHead = newHead;
							}
							else{
								HX_STACK_LINE(65)
								newItem = ::org::flixel::system::layer::DrawStackItem_obj::__new();
							}
							HX_STACK_LINE(65)
							newItem->atlas = ObjAtlas;
							HX_STACK_LINE(65)
							newItem->colored = ObjColored;
							HX_STACK_LINE(65)
							newItem->blending = ObjBlending;
							HX_STACK_LINE(65)
							camera->_currentStackItem->next = newItem;
							HX_STACK_LINE(65)
							camera->_currentStackItem = newItem;
							HX_STACK_LINE(65)
							itemToReturn = camera->_currentStackItem;
						}
						HX_STACK_LINE(65)
						itemToReturn->initialized = true;
						HX_STACK_LINE(65)
						return itemToReturn;
					}
					return null();
				}
			};
			HX_STACK_LINE(65)
			drawItem = _Function_2_1::Block(this,camera,isColored,isColoredCamera);
			HX_STACK_LINE(69)
			currDrawData = drawItem->drawData;
			HX_STACK_LINE(70)
			currIndex = drawItem->position;
			HX_STACK_LINE(72)
			this->_point->x = (camera->width * 0.5);
			HX_STACK_LINE(73)
			this->_point->y = (camera->height * 0.5);
			HX_STACK_LINE(75)
			Float csx = camera->width;		HX_STACK_VAR(csx,"csx");
			HX_STACK_LINE(76)
			Float ssy = (int)0;		HX_STACK_VAR(ssy,"ssy");
			HX_STACK_LINE(77)
			Float ssx = (int)0;		HX_STACK_VAR(ssx,"ssx");
			HX_STACK_LINE(78)
			Float csy = camera->height;		HX_STACK_VAR(csy,"csy");
			HX_STACK_LINE(80)
			Float x1 = (this->origin->x - this->_halfWidth);		HX_STACK_VAR(x1,"x1");
			HX_STACK_LINE(81)
			Float y1 = (this->origin->y - this->_halfHeight);		HX_STACK_VAR(y1,"y1");
			HX_STACK_LINE(82)
			Float x2 = ((x1 * csx) + (y1 * ssy));		HX_STACK_VAR(x2,"x2");
			HX_STACK_LINE(83)
			Float y2 = ((-(x1) * ssx) + (y1 * csy));		HX_STACK_VAR(y2,"y2");
			HX_STACK_LINE(85)
			currDrawData[(currIndex)++] = (this->_point->x - x2);
			HX_STACK_LINE(86)
			currDrawData[(currIndex)++] = (this->_point->y - y2);
			HX_STACK_LINE(88)
			currDrawData[(currIndex)++] = this->_frameID;
			HX_STACK_LINE(90)
			currDrawData[(currIndex)++] = csx;
			HX_STACK_LINE(91)
			currDrawData[(currIndex)++] = ssy;
			HX_STACK_LINE(92)
			currDrawData[(currIndex)++] = -(ssx);
			HX_STACK_LINE(93)
			currDrawData[(currIndex)++] = csy;
			HX_STACK_LINE(96)
			if (((bool(isColored) || bool(isColoredCamera)))){
				HX_STACK_LINE(97)
				if ((isColoredCamera)){
					HX_STACK_LINE(100)
					currDrawData[(currIndex)++] = (this->_red * camera->red);
					HX_STACK_LINE(101)
					currDrawData[(currIndex)++] = (this->_green * camera->green);
					HX_STACK_LINE(102)
					currDrawData[(currIndex)++] = (this->_blue * camera->blue);
				}
				else{
					HX_STACK_LINE(106)
					currDrawData[(currIndex)++] = this->_red;
					HX_STACK_LINE(107)
					currDrawData[(currIndex)++] = this->_green;
					HX_STACK_LINE(108)
					currDrawData[(currIndex)++] = this->_blue;
				}
			}
			HX_STACK_LINE(111)
			currDrawData[(currIndex)++] = this->alpha;
			HX_STACK_LINE(118)
			drawItem->position = currIndex;
			HX_STACK_LINE(120)
			(::org::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
		}
	}
return null();
}



BGSprite_obj::BGSprite_obj()
{
}

void BGSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BGSprite);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BGSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BGSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BGSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BGSprite_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("draw"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BGSprite_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BGSprite_obj::__mClass,"__mClass");
};

Class BGSprite_obj::__mClass;

void BGSprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.BGSprite"), hx::TCanCast< BGSprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BGSprite_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
