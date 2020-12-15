#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/Wcet.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Print
#line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
typedef struct {
#line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int value;
#line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    bool is_present;
#line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int num_destinations;
#line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
} print_in_t;
typedef struct {
    int bank_index;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    print_in_t* __in;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // width of -2 indicates that it is not a multiport.
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int __in__width;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // Default input (in case it does not get connected)
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    print_in_t __default__in;
    #line 28 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t ___reaction_0;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    trigger_t ___in;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t* ___in_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    print_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 29 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    printf("Received: %d\n", in->value);
        
}
print_self_t* new_Print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // Set input by default to an always absent default input.
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->__in = &self->__default__in;
    #line 28 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.number = 0;
    #line 28 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.function = printreaction_function_0;
    #line 28 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.self = self;
    #line 28 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 28 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in.last = NULL;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 27 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
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

// =============== START reactor class Work
#line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
typedef struct {
#line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int value;
#line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    bool is_present;
#line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int num_destinations;
#line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
} work_in1_t;
#line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
typedef struct {
#line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int value;
#line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    bool is_present;
#line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int num_destinations;
#line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
} work_in2_t;
#line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
typedef struct {
#line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int value;
#line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    bool is_present;
#line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int num_destinations;
#line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
} work_out_t;
typedef struct {
    int bank_index;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    work_in1_t* __in1;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // width of -2 indicates that it is not a multiport.
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int __in1__width;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // Default input (in case it does not get connected)
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    work_in1_t __default__in1;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    work_in2_t* __in2;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // width of -2 indicates that it is not a multiport.
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int __in2__width;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // Default input (in case it does not get connected)
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    work_in2_t __default__in2;
    #line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    work_out_t __out;
    #line 15 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int __out__width;
    #line 16 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t ___reaction_0;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    trigger_t ___in1;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t* ___in1_reactions[1];
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    trigger_t ___in2;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t* ___in2_reactions[1];
} work_self_t;
void workreaction_function_0(void* instance_args) {
    work_self_t* self = (work_self_t*)instance_args;
    work_in1_t* in1 = self->__in1;
    int in1_width = self->__in1__width;
    work_in2_t* in2 = self->__in2;
    int in2_width = self->__in2__width;
    work_out_t* out = &self->__out;
    #line 17 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int ret;
    if (in1->value > 10) {
        ret = in2->value * in1->value;
    } else {
        ret = in2->value + in1->value;
    }
            SET(out, ret);
        
}
work_self_t* new_Work() {
    work_self_t* self = (work_self_t*)calloc(1, sizeof(work_self_t));
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // Set input by default to an always absent default input.
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->__in1 = &self->__default__in1;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    // Set input by default to an always absent default input.
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->__in2 = &self->__default__in2;
    #line 16 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.number = 0;
    #line 16 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.function = workreaction_function_0;
    #line 16 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.self = self;
    #line 16 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 16 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in1.last = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in1_reactions[0] = &self->___reaction_0;
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in1.reactions = &self->___in1_reactions[0];
    #line 13 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in1.number_of_reactions = 1;
    self->___in1.element_size = sizeof(int);
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in2.last = NULL;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in2_reactions[0] = &self->___reaction_0;
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in2.reactions = &self->___in2_reactions[0];
    #line 14 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___in2.number_of_reactions = 1;
    self->___in2.element_size = sizeof(int);
    return self;
}
void delete_Work(work_self_t* self) {
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
// =============== END reactor class Work

// =============== START reactor class Source
#line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
typedef struct {
#line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int value;
#line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    bool is_present;
#line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int num_destinations;
#line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
} source_out1_t;
#line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
typedef struct {
#line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int value;
#line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    bool is_present;
#line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int num_destinations;
#line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
} source_out2_t;
typedef struct {
    int bank_index;
    #line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    source_out1_t __out1;
    #line 4 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int __out1__width;
    #line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    source_out2_t __out2;
    #line 5 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    int __out2__width;
    #line 7 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t ___reaction_0;
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    trigger_t ___t;
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    reaction_t* ___t_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_out1_t* out1 = &self->__out1;
    source_out2_t* out2 = &self->__out2;
    #line 8 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    SET(out1, 5);
    SET(out2, 10);
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 7 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.number = 0;
    #line 7 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.self = self;
    #line 7 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___t.last = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 6 "file:/lf-flexpret-scripts/tests/Wcet.lf"
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

// =============== START reactor class Wcet
typedef struct {
    int bank_index;
} wcet_self_t;
wcet_self_t* new_Wcet() {
    wcet_self_t* self = (wcet_self_t*)calloc(1, sizeof(wcet_self_t));
    return self;
}
void delete_Wcet(wcet_self_t* self) {
    free(self);
}
// =============== END reactor class Wcet

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t* __timer_triggers[1];
int __timer_triggers_size = 1;
// Array of pointers to reactions to be scheduled in __trigger_startup_reactions().
reaction_t** __startup_reactions = NULL;
int __startup_reactions_size = 0;
// Empty array of pointers to shutdown triggers.
reaction_t** __shutdown_reactions = NULL;
int __shutdown_reactions_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance Wcet of class Wcet
    wcet_self_t* wcet_self = new_Wcet();
    //***** Start initializing Wcet
    // ************* Instance Wcet.source of class Source
    source_self_t* wcet_source_self = new_Source();
    //***** Start initializing Wcet.source
    // width of -2 indicates that it is not a multiport.
    wcet_source_self->__out1__width = -2;
    // width of -2 indicates that it is not a multiport.
    wcet_source_self->__out2__width = -2;
    wcet_source_self->___t.offset = 0;
    wcet_source_self->___t.period = 0;
    __timer_triggers[0] = &wcet_source_self->___t;
    //***** End initializing Wcet.source
    // ************* Instance Wcet.work of class Work
    work_self_t* wcet_work_self = new_Work();
    //***** Start initializing Wcet.work
    // width of -2 indicates that it is not a multiport.
    wcet_work_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    wcet_work_self->__in1__width = -2;
    // width of -2 indicates that it is not a multiport.
    wcet_work_self->__in2__width = -2;
    //***** End initializing Wcet.work
    // ************* Instance Wcet.print of class Print
    print_self_t* wcet_print_self = new_Print();
    //***** Start initializing Wcet.print
    // width of -2 indicates that it is not a multiport.
    wcet_print_self->__in__width = -2;
    //***** End initializing Wcet.print
    //***** End initializing Wcet
    // Populate arrays of trigger pointers.
    wcet_self->bank_index = 0;
    wcet_source_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    wcet_source_self->___reaction_0.num_outputs = 2;
    // Allocate arrays for triggering downstream reactions.
    if (wcet_source_self->___reaction_0.num_outputs > 0) {
        wcet_source_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * wcet_source_self->___reaction_0.num_outputs);
        wcet_source_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * wcet_source_self->___reaction_0.num_outputs);
        wcet_source_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * wcet_source_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    wcet_source_self->___reaction_0.output_produced[0]
    = &wcet_source_self->__out1.is_present
    ;
    wcet_source_self->___reaction_0.output_produced[1]
    = &wcet_source_self->__out2.is_present
    ;
    // Reaction 0 of Wcet.source does not depend on one maximal upstream reaction.
    wcet_source_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of Wcet.source triggers 1 downstream reactions through port Wcet.source.out1.
    wcet_source_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Wcet.source, allocate an
    // array of trigger pointers for downstream reactions through port Wcet.source.out1
    trigger_t** wcet_source_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    wcet_source_self->___reaction_0.triggers[0] = wcet_source_0_0;
    // Point to destination port Wcet.work.in1's trigger struct.
    wcet_source_0_0[0] = &wcet_work_self->___in1;
    // Reaction 0 of Wcet.source triggers 1 downstream reactions through port Wcet.source.out2.
    wcet_source_self->___reaction_0.triggered_sizes[1] = 1;
    // For reaction 0 of Wcet.source, allocate an
    // array of trigger pointers for downstream reactions through port Wcet.source.out2
    trigger_t** wcet_source_0_1 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    wcet_source_self->___reaction_0.triggers[1] = wcet_source_0_1;
    // Point to destination port Wcet.work.in2's trigger struct.
    wcet_source_0_1[0] = &wcet_work_self->___in2;
    wcet_source_self->__out1.num_destinations
    = 1;
    wcet_source_self->__out2.num_destinations
    = 1;
    wcet_work_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    wcet_work_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (wcet_work_self->___reaction_0.num_outputs > 0) {
        wcet_work_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * wcet_work_self->___reaction_0.num_outputs);
        wcet_work_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * wcet_work_self->___reaction_0.num_outputs);
        wcet_work_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * wcet_work_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    wcet_work_self->___reaction_0.output_produced[0]
    = &wcet_work_self->__out.is_present
    ;
    // Reaction 0 of Wcet.work depends on one maximal upstream reaction.
    wcet_work_self->___reaction_0.last_enabling_reaction = &(wcet_source_self->___reaction_0);
    // Reaction 0 of Wcet.work triggers 1 downstream reactions through port Wcet.work.out.
    wcet_work_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Wcet.work, allocate an
    // array of trigger pointers for downstream reactions through port Wcet.work.out
    trigger_t** wcet_work_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    wcet_work_self->___reaction_0.triggers[0] = wcet_work_0_0;
    // Point to destination port Wcet.print.in's trigger struct.
    wcet_work_0_0[0] = &wcet_print_self->___in;
    wcet_work_self->__out.num_destinations
    = 1;
    wcet_print_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    wcet_print_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (wcet_print_self->___reaction_0.num_outputs > 0) {
        wcet_print_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * wcet_print_self->___reaction_0.num_outputs);
        wcet_print_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * wcet_print_self->___reaction_0.num_outputs);
        wcet_print_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * wcet_print_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Wcet.print depends on one maximal upstream reaction.
    wcet_print_self->___reaction_0.last_enabling_reaction = &(wcet_work_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Wcet.
    // Connect Wcet.source.out1 to input port Wcet.work.in1
    wcet_work_self->__in1 = (work_in1_t*)&wcet_source_self->__out1;
    // Connect Wcet.source.out2 to input port Wcet.work.in2
    wcet_work_self->__in2 = (work_in2_t*)&wcet_source_self->__out2;
    // Connect Wcet.work.out to input port Wcet.print.in
    wcet_print_self->__in = (print_in_t*)&wcet_work_self->__out;
    // Connect inputs and outputs for reactor Wcet.source.
    // END Connect inputs and outputs for reactor Wcet.source.
    // Connect inputs and outputs for reactor Wcet.work.
    // END Connect inputs and outputs for reactor Wcet.work.
    // Connect inputs and outputs for reactor Wcet.print.
    // END Connect inputs and outputs for reactor Wcet.print.
    // END Connect inputs and outputs for reactor Wcet.
    // Add port Wcet.source.out1 to array of is_present fields.
    __is_present_fields[0] = &wcet_source_self->__out1.is_present
    ;
    // Add port Wcet.source.out2 to array of is_present fields.
    __is_present_fields[1] = &wcet_source_self->__out2.is_present
    ;
    // Add port Wcet.work.out to array of is_present fields.
    __is_present_fields[2] = &wcet_work_self->__out.is_present
    ;
    wcet_source_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    wcet_source_self->___reaction_0.index = 0x7fffffffffff0000LL;
    wcet_work_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    wcet_work_self->___reaction_0.index = 0x7fffffffffff0001LL;
    wcet_print_self->___reaction_0.chain_id = 1;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    wcet_print_self->___reaction_0.index = 0x7fffffffffff0002LL;
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
