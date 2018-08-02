#include "framework.h"


namespace beatmapper
{


   application::application()
   {

      m_ptemplateBeatMapperMain = NULL;
      m_ptemplateBeatMapperView = NULL;

      m_strAppId = "scorpionilluminati/beatmapper";
      m_strAppName = "scorpionilluminati/beatmapper";
      m_strBaseSupportId = "ca2_flag";
      m_bLicense = false;

      m_etype = type_normal;

      m_bMultiverseChat = true;

   }


   application::~application()
   {
   }


   bool application::init_instance()
   {

      set_local_data();

      ::core::session * pcoression = &Session;

      pcoression->will_use_view_hint("font_sel");

      System.factory().creatable_small < ::beatmapper::document >();
      System.factory().creatable_small < ::beatmapper::frame >();
      System.factory().creatable_small < ::beatmapper::main_frame >();
      System.factory().creatable_small < ::user::button_view >();
      System.factory().creatable_small < ::beatmapper::view >();
      System.factory().creatable_small < ::beatmapper::main_view >();
      System.factory().creatable_small < ::beatmapper::pane_view >();

      if (!::sphere::application::init_instance())
      {

         return false;

      }

      ::user::single_document_template* pDocTemplate;

      pDocTemplate = canew(::user::single_document_template(
                           this,
                           "main",
                           System.type_info < document >(),
                           System.type_info < main_frame >(),
                           System.type_info < pane_view >()));
      m_ptemplateBeatMapperMain = pDocTemplate;
      add_document_template(pDocTemplate);


      pDocTemplate = canew(::user::single_document_template(
                           this,
                           "main",
                           System.type_info < document >(),
                           System.type_info < frame >(),
                           System.type_info < main_view >()));
      m_ptemplateBeatMapperView = pDocTemplate;
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

      if (m_ptemplateBeatMapperMain->get_document_count() == 0)
      {

         m_ptemplateBeatMapperMain->request_create(pcreate);

      }

      if (pcreate->m_spCommandLine->m_varFile.has_char())
      {

         m_ptemplateBeatMapperView->request_create(pcreate);

      }

      if (handler()->m_varTopicQuery["wfi_maximize"].is_set())
      {

         pcreate->m_spCommandLine->m_varQuery["document"].cast < document >()->get_typed_view < ::userex::pane_tab_view >()->GetTopLevelFrame()->_001WindowMaximize();

      }

      output_debug_string("\nfinished beatmapper::on_request");

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


} // namespace beatmapper




extern "C"
::aura::library * scorpionilluminati_beatmapper_get_new_library(::aura::application * papp)
{

   return new ::aura::single_application_library < ::beatmapper::application >(papp, "scorpionilluminati/beatmapper");

}


aura_app aura_scorpionilluminati_beatmapper("scorpionilluminati/beatmapper", &scorpionilluminati_beatmapper_get_new_library);


