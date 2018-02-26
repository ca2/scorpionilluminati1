#include "framework.h"


namespace hellomultiverse
{


   main_view::main_view(::aura::application * papp):
      object(papp),
      ::user::split_layout(papp),
      ::user::split_view(papp),
      place_holder_container(papp)
   {

      m_ptopview = NULL;
      m_pview    = NULL;
      m_flagNonClient.signalize(non_client_background);
      m_flagNonClient.signalize(non_client_focus_rect);


   }


   main_view::~main_view()
   {

   }


   void main_view::assert_valid() const
   {

      ::user::split_view::assert_valid();

   }


   void main_view::dump(dump_context & dumpcontext) const
   {

      ::user::split_view::dump(dumpcontext);

   }


   void main_view::on_update(::user::impact * pSender,LPARAM lHint,object* phint)
   {
      
       ::user::split_view::on_update(pSender,lHint,phint);
      
   }


   void main_view::on_create_views()
   {

      if(get_pane_count() > 0)
         return;

      int iPane;

      if (Application.m_bMultiverseChat)
      {

         SetPaneCount(2);

         SetSplitOrientation(orientation_horizontal);

         set_position(0, 31);

         initialize_split_layout();

         m_ptopview = create_view < ::userex::top_view >(NULL, ::null_rect(), NULL, "top_view");

         if (m_ptopview == NULL)
         {

            System.simple_message_box(NULL, "Could not create folder edit view");

         }

         SetPane(0, m_ptopview, false);

         iPane = 1;

      }
      else
      {

         SetPaneCount(1);

         initialize_split_layout();

         iPane = 0;

      }

      //m_pview = create_view < lite_view >();

      m_pview = create_view < view >(NULL,::null_rect(),get_pane_holder(iPane), "hellomultiverse_view");

      if(m_pview == NULL)
      {

         System.simple_message_box(NULL,"Could not create file list ::user::impact");

      }

      sp(::userex::top_edit_view) peditview = get_child_by_id("top_edit_view");

      if(peditview.is_set())
      {

         string strText;

         m_pview->data_get("cur_text",strText);

         peditview->_001SetText(strText, ::action::source_initialize);

      }

//      SetPane(iPane,m_pview,false);

   }

   
   void main_view::_001OnNcDraw(::draw2d::graphics * pgraphics)
   {

      ::user::split_view::_001OnNcDraw(pgraphics);

   }


   void main_view::_001OnDraw(::draw2d::graphics * pgraphics)
   {

      ::user::split_view::_001OnDraw(pgraphics);

   }


   bool main_view::BaseOnControlEvent(::user::control_event * pevent)
   {

      if(pevent->m_eevent == ::user::event_button_clicked)
      {

         if(pevent->m_puie->m_id == "hellomultiverse_toggle")
         {

            m_pview->m_prender->m_bLite = !m_pview->m_prender->m_bLite;


            m_pview->on_layout();

            return true;

         }

      }

      return false;

   }

} // namespace hellomultiverse



