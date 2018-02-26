﻿#include "framework.h"
#include <math.h>


namespace beatmapper
{



   view::view(::aura::application * papp):
      object(papp),
      view_base(papp),
      m_dibColor(allocer()),
      m_dibAi1(allocer()),
      m_dibAi2(allocer())
   {


      oprop("font_sel") = true;


      m_flagNonClient.unsignalize(non_client_background);
      m_flagNonClient.unsignalize(non_client_focus_rect);

      m_eeffect                  = effect_none;

      m_bOkPending               = false;
      //m_dFps = 1.0 / 60.0;
      m_dFps = 0.0;


      m_bHelloLayoutOn001Layout  = false;
      m_b001LayoutIgnoreEmpty    = false;


      m_prender                  = NULL;


      m_prender = new render(get_app());

      m_prender->m_pview = this;

      m_prender->m_pmutexText = &m_mutexText;

      m_bOkPending = true;

      m_bHelloLayoutOn001Layout = true;

      m_b001LayoutIgnoreEmpty = false;

      m_ppcreutil = pcre_util::compile(get_app(), "\\:\\-\\)");

   }

   view::~view()
   {
   }

   void view::assert_valid() const
   {
      user::box::assert_valid();
   }

   void view::dump(dump_context & dumpcontext) const
   {
      user::box::dump(dumpcontext);
   }

   void view::install_message_routing(::message::sender * psender)
   {

      view_base::install_message_routing(psender);

      IGUI_MSG_LINK(message_view_update,psender,this,&view::_001OnLayout);
      IGUI_MSG_LINK(WM_CREATE,psender,this,&view::_001OnCreate);
      IGUI_MSG_LINK(WM_DESTROY, psender, this, &view::_001OnDestroy);

   }


   void view::_001OnCreate(::message::message * pobj)
   {

      SCAST_PTR(::message::create,pcreate,pobj);

      pcreate->previous();

      if(pcreate->m_bRet)
         return;

      string strId = get_document()->m_pimpactsystem->m_strMatter;

      m_prender->initialize_render(strId);

      string strText;

      data_get("cur_font",m_prender->m_strNewFont);

      data_get("cur_text",strText);

      if(GetTypedParent<::user::split_view>() != NULL)
      {

         if(GetTypedParent<::user::split_view>()->get_child_by_id("top_edit_view") != NULL)
         {
            
            sp(::user::edit_text) pedit = GetTypedParent<::user::split_view>()->get_child_by_id("top_edit_view");

            pedit->_001SetText(strText,::action::source_initialize);


         }

      }

      set_beatmapper(strText);

      if(Application.m_etype == application::type_normal)
      {

         m_prender->begin();

      }

   }


   void view::_001OnDestroy(::message::message * pobj)
   {

   }

   void view::_001OnLayout(::message::message * pobj)
   {

      synch_lock sl(m_pmutex);

      {

         synch_lock slText(&m_mutexText);

         if(m_strNewBeatMapper.is_empty())
         {

            if(m_prender->m_bFastOnEmpty)
            {

               m_prender->m_bFast = true;

            }

            return;

         }

      }

      m_prender->m_bHelloRender = true;

      if(m_bHelloLayoutOn001Layout)
      {

         m_prender->m_bNewLayout = true;

         m_bOkPending = true;

         m_prender->m_bFast = true;

      }
      else
      {

         on_layout();

      }

   }


   void view::on_update(::user::impact * pSender, LPARAM lHint, object* phint)
   {

      view_base::on_update(pSender, lHint, phint);

      ::user::view_update_hint * puh = dynamic_cast < ::user::view_update_hint *> (phint);

      if (puh != NULL)
      {

         if (puh->m_ehint == ::user::view_update_hint::hint_after_change_text)
         {

            auto * peditview = _001TypedWindow < ::userex::top_edit_view >();

            if (peditview != NULL && puh->m_pui == peditview)
            {

               string strText;

               peditview->_001GetText(strText);

               set_beatmapper(strText);

            }

         }

      }

   }




   void view::_001OnHelloDraw(::draw2d::graphics * pgraphics)
   {

      m_prender->_001OnHelloDraw(pgraphics);

   }


   ::user::document * view::get_document()
   {

      return  (::user::impact::get_document());

   }


   void view::on_layout()
   {

      rect rectClient;

      GetClientRect(rectClient);

      if(rectClient.area() <= 0)
         return;

      bool bHover = GetTypedParent < pane_view >()->m_pviewLast == this && GetTypedParent < pane_view >()->get_cur_tab_id() == "font_sel";

      if(m_prender->m_cx == rectClient.width()
            && m_prender->m_cy == rectClient.height()
            && !bHover
            && m_prender->m_strNewFont == m_prender->m_strFont)
         return;

      if (bHover)
      {

         m_prender->m_strFont = m_prender->m_strHoverFont;

      }
      else if(m_prender->m_strNewFont != m_prender->m_strFont)
      {

         m_prender->m_strFont = m_prender->m_strNewFont;
         
      }

      m_prender->m_cx = rectClient.width();

      m_prender->m_cy = rectClient.height();

      m_prender->m_rectClient = rectClient;

      m_prender->m_bNewLayout = true;

      m_bOkPending = true;

      m_prender->m_bFast = true;

   }


