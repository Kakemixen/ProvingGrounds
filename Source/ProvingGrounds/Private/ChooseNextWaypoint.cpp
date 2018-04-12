// Nor really copyrighted by me, Erling. (but kinda)

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h" //TODO meh del
#include "Classes/AIController.h"



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	int32 Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);

	APatrollingGuard* AI = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	if (!ensure(AI) || !ensure(AI->PatrolPointsCPP.Num() > 0)) { return EBTNodeResult::Failed; }

	AActor* Waypoint = AI->PatrolPointsCPP[Index];

	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoint);

	++Index %= (AI->PatrolPointsCPP.Num()); //cycle index
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}

