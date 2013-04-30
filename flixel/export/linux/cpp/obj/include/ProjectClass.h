#ifndef INCLUDED_ProjectClass
#define INCLUDED_ProjectClass

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/flixel/FlxGame.h>
HX_DECLARE_CLASS0(ProjectClass)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(org,flixel,FlxGame)


class ProjectClass_obj : public ::org::flixel::FlxGame_obj{
	public:
		typedef ::org::flixel::FlxGame_obj super;
		typedef ProjectClass_obj OBJ_;
		ProjectClass_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ProjectClass_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ProjectClass_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ProjectClass"); }

};


#endif /* INCLUDED_ProjectClass */ 
