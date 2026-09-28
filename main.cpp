#include <iostream>
#include <vector>

#include "AccessControlSubsystem.h"
#include "CentralDispatcher.h"
#include "DispatchUnitCommand.h"
#include "EmergencyUnitFactory.h"
#include "EmergencyWorkflowFacade.h"
#include "Incident.h"
#include "IncidentCommanderConsole.h"
#include "IssueEvacuationAlertCommand.h"
#include "LegacySirenAdapter.h"
#include "LockdownAreaCommand.h"
#include "OldSirenRadioHW.h"
#include "ResponseUnit.h"

// Scenario 1: Chemical Spill & Toxic Hazard Containment
// Patterns: Factory Method, State, Command, Mediator (4 patterns in one continuous flow)
void runScenario1_ChemicalSpillContainment() {

    std::cout << "SCENARIO 1: Chemical Spill & Toxic Hazard Escalation\n";
    std::cout << "Context: Chemistry Complex Lab 3B | Hazardous Liquid Spill\n";
    std::cout << "======================================================================\n\n";

    // 1. Initialize Mediator
    CentralDispatcher centralDispatcher;

    // 2. Factory Method: Instantiate & register collaborating response units
    EmergencyUnitFactory unitFactory;
    ResponseUnit* secAlpha=unitFactory.createUnit("SECURITY","SEC-Alpha",&centralDispatcher);
    ResponseUnit* medBravo=unitFactory.createUnit("MEDICAL","MED-Bravo",&centralDispatcher);
    ResponseUnit* facCharlie=unitFactory.createUnit("FACILITIES","FAC-Charlie",&centralDispatcher);

    // 3. State Pattern: New incident logged in ReportedState
    Incident chemSpill("INC-101","Chemistry Complex Lab 3B","Corrosive Acid Leak");
    chemSpill.displayStatus();

    // 4. Test Invalid Operation: Attempting to resolve an unconfirmed report
    std::cout << "\n[Testing Invalid Operation 1: Illegal Early Resolution]\n";
    chemSpill.resolve(); // Handled by ReportedState

    // 5. Command Pattern: Invoker queues and dispatches security unit
    IncidentCommanderConsole console;
    std::cout << "\n[Operator Action: Dispatching Security Recon]\n";
    Command* dispatchSec=new DispatchUnitCommand(secAlpha, "Chemistry Complex Lab 3B");
    console.executeCommand(dispatchSec);

    // 6. State transition: Incident escalates to ActiveState
    std::cout << "\n[Incident Verification]\n";
    chemSpill.escalate();
    chemSpill.displayStatus();

    // 7. Mediator Pattern: Security detects vapor; coordinates Medical and Facilities automatically
    std::cout << "\n[Field Event: Security Discovers Toxic Fumes]\n";
    secAlpha->reportStatus("TOXIC_HAZARD","Chemistry Complex Lab 3B");

    // 8. Command Pattern: Dispatch facilities containment team
    std::cout << "\n[Operator Action: Dispatching Facilities Isolation Team]\n";
    Command* dispatchFac = new DispatchUnitCommand(facCharlie, "Chemistry Complex Lab 3B");
    console.executeCommand(dispatchFac);

    // 9. State transition: Resolution after hazard containment
    std::cout << "\n[Incident Resolution]\n";
    chemSpill.resolve();
    chemSpill.displayStatus();

    // 10. Test Invalid Operation: Attempting to re-escalate an archived/resolved incident
    std::cout << "\n[Testing Invalid Operation 2: Illegal Escalation of Closed Case]\n";
    chemSpill.escalate(); // Handled gracefully by ResolvedState

    // Clean up dynamically allocated units owned by this runtime context
    delete secAlpha;
    delete medBravo;
    delete facCharlie;

    std::cout << "\nSCENARIO 1 COMPLETE\n\n";
}

// Scenario 2: Active Intruder, Perimeter Lockdown & Legacy Audio Broadcast
// Patterns: Facade, Adapter, Command, State, Mediator (5 patterns collaborating)
void runScenario2_HostileIntruderLockdown() {

    std::cout << "SCENARIO 2: Active Campus Intruder & High-Level Emergency Lockdown\n";
    std::cout << "Context: Engineering Tower B | Unauthorized Armed Breach\n";
    std::cout << "Patterns: Facade, Adapter, Command, State, Mediator\n";
    std::cout << "======================================================================\n\n";

    // 1. Core Subsystems setup
    AccessControlSubsystem accessControl;
    OldSirenRadioHW legacyHardware;
    LegacySirenAdapter sirenAdapter(&legacyHardware); // Adapter pattern
    IncidentCommanderConsole console;
    CentralDispatcher centralDispatcher;

    EmergencyUnitFactory unitFactory;
    ResponseUnit* secBravo=unitFactory.createUnit("SECURITY","SEC-Bravo", &centralDispatcher);

    // 2. Incident created in ReportedState
    Incident intruderIncident("INC-202", "Engineering Tower B","Armed Intruder Detected");
    intruderIncident.displayStatus();

    // 3. Facade Pattern: Coordinates >= 3 subsystem operations in one call
    // Operations: (a) Executes LockdownAreaCommand, (b) Issues Legacy Siren Alert, (c) Updates Incident State
    EmergencyWorkflowFacade workflowFacade(&accessControl, &sirenAdapter, &console);
    workflowFacade.initiateCampusLockdown("Engineering Tower B", &intruderIncident);

    // Check subsystem status independently
    std::cout << "\n[Subsystem Verification] Is Engineering Tower B locked? " <<(accessControl.isLocked("Engineering Tower B")?"YES (LOCKED)":"NO")<< "\n";

    // 4. Command Pattern: Issue public evacuation alert
    std::cout << "\n[Operator Action: Issue Broad Campus Evacuation Notice]\n";
    Command* alertCmd = new IssueEvacuationAlertCommand(&sirenAdapter, "Engineering Tower B", "IMMEDIATE EVACUATION REQUIRED");
    console.executeCommand(alertCmd);

    // 5. Mediator Pattern: Security intercepts intruder and coordinates containment
    std::cout << "\n[Field Event: Security Engages and Corrals Intruder]\n";
    secBravo->reportStatus("HOSTILE_BREACH", "Engineering Tower B - Ground Floor");

    // 6. Facade Pattern: Single-call de-escalation workflow
    std::cout << "\n[Threat Neutralized: Executing De-escalation Workflow]\n";
    workflowFacade.resolveEmergency("Engineering Tower B", &intruderIncident);

    // Verify independent access control status post-resolution
    std::cout << "\n[Subsystem Verification] Is Engineering Tower B locked? " << (accessControl.isLocked("Engineering Tower B") ? "YES (LOCKED)" : "NO (RESTORED)") << "\n";

    delete secBravo;

    std::cout << "\nSCENARIO 2 COMPLETE\n\n";
}

int main() {
  
    std::cout << "                 CAMPUSGUARD: RUNTIME SYSTEM DEMO                  \n";
    std::cout << "-------------------------------------------------------------------\n\n";

    runScenario1_ChemicalSpillContainment();
    runScenario2_HostileIntruderLockdown();

    std::cout << "             ALL DEMONSTRATION SCENARIOS COMPLETED CLEANLY          \n";
    std::cout << "--------------------------------------------------------------------\n";
    return 0;
}