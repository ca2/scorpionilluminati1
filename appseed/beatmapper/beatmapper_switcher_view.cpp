﻿#include "framework.h"


namespace beatmapper
{


   switcher_view::switcher_view(::aura::application * papp):
      object(papp),
      ::user::split_layout(papp),
      ::user::split_view(papp),
      place_holder_container(papp)
   {

      m_pview = NULL;

      m_ptopview = NULL;

   }


   switcher_view::~switcher_view()
   {

   }


   void switcher_view::assert_valid() const
   {

      ::user::split_view::assert_valid();

   }


   void switcher_view::dump(dump_context & dumpcontext) const
   {

      ::user::split_view::dump(dumpcontext);

   }


   void switcher_view::on_update(::user::impact * pSender,LPARAM lHint,object* phint)
   {
      ::user::split_view::on_update(pSender,lHint,phint);
   }


   void switcher_view::on_create_views()
   {

      if(get_pane_count() > 0)
         return;

      SetPaneCount(2);

      SetSplitOrientation(orientation_horizontal);

      set_position(0,24);

      initialize_split_layout();

      m_ptopview = create_view < ::userex::top_view >(NULL,::null_rect(),get_pane_holder(0),"top_view");

      if(m_ptopview == NULL)
      {

         System.simple_message_box(NULL,"Could not create folder edit view");

      }

      //SetPane(0,m_ptopview,false);

      m_pview = create_view < view >(NULL,::null_rect(),get_pane_holder(1),"beatmapper_view");

      m_pview->m_prender->m_bAlternate = true;

      if(m_pview == NULL)
      {

         System.simple_message_box(NULL,"Could not create file list ::user::impact");

      }

   }



   bool switcher_view::BaseOnControlEvent(::user::control_event * pevent)
   {

      if(pevent->m_eevent == ::user::event_button_clicked)
      {

         if(pevent->m_puie->m_id == "switcher_toggle")
         {

            sp(view) pview = m_pview;

            pview->m_prender->m_bLite = !pview->m_prender->m_bLite;

            return true;

         }
         else if(pevent->m_puie->m_id == "beatmapper_toggle")
         {

            m_pview->m_prender->m_bLite = !m_pview->m_prender->m_bLite;


            m_pview->on_layout();

            return true;

         }

      }

      return false;

   }

   void switcher_view::_001OnNcDraw(::draw2d::graphics * pgraphics)
   {

      ::user::split_view::_001OnNcDraw(pgraphics);

   }


   void switcher_view::_001OnDraw(::draw2d::graphics * pgraphics)
   {

      ::user::split_view::_001OnDraw(pgraphics);

   }


} // namespace beatmapper



