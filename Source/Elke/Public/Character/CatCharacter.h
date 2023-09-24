#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

#include "EMovementState.h"
#include "ECatBodyPosition.h"

#include "CatCharacter.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class ELKE_API ACatCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECatBodyPosition InitialBodyPosition = ECatBodyPosition::Sitting;

	UPROPERTY(BlueprintReadOnly)
	EMovementState MovementState = EMovementState::None;

	UPROPERTY(BlueprintReadOnly)
	ECatBodyPosition BodyPosition = InitialBodyPosition;


};
