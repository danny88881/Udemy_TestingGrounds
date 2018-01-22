// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8* NodeMemory) {
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto PatrolPoints = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	
	BlackBoardComp->SetValueAsObject(NextWaypoint.SelectedKeyName, PatrolPoints->PatrolPoints[Index]);
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolPoints->PatrolPoints.Num());
	return EBTNodeResult::Succeeded;
}