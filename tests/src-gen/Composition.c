#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/Composition.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Test
#line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
typedef struct {
#line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int value;
#line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    bool is_present;
#line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int num_destinations;
#line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
} test_x_t;
typedef struct {
    int bank_index;
    #line 20 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int count;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    test_x_t* __x;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    // width of -2 indicates that it is not a multiport.
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int __x__width;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    // Default input (in case it does not get connected)
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    test_x_t __default__x;
    #line 21 "file:/lf-flexpret-scripts/tests/Composition.lf"
    reaction_t ___reaction_0;
    #line 29 "file:/lf-flexpret-scripts/tests/Composition.lf"
    reaction_t ___reaction_1;
    trigger_t ___shutdown;
    reaction_t* ___shutdown_reactions[1];
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    trigger_t ___x;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    reaction_t* ___x_reactions[1];
} test_self_t;
void testreaction_function_0(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    test_x_t* x = self->__x;
    int x_width = self->__x__width;
    #line 22 "file:/lf-flexpret-scripts/tests/Composition.lf"
    (self->count)++;
    printf("Received %d\n", x->value);
    if (x->value != self->count) { 
        fprintf(stderr, "FAILURE: Expected %d\n", self->count);
        exit(1); 
    }
        
}
void testreaction_function_1(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    #line 30 "file:/lf-flexpret-scripts/tests/Composition.lf"
    if (self->count == 0) {
        fprintf(stderr, "FAILURE: No data received.\n");
    }
        
}
test_self_t* new_Test() {
    test_self_t* self = (test_self_t*)calloc(1, sizeof(test_self_t));
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    // Set input by default to an always absent default input.
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->__x = &self->__default__x;
    #line 21 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.number = 0;
    #line 21 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.function = testreaction_function_0;
    #line 21 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.self = self;
    #line 21 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 21 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 29 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_1.number = 1;
    #line 29 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_1.function = testreaction_function_1;
    #line 29 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_1.self = self;
    #line 29 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 29 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_1.tardy_handler = NULL;
    self->___shutdown_reactions[0] = &self->___reaction_1;
    self->___shutdown.last = NULL;
    self->___shutdown.reactions = &self->___shutdown_reactions[0];
    self->___shutdown.number_of_reactions = 1;
    self->___shutdown.is_timer = false;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___x.last = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 19 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_Test(test_self_t* self) {
    if (self->___reaction_0.output_produced != NULL) {
        free(self->___reaction_0.output_produced);
    }
    if (self->___reaction_0.triggers != NULL) {
        free(self->___reaction_0.triggers);
    }
    if (self->___reaction_0.triggered_sizes != NULL) {
        free(self->___reaction_0.triggered_sizes);
    }
    if (self->___reaction_1.output_produced != NULL) {
        free(self->___reaction_1.output_produced);
    }
    if (self->___reaction_1.triggers != NULL) {
        free(self->___reaction_1.triggers);
    }
    if (self->___reaction_1.triggered_sizes != NULL) {
        free(self->___reaction_1.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_1.num_outputs; i++) {
        free(self->___reaction_1.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Test

// =============== START reactor class Source
#line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
typedef struct {
#line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int value;
#line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
    bool is_present;
#line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int num_destinations;
#line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
} source_y_t;
typedef struct {
    int bank_index;
    #line 7 "file:/lf-flexpret-scripts/tests/Composition.lf"
    interval_t period;
    #line 10 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int count;
    #line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
    source_y_t __y;
    #line 8 "file:/lf-flexpret-scripts/tests/Composition.lf"
    int __y__width;
    #line 11 "file:/lf-flexpret-scripts/tests/Composition.lf"
    reaction_t ___reaction_0;
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    trigger_t ___t;
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    reaction_t* ___t_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_y_t* y = &self->__y;
    #line 12 "file:/lf-flexpret-scripts/tests/Composition.lf"
    (self->count)++;
    printf("Source sending %d.\n", self->count);
    SET(y, self->count);
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 11 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.number = 0;
    #line 11 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 11 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.self = self;
    #line 11 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___t.last = NULL;
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 9 "file:/lf-flexpret-scripts/tests/Composition.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_Source(source_self_t* self) {
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
// =============== END reactor class Source

// =============== START reactor class Composition
typedef struct {
    int bank_index;
} composition_self_t;
composition_self_t* new_Composition() {
    composition_self_t* self = (composition_self_t*)calloc(1, sizeof(composition_self_t));
    return self;
}
void delete_Composition(composition_self_t* self) {
    free(self);
}
// =============== END reactor class Composition

char* __default_argv[] = {"X", "-f", "true", "-o", "10", "sec"};
void __set_default_command_line_options() {
    default_argc = 6;
    default_argv = __default_argv;
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t* __timer_triggers[1];
int __timer_triggers_size = 1;
// Array of pointers to reactions to be scheduled in __trigger_startup_reactions().
reaction_t** __startup_reactions = NULL;
int __startup_reactions_size = 0;
// Array of pointers to shutdown triggers.
reaction_t* __shutdown_reactions[1];
int __shutdown_reactions_size = 1;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 1;
    __is_present_fields = (bool**)malloc(1 * sizeof(bool*));
    // ************* Instance Composition of class Composition
    composition_self_t* composition_self = new_Composition();
    //***** Start initializing Composition
    // ************* Instance Composition.s of class Source
    source_self_t* composition_s_self = new_Source();
    //***** Start initializing Composition.s
    composition_s_self->period = SEC(2); 
    // width of -2 indicates that it is not a multiport.
    composition_s_self->__y__width = -2;
    static int composition_s_initial_count = 0;
    composition_s_self->count = composition_s_initial_count;
    composition_s_self->___t.offset = SEC(1);
    composition_s_self->___t.period = SEC(2);
    __timer_triggers[0] = &composition_s_self->___t;
    //***** End initializing Composition.s
    // ************* Instance Composition.d of class Test
    test_self_t* composition_d_self = new_Test();
    //***** Start initializing Composition.d
    __shutdown_reactions[0] = &composition_d_self->___reaction_1;
    // width of -2 indicates that it is not a multiport.
    composition_d_self->__x__width = -2;
    static int composition_d_initial_count = 0;
    composition_d_self->count = composition_d_initial_count;
    //***** End initializing Composition.d
    //***** End initializing Composition
    // Populate arrays of trigger pointers.
    composition_self->bank_index = 0;
    composition_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    composition_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (composition_s_self->___reaction_0.num_outputs > 0) {
        composition_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * composition_s_self->___reaction_0.num_outputs);
        composition_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_s_self->___reaction_0.num_outputs);
        composition_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * composition_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    composition_s_self->___reaction_0.output_produced[0]
    = &composition_s_self->__y.is_present
    ;
    // Reaction 0 of Composition.s does not depend on one maximal upstream reaction.
    composition_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of Composition.s triggers 1 downstream reactions through port Composition.s.y.
    composition_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Composition.s, allocate an
    // array of trigger pointers for downstream reactions through port Composition.s.y
    trigger_t** composition_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    composition_s_self->___reaction_0.triggers[0] = composition_s_0_0;
    // Point to destination port Composition.d.x's trigger struct.
    composition_s_0_0[0] = &composition_d_self->___x;
    composition_s_self->__y.num_destinations
    = 1;
    composition_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    composition_d_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (composition_d_self->___reaction_0.num_outputs > 0) {
        composition_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * composition_d_self->___reaction_0.num_outputs);
        composition_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_d_self->___reaction_0.num_outputs);
        composition_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * composition_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    composition_d_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (composition_d_self->___reaction_1.num_outputs > 0) {
        composition_d_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * composition_d_self->___reaction_1.num_outputs);
        composition_d_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_d_self->___reaction_1.num_outputs);
        composition_d_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * composition_d_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Composition.d depends on one maximal upstream reaction.
    composition_d_self->___reaction_0.last_enabling_reaction = &(composition_s_self->___reaction_0);
    // Reaction 1 of Composition.d depends on one maximal upstream reaction.
    composition_d_self->___reaction_1.last_enabling_reaction = &(composition_d_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Composition.
    // Connect Composition.s.y to input port Composition.d.x
    composition_d_self->__x = (test_x_t*)&composition_s_self->__y;
    // Connect inputs and outputs for reactor Composition.s.
    // END Connect inputs and outputs for reactor Composition.s.
    // Connect inputs and outputs for reactor Composition.d.
    // END Connect inputs and outputs for reactor Composition.d.
    // END Connect inputs and outputs for reactor Composition.
    // Add port Composition.s.y to array of is_present fields.
    __is_present_fields[0] = &composition_s_self->__y.is_present
    ;
    composition_s_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    composition_d_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_d_self->___reaction_0.index = 0x7fffffffffff0001LL;
    composition_d_self->___reaction_1.chain_id = 1;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_d_self->___reaction_1.index = 0x7fffffffffff0002LL;
}
void __trigger_startup_reactions() {
    
}
void __initialize_timers() {
    for (int i = 0; i < __timer_triggers_size; i++) {
        if (__timer_triggers[i] != NULL) {
            _lf_initialize_timer(__timer_triggers[i]);
        }
    }
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
