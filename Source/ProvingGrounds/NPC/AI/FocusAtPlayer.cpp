// Nor really copyrighted by me, Erling. (but kinda)

#include "FocusAtPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"


EBTNodeResult::Type UFocusAtPlayer::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	AAIController* AI = OwnerComp.GetAIOwner();
	if (!ensure(AI)) { return EBTNodeResult::Failed; }

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	FVector FocusPoint = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();//BlackboardComponent->GetValueAsVector(PointKey.SelectedKeyName);
	BlackboardComponent->SetValueAsVector(PointKey.SelectedKeyName, FocusPoint);
	AI->SetFocalPoint(FocusPoint);

	return EBTNodeResult::Succeeded;
}

