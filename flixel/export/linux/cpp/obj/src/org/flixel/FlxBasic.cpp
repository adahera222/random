#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
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
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
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
#ifndef INCLUDED_org_flixel_FlxGroup
#include <org/flixel/FlxGroup.h>
#endif
#ifndef INCLUDED_org_flixel_FlxState
#include <org/flixel/FlxState.h>
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
#ifndef INCLUDED_org_flixel_tweens_FlxTween
#include <org/flixel/tweens/FlxTween.h>
#endif
namespace org{
namespace flixel{

Void FlxBasic_obj::__construct()
{
HX_STACK_PUSH("FlxBasic::new","org/flixel/FlxBasic.hx",68);
{
	HX_STACK_LINE(69)
	this->ID = (int)-1;
	HX_STACK_LINE(70)
	this->exists = true;
	HX_STACK_LINE(71)
	this->active = true;
	HX_STACK_LINE(72)
	this->visible = true;
	HX_STACK_LINE(73)
	this->alive = true;
	HX_STACK_LINE(74)
	this->autoClear = true;
	HX_STACK_LINE(77)
	this->ignoreDrawDebug = false;
}
;
	return null();
}

FlxBasic_obj::~FlxBasic_obj() { }

Dynamic FlxBasic_obj::__CreateEmpty() { return  new FlxBasic_obj; }
hx::ObjectPtr< FlxBasic_obj > FlxBasic_obj::__new()
{  hx::ObjectPtr< FlxBasic_obj > result = new FlxBasic_obj();
	result->__construct();
	return result;}

Dynamic FlxBasic_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxBasic_obj > result = new FlxBasic_obj();
	result->__construct();
	return result;}

Void FlxBasic_obj::updateFrameData( ){
{
		HX_STACK_PUSH("FlxBasic::updateFrameData","org/flixel/FlxBasic.hx",391);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,updateFrameData,(void))

::org::flixel::system::layer::Atlas FlxBasic_obj::getAtlas( ){
	HX_STACK_PUSH("FlxBasic::getAtlas","org/flixel/FlxBasic.hx",385);
	HX_STACK_THIS(this);
	HX_STACK_LINE(385)
	return ::org::flixel::FlxG_obj::get_state()->getAtlasFor(this->_bitmapDataKey);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,getAtlas,return )

Void FlxBasic_obj::updateAtlasInfo( hx::Null< bool >  __o_updateAtlas){
bool updateAtlas = __o_updateAtlas.Default(false);
	HX_STACK_PUSH("FlxBasic::updateAtlasInfo","org/flixel/FlxBasic.hx",348);
	HX_STACK_THIS(this);
	HX_STACK_ARG(updateAtlas,"updateAtlas");
{
		HX_STACK_LINE(357)
		if (((this->_atlas == null()))){
			HX_STACK_LINE(359)
			this->_atlas = this->getAtlas();
			HX_STACK_LINE(360)
			this->_node = this->_atlas->getNodeByKey(this->_bitmapDataKey);
		}
		else{
			HX_STACK_LINE(362)
			if ((this->_atlas->hasNodeWithName(this->_bitmapDataKey))){
				HX_STACK_LINE(363)
				if ((updateAtlas)){
					HX_STACK_LINE(365)
					this->_atlas->redrawNode(this->_node);
				}
			}
			else{
				HX_STACK_LINE(371)
				::native::display::BitmapData bm = ::org::flixel::FlxG_obj::_cache->get(this->_bitmapDataKey);		HX_STACK_VAR(bm,"bm");
				HX_STACK_LINE(372)
				this->_node = this->_atlas->addNode(bm,this->_bitmapDataKey);
				HX_STACK_LINE(373)
				if (((this->_node == null()))){
					HX_STACK_LINE(375)
					this->_atlas = this->getAtlas();
					HX_STACK_LINE(376)
					this->_node = this->_atlas->getNodeByKey(this->_bitmapDataKey);
				}
			}
		}
		HX_STACK_LINE(379)
		this->updateFrameData();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,updateAtlasInfo,(void))

::String FlxBasic_obj::get_bitmapDataKey( ){
	HX_STACK_PUSH("FlxBasic::get_bitmapDataKey","org/flixel/FlxBasic.hx",342);
	HX_STACK_THIS(this);
	HX_STACK_LINE(342)
	return this->_bitmapDataKey;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,get_bitmapDataKey,return )

::org::flixel::system::layer::Atlas FlxBasic_obj::set_atlas( ::org::flixel::system::layer::Atlas value){
	HX_STACK_PUSH("FlxBasic::set_atlas","org/flixel/FlxBasic.hx",296);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(297)
	if (((this->_atlas != value))){
		HX_STACK_LINE(298)
		if (((value == null()))){
			HX_STACK_LINE(301)
			this->_atlas = value;
			HX_STACK_LINE(302)
			this->_node = null();
			HX_STACK_LINE(303)
			this->_framesData = null();
		}
		else{
			HX_STACK_LINE(307)
			if (((this->_bitmapDataKey != null()))){
				HX_STACK_LINE(309)
				if ((!(value->hasNodeWithName(this->_bitmapDataKey)))){
					HX_STACK_LINE(311)
					::native::display::BitmapData bm = ::org::flixel::FlxG_obj::_cache->get(this->_bitmapDataKey);		HX_STACK_VAR(bm,"bm");
					HX_STACK_LINE(312)
					if (((bm == null()))){
						HX_STACK_LINE(313)
						return null();
					}
					else{
						HX_STACK_LINE(319)
						if (((value->addNode(bm,this->_bitmapDataKey) == null()))){
							HX_STACK_LINE(320)
							return null();
						}
					}
				}
				HX_STACK_LINE(328)
				this->_atlas = value;
				HX_STACK_LINE(329)
				this->_node = value->getNodeByKey(this->_bitmapDataKey);
			}
			HX_STACK_LINE(332)
			this->updateFrameData();
		}
	}
	HX_STACK_LINE(336)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,set_atlas,return )

::org::flixel::system::layer::Atlas FlxBasic_obj::get_atlas( ){
	HX_STACK_PUSH("FlxBasic::get_atlas","org/flixel/FlxBasic.hx",291);
	HX_STACK_THIS(this);
	HX_STACK_LINE(291)
	return this->_atlas;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,get_atlas,return )

bool FlxBasic_obj::get_hasTween( ){
	HX_STACK_PUSH("FlxBasic::get_hasTween","org/flixel/FlxBasic.hx",272);
	HX_STACK_THIS(this);
	HX_STACK_LINE(272)
	return (this->_tween != null());
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,get_hasTween,return )

Void FlxBasic_obj::updateTweens( ){
{
		HX_STACK_PUSH("FlxBasic::updateTweens","org/flixel/FlxBasic.hx",251);
		HX_STACK_THIS(this);
		HX_STACK_LINE(252)
		::org::flixel::tweens::FlxTween t;		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(253)
		Dynamic ft = this->_tween;		HX_STACK_VAR(ft,"ft");
		HX_STACK_LINE(254)
		while(((ft != null()))){
			HX_STACK_LINE(256)
			t = hx::TCast< org::flixel::tweens::FlxTween >::cast(ft);
			HX_STACK_LINE(257)
			if ((t->active)){
				HX_STACK_LINE(259)
				t->update();
				HX_STACK_LINE(260)
				if ((ft->__Field(HX_CSTRING("_finish"),true))){
					HX_STACK_LINE(261)
					ft->__Field(HX_CSTRING("finish"),true)();
				}
			}
			HX_STACK_LINE(265)
			ft = ft->__Field(HX_CSTRING("_next"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,updateTweens,(void))

Void FlxBasic_obj::clearTweens( hx::Null< bool >  __o_destroy){
bool destroy = __o_destroy.Default(false);
	HX_STACK_PUSH("FlxBasic::clearTweens","org/flixel/FlxBasic.hx",238);
	HX_STACK_THIS(this);
	HX_STACK_ARG(destroy,"destroy");
{
		HX_STACK_LINE(239)
		::org::flixel::tweens::FlxTween t;		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(240)
		Dynamic ft = this->_tween;		HX_STACK_VAR(ft,"ft");
		HX_STACK_LINE(241)
		Dynamic fn;		HX_STACK_VAR(fn,"fn");
		HX_STACK_LINE(242)
		while(((ft != null()))){
			HX_STACK_LINE(244)
			fn = ft->__Field(HX_CSTRING("_next"),true);
			HX_STACK_LINE(245)
			this->removeTween(hx::TCast< org::flixel::tweens::FlxTween >::cast(ft),destroy);
			HX_STACK_LINE(246)
			ft = fn;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,clearTweens,(void))

::org::flixel::tweens::FlxTween FlxBasic_obj::removeTween( ::org::flixel::tweens::FlxTween t,hx::Null< bool >  __o_destroy){
bool destroy = __o_destroy.Default(false);
	HX_STACK_PUSH("FlxBasic::removeTween","org/flixel/FlxBasic.hx",212);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(destroy,"destroy");
{
		HX_STACK_LINE(213)
		Dynamic ft = t;		HX_STACK_VAR(ft,"ft");
		HX_STACK_LINE(214)
		if (((ft->__Field(HX_CSTRING("_parent"),true) != hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(215)
			hx::Throw (HX_CSTRING("Core object does not contain FlxTween."));
		}
		HX_STACK_LINE(218)
		if (((ft->__Field(HX_CSTRING("_next"),true) != null()))){
			HX_STACK_LINE(219)
			ft->__Field(HX_CSTRING("_next"),true)->__FieldRef(HX_CSTRING("_prev")) = ft->__Field(HX_CSTRING("_prev"),true);
		}
		HX_STACK_LINE(222)
		if (((ft->__Field(HX_CSTRING("_prev"),true) != null()))){
			HX_STACK_LINE(223)
			ft->__Field(HX_CSTRING("_prev"),true)->__FieldRef(HX_CSTRING("_next")) = ft->__Field(HX_CSTRING("_next"),true);
		}
		else{
			HX_STACK_LINE(227)
			this->_tween = (  (((ft->__Field(HX_CSTRING("_next"),true) == null()))) ? ::org::flixel::tweens::FlxTween(null()) : ::org::flixel::tweens::FlxTween(hx::TCast< org::flixel::tweens::FlxTween >::cast(ft->__Field(HX_CSTRING("_next"),true))) );
		}
		HX_STACK_LINE(230)
		ft->__FieldRef(HX_CSTRING("_next")) = ft->__FieldRef(HX_CSTRING("_prev")) = null();
		HX_STACK_LINE(231)
		ft->__FieldRef(HX_CSTRING("_parent")) = null();
		HX_STACK_LINE(232)
		if ((destroy)){
			HX_STACK_LINE(232)
			t->destroy();
		}
		HX_STACK_LINE(233)
		t->active = false;
		HX_STACK_LINE(234)
		return t;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxBasic_obj,removeTween,return )

::org::flixel::tweens::FlxTween FlxBasic_obj::addTween( ::org::flixel::tweens::FlxTween t,hx::Null< bool >  __o_start){
bool start = __o_start.Default(false);
	HX_STACK_PUSH("FlxBasic::addTween","org/flixel/FlxBasic.hx",190);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(start,"start");
{
		HX_STACK_LINE(191)
		Dynamic ft = t;		HX_STACK_VAR(ft,"ft");
		HX_STACK_LINE(192)
		if (((ft->__Field(HX_CSTRING("_parent"),true) != null()))){
			HX_STACK_LINE(193)
			hx::Throw (HX_CSTRING("Cannot add a FlxTween object more than once."));
		}
		HX_STACK_LINE(196)
		ft->__FieldRef(HX_CSTRING("_parent")) = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(197)
		ft->__FieldRef(HX_CSTRING("_next")) = this->_tween;
		HX_STACK_LINE(198)
		Dynamic friendTween = this->_tween;		HX_STACK_VAR(friendTween,"friendTween");
		HX_STACK_LINE(199)
		if (((this->_tween != null()))){
			HX_STACK_LINE(200)
			friendTween->__FieldRef(HX_CSTRING("_prev")) = t;
		}
		HX_STACK_LINE(203)
		this->_tween = t;
		HX_STACK_LINE(204)
		if ((start)){
			HX_STACK_LINE(205)
			this->_tween->start();
		}
		HX_STACK_LINE(208)
		return t;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxBasic_obj,addTween,return )

::String FlxBasic_obj::toString( ){
	HX_STACK_PUSH("FlxBasic::toString","org/flixel/FlxBasic.hx",185);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::String Block( ::org::flixel::FlxBasic_obj *__this){
			HX_STACK_PUSH("*::closure","org/flixel/FlxBasic.hx",186);
			{
				HX_STACK_LINE(186)
				::String s = ::Type_obj::getClassName(::Type_obj::getClass(__this));		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(186)
				if (((s != null()))){
					HX_STACK_LINE(186)
					s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
					HX_STACK_LINE(186)
					s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
				}
				HX_STACK_LINE(186)
				return s;
			}
			return null();
		}
	};
	HX_STACK_LINE(185)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,toString,return )

Void FlxBasic_obj::revive( ){
{
		HX_STACK_PUSH("FlxBasic::revive","org/flixel/FlxBasic.hx",176);
		HX_STACK_THIS(this);
		HX_STACK_LINE(177)
		this->alive = true;
		HX_STACK_LINE(178)
		this->exists = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,revive,(void))

Void FlxBasic_obj::kill( ){
{
		HX_STACK_PUSH("FlxBasic::kill","org/flixel/FlxBasic.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_LINE(167)
		this->alive = false;
		HX_STACK_LINE(168)
		this->exists = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,kill,(void))

Void FlxBasic_obj::drawDebug( ::org::flixel::FlxCamera Camera){
{
		HX_STACK_PUSH("FlxBasic::drawDebug","org/flixel/FlxBasic.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Camera,"Camera");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,drawDebug,(void))

Void FlxBasic_obj::draw( ){
{
		HX_STACK_PUSH("FlxBasic::draw","org/flixel/FlxBasic.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_LINE(127)
		if (((this->cameras == null()))){
			HX_STACK_LINE(128)
			this->cameras = ::org::flixel::FlxG_obj::cameras;
		}
		HX_STACK_LINE(131)
		::org::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(132)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(133)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(134)
		while(((i < l))){
			HX_STACK_LINE(136)
			camera = this->cameras->__get((i)++);
			HX_STACK_LINE(137)
			(::org::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
			HX_STACK_LINE(140)
			if (((bool(::org::flixel::FlxG_obj::visualDebug) && bool(!(this->ignoreDrawDebug))))){
				HX_STACK_LINE(141)
				this->drawDebug(camera);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,draw,(void))

Void FlxBasic_obj::postUpdate( ){
{
		HX_STACK_PUSH("FlxBasic::postUpdate","org/flixel/FlxBasic.hx",119);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,postUpdate,(void))

Void FlxBasic_obj::update( ){
{
		HX_STACK_PUSH("FlxBasic::update","org/flixel/FlxBasic.hx",114);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,update,(void))

Void FlxBasic_obj::preUpdate( ){
{
		HX_STACK_PUSH("FlxBasic::preUpdate","org/flixel/FlxBasic.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_LINE(106)
		(::org::flixel::FlxBasic_obj::_ACTIVECOUNT)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,preUpdate,(void))

Void FlxBasic_obj::destroy( ){
{
		HX_STACK_PUSH("FlxBasic::destroy","org/flixel/FlxBasic.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_LINE(88)
		if (((bool(this->autoClear) && bool(this->get_hasTween())))){
			HX_STACK_LINE(90)
			this->clearTweens(true);
			HX_STACK_LINE(91)
			this->_tween = null();
		}
		HX_STACK_LINE(95)
		this->_framesData = null();
		HX_STACK_LINE(96)
		this->_bitmapDataKey = null();
		HX_STACK_LINE(97)
		this->_atlas = null();
		HX_STACK_LINE(98)
		this->_node = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,destroy,(void))

int FlxBasic_obj::_ACTIVECOUNT;

int FlxBasic_obj::_VISIBLECOUNT;


FlxBasic_obj::FlxBasic_obj()
{
}

void FlxBasic_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxBasic);
	HX_MARK_MEMBER_NAME(bitmapDataKey,"bitmapDataKey");
	HX_MARK_MEMBER_NAME(atlas,"atlas");
	HX_MARK_MEMBER_NAME(_node,"_node");
	HX_MARK_MEMBER_NAME(_atlas,"_atlas");
	HX_MARK_MEMBER_NAME(_framesData,"_framesData");
	HX_MARK_MEMBER_NAME(_bitmapDataKey,"_bitmapDataKey");
	HX_MARK_MEMBER_NAME(_tween,"_tween");
	HX_MARK_MEMBER_NAME(hasTween,"hasTween");
	HX_MARK_MEMBER_NAME(autoClear,"autoClear");
	HX_MARK_MEMBER_NAME(ignoreDrawDebug,"ignoreDrawDebug");
	HX_MARK_MEMBER_NAME(cameras,"cameras");
	HX_MARK_MEMBER_NAME(alive,"alive");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(exists,"exists");
	HX_MARK_MEMBER_NAME(ID,"ID");
	HX_MARK_END_CLASS();
}

void FlxBasic_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bitmapDataKey,"bitmapDataKey");
	HX_VISIT_MEMBER_NAME(atlas,"atlas");
	HX_VISIT_MEMBER_NAME(_node,"_node");
	HX_VISIT_MEMBER_NAME(_atlas,"_atlas");
	HX_VISIT_MEMBER_NAME(_framesData,"_framesData");
	HX_VISIT_MEMBER_NAME(_bitmapDataKey,"_bitmapDataKey");
	HX_VISIT_MEMBER_NAME(_tween,"_tween");
	HX_VISIT_MEMBER_NAME(hasTween,"hasTween");
	HX_VISIT_MEMBER_NAME(autoClear,"autoClear");
	HX_VISIT_MEMBER_NAME(ignoreDrawDebug,"ignoreDrawDebug");
	HX_VISIT_MEMBER_NAME(cameras,"cameras");
	HX_VISIT_MEMBER_NAME(alive,"alive");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(exists,"exists");
	HX_VISIT_MEMBER_NAME(ID,"ID");
}

Dynamic FlxBasic_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { return ID; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { return inCallProp ? get_atlas() : atlas; }
		if (HX_FIELD_EQ(inName,"_node") ) { return _node; }
		if (HX_FIELD_EQ(inName,"alive") ) { return alive; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_atlas") ) { return _atlas; }
		if (HX_FIELD_EQ(inName,"_tween") ) { return _tween; }
		if (HX_FIELD_EQ(inName,"revive") ) { return revive_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"cameras") ) { return cameras; }
		if (HX_FIELD_EQ(inName,"visible") ) { return visible; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAtlas") ) { return getAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"hasTween") ) { return inCallProp ? get_hasTween() : hasTween; }
		if (HX_FIELD_EQ(inName,"addTween") ) { return addTween_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_atlas") ) { return set_atlas_dyn(); }
		if (HX_FIELD_EQ(inName,"get_atlas") ) { return get_atlas_dyn(); }
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		if (HX_FIELD_EQ(inName,"preUpdate") ) { return preUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"autoClear") ) { return autoClear; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"postUpdate") ) { return postUpdate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_framesData") ) { return _framesData; }
		if (HX_FIELD_EQ(inName,"clearTweens") ) { return clearTweens_dyn(); }
		if (HX_FIELD_EQ(inName,"removeTween") ) { return removeTween_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_ACTIVECOUNT") ) { return _ACTIVECOUNT; }
		if (HX_FIELD_EQ(inName,"get_hasTween") ) { return get_hasTween_dyn(); }
		if (HX_FIELD_EQ(inName,"updateTweens") ) { return updateTweens_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_VISIBLECOUNT") ) { return _VISIBLECOUNT; }
		if (HX_FIELD_EQ(inName,"bitmapDataKey") ) { return inCallProp ? get_bitmapDataKey() : bitmapDataKey; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_bitmapDataKey") ) { return _bitmapDataKey; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAtlasInfo") ) { return updateAtlasInfo_dyn(); }
		if (HX_FIELD_EQ(inName,"ignoreDrawDebug") ) { return ignoreDrawDebug; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_bitmapDataKey") ) { return get_bitmapDataKey_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxBasic_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { ID=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { if (inCallProp) return set_atlas(inValue);atlas=inValue.Cast< ::org::flixel::system::layer::Atlas >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_node") ) { _node=inValue.Cast< ::org::flixel::system::layer::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alive") ) { alive=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_atlas") ) { _atlas=inValue.Cast< ::org::flixel::system::layer::Atlas >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tween") ) { _tween=inValue.Cast< ::org::flixel::tweens::FlxTween >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"exists") ) { exists=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cameras") ) { cameras=inValue.Cast< Array< ::org::flixel::FlxCamera > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visible") ) { visible=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasTween") ) { hasTween=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"autoClear") ) { autoClear=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_framesData") ) { _framesData=inValue.Cast< ::org::flixel::system::layer::FlxSpriteFrames >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_ACTIVECOUNT") ) { _ACTIVECOUNT=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_VISIBLECOUNT") ) { _VISIBLECOUNT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bitmapDataKey") ) { bitmapDataKey=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_bitmapDataKey") ) { _bitmapDataKey=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ignoreDrawDebug") ) { ignoreDrawDebug=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxBasic_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapDataKey"));
	outFields->push(HX_CSTRING("atlas"));
	outFields->push(HX_CSTRING("_node"));
	outFields->push(HX_CSTRING("_atlas"));
	outFields->push(HX_CSTRING("_framesData"));
	outFields->push(HX_CSTRING("_bitmapDataKey"));
	outFields->push(HX_CSTRING("_tween"));
	outFields->push(HX_CSTRING("hasTween"));
	outFields->push(HX_CSTRING("autoClear"));
	outFields->push(HX_CSTRING("ignoreDrawDebug"));
	outFields->push(HX_CSTRING("cameras"));
	outFields->push(HX_CSTRING("alive"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("exists"));
	outFields->push(HX_CSTRING("ID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_ACTIVECOUNT"),
	HX_CSTRING("_VISIBLECOUNT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("getAtlas"),
	HX_CSTRING("updateAtlasInfo"),
	HX_CSTRING("get_bitmapDataKey"),
	HX_CSTRING("bitmapDataKey"),
	HX_CSTRING("set_atlas"),
	HX_CSTRING("get_atlas"),
	HX_CSTRING("atlas"),
	HX_CSTRING("_node"),
	HX_CSTRING("_atlas"),
	HX_CSTRING("_framesData"),
	HX_CSTRING("_bitmapDataKey"),
	HX_CSTRING("_tween"),
	HX_CSTRING("get_hasTween"),
	HX_CSTRING("hasTween"),
	HX_CSTRING("updateTweens"),
	HX_CSTRING("clearTweens"),
	HX_CSTRING("removeTween"),
	HX_CSTRING("addTween"),
	HX_CSTRING("toString"),
	HX_CSTRING("revive"),
	HX_CSTRING("kill"),
	HX_CSTRING("drawDebug"),
	HX_CSTRING("draw"),
	HX_CSTRING("postUpdate"),
	HX_CSTRING("update"),
	HX_CSTRING("preUpdate"),
	HX_CSTRING("destroy"),
	HX_CSTRING("autoClear"),
	HX_CSTRING("ignoreDrawDebug"),
	HX_CSTRING("cameras"),
	HX_CSTRING("alive"),
	HX_CSTRING("visible"),
	HX_CSTRING("active"),
	HX_CSTRING("exists"),
	HX_CSTRING("ID"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxBasic_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxBasic_obj::_ACTIVECOUNT,"_ACTIVECOUNT");
	HX_MARK_MEMBER_NAME(FlxBasic_obj::_VISIBLECOUNT,"_VISIBLECOUNT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxBasic_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxBasic_obj::_ACTIVECOUNT,"_ACTIVECOUNT");
	HX_VISIT_MEMBER_NAME(FlxBasic_obj::_VISIBLECOUNT,"_VISIBLECOUNT");
};

Class FlxBasic_obj::__mClass;

void FlxBasic_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxBasic"), hx::TCanCast< FlxBasic_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxBasic_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
