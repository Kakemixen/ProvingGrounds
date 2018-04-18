// Nor really copyrighted by me, Erling. (but kinda)

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FocusAtPlayer.generated.h"

/**
 * 
 */
UCLASS()
class PROVINGGROUNDS_API UFocusAtPlayer : public UBTTaskNode
{
	GENERATED_BODY()
		
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;


protected:

	UPROPERTY(EditAnywhere, Category = "BlackboardKeys")
		struct FBlackboardKeySelector PointKey;
	
	
};