   string view::get_processed_beatmapper()
   {

      synch_lock slText(&m_mutexText);

      string str = get_beatmapper();

      int c = m_ppcreutil->matches(str);

//      int c = pcre2_get_ovector_count(m_pmd);

      if(c > 0)
      {
         str += "Smile for you too (pcremade |-) !!";
      }


      if(::str::begins_eat_ci(str,"image:"))
      {

         string strImage = str;

         strsize iFind = strImage.find(",");

         if(iFind >= 0)
         {

            strImage = strImage.Mid(0,iFind);

         }

         if(m_strImage != strImage)
         {

            m_strImage = strImage;


            ::fork(get_app(),[=]()
            {


               if(::str::ends_ci(strImage,".png"))
               {
               }
               else if(::str::ends_ci(strImage,".jpg"))
               {
               }
               else
               {
                  Sleep(1000);
               }

               if(m_strImage != strImage)
                  return;


               get_document()->on_open_document(m_strImage);
               //   var varFile;
               //
               //   varFile["url"] = strImage;
               //
               //   varFile["http_set"]["raw_http"] = System.url().get_server(m_strImage).find_wci("ca2") < 0;
               //
               //   ::visual::dib_sp dib(allocer());
               //
               //   if(dib.load_from_file(varFile))
               //   {
               //
               //      if(strImage == m_strImage)
               //      {

               //         *m_prender->m_dibImage = *dib;
               //      }

               //   }

            });

         }


         if(m_prender->m_dibImage.is_set() && m_prender->m_dibImage->area() > 0)
         {

            if(::str::begins_eat_ci(str,m_strImage))
            {
               ::str::begins_eat_ci(str,",");
            }

         }

      }

      if(::str::begins_eat_ci(str, "crt:"))
      {

         m_eeffect = effect_crt;

      }
      else
      {

         m_eeffect = effect_none;

      }

      return str;

   }


   string view::get_beatmapper()
   {

      synch_lock sl(&m_mutexText);

      if(m_strBeatMapper != m_strNewBeatMapper)
      {

         m_strBeatMapper = m_strNewBeatMapper;

      }

      if(m_strBeatMapper.is_empty())
      {

         if(m_prender->m_bAlternate)
         {

            if(m_dFps != 0.0)
            {
               return "Rolling " + Application.m_strAlternateBeatMapper;
            }
            else
            {
               return Application.m_strAlternateBeatMapper;
            }


         }
         else
         {

            if(m_dFps != 0.0)
            {
               return "Rolling " + Application.m_strBeatMapper;
            }
            else
            {
               return Application.m_strBeatMapper;
            }


         }

      }
      else
      {

         return m_strBeatMapper;

      }

   }


   void view::defer_check_on_draw_layout()
   {

      if (m_prender != NULL)
      {

         synch_lock sl(&m_mutexText);

         if (get_processed_beatmapper() != m_prender->m_strBeatMapper)
         {

            m_prender->m_strBeatMapper = get_processed_beatmapper().c_str(); // rationale : string allocation fork *for multithreading*

            sl.unlock();

            _001OnLayout(NULL);

         }

      }

   }


   void view::on_draw_image_layer(::draw2d::graphics * pgraphics)
   {

      if (m_prender->m_bImageEnable && m_prender->m_dibImage.is_set() && m_prender->m_dibImage->area() > 0)
         //if(m_prender->m_dibImage.is_set() && m_prender->m_dibImage->area() > 0)
      {

         //m_bFirstDone = true;

         ::rect rectWork(0, 0, m_prender->m_dibWork->get_size().cx, m_prender->m_dibWork->get_size().cy);
         ::rect rectImage(0, 0, m_prender->m_dibImage->get_size().cx, m_prender->m_dibImage->get_size().cy);

         rectImage.FitOnCenterOf(rectWork);

         m_dibPost->get_graphics()->set_alpha_mode(::draw2d::alpha_mode_set);

         m_dibPost->get_graphics()->StretchBlt(rectImage.left, rectImage.top, rectImage.width(), rectImage.height(),
                                               m_prender->m_dibImage->get_graphics(), 0, 0,
                                               m_prender->m_dibImage->get_size().cx,
                                               m_prender->m_dibImage->get_size().cy, SRCCOPY);


      }

   }

   void view::set_beatmapper(string strText)
   {

      m_strNewBeatMapper = strText;

      data_set("cur_text", strText);

   }


} // namespace beatmapper


