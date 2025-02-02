#ifndef color_gray_convert_lms
#define color_gray_convert_lms

#include "../../_internal/convert.hpp"
#include "../../lms/lms.hpp"

#include "../../_internal/reformat.hpp"








namespace color
 {
  namespace _internal
   {

    template
     <
       typename  gray_tag_name
      ,typename   lms_tag_name, ::color::constant::lms::reference_enum lms_reference_number
     >
     struct convert
      <
        ::color::category::gray< gray_tag_name >
       ,::color::category::lms<     lms_tag_name,   lms_reference_number >
      >
      {
       public:
         typedef ::color::category::gray<   gray_tag_name >                           gray_category_type,  category_left_type;
         typedef ::color::category::lms<     lms_tag_name,   lms_reference_number >    lms_category_type, category_right_type;

         typedef typename ::color::trait::scalar<category_left_type>::instance_type scalar_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type >    reformat_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           container_left_trait_type::template set<0>( left, reformat_type::template process<0,0>( container_right_trait_type::template get<0>( right ) ) );
          }
      };

   }
 }

#endif
