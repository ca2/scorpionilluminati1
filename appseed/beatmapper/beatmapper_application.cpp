#include "framework.h"


namespace hellomultiverse
{


   application::application() :
      m_mutexAiFont(this)
   {

      m_ptemplateHelloMultiverseMain = NULL;
      m_ptemplateHelloMultiverseView = NULL;
      m_ptemplateHelloMultiverseSwitcher = NULL;

      m_strAppId = "app-core/hellomultiverse";
      m_strAppName = "app-core/hellomultiverse";
      m_strBaseSupportId = "ca2_flag";
      m_bLicense = false;

      m_etype = type_normal;

      m_strHelloMultiverseDefault = "Hello Multiverse!!";
      m_strAlternateHelloMultiverseDefault = "Hello!!";

      m_strHelloMultiverse = m_strHelloMultiverseDefault;
      m_strAlternateHelloMultiverse = m_strAlternateHelloMultiverseDefault;

      m_iErrorAiFont = -1;

      m_bLoadAiFont = false;

      m_faceAi = NULL; // FT_Face m_faceAi;

      m_bMultiverseChat = true;



   }


   application::~application()
   {
   }


   bool application::init_instance()
   {

      set_local_data_key_modifier();

      ::core::session * pcoression = m_pauraapp->m_pcoresession;

      pcoression->use_font_sel();

      System.factory().creatable_small < ::hellomultiverse::document >();
      System.factory().creatable_small < ::hellomultiverse::frame >();
      System.factory().creatable_small < ::hellomultiverse::main_frame >();
      System.factory().creatable_small < ::user::button_view >();
      System.factory().creatable_small < ::hellomultiverse::view >();
      System.factory().creatable_small < ::hellomultiverse::main_view >();
      System.factory().creatable_small < ::hellomultiverse::switcher_view >();
      System.factory().creatable_small < ::hellomultiverse::pane_view >();
      System.factory().creatable_small < ::hellomultiverse::gcom >();

      if (!::sphere::application::init_instance())
      {

         return false;

      }

      string str = handler()->m_varTopicQuery["hellomultiverse"];

      if (str.has_char())
      {

         m_strHelloMultiverse = str;

      }


      ::user::single_document_template* pDocTemplate;


      pDocTemplate = canew(::user::single_document_template(
                           this,
                           "main",
                           System.type_info < document >(),
                           System.type_info < main_frame >(),
                           System.type_info < pane_view >()));
      m_ptemplateHelloMultiverseMain = pDocTemplate;
      add_document_template(pDocTemplate);


      pDocTemplate = canew(::user::single_document_template(
                           this,
                           "main",
                           System.type_info < document >(),
                           System.type_info < frame >(),
                           System.type_info < main_view >()));
      m_ptemplateHelloMultiverseView = pDocTemplate;
      add_document_template(pDocTemplate);


      pDocTemplate = canew(::user::single_document_template(
                           this,
                           "switcher",
                           System.type_info < document >(),
                           System.type_info < frame >(),
                           System.type_info < switcher_view >()));
      m_ptemplateHelloMultiverseSwitcher = pDocTemplate;
      add_document_template(pDocTemplate);


      return true;

   }


   void application::term_application()
   {

      ::core::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

#if 0

#ifdef DEBUG

      output_debug_string("DEBUG build? (basis)");

      ASSERT(FALSE);

#else

      output_debug_string("RELEASE build? (stage)");

      ASSERT(FALSE);

#endif

#endif

      m_bMultiverseChat = !handler()->m_varTopicQuery["no_hello_edit"].is_set();

      if (m_ptemplateHelloMultiverseMain->get_document_count() == 0)
      {

         m_ptemplateHelloMultiverseMain->request_create(pcreate);

      }

      if (pcreate->m_spCommandLine->m_varFile.has_char())
      {

         m_ptemplateHelloMultiverseView->request_create(pcreate);

      }

      if (handler()->m_varTopicQuery["wfi_maximize"].is_set())
      {

         pcreate->m_spCommandLine->m_varQuery["document"].cast < document >()->get_typed_view < ::userex::pane_tab_view >()->GetTopLevelFrame()->_001WindowMaximize();

      }

      output_debug_string("\nfinished hellomultiverse::on_request");

   }


   string application::preferred_userschema()
   {

      return "core";

   }


   int64_t application::add_ref()
   {

      return ::object::add_ref();

   }

   int64_t application::dec_ref()
   {

      return ::object::dec_ref();

   }


} // namespace hellomultiverse




extern "C"
::aura::library * app_core_hellomultiverse_get_new_library(::aura::application * papp)
{

   return new ::aura::single_application_library < ::hellomultiverse::application >(papp, "app-core/hellomultiverse");

}


aura_app aura_app_core_hellomultiverse("app-core/hellomultiverse", &app_core_hellomultiverse_get_new_library);


