#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Atlas
#include <org/flixel/system/layer/Atlas.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_Node
#include <org/flixel/system/layer/Node.h>
#endif
#ifndef INCLUDED_org_flixel_system_layer_TileSheetData
#include <org/flixel/system/layer/TileSheetData.h>
#endif
namespace org{
namespace flixel{
namespace system{
namespace layer{

Void Atlas_obj::__construct(::String name,int width,int height,hx::Null< int >  __o_borderX,hx::Null< int >  __o_borderY,::native::display::BitmapData bitmapData)
{
HX_STACK_PUSH("Atlas::new","org/flixel/system/layer/Atlas.hx",59);
int borderX = __o_borderX.Default(1);
int borderY = __o_borderY.Default(1);
{
	HX_STACK_LINE(60)
	this->nodes = ::Hash_obj::__new();
	HX_STACK_LINE(61)
	this->name = name;
	HX_STACK_LINE(63)
	if (((bitmapData == null()))){
		HX_STACK_LINE(65)
		this->root = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new((int)0,(int)0,width,height),null(),null());
		HX_STACK_LINE(66)
		this->atlasBitmapData = ::native::display::BitmapData_obj::__new(width,height,true,(int)0,null());
		HX_STACK_LINE(67)
		this->_fromBitmapData = false;
	}
	else{
		HX_STACK_LINE(71)
		this->root = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),bitmapData->get_rect(),bitmapData,name);
		HX_STACK_LINE(72)
		this->atlasBitmapData = bitmapData;
		HX_STACK_LINE(73)
		this->nodes->set(name,this->root);
		HX_STACK_LINE(74)
		this->_fromBitmapData = true;
	}
	HX_STACK_LINE(77)
	this->borderX = borderX;
	HX_STACK_LINE(78)
	this->borderY = borderY;
	HX_STACK_LINE(81)
	this->_tileSheetData = this->createTileSheetData(this->atlasBitmapData);
	HX_STACK_LINE(84)
	::org::flixel::system::layer::Atlas_obj::_atlasCache->set(name,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Atlas_obj::~Atlas_obj() { }

Dynamic Atlas_obj::__CreateEmpty() { return  new Atlas_obj; }
hx::ObjectPtr< Atlas_obj > Atlas_obj::__new(::String name,int width,int height,hx::Null< int >  __o_borderX,hx::Null< int >  __o_borderY,::native::display::BitmapData bitmapData)
{  hx::ObjectPtr< Atlas_obj > result = new Atlas_obj();
	result->__construct(name,width,height,__o_borderX,__o_borderY,bitmapData);
	return result;}

Dynamic Atlas_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Atlas_obj > result = new Atlas_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::org::flixel::system::layer::Node Atlas_obj::findNodeToInsert( int insertWidth,int insertHeight){
	HX_STACK_PUSH("Atlas::findNodeToInsert","org/flixel/system/layer/Atlas.hx",573);
	HX_STACK_THIS(this);
	HX_STACK_ARG(insertWidth,"insertWidth");
	HX_STACK_ARG(insertHeight,"insertHeight");
	HX_STACK_LINE(575)
	Array< ::org::flixel::system::layer::Node > stack = Array_obj< ::org::flixel::system::layer::Node >::__new();		HX_STACK_VAR(stack,"stack");
	HX_STACK_LINE(577)
	::org::flixel::system::layer::Node current = this->root;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(579)
	while((true)){
		HX_STACK_LINE(582)
		if (((bool(current->get_isEmpty()) && bool(current->canPlace(insertWidth,insertHeight))))){
			HX_STACK_LINE(583)
			return current;
		}
		HX_STACK_LINE(587)
		if (((bool((bool((bool((current->right != null())) && bool(current->right->canPlace(insertWidth,insertHeight)))) && bool((current->left != null())))) && bool(current->left->canPlace(insertWidth,insertHeight))))){
			HX_STACK_LINE(589)
			stack->push(current->right);
			HX_STACK_LINE(590)
			current = current->left;
		}
		else{
			HX_STACK_LINE(592)
			if (((bool((current->left != null())) && bool(current->left->canPlace(insertWidth,insertHeight))))){
				HX_STACK_LINE(593)
				current = current->left;
			}
			else{
				HX_STACK_LINE(596)
				if (((bool((current->right != null())) && bool(current->right->canPlace(insertWidth,insertHeight))))){
					HX_STACK_LINE(597)
					current = current->right;
				}
				else{
					HX_STACK_LINE(601)
					if (((stack->length > (int)0))){
						HX_STACK_LINE(603)
						current = stack->pop();
					}
					else{
						HX_STACK_LINE(608)
						return null();
					}
				}
			}
		}
	}
	HX_STACK_LINE(615)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,findNodeToInsert,return )

Void Atlas_obj::deleteSubtree( ::org::flixel::system::layer::Node node){
{
		HX_STACK_PUSH("Atlas::deleteSubtree","org/flixel/system/layer/Atlas.hx",562);
		HX_STACK_THIS(this);
		HX_STACK_ARG(node,"node");
		HX_STACK_LINE(562)
		if (((node != null()))){
			HX_STACK_LINE(565)
			if (((node->left != null()))){
				HX_STACK_LINE(565)
				this->deleteSubtree(node->left);
			}
			HX_STACK_LINE(566)
			if (((node->right != null()))){
				HX_STACK_LINE(566)
				this->deleteSubtree(node->right);
			}
			HX_STACK_LINE(567)
			node->destroy();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,deleteSubtree,(void))

::org::flixel::system::layer::Atlas Atlas_obj::clone( ::String cloneName){
	HX_STACK_PUSH("Atlas::clone","org/flixel/system/layer/Atlas.hx",544);
	HX_STACK_THIS(this);
	HX_STACK_ARG(cloneName,"cloneName");
	HX_STACK_LINE(545)
	if ((this->_fromBitmapData)){
		HX_STACK_LINE(546)
		return null();
	}
	HX_STACK_LINE(550)
	::String atlasKey = ::org::flixel::system::layer::Atlas_obj::getUniqueKey(cloneName);		HX_STACK_VAR(atlasKey,"atlasKey");
	HX_STACK_LINE(551)
	::org::flixel::system::layer::Atlas cloneAtlas = ::org::flixel::system::layer::Atlas_obj::__new(cloneName,this->get_width(),this->get_height(),this->borderX,this->borderY,null());		HX_STACK_VAR(cloneAtlas,"cloneAtlas");
	HX_STACK_LINE(552)
	cloneAtlas->createQueue();
	HX_STACK_LINE(553)
	for(::cpp::FastIterator_obj< ::org::flixel::system::layer::Node > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::layer::Node >(this->nodes->iterator());  __it->hasNext(); ){
		::org::flixel::system::layer::Node node = __it->next();
		cloneAtlas->addToQueue(node->item,node->key);
	}
	HX_STACK_LINE(557)
	cloneAtlas->generateAtlasFromQueue();
	HX_STACK_LINE(558)
	return cloneAtlas;
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,clone,return )

::org::flixel::system::layer::Node Atlas_obj::clearAndFillWith( ::native::display::BitmapData bmd){
	HX_STACK_PUSH("Atlas::clearAndFillWith","org/flixel/system/layer/Atlas.hx",518);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bmd,"bmd");
	HX_STACK_LINE(519)
	this->deleteSubtree(this->root);
	HX_STACK_LINE(520)
	this->nodes = ::Hash_obj::__new();
	HX_STACK_LINE(522)
	::org::flixel::system::layer::TileSheetData_obj::removeTileSheet(this->_tileSheetData);
	HX_STACK_LINE(524)
	if ((!(this->_fromBitmapData))){
		HX_STACK_LINE(525)
		this->atlasBitmapData->dispose();
	}
	HX_STACK_LINE(528)
	this->root = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),bmd->get_rect(),bmd,this->name);
	HX_STACK_LINE(529)
	this->atlasBitmapData = bmd;
	HX_STACK_LINE(530)
	this->nodes->set(this->name,this->root);
	HX_STACK_LINE(531)
	this->_fromBitmapData = true;
	HX_STACK_LINE(533)
	this->_tileSheetData = ::org::flixel::system::layer::TileSheetData_obj::addTileSheet(this->atlasBitmapData);
	HX_STACK_LINE(535)
	return this->root;
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,clearAndFillWith,return )

Void Atlas_obj::clear( ){
{
		HX_STACK_PUSH("Atlas::clear","org/flixel/system/layer/Atlas.hx",503);
		HX_STACK_THIS(this);
		HX_STACK_LINE(504)
		int rootWidth = this->root->get_width();		HX_STACK_VAR(rootWidth,"rootWidth");
		HX_STACK_LINE(505)
		int rootHeight = this->root->get_height();		HX_STACK_VAR(rootHeight,"rootHeight");
		HX_STACK_LINE(506)
		this->deleteSubtree(this->root);
		HX_STACK_LINE(508)
		this->root = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new((int)0,(int)0,rootWidth,rootHeight),null(),null());
		HX_STACK_LINE(509)
		this->atlasBitmapData->fillRect(this->root->rect,(int)0);
		HX_STACK_LINE(510)
		this->nodes = ::Hash_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,clear,(void))

Void Atlas_obj::destroy( ){
{
		HX_STACK_PUSH("Atlas::destroy","org/flixel/system/layer/Atlas.hx",484);
		HX_STACK_THIS(this);
		HX_STACK_LINE(485)
		this->tempStorage = null();
		HX_STACK_LINE(486)
		this->deleteSubtree(this->root);
		HX_STACK_LINE(487)
		this->root = null();
		HX_STACK_LINE(488)
		if (((bool(!(this->_fromBitmapData)) && bool((this->atlasBitmapData != null()))))){
			HX_STACK_LINE(489)
			this->atlasBitmapData->dispose();
		}
		HX_STACK_LINE(492)
		this->atlasBitmapData = null();
		HX_STACK_LINE(494)
		this->_tileSheetData = null();
		HX_STACK_LINE(496)
		this->nodes = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,destroy,(void))

Void Atlas_obj::generateAtlasFromQueue( ){
{
		HX_STACK_PUSH("Atlas::generateAtlasFromQueue","org/flixel/system/layer/Atlas.hx",465);
		HX_STACK_THIS(this);
		HX_STACK_LINE(465)
		if (((this->tempStorage != null()))){
			HX_STACK_LINE(468)
			Array< ::native::display::BitmapData > bitmaps = Array_obj< ::native::display::BitmapData >::__new();		HX_STACK_VAR(bitmaps,"bitmaps");
			HX_STACK_LINE(469)
			Array< ::String > keys = Array_obj< ::String >::__new();		HX_STACK_VAR(keys,"keys");
			HX_STACK_LINE(470)
			{
				HX_STACK_LINE(470)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Dynamic _g1 = this->tempStorage;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(470)
				while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
					HX_STACK_LINE(470)
					Dynamic obj = _g1->__GetItem(_g);		HX_STACK_VAR(obj,"obj");
					HX_STACK_LINE(470)
					++(_g);
					HX_STACK_LINE(472)
					bitmaps->push(obj->__Field(HX_CSTRING("bmd"),true));
					HX_STACK_LINE(473)
					keys->push(obj->__Field(HX_CSTRING("keyStr"),true));
				}
			}
			HX_STACK_LINE(475)
			this->addNodes(bitmaps,keys);
			HX_STACK_LINE(476)
			this->tempStorage = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,generateAtlasFromQueue,(void))

Void Atlas_obj::addToQueue( ::native::display::BitmapData data,::String key){
{
		HX_STACK_PUSH("Atlas::addToQueue","org/flixel/system/layer/Atlas.hx",452);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(key,"key");
		HX_STACK_LINE(453)
		if (((this->tempStorage == null()))){
			HX_STACK_LINE(454)
			this->tempStorage = Dynamic( Array_obj<Dynamic>::__new() );
		}
		struct _Function_1_1{
			inline static Dynamic Block( ::native::display::BitmapData &data,::String &key){
				HX_STACK_PUSH("*::closure","org/flixel/system/layer/Atlas.hx",458);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("bmd") , data,false);
					__result->Add(HX_CSTRING("keyStr") , key,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(458)
		this->tempStorage->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block(data,key));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,addToQueue,(void))

Void Atlas_obj::createQueue( ){
{
		HX_STACK_PUSH("Atlas::createQueue","org/flixel/system/layer/Atlas.hx",442);
		HX_STACK_THIS(this);
		HX_STACK_LINE(442)
		this->tempStorage = Dynamic( Array_obj<Dynamic>::__new() );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,createQueue,(void))

int Atlas_obj::bitmapSorter( ::native::display::BitmapData bmd1,::native::display::BitmapData bmd2){
	HX_STACK_PUSH("Atlas::bitmapSorter","org/flixel/system/layer/Atlas.hx",413);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bmd1,"bmd1");
	HX_STACK_ARG(bmd2,"bmd2");
	HX_STACK_LINE(414)
	if (((bmd2->get_width() == bmd1->get_width()))){
		HX_STACK_LINE(415)
		if (((bmd2->get_height() == bmd1->get_height()))){
			HX_STACK_LINE(417)
			return (int)0;
		}
		else{
			HX_STACK_LINE(420)
			if (((bmd2->get_height() > bmd1->get_height()))){
				HX_STACK_LINE(421)
				return (int)1;
			}
			else{
				HX_STACK_LINE(425)
				return (int)-1;
			}
		}
	}
	HX_STACK_LINE(430)
	if (((bmd2->get_width() > bmd1->get_width()))){
		HX_STACK_LINE(431)
		return (int)1;
	}
	HX_STACK_LINE(435)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,bitmapSorter,return )

int Atlas_obj::indexOf( Array< ::native::display::BitmapData > bitmaps,::native::display::BitmapData bmd){
	HX_STACK_PUSH("Atlas::indexOf","org/flixel/system/layer/Atlas.hx",400);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bitmaps,"bitmaps");
	HX_STACK_ARG(bmd,"bmd");
	HX_STACK_LINE(401)
	{
		HX_STACK_LINE(401)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = bitmaps->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(401)
		while(((_g1 < _g))){
			HX_STACK_LINE(401)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(403)
			if (((bitmaps->__get(i) == bmd))){
				HX_STACK_LINE(404)
				return i;
			}
		}
	}
	HX_STACK_LINE(409)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,indexOf,return )

bool Atlas_obj::addNodes( Array< ::native::display::BitmapData > bitmaps,Array< ::String > keys){
	HX_STACK_PUSH("Atlas::addNodes","org/flixel/system/layer/Atlas.hx",371);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bitmaps,"bitmaps");
	HX_STACK_ARG(keys,"keys");
	HX_STACK_LINE(372)
	int numKeys = keys->length;		HX_STACK_VAR(numKeys,"numKeys");
	HX_STACK_LINE(373)
	int numBitmaps = bitmaps->length;		HX_STACK_VAR(numBitmaps,"numBitmaps");
	HX_STACK_LINE(375)
	if (((numBitmaps != numKeys))){
		HX_STACK_LINE(376)
		return false;
	}
	HX_STACK_LINE(380)
	Array< ::native::display::BitmapData > sortedBitmaps = bitmaps->slice((int)0,bitmaps->length);		HX_STACK_VAR(sortedBitmaps,"sortedBitmaps");
	HX_STACK_LINE(381)
	sortedBitmaps->sort(this->bitmapSorter_dyn());
	HX_STACK_LINE(383)
	::org::flixel::system::layer::Node node;		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(384)
	bool result = true;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(385)
	int index;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(386)
	{
		HX_STACK_LINE(386)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = numBitmaps;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(386)
		while(((_g1 < _g))){
			HX_STACK_LINE(386)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(388)
			index = this->indexOf(bitmaps,sortedBitmaps->__get(i));
			HX_STACK_LINE(389)
			node = this->addNode(sortedBitmaps->__get(i),keys->__get(index));
			HX_STACK_LINE(390)
			if (((node == null()))){
				HX_STACK_LINE(391)
				result = false;
			}
		}
	}
	HX_STACK_LINE(396)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,addNodes,return )

::org::flixel::system::layer::Node Atlas_obj::getNodeByBitmap( ::native::display::BitmapData bitmap){
	HX_STACK_PUSH("Atlas::getNodeByBitmap","org/flixel/system/layer/Atlas.hx",352);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bitmap,"bitmap");
	HX_STACK_LINE(353)
	for(::cpp::FastIterator_obj< ::org::flixel::system::layer::Node > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::layer::Node >(this->nodes->iterator());  __it->hasNext(); ){
		::org::flixel::system::layer::Node node = __it->next();
		if (((node->item == bitmap))){
			HX_STACK_LINE(356)
			return node;
		}
;
	}
	HX_STACK_LINE(361)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,getNodeByBitmap,return )

::org::flixel::system::layer::Node Atlas_obj::getNodeByKey( ::String key){
	HX_STACK_PUSH("Atlas::getNodeByKey","org/flixel/system/layer/Atlas.hx",337);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(338)
	if (((this->hasNodeWithName(key) == true))){
		HX_STACK_LINE(339)
		return this->nodes->get(key);
	}
	HX_STACK_LINE(343)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,getNodeByKey,return )

bool Atlas_obj::hasNodeWithName( ::String nodeName){
	HX_STACK_PUSH("Atlas::hasNodeWithName","org/flixel/system/layer/Atlas.hx",327);
	HX_STACK_THIS(this);
	HX_STACK_ARG(nodeName,"nodeName");
	HX_STACK_LINE(327)
	return this->nodes->exists(nodeName);
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,hasNodeWithName,return )

int Atlas_obj::get_height( ){
	HX_STACK_PUSH("Atlas::get_height","org/flixel/system/layer/Atlas.hx",317);
	HX_STACK_THIS(this);
	HX_STACK_LINE(317)
	return this->root->get_height();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,get_height,return )

int Atlas_obj::get_width( ){
	HX_STACK_PUSH("Atlas::get_width","org/flixel/system/layer/Atlas.hx",307);
	HX_STACK_THIS(this);
	HX_STACK_LINE(307)
	return this->root->get_width();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,get_width,return )

::org::flixel::system::layer::Node Atlas_obj::addNode( ::native::display::BitmapData data,::String key){
	HX_STACK_PUSH("Atlas::addNode","org/flixel/system/layer/Atlas.hx",243);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(244)
	if (((this->hasNodeWithName(key) == true))){
		HX_STACK_LINE(245)
		return this->nodes->get(key);
	}
	HX_STACK_LINE(249)
	if (((this->root->canPlace(data->get_width(),data->get_height()) == false))){
		HX_STACK_LINE(250)
		return null();
	}
	HX_STACK_LINE(254)
	int insertWidth = (  (((data->get_width() == this->get_width()))) ? int(data->get_width()) : int((data->get_width() + this->borderX)) );		HX_STACK_VAR(insertWidth,"insertWidth");
	HX_STACK_LINE(255)
	int insertHeight = (  (((data->get_height() == this->get_height()))) ? int(data->get_height()) : int((data->get_height() + this->borderY)) );		HX_STACK_VAR(insertHeight,"insertHeight");
	HX_STACK_LINE(257)
	::org::flixel::system::layer::Node nodeToInsert = this->findNodeToInsert(insertWidth,insertHeight);		HX_STACK_VAR(nodeToInsert,"nodeToInsert");
	HX_STACK_LINE(258)
	if (((nodeToInsert != null()))){
		HX_STACK_LINE(260)
		::org::flixel::system::layer::Node firstChild;		HX_STACK_VAR(firstChild,"firstChild");
		HX_STACK_LINE(261)
		::org::flixel::system::layer::Node secondChild;		HX_STACK_VAR(secondChild,"secondChild");
		HX_STACK_LINE(262)
		::org::flixel::system::layer::Node firstGrandChild;		HX_STACK_VAR(firstGrandChild,"firstGrandChild");
		HX_STACK_LINE(263)
		::org::flixel::system::layer::Node secondGrandChild;		HX_STACK_VAR(secondGrandChild,"secondGrandChild");
		HX_STACK_LINE(265)
		int dw = (nodeToInsert->get_width() - insertWidth);		HX_STACK_VAR(dw,"dw");
		HX_STACK_LINE(266)
		int dh = (nodeToInsert->get_height() - insertHeight);		HX_STACK_VAR(dh,"dh");
		HX_STACK_LINE(268)
		if (((dw > dh))){
			HX_STACK_LINE(270)
			firstChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new(nodeToInsert->get_x(),nodeToInsert->get_y(),insertWidth,nodeToInsert->get_height()),null(),null());
			HX_STACK_LINE(271)
			secondChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new((nodeToInsert->get_x() + insertWidth),nodeToInsert->get_y(),(nodeToInsert->get_width() - insertWidth),nodeToInsert->get_height()),null(),null());
			HX_STACK_LINE(273)
			firstGrandChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new(firstChild->get_x(),firstChild->get_y(),insertWidth,insertHeight),data,key);
			HX_STACK_LINE(274)
			secondGrandChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new(firstChild->get_x(),(firstChild->get_y() + insertHeight),insertWidth,(firstChild->get_height() - insertHeight)),null(),null());
		}
		else{
			HX_STACK_LINE(278)
			firstChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new(nodeToInsert->get_x(),nodeToInsert->get_y(),nodeToInsert->get_width(),insertHeight),null(),null());
			HX_STACK_LINE(279)
			secondChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new(nodeToInsert->get_x(),(nodeToInsert->get_y() + insertHeight),nodeToInsert->get_width(),(nodeToInsert->get_height() - insertHeight)),null(),null());
			HX_STACK_LINE(281)
			firstGrandChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new(firstChild->get_x(),firstChild->get_y(),insertWidth,insertHeight),data,key);
			HX_STACK_LINE(282)
			secondGrandChild = ::org::flixel::system::layer::Node_obj::__new(hx::ObjectPtr<OBJ_>(this),::native::geom::Rectangle_obj::__new((firstChild->get_x() + insertWidth),firstChild->get_y(),(firstChild->get_width() - insertWidth),insertHeight),null(),null());
		}
		HX_STACK_LINE(285)
		firstChild->left = firstGrandChild;
		HX_STACK_LINE(286)
		firstChild->right = secondGrandChild;
		HX_STACK_LINE(288)
		nodeToInsert->left = firstChild;
		HX_STACK_LINE(289)
		nodeToInsert->right = secondChild;
		HX_STACK_LINE(291)
		this->atlasBitmapData->copyPixels(data,data->get_rect(),firstGrandChild->point,null(),null(),null());
		HX_STACK_LINE(293)
		this->nodes->set(key,firstGrandChild);
		HX_STACK_LINE(295)
		return firstGrandChild;
	}
	HX_STACK_LINE(298)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,addNode,return )

