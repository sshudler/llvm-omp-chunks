#ifndef  __OMPT_EVENT_SPECIFIC_H__
#define  __OMPT_EVENT_SPECIFIC_H__

/******************************************************************************
 * File: ompt-event-specific.h
 *
 * Description:
 *
 *   specify which of the OMPT events are implemented by this runtime system
 *   and the level of their implementation by a runtime system.
 *****************************************************************************/

#define _ompt_tokenpaste_helper(x,y)        x ## y
#define _ompt_tokenpaste(x,y)               _ompt_tokenpaste_helper(x,y)
#define ompt_event_implementation_status(e) _ompt_tokenpaste(e,_implemented)


/*----------------------------------------------------------------------------
 | Specify whether an event may occur or not, and whether event callbacks
 | never, sometimes, or always occur.
 |
 | The values for these constants are defined in section 6.1.2 of
 | the OMPT TR. They are exposed to tools through ompt_set_callback.
 +--------------------------------------------------------------------------*/

//#define ompt_event_NEVER             ompt_set_never
#define ompt_event_UNIMPLEMENTED     ompt_set_never
#define ompt_event_MAY_CONVENIENT    ompt_set_sometimes
#define ompt_event_MAY_ALWAYS        ompt_set_always

#if OMPT_OPTIONAL
#define ompt_event_MAY_ALWAYS_OPTIONAL   ompt_event_MAY_ALWAYS
#else
#define ompt_event_MAY_ALWAYS_OPTIONAL   ompt_event_UNIMPLEMENTED
#endif

/*----------------------------------------------------------------------------
 | Mandatory Events
 +--------------------------------------------------------------------------*/

#define ompt_callback_parallel_begin_implemented        ompt_event_MAY_ALWAYS
#define ompt_callback_parallel_end_implemented          ompt_event_MAY_ALWAYS

#define ompt_callback_task_create_implemented           ompt_event_MAY_ALWAYS
#define ompt_callback_task_schedule_implemented         ompt_event_MAY_ALWAYS

#define ompt_callback_thread_begin_implemented          ompt_event_MAY_ALWAYS
#define ompt_callback_thread_end_implemented            ompt_event_MAY_ALWAYS

#define ompt_event_control_implemented                  ompt_event_MAY_ALWAYS

#define ompt_callback_implicit_task_implemented         ompt_event_MAY_ALWAYS


/*----------------------------------------------------------------------------
 | Optional Events (blame shifting)
 +--------------------------------------------------------------------------*/

#define ompt_callback_idle_implemented                  ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_sync_region_wait_implemented      ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_mutex_released_implemented        ompt_event_MAY_ALWAYS_OPTIONAL


/*----------------------------------------------------------------------------
 | Optional Events (synchronous events)
 +--------------------------------------------------------------------------*/

#define ompt_callback_work_implemented                  ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_master_implemented                ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_sync_region_implemented           ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_mutex_acquire_implemented         ompt_event_MAY_ALWAYS_OPTIONAL
#define ompt_callback_mutex_acquired_implemented        ompt_event_MAY_ALWAYS_OPTIONAL
#define ompt_callback_nest_lock_implemented             ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_lock_init_implemented             ompt_event_MAY_ALWAYS_OPTIONAL
#define ompt_callback_lock_destroy_implemented          ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_flush_implemented                 ompt_event_MAY_ALWAYS_OPTIONAL

#define ompt_callback_cancel_implemented                ompt_event_MAY_ALWAYS_OPTIONAL

// Start of PVLangdal extensions

#define ext_callback_task_create_begin_implemented      ompt_event_MAY_ALWAYS
#define ext_callback_loop_implemented                   ompt_event_MAY_ALWAYS
#define ext_callback_chunk_implemented                  ompt_event_MAY_ALWAYS

// End of PVLangdal extensions

#if OMP_40_ENABLED
# define ompt_callback_task_dependences_implemented      ompt_event_MAY_ALWAYS_OPTIONAL
# define ompt_callback_task_dependence_implemented       ompt_event_MAY_ALWAYS_OPTIONAL
#else
# define ompt_callback_task_dependences_implemented      ompt_event_UNIMPLEMENTED
# define ompt_callback_task_dependence_implemented       ompt_event_UNIMPLEMENTED
#endif /* OMP_40_ENABLED */

#endif