// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AgoraBlueprintable/Public/MediaDevice.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMediaDevice() {}
// Cross Module References
	AGORABLUEPRINTABLE_API UScriptStruct* Z_Construct_UScriptStruct_FMediaDevice();
	UPackage* Z_Construct_UPackage__Script_AgoraBlueprintable();
// End Cross Module References
class UScriptStruct* FMediaDevice::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern AGORABLUEPRINTABLE_API uint32 Get_Z_Construct_UScriptStruct_FMediaDevice_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMediaDevice, Z_Construct_UPackage__Script_AgoraBlueprintable(), TEXT("MediaDevice"), sizeof(FMediaDevice), Get_Z_Construct_UScriptStruct_FMediaDevice_Hash());
	}
	return Singleton;
}
template<> AGORABLUEPRINTABLE_API UScriptStruct* StaticStruct<FMediaDevice>()
{
	return FMediaDevice::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMediaDevice(FMediaDevice::StaticStruct, TEXT("/Script/AgoraBlueprintable"), TEXT("MediaDevice"), false, nullptr, nullptr);
static struct FScriptStruct_AgoraBlueprintable_StaticRegisterNativesFMediaDevice
{
	FScriptStruct_AgoraBlueprintable_StaticRegisterNativesFMediaDevice()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MediaDevice")),new UScriptStruct::TCppStructOps<FMediaDevice>);
	}
} ScriptStruct_AgoraBlueprintable_StaticRegisterNativesFMediaDevice;
	struct Z_Construct_UScriptStruct_FMediaDevice_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeviceName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DeviceName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeviceID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DeviceID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMediaDevice_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Describes audio and video devices available in the system. */" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/MediaDevice.h" },
		{ "ToolTip", "Describes audio and video devices available in the system." },
	};
#endif
	void* Z_Construct_UScriptStruct_FMediaDevice_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMediaDevice>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceName_MetaData[] = {
		{ "Category", "MediaDevice" },
		{ "Comment", "/** Device name. */" },
		{ "ModuleRelativePath", "Public/MediaDevice.h" },
		{ "ToolTip", "Device name." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceName = { "DeviceName", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMediaDevice, DeviceName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceName_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceID_MetaData[] = {
		{ "Category", "MediaDevice" },
		{ "Comment", "/** Device Id. */" },
		{ "ModuleRelativePath", "Public/MediaDevice.h" },
		{ "ToolTip", "Device Id." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceID = { "DeviceID", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMediaDevice, DeviceID), METADATA_PARAMS(Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_Index_MetaData[] = {
		{ "Category", "MediaDevice" },
		{ "Comment", "/** Specified index of the device. */" },
		{ "ModuleRelativePath", "Public/MediaDevice.h" },
		{ "ToolTip", "Specified index of the device." },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMediaDevice, Index), METADATA_PARAMS(Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_Index_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_Index_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMediaDevice_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_DeviceID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMediaDevice_Statics::NewProp_Index,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMediaDevice_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AgoraBlueprintable,
		nullptr,
		&NewStructOps,
		"MediaDevice",
		sizeof(FMediaDevice),
		alignof(FMediaDevice),
		Z_Construct_UScriptStruct_FMediaDevice_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FMediaDevice_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMediaDevice_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FMediaDevice_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMediaDevice()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMediaDevice_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_AgoraBlueprintable();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MediaDevice"), sizeof(FMediaDevice), Get_Z_Construct_UScriptStruct_FMediaDevice_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMediaDevice_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMediaDevice_Hash() { return 192020328U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
