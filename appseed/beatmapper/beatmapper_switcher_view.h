﻿#pragma once


namespace beatmapper
{


   class CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER switcher_view:
      virtual public ::user::split_view
   {
   public:


      ::userex::top_view *    m_ptopview;
      view *                  m_pview;


      switcher_view(::aura::application * papp);
      virtual ~switcher_view();


      virtual void assert_valid() const;

      virtual void dump(dump_context & dumpcontext) const;

      void on_create_views();

      virtual void on_update(::user::impact * pSender,LPARAM lHint,object* pHint);

      virtual bool BaseOnControlEvent(::user::control_event * pevent);
      virtual void _001OnNcDraw(::draw2d::graphics * pgraphics);
      virtual void _001OnDraw(::draw2d::graphics * pgraphics);

   };


} // namespace beatmapper





