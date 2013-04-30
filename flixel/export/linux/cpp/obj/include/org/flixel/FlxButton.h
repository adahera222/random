#ifndef INCLUDED_org_flixel_FlxButton
#define INCLUDED_org_flixel_FlxButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/FlxTypedButton.h>
HX_DECLARE_CLASS2(org,flixel,FlxBasic)
HX_DECLARE_CLASS2(org,flixel,FlxButton)
HX_DECLARE_CLASS2(org,flixel,FlxObject)
HX_DECLARE_CLASS2(org,flixel,FlxSprite)
HX_DECLARE_CLASS2(org,flixel,FlxTypedButton)
namespace org{
namespace flixel{


class FlxButton_obj : public ::org::flixel::FlxTypedButton_obj{
	public:
		typedef ::org::flixel::FlxTypedButton_obj super;
		typedef FlxButton_obj OBJ_;
		FlxButton_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);

	public:
		static hx::ObjectPtr< FlxButton_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlxButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxButton"); }

		virtual Void resetHelpers( );

		static int NORMAL; /* REM */ 
		static int HIGHLIGHT; /* REM */ 
		static int PRESSED; /* REM */ 
};

} // end namespace org
} // end namespace flixel

#endif /* INCLUDED_org_flixel_FlxButton */ 
