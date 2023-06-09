#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define SPEED 100


void go(int time, int deg = 0){
	clearTimer(T1);
	while (time1(T1) < time){
		int g = SensorValue(gyro)-deg;
		motor(leftMotor) = SPEED-2*g;
		motor(rightMotor) = SPEED+2*g;
	}
}


task main()
{
	go(2250);
	go(2500,-900);
	go(2250);
	go(2000,900);
}
