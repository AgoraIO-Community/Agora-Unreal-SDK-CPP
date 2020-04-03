// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AGORABLUEPRINTABLE_AgoraUtils_generated_h
#error "AgoraUtils.generated.h already included, missing '#pragma once' in AgoraUtils.h"
#endif
#define AGORABLUEPRINTABLE_AgoraUtils_generated_h

#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateAudioFileForSpeakersTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAgoraUtils::CreateAudioFileForSpeakersTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToInt64) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int64*)Z_Param__Result=UAgoraUtils::StringToInt64(Z_Param_String); \
		P_NATIVE_END; \
	}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateAudioFileForSpeakersTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAgoraUtils::CreateAudioFileForSpeakersTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToInt64) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int64*)Z_Param__Result=UAgoraUtils::StringToInt64(Z_Param_String); \
		P_NATIVE_END; \
	}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAgoraUtils(); \
	friend struct Z_Construct_UClass_UAgoraUtils_Statics; \
public: \
	DECLARE_CLASS(UAgoraUtils, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AgoraBlueprintable"), NO_API) \
	DECLARE_SERIALIZER(UAgoraUtils)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUAgoraUtils(); \
	friend struct Z_Construct_UClass_UAgoraUtils_Statics; \
public: \
	DECLARE_CLASS(UAgoraUtils, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AgoraBlueprintable"), NO_API) \
	DECLARE_SERIALIZER(UAgoraUtils)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAgoraUtils(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAgoraUtils) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAgoraUtils); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAgoraUtils); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAgoraUtils(UAgoraUtils&&); \
	NO_API UAgoraUtils(const UAgoraUtils&); \
public:


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAgoraUtils(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAgoraUtils(UAgoraUtils&&); \
	NO_API UAgoraUtils(const UAgoraUtils&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAgoraUtils); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAgoraUtils); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAgoraUtils)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_PRIVATE_PROPERTY_OFFSET
#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_14_PROLOG
#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_PRIVATE_PROPERTY_OFFSET \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_RPC_WRAPPERS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_INCLASS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_PRIVATE_PROPERTY_OFFSET \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_INCLASS_NO_PURE_DECLS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AGORABLUEPRINTABLE_API UClass* StaticClass<class UAgoraUtils>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_AgoraUtils_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
