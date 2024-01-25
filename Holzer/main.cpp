#include "stuff.h"

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	if (MessageBoxA(0, "You are about to run a GDI Only.\n\n\
Use this GDI Only wisely, this will not cause data loss and doesn't make your computer likely unbootable.\n\
If you don't know what is this program do, just click 'No' to keep your computer safe.\n\
When clicking 'Yes', the GDI Only will start and you'll understand the risk. If you want to\n\
try this, then use a secure environment, like a Virtual Machine.\n\
The creator is not responsible for any data loss or damage made to your computer.\n\
Execute this GDI Only? You will be able to use Windows again!\n\n\
WARNING: This GDI Only contain flashing lights and disturbing noises.", "Holzer (GDI Only)", MB_YESNO | MB_ICONWARNING) != IDYES) {
		ExitProcess(0);
	}
    if (MessageBoxA(0, "FINAL WARNING!\n\n\
If you have read the previous warning, then you'll keep in mind that your\n\
computer not going to be destroyed. Clicking 'Yes' doesn't destroy your computer!\n\
You will be able to use Windows again!\n\
The creator is not responsible for any data loss or damage made to your computer.\n\n\
Do you still wanna execute this GDI Only?", "Holzer (GDI Only)", MB_YESNO | MB_ICONWARNING) != IDYES) {
		ExitProcess(0);
	}

	

	startPayloads();
}