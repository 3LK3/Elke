#include "Character/CatCharacter.h"

#include "EnhancedInputSubsystems.h"


void ACatCharacter::SetupPlayerInput()
{
	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		ULocalPlayer* localPlayer = playerController->GetLocalPlayer();

		if (UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(localPlayer))
		{
			inputSubsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

bool ACatCharacter::IsSitting()
{
	return BodyPosition == ECatBodyPosition::Sitting;
}

bool ACatCharacter::IsStanding()
{
	return BodyPosition == ECatBodyPosition::Standing;
}

bool ACatCharacter::IsStandingUp()
{
	return MovementState == EMovementState::StandingUp;
}

bool ACatCharacter::IsSittingDown()
{
	return MovementState == EMovementState::SittingDown;
}

bool ACatCharacter::IsWalking()
{
	return MovementState == EMovementState::Walking;
}

bool ACatCharacter::IsMoving()
{
	return MovementState != EMovementState::None;
}

void ACatCharacter::Walk(float direction)
{
	bool isWalking = IsWalking();
	if (!(isWalking || IsStanding()))
	{
		return;
	}

	AddMovementInput(FVector::XAxisVector, direction * MovementSpeed);

	if (!isWalking)
	{
		MovementState = EMovementState::Walking;
	}
}

void ACatCharacter::StopWalking()
{
}

void ACatCharacter::StandUp()
{
	if (!IsSitting())
	{
		return;
	}

	MovementState = EMovementState::StandingUp;
}

void ACatCharacter::SitDown()
{
	if (!IsStanding() || IsMoving())
	{
		return;
	}

	MovementState = EMovementState::SittingDown;
}

void ACatCharacter::FinishedSitDown()
{
	BodyPosition = ECatBodyPosition::Sitting;
	MovementState = EMovementState::None;
}

void ACatCharacter::FinishedStandUp()
{
	BodyPosition = ECatBodyPosition::Standing;
	MovementState = EMovementState::None;
}


