#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_filesystem_File
#include <native/filesystem/File.h>
#endif
#ifndef INCLUDED_native_net_SharedObject
#include <native/net/SharedObject.h>
#endif
#ifndef INCLUDED_native_net_SharedObjectFlushStatus
#include <native/net/SharedObjectFlushStatus.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
namespace native{
namespace net{

Void SharedObject_obj::__construct(::String name,::String localPath,Dynamic data)
{
HX_STACK_PUSH("SharedObject::new","native/net/SharedObject.hx",42);
{
	HX_STACK_LINE(44)
	super::__construct(null());
	HX_STACK_LINE(46)
	this->name = name;
	HX_STACK_LINE(47)
	this->localPath = localPath;
	HX_STACK_LINE(48)
	this->data = data;
}
;
	return null();
}

SharedObject_obj::~SharedObject_obj() { }

Dynamic SharedObject_obj::__CreateEmpty() { return  new SharedObject_obj; }
hx::ObjectPtr< SharedObject_obj > SharedObject_obj::__new(::String name,::String localPath,Dynamic data)
{  hx::ObjectPtr< SharedObject_obj > result = new SharedObject_obj();
	result->__construct(name,localPath,data);
	return result;}

Dynamic SharedObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SharedObject_obj > result = new SharedObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::native::net::SharedObjectFlushStatus SharedObject_obj::flush( hx::Null< int >  __o_minDiskSpace){
int minDiskSpace = __o_minDiskSpace.Default(0);
	HX_STACK_PUSH("SharedObject::flush","native/net/SharedObject.hx",129);
	HX_STACK_THIS(this);
	HX_STACK_ARG(minDiskSpace,"minDiskSpace");
{
		HX_STACK_LINE(131)
		::String encodedData = ::haxe::Serializer_obj::run(this->data);		HX_STACK_VAR(encodedData,"encodedData");
		HX_STACK_LINE(139)
		::String filePath = ::native::net::SharedObject_obj::getFilePath(this->name,this->localPath);		HX_STACK_VAR(filePath,"filePath");
		HX_STACK_LINE(140)
		::String folderPath = ::haxe::io::Path_obj::directory(filePath);		HX_STACK_VAR(folderPath,"folderPath");
		HX_STACK_LINE(142)
		if ((!(::sys::FileSystem_obj::exists(folderPath)))){
			HX_STACK_LINE(142)
			::native::net::SharedObject_obj::mkdir(folderPath);
		}
		HX_STACK_LINE(148)
		::sys::io::FileOutput output = ::sys::io::File_obj::write(filePath,false);		HX_STACK_VAR(output,"output");
		HX_STACK_LINE(149)
		output->writeString(encodedData);
		HX_STACK_LINE(150)
		output->close();
		HX_STACK_LINE(154)
		return ::native::net::SharedObjectFlushStatus_obj::FLUSHED_dyn();
	}
}


HX_DEFINE_DYNAMIC_FUNC1(SharedObject_obj,flush,return )

Void SharedObject_obj::clear( ){
{
		HX_STACK_PUSH("SharedObject::clear","native/net/SharedObject.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_LINE(61)
		::String filePath = ::native::net::SharedObject_obj::getFilePath(this->name,this->localPath);		HX_STACK_VAR(filePath,"filePath");
		HX_STACK_LINE(63)
		if ((::sys::FileSystem_obj::exists(filePath))){
			HX_STACK_LINE(63)
			::sys::FileSystem_obj::deleteFile(filePath);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SharedObject_obj,clear,(void))

Void SharedObject_obj::mkdir( ::String directory){
{
		HX_STACK_PUSH("SharedObject::mkdir","native/net/SharedObject.hx",75);
		HX_STACK_ARG(directory,"directory");
		HX_STACK_LINE(77)
		directory = ::StringTools_obj::replace(directory,HX_CSTRING("\\"),HX_CSTRING("/"));
		HX_STACK_LINE(78)
		::String total = HX_CSTRING("");		HX_STACK_VAR(total,"total");
		HX_STACK_LINE(80)
		if (((directory.substr((int)0,(int)1) == HX_CSTRING("/")))){
			HX_STACK_LINE(80)
			total = HX_CSTRING("/");
		}
		HX_STACK_LINE(86)
		Array< ::String > parts = directory.split(HX_CSTRING("/"));		HX_STACK_VAR(parts,"parts");
		HX_STACK_LINE(87)
		::String oldPath = HX_CSTRING("");		HX_STACK_VAR(oldPath,"oldPath");
		HX_STACK_LINE(89)
		if (((bool((parts->length > (int)0)) && bool((parts->__get((int)0).indexOf(HX_CSTRING(":"),null()) > (int)-1))))){
			HX_STACK_LINE(91)
			oldPath = ::Sys_obj::getCwd();
			HX_STACK_LINE(92)
			::Sys_obj::setCwd((parts->__get((int)0) + HX_CSTRING("\\")));
			HX_STACK_LINE(93)
			parts->shift();
		}
		HX_STACK_LINE(97)
		{
			HX_STACK_LINE(97)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(97)
			while(((_g < parts->length))){
				HX_STACK_LINE(97)
				::String part = parts->__get(_g);		HX_STACK_VAR(part,"part");
				HX_STACK_LINE(97)
				++(_g);
				HX_STACK_LINE(99)
				if (((bool((part != HX_CSTRING("."))) && bool((part != HX_CSTRING("")))))){
					HX_STACK_LINE(101)
					if (((total != HX_CSTRING("")))){
						HX_STACK_LINE(101)
						hx::AddEq(total,HX_CSTRING("/"));
					}
					HX_STACK_LINE(107)
					hx::AddEq(total,part);
					HX_STACK_LINE(109)
					if ((!(::sys::FileSystem_obj::exists(total)))){
						HX_STACK_LINE(109)
						::sys::FileSystem_obj::createDirectory(total);
					}
				}
			}
		}
		HX_STACK_LINE(119)
		if (((oldPath != HX_CSTRING("")))){
			HX_STACK_LINE(119)
			::Sys_obj::setCwd(oldPath);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SharedObject_obj,mkdir,(void))

::String SharedObject_obj::getFilePath( ::String name,::String localPath){
	HX_STACK_PUSH("SharedObject::getFilePath","native/net/SharedObject.hx",159);
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(localPath,"localPath");
	HX_STACK_LINE(161)
	::String path = ::native::filesystem::File_obj::get_applicationStorageDirectory()->nativePath;		HX_STACK_VAR(path,"path");
	HX_STACK_LINE(163)
	hx::AddEq(path,((((HX_CSTRING("/") + localPath) + HX_CSTRING("/")) + name) + HX_CSTRING(".sol")));
	HX_STACK_LINE(165)
	return path;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(SharedObject_obj,getFilePath,return )

::native::net::SharedObject SharedObject_obj::getLocal( ::String name,::String localPath,hx::Null< bool >  __o_secure){
bool secure = __o_secure.Default(false);
	HX_STACK_PUSH("SharedObject::getLocal","native/net/SharedObject.hx",170);
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(localPath,"localPath");
	HX_STACK_ARG(secure,"secure");
{
		HX_STACK_LINE(172)
		if (((localPath == null()))){
			HX_STACK_LINE(172)
			localPath = HX_CSTRING("");
		}
		HX_STACK_LINE(184)
		::String filePath = ::native::net::SharedObject_obj::getFilePath(name,localPath);		HX_STACK_VAR(filePath,"filePath");
		HX_STACK_LINE(185)
		::String rawData = HX_CSTRING("");		HX_STACK_VAR(rawData,"rawData");
		HX_STACK_LINE(187)
		if ((::sys::FileSystem_obj::exists(filePath))){
			HX_STACK_LINE(187)
			rawData = ::sys::io::File_obj::getContent(filePath);
		}
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","native/net/SharedObject.hx",195);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(195)
		Dynamic loadedData = _Function_1_1::Block();		HX_STACK_VAR(loadedData,"loadedData");
		HX_STACK_LINE(197)
		if (((bool((rawData == HX_CSTRING(""))) || bool((rawData == null()))))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","native/net/SharedObject.hx",199);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(197)
			loadedData = _Function_2_1::Block();
		}
		else{
			HX_STACK_LINE(201)
			try{
				HX_STACK_LINE(205)
				::haxe::Unserializer unserializer = ::haxe::Unserializer_obj::__new(rawData);		HX_STACK_VAR(unserializer,"unserializer");
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","native/net/SharedObject.hx",206);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("resolveEnum") , ::Type_obj::resolveEnum_dyn(),false);
							__result->Add(HX_CSTRING("resolveClass") , ::native::net::SharedObject_obj::resolveClass_dyn(),false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(206)
				unserializer->setResolver(_Function_3_1::Block());
				HX_STACK_LINE(207)
				loadedData = unserializer->unserialize();
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_STACK_LINE(211)
						::haxe::Log_obj::trace(HX_CSTRING("Could not unserialize SharedObject"),hx::SourceInfo(HX_CSTRING("SharedObject.hx"),211,HX_CSTRING("native.net.SharedObject"),HX_CSTRING("getLocal")));
						struct _Function_3_1{
							inline static Dynamic Block( ){
								HX_STACK_PUSH("*::closure","native/net/SharedObject.hx",212);
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(212)
						loadedData = _Function_3_1::Block();
					}
				}
			}
		}
		HX_STACK_LINE(218)
		::native::net::SharedObject so = ::native::net::SharedObject_obj::__new(name,localPath,loadedData);		HX_STACK_VAR(so,"so");
		HX_STACK_LINE(220)
		return so;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(SharedObject_obj,getLocal,return )

::Class SharedObject_obj::resolveClass( ::String name){
	HX_STACK_PUSH("SharedObject::resolveClass","native/net/SharedObject.hx",225);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(227)
	if (((name != null()))){
		HX_STACK_LINE(227)
		return ::Type_obj::resolveClass(::StringTools_obj::replace(name,HX_CSTRING("neash."),HX_CSTRING("native.")));
	}
	HX_STACK_LINE(233)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SharedObject_obj,resolveClass,return )


SharedObject_obj::SharedObject_obj()
{
}

void SharedObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SharedObject);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(localPath,"localPath");
	HX_MARK_MEMBER_NAME(data,"data");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SharedObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(localPath,"localPath");
	HX_VISIT_MEMBER_NAME(data,"data");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SharedObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mkdir") ) { return mkdir_dyn(); }
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getLocal") ) { return getLocal_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"localPath") ) { return localPath; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getFilePath") ) { return getFilePath_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resolveClass") ) { return resolveClass_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SharedObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"localPath") ) { localPath=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SharedObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("localPath"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("mkdir"),
	HX_CSTRING("getFilePath"),
	HX_CSTRING("getLocal"),
	HX_CSTRING("resolveClass"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("flush"),
	HX_CSTRING("clear"),
	HX_CSTRING("name"),
	HX_CSTRING("localPath"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SharedObject_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SharedObject_obj::__mClass,"__mClass");
};

Class SharedObject_obj::__mClass;

void SharedObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.net.SharedObject"), hx::TCanCast< SharedObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SharedObject_obj::__boot()
{
}

} // end namespace native
} // end namespace net
