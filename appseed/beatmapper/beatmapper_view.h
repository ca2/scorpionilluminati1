#pragma once


namespace beatmapper
{


   class CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER view :
      virtual public ::user::impact
   {
   public:


      sp(beatmapper)       m_pbeatmapper;


      view(::aura::application * papp);
      virtual ~view();

      virtual void assert_valid() const;
      virtual void dump(dump_context & dumpcontext) const;

      virtual int64_t add_ref()
      {
         return ::object::add_ref();
      }
      virtual int64_t dec_ref()
      {
         return ::object::dec_ref();
      }

      virtual void install_message_routing(::message::sender * psender);

      virtual void _001OnDraw(::draw2d::graphics * pgraphics);

      virtual void on_update(::user::impact * pSender, LPARAM lHint, object* pHint);

      ::user::document * get_document();

      virtual void on_layout();

      DECL_GEN_SIGNAL(_001OnCreate);
      DECL_GEN_SIGNAL(_001OnDestroy);

   };


} // namespace beatmapper


