#ifndef color_xyz_make_pink
#define color_xyz_make_pink

// ::color::make::pink( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 0.803922, 0.521569, 0.247059 } ) - rgb(205,133,63) - #cd853f

      inline
      void pink( ::color::model< color::category::xyz_uint8 > & color_parameter )
       {
        color_parameter.container() = 0x37;
       }

      inline
      void pink( ::color::model< color::category::xyz_uint16 > & color_parameter )
       {
        color_parameter.container() = 0x6069;
       }

      inline
      void pink( ::color::model< color::category::xyz_uint32 > & color_parameter )
       {
        color_parameter.container() = 0xff673367u;
       }

      inline
      void pink( ::color::model< color::category::xyz_uint64 > & color_parameter )
       {
        color_parameter.container() = 0xffff695a36896b31ul;
       }

      inline
      void pink( ::color::model< color::category::xyz_float > & color_parameter )
       {
        color_parameter.container() = std::array<float,3>( { 19.3184, 18.1561, 7.97628 } );
       }

      inline
      void pink( ::color::model< color::category::xyz_double> & color_parameter )
       {
        color_parameter.container() = std::array<double,3>( { 19.3184, 18.1561, 7.97628 } );
       }

      inline
      void pink( ::color::model< color::category::xyz_ldouble> & color_parameter )
       {
        color_parameter.container() = std::array<long double,3>( { 19.3184, 18.1561, 7.97628 } );
       }

    }
  }

#endif
