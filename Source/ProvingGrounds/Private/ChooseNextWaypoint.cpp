// Nor really copyrighted by me, Erling. (but kinda)

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "GameFramework/Pawn.h"
#include "PatrolRoute.h"



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (!ensure(AIPawn)) { return EBTNodeResult::Failed; }
	UPatrolRoute* PatrolRoute = AIPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	TArray<AActor*> Waypoints = PatrolRoute->GetPatrolPoints();
	if (Waypoints.Num() == 0) { 
		UE_LOG(LogTemp, Warning, TEXT("Guard missing route %s"), *AIPawn->GetName());
		return EBTNodeResult::Failed; 
	}
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	int32 Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	AActor* Waypoint = Waypoints[Index];

	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoint);

	++Index %= (Waypoints.Num()); //cycle index
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}

