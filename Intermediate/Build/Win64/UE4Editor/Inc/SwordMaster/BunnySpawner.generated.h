// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SWORDMASTER_BunnySpawner_generated_h
#error "BunnySpawner.generated.h already included, missing '#pragma once' in BunnySpawner.h"
#endif
#define SWORDMASTER_BunnySpawner_generated_h

#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSpawnBunny) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SpawnBunny(); \
		P_NATIVE_END; \
	}


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSpawnBunny) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SpawnBunny(); \
		P_NATIVE_END; \
	}


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABunnySpawner(); \
	friend struct Z_Construct_UClass_ABunnySpawner_Statics; \
public: \
	DECLARE_CLASS(ABunnySpawner, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SwordMaster"), NO_API) \
	DECLARE_SERIALIZER(ABunnySpawner)


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_INCLASS \
private: \
	static void StaticRegisterNativesABunnySpawner(); \
	friend struct Z_Construct_UClass_ABunnySpawner_Statics; \
public: \
	DECLARE_CLASS(ABunnySpawner, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SwordMaster"), NO_API) \
	DECLARE_SERIALIZER(ABunnySpawner)


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABunnySpawner(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABunnySpawner) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABunnySpawner); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABunnySpawner); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABunnySpawner(ABunnySpawner&&); \
	NO_API ABunnySpawner(const ABunnySpawner&); \
public:


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABunnySpawner(ABunnySpawner&&); \
	NO_API ABunnySpawner(const ABunnySpawner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABunnySpawner); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABunnySpawner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABunnySpawner)


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_PRIVATE_PROPERTY_OFFSET
#define SwordMaster_Source_SwordMaster_BunnySpawner_h_16_PROLOG
#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_PRIVATE_PROPERTY_OFFSET \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_RPC_WRAPPERS \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_INCLASS \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SwordMaster_Source_SwordMaster_BunnySpawner_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_PRIVATE_PROPERTY_OFFSET \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_INCLASS_NO_PURE_DECLS \
	SwordMaster_Source_SwordMaster_BunnySpawner_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SWORDMASTER_API UClass* StaticClass<class ABunnySpawner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SwordMaster_Source_SwordMaster_BunnySpawner_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
