#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/Import.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class ImportedAgain
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
typedef struct {
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    int value;
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    bool is_present;
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    int num_destinations;
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
} importedagain_x_t;
typedef struct {
    int bank_index;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    importedagain_x_t* __x;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    // width of -2 indicates that it is not a multiport.
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    int __x__width;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    // Default input (in case it does not get connected)
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    importedagain_x_t __default__x;
    #line 8 "file:/lf-flexpret-scripts/tests/Import.lf"
    reaction_t ___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    trigger_t ___x;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    reaction_t* ___x_reactions[1];
} importedagain_self_t;
void importedagainreaction_function_0(void* instance_args) {
    importedagain_self_t* self = (importedagain_self_t*)instance_args;
    importedagain_x_t* x = self->__x;
    int x_width = self->__x__width;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    printf("Received: %d.\n", x->value);
            if (x->value != 42) {
                printf("ERROR: Expected input to be 42. Got: %d.\n", x->value);
                exit(1);
            }
        
}
importedagain_self_t* new_ImportedAgain() {
    importedagain_self_t* self = (importedagain_self_t*)calloc(1, sizeof(importedagain_self_t));
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    // Set input by default to an always absent default input.
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->__x = &self->__default__x;
    #line 8 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.number = 0;
    #line 8 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.function = importedagainreaction_function_0;
    #line 8 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.self = self;
    #line 8 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x.last = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_ImportedAgain(importedagain_self_t* self) {
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
// =============== END reactor class ImportedAgain

// =============== START reactor class Imported
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
typedef struct {
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    int value;
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    bool is_present;
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    int num_destinations;
#line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
} imported_x_t;
typedef struct {
    int bank_index;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    imported_x_t* __x;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    // width of -2 indicates that it is not a multiport.
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    int __x__width;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    // Default input (in case it does not get connected)
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    imported_x_t __default__x;
    struct {
        #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
        importedagain_x_t x;
    } __a;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    reaction_t ___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    trigger_t ___x;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    reaction_t* ___x_reactions[1];
} imported_self_t;
void importedreaction_function_0(void* instance_args) {
    struct a{
        importedagain_x_t* x;
    } a;
    imported_self_t* self = (imported_self_t*)instance_args;
    imported_x_t* x = self->__x;
    int x_width = self->__x__width;
    a.x = &(self->__a.x);
    #line 10 "file:/lf-flexpret-scripts/tests/Import.lf"
    SET(a.x, x->value); 
        
}
imported_self_t* new_Imported() {
    imported_self_t* self = (imported_self_t*)calloc(1, sizeof(imported_self_t));
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    // Set input by default to an always absent default input.
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->__x = &self->__default__x;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.number = 0;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.function = importedreaction_function_0;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.self = self;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x.last = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_Imported(imported_self_t* self) {
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
// =============== END reactor class Imported

// =============== START reactor class Import
typedef struct {
    int bank_index;
    struct {
        #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
        imported_x_t x;
    } __a;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    reaction_t ___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    trigger_t ___t;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    reaction_t* ___t_reactions[1];
} import_self_t;
void importreaction_function_0(void* instance_args) {
    struct a{
        imported_x_t* x;
    } a;
    import_self_t* self = (import_self_t*)instance_args;
    a.x = &(self->__a.x);
    #line 10 "file:/lf-flexpret-scripts/tests/Import.lf"
    SET(a.x, 42); 
        
}
import_self_t* new_Import() {
    import_self_t* self = (import_self_t*)calloc(1, sizeof(import_self_t));
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.number = 0;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.function = importreaction_function_0;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.self = self;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 9 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___t.last = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 7 "file:/lf-flexpret-scripts/tests/Import.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_Import(import_self_t* self) {
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
// =============== END reactor class Import

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
    __is_present_fields_size = 2;
    __is_present_fields = (bool**)malloc(2 * sizeof(bool*));
    // ************* Instance Import of class Import
    import_self_t* import_self = new_Import();
    //***** Start initializing Import
    import_self->___t.offset = 0;
    import_self->___t.period = 0;
    __timer_triggers[0] = &import_self->___t;
    // ************* Instance Import.a of class Imported
    imported_self_t* import_a_self = new_Imported();
    //***** Start initializing Import.a
    // width of -2 indicates that it is not a multiport.
    import_a_self->__x__width = -2;
    // ************* Instance Import.a.a of class ImportedAgain
    importedagain_self_t* import_a_a_self = new_ImportedAgain();
    //***** Start initializing Import.a.a
    // width of -2 indicates that it is not a multiport.
    import_a_a_self->__x__width = -2;
    //***** End initializing Import.a.a
    //***** End initializing Import.a
    //***** End initializing Import
    // Populate arrays of trigger pointers.
    import_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    import_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (import_self->___reaction_0.num_outputs > 0) {
        import_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * import_self->___reaction_0.num_outputs);
        import_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * import_self->___reaction_0.num_outputs);
        import_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * import_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    import_self->___reaction_0.output_produced[0]
    = &import_self->__a.x.is_present
    ;
    // Reaction 0 of Import does not depend on one maximal upstream reaction.
    import_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of Import triggers 1 downstream reactions through port Import.a.x.
    import_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Import, allocate an
    // array of trigger pointers for downstream reactions through port Import.a.x
    trigger_t** import_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    import_self->___reaction_0.triggers[0] = import_0_0;
    // Point to destination port Import.a.x's trigger struct.
    import_0_0[0] = &import_a_self->___x;
    import_self->__a.x.
    num_destinations = 1;
    import_a_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    import_a_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (import_a_self->___reaction_0.num_outputs > 0) {
        import_a_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * import_a_self->___reaction_0.num_outputs);
        import_a_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * import_a_self->___reaction_0.num_outputs);
        import_a_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * import_a_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    import_a_self->___reaction_0.output_produced[0]
    = &import_a_self->__a.x.is_present
    ;
    // Reaction 0 of Import.a depends on one maximal upstream reaction.
    import_a_self->___reaction_0.last_enabling_reaction = &(import_self->___reaction_0);
    // Reaction 0 of Import.a triggers 1 downstream reactions through port Import.a.a.x.
    import_a_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Import.a, allocate an
    // array of trigger pointers for downstream reactions through port Import.a.a.x
    trigger_t** import_a_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    import_a_self->___reaction_0.triggers[0] = import_a_0_0;
    // Point to destination port Import.a.a.x's trigger struct.
    import_a_0_0[0] = &import_a_a_self->___x;
    import_a_self->__a.x.
    num_destinations = 1;
    import_a_a_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    import_a_a_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (import_a_a_self->___reaction_0.num_outputs > 0) {
        import_a_a_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * import_a_a_self->___reaction_0.num_outputs);
        import_a_a_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * import_a_a_self->___reaction_0.num_outputs);
        import_a_a_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * import_a_a_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Import.a.a depends on one maximal upstream reaction.
    import_a_a_self->___reaction_0.last_enabling_reaction = &(import_a_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Import.
    // Connect inputs and outputs for reactor Import.a.
    // Connect inputs and outputs for reactor Import.a.a.
    // END Connect inputs and outputs for reactor Import.a.a.
    // Connect PortInstance Import.a.a.x, which gets data from reaction 0
    // of Import.a, to Import.a.a.x.
    import_a_a_self->__x = (importedagain_x_t*)&import_a_self->__a.x;
    // END Connect inputs and outputs for reactor Import.a.
    // Connect PortInstance Import.a.x, which gets data from reaction 0
    // of Import, to Import.a.x.
    import_a_self->__x = (imported_x_t*)&import_self->__a.x;
    // END Connect inputs and outputs for reactor Import.
    // Add port Import.a.a.x to array of is_present fields.
    __is_present_fields[0] 
            = &import_a_self->__a.x.
            is_present;
    // Add port Import.a.x to array of is_present fields.
    __is_present_fields[1] 
            = &import_self->__a.x.
            is_present;
    import_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    import_self->___reaction_0.index = 0x7fffffffffff0000LL;
    import_a_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    import_a_self->___reaction_0.index = 0x7fffffffffff0001LL;
    import_a_a_self->___reaction_0.chain_id = 1;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    import_a_a_self->___reaction_0.index = 0x7fffffffffff0002LL;
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