Void Atlas_obj::resize( int newWidth,int newHeight){
{
		HX_STACK_PUSH("Atlas::resize","org/flixel/system/layer/Atlas.hx",228);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newWidth,"newWidth");
		HX_STACK_ARG(newHeight,"newHeight");
		HX_STACK_LINE(229)
		this->root->rect->width = newWidth;
		HX_STACK_LINE(230)
		this->root->rect->height = newHeight;
		HX_STACK_LINE(231)
		this->atlasBitmapData->dispose();
		HX_STACK_LINE(232)
		this->atlasBitmapData = ::native::display::BitmapData_obj::__new(newWidth,newHeight,true,(int)0,null());
		HX_STACK_LINE(233)
		this->rebuildAtlas();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,resize,(void))

Void Atlas_obj::redrawAll( ){
{
		HX_STACK_PUSH("Atlas::redrawAll","org/flixel/system/layer/Atlas.hx",215);
		HX_STACK_THIS(this);
		HX_STACK_LINE(216)
		this->atlasBitmapData->fillRect(this->atlasBitmapData->get_rect(),(int)0);
		HX_STACK_LINE(218)
		for(::cpp::FastIterator_obj< ::org::flixel::system::layer::Node > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::layer::Node >(this->nodes->iterator());  __it->hasNext(); ){
			::org::flixel::system::layer::Node node = __it->next();
			this->atlasBitmapData->copyPixels(node->item,node->rect,node->point,null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,redrawAll,(void))

Void Atlas_obj::redrawNode( ::org::flixel::system::layer::Node node){
{
		HX_STACK_PUSH("Atlas::redrawNode","org/flixel/system/layer/Atlas.hx",203);
		HX_STACK_THIS(this);
		HX_STACK_ARG(node,"node");
		HX_STACK_LINE(203)
		if (((bool(this->hasNodeWithName(node->key)) && bool((this->atlasBitmapData != node->item))))){
			HX_STACK_LINE(206)
			this->atlasBitmapData->fillRect(node->rect,(int)0);
			HX_STACK_LINE(207)
			this->atlasBitmapData->copyPixels(node->item,node->rect,node->point,null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,redrawNode,(void))

Void Atlas_obj::rebuildAtlas( ){
{
		HX_STACK_PUSH("Atlas::rebuildAtlas","org/flixel/system/layer/Atlas.hx",187);
		HX_STACK_THIS(this);
		HX_STACK_LINE(188)
		this->createQueue();
		HX_STACK_LINE(189)
		for(::cpp::FastIterator_obj< ::org::flixel::system::layer::Node > *__it = ::cpp::CreateFastIterator< ::org::flixel::system::layer::Node >(this->nodes->iterator());  __it->hasNext(); ){
			::org::flixel::system::layer::Node node = __it->next();
			this->addToQueue(node->item,node->key);
		}
		HX_STACK_LINE(194)
		this->clear();
		HX_STACK_LINE(195)
		this->generateAtlasFromQueue();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,rebuildAtlas,(void))

::org::flixel::system::layer::TileSheetData Atlas_obj::createTileSheetData( ::native::display::BitmapData bitmapData){
	HX_STACK_PUSH("Atlas::createTileSheetData","org/flixel/system/layer/Atlas.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bitmapData,"bitmapData");
	HX_STACK_LINE(94)
	return ::org::flixel::system::layer::TileSheetData_obj::addTileSheet(bitmapData);
}


HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,createTileSheetData,return )

::Hash Atlas_obj::_atlasCache;

bool Atlas_obj::isExists( ::String key){
	HX_STACK_PUSH("Atlas::isExists","org/flixel/system/layer/Atlas.hx",105);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(105)
	return ::org::flixel::system::layer::Atlas_obj::_atlasCache->exists(key);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,isExists,return )

::org::flixel::system::layer::Atlas Atlas_obj::getAtlas( ::String Key,::native::display::BitmapData BmData,hx::Null< bool >  __o_Unique){
bool Unique = __o_Unique.Default(false);
	HX_STACK_PUSH("Atlas::getAtlas","org/flixel/system/layer/Atlas.hx",116);
	HX_STACK_ARG(Key,"Key");
	HX_STACK_ARG(BmData,"BmData");
	HX_STACK_ARG(Unique,"Unique");
{
		HX_STACK_LINE(117)
		bool alreadyExist = ::org::flixel::system::layer::Atlas_obj::isExists(Key);		HX_STACK_VAR(alreadyExist,"alreadyExist");
		HX_STACK_LINE(119)
		if (((bool(!(Unique)) && bool(alreadyExist)))){
			HX_STACK_LINE(120)
			return ::org::flixel::system::layer::Atlas_obj::_atlasCache->get(Key);
		}
		HX_STACK_LINE(124)
		::String AtlasKey = Key;		HX_STACK_VAR(AtlasKey,"AtlasKey");
		HX_STACK_LINE(125)
		if (((bool(Unique) && bool(alreadyExist)))){
			HX_STACK_LINE(126)
			AtlasKey = ::org::flixel::system::layer::Atlas_obj::getUniqueKey(Key);
		}
		HX_STACK_LINE(130)
		::org::flixel::system::layer::Atlas atlas = ::org::flixel::system::layer::Atlas_obj::__new(AtlasKey,BmData->get_width(),BmData->get_height(),(int)1,(int)1,BmData);		HX_STACK_VAR(atlas,"atlas");
		HX_STACK_LINE(131)
		return atlas;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Atlas_obj,getAtlas,return )

::String Atlas_obj::getUniqueKey( ::String Key){
	HX_STACK_PUSH("Atlas::getUniqueKey","org/flixel/system/layer/Atlas.hx",135);
	HX_STACK_ARG(Key,"Key");
	HX_STACK_LINE(136)
	if ((!(::org::flixel::system::layer::Atlas_obj::_atlasCache->exists(Key)))){
		HX_STACK_LINE(136)
		return Key;
	}
	HX_STACK_LINE(138)
	::String AtlasKey = Key;		HX_STACK_VAR(AtlasKey,"AtlasKey");
	HX_STACK_LINE(139)
	int i = (int)1;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(140)
	while((::org::flixel::system::layer::Atlas_obj::_atlasCache->exists((Key + i)))){
		HX_STACK_LINE(141)
		(i)++;
	}
	HX_STACK_LINE(144)
	AtlasKey = (Key + i);
	HX_STACK_LINE(145)
	return AtlasKey;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Atlas_obj,getUniqueKey,return )

Void Atlas_obj::removeAtlas( ::org::flixel::system::layer::Atlas atlas,hx::Null< bool >  __o_destroy){
bool destroy = __o_destroy.Default(false);
	HX_STACK_PUSH("Atlas::removeAtlas","org/flixel/system/layer/Atlas.hx",154);
	HX_STACK_ARG(atlas,"atlas");
	HX_STACK_ARG(destroy,"destroy");
{
		HX_STACK_LINE(155)
		::org::flixel::system::layer::Atlas currAtlas;		HX_STACK_VAR(currAtlas,"currAtlas");
		HX_STACK_LINE(156)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(::org::flixel::system::layer::Atlas_obj::_atlasCache->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(158)
				currAtlas = ::org::flixel::system::layer::Atlas_obj::_atlasCache->get(key);
				HX_STACK_LINE(159)
				if (((currAtlas == atlas))){
					HX_STACK_LINE(161)
					::org::flixel::system::layer::Atlas_obj::_atlasCache->remove(key);
					HX_STACK_LINE(162)
					if ((destroy)){
						HX_STACK_LINE(162)
						atlas->destroy();
					}
					HX_STACK_LINE(163)
					return null();
				}
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Atlas_obj,removeAtlas,(void))

Void Atlas_obj::clearAtlasCache( ){
{
		HX_STACK_PUSH("Atlas::clearAtlasCache","org/flixel/system/layer/Atlas.hx",172);
		HX_STACK_LINE(173)
		::org::flixel::system::layer::Atlas atlas;		HX_STACK_VAR(atlas,"atlas");
		HX_STACK_LINE(174)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(::org::flixel::system::layer::Atlas_obj::_atlasCache->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(176)
				atlas = ::org::flixel::system::layer::Atlas_obj::_atlasCache->get(key);
				HX_STACK_LINE(177)
				::org::flixel::system::layer::Atlas_obj::_atlasCache->remove(key);
				HX_STACK_LINE(178)
				atlas->destroy();
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Atlas_obj,clearAtlasCache,(void))


Atlas_obj::Atlas_obj()
{
}

void Atlas_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Atlas);
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(_fromBitmapData,"_fromBitmapData");
	HX_MARK_MEMBER_NAME(_tileSheetData,"_tileSheetData");
	HX_MARK_MEMBER_NAME(borderY,"borderY");
	HX_MARK_MEMBER_NAME(borderX,"borderX");
	HX_MARK_MEMBER_NAME(atlasBitmapData,"atlasBitmapData");
	HX_MARK_MEMBER_NAME(nodes,"nodes");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(root,"root");
	HX_MARK_MEMBER_NAME(tempStorage,"tempStorage");
	HX_MARK_END_CLASS();
}

void Atlas_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(_fromBitmapData,"_fromBitmapData");
	HX_VISIT_MEMBER_NAME(_tileSheetData,"_tileSheetData");
	HX_VISIT_MEMBER_NAME(borderY,"borderY");
	HX_VISIT_MEMBER_NAME(borderX,"borderX");
	HX_VISIT_MEMBER_NAME(atlasBitmapData,"atlasBitmapData");
	HX_VISIT_MEMBER_NAME(nodes,"nodes");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(root,"root");
	HX_VISIT_MEMBER_NAME(tempStorage,"tempStorage");
}

Dynamic Atlas_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"root") ) { return root; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		if (HX_FIELD_EQ(inName,"nodes") ) { return nodes; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf") ) { return indexOf_dyn(); }
		if (HX_FIELD_EQ(inName,"addNode") ) { return addNode_dyn(); }
		if (HX_FIELD_EQ(inName,"borderY") ) { return borderY; }
		if (HX_FIELD_EQ(inName,"borderX") ) { return borderX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isExists") ) { return isExists_dyn(); }
		if (HX_FIELD_EQ(inName,"getAtlas") ) { return getAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"addNodes") ) { return addNodes_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"redrawAll") ) { return redrawAll_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addToQueue") ) { return addToQueue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"redrawNode") ) { return redrawNode_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_atlasCache") ) { return _atlasCache; }
		if (HX_FIELD_EQ(inName,"removeAtlas") ) { return removeAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"createQueue") ) { return createQueue_dyn(); }
		if (HX_FIELD_EQ(inName,"tempStorage") ) { return tempStorage; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getUniqueKey") ) { return getUniqueKey_dyn(); }
		if (HX_FIELD_EQ(inName,"bitmapSorter") ) { return bitmapSorter_dyn(); }
		if (HX_FIELD_EQ(inName,"getNodeByKey") ) { return getNodeByKey_dyn(); }
		if (HX_FIELD_EQ(inName,"rebuildAtlas") ) { return rebuildAtlas_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"deleteSubtree") ) { return deleteSubtree_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_tileSheetData") ) { return _tileSheetData; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"clearAtlasCache") ) { return clearAtlasCache_dyn(); }
		if (HX_FIELD_EQ(inName,"getNodeByBitmap") ) { return getNodeByBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"hasNodeWithName") ) { return hasNodeWithName_dyn(); }
		if (HX_FIELD_EQ(inName,"_fromBitmapData") ) { return _fromBitmapData; }
		if (HX_FIELD_EQ(inName,"atlasBitmapData") ) { return atlasBitmapData; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"findNodeToInsert") ) { return findNodeToInsert_dyn(); }
		if (HX_FIELD_EQ(inName,"clearAndFillWith") ) { return clearAndFillWith_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"createTileSheetData") ) { return createTileSheetData_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"generateAtlasFromQueue") ) { return generateAtlasFromQueue_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Atlas_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"root") ) { root=inValue.Cast< ::org::flixel::system::layer::Node >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodes") ) { nodes=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"borderY") ) { borderY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderX") ) { borderX=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_atlasCache") ) { _atlasCache=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tempStorage") ) { tempStorage=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_tileSheetData") ) { _tileSheetData=inValue.Cast< ::org::flixel::system::layer::TileSheetData >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_fromBitmapData") ) { _fromBitmapData=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"atlasBitmapData") ) { atlasBitmapData=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Atlas_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("_fromBitmapData"));
	outFields->push(HX_CSTRING("_tileSheetData"));
	outFields->push(HX_CSTRING("borderY"));
	outFields->push(HX_CSTRING("borderX"));
	outFields->push(HX_CSTRING("atlasBitmapData"));
	outFields->push(HX_CSTRING("nodes"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("root"));
	outFields->push(HX_CSTRING("tempStorage"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_atlasCache"),
	HX_CSTRING("isExists"),
	HX_CSTRING("getAtlas"),
	HX_CSTRING("getUniqueKey"),
	HX_CSTRING("removeAtlas"),
	HX_CSTRING("clearAtlasCache"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("findNodeToInsert"),
	HX_CSTRING("deleteSubtree"),
	HX_CSTRING("clone"),
	HX_CSTRING("clearAndFillWith"),
	HX_CSTRING("clear"),
	HX_CSTRING("destroy"),
	HX_CSTRING("generateAtlasFromQueue"),
	HX_CSTRING("addToQueue"),
	HX_CSTRING("createQueue"),
	HX_CSTRING("bitmapSorter"),
	HX_CSTRING("indexOf"),
	HX_CSTRING("addNodes"),
	HX_CSTRING("getNodeByBitmap"),
	HX_CSTRING("getNodeByKey"),
	HX_CSTRING("hasNodeWithName"),
	HX_CSTRING("get_height"),
	HX_CSTRING("height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("width"),
	HX_CSTRING("addNode"),
	HX_CSTRING("resize"),
	HX_CSTRING("redrawAll"),
	HX_CSTRING("redrawNode"),
	HX_CSTRING("rebuildAtlas"),
	HX_CSTRING("createTileSheetData"),
	HX_CSTRING("_fromBitmapData"),
	HX_CSTRING("_tileSheetData"),
	HX_CSTRING("borderY"),
	HX_CSTRING("borderX"),
	HX_CSTRING("atlasBitmapData"),
	HX_CSTRING("nodes"),
	HX_CSTRING("name"),
	HX_CSTRING("root"),
	HX_CSTRING("tempStorage"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Atlas_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Atlas_obj::_atlasCache,"_atlasCache");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Atlas_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Atlas_obj::_atlasCache,"_atlasCache");
};

Class Atlas_obj::__mClass;

void Atlas_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.flixel.system.layer.Atlas"), hx::TCanCast< Atlas_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Atlas_obj::__boot()
{
	_atlasCache= ::Hash_obj::__new();
}

} // end namespace org
} // end namespace flixel
} // end namespace system
} // end namespace layer
