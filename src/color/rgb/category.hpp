#ifndef color_rgb_category_
#define color_rgb_category_

// ::color::category::rgb_ABC;

namespace color
 {
  namespace category
   {

    template< typename tag_name >
     struct rgb
      {
       // typedef void category_name;
      };

    namespace _internal
     {
      template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
       struct rgb_scramble{};

      using rgb_uint8   = ::color::category::_internal::rgb_scramble< std::uint8_t  ,   0, 1, 2 >;
      using rgb_uint16  = ::color::category::_internal::rgb_scramble< std::uint16_t ,   0, 1, 2 >;
      using rgb_uint32  = ::color::category::_internal::rgb_scramble< std::uint32_t ,   0, 1, 2 >;
      using rgb_uint64  = ::color::category::_internal::rgb_scramble< std::uint64_t ,   0, 1, 2 >;
      using rgb_float   = ::color::category::_internal::rgb_scramble<      float  ,     0, 1, 2 >;
      using rgb_double  = ::color::category::_internal::rgb_scramble<      double ,     0, 1, 2 >;
      using rgb_ldouble = ::color::category::_internal::rgb_scramble<      long double, 0, 1, 2 >;

      struct rgb_split233{};
      struct rgb_split332{};
      struct rgb_split442 {};
      struct rgb_split556 {};
      struct rgb_split655 {};
      struct rgb_splitAAA2{};

      template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
        struct rgba_scramble{};
     }


    using rgb_uint8   = ::color::category::rgb< ::color::category::_internal::rgb_uint8   >;
    using rgb_uint16  = ::color::category::rgb< ::color::category::_internal::rgb_uint16  >;
    using rgb_uint32  = ::color::category::rgb< ::color::category::_internal::rgb_uint32  >;
    using rgb_uint64  = ::color::category::rgb< ::color::category::_internal::rgb_uint64  >;
    using rgb_float   = ::color::category::rgb< ::color::category::_internal::rgb_float   >;
    using rgb_double  = ::color::category::rgb< ::color::category::_internal::rgb_double  >;
    using rgb_ldouble = ::color::category::rgb< ::color::category::_internal::rgb_ldouble >;

    using rgb_split233  = ::color::category::rgb< ::color::category::_internal::rgb_split233  >;
    using rgb_split332  = ::color::category::rgb< ::color::category::_internal::rgb_split332  >;
    using rgb_split442  = ::color::category::rgb< ::color::category::_internal::rgb_split442  >;
    using rgb_split556  = ::color::category::rgb< ::color::category::_internal::rgb_split556  >;
    using rgb_split655  = ::color::category::rgb< ::color::category::_internal::rgb_split655  >;
    using rgb_splitAAA2 = ::color::category::rgb< ::color::category::_internal::rgb_splitAAA2 >;

   }
 }

#endif
