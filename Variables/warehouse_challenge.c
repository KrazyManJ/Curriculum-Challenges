#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define SPEED 50
#define DEF_DEGREE 0


task countLines()
{
	int linesAmount = 0;
	wait1Msec(500);
	while (true){
		if (SensorValue(light) < 60)
		{
			linesAmount++;
			nxtDisplayTextLine(0, "Line count: %d", linesAmount);
			wait1Msec(300);
		}
	}
}

void ride(int time,int degrees = DEF_DEGREE)
{
	clearTimer(T1);
	while (time1(T1)<time)
	{
		int g = SensorValue(gyro)-degrees;
		motor(leftMotor) = SPEED-2*g;
		motor(rightMotor) = SPEED+2*g;
	}
}


task main()
{
	startTask(countLines);
	ride(3000);
	ride(2000, 1800);
	ride(4500, 2700);
	ride(4000);
	ride(4500,900);
	ride(7000);
	ride(4500,-900);
	ride(3500,-1800);
	ride(2000,-2700);
	ride(2000,-900);
	ride(2000,-1800);
	stopAllTasks();
}
