#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/TimeState.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Foo
typedef struct {
    int bank_index;
    #line 3 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    int bar;
    #line 4 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    interval_t baz;
    #line 6 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} foo_self_t;
void fooreaction_function_0(void* instance_args) {
    foo_self_t* self = (foo_self_t*)instance_args;
    #line 7 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    printf("Baz: %lld\n", self->baz);
        
}
foo_self_t* new_Foo() {
    foo_self_t* self = (foo_self_t*)calloc(1, sizeof(foo_self_t));
    #line 6 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    self->___reaction_0.number = 0;
    #line 6 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    self->___reaction_0.function = fooreaction_function_0;
    #line 6 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    self->___reaction_0.self = self;
    #line 6 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/TimeState.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    return self;
}
void delete_Foo(foo_self_t* self) {
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
// =============== END reactor class Foo

// =============== START reactor class X
typedef struct {
    int bank_index;
} x_self_t;
x_self_t* new_X() {
    x_self_t* self = (x_self_t*)calloc(1, sizeof(x_self_t));
    return self;
}
void delete_X(x_self_t* self) {
    free(self);
}
// =============== END reactor class X

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
    // ************* Instance X of class X
    x_self_t* x_self = new_X();
    //***** Start initializing X
    // ************* Instance X.a of class Foo
    foo_self_t* x_a_self = new_Foo();
    //***** Start initializing X.a
    x_a_self->bar = 42; 
    __startup_reactions[0] = &x_a_self->___reaction_0;
    x_a_self->baz = MSEC(500);
    //***** End initializing X.a
    //***** End initializing X
    // Populate arrays of trigger pointers.
    x_self->bank_index = 0;
    x_a_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    x_a_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (x_a_self->___reaction_0.num_outputs > 0) {
        x_a_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * x_a_self->___reaction_0.num_outputs);
        x_a_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * x_a_self->___reaction_0.num_outputs);
        x_a_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * x_a_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of X.a does not depend on one maximal upstream reaction.
    x_a_self->___reaction_0.last_enabling_reaction = NULL;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor X.
    // Connect inputs and outputs for reactor X.a.
    // END Connect inputs and outputs for reactor X.a.
    // END Connect inputs and outputs for reactor X.
    
    x_a_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    x_a_self->___reaction_0.index = 0x7fffffffffff0000LL;
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
