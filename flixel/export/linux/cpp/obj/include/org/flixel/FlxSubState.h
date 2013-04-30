#ifndef INCLUDED_org_flixel_FlxSubState
#define INCLUDED_org_flixel_FlxSubState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/FlxState.h>
HX_DECLARE_CLASS2(org,flixel,FlxBasic)
HX_DECLARE_CLASS2(org,flixel,FlxGroup)
HX_DECLARE_CLASS2(org,flixel,FlxObject)
HX_DECLARE_CLASS2(org,flixel,FlxSprite)
HX_DECLARE_CLASS2(org,flixel,FlxState)
HX_DECLARE_CLASS2(org,flixel,FlxSubState)
HX_DECLARE_CLASS2(org,flixel,FlxTypedGroup)
HX_DECLARE_CLASS3(org,flixel,system,BGSprite)
namespace org{
namespace flixel{


class FlxSubState_obj : public ::org::flixel::FlxState_obj{
	public:
		typedef ::org::flixel::FlxState_obj super;
		typedef FlxSubState_obj OBJ_;
		FlxSubState_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FlxSubState_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlxSubState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxSubState"); }

		virtual Void destroy( );

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void draw( );

		virtual int set_bgColor( int value);

		virtual int get_bgColor( );

		::org::flixel::system::BGSprite _bgSprite; /* REM */ 
		Dynamic closeCallback; /* REM */ 
		Dynamic &closeCallback_dyn() { return closeCallback;}
		::org::flixel::FlxState _parentState; /* REM */ 
};

} // end namespace org
} // end namespace flixel

#endif /* INCLUDED_org_flixel_FlxSubState */ 
