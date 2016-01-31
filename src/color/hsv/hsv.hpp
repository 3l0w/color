#ifndef color_hsv_hsv_
#define color_hsv_hsv_

#include "../_internal/model.hpp"

#include "./category.hpp"
#include "./place/place.hpp"

#include "./akin/akin.hpp"
#include "./trait/trait.hpp"

#include "./get/get.hpp"
#include "./set/set.hpp"
#include "./make/make.hpp"
#include "./convert/convert.hpp"
#include "./check/check.hpp"
#include "./fix/fix.hpp"


namespace color
 {
  namespace _internal
   {

    template< typename type_name >
     struct pick_hsv
      {
       typedef ::color::category::hsv_uint32 category_type;
      };


    template<> struct pick_hsv< std::uint8_t   >{ typedef ::color::category::hsv_uint8   category_type; };
    template<> struct pick_hsv< std::uint16_t  >{ typedef ::color::category::hsv_uint16  category_type; };
    template<> struct pick_hsv< std::uint32_t  >{ typedef ::color::category::hsv_uint32  category_type; };
    template<> struct pick_hsv< std::uint64_t  >{ typedef ::color::category::hsv_uint64  category_type; };
    template<> struct pick_hsv< float          >{ typedef ::color::category::hsv_float   category_type; };
    template<> struct pick_hsv< double         >{ typedef ::color::category::hsv_double  category_type; };
    template<> struct pick_hsv< long    double >{ typedef ::color::category::hsv_ldouble category_type; };
   }

  template< typename type_name >
   using hsv = ::color::_internal::model< typename ::color::_internal::pick_hsv< type_name >::category_type >;

 }

#endif 