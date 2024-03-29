﻿#pragma once


namespace beatmapper
{


   class CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER pane_view :
      virtual public ::userex::pane_tab_view,
      virtual public ::user::form_callback
   {
   public:


      ::user::split_view *                            m_ptopviewLast;
      view *                                          m_pviewLast;
      string                                          m_strTopicTitle;


      sp(::user::document)                            m_pdocMenu;


      pane_view(::aura::application * papp);
      virtual ~pane_view();


      void on_create_view(::user::view_creator_data * pcreatordata);

      virtual void install_message_routing(::message::sender * pinterface);

      virtual void assert_valid() const;

      virtual void dump(dump_context & dumpcontext) const;

      DECL_GEN_SIGNAL(_001OnCreate);
      bool BaseOnControlEvent(::user::form_window * pview,::user::control_event * pevent);
      void on_show_view();

      virtual void on_update(::user::impact * pSender, LPARAM lHint, object* pHint);


      virtual void _001OnNcDraw(::draw2d::graphics * pgraphics);
      virtual void _001OnDraw(::draw2d::graphics * pgraphics);

   };


} // namespace beatmapper













