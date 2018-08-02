#include "framework.h"
#include <math.h>


namespace beatmapper
{


   pane_view::pane_view(::aura::application * papp) :
      object(papp),
      ::user::tab_view(papp),
      ::userex::pane_tab_view(papp),
      place_holder_container(papp)
   {

      m_pviewLast = NULL;

   }


   pane_view::~pane_view()
   {

   }


   void pane_view::assert_valid() const
   {

      ::user::impact::assert_valid();

   }


   void pane_view::dump(dump_context & dumpcontext) const
   {

      ::user::impact::dump(dumpcontext);

   }


   void pane_view::install_message_routing(::message::sender * pinterface)
   {

      ::userex::pane_tab_view::install_message_routing(pinterface);

      IGUI_MSG_LINK(WM_CREATE, pinterface, this, &pane_view::_001OnCreate);

   }


   void pane_view::_001OnCreate(::message::message * pobj)
   {

      if(pobj->previous())
         return;

      set_tab("Menu",::beatmapper::PaneViewMenu);
      set_tab("beatmapper", ::beatmapper::PaneViewBeatMapper);
      set_tab("Font","font_sel");
      set_tab("Open", "file_manager");

      set_cur_tab_by_id(::beatmapper::PaneViewBeatMapper);

   }


   void pane_view::_001OnNcDraw(::draw2d::graphics * pgraphics)
   {

      ::userex::pane_tab_view::_001OnNcDraw(pgraphics);

   }


   void pane_view::_001OnDraw(::draw2d::graphics * pgraphics)
   {

      ::userex::pane_tab_view::_001OnDraw(pgraphics);

   }


   void pane_view::on_show_view()
   {

      ::userex::pane_tab_view::on_show_view();
      string strId = get_view_id();
      stringa stra;

      stra.explode("->:<-",strId);

      if (get_pane_by_id(::beatmapper::PaneViewMenu) != NULL && get_pane_by_id(::beatmapper::PaneViewMenu)->m_pholder != NULL)
      {

         get_pane_by_id(::beatmapper::PaneViewMenu)->m_pholder->ShowWindow(SW_HIDE);

      }

      if(get_view_id() == ::beatmapper::PaneViewBeatMapper)
      {

         if(get_pane_by_id("file_manager") != NULL && get_pane_by_id("file_manager")->m_pholder != NULL)
         {

            get_pane_by_id("file_manager")->m_pholder->ShowWindow(SW_HIDE);

         }

         if (get_pane_by_id("font_sel") != NULL && get_pane_by_id("font_sel")->m_pholder != NULL)
         {

            get_pane_by_id("font_sel")->m_pholder->ShowWindow(SW_HIDE);

         }

         m_pviewLast = NULL;

         if(get_view_id() == ::beatmapper::PaneViewBeatMapper)
         {

            m_pviewLast = dynamic_cast < view * > (get_pane_by_id(::beatmapper::PaneViewBeatMapper)->m_pholder->get_child_by_id("beatmapper_view"));
            m_pviewLast->set_need_layout();
            m_strTopicTitle = get_pane_by_id(::beatmapper::PaneViewBeatMapper)->m_straTitle.implode(" ");

         }

      }
      else if (get_view_id() == ::beatmapper::PaneViewMenu)
      {

         m_pdocMenu->open_document("matter://menu.html");

      }
      else if (get_view_id() == "font_sel")
      {

         sp(::user::font_list_view) pfontview = get_pane_by_id("font_sel")->m_pholder->get_child_by_id("font_list_view");

         if (m_pviewLast != NULL && pfontview.is_set())
         {

            pfontview->set_sel_by_name(m_pviewLast->m_pbeatmapper->m_strFont);

         }

      }

   }


   void pane_view::on_create_view(::user::view_creator_data * pcreatordata)
   {

      switch(pcreatordata->m_id)
      {
      case PaneViewMenu:
      {

         m_pdocMenu = Application.create_child_form(this,pcreatordata->m_pholder);

         ::user::impact * pview = m_pdocMenu->get_view(0);

         m_pviewdata->m_pwnd = pview->GetParentFrame();

      }
      break;
      case PaneViewBeatMapper:
      {

         Application.m_ptemplateBeatMapperView->create_subdocument(pcreatordata);

      }
      break;
      }

      ::userex::pane_tab_view::on_create_view(pcreatordata);

   }


   bool pane_view::BaseOnControlEvent(::user::form_window * pview,::user::control_event * pevent)
   {

      if(m_pdocMenu != NULL && dynamic_cast < ::user::impact * > (pview) == m_pdocMenu->get_view(0) && pevent->m_puie != NULL)
      {

         if(pevent->m_eevent == ::user::event_after_change_text)
         {


         }
         else if (pevent->m_eevent == ::user::event_set_check && pevent->m_puie != NULL)
         {

            string strCheck = pevent->m_puie->m_id;


            if (::str::begins_eat_ci(strCheck, "bilbo"))
            {

               if (pevent->m_puie != NULL && !pevent->m_actioncontext.is_source(::action::source_initialize)
                     && !pevent->m_actioncontext.is_source(::action::source_sync))
               {

                  int iCheck = atoi(strCheck);

                  sp(::user::check) pcheck = pevent->m_puie;

               }

            }

         }

      }

      return false;

   }


   void pane_view::on_update(::user::impact * pSender, LPARAM lHint, object* phint)
   {

      ::user::view_update_hint * puh = dynamic_cast <::user::view_update_hint *> (phint);

      if (puh != NULL)
      {

         if (puh->m_ehint == ::user::view_update_hint::hint_control_event
               && puh->m_pui == m_pfontview
               && m_pviewLast != NULL)
         {

            if(puh->m_pusercontrolevent->m_eevent == ::user::event_after_change_cur_sel)
            {

               string strFont = m_pfontview->m_pview->get_cur_sel_face_name();

            }
            else if (puh->m_pusercontrolevent->m_eevent == ::user::event_after_change_cur_hover)
            {

               string strFont = m_pfontview->m_pview->get_cur_hover_face_name();

            }

         }

      }

      ::userex::pane_tab_view::on_update(pSender, lHint, phint);

   }


} // namespace beatmapper





