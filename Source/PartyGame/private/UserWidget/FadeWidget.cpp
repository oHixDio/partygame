// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/FadeWidget.h"
#include "Kismet/GameplayStatics.h"

void UFadeWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	InEndDelegate.BindDynamic(this, &UFadeWidget::FadeInFinished);
	OutEndDelegate.BindDynamic(this, &UFadeWidget::FadeOutFinished);

	if (InEndDelegate.IsBound())
	{
		BindToAnimationFinished(FadeInAnimation, InEndDelegate);
	}
	if (OutEndDelegate.IsBound())
	{
		BindToAnimationFinished(FadeOutAnimation, OutEndDelegate);
	}
}

void UFadeWidget::FadeInFinished()
{
	RemoveFromParent();
}

void UFadeWidget::FadeOutFinished()
{
	if (UKismetSystemLibrary::IsValidSoftObjectReference(LoadLevel))
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), LoadLevel);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not open level"));
	}
}

void UFadeWidget::FadeIn()
{
	PlayAnimationForward(FadeInAnimation);
}

void UFadeWidget::FadeOut(TSoftObjectPtr<UWorld> Level)
{
	PlayAnimationForward(FadeOutAnimation);
	LoadLevel = Level;
}