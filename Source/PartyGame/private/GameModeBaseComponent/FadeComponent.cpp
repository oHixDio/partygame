// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBaseComponent/FadeComponent.h"

#include "UserWidget/FadeWidget.h"

// Sets default values for this component's properties
UFadeComponent::UFadeComponent()
{
}

// Called when the game starts
void UFadeComponent::BeginPlay()
{
	Super::BeginPlay();

	
	if (bShouldFadeIn)
	{
		if (FadeWidgetClass)
		{
			FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeWidgetClass);
			FadeWidget->AddToViewport(9000);
			FadeWidget->FadeIn();
		}
	}

}

void UFadeComponent::ChangeLevel()
{
	if (bShoultFadeOut)
	{
		if (IsValid(FadeWidget))
		{
			FadeWidget->FadeOut(LoadLevel);
		}
		else
		{
			if (FadeWidgetClass)
			{
				FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeWidgetClass);
				FadeWidget->AddToViewport(9000);
				FadeWidget->FadeOut(LoadLevel);
			}
		}
	}
}
