#include <stdint.h>
#include <stdbool.h>
#include "driverlib/debug.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/udma.h"

int main()
{
    // Create a control table in memory to manage DMA transfers
    uint8_t DMA_Control_Table[1024]; //  This array will be used as the base address for the control table for uDMA transfers.

/*

The purpose of the DMA_Control_Table is to store the configuration information for each DMA channel.
Each entry in the table corresponds to a specific DMA channel and contains the necessary settings and parameters for a DMA transfer.
These settings include the source and destination addresses, transfer length, data width, and other control parameters.



 */





    // Define source and destination buffers for DMA transfer
    uint8_t Source_Buffer[256] = "DMA Test"; // //  will be the source of the data to be transferred using DMA.
    uint8_t Destination_Buffer[256];   // This buffer will be the destination where the transferred data will be stored.

    // Enable uDMA (Micro Direct Memory Access) peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);  // that allows data transfers between memory and peripherals
                                                 // without CPU intervention.
                                                 // It is used to store the transferred data received from the DMA operation.

    // Wait until uDMA peripheral is ready
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_UDMA));

    // Enable the uDMA controller ,  allowing DMA transfers to be performed.
    uDMAEnable();

    // Set the base address of the control table for uDMA transfers
    uDMAControlBaseSet(&DMA_Control_Table[0]); // disables attributes for the uDMA software channel.
                                               //It disables all attributes (interrupts, end of transfer, etc.)

    // Disable attributes for the uDMA software channel

    /*
    By calling uDMAChannelAttributeDisable with these arguments, all attributes of the uDMA software channel are disabled. This includes disabling interrupts,
     end-of-transfer signals, and other attributes associated with the software channel.

    Disabling these attributes means that the uDMA software channel will not generate interrupts or other events upon DMA transfer completion,
    providing a straightforward and non-interrupt-driven DMA operation.



    */
    uDMAChannelAttributeDisable(UDMA_CHANNEL_SW, UDMA_ATTR_ALL);

    /* Configure uDMA channel control for software transfer where, transfer size is 8 bits (UDMA_SIZE_8),
       the source address is incremented by 8 bits after each transfer (UDMA_SRC_INC_8),
       the destination address is incremented by 8 bits after each transfer (UDMA_DST_INC_8),
       and the arbitration size is set to 8 (UDMA_ARB_8). arbitration means
       arbitration refers to the process of determining the priority or order in which multiple DMA transfer
       requests are serviced
       when they are pending simultaneously. When multiple DMA channels or requests are active or pending,
       arbitration decides which request gets access to the bus or the memory first. */

    uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT,
                          UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_8 | UDMA_ARB_8);

    /*  Set up uDMA channel transfer parameters
        It configures the transfer mode, source address, destination address, and transfer size for the software channel.
        The transfer mode is set to automatic
    */
    uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT,
                           UDMA_MODE_AUTO, Source_Buffer, Destination_Buffer, sizeof(Destination_Buffer));


    // Enable and initiate the uDMA software channel initiate the transfer request. Once these lines are executed,
    //the DMA transfer will start, and the data from the source buffer will be transferred to the destination buffer.
    uDMAChannelEnable(UDMA_CHANNEL_SW);
    uDMAChannelRequest(UDMA_CHANNEL_SW);

    // Main loop
    while (1)
    {
        // Code execution will remain in this loop
        // as the DMA transfer is being performed
    }
}



// Take care of stack size