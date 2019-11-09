/*------------------------------------------------------------------------------
						SEPIA
------------------------------------------------------------------------------*/
#include "darkD3_Shaders\ColorTones.h"

float4 SepiaPass( float4 colorInput, float2 tex )
{
	float4 sepia = colorInput;

	float gray = dot(sepia.rgb, float4(0.3, 0.59, 0.11, 0)); 
	sepia.rgb = float4(sepia.rgb * ColorShade , 1);
    sepia.rgb = lerp(gray, sepia.rgb, SepiaPower);

	return sepia;
}