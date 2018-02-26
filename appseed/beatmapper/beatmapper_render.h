//
//  beatmapper_render.h
//  scorpionilluminati_beatmapper
//
//  Created by Camilo Sasuke Tsumanuma on 8/6/15 23:27;24.
//  Copyright (c) 2015 Camilo Sasuke Tsumanuma. All rights reserved.
//


#pragma once


namespace beatmapper
{


   class CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER render :
      virtual public ::thread
   {
   public:


      class bilbo
      {
      public:

         string         m_strPath;
         bool           m_b;
         bool           m_bNew;

         bilbo();
         bilbo(string strPath);
         ~bilbo();

      };

      double                           m_dRenderFps;
      bool                             m_bDib1;

      bool                             m_bAlternate;

      bool                             m_bLite;

      bool                             m_bImageEnable;

      mutex                            m_mutexWork;
      mutex                            m_mutexDraw;
      mutex                            m_mutexSwap;
      mutex                            m_mutexDib;
      mutex                            m_mutexDib23;

      bool                             m_bNewLayout;
      bool                             m_bHelloRender;
      int                              m_cx;
      int                              m_cy;
      int                              m_cxCache1;
      int                              m_cyCache1;
      int                              m_cxTarget;
      int                              m_cyTarget;

      ::visual::fastblur               m_dibImage;
      ::draw2d::dib_sp                 m_dibOut;
      ::draw2d::dib_sp                 m_dibA;
      ::draw2d::dib_sp                 m_dibB;
      ::visual::dib_sp                 m_dibWork;
      ::visual::fastblur               m_dib;
      ::visual::fastblur               m_dibTint;
      ::visual::dib_sp                 m_dibTemplate;
      ::visual::dib_sp                 m_dibTemplate2;

      bool                             m_bVoidTransfer;
      bool                             m_bFirstDone;

      ::draw2d::font_sp                m_font;

      double                           m_dMinRadius;
      double                           m_dMaxRadius;

      string                           m_strBeatMapper;

      rect                             m_rectClient;


      mutex *                          m_pmutexText;

      view *                           m_pview;


      DWORD                            m_dwAnime;
      DWORD                            m_dwLastFast;
      DWORD                            m_dwFastAnime;
      ::visual::dib_sp                 m_dibFast;


      stringa                          m_stra23;
      string_map <::visual::dib_sp>    m_mapDib23;
      bool                             m_b23;
      uint32_t                         m_uiCurrent23;
      string                           m_strCurrent23;
      string                           m_strLast23;
      bool                             m_bFirst23;
      DWORD                            m_dw23;

      array < bilbo >                  m_bilboa;
      DWORD                            m_dwLastOk;


      bool                             m_bFast;
      bool                             m_bFastOnEmpty;

      string                           m_strNewFont;
      string                           m_strHoverFont;
      string                           m_strFont;


      render(::aura::application * papp);
      virtual ~render();


      string get_beatmapper() { synch_lock slText(m_pmutexText);  string str(m_strBeatMapper.c_str()); return str; }


      virtual void run() override;

      virtual bool initialize_render(string strId);


      virtual void full_render();
      virtual void beatmapper_render();
      virtual void beatmapper_draw();
      virtual void beatmapper_render(::draw2d::graphics * pgraphics);
      //virtual void beatmapper_render(::draw2d::graphics * pgraphics);

      virtual void beatmapper_render_full_view(::draw2d::graphics * pgraphics);
      virtual void beatmapper_render_lite_view(::draw2d::graphics * pgraphics);


      virtual void _001OnHelloDraw(::draw2d::graphics * pgraphics);

      virtual void defer_update_bilbo();

      ::visual::dib_sp & dib23(string strDib);

      virtual bool in_anime();
      virtual void beatmapper_fast_render(const string & strBeatMapper);


   };


} // namespace beatmapper


