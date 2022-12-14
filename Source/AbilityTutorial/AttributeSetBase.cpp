// Fill out your copyright notice in the Description page of Project Settings.

#include "AttributeSetBase.h"

//Initialize Health component to 20.0f
UAttributeSetBase::UAttributeSetBase():
    Health(200.0f),
    MaxHealth(200.0f),
    Mana(100.0f),
    MaxMana(100.0f),
    Strength(100.0f),
    MaxStrength(100.0f)
{
}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData & Data) 
{
    if(Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
    {
        Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.f, MaxHealth.GetCurrentValue()));
        Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0.f, MaxHealth.GetCurrentValue()));
        //UE_LOG(LogTemp, Warning, TEXT( "Ouch, I took some damage. Now my health is %f"), Health.GetCurrentValue());
        OnHealthChange.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
    }

    if(Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
    {
        Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), 0.f, MaxMana.GetCurrentValue()));
        Mana.SetBaseValue(FMath::Clamp(Mana.GetBaseValue(), 0.f, MaxMana.GetCurrentValue()));
        //UE_LOG(LogTemp, Warning, TEXT( "Ouch, I took some damage. Now my health is %f"), Health.GetCurrentValue());
        OnManaChange.Broadcast(Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
    }
    if(Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength)))
    {
        Strength.SetCurrentValue(FMath::Clamp(Strength.GetCurrentValue(), 0.f, MaxStrength.GetCurrentValue()));
        Strength.SetBaseValue(FMath::Clamp(Strength.GetBaseValue(), 0.f, MaxStrength.GetCurrentValue()));
        //UE_LOG(LogTemp, Warning, TEXT( "Ouch, I took some damage. Now my health is %f"), Health.GetCurrentValue());
        OnStrengthChange.Broadcast(Strength.GetCurrentValue(), MaxStrength.GetCurrentValue());
    }
    
}
