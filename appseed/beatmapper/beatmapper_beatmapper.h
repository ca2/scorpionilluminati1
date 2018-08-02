#pragma once


namespace beatmapper
{


   class CLASS_DECL_SCORPIONILLUMINATI_BEATMAPPER beatmapper :
      virtual public ::object
   {
   public:


      rect                    m_rect;
      ::user::impact *        m_pview;
      string                  m_strFont;


      beatmapper(::aura::application * papp);
      virtual ~beatmapper();


      virtual int64_t add_ref()
      {
         return ::object::add_ref();
      }
      virtual int64_t dec_ref()
      {
         return ::object::dec_ref();
      }

      virtual void _001OnBeatMapperDraw(::draw2d::graphics * pgraphics);

      virtual void on_layout();

   };


} // namespace beatmapper


