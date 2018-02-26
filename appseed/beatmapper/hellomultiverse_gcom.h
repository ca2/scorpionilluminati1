#pragma once


namespace hellomultiverse
{


   class CLASS_DECL_APP_CORE_HELLOMULTIVERSE gcom :
      virtual public view_base,
      virtual public ::backview::user::impact
   {
   public:


      ::visual::dib_sp        m_dibBk;
      bool                    m_bBkLoaded;


      gcom(::aura::application * papp);
      virtual ~gcom();


      virtual void assert_valid() const;
      virtual void dump(dump_context & dumpcontext) const;


      virtual void install_message_routing(::message::sender * psender);

      virtual void _001OnDraw(::draw2d::graphics * pgraphics);

      virtual void _001OnHelloDraw(::draw2d::graphics * pgraphics);

      virtual void on_update(::user::impact * pSender, LPARAM lHint, object* pHint);

      ::user::document * get_document();

      virtual void on_layout();

      DECL_GEN_SIGNAL(_001OnCreate);
      DECL_GEN_SIGNAL(_001OnDestroy);

      virtual int64_t add_ref()
      {
         return ::object::add_ref();
      }
      virtual int64_t dec_ref()
      {
         return ::object::dec_ref();
      }

   };


} // namespace hellomultiverse





















