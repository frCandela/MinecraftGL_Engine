#include "Minecraft.h"

int main()
{
	Minecraft& minecraft = Minecraft::Instance();
	minecraft.Init("Minecraft", 800, 800);
	minecraft.Start();

}