#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_org_flixel_FlxU
#include <org/flixel/FlxU.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxInputStates
#include <org/flixel/system/input/FlxInputStates.h>
#endif
#ifndef INCLUDED_org_flixel_system_input_FlxMapObject
#include <org/flixel/system/input/FlxMapObject.h>
#endif
#ifndef INCLUDED_org_flixel_system_replay_CodeValuePair
#include <org/flixel/system/replay/CodeValuePair.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace input{

Void FlxInputStates_obj::__construct()
{
HX_STACK_PUSH("FlxInputStates::new","org/flixel/system/input/FlxInputStates.hx",29);
{
	HX_STACK_LINE(30)
	this->_total = (int)256;
	HX_STACK_LINE(32)
	this->_lookup = ::Hash_obj::__new();
	HX_STACK_LINE(33)
	this->_map = Array_obj< ::org::flixel::system::input::FlxMapObject >::__new();
	HX_STACK_LINE(34)
	::org::flixel::FlxU_obj::SetArrayLength(this->_map,this->_total);
}
;
	return null();
}

FlxInputStates_obj::~FlxInputStates_obj() { }

Dynamic FlxInputStates_obj::__CreateEmpty() { return  new FlxInputStates_obj; }
hx::ObjectPtr< FlxInputStates_obj > FlxInputStates_obj::__new()
{  hx::ObjectPtr< FlxInputStates_obj > result = new FlxInputStates_obj();
	result->__construct();
	return result;}

Dynamic FlxInputStates_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxInputStates_obj > result = new FlxInputStates_obj();
	result->__construct();
	return result;}

