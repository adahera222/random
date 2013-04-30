#ifndef INCLUDED_org_flixel_FlxTypedButton
#define INCLUDED_org_flixel_FlxTypedButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/FlxSprite.h>
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,media,Sound)
HX_DECLARE_CLASS2(org,flixel,FlxBasic)
HX_DECLARE_CLASS2(org,flixel,FlxCamera)
HX_DECLARE_CLASS2(org,flixel,FlxObject)
HX_DECLARE_CLASS2(org,flixel,FlxPoint)
HX_DECLARE_CLASS2(org,flixel,FlxSound)
HX_DECLARE_CLASS2(org,flixel,FlxSprite)
HX_DECLARE_CLASS2(org,flixel,FlxTypedButton)
HX_DECLARE_CLASS4(org,flixel,system,layer,Atlas)
namespace org{
namespace flixel{


class FlxTypedButton_obj : public ::org::flixel::FlxSprite_obj{
	public:
		typedef ::org::flixel::FlxSprite_obj super;
		typedef FlxTypedButton_obj OBJ_;
		FlxTypedButton_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);

	public:
		static hx::ObjectPtr< FlxTypedButton_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlxTypedButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxTypedButton"); }

		virtual ::org::flixel::system::layer::Atlas set_atlas( ::org::flixel::system::layer::Atlas value);

		virtual Void onMouseUp( ::native::events::Event event);
		Dynamic onMouseUp_dyn();

		virtual Void setSounds( ::native::media::Sound SoundOver,hx::Null< Float >  SoundOverVolume,::native::media::Sound SoundOut,hx::Null< Float >  SoundOutVolume,::native::media::Sound SoundDown,hx::Null< Float >  SoundDownVolume,::native::media::Sound SoundUp,hx::Null< Float >  SoundUpVolume);
		Dynamic setSounds_dyn();

		virtual Void draw( );

		virtual bool updateButtonStatus( ::org::flixel::FlxPoint Point,::org::flixel::FlxCamera Camera,bool JustPressed);
		Dynamic updateButtonStatus_dyn();

		virtual Void updateButton( );
		Dynamic updateButton_dyn();

		virtual Void update( );

		virtual Void preUpdate( );

		virtual Void destroy( );

		bool _initialized; /* REM */ 
		bool _pressed; /* REM */ 
		::org::flixel::FlxSound soundUp; /* REM */ 
		::org::flixel::FlxSound soundDown; /* REM */ 
		::org::flixel::FlxSound soundOut; /* REM */ 
		::org::flixel::FlxSound soundOver; /* REM */ 
		int status; /* REM */ 
		Dynamic onOut; /* REM */ 
		Dynamic &onOut_dyn() { return onOut;}
		Dynamic onOver; /* REM */ 
		Dynamic &onOver_dyn() { return onOver;}
		Dynamic onDown; /* REM */ 
		Dynamic &onDown_dyn() { return onDown;}
		Dynamic onUp; /* REM */ 
		Dynamic &onUp_dyn() { return onUp;}
		::org::flixel::FlxPoint labelOffset; /* REM */ 
		Dynamic label; /* REM */ 
		bool on; /* REM */ 
};

} // end namespace org
} // end namespace flixel

#endif /* INCLUDED_org_flixel_FlxTypedButton */ 
