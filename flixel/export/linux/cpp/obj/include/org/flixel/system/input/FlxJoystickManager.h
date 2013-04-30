#ifndef INCLUDED_org_flixel_system_input_FlxJoystickManager
#define INCLUDED_org_flixel_system_input_FlxJoystickManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/system/input/IFlxInput.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,JoystickEvent)
HX_DECLARE_CLASS4(org,flixel,system,input,FlxJoystick)
HX_DECLARE_CLASS4(org,flixel,system,input,FlxJoystickManager)
HX_DECLARE_CLASS4(org,flixel,system,input,IFlxInput)
namespace org{
namespace flixel{
namespace system{
namespace input{


class FlxJoystickManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FlxJoystickManager_obj OBJ_;
		FlxJoystickManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FlxJoystickManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlxJoystickManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::org::flixel::system::input::IFlxInput_obj *()
			{ return new ::org::flixel::system::input::IFlxInput_delegate_< FlxJoystickManager_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FlxJoystickManager"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void onFocusLost( );
		Dynamic onFocusLost_dyn();

		virtual Void onFocus( );
		Dynamic onFocus_dyn();

		virtual Float set_deadZone( Float DeadZone);
		Dynamic set_deadZone_dyn();

		virtual Void handleHatMove( ::native::events::JoystickEvent FlashEvent);
		Dynamic handleHatMove_dyn();

		virtual Void handleBallMove( ::native::events::JoystickEvent FlashEvent);
		Dynamic handleBallMove_dyn();

		virtual Void handleAxisMove( ::native::events::JoystickEvent FlashEvent);
		Dynamic handleAxisMove_dyn();

		virtual Void handleButtonUp( ::native::events::JoystickEvent FlashEvent);
		Dynamic handleButtonUp_dyn();

		virtual Void handleButtonDown( ::native::events::JoystickEvent FlashEvent);
		Dynamic handleButtonDown_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual int getNumActiveJoysticks( );
		Dynamic getNumActiveJoysticks_dyn();

		virtual ::org::flixel::system::input::FlxJoystick joystick( int joystickID);
		Dynamic joystick_dyn();

		::IntHash joysticks; /* REM */ 
		int numActiveJoysticks; /* REM */ 
		Float globalDeadZone; /* REM */ 
};

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input

#endif /* INCLUDED_org_flixel_system_input_FlxJoystickManager */ 
