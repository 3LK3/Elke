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
	float MovementSpeed = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkPlayRate = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECatBodyPosition InitialBodyPosition = ECatBodyPosition::Sitting;

	UPROPERTY(BlueprintReadOnly)
	EMovementState MovementState = EMovementState::None;

	UPROPERTY(BlueprintReadOnly)
	ECatBodyPosition BodyPosition = InitialBodyPosition;

#pragma region /** Input */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;

	UFUNCTION(BlueprintCallable)
	void SetupPlayerInput();

#pragma endregion

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsSitting();

	UFUNCTION(BlueprintCallable)
	bool IsStanding();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsStandingUp();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsSittingDown();

	UFUNCTION(BlueprintCallable)
	bool IsWalking();

	UFUNCTION(BlueprintCallable)
	bool IsMoving();

	UFUNCTION(BlueprintCallable)
	void Walk(float direction);

	UFUNCTION(BlueprintCallable)
	void StopWalking();

	UFUNCTION(BlueprintCallable)
	void StandUp();

	UFUNCTION(BlueprintCallable)
	void SitDown();

	UFUNCTION(BlueprintCallable)
	void FinishedSitDown();

	UFUNCTION(BlueprintCallable)
	void FinishedStandUp();
};
