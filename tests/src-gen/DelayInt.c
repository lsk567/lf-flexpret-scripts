#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/DelayInt.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Test
#line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
typedef struct {
#line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int value;
#line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    bool is_present;
#line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int num_destinations;
#line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
} test_in_t;
typedef struct {
    int bank_index;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    interval_t start_time;
    #line 18 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    bool received_value;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    test_in_t* __in;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // width of -2 indicates that it is not a multiport.
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int __in__width;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Default input (in case it does not get connected)
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    test_in_t __default__in;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t ___reaction_0;
    #line 23 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t ___reaction_1;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t ___reaction_2;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
    trigger_t ___shutdown;
    reaction_t* ___shutdown_reactions[1];
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    trigger_t ___in;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t* ___in_reactions[1];
} test_self_t;
void testreaction_function_0(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Record the logical time at the start.
    self->start_time = get_logical_time();
        
}
void testreaction_function_1(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    test_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 24 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    printf("Received: %d.\n", in->value);
    self->received_value = true;
    // Check the time of the input.
    instant_t current_time = get_logical_time();
    interval_t elapsed = current_time - self->start_time;
    printf("After %lld nsec of logical time.\n", elapsed);
    if (elapsed != 100000000LL) {
        printf("ERROR: Expected elapsed time to be 100000000. It was %lld.\n", elapsed);
        exit(1);
    }
    if (in->value != 42) {
        printf("ERROR: Expected input value to be 42. It was %d.\n", in->value);
        exit(2);            
    }
        
}
void testreaction_function_2(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    #line 40 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    printf("Checking that communication occurred.\n");
    if (!self->received_value) {
        printf("ERROR: No communication occurred!\n");
        exit(3);            
    }
        
}
test_self_t* new_Test() {
    test_self_t* self = (test_self_t*)calloc(1, sizeof(test_self_t));
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Set input by default to an always absent default input.
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->__in = &self->__default__in;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.number = 0;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.function = testreaction_function_0;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.self = self;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.number = 1;
    #line 23 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.function = testreaction_function_1;
    #line 23 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.self = self;
    #line 23 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_2.number = 2;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_2.function = testreaction_function_2;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_2.self = self;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_2.deadline_violation_handler = NULL;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_2.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    self->___shutdown_reactions[0] = &self->___reaction_2;
    self->___shutdown.last = NULL;
    self->___shutdown.reactions = &self->___shutdown_reactions[0];
    self->___shutdown.number_of_reactions = 1;
    self->___shutdown.is_timer = false;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in.last = NULL;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in_reactions[0] = &self->___reaction_1;
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 16 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
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
    if (self->___reaction_2.output_produced != NULL) {
        free(self->___reaction_2.output_produced);
    }
    if (self->___reaction_2.triggers != NULL) {
        free(self->___reaction_2.triggers);
    }
    if (self->___reaction_2.triggered_sizes != NULL) {
        free(self->___reaction_2.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_1.num_outputs; i++) {
        free(self->___reaction_1.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_2.num_outputs; i++) {
        free(self->___reaction_2.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Test

// =============== START reactor class Delay
#line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
typedef struct {
#line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int value;
#line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    bool is_present;
#line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int num_destinations;
#line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
} delay_in_t;
#line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
typedef struct {
#line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int value;
#line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    bool is_present;
#line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int num_destinations;
#line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
} delay_out_t;
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
typedef struct {
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    trigger_t* trigger;
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int value;
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    bool is_present;
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    bool has_value;
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    lf_token_t* token;
#line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
} delay_a_t;
typedef struct {
    int bank_index;
    #line 3 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    interval_t delay;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    delay_a_t __a;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    delay_in_t* __in;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // width of -2 indicates that it is not a multiport.
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int __in__width;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Default input (in case it does not get connected)
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    delay_in_t __default__in;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    delay_out_t __out;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    int __out__width;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t ___reaction_0;
    #line 10 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t ___reaction_1;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    trigger_t ___a;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t* ___a_reactions[1];
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    trigger_t ___in;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t* ___in_reactions[1];
} delay_self_t;
void delayreaction_function_0(void* instance_args) {
    delay_self_t* self = (delay_self_t*)instance_args;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Expose the action struct as a local variable whose name matches the action name.
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    delay_a_t* a = &self->__a;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Set the fields of the action struct to match the current trigger.
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    a->is_present = self->___a.is_present;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    a->has_value = ((self->___a.token) != NULL && (self->___a.token)->value != NULL);
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    a->token = (self->___a.token);
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    if (a->has_value) {
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
        a->value = *(int*)(self->___a.token)->value;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    }
    delay_out_t* out = &self->__out;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    if (a->has_value && a->is_present) SET(out, a->value);
        
}
void delayreaction_function_1(void* instance_args) {
    delay_self_t* self = (delay_self_t*)instance_args;
    delay_in_t* in = self->__in;
    int in_width = self->__in__width;
    delay_a_t* a = &self->__a;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Use specialized form of schedule for integer payloads.
    schedule_int(a, self->delay, in->value);
        
}
delay_self_t* new_Delay() {
    delay_self_t* self = (delay_self_t*)calloc(1, sizeof(delay_self_t));
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->__a.trigger = &self->___a;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    // Set input by default to an always absent default input.
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->__in = &self->__default__in;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.number = 0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.function = delayreaction_function_0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.self = self;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.number = 1;
    #line 10 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.function = delayreaction_function_1;
    #line 10 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.self = self;
    #line 10 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___a.last = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___a_reactions[0] = &self->___reaction_0;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___a.reactions = &self->___a_reactions[0];
    #line 6 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___a.number_of_reactions = 1;
    self->___a.is_physical = false;
    self->___a.element_size = sizeof(int);
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in.last = NULL;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in_reactions[0] = &self->___reaction_1;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
    return self;
}
void delete_Delay(delay_self_t* self) {
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
// =============== END reactor class Delay

// =============== START reactor class DelayInt
typedef struct {
    int bank_index;
    struct {
        #line 4 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
        delay_in_t in;
    } __d;
    #line 52 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} delayint_self_t;
void delayintreaction_function_0(void* instance_args) {
    struct d{
        delay_in_t* in;
    } d;
    delayint_self_t* self = (delayint_self_t*)instance_args;
    d.in = &(self->__d.in);
    #line 53 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    SET(d.in, 42);
        
}
delayint_self_t* new_DelayInt() {
    delayint_self_t* self = (delayint_self_t*)calloc(1, sizeof(delayint_self_t));
    #line 52 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.number = 0;
    #line 52 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.function = delayintreaction_function_0;
    #line 52 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.self = self;
    #line 52 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 52 "file:/lf-flexpret-scripts/tests/DelayInt.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    return self;
}
void delete_DelayInt(delayint_self_t* self) {
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
// =============== END reactor class DelayInt

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t** __timer_triggers = NULL;
int __timer_triggers_size = 0;
// Array of pointers to timer triggers to be scheduled in __trigger_startup_reactions().
reaction_t* __startup_reactions[2];
int __startup_reactions_size = 2;
// Array of pointers to shutdown triggers.
reaction_t* __shutdown_reactions[1];
int __shutdown_reactions_size = 1;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    __tokens_with_ref_count_size = 1;
    __tokens_with_ref_count = (token_present_t*)malloc(1 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance DelayInt of class DelayInt
    delayint_self_t* delayint_self = new_DelayInt();
    //***** Start initializing DelayInt
    __startup_reactions[0] = &delayint_self->___reaction_0;
    // ************* Instance DelayInt.d of class Delay
    delay_self_t* delayint_d_self = new_Delay();
    //***** Start initializing DelayInt.d
    delayint_d_self->delay = MSEC(100); 
    // width of -2 indicates that it is not a multiport.
    delayint_d_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    delayint_d_self->__in__width = -2;
    delayint_d_self->___a.offset = 0;
    delayint_d_self->___a.period = -1;
    delayint_d_self->___a.token = __create_token(sizeof(int));
    delayint_d_self->___a.is_present = false;
    __tokens_with_ref_count[0].token
            = &delayint_d_self->___a.token;
    __tokens_with_ref_count[0].is_present
            = &delayint_d_self->___a.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing DelayInt.d
    // ************* Instance DelayInt.t of class Test
    test_self_t* delayint_t_self = new_Test();
    //***** Start initializing DelayInt.t
    __startup_reactions[1] = &delayint_t_self->___reaction_0;
    __shutdown_reactions[0] = &delayint_t_self->___reaction_2;
    // width of -2 indicates that it is not a multiport.
    delayint_t_self->__in__width = -2;
    delayint_t_self->start_time = 0;
    static bool delayint_t_initial_received_value = false;
    delayint_t_self->received_value = delayint_t_initial_received_value;
    //***** End initializing DelayInt.t
    //***** End initializing DelayInt
    // Populate arrays of trigger pointers.
    delayint_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayint_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_self->___reaction_0.num_outputs > 0) {
        delayint_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayint_self->___reaction_0.num_outputs);
        delayint_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_self->___reaction_0.num_outputs);
        delayint_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayint_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delayint_self->___reaction_0.output_produced[0]
    = &delayint_self->__d.in.is_present
    ;
    // Reaction 0 of DelayInt does not depend on one maximal upstream reaction.
    delayint_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayInt triggers 1 downstream reactions through port DelayInt.d.in.
    delayint_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayInt, allocate an
    // array of trigger pointers for downstream reactions through port DelayInt.d.in
    trigger_t** delayint_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayint_self->___reaction_0.triggers[0] = delayint_0_0;
    // Point to destination port DelayInt.d.in's trigger struct.
    delayint_0_0[0] = &delayint_d_self->___in;
    delayint_self->__d.in.
    num_destinations = 1;
    delayint_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayint_d_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_d_self->___reaction_0.num_outputs > 0) {
        delayint_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayint_d_self->___reaction_0.num_outputs);
        delayint_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_d_self->___reaction_0.num_outputs);
        delayint_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayint_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delayint_d_self->___reaction_0.output_produced[0]
    = &delayint_d_self->__out.is_present
    ;
    // Total number of outputs produced by the reaction.
    delayint_d_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_d_self->___reaction_1.num_outputs > 0) {
        delayint_d_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delayint_d_self->___reaction_1.num_outputs);
        delayint_d_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_d_self->___reaction_1.num_outputs);
        delayint_d_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delayint_d_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayInt.d does not depend on one maximal upstream reaction.
    delayint_d_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayInt.d triggers 1 downstream reactions through port DelayInt.d.out.
    delayint_d_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayInt.d, allocate an
    // array of trigger pointers for downstream reactions through port DelayInt.d.out
    trigger_t** delayint_d_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayint_d_self->___reaction_0.triggers[0] = delayint_d_0_0;
    // Point to destination port DelayInt.t.in's trigger struct.
    delayint_d_0_0[0] = &delayint_t_self->___in;
    // Reaction 1 of DelayInt.d does not depend on one maximal upstream reaction.
    delayint_d_self->___reaction_1.last_enabling_reaction = NULL;
    delayint_d_self->__out.num_destinations
    = 1;
    delayint_t_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayint_t_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_t_self->___reaction_0.num_outputs > 0) {
        delayint_t_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayint_t_self->___reaction_0.num_outputs);
        delayint_t_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_t_self->___reaction_0.num_outputs);
        delayint_t_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayint_t_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    delayint_t_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_t_self->___reaction_1.num_outputs > 0) {
        delayint_t_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delayint_t_self->___reaction_1.num_outputs);
        delayint_t_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_t_self->___reaction_1.num_outputs);
        delayint_t_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delayint_t_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    delayint_t_self->___reaction_2.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_t_self->___reaction_2.num_outputs > 0) {
        delayint_t_self->___reaction_2.output_produced = (bool**)malloc(sizeof(bool*) * delayint_t_self->___reaction_2.num_outputs);
        delayint_t_self->___reaction_2.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_t_self->___reaction_2.num_outputs);
        delayint_t_self->___reaction_2.triggered_sizes = (int*)malloc(sizeof(int) * delayint_t_self->___reaction_2.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayInt.t does not depend on one maximal upstream reaction.
    delayint_t_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 1 of DelayInt.t does not depend on one maximal upstream reaction.
    delayint_t_self->___reaction_1.last_enabling_reaction = NULL;
    // Reaction 2 of DelayInt.t depends on one maximal upstream reaction.
    delayint_t_self->___reaction_2.last_enabling_reaction = &(delayint_t_self->___reaction_1);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor DelayInt.
    // Connect DelayInt.d.out to input port DelayInt.t.in
    delayint_t_self->__in = (test_in_t*)&delayint_d_self->__out;
    // Connect inputs and outputs for reactor DelayInt.d.
    // END Connect inputs and outputs for reactor DelayInt.d.
    // Connect inputs and outputs for reactor DelayInt.t.
    // END Connect inputs and outputs for reactor DelayInt.t.
    // Connect PortInstance DelayInt.d.in, which gets data from reaction 0
    // of DelayInt, to DelayInt.d.in.
    delayint_d_self->__in = (delay_in_t*)&delayint_self->__d.in;
    // END Connect inputs and outputs for reactor DelayInt.
    // Add action DelayInt.d.a to array of is_present fields.
    __is_present_fields[0] 
            = &delayint_d_self->__a.is_present;
    // Add port DelayInt.d.in to array of is_present fields.
    __is_present_fields[1] 
            = &delayint_self->__d.in.
            is_present;
    // Add port DelayInt.d.out to array of is_present fields.
    __is_present_fields[2] = &delayint_d_self->__out.is_present
    ;
    delayint_self->___reaction_0.chain_id = 8;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayint_d_self->___reaction_0.chain_id = 5;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_d_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayint_d_self->___reaction_1.chain_id = 12;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_d_self->___reaction_1.index = 0x7fffffffffff0001LL;
    delayint_t_self->___reaction_0.chain_id = 2;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_t_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayint_t_self->___reaction_1.chain_id = 3;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_t_self->___reaction_1.index = 0x7fffffffffff0001LL;
    delayint_t_self->___reaction_2.chain_id = 3;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_t_self->___reaction_2.index = 0x7fffffffffff0002LL;
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
