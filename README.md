# Yet another c++ library that implements color.

### Status:
- Documentation
  - Examples coverage: ~90%
  - HTML coverage: ~90%
- Ready for test use

### Description
 - Yet another c++ library that implements color conversion and manipulation.

### Key features:
- No _virtual_ functions
- Minimal memory footprint
- Ability to copy _array_/_vector_ of colors with _memcpy_, _memmove_ and initialize with _memset_.
- Conversions from/to different types ( and its formats ).
- Headers only
  - One file to include to start the fun
  - By using _del_ or _rm_ it is reducible in to only two of them.
- No third parties
- No additional binaries
- Out of the box ready
  - No need to recompile or start some install process.
- Color models:
  - GRAY,
  - RGB, CMY, CMYK,
  - HSI, HSL, HSV, HWB,
  - YIQ, YUV(BT.601, BT.709), YCgCo, YPbPr(BT.601, BT.709, BT.2020),
  - XYZ( sRGB, D65, 2� ), LAB, LUV, LMS( von Kries D65, von Kries E, BFD, MCAT02 ), xyY, LabCH, LuvCH

### Code sample:
```c++
color::rgb<::color::type::split655_t>   r;                //!< One std::uint16_t in memory. 6 bits for red, 5 bits for green and 5 bits for blue.
color::bgr<std::uint8_t>  b( ::color::constant::aqua_t{} ); //!< Three consecutive std::uint8_t. Ordered in memory: blue, green and red.
color::yiq<std::uint8_t>  y( { 192, 64, 92 } );           //!< Three consecutive std::uint8_t. Ordered in memory: luma, inphase and quadrature.
color::hsv<double>        h( { 90.0, 50.0, 60.0 } );      //!< This will pack ONLY three consecutive doubles in memory
color::lab<float>         l( { 50.0, 0, 0 } );            //!< This will pack ONLY three consecutive floats in memory

y = ::color::constant::turquoise_t{};  //!< Set 'y' to be turquoise.

b = r; //!< Reformat and convert.
r = b; //!< Reformat and convert in opposite direction.
h = b; //!< Reformat and convert from BGR to HSV
h = y; //!< Reformat and convert from YIQ to HSV
l = y; //!< Reformat and convert from YIQ to LAB

color::set::red( y, 127 ); //!< Set redness of YIQ

::color::operation::blend( y, 0.1, color::yiq<std::uint8_t>( r ) ); //!< Blend two colors for given alpha. Accumulation style.
b = color::operation::mix( y, 0.5, color::yiq<std::uint8_t>( h ) ); //!< Blend two colors for given alpha. return style.
```

### Install:
1. Clone this Repository:
  Examples:
    - Windows : git clone https://github.com/dmilos/color.git c:\my-work-folder\my-git-folder\color
    - Linux   : git clone https://github.com/dmilos/color.git /home/my-user-name/my-work-folder/my-git-folder/color
2. Inform compiler where to find headers:
  Examples:
   - MSVC : /Ic:\my-work-folder\my-git-folder\color\src
   - gcc  : -I/home/my-user-name/my-work-folder/my-git-folder/color/src

### Want to see more:
  - [HTML Documentation ](doc/index.html)
  - [Wiki page](https://github.com/dmilos/color/wiki)

### Tested against:
  - GCC 4.8.4
  - GCC 5.4.0 20160609
  - MSVC 2015 Update 3
  - MSVC 2013 Update 5







