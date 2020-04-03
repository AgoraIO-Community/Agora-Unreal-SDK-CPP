// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AgoraBlueprintable/Public/AgoraUtils.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAgoraUtils() {}
// Cross Module References
	AGORABLUEPRINTABLE_API UClass* Z_Construct_UClass_UAgoraUtils_NoRegister();
	AGORABLUEPRINTABLE_API UClass* Z_Construct_UClass_UAgoraUtils();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AgoraBlueprintable();
	AGORABLUEPRINTABLE_API UFunction* Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest();
	AGORABLUEPRINTABLE_API UFunction* Z_Construct_UFunction_UAgoraUtils_StringToInt64();
// End Cross Module References
	void UAgoraUtils::StaticRegisterNativesUAgoraUtils()
	{
		UClass* Class = UAgoraUtils::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateAudioFileForSpeakersTest", &UAgoraUtils::execCreateAudioFileForSpeakersTest },
			{ "StringToInt64", &UAgoraUtils::execStringToInt64 },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics
	{
		struct AgoraUtils_eventCreateAudioFileForSpeakersTest_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoraUtils_eventCreateAudioFileForSpeakersTest_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::Function_MetaDataParams[] = {
		{ "Category", "Agora|Utils" },
		{ "Comment", "/** Creates audio file for speakers test called \\\"ID_TEST_AUDIO.wav\\\"\n   \n   For Windows in *Content/Audio* directory.\n   \n   For Mac in *Library/Caches* directory.\n\n   May be used for \\ref UIAgora::StartAudioPlaybackDeviceTest \"StartAudioPlaybackDeviceTest\" function.\n   @return\n   - Path to the file : Success.\n   - Empty string : Failure.\n   */" },
		{ "ModuleRelativePath", "Public/AgoraUtils.h" },
		{ "ToolTip", "Creates audio file for speakers test called \\\"ID_TEST_AUDIO.wav\\\"\n\n  For Windows in *Content/Audio* directory.\n\n  For Mac in *Library/Caches* directory.\n\n  May be used for \\ref UIAgora::StartAudioPlaybackDeviceTest \"StartAudioPlaybackDeviceTest\" function.\n  @return\n  - Path to the file : Success.\n  - Empty string : Failure." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAgoraUtils, nullptr, "CreateAudioFileForSpeakersTest", nullptr, nullptr, sizeof(AgoraUtils_eventCreateAudioFileForSpeakersTest_Parms), Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics
	{
		struct AgoraUtils_eventStringToInt64_Parms
		{
			FString String;
			int64 ReturnValue;
		};
		static const UE4CodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_String_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_String;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoraUtils_eventStringToInt64_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_String_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_String = { "String", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AgoraUtils_eventStringToInt64_Parms, String), METADATA_PARAMS(Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_String_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_String_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::NewProp_String,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::Function_MetaDataParams[] = {
		{ "Category", "Agora|Utils" },
		{ "Comment", "/** Converts string number to int64.\n   May be convenient when working with *Uid*.\n   @param String Number as a string.\n   @return\n    - int64 number : Success.\n    - 0 : Failure. Error message will be written to the log, search \"UAgoraUtils::StringToInt64 - exception:\".\n   */" },
		{ "DisplayName", "String To Int64" },
		{ "ModuleRelativePath", "Public/AgoraUtils.h" },
		{ "ToolTip", "Converts string number to int64.\n  May be convenient when working with *Uid*.\n  @param String Number as a string.\n  @return\n   - int64 number : Success.\n   - 0 : Failure. Error message will be written to the log, search \"UAgoraUtils::StringToInt64 - exception:\"." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAgoraUtils, nullptr, "StringToInt64", nullptr, nullptr, sizeof(AgoraUtils_eventStringToInt64_Parms), Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAgoraUtils_StringToInt64()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAgoraUtils_StringToInt64_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAgoraUtils_NoRegister()
	{
		return UAgoraUtils::StaticClass();
	}
	struct Z_Construct_UClass_UAgoraUtils_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAgoraUtils_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AgoraBlueprintable,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAgoraUtils_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAgoraUtils_CreateAudioFileForSpeakersTest, "CreateAudioFileForSpeakersTest" }, // 1702749494
		{ &Z_Construct_UFunction_UAgoraUtils_StringToInt64, "StringToInt64" }, // 152955987
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAgoraUtils_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Auxiliary functions that can help when working with Agora in blueprints.\n */" },
		{ "IncludePath", "AgoraUtils.h" },
		{ "ModuleRelativePath", "Public/AgoraUtils.h" },
		{ "ToolTip", "Auxiliary functions that can help when working with Agora in blueprints." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAgoraUtils_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAgoraUtils>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAgoraUtils_Statics::ClassParams = {
		&UAgoraUtils::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAgoraUtils_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAgoraUtils_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAgoraUtils()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAgoraUtils_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAgoraUtils, 3894258939);
	template<> AGORABLUEPRINTABLE_API UClass* StaticClass<UAgoraUtils>()
	{
		return UAgoraUtils::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAgoraUtils(Z_Construct_UClass_UAgoraUtils, &UAgoraUtils::StaticClass, TEXT("/Script/AgoraBlueprintable"), TEXT("UAgoraUtils"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAgoraUtils);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
