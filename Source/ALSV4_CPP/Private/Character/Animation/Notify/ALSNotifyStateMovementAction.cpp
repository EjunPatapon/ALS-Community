// Copyright:       Copyright (C) 2022 Doğa Can Yanıkoğlu
// Source Code:     https://github.com/dyanikoglu/ALS-Community


#include "Character/Animation/Notify/ALSNotifyStateMovementAction.h"

#include "Character/ALSBaseCharacter.h"

void UALSNotifyStateMovementAction::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                                float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	AALSBaseCharacter* BaseCharacter = Cast<AALSBaseCharacter>(MeshComp->GetOwner());
	if (BaseCharacter)
	{
		BaseCharacter->SetMovementAction(MovementAction);
	}
}

void UALSNotifyStateMovementAction::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                              const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	AALSBaseCharacter* BaseCharacter = Cast<AALSBaseCharacter>(MeshComp->GetOwner());
	if (BaseCharacter && BaseCharacter->GetMovementAction() == MovementAction)
	{
		BaseCharacter->SetMovementAction(NextMovementAction);
	}
}

FString UALSNotifyStateMovementAction::GetNotifyName_Implementation() const
{
	FString Name(TEXT("MovementAction: "));
	Name.Append(GetEnumerationToString(MovementAction));
	Name.Append(TEXT(", Next MovementAction: "));
	Name.Append(GetEnumerationToString(NextMovementAction));
	return Name;
}
