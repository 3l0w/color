#ifndef color_lms_convert_cmy
#define color_lms_convert_cmy

#include "../../_internal/convert.hpp"

#include "../category.hpp"


#include "../../cmy/cmy.hpp"
#include "../../rgb/rgb.hpp"
#include "../../xyz/xyz.hpp"


namespace color
 {
  namespace _internal
   {

    template
     <
       typename lms_tag_name  , ::color::constant::lms::reference_enum lms_reference_number
      ,typename cmy_tag_name 
     >
     struct convert
      <
        ::color::category::lms< lms_tag_name, lms_reference_number >
       ,::color::category::cmy<  cmy_tag_name >
      >
      {
       public:
         typedef ::color::category::lms< lms_tag_name, lms_reference_number >    lms_category_type,  category_left_type;
         typedef ::color::category::cmy< cmy_tag_name >    cmy_category_type, category_right_type;

         typedef typename ::color::trait::scalar<category_left_type>::instance_type scalar_type;

         typedef ::color::model< cmy_category_type >  cmy_model_type;
         typedef ::color::model< lms_category_type >  lms_model_type;

         typedef ::color::rgb< scalar_type >  rgb_model_type;
         typedef ::color::xyz< scalar_type >  xyz_model_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           left = lms_model_type( xyz_model_type( rgb_model_type( cmy_model_type( right ) ) ) ).container();
          }
      };

   }
 }

#endif