Void FlxInputStates_obj::destroy( ){
{
		HX_STACK_PUSH("FlxInputStates::destroy","org/flixel/system/input/FlxInputStates.hx",210);
		HX_STACK_THIS(this);
		HX_STACK_LINE(211)
		this->_lookup = null();
		HX_STACK_LINE(212)
		this->_map = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxInputStates_obj,destroy,(void))

Void FlxInputStates_obj::addKey( ::String KeyName,int KeyCode){
{
		HX_STACK_PUSH("FlxInputStates::addKey","org/flixel/system/input/FlxInputStates.hx",201);
		HX_STACK_THIS(this);
		HX_STACK_ARG(KeyName,"KeyName");
		HX_STACK_ARG(KeyCode,"KeyCode");
		HX_STACK_LINE(202)
		this->_lookup->set(KeyName,KeyCode);
		HX_STACK_LINE(203)
		this->_map[KeyCode] = ::org::flixel::system::input::FlxMapObject_obj::__new(KeyName,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxInputStates_obj,addKey,(void))

Array< ::org::flixel::system::input::FlxMapObject > FlxInputStates_obj::getIsDown( ){
	HX_STACK_PUSH("FlxInputStates::getIsDown","org/flixel/system/input/FlxInputStates.hx",181);
	HX_STACK_THIS(this);
	HX_STACK_LINE(182)
	Array< ::org::flixel::system::input::FlxMapObject > keysdown = Array_obj< ::org::flixel::system::input::FlxMapObject >::__new();		HX_STACK_VAR(keysdown,"keysdown");
	HX_STACK_LINE(183)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(184)
	while(((i < this->_total))){
		HX_STACK_LINE(186)
		::org::flixel::system::input::FlxMapObject o = this->_map->__get((i)++);		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(187)
		if (((bool((o != null())) && bool((o->current > (int)0))))){
			HX_STACK_LINE(188)
			keysdown->push(o);
		}
	}
	HX_STACK_LINE(192)
	return keysdown;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxInputStates_obj,getIsDown,return )

bool FlxInputStates_obj::any( ){
	HX_STACK_PUSH("FlxInputStates::any","org/flixel/system/input/FlxInputStates.hx",163);
	HX_STACK_THIS(this);
	HX_STACK_LINE(164)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(165)
	while(((i < this->_total))){
		HX_STACK_LINE(167)
		::org::flixel::system::input::FlxMapObject o = this->_map->__get((i)++);		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(168)
		if (((bool((o != null())) && bool((o->current > (int)0))))){
			HX_STACK_LINE(169)
			return true;
		}
	}
	HX_STACK_LINE(173)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxInputStates_obj,any,return )

int FlxInputStates_obj::getKeyCode( ::String KeyName){
	HX_STACK_PUSH("FlxInputStates::getKeyCode","org/flixel/system/input/FlxInputStates.hx",154);
	HX_STACK_THIS(this);
	HX_STACK_ARG(KeyName,"KeyName");
	HX_STACK_LINE(154)
	return this->_lookup->get(KeyName);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxInputStates_obj,getKeyCode,return )

Void FlxInputStates_obj::playback( Array< ::org::flixel::system::replay::CodeValuePair > Record){
{
		HX_STACK_PUSH("FlxInputStates::playback","org/flixel/system/input/FlxInputStates.hx",131);
		HX_STACK_THIS(this);
		HX_STACK_ARG(Record,"Record");
		HX_STACK_LINE(132)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(133)
		int l = Record->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(134)
		::org::flixel::system::replay::CodeValuePair o;		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(135)
		::org::flixel::system::input::FlxMapObject o2;		HX_STACK_VAR(o2,"o2");
		HX_STACK_LINE(136)
		while(((i < l))){
			HX_STACK_LINE(138)
			o = Record->__get((i)++);
			HX_STACK_LINE(139)
			o2 = this->_map->__get(o->code);
			HX_STACK_LINE(140)
			o2->current = o->value;
			HX_STACK_LINE(141)
			if (((o->value > (int)0))){
				HX_STACK_LINE(142)
				this->__SetField(o2->name,true,true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxInputStates_obj,playback,(void))

Array< ::org::flixel::system::replay::CodeValuePair > FlxInputStates_obj::record( ){
	HX_STACK_PUSH("FlxInputStates::record","org/flixel/system/input/FlxInputStates.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(106)
	Array< ::org::flixel::system::replay::CodeValuePair > data = null();		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(107)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(108)
	while(((i < this->_total))){
		HX_STACK_LINE(110)
		::org::flixel::system::input::FlxMapObject o = this->_map->__get((i)++);		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(111)
		if (((bool((o == null())) || bool((o->current == (int)0))))){
			HX_STACK_LINE(112)
			continue;
		}
		HX_STACK_LINE(115)
		if (((data == null()))){
			HX_STACK_LINE(116)
			data = Array_obj< ::org::flixel::system::replay::CodeValuePair >::__new();
		}
		HX_STACK_LINE(119)
		data->push(::org::flixel::system::replay::CodeValuePair_obj::__new((i - (int)1),o->current));
	}
	HX_STACK_LINE(121)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxInputStates_obj,record,return )

bool FlxInputStates_obj::justReleased( ::String Key){
	HX_STACK_PUSH("FlxInputStates::justReleased","org/flixel/system/input/FlxInputStates.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Key,"Key");
	HX_STACK_LINE(94)
	return (this->_map->__get(this->_lookup->get(Key))->current == (int)-1);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxInputStates_obj,justReleased,return )

bool FlxInputStates_obj::justPressed( ::String Key){
	HX_STACK_PUSH("FlxInputStates::justPressed","org/flixel/system/input/FlxInputStates.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Key,"Key");
	HX_STACK_LINE(84)
	return (this->_map->__get(this->_lookup->get(Key))->current == (int)2);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxInputStates_obj,justPressed,return )

bool FlxInputStates_obj::pressed( ::String Key){
	HX_STACK_PUSH("FlxInputStates::pressed","org/flixel/system/input/FlxInputStates.hx",74);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Key,"Key");
	HX_STACK_LINE(74)
	return this->__Field(Key,true);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxInputStates_obj,pressed,return )

Void FlxInputStates_obj::reset( ){
{
		HX_STACK_PUSH("FlxInputStates::reset","org/flixel/system/input/FlxInputStates.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_LINE(58)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->_total;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		while(((_g1 < _g))){
			HX_STACK_LINE(58)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(60)
			if (((this->_map->__get(i) == null()))){
				HX_STACK_LINE(60)
				continue;
			}
			HX_STACK_LINE(61)
			::org::flixel::system::input::FlxMapObject o = this->_map->__get(i);		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(62)
			this->__SetField(o->name,false,true);
			HX_STACK_LINE(63)
			o->current = (int)0;
			HX_STACK_LINE(64)
			o->last = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxInputStates_obj,reset,(void))

Void FlxInputStates_obj::update( ){
{
		HX_STACK_PUSH("FlxInputStates::update","org/flixel/system/input/FlxInputStates.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(43)
		while(((i < this->_total))){
			HX_STACK_LINE(45)
			::org::flixel::system::input::FlxMapObject o = this->_map->__get((i)++);		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(46)
			if (((o == null()))){
				HX_STACK_LINE(46)
				continue;
			}
			HX_STACK_LINE(47)
			if (((bool((o->last == (int)-1)) && bool((o->current == (int)-1))))){
				HX_STACK_LINE(47)
				o->current = (int)0;
			}
			else{
				HX_STACK_LINE(48)
				if (((bool((o->last == (int)2)) && bool((o->current == (int)2))))){
					HX_STACK_LINE(48)
					o->current = (int)1;
				}
			}
			HX_STACK_LINE(49)
			o->last = o->current;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxInputStates_obj,update,(void))


FlxInputStates_obj::FlxInputStates_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void FlxInputStates_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxInputStates);
	HX_MARK_DYNAMIC;
	HX_MARK_MEMBER_NAME(_total,"_total");
	HX_MARK_MEMBER_NAME(_map,"_map");
	HX_MARK_MEMBER_NAME(_lookup,"_lookup");
	HX_MARK_END_CLASS();
}

void FlxInputStates_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_DYNAMIC;
	HX_VISIT_MEMBER_NAME(_total,"_total");
	HX_VISIT_MEMBER_NAME(_map,"_map");
	HX_VISIT_MEMBER_NAME(_lookup,"_lookup");
}

Dynamic FlxInputStates_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"any") ) { return any_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { return _map; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"addKey") ) { return addKey_dyn(); }
		if (HX_FIELD_EQ(inName,"record") ) { return record_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_total") ) { return _total; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"pressed") ) { return pressed_dyn(); }
		if (HX_FIELD_EQ(inName,"_lookup") ) { return _lookup; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"playback") ) { return playback_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getIsDown") ) { return getIsDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getKeyCode") ) { return getKeyCode_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"justPressed") ) { return justPressed_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"justReleased") ) { return justReleased_dyn(); }
	}
	HX_CHECK_DYNAMIC_GET_FIELD(inName);
	return super::__Field(inName,inCallProp);
}

Dynamic FlxInputStates_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { _map=inValue.Cast< Array< ::org::flixel::system::input::FlxMapObject > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_total") ) { _total=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_lookup") ) { _lookup=inValue.Cast< ::Hash >(); return inValue; }
	}
	try { return super::__SetField(inName,inValue,inCallProp); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void FlxInputStates_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_total"));
	outFields->push(HX_CSTRING("_map"));
	outFields->push(HX_CSTRING("_lookup"));
	HX_APPEND_DYNAMIC_FIELDS(outFields);
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("addKey"),
	HX_CSTRING("getIsDown"),
	HX_CSTRING("any"),
	HX_CSTRING("getKeyCode"),
	HX_CSTRING("playback"),
	HX_CSTRING("record"),
	HX_CSTRING("justReleased"),
	HX_CSTRING("justPressed"),
	HX_CSTRING("pressed"),
	HX_CSTRING("reset"),
	HX_CSTRING("update"),
	HX_CSTRING("_total"),
	HX_CSTRING("_map"),
	HX_CSTRING("_lookup"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxInputStates_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxInputStates_obj::__mClass,"__mClass");
};

Class FlxInputStates_obj::__mClass;

void FlxInputStates_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.input.FlxInputStates"), hx::TCanCast< FlxInputStates_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlxInputStates_obj::__boot()
{
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input
