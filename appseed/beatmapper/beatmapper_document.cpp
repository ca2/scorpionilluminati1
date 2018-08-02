#include "framework.h"


namespace beatmapper
{


   document::document(::aura::application * papp) :
      object(papp),
      ::data::data_container_base(papp),
      ::user::controller(papp),
      ::user::document(papp)
   {

   }


   document::~document()
   {

   }





   void document::assert_valid() const
   {

      ::user::document::assert_valid();

   }


   void document::dump(dump_context & dumpcontext) const
   {

      ::user::document::dump(dumpcontext);

   }


   bool document::on_new_document()
   {

      return ::user::document::on_new_document();

   }


   bool document::on_open_document(var varFile)
   {

      view * pview = get_typed_view < view >();

      if(pview == NULL)
      {

         return true;

      }

      string strPath = varFile.get_file_path();


      return true;

   }


   int64_t document::add_ref()
   {

      return  ::user::document::add_ref();

   }

   int64_t document::dec_ref()
   {

      return  ::user::document::dec_ref();

   }



} // namespace beatmapper

















