#pragma once



namespace beatmapper
{


   class CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER application :
      virtual public ::sphere::application
   {
   public:


      enum e_type
      {

         type_normal,
         type_mili,

      };

      e_type                                 m_etype;

      bool                                   m_bMultiverseChat;

      ::user::document *                     m_pdocMenu;
      ::user::plain_edit_view *              m_prollfps;
      ::user::single_document_template *     m_ptemplateBeatMapperMain;
      ::user::single_document_template *     m_ptemplateBeatMapperView;


      application();
      virtual ~application();

      virtual string preferred_userschema() override;
      virtual bool init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::create * pcreate) override;

      virtual int64_t add_ref() override;
      virtual int64_t dec_ref() override;

   };


} // namespace beatmapper



