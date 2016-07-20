//------------------------------------------------
// ColorRamp creation
//------------------------------------------------
//
// Colors for Morse function visualization
// Version 0.1 - 23/10/2002
//
// Thomas Lewiner: thomas.lewiner@polytechnique.org
// INRIA - Geometrica Project
//
//________________________________________________



//#pragma implementation

#include "colorramp.h"
#include "colormaps.h"
#include <GL/glut.h>

//_____________________________________________________________________________
// Constructor
ColorRamp::ColorRamp()
//-----------------------------------------------------------------------------
{
  int i ;

  for( i = 0 ; i < 256 ; i++ )
    rainbow( (float)i/255.0f, color_rainbow + 3*i ) ;

  for( i = 0 ; i < 256 ; i++ )
  {
    color_grayscale[ 3*i ] = (float)i/255.0f ;
    color_grayscale[3*i+1] = (float)i/255.0f ;
    color_grayscale[3*i+2] = (float)i/255.0f ;
  }

  for( i = 1; i < COLOR_NUMBER; i++ )
  {
    switch( i )
    {
    case COLOR_RAINBOW   : colormaps[i] = color_rainbow   ; break ;
    case COLOR_GRAYSCALE : colormaps[i] = color_grayscale ; break ;
    case COLOR_AUTUMN    : colormaps[i] = color_autumn    ; break ;
    case COLOR_BONE      : colormaps[i] = color_bone      ; break ;
    case COLOR_COLORCUBE : colormaps[i] = color_colorcube ; break ;
    case COLOR_COOL      : colormaps[i] = color_cool      ; break ;
    case COLOR_COPPER    : colormaps[i] = color_copper    ; break ;
    case COLOR_FLAG      : colormaps[i] = color_flag      ; break ;
    case COLOR_HOT       : colormaps[i] = color_hot       ; break ;
    case COLOR_HSV       : colormaps[i] = color_hsv       ; break ;
    case COLOR_JET       : colormaps[i] = color_jet       ; break ;
    case COLOR_LINES     : colormaps[i] = color_lines     ; break ;
    case COLOR_PINK      : colormaps[i] = color_pink      ; break ;
    case COLOR_PRISM     : colormaps[i] = color_prism     ; break ;
    case COLOR_SPRING    : colormaps[i] = color_spring    ; break ;
    case COLOR_SUMMER    : colormaps[i] = color_summer    ; break ;
    case COLOR_WINTER    : colormaps[i] = color_winter    ; break ;
    }
  }
}
//_____________________________________________________________________________




//_____________________________________________________________________________
// Destructor
ColorRamp::~ColorRamp()
//-----------------------------------------------------------------------------
{}
//_____________________________________________________________________________




//_____________________________________________________________________________
// Compute one HSV component
void ColorRamp::rainbow( float v, float *cols )
//-----------------------------------------------------------------------------
{
  cols[0] = 1 ;
  cols[1] = 1 ;
  cols[2] = 1 ;

  if( v < 0.25f )
  {
    cols[0] = 0;
    cols[1] = 4 * v;
  }
  else if( v < 0.5f )
  {
    cols[0] = 0;
    cols[2] = 1 + 4 * (0.25f - v);
  }
  else if( v < 0.75f )
  {
    cols[0] = 4 * (v - 0.5f);
    cols[2] = 0;
  }
  else
  {
    cols[1] = 1 + 4 * (0.75f - v);
    cols[2] = 0;
  }
}
//_____________________________________________________________________________



//_____________________________________________________________________________
// Accessor
void ColorRamp::get_color( unsigned char i, ColorMap cmap, float *cols, bool inv  )
//-----------------------------------------------------------------------------
{
  if( cmap != COLOR_NONE && cmap != COLOR_NUMBER )
  {
    if( inv ) i = 255 - i ;
    cols[0] = colormaps[cmap][ 3*i ] ;
    cols[1] = colormaps[cmap][3*i+1] ;
    cols[2] = colormaps[cmap][3*i+2] ;
  }
}
//_____________________________________________________________________________




#include <math.h>
//_____________________________________________________________________________
// Main use: set openGL color
void ColorRamp::set_GLcolor( double v, double vmax, ColorMap cmap, float alpha, bool inv )
//-----------------------------------------------------------------------------
{
  if( cmap != COLOR_NONE && cmap != COLOR_NUMBER )
  {
    int i = (int) ( sqrt(fabs(v)/vmax) * 255.0 ) ;
    if( i > 255 ) i = 255 ;
    if( inv ) i = 255 - i ;
    ::glColor4f( colormaps[cmap][3*i], colormaps[cmap][3*i+1], colormaps[cmap][3*i+2], alpha ) ;
  }
}
//_____________________________________________________________________________
