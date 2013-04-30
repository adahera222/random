#ifndef INCLUDED_org_flixel_system_input_FlxTouchManager
#define INCLUDED_org_flixel_system_input_FlxTouchManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/system/input/IFlxInput.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,MouseEvent)
HX_DECLARE_CLASS2(native,events,TouchEvent)
HX_DECLARE_CLASS2(org,flixel,FlxPoint)
HX_DECLARE_CLASS4(org,flixel,system,input,FlxTouch)
HX_DECLARE_CLASS4(org,flixel,system,input,FlxTouchManager)
HX_DECLARE_CLASS4(org,flixel,system,input,IFlxInput)
namespace org{
namespace flixel{
namespace system{
namespace input{


class FlxTouchManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FlxTouchManager_obj OBJ_;
		FlxTouchManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FlxTouchManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlxTouchManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::org::flixel::system::input::IFlxInput_obj *()
			{ return new ::org::flixel::system::input::IFlxInput_delegate_< FlxTouchManager_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FlxTouchManager"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void onFocusLost( );
		Dynamic onFocusLost_dyn();

		virtual Void onFocus( );
		Dynamic onFocus_dyn();

		virtual ::org::flixel::system::input::FlxTouch recycle( Float X,Float Y,int PointID);
		Dynamic recycle_dyn();

		virtual ::org::flixel::system::input::FlxTouch add( ::org::flixel::system::input::FlxTouch touch);
		Dynamic add_dyn();

		virtual Array< ::org::flixel::system::input::FlxTouch > justReleasedTouches( Array< ::org::flixel::system::input::FlxTouch > TouchArray);
		Dynamic justReleasedTouches_dyn();

		virtual Array< ::org::flixel::system::input::FlxTouch > justStartedTouches( Array< ::org::flixel::system::input::FlxTouch > TouchArray);
		Dynamic justStartedTouches_dyn();

		virtual Void handleTouchMove( ::native::events::TouchEvent FlashEvent);
		Dynamic handleTouchMove_dyn();

		virtual Void handleTouchEnd( ::native::events::TouchEvent FlashEvent);
		Dynamic handleTouchEnd_dyn();

		virtual Void handleTouchBegin( ::native::events::TouchEvent FlashEvent);
		Dynamic handleTouchBegin_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual ::org::flixel::system::input::FlxTouch getFirstTouch( );
		Dynamic getFirstTouch_dyn();

		::IntHash _touchesCache; /* REM */ 
		Array< ::org::flixel::system::input::FlxTouch > _inactiveTouches; /* REM */ 
		Array< ::org::flixel::system::input::FlxTouch > touches; /* REM */ 
		static int maxTouchPoints; /* REM */ 
};

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input

#endif /* INCLUDED_org_flixel_system_input_FlxTouchManager */ 
