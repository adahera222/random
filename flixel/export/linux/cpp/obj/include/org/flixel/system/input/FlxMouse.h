#ifndef INCLUDED_org_flixel_system_input_FlxMouse
#define INCLUDED_org_flixel_system_input_FlxMouse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/FlxPoint.h>
#include <org/flixel/system/input/IFlxInput.h>
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,MouseEvent)
HX_DECLARE_CLASS2(org,flixel,FlxBasic)
HX_DECLARE_CLASS2(org,flixel,FlxCamera)
HX_DECLARE_CLASS2(org,flixel,FlxPoint)
HX_DECLARE_CLASS4(org,flixel,system,input,FlxMouse)
HX_DECLARE_CLASS4(org,flixel,system,input,IFlxInput)
HX_DECLARE_CLASS4(org,flixel,system,replay,MouseRecord)
namespace org{
namespace flixel{
namespace system{
namespace input{


class FlxMouse_obj : public ::org::flixel::FlxPoint_obj{
	public:
		typedef ::org::flixel::FlxPoint_obj super;
		typedef FlxMouse_obj OBJ_;
		FlxMouse_obj();
		Void __construct(::native::display::Sprite CursorContainer);

	public:
		static hx::ObjectPtr< FlxMouse_obj > __new(::native::display::Sprite CursorContainer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlxMouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::org::flixel::system::input::IFlxInput_obj *()
			{ return new ::org::flixel::system::input::IFlxInput_delegate_< FlxMouse_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FlxMouse"); }

		virtual bool set_systemCursor( bool value);
		Dynamic set_systemCursor_dyn();

		virtual Void onFocusLost( );
		Dynamic onFocusLost_dyn();

		virtual Void onFocus( );
		Dynamic onFocus_dyn();

		virtual Void playback( ::org::flixel::system::replay::MouseRecord Record);
		Dynamic playback_dyn();

		virtual ::org::flixel::system::replay::MouseRecord record( );
		Dynamic record_dyn();

		virtual bool justReleased( );
		Dynamic justReleased_dyn();

		virtual bool justPressed( );
		Dynamic justPressed_dyn();

		virtual bool pressed( );
		Dynamic pressed_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual ::org::flixel::FlxPoint getScreenPosition( ::org::flixel::FlxCamera Camera,::org::flixel::FlxPoint point);
		Dynamic getScreenPosition_dyn();

		virtual ::org::flixel::FlxPoint getWorldPosition( ::org::flixel::FlxCamera Camera,::org::flixel::FlxPoint point);
		Dynamic getWorldPosition_dyn();

		virtual Void updateCursor( );
		Dynamic updateCursor_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual Void unload( );
		Dynamic unload_dyn();

		virtual Void load( Dynamic Graphic,hx::Null< Float >  Scale,hx::Null< int >  XOffset,hx::Null< int >  YOffset);
		Dynamic load_dyn();

		virtual bool get_visible( );
		Dynamic get_visible_dyn();

		virtual Void hide( );
		Dynamic hide_dyn();

		virtual Void show( Dynamic Graphic,hx::Null< Float >  Scale,hx::Null< int >  XOffset,hx::Null< int >  YOffset);
		Dynamic show_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void onMouseWheel( ::native::events::MouseEvent FlashEvent);
		Dynamic onMouseWheel_dyn();

		virtual Void onMouseUp( ::native::events::MouseEvent FlashEvent);
		Dynamic onMouseUp_dyn();

		virtual Void onMouseDown( ::native::events::MouseEvent FlashEvent);
		Dynamic onMouseDown_dyn();

		bool useSystemCursor; /* REM */ 
		::org::flixel::FlxPoint _globalScreenPosition; /* REM */ 
		::org::flixel::FlxPoint _point; /* REM */ 
		int _lastWheel; /* REM */ 
		int _lastY; /* REM */ 
		int _lastX; /* REM */ 
		::native::display::Bitmap _cursor; /* REM */ 
		bool _updateCursorContainer; /* REM */ 
		::native::display::Sprite _cursorContainer; /* REM */ 
		int _last; /* REM */ 
		int _current; /* REM */ 
		bool visible; /* REM */ 
		int screenY; /* REM */ 
		int screenX; /* REM */ 
		int wheel; /* REM */ 
};

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace input

#endif /* INCLUDED_org_flixel_system_input_FlxMouse */ 
