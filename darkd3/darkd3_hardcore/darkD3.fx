/*------------------------------------------------------------------------------
						DARKER DIABLO III SHADER
------------------------------------------------------------------------------*/

#define FXAA_PC 1
#define FXAA_HLSL_3 1
#define FXAA_QUALITY__PRESET 39
#define FXAA_GREEN_AS_LUMA 1

#include "darkD3_Settings.h"
#include "darkD3_Shaders\Fxaa3_11.h"

uniform extern texture gScreenTexture;
uniform extern texture gLumaTexture;

//Difinitions: BUFFER_WIDTH, BUFFER_HEIGHT, BUFFER_RCP_WIDTH, BUFFER_RCP_HEIGHT
sampler screenSampler = sampler_state
{
    Texture = <gScreenTexture>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
    MipFilter = LINEAR;
    AddressU = BORDER;
    AddressV = BORDER;
    SRGBTexture = FALSE;
};
sampler lumaSampler = sampler_state
{
    Texture = <gLumaTexture>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
    MipFilter = LINEAR;
    AddressU = BORDER;
    AddressV = BORDER;
    SRGBTexture = FALSE;
};

#include "darkD3_Shaders\Post.h"

float4 LumaShader( float2 Tex : TEXCOORD0 ) : COLOR0
{
#ifdef USE_ANTI_ALIASING
    float4 c0 = FxaaPixelShader(
		Tex, //pos
		0, //fxaaConsolePosPos (?)
		screenSampler, //tex
		screenSampler, //fxaaConsole360TexExpBiasNegOne
		screenSampler, //fxaaConsole360TexExpBiasNegTwo
		float2(BUFFER_RCP_WIDTH, BUFFER_RCP_HEIGHT), //fxaaQualityRcpFrame
		float4(-0.5*BUFFER_RCP_WIDTH,-0.5*BUFFER_RCP_HEIGHT,0.5*BUFFER_RCP_WIDTH,0.5*BUFFER_RCP_HEIGHT), //fxaaConsoleRcpFrameOpt
		float4(-2.0*BUFFER_RCP_WIDTH,-2.0*BUFFER_RCP_HEIGHT,2.0*BUFFER_RCP_WIDTH,2.0*BUFFER_RCP_HEIGHT), //fxaaConsoleRcpFrameOpt2
		float4(8.0*BUFFER_RCP_WIDTH,8.0*BUFFER_RCP_HEIGHT,-4.0*BUFFER_RCP_WIDTH,-4.0*BUFFER_RCP_HEIGHT), 
		//fxaaConsole360RcpFrameOpt2
		fxaaQualitySubpix,
		fxaaQualityEdgeThreshold,
		fxaaQualityEdgeThresholdMin,
		8.0, //fxaaConsoleEdgeSharpness
		0.125, //fxaaConsoleEdgeThreshold
		0.05, //fxaaConsoleEdgeThresholdMin
		0 //fxaaConsole360ConstDir
	);
#else
		float4 c0 = tex2D(screenSampler,Tex);
#endif
    return c0;
}


float4 MyShader( float2 Tex : TEXCOORD0 ) : COLOR0
{
	float4 c0 = main(Tex);
	c0.w = 1;
    return saturate(c0);
}

technique PostProcess1
{
    pass p1
    {
        PixelShader = compile ps_3_0 LumaShader();
    }
}
technique PostProcess2
{
    pass p1
    {
        PixelShader = compile ps_3_0 MyShader();
    }
}