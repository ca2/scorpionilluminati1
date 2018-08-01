#pragma once


#include "sphere/sphere/sphere.h"
#include "core/filesystem/filemanager/filemanager.h"
#include "core/user/userex/userex.h"
#include "core/user/html/html/html.h"
#include "app-core/appseed/gcom/gcom/gcom.h"

#ifdef _SCORPIONILLUMINATI_BEATMAPPER_LIBRARY
   #define CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace beatmapper
{

   class application;
   class main_view;
   class document;
   class view;

} // namespace flag


#undef App
#define App(papp) (*papp->cast < ::beatmapper::application > ())


#include "beatmapper_render.h"

#include "beatmapper_document.h"
#include "beatmapper_view_base.h"
#include "beatmapper_gcom.h"
#include "beatmapper_view.h"
//#include "beatmapper_lite_view.h"
//#include "beatmapper_full_view.h"
#include "beatmapper_main_view.h"
#include "beatmapper_switcher_view.h"
#include "beatmapper_frame.h"
#include "beatmapper_main_frame.h"
#include "beatmapper_pane_view_update_hint.h"
#include "beatmapper_pane_view.h"

#include "beatmapper_application.h"

