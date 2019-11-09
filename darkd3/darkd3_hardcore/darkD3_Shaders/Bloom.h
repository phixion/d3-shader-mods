/*------------------------------------------------------------------------------
						BLOOM
------------------------------------------------------------------------------*/

float4 BloomPass( float4 ColorInput2,float2 Tex  )
{
	float4 BlurColor2 =  0.0f;
	float BloomThreshold2 = 0.0f;
	float BloomPower2 = 0.0f;
	float BloomWidth2 = 0.0f;
	if (BloomPreset >= 1 && BloomPreset <= 9)
	{
		BloomThreshold2 = 22 - (BloomPreset * 0.875);
		BloomPower2 = (BloomPreset * 0.223) + 1;
		BloomWidth2 = (BloomPreset /175) * 1.25;
	}
	else 
	{
		if (BloomThreshold < 1) 	{ BloomThreshold2 = 8.125; }
		if (BloomThreshold > 9) 	{ BloomThreshold2 = 1.125; }
		else 						{ BloomThreshold2 = 22 - (BloomThreshold * 0.875); }

		if (BloomPower < 1) 		{ BloomPower2 = 1; }
		if (BloomPower > 9) 		{ BloomPower2 = 3; }
		else 						{ BloomPower2 = (BloomPower * 0.223) + 1; }

		if (BloomWidth < 1) 		{ BloomWidth2 = 0.2585; }
		if (BloomWidth > 9) 		{ BloomWidth2 = 0.3265; }
		else						{ BloomWidth2 = (BloomPreset /175) * 1.25; }
	}
	float NRGSamples = 0;
	NRGSamples = NUM_SAMPLES2 /2;
	float MaxSamples = (NUM_SAMPLES2)*(NUM_SAMPLES2);
	float MaxDistance = sqrt(NRGSamples*NRGSamples*2*BloomWidth2);
	float   MaxSamplingdistance = (4 * BloomWidth2) + 0.001;
	float CurDistance = 0;
	float4 Blurtemp = 0;
	float Samplecount = 0;
	for(float Samplex = (- NRGSamples); Samplex < NRGSamples+1; Samplex = Samplex + 1)
	{
		for(float Sampley = (- NRGSamples); Sampley < NRGSamples+1; Sampley = Sampley + 1)
		{
			CurDistance = sqrt (((Samplex * Samplex) + (Sampley*Sampley))*BloomWidth2);
			Blurtemp.rgb = tex2D(s0, float2(Tex.x +(Tex.x*Samplex*px*BloomWidth2),Tex.y +(Tex.y*Sampley*py*BloomWidth2)));
			BlurColor2.rgb += lerp(Blurtemp.rgb,ColorInput2.rgb, 1 - ((MaxDistance - CurDistance)/MaxDistance));
			Samplecount = Samplecount + 1;
		}
	}
	BlurColor2.rgb = (BlurColor2.rgb / (Samplecount - (BloomPower2 - BloomThreshold2*5)));
	float Bloomamount = (dot(ColorInput2.xyz,float3(0.299, 0.587, 0.114)) ) ;
	float4	BlurColor = BlurColor2 * (BloomPower2 + 3);
	BlurColor2.rgb =lerp(ColorInput2,BlurColor, Bloomamount).rgb ;	
	BlurColor2.a = ColorInput2.a;
	Blurtemp = 0;
	return  BlurColor2;
}
