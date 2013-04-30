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
#ifndef INCLUDED_org_flixel_FlxPath
#include <org/flixel/FlxPath.h>
#endif
#ifndef INCLUDED_org_flixel_plugin_DebugPathDisplay
#include <org/flixel/plugin/DebugPathDisplay.h>
#endif
namespace org{
namespace flixel{
namespace plugin{

Void DebugPathDisplay_obj::__construct()
{
HX_STACK_PUSH("DebugPathDisplay::new","org/flixel/plugin/DebugPathDisplay.hx",21);
{
	HX_STACK_LINE(22)
	super::__construct();
	HX_STACK_LINE(24)
	this->_paths = Array_obj< ::org::flixel::FlxPath >::__new();
	HX_STACK_LINE(25)
	this->active = false;
}
;
	return null();
}

DebugPathDisplay_obj::~DebugPathDisplay_obj() { }

Dynamic DebugPathDisplay_obj::__CreateEmpty() { return  new DebugPathDisplay_obj; }
hx::ObjectPtr< DebugPathDisplay_obj > DebugPathDisplay_obj::__new()
{  hx::ObjectPtr< DebugPathDisplay_obj > result = new DebugPathDisplay_obj();
	result->__construct();
	return result;}

Dynamic DebugPathDisplay_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DebugPathDisplay_obj > result = new DebugPathDisplay_obj();
	result->__construct();
	return result;}

Void DebugPathDisplay_obj::clear( ){
{
		HX_STACK_PUSH("DebugPathDisplay::clear","org/flixel/plugin/DebugPathDisplay.hx",115);
		HX_STACK_THIS(this);
		HX_STACK_LINE(116)
		if (((this->_paths != null()))){
			HX_STACK_LINE(118)
			int i = (this->_paths->length - (int)1);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(119)
			::org::flixel::FlxPath path;		HX_STACK_VAR(path,"path");
			HX_STACK_LINE(120)
			while(((i >= (int)0))){
				HX_STACK_LINE(122)
				path = this->_paths->__get((i)--);
				HX_STACK_LINE(123)
				if (((path != null()))){
					HX_STACK_LINE(124)
					path->destroy();
				}
			}
		}
		HX_STACK_LINE(130)
		this->_paths = Array_obj< ::org::flixel::FlxPath >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DebugPathDisplay_obj,clear,(void))

Void DebugPathDisplay_obj::remove( ::org::flixel::FlxPath Path){
{
		HX_STACK_PUSH("DebugPathDisplay::remove","org/flixel/plugin/DebugPathDisplay.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Path,"Path");
		struct _Function_1_1{
			inline static int Block( ::org::flixel::plugin::DebugPathDisplay_obj *__this,::org::flixel::FlxPath &Path){
				HX_STACK_PUSH("*::closure","org/flixel/plugin/DebugPathDisplay.hx",104);
				{
					HX_STACK_LINE(104)
					Dynamic array = __this->_paths;		HX_STACK_VAR(array,"array");
					int fromIndex = (int)0;		HX_STACK_VAR(fromIndex,"fromIndex");
					HX_STACK_LINE(104)
					int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(104)
					int index = (int)-1;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(104)
					{
						HX_STACK_LINE(104)
						int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(104)
						while(((_g < len))){
							HX_STACK_LINE(104)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(104)
							if (((array->__GetItem(i) == Path))){
								HX_STACK_LINE(104)
								index = i;
								HX_STACK_LINE(104)
								break;
							}
						}
					}
					HX_STACK_LINE(104)
					return index;
				}
				return null();
			}
		};
		HX_STACK_LINE(104)
		int index = _Function_1_1::Block(this,Path);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(105)
		if (((index >= (int)0))){
			HX_STACK_LINE(106)
			this->_paths->splice(index,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DebugPathDisplay_obj,remove,(void))

Void DebugPathDisplay_obj::add( ::org::flixel::FlxPath Path){
{
		HX_STACK_PUSH("DebugPathDisplay::add","org/flixel/plugin/DebugPathDisplay.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Path,"Path");
		HX_STACK_LINE(92)
		this->_paths->push(Path);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DebugPathDisplay_obj,add,(void))

Void DebugPathDisplay_obj::drawDebug( ::org::flixel::FlxCamera Camera){
{
		HX_STACK_PUSH("DebugPathDisplay::drawDebug","org/flixel/plugin/DebugPathDisplay.hx",68);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Camera,"Camera");
		HX_STACK_LINE(69)
		if (((Camera == null()))){
			HX_STACK_LINE(70)
			Camera = ::org::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(74)
		int i = (this->_paths->length - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(75)
		::org::flixel::FlxPath path;		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(76)
		while(((i >= (int)0))){
			HX_STACK_LINE(78)
			path = this->_paths->__get((i)--);
			HX_STACK_LINE(79)
			if (((bool((path != null())) && bool(!(path->ignoreDrawDebug))))){
				HX_STACK_LINE(80)
				path->drawDebug(Camera);
			}
		}
	}
return null();
}


Void DebugPathDisplay_obj::draw( ){
{
		HX_STACK_PUSH("DebugPathDisplay::draw","org/flixel/plugin/DebugPathDisplay.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_LINE(44)
		if (((bool(!(::org::flixel::FlxG_obj::visualDebug)) || bool(this->ignoreDrawDebug)))){
			HX_STACK_LINE(45)
			return null();
		}
		HX_STACK_LINE(49)
		if (((this->cameras == null()))){
			HX_STACK_LINE(50)
			this->cameras = ::org::flixel::FlxG_obj::cameras;
		}
		HX_STACK_LINE(53)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(54)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(55)
		while(((i < l))){
			HX_STACK_LINE(56)
			this->drawDebug(this->cameras->__get((i)++));
		}
	}
return null();
}


Void DebugPathDisplay_obj::destroy( ){
{
		HX_STACK_PUSH("DebugPathDisplay::destroy","org/flixel/plugin/DebugPathDisplay.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_LINE(33)
		this->clear();
		HX_STACK_LINE(34)
		this->_paths = null();
		HX_STACK_LINE(35)
		this->super::destroy();
	}
return null();
}



DebugPathDisplay_obj::DebugPathDisplay_obj()
{
}

void DebugPathDisplay_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DebugPathDisplay);
	HX_MARK_MEMBER_NAME(_paths,"_paths");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DebugPathDisplay_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_paths,"_paths");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic DebugPathDisplay_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"_paths") ) { return _paths; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DebugPathDisplay_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_paths") ) { _paths=inValue.Cast< Array< ::org::flixel::FlxPath > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DebugPathDisplay_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_paths"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clear"),
	HX_CSTRING("remove"),
	HX_CSTRING("add"),
	HX_CSTRING("drawDebug"),
	HX_CSTRING("draw"),
	HX_CSTRING("destroy"),
	HX_CSTRING("_paths"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DebugPathDisplay_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DebugPathDisplay_obj::__mClass,"__mClass");
};

Class DebugPathDisplay_obj::__mClass;

void DebugPathDisplay_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.plugin.DebugPathDisplay"), hx::TCanCast< DebugPathDisplay_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DebugPathDisplay_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace plugin
