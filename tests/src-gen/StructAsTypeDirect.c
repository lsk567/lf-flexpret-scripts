#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/StructAsTypeDirect.lf
#include "hello.h"
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Print
#line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
typedef struct {
#line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    hello_t value;
#line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    bool is_present;
#line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    int num_destinations;
#line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
} print_in_t;
typedef struct {
    int bank_index;
    #line 18 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    int expected;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    print_in_t* __in;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    // width of -2 indicates that it is not a multiport.
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    int __in__width;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    // Default input (in case it does not get connected)
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    print_in_t __default__in;
    #line 20 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    reaction_t ___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    trigger_t ___in;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    reaction_t* ___in_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    print_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 21 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    printf("Received: name = %s, value = %d\n", in->value.name, in->value.value);
    if (in->value.value != self->expected) {
        printf("ERROR: Expected value to be %d.\n", self->expected);
        exit(1);
    }
        
}
print_self_t* new_Print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    // Set input by default to an always absent default input.
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->__in = &self->__default__in;
    #line 20 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.number = 0;
    #line 20 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.function = printreaction_function_0;
    #line 20 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.self = self;
    #line 20 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 20 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___in.last = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 19 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(hello_t);
    return self;
}
void delete_Print(print_self_t* self) {
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
// =============== END reactor class Print

// =============== START reactor class Source
#line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
typedef struct {
#line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    hello_t value;
#line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    bool is_present;
#line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    int num_destinations;
#line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
} source_out_t;
typedef struct {
    int bank_index;
    #line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    source_out_t __out;
    #line 10 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    int __out__width;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_out_t* out = &self->__out;
    #line 12 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    out->value.name = "Earth";
    out->value.value = 42;
    SET_PRESENT(out);
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.number = 0;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.self = self;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsTypeDirect.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
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

// =============== START reactor class StructAsArrayType
typedef struct {
    int bank_index;
} structasarraytype_self_t;
structasarraytype_self_t* new_StructAsArrayType() {
    structasarraytype_self_t* self = (structasarraytype_self_t*)calloc(1, sizeof(structasarraytype_self_t));
    return self;
}
void delete_StructAsArrayType(structasarraytype_self_t* self) {
    free(self);
}
// =============== END reactor class StructAsArrayType

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
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 1;
    __is_present_fields = (bool**)malloc(1 * sizeof(bool*));
    // ************* Instance StructAsArrayType of class StructAsArrayType
    structasarraytype_self_t* structasarraytype_self = new_StructAsArrayType();
    //***** Start initializing StructAsArrayType
    // ************* Instance StructAsArrayType.s of class Source
    source_self_t* structasarraytype_s_self = new_Source();
    //***** Start initializing StructAsArrayType.s
    // width of -2 indicates that it is not a multiport.
    structasarraytype_s_self->__out__width = -2;
    __startup_reactions[0] = &structasarraytype_s_self->___reaction_0;
    //***** End initializing StructAsArrayType.s
    // ************* Instance StructAsArrayType.p of class Print
    print_self_t* structasarraytype_p_self = new_Print();
    //***** Start initializing StructAsArrayType.p
    structasarraytype_p_self->expected = 42; 
    // width of -2 indicates that it is not a multiport.
    structasarraytype_p_self->__in__width = -2;
    //***** End initializing StructAsArrayType.p
    //***** End initializing StructAsArrayType
    // Populate arrays of trigger pointers.
    structasarraytype_self->bank_index = 0;
    structasarraytype_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structasarraytype_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (structasarraytype_s_self->___reaction_0.num_outputs > 0) {
        structasarraytype_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structasarraytype_s_self->___reaction_0.num_outputs);
        structasarraytype_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structasarraytype_s_self->___reaction_0.num_outputs);
        structasarraytype_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structasarraytype_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    structasarraytype_s_self->___reaction_0.output_produced[0]
    = &structasarraytype_s_self->__out.is_present
    ;
    // Reaction 0 of StructAsArrayType.s does not depend on one maximal upstream reaction.
    structasarraytype_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of StructAsArrayType.s triggers 1 downstream reactions through port StructAsArrayType.s.out.
    structasarraytype_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of StructAsArrayType.s, allocate an
    // array of trigger pointers for downstream reactions through port StructAsArrayType.s.out
    trigger_t** structasarraytype_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    structasarraytype_s_self->___reaction_0.triggers[0] = structasarraytype_s_0_0;
    // Point to destination port StructAsArrayType.p.in's trigger struct.
    structasarraytype_s_0_0[0] = &structasarraytype_p_self->___in;
    structasarraytype_s_self->__out.num_destinations
    = 1;
    structasarraytype_p_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structasarraytype_p_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structasarraytype_p_self->___reaction_0.num_outputs > 0) {
        structasarraytype_p_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structasarraytype_p_self->___reaction_0.num_outputs);
        structasarraytype_p_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structasarraytype_p_self->___reaction_0.num_outputs);
        structasarraytype_p_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structasarraytype_p_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of StructAsArrayType.p depends on one maximal upstream reaction.
    structasarraytype_p_self->___reaction_0.last_enabling_reaction = &(structasarraytype_s_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor StructAsArrayType.
    // Connect StructAsArrayType.s.out to input port StructAsArrayType.p.in
    structasarraytype_p_self->__in = (print_in_t*)&structasarraytype_s_self->__out;
    // Connect inputs and outputs for reactor StructAsArrayType.s.
    // END Connect inputs and outputs for reactor StructAsArrayType.s.
    // Connect inputs and outputs for reactor StructAsArrayType.p.
    // END Connect inputs and outputs for reactor StructAsArrayType.p.
    // END Connect inputs and outputs for reactor StructAsArrayType.
    // Add port StructAsArrayType.s.out to array of is_present fields.
    __is_present_fields[0] = &structasarraytype_s_self->__out.is_present
    ;
    structasarraytype_s_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    structasarraytype_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    structasarraytype_p_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    structasarraytype_p_self->___reaction_0.index = 0x7fffffffffff0001LL;
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
