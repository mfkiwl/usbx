/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */ 
/** USBX Component                                                        */ 
/**                                                                       */
/**   Pictbridge Application                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/* Include necessary system files.  */

#define UX_SOURCE_CODE

#include "ux_api.h"
#include "ux_pictbridge.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_pictbridge_xml_function_output_getdevicestatus_                 */
/*                                       dpsprintservicestatus            */ 
/*                                                        PORTABLE C      */ 
/*                                                           6.0          */
/*                                                                        */ 
/*                                                                        */ 
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*    This function decodes the dpsprintservicestatus tag                 */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    pictbridge                             Pictbridge instance          */ 
/*    input_variable                         Pointer to variable          */ 
/*    input_string                           Pointer to string            */ 
/*    xml_parameter                          Pointer to xml parameter     */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    Completion Status                                                   */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    _ux_pictbridge_object_parse                                         */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */ 
/*                                                                        */ 
/*  05-19-2020     Chaoqiong Xiao           Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
UINT  _ux_pictbridge_xml_function_output_getdevicestatus_dpsprintservicestatus(UX_PICTBRIDGE *pictbridge, 
                            UCHAR *input_variable, UCHAR *input_string, UCHAR *xml_parameter)
{
UINT    status;
ULONG   hexa_element;

    UX_PARAMETER_NOT_USED(input_string);
    UX_PARAMETER_NOT_USED(input_variable);

    /* Get the dpsprintservicestatus variable.  */
    status = _ux_pictbridge_element_to_hexa(xml_parameter, &hexa_element);

    /* Check status.  */
    if (status == UX_SUCCESS)
    {
        /* Check the returned value. Must be one of 3 possibilities.  */
        if (hexa_element == UX_PICTBRIDGE_DPS_PRINTSERVICE_STATUS_ACTIVE ||
            hexa_element == UX_PICTBRIDGE_DPS_PRINTSERVICE_STATUS_IDLE ||
            hexa_element == UX_PICTBRIDGE_DPS_PRINTSERVICE_STATUS_PAUSED)     
        {

            /* Save this value.  */
            pictbridge -> ux_pictbridge_dpsclient.ux_pictbridge_devinfo_dpsprintservicestatus = hexa_element;

           /* We are done. */
            return(UX_SUCCESS);        
        }            
    }        

    /* We get here when we reached an unexpected end of the XML object or a format error.  */
    return(UX_PICTBRIDGE_ERROR_SCRIPT_SYNTAX_ERROR);    
        
    
}


