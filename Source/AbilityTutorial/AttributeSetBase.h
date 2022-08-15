// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangeDelegate, float, Health, float, MaxHealth);

UCLASS()
class ABILITYTUTORIAL_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase") FGameplayAttributeData Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase") FGameplayAttributeData MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase") FGameplayAttributeData Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase") FGameplayAttributeData MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase") FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase") FGameplayAttributeData MaxStrength;

	UAttributeSetBase();
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData & Data) override;
	
	FOnHealthChangeDelegate OnHealthChange;
	FOnHealthChangeDelegate OnManaChange;
	FOnHealthChangeDelegate OnStrengthChange;

};
