#include "framework.h"


namespace beatmapper
{


   gcom::gcom(::aura::application * papp) :
      object(papp),
      m_dibBk(allocer()),
      view_base(papp)
   {

      m_bBkLoaded = false;

      if (Application.handler()->m_varTopicQuery["hello_bk"].get_string().has_char())
      {

         property_set varFile;

         varFile["url"] = Application.handler()->m_varTopicQuery["hello_bk"];
         varFile["http_set"]["raw_http"] = true;
         varFile["http_set"]["disable_common_name_cert_check"] = true;

         fork([=]()
         {

            m_bBkLoaded = m_dibBk.load_from_file(varFile);

         });

      }

      m_bEnableShowGcomBackground = true;

   }

   gcom::~gcom()
   {
   }

   void gcom::assert_valid() const
   {
      user::box::assert_valid();
   }

   void gcom::dump(dump_context & dumpcontext) const
   {
      user::box::dump(dumpcontext);
   }

   void gcom::install_message_routing(::message::sender * psender)
   {

      view_base::install_message_routing(psender);
      ::backview::user::impact::install_message_routing(psender);

      IGUI_MSG_LINK(WM_CREATE, psender, this, &gcom::_001OnCreate);
      IGUI_MSG_LINK(WM_DESTROY, psender, this, &gcom::_001OnDestroy);

   }


   void gcom::_001OnCreate(::message::message * pobj)
   {

      SCAST_PTR(::message::create, pcreate, pobj);

      m_id = "beatmapper_gcom";

      pcreate->previous();

      if (pcreate->m_bRet)
         return;

      show_gcom_background(true);

   }

   void gcom::_001OnDestroy(::message::message * pobj)
   {


   }


   void gcom::on_update(::user::impact * pSender, LPARAM lHint, object* phint)
   {

      UNREFERENCED_PARAMETER(pSender);
      UNREFERENCED_PARAMETER(lHint);
      UNREFERENCED_PARAMETER(phint);

   }


   void gcom::_001OnDraw(::draw2d::graphics * pgraphics)
   {

      view_base::_001OnDraw(pgraphics);

   }


   void gcom::_001OnHelloDraw(::draw2d::graphics * pgraphics)
   {


      rect rectClient;

      GetClientRect(rectClient);

      if (m_bBkLoaded && m_dibBk.is_set() && m_dibBk->area() > 0)
      {

         m_dibPost->get_graphics()->BitBlt(
            0, 0, MIN(rectClient.width(), m_dibBk->m_size.cx),
            MIN(rectClient.height(), m_dibBk->m_size.cy),
            m_dibBk->get_graphics());
         
         return;

      }

      if (rectClient.area() <= 0)
      {

         return;

      }

      backview::user::impact::BackViewRender(pgraphics, rectClient);

   }


   ::user::document * gcom::get_document()
   {

      return  (::user::impact::get_document());

   }





   void gcom::on_layout()
   {

      ::backview::user::impact::on_layout();

   }




} // namespace beatmapper

















