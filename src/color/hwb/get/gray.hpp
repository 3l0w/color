#ifndef color_hwb_get_gray
#define color_hwb_get_gray

// ::color::get::gray( c )

#include "../../gray/place/place.hpp"
#include "../../gray/akin/hwb.hpp"
#include "../../gray/trait/component.hpp"

#include "../category.hpp"

#include "../../_internal/reformat.hpp"
#include "../../generic/trait/scalar.hpp"




 namespace color
  {
   namespace get
    {

     template< typename tag_name >
      inline
      typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hwb<tag_name> >::akin_type >::return_type
      gray( ::color::model< ::color::category::hwb<tag_name> > const& color_parameter )
       {
        typedef ::color::category::hwb< tag_name > category_type;

        typedef typename ::color::trait::scalar< category_type > ::instance_type   scalar_type;

        typedef typename ::color::akin::gray< category_type >::akin_type     akin_category_type;

        typedef ::color::_internal::reformat< akin_category_type, category_type, scalar_type >  reformat_type;

        enum
         {
           lightness_p  = ::color::place::_internal::lightness<category_type>::position_enum
         };

        enum
         {
           gray_p  = ::color::place::_internal::gray<akin_category_type>::position_enum
         };

        return reformat_type::template process<gray_p,lightness_p>( color_parameter.template get<lightness_p>() );
       }

    }
  }

#endif
