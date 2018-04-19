// Nor really copyrighted by me, Erling. (but kinda)

#include "FocusAtPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"


EBTNodeResult::Type UFocusAtPlayer::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	AAIController* AI = OwnerComp.GetAIOwner();
	if (!ensure(AI)) { return EBTNodeResult::Failed; }

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	AActor* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	AI->SetFocus(PlayerPawn);

	return EBTNodeResult::Succeeded;
}

