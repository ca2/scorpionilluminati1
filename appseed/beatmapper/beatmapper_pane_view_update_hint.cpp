﻿#include "framework.h"


namespace beatmapper
{


   pane_view_update_hint::pane_view_update_hint()
   {

      m_eview = pane_view_none;
      m_etype = type_none;

   }


   pane_view_update_hint::~pane_view_update_hint()
   {

   }


   bool pane_view_update_hint::is_type_of(e_type e_type)
   {

      return m_etype == e_type;

   }


   void pane_view_update_hint::set_type(e_type e_type)
   {

      m_etype = e_type;

   }


} // namespace beatmapper



