#include "player.h"
#include "tilemap.h"
#include "scaler.h"
#include "vdma.h"
#include "xil_printf.h"
#include "myColorRegister.h"
#include "sleep.h"

int main() {
    struct Player* player = initialize_player();
    struct TileMap* map = initialize_map();
	configureScaler();
    configureVdma();

    int colorA = 0;
    int colorB = 0xFF;
    MYCOLORREGISTER_mWriteReg(XPAR_MYCOLORREGISTER_0_S00_AXI_BASEADDR, 4, colorB);

    while (1) {
        MYCOLORREGISTER_mWriteReg(XPAR_MYCOLORREGISTER_0_S00_AXI_BASEADDR, 0, colorA);
		//MYCONTROLLERPPU_mWriteReg(XPAR_MYCONTROLLLERPPU_0_S00_AXI_BASEADDR, 0, instruction);
		colorA = colorA + 1024;
        move_player(player, 1, 0); // Move the player to the right
		sleep(1);
    }

    free(player);
    return 0;
}
