/*======================================================================================
                             POST FXAA RENDERING PASSES
======================================================================================*/

#define USE_ADDITIONAL_SHADER 1
#define s0 lumaSampler
#define width BUFFER_WIDTH
#define height BUFFER_HEIGHT
#define px BUFFER_RCP_WIDTH
#define py BUFFER_RCP_HEIGHT
#define dx (Average*px)
#define dy (Average*py)
#define CoefOri (1+ CoefBlur)
#define Sharpen_val1 ((Sharpen_val0-1) / 8.0)

/*------------------------------------------------------------------------------
						FILTER TO USE CHECK
------------------------------------------------------------------------------*/
#ifdef USE_PRE_SHARPEN
#include "darkD3_Shaders\PreSharpen.h"
#endif
#ifdef USE_BLOOM
#include "darkD3_Shaders\Bloom.h"
#endif
#ifdef USE_TECHNICOLOR
#include "darkD3_Shaders\Technicolor.h"
#endif
#ifdef USE_TONEMAP
#include "darkD3_Shaders\Tonemap.h"
#endif
#ifdef USE_SEPIA
#include "darkD3_Shaders\Sepia.h"
#endif
#ifdef USE_VIGNETTE
#include "darkD3_Shaders\Vignette.h"
#endif
#ifdef USE_POST_SHARPEN
#include "darkD3_Shaders\PostSharpen.h"
#endif
#ifdef USE_FINAL_LIMITER
#include "darkD3_Shaders\FinalLimiter.h"
#endif


/*------------------------------------------------------------------------------
						RENDERING PASSES
------------------------------------------------------------------------------*/

float4 main( float2 tex)
{
	// PreSharpenPass (has to be the first pass because it samples multiple texels)
	#ifdef USE_PRE_SHARPEN
		float4 pass1 = SharpenPass(tex);
	#else
		float4 pass1 = tex2D(s0,tex);
	#endif
	// BloomPass
	#ifdef USE_BLOOM
		float4 pass2 = BloomPass (pass1,tex);
	#else
		float4 pass2 = pass1;
	#endif
	// Technicolor
	#ifdef USE_TECHNICOLOR
		float4 pass3 = TechnicolorPass( pass2, tex);
	#else
		float4 pass3 = pass2;
	#endif
	// TonemapPass
	#ifdef USE_TONEMAP
		float4 pass4 = TonemapPass( pass3, tex);
	#else
		float4 pass4 = pass3;
	#endif
	// SepiaPass
	#ifdef USE_SEPIA
		float4 pass5 = SepiaPass (pass4,tex);
	#else
		float4 pass5 = pass4;
	#endif
	//VignettePass
	#ifdef USE_VIGNETTE
		float4 pass6 = VignettePass( pass5, tex);
	#else
		float4 pass6 = pass5;
	#endif
	// PostSharpenPass
	#ifdef USE_POST_SHARPEN
		float4 pass7 = PostSharpenPass (pass6,tex);
	#else
		float4 pass7 = pass6;
	#endif
	// FinalLimiterPass (always last)
	#ifdef USE_FINAL_LIMITER
		float4 pass8 = limiter (pass7,tex);
	#else
		float4 pass8 = pass7;
	#endif
	// ReturnFinalColor
	return pass8;
}