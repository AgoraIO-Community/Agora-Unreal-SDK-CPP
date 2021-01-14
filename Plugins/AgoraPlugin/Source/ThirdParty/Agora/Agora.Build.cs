//  Copyright (c) 2019 Agora.io. All rights reserved.

using System.IO;
using UnrealBuildTool;

public class Agora : ModuleRules
{
	public Agora(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, "x64", "Release"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release","agora_rtc_sdk.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("agora_rtc_sdk.dll");
            PublicDelayLoadDLLs.Add("libagora-fdkaac.dll");
            PublicDelayLoadDLLs.Add("libagora-ffmpeg.dll");
            PublicDelayLoadDLLs.Add("libagora-mpg123.dll");
            PublicDelayLoadDLLs.Add("libagora-soundtouch.dll");
            PublicDelayLoadDLLs.Add("libhwcodec.dll");
		}
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicFrameworks.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "Agorafdkaac.framework"));
            PublicFrameworks.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "Agoraffmpeg.framework"));
            PublicFrameworks.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "AgoraRtcKit.framework"));
            PublicFrameworks.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "AgoraSoundTouch.framework"));
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            //PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "iOS", "libcrypto.a"));
 
            PublicAdditionalFrameworks.Add( new Framework( "AgoraRtcKit", Path.Combine(ModuleDirectory, "iOS", "AgoraRtcKit.framework.zip"), "" ) );

	    //PublicAdditionalFrameworks.Add( new Framework( "AgoraRtcCryptoLoader", Path.Combine(ModuleDirectory, "iOS", "AgoraRtcCryptoLoader.framework.zip"), "" ) );

	    PublicAdditionalLibraries.Add ("resolv");

			PublicFrameworks.AddRange(
                		new string[] {
				"CoreML",
				"VideoToolbox",
				"Accelerate",
				"CFNetwork",
				"OpenGLES",
                		"CoreTelephony"
				}
			);
        }
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{			
			AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(ModuleDirectory, "Android", "APL_armv7.xml")));
			
			// select required architecture
			string Architecture = "armeabi-v7a";
			//string Architecture = "arm64-v8a";
			//string Architecture = "x86";
			//string Architecture = "x86_64";
			
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libagora-crypto.so"));
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libcrypto_1_0_0.so"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libagora-fdkaac.so"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libagora-ffmpeg.so"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libagora-mpg123.so"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libagora-rtc-sdk.so"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Android", Architecture, "libagora-soundtouch.so"));
		}
    }
}
