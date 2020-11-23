#define debugPrint(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define debugPrintFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "MageTrigger.h"
#include "DrawDebugHelpers.h"

AMageTrigger::AMageTrigger()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AMageTrigger::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMageTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AMageTrigger::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Black, true, -1, 0, 3);
    //AMageTrigger().GroupActor();
   // GetActorLocation();

}

void AMageTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor enters trigger box
        debugPrint("Overlap Begin");
        debugPrintFString("Overlapped Actor = %s", *OverlappedActor->GetName());
    }
}

void AMageTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor leaves trigger box
        debugPrint("Overlap Ended");
        debugPrintFString("%s has left the Trigger Box", *OtherActor->GetName());
    }
}
