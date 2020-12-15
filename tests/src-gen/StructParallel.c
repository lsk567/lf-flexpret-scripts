#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/StructParallel.lf
#include "hello.h"
#include "hello.h"
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Check
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
typedef struct {
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    hello_t* value;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    bool is_present;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int num_destinations;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    lf_token_t* token;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int length;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
} check_in_t;
typedef struct {
    int bank_index;
    #line 12 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int expected;
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    bool invoked;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    check_in_t* __in;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // width of -2 indicates that it is not a multiport.
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int __in__width;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // Default input (in case it does not get connected)
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    check_in_t __default__in;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    reaction_t ___reaction_0;
    #line 23 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    reaction_t ___reaction_1;
    trigger_t ___shutdown;
    reaction_t* ___shutdown_reactions[1];
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    trigger_t ___in;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
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
    #line 16 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    printf("Received: name = %s, value = %d\n", in->value->name, in->value->value);
    if (in->value->value != self->expected) {
        printf("ERROR: Expected value to be %d.\n", self->expected);
        exit(1);
    }
    self->invoked = true;
        
}
void checkreaction_function_1(void* instance_args) {
    check_self_t* self = (check_self_t*)instance_args;
    #line 24 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    if (self->invoked == false) {
        fprintf(stderr, "ERROR: No data received.\n");
        exit(2);
    }
        
}
check_self_t* new_Check() {
    check_self_t* self = (check_self_t*)calloc(1, sizeof(check_self_t));
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // Set input by default to an always absent default input.
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->__in = &self->__default__in;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.number = 0;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.function = checkreaction_function_0;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.self = self;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_1.number = 1;
    #line 23 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_1.function = checkreaction_function_1;
    #line 23 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_1.self = self;
    #line 23 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_1.tardy_handler = NULL;
    self->___shutdown_reactions[0] = &self->___reaction_1;
    self->___shutdown.last = NULL;
    self->___shutdown.reactions = &self->___shutdown_reactions[0];
    self->___shutdown.number_of_reactions = 1;
    self->___shutdown.is_timer = false;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___in.last = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
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
// =============== END reactor class Check

// =============== START reactor class Print
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
typedef struct {
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    hello_t* value;
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    bool is_present;
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int num_destinations;
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    lf_token_t* token;
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int length;
#line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
} print_in_t;
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
typedef struct {
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    hello_t* value;
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    bool is_present;
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int num_destinations;
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    lf_token_t* token;
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int length;
#line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
} print_out_t;
typedef struct {
    int bank_index;
    #line 31 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int scale;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    print_in_t* __in;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // width of -2 indicates that it is not a multiport.
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int __in__width;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // Default input (in case it does not get connected)
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    print_in_t __default__in;
    #line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    print_out_t __out;
    #line 35 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int __out__width;
    #line 36 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    reaction_t ___reaction_0;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    trigger_t ___in;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    reaction_t* ___in_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    // Mutable input, so copy the input struct into a temporary variable.
    print_in_t __tmp_in = *(self->__in);
    print_in_t* in = &__tmp_in;
    if (in->is_present) {
        in->length = in->token->length;
        lf_token_t* _lf_input_token = in->token;
        in->token = writable_copy(_lf_input_token);
        if (in->token != _lf_input_token) {
            // A copy of the input token has been made.
            // This needs to be reference counted.
            in->token->ref_count = 1;
            // Repurpose the next_free pointer on the token to add to the list.
            in->token->next_free = _lf_more_tokens_with_ref_count;
            _lf_more_tokens_with_ref_count = in->token;
        }
        in->value = (hello_t*)in->token->value;
    } else {
        in->length = 0;
    }
    int in_width = self->__in__width;
    print_out_t* out = &self->__out;
    #line 37 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    in->value->value *= self->scale;
    printf("Print received name = %s, value = %d\n", in->value->name, in->value->value);
    SET_TOKEN(out, in->token);
        
}
print_self_t* new_Print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // Set input by default to an always absent default input.
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->__in = &self->__default__in;
    #line 36 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.number = 0;
    #line 36 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.function = printreaction_function_0;
    #line 36 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.self = self;
    #line 36 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 36 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___in.last = NULL;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 33 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
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
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
typedef struct {
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    hello_t* value;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    bool is_present;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int num_destinations;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    lf_token_t* token;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int length;
#line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
} source_out_t;
typedef struct {
    int bank_index;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    source_out_t __out;
    #line 13 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    int __out__width;
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_out_t* out = &self->__out;
    #line 15 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    // Dynamically allocate an output struct.
    SET_NEW(out);
    // Above allocates a struct, which then must be populated.
    out->value->name = "Earth";
    out->value->value = 42;
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.number = 0;
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.self = self;
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 14 "file:/lf-flexpret-scripts/tests/StructParallel.lf"
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

// =============== START reactor class StructParallel
typedef struct {
    int bank_index;
} structparallel_self_t;
structparallel_self_t* new_StructParallel() {
    structparallel_self_t* self = (structparallel_self_t*)calloc(1, sizeof(structparallel_self_t));
    return self;
}
void delete_StructParallel(structparallel_self_t* self) {
    free(self);
}
// =============== END reactor class StructParallel

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t** __timer_triggers = NULL;
int __timer_triggers_size = 0;
// Array of pointers to timer triggers to be scheduled in __trigger_startup_reactions().
reaction_t* __startup_reactions[1];
int __startup_reactions_size = 1;
// Array of pointers to shutdown triggers.
reaction_t* __shutdown_reactions[2];
int __shutdown_reactions_size = 2;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    __tokens_with_ref_count_size = 4;
    __tokens_with_ref_count = (token_present_t*)malloc(4 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance StructParallel of class StructParallel
    structparallel_self_t* structparallel_self = new_StructParallel();
    //***** Start initializing StructParallel
    // ************* Instance StructParallel.s of class Source
    source_self_t* structparallel_s_self = new_Source();
    //***** Start initializing StructParallel.s
    // width of -2 indicates that it is not a multiport.
    structparallel_s_self->__out__width = -2;
    __startup_reactions[0] = &structparallel_s_self->___reaction_0;
    //***** End initializing StructParallel.s
    // ************* Instance StructParallel.c1 of class Print
    print_self_t* structparallel_c1_self = new_Print();
    //***** Start initializing StructParallel.c1
    structparallel_c1_self->scale = 2; 
    // width of -2 indicates that it is not a multiport.
    structparallel_c1_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    structparallel_c1_self->__in__width = -2;
    //***** End initializing StructParallel.c1
    // ************* Instance StructParallel.c2 of class Print
    print_self_t* structparallel_c2_self = new_Print();
    //***** Start initializing StructParallel.c2
    structparallel_c2_self->scale = 3; 
    // width of -2 indicates that it is not a multiport.
    structparallel_c2_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    structparallel_c2_self->__in__width = -2;
    //***** End initializing StructParallel.c2
    // ************* Instance StructParallel.p1 of class Check
    check_self_t* structparallel_p1_self = new_Check();
    //***** Start initializing StructParallel.p1
    structparallel_p1_self->expected = 84; 
    __shutdown_reactions[0] = &structparallel_p1_self->___reaction_1;
    // width of -2 indicates that it is not a multiport.
    structparallel_p1_self->__in__width = -2;
    static bool structparallel_p1_initial_invoked = false;
    structparallel_p1_self->invoked = structparallel_p1_initial_invoked;
    //***** End initializing StructParallel.p1
    // ************* Instance StructParallel.p2 of class Check
    check_self_t* structparallel_p2_self = new_Check();
    //***** Start initializing StructParallel.p2
    structparallel_p2_self->expected = 126; 
    __shutdown_reactions[1] = &structparallel_p2_self->___reaction_1;
    // width of -2 indicates that it is not a multiport.
    structparallel_p2_self->__in__width = -2;
    static bool structparallel_p2_initial_invoked = false;
    structparallel_p2_self->invoked = structparallel_p2_initial_invoked;
    //***** End initializing StructParallel.p2
    //***** End initializing StructParallel
    // Populate arrays of trigger pointers.
    structparallel_self->bank_index = 0;
    structparallel_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structparallel_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_s_self->___reaction_0.num_outputs > 0) {
        structparallel_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_s_self->___reaction_0.num_outputs);
        structparallel_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_s_self->___reaction_0.num_outputs);
        structparallel_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    structparallel_s_self->___reaction_0.output_produced[0]
    = &structparallel_s_self->__out.is_present
    ;
    // Reaction 0 of StructParallel.s does not depend on one maximal upstream reaction.
    structparallel_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of StructParallel.s triggers 2 downstream reactions through port StructParallel.s.out.
    structparallel_s_self->___reaction_0.triggered_sizes[0] = 2;
    // For reaction 0 of StructParallel.s, allocate an
    // array of trigger pointers for downstream reactions through port StructParallel.s.out
    trigger_t** structparallel_s_0_0 = (trigger_t**)malloc(2 * sizeof(trigger_t*));
    structparallel_s_self->___reaction_0.triggers[0] = structparallel_s_0_0;
    // Point to destination port StructParallel.c1.in's trigger struct.
    structparallel_s_0_0[0] = &structparallel_c1_self->___in;
    // Point to destination port StructParallel.c2.in's trigger struct.
    structparallel_s_0_0[1] = &structparallel_c2_self->___in;
    structparallel_s_self->__out.num_destinations
    = 2;
    structparallel_c1_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structparallel_c1_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_c1_self->___reaction_0.num_outputs > 0) {
        structparallel_c1_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_c1_self->___reaction_0.num_outputs);
        structparallel_c1_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_c1_self->___reaction_0.num_outputs);
        structparallel_c1_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_c1_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    structparallel_c1_self->___reaction_0.output_produced[0]
    = &structparallel_c1_self->__out.is_present
    ;
    // Reaction 0 of StructParallel.c1 depends on one maximal upstream reaction.
    structparallel_c1_self->___reaction_0.last_enabling_reaction = &(structparallel_s_self->___reaction_0);
    // Reaction 0 of StructParallel.c1 triggers 1 downstream reactions through port StructParallel.c1.out.
    structparallel_c1_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of StructParallel.c1, allocate an
    // array of trigger pointers for downstream reactions through port StructParallel.c1.out
    trigger_t** structparallel_c1_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    structparallel_c1_self->___reaction_0.triggers[0] = structparallel_c1_0_0;
    // Point to destination port StructParallel.p1.in's trigger struct.
    structparallel_c1_0_0[0] = &structparallel_p1_self->___in;
    structparallel_c1_self->__out.num_destinations
    = 1;
    structparallel_c2_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structparallel_c2_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_c2_self->___reaction_0.num_outputs > 0) {
        structparallel_c2_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_c2_self->___reaction_0.num_outputs);
        structparallel_c2_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_c2_self->___reaction_0.num_outputs);
        structparallel_c2_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_c2_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    structparallel_c2_self->___reaction_0.output_produced[0]
    = &structparallel_c2_self->__out.is_present
    ;
    // Reaction 0 of StructParallel.c2 depends on one maximal upstream reaction.
    structparallel_c2_self->___reaction_0.last_enabling_reaction = &(structparallel_s_self->___reaction_0);
    // Reaction 0 of StructParallel.c2 triggers 1 downstream reactions through port StructParallel.c2.out.
    structparallel_c2_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of StructParallel.c2, allocate an
    // array of trigger pointers for downstream reactions through port StructParallel.c2.out
    trigger_t** structparallel_c2_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    structparallel_c2_self->___reaction_0.triggers[0] = structparallel_c2_0_0;
    // Point to destination port StructParallel.p2.in's trigger struct.
    structparallel_c2_0_0[0] = &structparallel_p2_self->___in;
    structparallel_c2_self->__out.num_destinations
    = 1;
    structparallel_p1_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structparallel_p1_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_p1_self->___reaction_0.num_outputs > 0) {
        structparallel_p1_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_p1_self->___reaction_0.num_outputs);
        structparallel_p1_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_p1_self->___reaction_0.num_outputs);
        structparallel_p1_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_p1_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    structparallel_p1_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_p1_self->___reaction_1.num_outputs > 0) {
        structparallel_p1_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_p1_self->___reaction_1.num_outputs);
        structparallel_p1_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_p1_self->___reaction_1.num_outputs);
        structparallel_p1_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_p1_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of StructParallel.p1 depends on one maximal upstream reaction.
    structparallel_p1_self->___reaction_0.last_enabling_reaction = &(structparallel_c1_self->___reaction_0);
    // Reaction 1 of StructParallel.p1 depends on one maximal upstream reaction.
    structparallel_p1_self->___reaction_1.last_enabling_reaction = &(structparallel_p1_self->___reaction_0);
    structparallel_p2_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structparallel_p2_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_p2_self->___reaction_0.num_outputs > 0) {
        structparallel_p2_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_p2_self->___reaction_0.num_outputs);
        structparallel_p2_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_p2_self->___reaction_0.num_outputs);
        structparallel_p2_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_p2_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    structparallel_p2_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structparallel_p2_self->___reaction_1.num_outputs > 0) {
        structparallel_p2_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * structparallel_p2_self->___reaction_1.num_outputs);
        structparallel_p2_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structparallel_p2_self->___reaction_1.num_outputs);
        structparallel_p2_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * structparallel_p2_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of StructParallel.p2 depends on one maximal upstream reaction.
    structparallel_p2_self->___reaction_0.last_enabling_reaction = &(structparallel_c2_self->___reaction_0);
    // Reaction 1 of StructParallel.p2 depends on one maximal upstream reaction.
    structparallel_p2_self->___reaction_1.last_enabling_reaction = &(structparallel_p2_self->___reaction_0);
    // doDeferredInitialize
    structparallel_s_self->__out.token = __create_token(sizeof(hello_t));
    structparallel_c1_self->__out.token = __create_token(sizeof(hello_t));
    structparallel_c2_self->__out.token = __create_token(sizeof(hello_t));
    // Connect inputs and outputs for reactor StructParallel.
    // Connect StructParallel.s.out to input port StructParallel.c1.in
    structparallel_c1_self->__in = (print_in_t*)&structparallel_s_self->__out;
    // Connect StructParallel.s.out to input port StructParallel.c2.in
    structparallel_c2_self->__in = (print_in_t*)&structparallel_s_self->__out;
    // Connect StructParallel.c1.out to input port StructParallel.p1.in
    structparallel_p1_self->__in = (check_in_t*)&structparallel_c1_self->__out;
    // Connect StructParallel.c2.out to input port StructParallel.p2.in
    structparallel_p2_self->__in = (check_in_t*)&structparallel_c2_self->__out;
    // Connect inputs and outputs for reactor StructParallel.s.
    // END Connect inputs and outputs for reactor StructParallel.s.
    // Connect inputs and outputs for reactor StructParallel.c1.
    // END Connect inputs and outputs for reactor StructParallel.c1.
    // Connect inputs and outputs for reactor StructParallel.c2.
    // END Connect inputs and outputs for reactor StructParallel.c2.
    // Connect inputs and outputs for reactor StructParallel.p1.
    // END Connect inputs and outputs for reactor StructParallel.p1.
    // Connect inputs and outputs for reactor StructParallel.p2.
    // END Connect inputs and outputs for reactor StructParallel.p2.
    // END Connect inputs and outputs for reactor StructParallel.
    __tokens_with_ref_count[0].token
            = &structparallel_c1_self->__in->token;
    __tokens_with_ref_count[0].is_present
            = &structparallel_c1_self->__in->is_present;
    __tokens_with_ref_count[0].reset_is_present = false;
    __tokens_with_ref_count[1].token
            = &structparallel_c2_self->__in->token;
    __tokens_with_ref_count[1].is_present
            = &structparallel_c2_self->__in->is_present;
    __tokens_with_ref_count[1].reset_is_present = false;
    __tokens_with_ref_count[2].token
            = &structparallel_p1_self->__in->token;
    __tokens_with_ref_count[2].is_present
            = &structparallel_p1_self->__in->is_present;
    __tokens_with_ref_count[2].reset_is_present = false;
    __tokens_with_ref_count[3].token
            = &structparallel_p2_self->__in->token;
    __tokens_with_ref_count[3].is_present
            = &structparallel_p2_self->__in->is_present;
    __tokens_with_ref_count[3].reset_is_present = false;
    // Add port StructParallel.s.out to array of is_present fields.
    __is_present_fields[0] = &structparallel_s_self->__out.is_present
    ;
    // Add port StructParallel.c1.out to array of is_present fields.
    __is_present_fields[1] = &structparallel_c1_self->__out.is_present
    ;
    // Add port StructParallel.c2.out to array of is_present fields.
    __is_present_fields[2] = &structparallel_c2_self->__out.is_present
    ;
    structparallel_s_self->___reaction_0.chain_id = 3;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    structparallel_c1_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_c1_self->___reaction_0.index = 0x7fffffffffff0001LL;
    structparallel_c2_self->___reaction_0.chain_id = 2;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_c2_self->___reaction_0.index = 0x7fffffffffff0001LL;
    structparallel_p1_self->___reaction_0.chain_id = 1;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_p1_self->___reaction_0.index = 0x7fffffffffff0002LL;
    structparallel_p1_self->___reaction_1.chain_id = 1;
    // index is the OR of level 3 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_p1_self->___reaction_1.index = 0x7fffffffffff0003LL;
    structparallel_p2_self->___reaction_0.chain_id = 2;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_p2_self->___reaction_0.index = 0x7fffffffffff0002LL;
    structparallel_p2_self->___reaction_1.chain_id = 2;
    // index is the OR of level 3 and 
    // deadline 140737488355327 shifted left 16 bits.
    structparallel_p2_self->___reaction_1.index = 0x7fffffffffff0003LL;
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
