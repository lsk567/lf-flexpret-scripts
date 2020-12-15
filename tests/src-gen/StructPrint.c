#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/StructPrint.lf
#include "hello.h"
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Check
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
typedef struct {
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    hello_t* value;
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    bool is_present;
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int num_destinations;
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    lf_token_t* token;
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int length;
#line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
} check_in_t;
typedef struct {
    int bank_index;
    #line 21 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int expected;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    check_in_t* __in;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    // width of -2 indicates that it is not a multiport.
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int __in__width;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    // Default input (in case it does not get connected)
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    check_in_t __default__in;
    #line 23 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    reaction_t ___reaction_0;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    trigger_t ___in;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    reaction_t* ___in_reactions[1];
} check_self_t;
void checkreaction_function_0(void* instance_args) {
    check_self_t* self = (check_self_t*)instance_args;
    check_in_t* in = self->__in;
    if (in->is_present) {
        in->length = in->token->length;
        in->value = (hello_t*)in->token->value;
    } else {
        in->length = 0;
    }
    int in_width = self->__in__width;
    #line 24 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    printf("Received: name = %s, value = %d\n", in->value->name, in->value->value);
    if (in->value->value != self->expected) {
        printf("ERROR: Expected value to be %d.\n", self->expected);
        exit(1);
    }
        
}
check_self_t* new_Check() {
    check_self_t* self = (check_self_t*)calloc(1, sizeof(check_self_t));
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    // Set input by default to an always absent default input.
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->__in = &self->__default__in;
    #line 23 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.number = 0;
    #line 23 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.function = checkreaction_function_0;
    #line 23 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.self = self;
    #line 23 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___in.last = NULL;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 22 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(hello_t);
    return self;
}
void delete_Check(check_self_t* self) {
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
// =============== END reactor class Check

// =============== START reactor class Print
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
typedef struct {
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    hello_t* value;
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    bool is_present;
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int num_destinations;
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    lf_token_t* token;
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int length;
#line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
} print_out_t;
typedef struct {
    int bank_index;
    #line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    print_out_t __out;
    #line 10 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    int __out__width;
    #line 11 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    print_out_t* out = &self->__out;
    #line 12 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    // Dynamically allocate an output struct.
    SET_NEW(out);
    // Above allocates a struct, which then must be populated.
    out->value->name = "Earth";
    out->value->value = 42;
        
}
print_self_t* new_Print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    #line 11 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.number = 0;
    #line 11 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.function = printreaction_function_0;
    #line 11 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.self = self;
    #line 11 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/StructPrint.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
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

// =============== START reactor class StructPrintTest
typedef struct {
    int bank_index;
} structprinttest_self_t;
structprinttest_self_t* new_StructPrintTest() {
    structprinttest_self_t* self = (structprinttest_self_t*)calloc(1, sizeof(structprinttest_self_t));
    return self;
}
void delete_StructPrintTest(structprinttest_self_t* self) {
    free(self);
}
// =============== END reactor class StructPrintTest

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
    __tokens_with_ref_count_size = 1;
    __tokens_with_ref_count = (token_present_t*)malloc(1 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 1;
    __is_present_fields = (bool**)malloc(1 * sizeof(bool*));
    // ************* Instance StructPrintTest of class StructPrintTest
    structprinttest_self_t* structprinttest_self = new_StructPrintTest();
    //***** Start initializing StructPrintTest
    // ************* Instance StructPrintTest.s of class Print
    print_self_t* structprinttest_s_self = new_Print();
    //***** Start initializing StructPrintTest.s
    // width of -2 indicates that it is not a multiport.
    structprinttest_s_self->__out__width = -2;
    __startup_reactions[0] = &structprinttest_s_self->___reaction_0;
    //***** End initializing StructPrintTest.s
    // ************* Instance StructPrintTest.p of class Check
    check_self_t* structprinttest_p_self = new_Check();
    //***** Start initializing StructPrintTest.p
    structprinttest_p_self->expected = 42; 
    // width of -2 indicates that it is not a multiport.
    structprinttest_p_self->__in__width = -2;
    //***** End initializing StructPrintTest.p
    //***** End initializing StructPrintTest
    // Populate arrays of trigger pointers.
    structprinttest_self->bank_index = 0;
    structprinttest_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structprinttest_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (structprinttest_s_self->___reaction_0.num_outputs > 0) {
        structprinttest_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structprinttest_s_self->___reaction_0.num_outputs);
        structprinttest_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structprinttest_s_self->___reaction_0.num_outputs);
        structprinttest_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structprinttest_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    structprinttest_s_self->___reaction_0.output_produced[0]
    = &structprinttest_s_self->__out.is_present
    ;
    // Reaction 0 of StructPrintTest.s does not depend on one maximal upstream reaction.
    structprinttest_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of StructPrintTest.s triggers 1 downstream reactions through port StructPrintTest.s.out.
    structprinttest_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of StructPrintTest.s, allocate an
    // array of trigger pointers for downstream reactions through port StructPrintTest.s.out
    trigger_t** structprinttest_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    structprinttest_s_self->___reaction_0.triggers[0] = structprinttest_s_0_0;
    // Point to destination port StructPrintTest.p.in's trigger struct.
    structprinttest_s_0_0[0] = &structprinttest_p_self->___in;
    structprinttest_s_self->__out.num_destinations
    = 1;
    structprinttest_p_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structprinttest_p_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structprinttest_p_self->___reaction_0.num_outputs > 0) {
        structprinttest_p_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structprinttest_p_self->___reaction_0.num_outputs);
        structprinttest_p_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structprinttest_p_self->___reaction_0.num_outputs);
        structprinttest_p_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structprinttest_p_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of StructPrintTest.p depends on one maximal upstream reaction.
    structprinttest_p_self->___reaction_0.last_enabling_reaction = &(structprinttest_s_self->___reaction_0);
    // doDeferredInitialize
    structprinttest_s_self->__out.token = __create_token(sizeof(hello_t));
    // Connect inputs and outputs for reactor StructPrintTest.
    // Connect StructPrintTest.s.out to input port StructPrintTest.p.in
    structprinttest_p_self->__in = (check_in_t*)&structprinttest_s_self->__out;
    // Connect inputs and outputs for reactor StructPrintTest.s.
    // END Connect inputs and outputs for reactor StructPrintTest.s.
    // Connect inputs and outputs for reactor StructPrintTest.p.
    // END Connect inputs and outputs for reactor StructPrintTest.p.
    // END Connect inputs and outputs for reactor StructPrintTest.
    __tokens_with_ref_count[0].token
            = &structprinttest_p_self->__in->token;
    __tokens_with_ref_count[0].is_present
            = &structprinttest_p_self->__in->is_present;
    __tokens_with_ref_count[0].reset_is_present = false;
    // Add port StructPrintTest.s.out to array of is_present fields.
    __is_present_fields[0] = &structprinttest_s_self->__out.is_present
    ;
    structprinttest_s_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    structprinttest_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    structprinttest_p_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    structprinttest_p_self->___reaction_0.index = 0x7fffffffffff0001LL;
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
