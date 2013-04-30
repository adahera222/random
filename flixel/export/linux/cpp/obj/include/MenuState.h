#ifndef INCLUDED_MenuState
#define INCLUDED_MenuState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/FlxState.h>
HX_DECLARE_CLASS0(MenuState)
HX_DECLARE_CLASS2(org,flixel,FlxBasic)
HX_DECLARE_CLASS2(org,flixel,FlxGroup)
HX_DECLARE_CLASS2(org,flixel,FlxState)
HX_DECLARE_CLASS2(org,flixel,FlxTypedGroup)


class MenuState_obj : public ::org::flixel::FlxState_obj{
	public:
		typedef ::org::flixel::FlxState_obj super;
		typedef MenuState_obj OBJ_;
		MenuState_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MenuState_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MenuState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MenuState"); }

		virtual Void update( );

		virtual Void destroy( );

		virtual Void create( );

};


#endif /* INCLUDED_MenuState */ 
