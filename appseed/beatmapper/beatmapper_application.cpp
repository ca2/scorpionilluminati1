#include "framework.h"


namespace beatmapper
{


   application::application() :
      m_mutexAiFont(this)
   {

      m_ptemplateBeatMapperMain = NULL;
      m_ptemplateBeatMapperView = NULL;
      m_ptemplateBeatMapperSwitcher = NULL;

      m_strAppId = "scorpionilluminati/beatmapper";
      m_strAppName = "scorpionilluminati/beatmapper";
      m_strBaseSupportId = "ca2_flag";
      m_bLicense = false;

      m_etype = type_normal;

      m_strBeatMapperDefault = "Beat Mapper!!";
      m_strAlternateBeatMapperDefault = "Hello!!";

      m_strBeatMapper = m_strBeatMapperDefault;
      m_strAlternateBeatMapper = m_strAlternateBeatMapperDefault;

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

      System.factory().creatable_small < ::beatmapper::document >();
      System.factory().creatable_small < ::beatmapper::frame >();
      System.factory().creatable_small < ::beatmapper::main_frame >();
      System.factory().creatable_small < ::user::button_view >();
      System.factory().creatable_small < ::beatmapper::view >();
      System.factory().creatable_small < ::beatmapper::main_view >();
      System.factory().creatable_small < ::beatmapper::switcher_view >();
      System.factory().creatable_small < ::beatmapper::pane_view >();
      System.factory().creatable_small < ::beatmapper::gcom >();

      if (!::sphere::application::init_instance())
      {

         return false;

      }

      string str = handler()->m_varTopicQuery["beatmapper"];

      if (str.has_char())
      {

         m_strBeatMapper = str;

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


      pDocTemplate = canew(::user::single_document_template(
                           this,
                           "switcher",
                           System.type_info < document >(),
                           System.type_info < frame >(),
                           System.type_info < switcher_view >()));
      m_ptemplateBeatMapperSwitcher = pDocTemplate;
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


