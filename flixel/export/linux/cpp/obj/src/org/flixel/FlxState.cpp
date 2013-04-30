#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
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
#ifndef INCLUDED_org_flixel_FlxG
#include <org/flixel/FlxG.h>
#endif
#ifndef INCLUDED_org_flixel_FlxGroup
#include <org/flixel/FlxGroup.h>
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
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
namespace org{
namespace flixel{

Void FlxState_obj::__construct()
{
HX_STACK_PUSH("FlxState::new","org/flixel/FlxState.hx",74);
{
	HX_STACK_LINE(75)
	super::__construct(null());
	HX_STACK_LINE(77)
	this->persistantUpdate = false;
	HX_STACK_LINE(78)
	this->persistantDraw = true;
	HX_STACK_LINE(79)
	this->_bgColor = ::org::flixel::FlxG_obj::get_bgColor();
}
;
	return null();
}

FlxState_obj::~FlxState_obj() { }

Dynamic FlxState_obj::__CreateEmpty() { return  new FlxState_obj; }
hx::ObjectPtr< FlxState_obj > FlxState_obj::__new()
{  hx::ObjectPtr< FlxState_obj > result = new FlxState_obj();
	result->__construct();
	return result;}

Dynamic FlxState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxState_obj > result = new FlxState_obj();
	result->__construct();
	return result;}

Void FlxState_obj::postUpdate( ){
{
		HX_STACK_PUSH("FlxState::postUpdate","org/flixel/FlxState.hx",246);
		HX_STACK_THIS(this);
	}
return null();
}


Void FlxState_obj::preUpdate( ){
{
		HX_STACK_PUSH("FlxState::preUpdate","org/flixel/FlxState.hx",241);
		HX_STACK_THIS(this);
	}
return null();
}


Void FlxState_obj::onFocus( ){
{
		HX_STACK_PUSH("FlxState::onFocus","org/flixel/FlxState.hx",233);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,onFocus,(void))

Void FlxState_obj::onFocusLost( ){
{
		HX_STACK_PUSH("FlxState::onFocusLost","org/flixel/FlxState.hx",223);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,onFocusLost,(void))

Void FlxState_obj::removeAtlas( ::org::flixel::system::layer::Atlas atlas,hx::Null< bool >  __o_destroy){
bool destroy = __o_destroy.Default(false);
	HX_STACK_PUSH("FlxState::removeAtlas","org/flixel/FlxState.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(atlas,"atlas");
	HX_STACK_ARG(destroy,"destroy");
{
		HX_STACK_LINE(213)
		::org::flixel::system::layer::Atlas_obj::removeAtlas(atlas,destroy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxState_obj,removeAtlas,(void))

::org::flixel::system::layer::Atlas FlxState_obj::createAtlas( ::String atlasName,int atlasWidth,int atlasHeight){
	HX_STACK_PUSH("FlxState::createAtlas","org/flixel/FlxState.hx",202);
	HX_STACK_THIS(this);
	HX_STACK_ARG(atlasName,"atlasName");
	HX_STACK_ARG(atlasWidth,"atlasWidth");
	HX_STACK_ARG(atlasHeight,"atlasHeight");
	HX_STACK_LINE(203)
	::String key = ::org::flixel::system::layer::Atlas_obj::getUniqueKey(atlasName);		HX_STACK_VAR(key,"key");
	HX_STACK_LINE(204)
	return ::org::flixel::system::layer::Atlas_obj::__new(key,atlasWidth,atlasHeight,null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC3(FlxState_obj,createAtlas,return )

::org::flixel::system::layer::Atlas FlxState_obj::getAtlasFor( ::String KeyInBitmapCache){
	HX_STACK_PUSH("FlxState::getAtlasFor","org/flixel/FlxState.hx",176);
	HX_STACK_THIS(this);
	HX_STACK_ARG(KeyInBitmapCache,"KeyInBitmapCache");
	HX_STACK_LINE(178)
	::native::display::BitmapData bm = ::org::flixel::FlxG_obj::_cache->get(KeyInBitmapCache);		HX_STACK_VAR(bm,"bm");
	HX_STACK_LINE(179)
	if (((bm != null()))){
		HX_STACK_LINE(181)
		::org::flixel::system::layer::Atlas tempAtlas = ::org::flixel::system::layer::Atlas_obj::getAtlas(KeyInBitmapCache,bm,null());		HX_STACK_VAR(tempAtlas,"tempAtlas");
		HX_STACK_LINE(182)
		return tempAtlas;
	}
	else{
		HX_STACK_LINE(185)
		hx::Throw ((HX_CSTRING("There isn't bitmapdata in cache with key: ") + KeyInBitmapCache));
	}
	HX_STACK_LINE(191)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxState_obj,getAtlasFor,return )

Void FlxState_obj::destroy( ){
{
		HX_STACK_PUSH("FlxState::destroy","org/flixel/FlxState.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_LINE(166)
		if (((this->_subState != null()))){
			HX_STACK_LINE(166)
			this->closeSubState();
		}
		HX_STACK_LINE(167)
		this->super::destroy();
	}
return null();
}


Void FlxState_obj::subStateCloseHandler( ){
{
		HX_STACK_PUSH("FlxState::subStateCloseHandler","org/flixel/FlxState.hx",154);
		HX_STACK_THIS(this);
		HX_STACK_LINE(155)
		if (((this->_subState->closeCallback_dyn() != null()))){
			HX_STACK_LINE(156)
			this->_subState->closeCallback();
		}
		HX_STACK_LINE(160)
		this->_subState->destroy();
		HX_STACK_LINE(161)
		this->_subState = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,subStateCloseHandler,(void))

Void FlxState_obj::setSubState( ::org::flixel::FlxSubState requestedState,Dynamic closeCallback){
{
		HX_STACK_PUSH("FlxState::setSubState","org/flixel/FlxState.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(requestedState,"requestedState");
		HX_STACK_ARG(closeCallback,"closeCallback");
		HX_STACK_LINE(125)
		if (((this->_subState == requestedState))){
			HX_STACK_LINE(125)
			return null();
		}
		HX_STACK_LINE(128)
		if (((this->_subState != null()))){
			HX_STACK_LINE(129)
			this->_subState->close();
		}
		HX_STACK_LINE(134)
		this->_subState = requestedState;
		HX_STACK_LINE(136)
		if (((this->_subState != null()))){
			HX_STACK_LINE(140)
			this->_subState->_parentState = hx::ObjectPtr<OBJ_>(this);
			HX_STACK_LINE(142)
			this->_subState->closeCallback = closeCallback;
			HX_STACK_LINE(145)
			if ((!(this->persistantUpdate))){
				HX_STACK_LINE(146)
				::org::flixel::FlxG_obj::resetInput();
			}
			HX_STACK_LINE(149)
			this->_subState->create();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxState_obj,setSubState,(void))

Void FlxState_obj::closeSubState( ){
{
		HX_STACK_PUSH("FlxState::closeSubState","org/flixel/FlxState.hx",119);
		HX_STACK_THIS(this);
		HX_STACK_LINE(119)
		this->setSubState(null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,closeSubState,(void))

Void FlxState_obj::tryUpdate( ){
{
		HX_STACK_PUSH("FlxState::tryUpdate","org/flixel/FlxState.hx",103);
		HX_STACK_THIS(this);
		HX_STACK_LINE(104)
		if (((bool(this->persistantUpdate) || bool((this->_subState == null()))))){
			HX_STACK_LINE(105)
			this->update();
		}
		HX_STACK_LINE(109)
		if (((this->_subState != null()))){
			HX_STACK_LINE(110)
			this->_subState->tryUpdate();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,tryUpdate,(void))

Void FlxState_obj::draw( ){
{
		HX_STACK_PUSH("FlxState::draw","org/flixel/FlxState.hx",90);
		HX_STACK_THIS(this);
		HX_STACK_LINE(91)
		if (((bool(this->persistantDraw) || bool((this->_subState == null()))))){
			HX_STACK_LINE(92)
			this->super::draw();
		}
		HX_STACK_LINE(96)
		if (((this->_subState != null()))){
			HX_STACK_LINE(97)
			this->_subState->draw();
		}
	}
return null();
}


Void FlxState_obj::create( ){
{
		HX_STACK_PUSH("FlxState::create","org/flixel/FlxState.hx",87);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,create,(void))

int FlxState_obj::set_bgColor( int value){
	HX_STACK_PUSH("FlxState::set_bgColor","org/flixel/FlxState.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(69)
	return ::org::flixel::FlxG_obj::set_bgColor(value);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxState_obj,set_bgColor,return )

int FlxState_obj::get_bgColor( ){
	HX_STACK_PUSH("FlxState::get_bgColor","org/flixel/FlxState.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_LINE(60)
	return ::org::flixel::FlxG_obj::get_bgColor();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,get_bgColor,return )

::org::flixel::FlxSubState FlxState_obj::get_subState( ){
	HX_STACK_PUSH("FlxState::get_subState","org/flixel/FlxState.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_LINE(43)
	return this->_subState;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxState_obj,get_subState,return )


FlxState_obj::FlxState_obj()
{
}

void FlxState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxState);
	HX_MARK_MEMBER_NAME(bgColor,"bgColor");
	HX_MARK_MEMBER_NAME(_bgColor,"_bgColor");
	HX_MARK_MEMBER_NAME(subState,"subState");
	HX_MARK_MEMBER_NAME(_subState,"_subState");
	HX_MARK_MEMBER_NAME(persistantDraw,"persistantDraw");
	HX_MARK_MEMBER_NAME(persistantUpdate,"persistantUpdate");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bgColor,"bgColor");
	HX_VISIT_MEMBER_NAME(_bgColor,"_bgColor");
	HX_VISIT_MEMBER_NAME(subState,"subState");
	HX_VISIT_MEMBER_NAME(_subState,"_subState");
	HX_VISIT_MEMBER_NAME(persistantDraw,"persistantDraw");
	HX_VISIT_MEMBER_NAME(persistantUpdate,"persistantUpdate");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlxState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"bgColor") ) { return inCallProp ? get_bgColor() : bgColor; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bgColor") ) { return _bgColor; }
		if (HX_FIELD_EQ(inName,"subState") ) { return inCallProp ? get_subState() : subState; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"preUpdate") ) { return preUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"tryUpdate") ) { return tryUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"_subState") ) { return _subState; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"postUpdate") ) { return postUpdate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		if (HX_FIELD_EQ(inName,"removeAtlas") ) { return removeAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"createAtlas") ) { return createAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"getAtlasFor") ) { return getAtlasFor_dyn(); }
		if (HX_FIELD_EQ(inName,"setSubState") ) { return setSubState_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bgColor") ) { return set_bgColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bgColor") ) { return get_bgColor_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_subState") ) { return get_subState_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"closeSubState") ) { return closeSubState_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"persistantDraw") ) { return persistantDraw; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"persistantUpdate") ) { return persistantUpdate; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"subStateCloseHandler") ) { return subStateCloseHandler_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"bgColor") ) { if (inCallProp) return set_bgColor(inValue);bgColor=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bgColor") ) { _bgColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"subState") ) { subState=inValue.Cast< ::org::flixel::FlxSubState >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_subState") ) { _subState=inValue.Cast< ::org::flixel::FlxSubState >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"persistantDraw") ) { persistantDraw=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"persistantUpdate") ) { persistantUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bgColor"));
	outFields->push(HX_CSTRING("_bgColor"));
	outFields->push(HX_CSTRING("subState"));
	outFields->push(HX_CSTRING("_subState"));
	outFields->push(HX_CSTRING("persistantDraw"));
	outFields->push(HX_CSTRING("persistantUpdate"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("postUpdate"),
	HX_CSTRING("preUpdate"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("removeAtlas"),
	HX_CSTRING("createAtlas"),
	HX_CSTRING("getAtlasFor"),
	HX_CSTRING("destroy"),
	HX_CSTRING("subStateCloseHandler"),
	HX_CSTRING("setSubState"),
	HX_CSTRING("closeSubState"),
	HX_CSTRING("tryUpdate"),
	HX_CSTRING("draw"),
	HX_CSTRING("create"),
	HX_CSTRING("set_bgColor"),
	HX_CSTRING("get_bgColor"),
	HX_CSTRING("bgColor"),
	HX_CSTRING("_bgColor"),
	HX_CSTRING("get_subState"),
	HX_CSTRING("subState"),
	HX_CSTRING("_subState"),
	HX_CSTRING("persistantDraw"),
	HX_CSTRING("persistantUpdate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxState_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxState_obj::__mClass,"__mClass");
};

Class FlxState_obj::__mClass;

void FlxState_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.FlxState"), hx::TCanCast< FlxState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxState_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
