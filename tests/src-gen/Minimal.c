#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/Minimal.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Minimal
typedef struct {
    int bank_index;
    #line 4 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} minimal_self_t;
void minimalreaction_function_0(void* instance_args) {
    minimal_self_t* self = (minimal_self_t*)instance_args;
    #line 5 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    printf("Hello World.\n");
        
}
minimal_self_t* new_Minimal() {
    minimal_self_t* self = (minimal_self_t*)calloc(1, sizeof(minimal_self_t));
    #line 4 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    self->___reaction_0.number = 0;
    #line 4 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    self->___reaction_0.function = minimalreaction_function_0;
    #line 4 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    self->___reaction_0.self = self;
    #line 4 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 4 "file:/lf-flexpret-scripts/tests/Minimal.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    return self;
}
void delete_Minimal(minimal_self_t* self) {
    if (self->___reaction_0.output_produced != NULL) {
        free(self->___reaction_0.output_produced);
    }
    if (self->___reaction_0.triggers != NULL) {
        free(self->___reaction_0.triggers);
    }
    if (self->___reaction_0.triggered_sizes != NULL) {
        free(self->___reaction_0.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Minimal

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t** __timer_triggers = NULL;
int __timer_triggers_size = 0;
// Array of pointers to timer triggers to be scheduled in __trigger_startup_reactions().
reaction_t* __startup_reactions[1];
int __startup_reactions_size = 1;
// Empty array of pointers to shutdown triggers.
reaction_t** __shutdown_reactions = NULL;
int __shutdown_reactions_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    // ************* Instance Minimal of class Minimal
    minimal_self_t* minimal_self = new_Minimal();
    //***** Start initializing Minimal
    __startup_reactions[0] = &minimal_self->___reaction_0;
    //***** End initializing Minimal
    // Populate arrays of trigger pointers.
    minimal_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    minimal_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (minimal_self->___reaction_0.num_outputs > 0) {
        minimal_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * minimal_self->___reaction_0.num_outputs);
        minimal_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * minimal_self->___reaction_0.num_outputs);
        minimal_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * minimal_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Minimal does not depend on one maximal upstream reaction.
    minimal_self->___reaction_0.last_enabling_reaction = NULL;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Minimal.
    // END Connect inputs and outputs for reactor Minimal.
    
    minimal_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    minimal_self->___reaction_0.index = 0x7fffffffffff0000LL;
}
void __trigger_startup_reactions() {
    
    for (int i = 0; i < __startup_reactions_size; i++) {
        if (__startup_reactions[i] != NULL) {
            _lf_enqueue_reaction(__startup_reactions[i]);
        }
    }
}
void __initialize_timers() {
}
void logical_time_complete(instant_t timestep, microstep_t microstep) {
}
tag_t next_event_tag(instant_t time, microstep_t microstep) {
    return (tag_t) {  .time = time, .microstep = microstep };
}
bool __trigger_shutdown_reactions() {                          
    for (int i = 0; i < __shutdown_reactions_size; i++) {
        if (__shutdown_reactions[i] != NULL) {
            _lf_enqueue_reaction(__shutdown_reactions[i]);
        }
    }
    // Return true if there are shutdown reactions.
    return (__shutdown_reactions_size > 0);
}
void __termination() {stop_trace();}
