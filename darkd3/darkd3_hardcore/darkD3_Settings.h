/*======================================================================================
                             "USER" ADJUSTABLE SETTINGS
======================================================================================*/

// TODO: Normalize values to be on a human range scale, whole numbers prefered, decimals usable for micro adjustments
// These values should have min/max limit checks included in their functions, so that the end user doesn't get crazy results

/*------------------------------------------------------------------------------
						FILTER SELECTION
------------------------------------------------------------------------------*/
// Comment to deactivate an effect. 
// Example: To disable the tonemap effect, use // in front of #define USE_TONEMAP
//#define USE_ANTI_ALIASING
#define USE_PRE_SHARPEN
//#define USE_BLOOM
#define USE_TECHNICOLOR
#define USE_TONEMAP
#define USE_SEPIA
#define USE_VIGNETTE
//#define USE_POST_SHARPEN
//#define USE_FINAL_LIMITER


/*------------------------------------------------------------------------------
						FXAA SHADER
------------------------------------------------------------------------------*/
// Set values to calculate the amount of Anti Aliasing applied
float fxaaQualitySubpix = 0.60;  // Default: 0.75 Raise to increase amount of blur
float fxaaQualityEdgeThreshold = 0.133; // Lower the value for more smoothing
float fxaaQualityEdgeThresholdMin = 0.0633; // Lower the value for more smoothing


/*------------------------------------------------------------------------------
						PRE_SHARPEN
------------------------------------------------------------------------------*/
//For higher precision in the calculation of contour, requires slightly more processing power
bool highQualitySharpen = 0; //0 = Disable  | 1 = Enable

// Set values to calculate the amount of  AA produced blur to consider for the sharpening pass
#define Average 0.8
#define CoefBlur 2

// Set values of the sharpening amount
#define SharpenEdge 0.2
#define Sharpen_val0 1.4


/*------------------------------------------------------------------------------
						BLOOM
------------------------------------------------------------------------------*/
// Number of samples per pixel taken for the Bloom effect. Don't set it to high!  4 = 25spp, 8 = 81spp, 16 = 289spp
#define NUM_SAMPLES2 4 // Must be set with a value dividable by 2
float BloomPreset = 4; // Disabled = 0 (Valid Preset Values = 1 to 9) Preset value 1 to 9 takes control over the next 3 settings.
float BloomThreshold = 1; // The min. level at which the effect starts (Valid Values = 1 to 9, use decimals for finetuning)
float BloomWidth = 1.2; // Sets the width of the effect (Valid Values = 1 to 9, use decimals for finetuning)
float BloomPower = 1; // The power of the effect (Valid Values = 1 to 9, use decimals for finetuning)


/*------------------------------------------------------------------------------
						TECHNICOLOR
------------------------------------------------------------------------------*/
#define TechniAmount 0.10 // 1.00 = Max
#define TechniPower 4.5 // lower values = whitening

// lower values = stronger channel
#define redNegativeAmount 1.0 // 1.00 = Max
#define greenNegativeAmount 1.0 // 1.00 = Max
#define blueNegativeAmount 1.0 // 1.00 = Max


/*------------------------------------------------------------------------------
						TONEMAP
------------------------------------------------------------------------------*/
#define Gamma 1.15
#define Exposure 0.25
#define Saturation -0.3 // use negative values for less saturation. 
#define BlueShift 0.00 // Higher = more blue in image.
#define Bleach 0.08 // Bleach bypass, higher = stronger effect
#define Defog 0.000 // Strength of Lens Colors.
#define FogColor float4(0.0, 0.0, 0.0, 0.0) //Lens-style color filters for Blue, Red, Yellow, White.


/*------------------------------------------------------------------------------
						SEPIA
------------------------------------------------------------------------------*/
#define Liver // Color Tone, available tones can be seen in ColorTones.PNG (Do not use spaces in the name!)
#define SepiaPower 0.82 // 1.00 = Max


/*------------------------------------------------------------------------------
						VIGNETTE
------------------------------------------------------------------------------*/
// Vignette effect, process by which there is loss in clarity towards the corners and sides of the image, like a picture frame
#define VignetteCenter float2(0.500, 0.500) // Center of screen for effect.
#define VignetteRadius 1.00 // lower values = stronger radial effect from center
#define VignetteAmount -0.10 // Strength of black. -2.00 = Max Black, 1.00 = Max White.


/*------------------------------------------------------------------------------
						POST_SHARPEN
------------------------------------------------------------------------------*/
// Controls additional sharpening applied after previous processing. Strength should be max 0.25!
float Sharpen = 0.05;


/*------------------------------------------------------------------------------
						FINAL_LIMITER
------------------------------------------------------------------------------*/
// Controls the strenght of the limiter. 1.000 for default setting
int LimiterStrenght = 1.000; 