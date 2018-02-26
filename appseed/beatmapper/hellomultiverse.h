#pragma once


#include "sphere/sphere/sphere.h"
#include "core/filesystem/filemanager/filemanager.h"
#include "core/user/userex/userex.h"
#include "core/user/html/html/html.h"
#include "app-core/appseed/gcom/gcom/gcom.h"

#ifdef _APP_CORE_HELLOMULTIVERSE_LIBRARY
   #define CLASS_DECL_APP_CORE_HELLOMULTIVERSE  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_APP_CORE_HELLOMULTIVERSE  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace hellomultiverse
{

   class application;
   class main_view;
   class document;
   class view;

} // namespace flag


#undef App
#define App(pbaseapp) (pbaseapp->m_pcoreapp->cast_app < ::hellomultiverse::application > ())


#include "hellomultiverse_render.h"

#include "hellomultiverse_document.h"
#include "hellomultiverse_view_base.h"
#include "hellomultiverse_gcom.h"
#include "hellomultiverse_view.h"
//#include "hellomultiverse_lite_view.h"
//#include "hellomultiverse_full_view.h"
#include "hellomultiverse_main_view.h"
#include "hellomultiverse_switcher_view.h"
#include "hellomultiverse_frame.h"
#include "hellomultiverse_main_frame.h"
#include "hellomultiverse_pane_view_update_hint.h"
#include "hellomultiverse_pane_view.h"

#include "hellomultiverse_application.h"

