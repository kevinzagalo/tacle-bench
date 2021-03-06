/*

  This program is part of the TACLeBench benchmark suite.
  Version V 1.x

  Name: powerwindow_PW_Control_PSG_BackR.h

  Author: CoSys-Lab, University of Antwerp

  Function: headerfile

  Source: https://github.com/tacle/tacle-bench/blob/master/bench/app/PowerWindow/powerwindow_HeaderFiles/powerwindow_PW_Control_PSG_BackR.h

  Changes: a brief summary of major functional changes and formatting)

  License: GNU General Public License

*/

#ifndef powerwindow_RTW_HEADER_PW_Control_PSG_BackR_h_
#define powerwindow_RTW_HEADER_PW_Control_PSG_BackR_h_
#ifndef powerwindow_PW_Control_PSG_BackR_COMMON_INCLUDES_
# define powerwindow_PW_Control_PSG_BackR_COMMON_INCLUDES_
#include "../powerwindow_HeaderFiles/powerwindow_rtwtypes.h"
#include "../powerwindow_HeaderFiles/powerwindow_rtw_solver.h"
#endif                                 /* powerwindow_PW_Control_PSG_BackR_COMMON_INCLUDES_*/

#include "../powerwindow_HeaderFiles/powerwindow_PW_Control_PSG_BackR_types.h"

/* Shared type includes */
#include "../powerwindow_HeaderFiles/powerwindow_model_reference_types.h"

/* Child system includes */
#include "../powerwindow_HeaderFiles/powerwindow_powerwindow_control.h"
#include "../powerwindow_HeaderFiles/powerwindow_debounce.h"
#include "../powerwindow_HeaderFiles/powerwindow_controlexclusion.h"

/* Macros for accessing real-time model data structure */
#ifndef powerwindow_PW_PSG_BackR_rtmGetErrorStatus
# define powerwindow_PW_PSG_BackR_rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef powerwindow_PW_PSG_BackR_rtmSetErrorStatus
# define powerwindow_PW_PSG_BackR_rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef powerwindow_PW_PSG_BackR_rtmGetErrorStatusPointer
# define powerwindow_PW_PSG_BackR_rtmGetErrorStatusPointer(rtm) ((const powerwindow_char_T **)(&((rtm)->errorStatus)))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  powerwindow_rtMdlrefDWork_debounce_T Debounce_Up_DWORK1;/* '<S2>/Debounce_Up' */
  powerwindow_rtMdlrefDWork_debounce_T
  Debounce_Down_DWORK1;/* '<S2>/Debounce_Down' */
  powerwindow_rtMdlrefDWork_PowerWindow_contr
  PW_PSG_BackR_DWORK1;/* '<S1>/PW_PSG_BackR' */
} powerwindow_D_Work_PW_Control_PSG_BackR;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  powerwindow_boolean_T Up_DRV;                    /* '<Root>/Up_DRV' */
  powerwindow_boolean_T Down_DRV;                  /* '<Root>/Down_DRV' */
  powerwindow_boolean_T
  endofdetectionrange;       /* '<Root>/end of detection range' */
  powerwindow_uint8_T currentsense;                /* '<Root>/current sense' */
  powerwindow_boolean_T
  Up_PSG_BackR;                    /* '<Root>/Up_PSG_BackR' */
  powerwindow_boolean_T
  Down_PSG_BackR;                  /* '<Root>/Down_PSG_BackR' */
} powerwindow_ExternalInputs_PW_Control_PSG_BackR;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  powerwindow_boolean_T window_up;                 /* '<Root>/window_up' */
  powerwindow_boolean_T window_down;               /* '<Root>/window_down' */
  powerwindow_boolean_T overcurrent;               /* '<Root>/overcurrent' */
  powerwindow_boolean_T pinch;                     /* '<Root>/pinch' */
  powerwindow_boolean_T wake;                      /* '<Root>/wake' */
} powerwindow_ExternalOutputs_PW_Control_PSG_BackR;

/* Real-time Model Data Structure */
struct powerwindow_tag_RTM_PW_Control_PSG_BackR {
  const powerwindow_char_T *volatile errorStatus;
};

/* Block states (auto storage) */
extern powerwindow_D_Work_PW_Control_PSG_BackR
powerwindow_PW_Control_PSG_BackR_DWork;

/* External inputs (root inport signals with auto storage) */
extern powerwindow_ExternalInputs_PW_Control_PSG_BackR
powerwindow_PW_Control_PSG_BackR_U;

/* External outputs (root outports fed by signals with auto storage) */
extern powerwindow_ExternalOutputs_PW_Control_PSG_BackR
powerwindow_PW_Control_PSG_BackR_Y;

/* Model entry point functions */
extern void powerwindow_PW_Control_PSG_BackR_initialize( void );
extern void powerwindow_PW_Control_PSG_BackR_main( void );
extern void powerwindow_PW_Control_PSG_BackR_terminate( void );

/* Real-time Model object */
extern powerwindow_RT_MODEL_PW_Control_PSG_BackR *const
powerwindow_PW_Control_PSG_BackR_M;

/*-
   The generated code includes comments that allow you to trace directly
   back to the appropriate location in the model.  The basic format
   is <system>/block_name, where system is the system number (uniquely
   assigned by Simulink) and block_name is the name of the block.

   Note that this particular code originates from a subsystem build,
   and has its own system numbers different from the parent model.
   Refer to the system hierarchy for this subsystem below, and use the
   MATLAB hilite_system command to trace the generated code back
   to the parent model.  For example,

   hilite_system('PowerWindow/PW_Control_PSG_BackR')    - opens subsystem PowerWindow/PW_Control_PSG_BackR
   hilite_system('PowerWindow/PW_Control_PSG_BackR/Kp') - opens and selects block Kp

   Here is the system hierarchy for this model

   '<Root>' : 'PowerWindow'
   '<S1>'   : 'PowerWindow/PW_Control_PSG_BackR'
   '<S2>'   : 'PowerWindow/PW_Control_PSG_BackR/Debounce_PSG'
*/
#endif                                 /* RTW_HEADER_PW_Control_PSG_h_*/

/*
   File trailer for generated code.

   [ EOF ]
*/
